#include "intercode.h"
#include "target.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

extern int var_count;
extern int temp_count;
extern InterCodes* intercs;

void pre_trans(){
	offset_sum = 1;
	arg_num = 0;
	max_offset = 0;
	offset_record = (int*)malloc(sizeof(int)*offset_sum);
	int i;
	for(i = 0; i < var_count + temp_count; i++)// for each t and v
		offset_record[i] = -1;

	printf("var%d\n", var_count);
	printf("temp%d\n", temp_count);
	fprintf(f2, ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n");
	fprintf(f2, ".text\n");
	fprintf(f2, "read:\n\tli $v0, 4\n\tla $a0, _prompt\n\tsyscall\t\n\tli $v0, 5\n\tsyscall\n\tjr $ra\n\n");
	fprintf(f2, "write:\n\tli $v0, 1\n\tsyscall\n\tli $v0, 4\n\tla $a0, _ret\n\tsyscall\n\tmove $v0, $0\n\tjr $ra\n\n");
}

int get_offset(int no, int type){
	int num = 0;
	if(type == 0)//t
		num = no;
	else if(type == 1)//v
		num = no + temp_count;
	else{
		fprintf(f2,"Error in get_offset()!!\n");
		return -1;
	}
	if(offset_record[num] == -1){
		int offset = (offset_sum++) * 4;
		offset_record[num] = offset;
		if(max_offset < offset){
			fprintf(f2, "\taddi $sp, $sp, -%d\n", offset - max_offset);
			max_offset = offset;
		}
		return offset;
	}
	else
		return offset_record[num];
}

void trans_op(Operand op){
	switch(op->kind){
		case CONSTANT:
			fprintf(f2, "\tli $t0, %d\n", op->u.value);
			break;
		case ARRA:
			fprintf(f2, "\tmove $t1, $fp\n");
			fprintf(f2, "\taddi $t1, $t1, -%d\n", get_offset(op->u.array_var_no, 1));
			fprintf(f2, "\tmove $t0, $t1\n");
			break;
		case ADDRESS:
			fprintf(f2, "\tlw $t1, -%d($fp)\n", get_offset(op->u.addr_temp_no, 0));
			fprintf(f2, "lw $t0, 0($t1)\n");
			break;
		case VARIABLE:
			fprintf(f2, "\tlw $t0, -%d($fp)\n", get_offset(op->u.var_no, 1));
			break;
		case TEMP:
			fprintf(f2, "\tlw $t0, -%d($fp)\n", get_offset(op->u.temp_no, 0));
			break;
	}
}

void trans_left_op(Operand op){
	if(op->kind == ADDRESS){
		fprintf(f2, "\tlw $t1, -%d($fp)\n", get_offset(op->u.addr_temp_no, 0));
		fprintf(f2, "\tsw $t0, 0($t1)\n");
	}
	else if(op->kind == VARIABLE){
		fprintf(f2, "\tsw $t0, -%d($fp)\n", get_offset(op->u.var_no, 1));
	}
	else if(op->kind == TEMP){
		fprintf(f2, "\tsw $t0, -%d($fp)\n", get_offset(op->u.temp_no, 0));
	}
}

void trans_arithmatic(InterCode* code){
	trans_op(code->u.binop.op1);
	fprintf(f2, "\tmove $t1, $t0\n");
	trans_op(code->u.binop.op2);
	switch(code->kind){
		case ADD:
			fprintf(f2, "\tadd $t0, $t0, $t1\n");
			break;
		case SUB:
			fprintf(f2, "\tsub $t0, $t1, $t0\n");
			break;
		case MUL:
			fprintf(f2, "\tmul $t0, $t0, $t1\n");
			break;
		case DIVIDE:
			fprintf(f2, "\tdiv $t1, $t0\n");
			fprintf(f2, "\tmflo $t0\n");
			break;
		default:
			fprintf(f2, "Error in trans_arithmatic()!!\n");
	}
	trans_left_op(code->u.binop.result);
}

void trans(InterCodes* cur){
	InterCode* code = cur->code;
	switch(code->kind){
		case LABEL:
			fprintf(f2, "label%d:\n", code->u.label_no);
			break;
		case RET:
			fprintf(f2, "\tlw $v0, -%d($fp)\n", get_offset(code->u.return_temp_no, 0));
			fprintf(f2, "\tmove $sp, $fp\n");
			fprintf(f2, "\tjr $ra\n");
			arg_num = 0;
			break;
		case GOTO:
			fprintf(f2, "\tj label%d\n", code->u.goto_no);
			break;
		case READ:
			fprintf(f2, "\taddi $sp, $sp, -4\n");
			fprintf(f2, "\tsw $ra, 0($sp)\n");
			fprintf(f2, "\tjal read\n");
			fprintf(f2, "\tlw $ra, 0($sp)\n");
			fprintf(f2, "\taddi $sp, $sp, 4\n");
			fprintf(f2, "\tsw $v0, -%d($fp)\n", get_offset(code->u.read_no, 0));
			break;
		case WRITE:
			fprintf(f2, "\tlw $a0, -%d($fp)\n", get_offset(code->u.write_no, 0));
			fprintf(f2, "\taddi $sp, $sp, -4\n");
			fprintf(f2, "\tsw $ra, 0($sp)\n");
			fprintf(f2, "\tjal write\n");
			fprintf(f2, "\tlw $ra, 0($sp)\n");
			fprintf(f2, "\taddi $sp, $sp, 4\n");
			break;
		case ARG:
			if(arg_num < 4){
				printf("hahahaha\n");
				fprintf(f2, "\tlw $a%d, -%d($fp)\n", arg_num, get_offset(code->u.arg_var_no, 0));
				//printf("%d %d\n", code->u.arg_var_no, get_offset(code->u.arg_var_no, 1));
			}
			else{
				//参数大于4个的情况				
			}
			arg_num++;
			break;
		case FUNC:
			fprintf(f2, "%s:\n", code->u.func);
			fprintf(f2, "\tmove $fp, $sp\n");
			max_offset = 0;
			break;
		case PARA:
			if(arg_num < 4)
				fprintf(f2, "\tsw $a%d, -%d($fp)\n", arg_num, get_offset(code->u.para_var_no, 1));
			else{
				//参数大于4个
			}
			arg_num++;
			break;
		case CALL:
			fprintf(f2, "\tli $s1, %d\n", max_offset);
			fprintf(f2, "\taddi $sp, $sp, -8\n");
			fprintf(f2, "\tsw $fp, 8($sp)\n");
			fprintf(f2, "\tsw $s1, 4($sp)\n");
			fprintf(f2, "\tsw $ra, 0($sp)\n");
			fprintf(f2, "\tjal %s\n", code->u.assign.right->u.fun);
			fprintf(f2, "\tlw $ra, 0($sp)\n");
			fprintf(f2, "\tlw $s1, 4($sp)\n");
			fprintf(f2, "\tlw $fp, 8($sp)\n");
			break;
		case ASS:
			if(code->u.assign.right->kind == FUN){
				fprintf(f2, "\tli $s1, %d\n", max_offset);
				fprintf(f2, "\taddi $sp, $sp, -8\n");
				fprintf(f2, "\tsw $fp, 8($sp)\n");
				fprintf(f2, "\tsw $s1, 4($sp)\n");
				fprintf(f2, "\tsw $ra, 0($sp)\n");
				fprintf(f2, "\tjal %s\n", code->u.assign.right->u.fun);
				fprintf(f2, "\tlw $ra, 0($sp)\n");
				fprintf(f2, "\tlw $s1, 4($sp)\n");
				fprintf(f2, "\tlw $fp, 8($sp)\n");
				fprintf(f2, "\tsw $v0, -%d($fp)\n", get_offset(code->u.assign.left->u.temp_no, 0));
				fprintf(f2, "\taddi $sp, $sp, 8\n");
			}
			else{
				trans_op(code->u.assign.right);
				assert(code->u.assign.left->kind != ARRA);
				trans_left_op(code->u.assign.left);
			}
			break;
		case DEC:{
			int num = code->u.dec.var_no + temp_count - 1;
			assert(offset_record[num] == -1);
			int offset = offset_sum * 4;
			offset_record[num] = offset;
			offset_sum += (code->u.dec.size);
			if(offset_sum*4 > max_offset){
				fprintf(f2, "\taddi $sp, $sp, -%d\n", offset_sum*4 - max_offset);
				max_offset = offset_sum * 4;
			}
			break;
		}
		case ADD:
			trans_arithmatic(code);
			break;
		case SUB:
			trans_arithmatic(code);
			break;
		case MUL:
			trans_arithmatic(code);
			break;
		case DIVIDE:
			trans_arithmatic(code);
			break;
		case IF2:
			fprintf(f2, "\tlw $t0, -%d($fp)\n", get_offset(code->u.if2.temp_no1, 0));
			fprintf(f2, "\tlw $t1, -%d($fp)\n", get_offset(code->u.if2.temp_no2, 0));
			if(strcmp(code->u.if2.op, ">") == 0) 
				fprintf(f2, "\tbgt $t0, $t1, label%d\n", code->u.if2.label_no);
			else if(strcmp(code->u.if2.op, "<") == 0) 
				fprintf(f2, "\tblt $t0, $t1, label%d\n", code->u.if2.label_no);
			else if(strcmp(code->u.if2.op, ">=") == 0) 
				fprintf(f2, "\tbge $t0, $t1, label%d\n", code->u.if2.label_no);
			else if(strcmp(code->u.if2.op, "<=") == 0) 
				fprintf(f2, "\tble $t0, $t1, label%d\n", code->u.if2.label_no);
			else if(strcmp(code->u.if2.op, "==") == 0) 
				fprintf(f2, "\tbeq $t0, $t1, label%d\n", code->u.if2.label_no);
			else if(strcmp(code->u.if2.op, "!=") == 0) 
				fprintf(f2, "\tbne $t0, $t1, label%d\n", code->u.if2.label_no);
			
			break;
		//case IF1:

	}
}

void trans_code(char *filename){
	//f2 = fopen("out_target.txt", "w+" );
	f2 = fopen( filename, "w+" );
	pre_trans();
	InterCodes* cur = intercs;
	do{
		trans(cur);
		cur = cur->next;
	}while(cur != NULL);
}