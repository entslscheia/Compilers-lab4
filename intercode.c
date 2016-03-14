#include "node.h"
#include "intercode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern InterCodes* intercs;
int var_count = 0;
int temp_count = 0;
int next_temp_no = 0; //  not sure 
int next_label = 0;

void initial_table(char* table[]){
	int i;
	for( i = 0; i < 100; i ++)
		table[i] = NULL;
}

int item_count(char* table[]){
	int i;
	for( i = 0; i < 100; i ++){
		if(table[i] == NULL)
			break; 
	}

	return i;
}

int insert(char* table[], char* id){
	int i;
	for( i = 0; i < 100; i ++){
		if(table[i] == NULL){
			//printf("i %d id %s\n", i, id);
			break;
		}
	}

	table[i] = (char *)malloc(sizeof(20));
	strcpy(table[i], (const char *)id);
	return i;
}

int lookup(char* table[], char* id){
	int i;
	for( i = 0; i < 100; i ++){
		if(table[i] != NULL){
			if(strcmp(id, table[i]) == 0)
				return i;
		}
	}
}

InterCodes* translate_Args(node *p, int arg_list[]){
	if(p -> numOfChildren == 1){// Exp
		int temp = next_temp_no;
		next_temp_no ++;
		int i;
		for( i = 0; i < 20; i ++){
			if(arg_list[i] == -1){
				arg_list[i] = temp;
				break;
			}
		}

		InterCodes* ics = translate_Exp(p -> children[0], sym_table, temp);
		return ics;
	}
	else{// Exp COMMA Args
		int temp = next_temp_no;
		next_temp_no ++;
		int i;
		for( i = 0; i < 20; i ++){
			if(arg_list[i] == -1){
				arg_list[i] = temp;
				break;
			}
		}

		InterCodes* ics0 = translate_Exp(p -> children[0], sym_table, temp);
		InterCodes* ics1 = translate_Args(p -> children[2], arg_list);

		ics0 -> prev = NULL;
		InterCodes* ict = ics0;
		for(; ict -> next != NULL; ict = ict -> next);
		ict -> next = ics1;
		ics1 -> prev = ict;

		//print_intercode(ics0);
		//printf("fenjiexian\n");
		return ics0;
	}
}

InterCodes* translate_Exp(node *p, char* table[], int place){
	//printf("%s\n", p -> children[0] -> name);
	if(p -> numOfChildren == 3){
		//case 1 Exp = Exp
		if(strcmp(p -> children[1] -> name, "ASSIGN") == 0){
			if(p -> children[0] -> numOfChildren == 1){// jian dan bian liang
				printf("ASSIGN\n");
				InterCodes *ics0, *ics1;
				int temp = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[2], sym_table, temp);

				char* id = (char*)malloc(sizeof(20));
				strcpy(id, (const char*)p -> children[0] -> children[0] -> val.type_ID);

				int var_no = lookup(sym_table, id);

				InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
				ic1 -> kind = ASS;
				ic1 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic1 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic1 -> u.assign.right -> kind = TEMP;
				ic1 -> u.assign.right -> u.temp_no = temp;
				ic1 -> u.assign.left -> kind = VARIABLE;
				ic1 -> u.assign.left -> u.var_no = var_no;

				ics1 = (InterCodes*)malloc(sizeof(InterCodes));
				ics1 -> code = ic1;
				//printf("%d\n", place);
				if(place != -1){
					printf("ASSIGN place != -1\n");
					InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
					ic2 -> kind = ASS;
					ic2 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
					ic2 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
					ic2 -> u.assign.right -> kind = VARIABLE;
					ic2 -> u.assign.right -> u.var_no = var_no;
					ic2 -> u.assign.left -> kind = TEMP;
					ic2 -> u.assign.left -> u.var_no = place;

					InterCodes* ics2 = (InterCodes*)malloc(sizeof(InterCodes));
					ics2 -> code = ic2;

					ics0 -> prev = NULL;
					InterCodes* ict = ics0;
					for(; ict -> next != NULL; ict = ict -> next);
					ict -> next = ics1;
					ics1 -> prev = ict;
					ics1 -> next = ics2;
					ics2 -> prev = ics1;
					ics2 -> next = NULL;
				}

				else{
					ics0 -> prev = NULL;
					InterCodes* ict = ics0;
					for(; ict -> next != NULL; ict = ict -> next);
					ict -> next = ics1;
					ics1 -> prev = ict;
					ics1 -> next = NULL;
				}
				return ics0;
			}
			else{// shu zu
				int temp0 = next_temp_no;
				next_temp_no ++;
				InterCodes* ics0 = translate_Exp(p -> children[2], sym_table, temp0);
				InterCodes* ics1 = translate_Exp(p -> children[0], sym_table, -1);
				int temp1 = next_temp_no - 3;

				InterCodes* ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = ASS;
				ic2 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.assign.right -> kind = TEMP;
				ic2 -> u.assign.right -> u.temp_no = temp0;
				ic2 -> u.assign.left -> kind = ADDRESS;
				ic2 -> u.assign.left -> u.addr_temp_no = temp1;
				ics2 -> code = ic2;
				if(place != -1){
					InterCodes* ics3 = (InterCodes*)malloc(sizeof(InterCodes));
					InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
					ic3 -> kind = ASS;
					ic3 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
					ic3 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
					ic3 -> u.assign.left -> kind = TEMP;
					ic3 -> u.assign.left -> u.temp_no = place;
					ic3 -> u.assign.right -> kind = ADDRESS;
					ic3 -> u.assign.right -> u.addr_temp_no = temp1;
					ics3 -> code = ic3;

					ics0 -> prev = NULL;
					InterCodes* ict = ics0;
					for(; ict -> next != NULL; ict = ict -> next);
					ict -> next = ics1;
					ics1 -> prev = ict;
					InterCodes* ict1 = ics1;
					for(; ict1 -> next != NULL; ict1 = ict1 -> next);
					ict1 -> next = ics2;
					ics2 -> prev = ict1;
					ics2 -> next = ics3;
					ics3 -> prev = ics2;
					ics3 -> next = NULL;
				}

				else{

					ics0 -> prev = NULL;
					InterCodes* ict = ics0;
					for(; ict -> next != NULL; ict = ict -> next);
					ict -> next = ics1;
					ics1 -> prev = ict;
					InterCodes* ict1 = ics1;
					for(; ict1 -> next != NULL; ict1 = ict1 -> next);
					ict1 -> next = ics2;
					ics2 -> prev = ict1;
					ics2 -> next = NULL;
				}
				return ics0;
			}
		}
		//case 2 Exp AND Exp
		if(strcmp(p -> children[1] -> name, "AND") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2, *ics3, *ics4;

				int label1 = next_label;
				next_label ++;
				int label2 = next_label;
				next_label ++;

				ics0 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic0 = (InterCode*)malloc(sizeof(InterCode));
				ic0 -> kind = ASS;
				ic0 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.left -> kind = TEMP;
				ic0 -> u.assign.left -> u.temp_no = place;
				ic0 -> u.assign.right -> kind = CONSTANT;
				ic0 -> u.assign.right -> u.value = 0;
				ics0 -> code = ic0;

				ics1 = translate_Cond(p, label1, label2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = LABEL;
				ic2 -> u.label_no = label1;
				ics2 -> code = ic2;

				ics3 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
				ic3 -> kind = ASS;
				ic3 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.left -> kind = TEMP;
				ic3 -> u.assign.left -> u.temp_no = place;
				ic3 -> u.assign.right -> kind = CONSTANT;
				ic3 -> u.assign.right -> u.value = 1;
				ics3 -> code = ic3;

				ics4 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic4 = (InterCode*)malloc(sizeof(InterCode));
				ic4 -> kind = LABEL;
				ic4 -> u.label_no = label2;
				ics4 -> code = ic4;

				ics0 -> prev = NULL;
				ics0 -> next = ics1;
				ics1 -> prev = ics0;
				ics1 -> next = ics2;
				ics2 -> prev = ics1;
				ics2 -> next = ics3;
				ics3 -> prev = ics2;
				ics3 -> next = ics4;
				ics4 -> prev = ics3;
				ics4 -> next = NULL;
				return ics0;
			}
			else{
				printf("illegal\n");
				return NULL;
			}
		}
		//case 3 Exp OR Exp
		if(strcmp(p -> children[1] -> name, "OR") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2, *ics3, *ics4;

				int label1 = next_label;
				next_label ++;
				int label2 = next_label;
				next_label ++;

				ics0 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic0 = (InterCode*)malloc(sizeof(InterCode));
				ic0 -> kind = ASS;
				ic0 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.left -> kind = TEMP;
				ic0 -> u.assign.left -> u.temp_no = place;
				ic0 -> u.assign.right -> kind = CONSTANT;
				ic0 -> u.assign.right -> u.value = 0;
				ics0 -> code = ic0;

				ics1 = translate_Cond(p, label1, label2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = LABEL;
				ic2 -> u.label_no = label1;
				ics2 -> code = ic2;

				ics3 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
				ic3 -> kind = ASS;
				ic3 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.left -> kind = TEMP;
				ic3 -> u.assign.left -> u.temp_no = place;
				ic3 -> u.assign.right -> kind = CONSTANT;
				ic3 -> u.assign.right -> u.value = 1;
				ics3 -> code = ic3;

				ics4 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic4 = (InterCode*)malloc(sizeof(InterCode));
				ic4 -> kind = LABEL;
				ic4 -> u.label_no = label2;
				ics4 -> code = ic4;

				ics0 -> prev = NULL;
				ics0 -> next = ics1;
				ics1 -> prev = ics0;
				ics1 -> next = ics2;
				ics2 -> prev = ics1;
				ics2 -> next = ics3;
				ics3 -> prev = ics2;
				ics3 -> next = ics4;
				ics4 -> prev = ics3;
				ics4 -> next = NULL;
				return ics0;
			}
			else{
				printf("illegal\n");
				return NULL;
			}
		}
		//case 4 Exp RELOP Exp
		if(strcmp(p -> children[1] -> name, "RELOP") == 0){
			printf("RELOP BEGIN\n");
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2, *ics3, *ics4;

				int label1 = next_label;
				next_label ++;
				int label2 = next_label;
				next_label ++;

				ics0 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic0 = (InterCode*)malloc(sizeof(InterCode));
				ic0 -> kind = ASS;
				ic0 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.left -> kind = TEMP;
				ic0 -> u.assign.left -> u.temp_no = place;
				ic0 -> u.assign.right -> kind = CONSTANT;
				ic0 -> u.assign.right -> u.value = 0;
				ics0 -> code = ic0;

				ics1 = translate_Cond(p, label1, label2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = LABEL;
				ic2 -> u.label_no = label1;
				ics2 -> code = ic2;

				ics3 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
				ic3 -> kind = ASS;
				ic3 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.left -> kind = TEMP;
				ic3 -> u.assign.left -> u.temp_no = place;
				ic3 -> u.assign.right -> kind = CONSTANT;
				ic3 -> u.assign.right -> u.value = 1;
				ics3 -> code = ic3;

				ics4 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic4 = (InterCode*)malloc(sizeof(InterCode));
				ic4 -> kind = LABEL;
				ic4 -> u.label_no = label2;
				ics4 -> code = ic4;

				ics0 -> prev = NULL;
				ics0 -> next = ics1;
				ics1 -> prev = ics0;
				InterCodes* ict1 = ics1;
				for(; ict1 -> next != NULL; ict1 = ict1 -> next);
				ict1 -> next = ics2;
				ics2 -> prev = ict1;
				ics2 -> next = ics3;
				ics3 -> prev = ics2;
				ics3 -> next = ics4;
				ics4 -> prev = ics3;
				ics4 -> next = NULL;
				return ics0;
			}
			else{
				printf("illegal\n");
				return NULL;
			}
		}
		//case 5 Exp + Exp
		if(strcmp(p -> children[1] -> name, "PLUS") == 0){
			
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));

				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = ADD;
				ic2 -> u.binop.result = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.result -> kind = TEMP;
				ic2 -> u.binop.result -> u.temp_no = place;
				ic2 -> u.binop.op1 -> kind = TEMP;
				ic2 -> u.binop.op1 -> u.temp_no = temp1;
				ic2 -> u.binop.op2 -> kind = TEMP;
				ic2 -> u.binop.op2 -> u.temp_no = temp2;
				ics2 -> code = ic2;

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ics0;
				InterCodes* ict1 = ics1;
				for(; ict1 -> next != NULL; ict1 = ict1 -> next);
				ict1 -> next = ics2;
				ics2 -> prev = ict1;
				ics2 -> next = NULL;

				return ics0;
			}
			else{
				InterCodes *ics0, *ics1;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ict0;

				return ics0;
			}
		}
		//case 6 Exp - Exp
		if(strcmp(p -> children[1] -> name, "MINUS") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));

				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = SUB;
				ic2 -> u.binop.result = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.result -> kind = TEMP;
				ic2 -> u.binop.result -> u.temp_no = place;
				ic2 -> u.binop.op1 -> kind = TEMP;
				ic2 -> u.binop.op1 -> u.temp_no = temp1;
				ic2 -> u.binop.op2 -> kind = TEMP;
				ic2 -> u.binop.op2 -> u.temp_no = temp2;
				ics2 -> code = ic2;

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ics0;
				InterCodes* ict1 = ics1;
				for(; ict1 -> next != NULL; ict1 = ict1 -> next);
				ict1 -> next = ics2;
				ics2 -> prev = ict1;
				ics2 -> next = NULL;

				return ics0;
			}
			else{
				InterCodes *ics0, *ics1;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ict0;

				return ics0;
			}
		}
		//case 7 Exp * Exp
		if(strcmp(p -> children[1] -> name, "STAR") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));

				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = MUL;
				ic2 -> u.binop.result = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.result -> kind = TEMP;
				ic2 -> u.binop.result -> u.temp_no = place;
				ic2 -> u.binop.op1 -> kind = TEMP;
				ic2 -> u.binop.op1 -> u.temp_no = temp1;
				ic2 -> u.binop.op2 -> kind = TEMP;
				ic2 -> u.binop.op2 -> u.temp_no = temp2;
				ics2 -> code = ic2;

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ics0;
				InterCodes* ict1 = ics1;
				for(; ict1 -> next != NULL; ict1 = ict1 -> next);
				ict1 -> next = ics2;
				ics2 -> prev = ict1;
				ics2 -> next = NULL;

				return ics0;
			}
			else{
				InterCodes *ics0, *ics1;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);
				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ict0;

				return ics0;
			}
		}
		//case 8 Exp / Exp
		if(strcmp(p -> children[1] -> name, "DIV") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));

				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = DIVIDE;
				ic2 -> u.binop.result = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.binop.result -> kind = TEMP;
				ic2 -> u.binop.result -> u.temp_no = place;
				ic2 -> u.binop.op1 -> kind = TEMP;
				ic2 -> u.binop.op1 -> u.temp_no = temp1;
				ic2 -> u.binop.op2 -> kind = TEMP;
				ic2 -> u.binop.op2 -> u.temp_no = temp2;
				ics2 -> code = ic2;

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ics0;
				InterCodes* ict1 = ics1;
				for(; ict1 -> next != NULL; ict1 = ict1 -> next);
				ict1 -> next = ics2;
				ics2 -> prev = ict1;
				ics2 -> next = NULL;

				return ics0;
			}
			else{
				InterCodes *ics0, *ics1;

				int temp1 = next_temp_no;
				next_temp_no ++;
				int temp2 = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[0], sym_table, temp1);
				ics1 = translate_Exp(p -> children[2], sym_table, temp2);

				ics0 -> prev = NULL;
				InterCodes* ict0 = ics0;
				for(; ict0 -> next != NULL; ict0 = ict0 -> next);
				ict0 -> next = ics1;
				ics1 -> prev = ict0;

				return ics0;
			}
		}
		//case 9 LP Exp RP	
		if(strcmp(p -> children[0] -> name, "LP") == 0){
			return translate_Exp(p -> children[1], sym_table, place);
		}
		//case 13 ID LP RP
		if(strcmp(p -> children[2] -> name, "RP") == 0){
			if(place != -1){
				if(strcmp(p -> children[0] -> val.type_ID, "read") == 0){
					InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
					InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
					ic -> kind = READ;
					ic -> u.read_no = place;
					ics -> code = ic;

					ics -> prev = NULL;
					ics -> next = NULL;

					return ics;
				}
				else{
					char* fun = (char*)malloc(sizeof(20));
					strcpy(fun, (const char*)p -> children[0] -> val.type_ID);

					InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
					InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
					ic -> kind = ASS;
					ic -> u.assign.left = (Operand)malloc(sizeof(Operand_));
					ic -> u.assign.right = (Operand)malloc(sizeof(Operand_));
					ic -> u.assign.left -> kind = TEMP;
					ic -> u.assign.left -> u.temp_no = place;
					ic -> u.assign.right -> kind = FUN;
					memset(ic -> u.assign.right -> u.fun, 0, 20);
					strcpy(ic -> u.assign.right -> u.fun, (const char*)fun);
					ics -> code = ic;
					ics -> prev = NULL;
					ics -> next = NULL;

					return ics;
				}
			}
			else{
				if(strcmp(p -> children[0] -> val.type_ID, "read") == 0){
					printf("illegal\n");
					return NULL;
				}
				else{
					char* func = (char*)malloc(sizeof(20));
					strcpy(func, (const char*)p -> children[0] -> val.type_ID);

					InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
					InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
					ic -> kind = CALL;
					memset(ic -> u.call_func, 0, 20);
					strcpy(ic -> u.call_func, (const char*)func);
					ics -> code = ic;
					ics -> prev = NULL;
					ics -> next = NULL;
					return ics;
				}
			}
		}
		//case 15 Exp DOT ID
		/*if(strcmp(p -> children[1] -> name, "DOT") == 0){
			// do nothing for now
		}*/
	}

	if(p -> numOfChildren == 1){
		//printf("%s\n", p -> children[0] -> name);
		//case 16 ID
		if(strcmp(p -> children[0] -> name, "ID") == 0){
			if(place != -1){
				InterCodes* ics;
				ics = (InterCodes*)malloc(sizeof(InterCodes));

				char* id = (char*)malloc(sizeof(20));
				strcpy(id, (const char*)p -> children[0] -> val.type_ID);

				InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
				ic -> kind = ASS;
				ic -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic -> u.assign.left = (Operand)malloc(sizeof(Operand_));

				ic -> u.assign.right -> kind = VARIABLE;
				ic -> u.assign.right -> u.var_no = lookup(sym_table, id);

				ic -> u.assign.left -> kind = TEMP;
				ic -> u.assign.left -> u.temp_no = place;

				ics -> code = ic;
				ics -> prev = NULL;
				ics -> next = NULL;

				return ics;
			}
			else return NULL;
		}
		//case 17 INT
		if(strcmp(p -> children[0] -> name, "INT") == 0){
			if(place != -1){
				InterCodes* ics;
				ics = (InterCodes*)malloc(sizeof(InterCodes));

				InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
				ic -> kind = ASS;
				ic -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic -> u.assign.left = (Operand)malloc(sizeof(Operand_));

				ic -> u.assign.right -> kind = CONSTANT;
				ic -> u.assign.right -> u.value = p -> children[0] -> val.type_int;

				ic -> u.assign.left -> kind = TEMP;
				ic -> u.assign.left -> u.temp_no = place;

				ics -> code = ic;
				ics -> prev = NULL;
				ics -> next = NULL;

				return ics;
			}
			else return NULL;
		}
		//case 18 FLOAT
		/*if(strcmp(p -> children[0] -> name, "FLOAT") == 0){
			//do nothing for now
		}*/
	}
	if(p -> numOfChildren == 2){
		//case 10 MINUS Exp
		if(strcmp(p -> children[0] -> name, "MINUS") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1;
				int temp = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[1], sym_table, temp);

				ics1 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));

				ic1 -> kind = ASS;
				ic1 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic1 -> u.assign.right = (Operand)malloc(sizeof(Operand_));

				ic1 -> u.assign.left -> kind = TEMP;
				ic1 -> u.assign.left -> u.temp_no = place;
				ic1 -> u.assign.right -> kind = NEGATIVE;
				ic1 -> u.assign.right -> u.neg_temp_no = temp;

				ics1 -> code = ic1;

				ics0 -> prev = NULL;
				ics0 -> next = ics1;
				ics1 -> prev = ics0;
				ics1 -> next = NULL;

				return ics0;
			}
			else{
				InterCodes* ics0;
				int temp = next_temp_no;
				next_temp_no ++;

				ics0 = translate_Exp(p -> children[1], sym_table, temp);
				return ics0;
			}
		}
		//case 11 NOT Exp
		if(strcmp(p -> children[0] -> name, "NOT") == 0){
			if(place != -1){
				InterCodes *ics0, *ics1, *ics2, *ics3, *ics4;

				int label1 = next_label;
				next_label ++;
				int label2 = next_label;
				next_label ++;

				ics0 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic0 = (InterCode*)malloc(sizeof(InterCode));
				ic0 -> kind = ASS;
				ic0 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic0 -> u.assign.left -> kind = TEMP;
				ic0 -> u.assign.left -> u.temp_no = place;
				ic0 -> u.assign.right -> kind = CONSTANT;
				ic0 -> u.assign.right -> u.value = 0;
				ics0 -> code = ic0;

				ics1 = translate_Cond(p, label1, label2);

				ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = LABEL;
				ic2 -> u.label_no = label1;
				ics2 -> code = ic2;

				ics3 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
				ic3 -> kind = ASS;
				ic3 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic3 -> u.assign.left -> kind = TEMP;
				ic3 -> u.assign.left -> u.temp_no = place;
				ic3 -> u.assign.right -> kind = CONSTANT;
				ic3 -> u.assign.right -> u.value = 1;
				ics3 -> code = ic3;

				ics4 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic4 = (InterCode*)malloc(sizeof(InterCode));
				ic4 -> kind = LABEL;
				ic4 -> u.label_no = label2;
				ics4 -> code = ic4;

				ics0 -> prev = NULL;
				ics0 -> next = ics1;
				ics1 -> prev = ics0;
				ics1 -> next = ics2;
				ics2 -> prev = ics1;
				ics2 -> next = ics3;
				ics3 -> prev = ics2;
				ics3 -> next = ics4;
				ics4 -> prev = ics3;
				ics4 -> next = NULL;
				return ics0;
			}
			else{
				printf("illegal\n");
				return NULL;
			}
		}
	}
	
	if(p -> numOfChildren == 4){
		//case 12 ID LP Args RP
		if(strcmp(p -> children[2] -> name, "Args") == 0){
			int arg_list[20];
			int i;
			for( i = 0; i < 20; i ++)
				arg_list[i] = -1;

			
			if(strcmp(p -> children[0] -> val.type_ID, "write") == 0){
				InterCodes* ics0 = translate_Args(p -> children[2], arg_list);
				InterCodes* ics1 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
				ic1 -> kind = WRITE;
				ic1 -> u.write_no = arg_list[0];
				ics1 -> code = ic1;

				
				ics0 -> prev = NULL;
				InterCodes* ict = ics0;
				for(; ict -> next != NULL; ict = ict -> next);
				ict -> next = ics1;
				ics1 -> prev = ict;
				ics1 -> next = NULL;
				return ics0;
			}
			else{
				InterCodes* ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
				if(place != -1){
					ic2 -> kind = ASS;
					ic2 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
					ic2 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
					ic2 -> u.assign.left -> kind = TEMP;
					ic2 -> u.assign.left -> u.temp_no = place;
					next_temp_no ++;
					ic2 -> u.assign.right -> kind = FUN;
					memset(ic2 -> u.assign.right -> u.fun, 0, 20);
					strcpy(ic2 -> u.assign.right -> u.fun, (const char*)p -> children[0] -> val.type_ID);
				}
				else{
					ic2 -> kind = CALL;
					memset(ic2 -> u.call_func, 0, 20);
					strcpy(ic2 -> u.call_func, (const char*)p -> children[0] -> val.type_ID);
				}
				ics2 -> code = ic2;
				InterCodes* ics0 = translate_Args(p -> children[2], arg_list);
				InterCodes* ics1 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
				ic1 -> kind = ARG;
				ic1 -> u.arg_var_no = arg_list[0];
				ics1 -> code = ic1;
				InterCodes* ip = ics1;
			    ip -> prev = NULL;
			    ip -> next = NULL;
				int i;
				for( i = 1; i < 20; i ++){
					if(arg_list[i] != -1){
						//printf("arglist != -1\n");
						ip -> next = (InterCodes*)malloc(sizeof(InterCodes));
						InterCodes* iq = ip -> next;
						iq -> prev = ip;
						iq -> next = NULL;
						InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
						ic -> kind = ARG;
						ic -> u.arg_var_no = arg_list[i];
						iq -> code = ic;

						ip = iq;
					}
					else break;
				}
				
				
				ics0 -> prev = NULL;
				InterCodes* ict = ics0;
				for(; ict -> next != NULL; ict = ict -> next);
				ict -> next = ics1;
				ics1 -> prev = ict;
				ip -> next = ics2;
				ics2 -> prev = ip;
				ics2 -> next = NULL;

				return ics0;
			}
		}
	
		//case 14 Exp LB Exp RB
		if(strcmp(p -> children[1] -> name, "LB") == 0){
			// zhi shi xian yi wei shu zu, ji ID LB Exp RB
			node* q = p -> children[0] -> children[0];// ID
			node* t = p -> children[2];
			InterCodes *ics0;
			int temp = next_temp_no;
			next_temp_no ++;
			int temp1 = next_temp_no;
			next_temp_no ++;
			ics0 = translate_Exp(t, sym_table, temp1);
			int temp2 = next_temp_no;
			next_temp_no ++;
			InterCodes* ics_patch = (InterCodes*)malloc(sizeof(InterCodes));
			InterCode* ic_patch = (InterCode*)malloc(sizeof(InterCode));
			ic_patch -> kind = MUL;
			ic_patch -> u.binop.result = (Operand)malloc(sizeof(Operand_));
			ic_patch -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
			ic_patch -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
			ic_patch -> u.binop.result -> kind = TEMP;
			ic_patch -> u.binop.result -> u.temp_no = temp2;
			ic_patch -> u.binop.op1 -> kind = TEMP;
			ic_patch -> u.binop.op1 -> u.temp_no = temp1;
			ic_patch -> u.binop.op2 -> kind = CONSTANT;
			ic_patch -> u.binop.op2 -> u.value = 4;
			ics_patch -> code = ic_patch;

			InterCodes* ics1 = (InterCodes*)malloc(sizeof(InterCodes));
			InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
			ic1 -> kind = ADD;
			ic1 -> u.binop.result = (Operand)malloc(sizeof(Operand_));
			ic1 -> u.binop.op1 = (Operand)malloc(sizeof(Operand_));
			ic1 -> u.binop.op2 = (Operand)malloc(sizeof(Operand_));
			ic1 -> u.binop.result -> kind = TEMP;
			ic1 -> u.binop.result -> u.temp_no = temp;
			ic1 -> u.binop.op1 -> kind = ARRA;
			ic1 -> u.binop.op1 -> u.array_var_no = lookup(sym_table, q -> val.type_ID);
			ic1 -> u.binop.op2 -> kind = TEMP;
			ic1 -> u.binop.op2 -> u.temp_no = temp2;
			ics1 -> code = ic1;

			ics0 -> prev = NULL;
			InterCodes* ict0 = ics0;
			for(; ict0 -> next != NULL; ict0 = ict0 -> next);
			ict0 -> next = ics_patch;
			ics_patch -> prev = ict0;
			ics_patch -> next = ics1;
			ics1 -> prev = ics_patch;
			ics1 -> next = NULL;
			if(place != -1){
				InterCodes *ics2 = (InterCodes*)malloc(sizeof(InterCodes));
				InterCode *ic2 = (InterCode*)malloc(sizeof(InterCode));
				ic2 -> kind = ASS;
				ic2 -> u.assign.left = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.assign.right = (Operand)malloc(sizeof(Operand_));
				ic2 -> u.assign.left -> kind = TEMP;
				ic2 -> u.assign.left -> u.temp_no = place;
				ic2 -> u.assign.right -> kind = ADDRESS;
				ic2 -> u.assign.right -> u.addr_temp_no = temp;
				ics2 -> code = ic2;

				ics1 -> next = ics2;
				ics2 -> prev = ics1;
				ics2 -> next = NULL;

			}
			return ics0;
		}
	}
}

InterCodes* translate_Cond(node *p, int label_t, int label_f){// node* p: Exp
	if(strcmp(p -> children[0] -> name, "NOT") == 0){//case NOT Exp
		return translate_Cond(p -> children[1], label_f, label_t);
	}
	else if(p -> numOfChildren == 3){
		//case Exp RELOP Exp
		if(strcmp(p -> children[1] -> name, "RELOP") == 0){
			InterCodes *ics0, *ics1, *ics2, *ics3;

			int temp1 = next_temp_no;
			next_temp_no ++;
			int temp2 = next_temp_no;
			next_temp_no ++;
			ics0 = translate_Exp(p -> children[0], sym_table, temp1);
			ics1 = translate_Exp(p -> children[2], sym_table, temp2);

			ics2 = (InterCodes*)malloc(sizeof(InterCodes));
			ics3 = (InterCodes*)malloc(sizeof(InterCodes));

			InterCode *ic2, *ic3;
			ic2 = (InterCode*)malloc(sizeof(InterCode));
			ic3 = (InterCode*)malloc(sizeof(InterCode));

			ic2 -> kind = IF2;
			ic2 -> u.if2.temp_no1 = temp1;
			ic2 -> u.if2.temp_no2 = temp2;
			ic2 -> u.if2.label_no = label_t;
			ic2 -> u.if2.op = (char*)malloc(sizeof(20));
			strcpy(ic2 -> u.if2.op, (const char*)p -> children[1] -> val.type_RELOP);

			ic3 -> kind = GOTO;
			ic3 -> u.goto_no = label_f;

			ics2 -> code = ic2;
			ics3 -> code = ic3;

			ics0 -> prev = NULL;
			InterCodes* ict0 = ics0;
			for(; ict0 -> next != NULL; ict0 = ict0 -> next);
			ict0 -> next = ics1;
			ics1 -> prev = ict0;
			InterCodes* ict1 = ics1;
			for(; ict1 -> next != NULL; ict1 = ict1 -> next);
			ict1 -> next = ics2;
			ics2 -> prev = ics1;
			ics2 -> next = ics3;
			ics3 -> prev = ics2;
			ics3 -> next = NULL;

			return ics0;
		}
		//case Exp AND Exp
		else if(strcmp(p -> children[1] -> name, "AND") == 0){
			InterCodes *ics0, *ics1, *ics2;

			int label1 = next_label;
			next_label ++;

			ics0 = translate_Cond(p -> children[0], label1, label_f);
			ics2 = translate_Cond(p -> children[2], label_t, label_f);

			ics1 = (InterCodes*)malloc(sizeof(InterCodes));
			InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
			ic1 -> kind = LABEL;
			ic1 -> u.label_no = label1;
			ics1 -> code = ic1;

			ics0 -> prev = NULL;
			ics0 -> next = ics1;
			ics1 -> prev = ics0;
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			ics2 -> next = NULL;

			return ics0;
		}
		//case Exp OR Exp
		else if(strcmp(p -> children[1] -> name, "OR") == 0){
			InterCodes *ics0, *ics1, *ics2;

			int label1 = next_label;
			next_label ++;

			ics0 = translate_Cond(p -> children[0], label_t, label1);
			ics2 = translate_Cond(p -> children[2], label_t, label_f);

			ics1 = (InterCodes*)malloc(sizeof(InterCodes));
			InterCode* ic1 = (InterCode*)malloc(sizeof(InterCode));
			ic1 -> kind = LABEL;
			ic1 -> u.label_no = label1;
			ics1 -> code = ic1;

			ics0 -> prev = NULL;
			ics0 -> next = ics1;
			ics1 -> prev = ics0;
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			ics2 -> next = NULL;

			return ics0;
		}
		else{//other case/////////////////////////////////////////////////////////////////////
			//printf("Other case\n");
			InterCodes *ics0, *ics1, *ics2;

			int temp1 = next_temp_no;
			next_temp_no ++;

			ics0 = translate_Exp(p, sym_table, temp1);
			//code2 = [IF t1 != #0 GOTO label_true]
			//return code1 + code2 + [GOTO label_false]

			ics1 = (InterCodes*)malloc(sizeof(InterCodes));
			ics2 = (InterCodes*)malloc(sizeof(InterCodes));

			InterCode *ic1, *ic2;
			ic1 = (InterCode*)malloc(sizeof(InterCode));
			ic2 = (InterCode*)malloc(sizeof(InterCode));

			ic1 -> kind = IF1;
			ic1 -> u.if1.temp_no = temp1;
			ic1 -> u.if1.label_no = label_t;

			ic2 -> kind = GOTO;
			ic2 -> u.goto_no = label_f;

			ics1 -> code = ic1;
			ics2 -> code = ic2;

			ics0 -> prev = NULL;
			ics0 -> next = ics1;
			ics1 -> prev = ics0;
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			ics2 -> next = NULL;

			return ics0;
		}
	}
	else{//other case
			printf("Other case\n");
			InterCodes *ics0, *ics1, *ics2;

			int temp1 = next_temp_no;
			next_temp_no ++;

			ics0 = translate_Exp(p, sym_table, temp1);
			//code2 = [IF t1 != #0 GOTO label_true]
			//return code1 + code2 + [GOTO label_false]

			ics1 = (InterCodes*)malloc(sizeof(InterCodes));
			ics2 = (InterCodes*)malloc(sizeof(InterCodes));

			InterCode *ic1, *ic2;
			ic1 = (InterCode*)malloc(sizeof(InterCode));
			ic2 = (InterCode*)malloc(sizeof(InterCode));

			ic1 -> kind = IF1;
			ic1 -> u.if1.temp_no = temp1;
			ic1 -> u.if1.label_no = label_t;

			ic2 -> kind = GOTO;
			ic2 -> u.goto_no = label_f;

			ics1 -> code = ic1;
			ics2 -> code = ic2;

			ics0 -> prev = NULL;
			ics0 -> next = ics1;
			ics1 -> prev = ics0;
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			ics2 -> next = NULL;

			return ics0;
	}
}

int translate_VarDec(node *p){//zhi chi gao wei shu zu
	if(p -> numOfChildren == 1){// di gui chu kou
		char* id = (char*)malloc(sizeof(20));
		strcpy(id, (const char*)p -> children[0] -> val.type_ID);
		insert(sym_table, id);
		return 1;
	}
	else{// array
		
		return (p -> children[2] -> val.type_int) * translate_VarDec(p -> children[0]);
	}
}

InterCodes* translate_Dec(node *p){
	if(p -> numOfChildren == 1){
		if(p -> children[0] -> numOfChildren == 1){// bu shi shu zu, zhi xu tian biao, wu xu sheng cheng dai ma
			char* id = (char*)malloc(sizeof(20));
			strcpy(id, (const char*)p -> children[0] -> children[0] -> val.type_ID);
			insert(sym_table, id);

			return NULL;
		}
		else{// shu zu, xu yao sheng cheng dai ma
			int i;
			for( i = 0; sym_table[i] != NULL; i ++);
			int size = translate_VarDec(p -> children[0]);

			InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
			ic -> kind = DEC;
			ic -> u.dec.var_no = i;
			ic -> u.dec.size = size;
			InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));

			ics -> code = ic;
			ics -> prev = NULL;
			ics -> next = NULL;

			return ics;
		}
	}
	else{// assign, zuo zhi yi ding shi yi ge jian dan bian liang
		char *id = (char*)malloc(sizeof(20));
		strcpy(id, (const char*)p -> children[0] -> children[0] -> val.type_ID);

		int no = insert(sym_table, id);// fill the symbol table

		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		ic -> kind = ASS;
		ic -> u.assign.right = (Operand)malloc(sizeof(Operand_));
		ic -> u.assign.left = (Operand)malloc(sizeof(Operand_));

		ic -> u.assign.left -> kind = VARIABLE;
		ic -> u.assign.left -> u.var_no = no;

		ic -> u.assign.right -> kind = TEMP;
		ic -> u.assign.right -> u.temp_no = next_temp_no;
		//next_temp_no ++;
		InterCodes* ics0 = translate_Exp(p -> children[2], sym_table, next_temp_no);////////////////////////////
		

		InterCodes* ics1 = (InterCodes*)malloc(sizeof(InterCodes));
		ics1 -> code = ic;
		ics1 -> prev = NULL;
		ics1 -> next = NULL;

		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			InterCodes* ict0 = ics0;
			for(; ict0 -> next != NULL; ict0 = ict0 -> next);
			ict0 -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict0;
				ics1 -> next = NULL;
			}
			return ics0;
		}

	}
}

InterCodes* translate_DecList(node *p){
	if(p -> numOfChildren == 1){
		//printf("DecList BEGIN0\n");
		return translate_Dec(p -> children[0]);
	}
	else{
		//printf("DecList BEGIN1\n");
		InterCodes *ics0, *ics1;
		ics0 = translate_Dec(p -> children[0]);
		ics1 = translate_DecList(p -> children[2]);

		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			InterCodes* ict0 = ics0;
			for(; ict0 -> next != NULL; ict0 = ict0 -> next);
			ict0 -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict0;
				//ics1 -> next = NULL;
			}

			return ics0;
		}
	}
}

InterCodes* translate_Def(node *p){
	InterCodes* res = translate_DecList(p -> children[1]);
	//printf("Def FINISH\n");
	return res;
}

InterCodes* translate_DefList(node *p){
	if(p -> children[1] == NULL){
		return translate_Def(p -> children[0]);
	}
	else{
		InterCodes *ics0, *ics1;
		ics0 = translate_Def(p -> children[0]);
		ics1 = translate_DefList(p -> children[1]);

		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			InterCodes* ict0 = ics0;
			for(;ict0 -> next != NULL; ict0 = ict0 -> next);
			ict0 -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict0;
			}

			return ics0;
		}
	}
}

InterCodes* translate_Stmt(node *p){///////////////////////////////////
	//case 1 Exp SEMI
	//printf("%s\n", p -> children[0] -> name);
	if(strcmp(p -> children[0] -> name, "Exp") == 0){
		InterCodes* res = translate_Exp(p -> children[0], sym_table, -1);
		return res;
	}
	//case 2 CompSt
	if(strcmp(p -> children[0] -> name, "CompSt") == 0){
		return translate_CompSt(p -> children[0]);
	}
	//case 3 RETURN Exp SEMI
	if(strcmp(p -> children[0] -> name, "RETURN") == 0){
		InterCodes *ics0, *ics1;
		int temp = next_temp_no;
		next_temp_no ++;
		ics0 = translate_Exp(p -> children[1], sym_table, temp);
		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		ic -> kind = RET;
		ic -> u.return_temp_no = temp;

		ics1 = (InterCodes*)malloc(sizeof(InterCodes));
		ics1 -> code = ic;
		
		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			InterCodes* ict = ics0;
			for(; ict -> next != NULL; ict = ict -> next);
			ict -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict;
				ics1 -> next = NULL;
			}
			return ics0;
		}
	}
	//case 4 IF LP Exp RP Stmt
	if(strcmp(p -> children[0] -> name, "IF") == 0 && p -> numOfChildren == 5){
		InterCodes *ics0, *ics1, *ics2, *ics3;

		int label1 = next_label;
		next_label ++;
		int label2 = next_label;
		next_label ++;
		ics0 = translate_Cond(p -> children[2], label1, label2);
		ics1 = (InterCodes*)malloc(sizeof(InterCodes));
		ics2 = translate_Stmt(p -> children[4]);
		ics3 = (InterCodes*)malloc(sizeof(InterCodes));

		InterCode *ic1, *ic3;
		ic1 = (InterCode*)malloc(sizeof(InterCode));
		ic3 = (InterCode*)malloc(sizeof(InterCode));

		ic1 -> kind = LABEL;
		ic1 -> u.label_no = label1;
		ic3 -> kind = LABEL;
		ic3 -> u.label_no = label2;

		ics1 -> code = ic1;
		ics3 -> code = ic3;


		ics0 -> prev = NULL;
		InterCodes* ict0 = ics0;
		for(; ict0 -> next != NULL; ict0 = ict0 -> next);
		ict0 -> next = ics1;
		ics1 -> prev = ict0;
		if(ics2 != NULL){
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			InterCodes* ict2 = ics2;
			for(; ict2 -> next != NULL; ict2 = ict2 -> next);
			ict2 -> next = ics3;
			ics3 -> prev = ict2;
			ics3 -> next = NULL;
		}
		else{
			ics1 -> next = ics3;
			ics3 -> prev = ics1;
			ics3 -> next = NULL;
		}

		return ics0;
	}
	//case 5 IF LP Exp RP Stmt ELSE Stmt
	if(strcmp(p -> children[0] -> name, "IF") == 0 && p -> numOfChildren == 7){
		InterCodes *ics0, *ics1, *ics2, *ics3, *ics4, *ics5, *ics6;

		int label1 = next_label;
		next_label ++;
		int label2 = next_label;
		next_label ++;
		int label3 = next_label;
		next_label ++;

		ics0 = translate_Cond(p -> children[2], label1, label2);
		ics1 = (InterCodes*)malloc(sizeof(InterCodes));
		ics2 = translate_Stmt(p -> children[4]);
		ics3 = (InterCodes*)malloc(sizeof(InterCodes));
		ics4 = (InterCodes*)malloc(sizeof(InterCodes));
		ics5 = translate_Stmt(p -> children[6]);
		ics6 = (InterCodes*)malloc(sizeof(InterCodes));

		InterCode *ic1, *ic3, *ic4, *ic6;
		ic1 = (InterCode*)malloc(sizeof(InterCode));
		ic3 = (InterCode*)malloc(sizeof(InterCode));
		ic4 = (InterCode*)malloc(sizeof(InterCode));
		ic6 = (InterCode*)malloc(sizeof(InterCode));

		ic1 -> kind = LABEL;
		ic1 -> u.label_no = label1;
		ic3 -> kind = GOTO;
		ic3 -> u.goto_no = label3;
		ic4 -> kind = LABEL;
		ic4 -> u.label_no = label2;
		ic6 -> kind = LABEL;
		ic6 -> u.label_no = label3;

		ics1 -> code = ic1;
		ics3 -> code = ic3;
		ics4 -> code = ic4;
		ics6 -> code = ic6;

		ics0 -> prev = NULL;
		InterCodes* ict0 = ics0;
		for(; ict0 -> next != NULL; ict0 = ict0 -> next);
		ict0 -> next = ics1;
		ics1 -> prev = ict0;
		if(ics2 != NULL){
			ics1 -> next = ics2;
			ics2 -> prev = ics1;
			InterCodes* ict2 = ics2;
			for(; ict2 -> next!= NULL; ict2 = ict2 -> next);
			ict2 -> next = ics3;
			ics3 -> prev = ict2;
			ics3 -> next = ics4;
		}
		else{
			ics1 -> next = ics3;
			ics3 -> prev = ics1;
			ics3 -> next = ics4;
		}
		ics4 -> prev = ics3;
		if(ics5 != NULL){
			ics4 -> next = ics5;
			ics5 -> prev = ics4;
			InterCodes* ict5 = ics5;
			for(; ict5 -> next != NULL; ict5 = ict5 -> next);
			ict5 -> next = ics6;
			ics6 -> prev = ict5;
			ics6 -> next = NULL;
		}
		else{
			ics4 -> next = ics6;
			ics6 -> prev = ics4;
			ics6 -> next = NULL;
		}

		return ics0;
	}
	//case 6 WHILE LP Exp RP Stmt
	if(strcmp(p -> children[0] -> name, "WHILE") == 0){
		InterCodes *ics0, *ics1, *ics2, *ics3, *ics4, *ics5;

		int label1 = next_label;
		next_label ++;
		int label2 = next_label;
		next_label ++;
		int label3 = next_label;
		next_label ++;

		ics1 = translate_Cond(p -> children[2], label2, label3);
		ics3 = translate_Stmt(p -> children[4]);

		InterCode *ic0, *ic2, *ic4, *ic5;

		ic0 = (InterCode*)malloc(sizeof(InterCode));//label
		ic2 = (InterCode*)malloc(sizeof(InterCode));//label
		ic4 = (InterCode*)malloc(sizeof(InterCode));//goto
		ic5 = (InterCode*)malloc(sizeof(InterCode));//label

		ic0 -> kind = LABEL;
		ic0 -> u.label_no = label1;
		ic2 -> kind = LABEL;
		ic2 -> u.label_no = label2;
		ic4 -> kind = GOTO;
		ic4 -> u.goto_no = label1;
		ic5 -> kind = LABEL;
		ic5 -> u.goto_no = label3;

		ics0 = (InterCodes*)malloc(sizeof(InterCodes));
		ics2 = (InterCodes*)malloc(sizeof(InterCodes));
		ics4 = (InterCodes*)malloc(sizeof(InterCodes));
		ics5 = (InterCodes*)malloc(sizeof(InterCodes));

		ics0 -> code = ic0;
		ics2 -> code = ic2;
		ics4 -> code = ic4;
		ics5 -> code = ic5;

		ics0 -> prev = NULL;
		ics0 -> next = ics1;
		ics1 -> prev = ics0;
		InterCodes* ict1 = ics1;
		for(; ict1 -> next != NULL; ict1 = ict1 -> next);
		ict1 -> next = ics2;
		ics2 -> prev = ict1;
		if(ics3 != NULL){
			ics2 -> next = ics3;
			ics3 -> prev = ics2;
			InterCodes* ict3 = ics3;
			for(; ict3 -> next != NULL; ict3 = ict3 -> next);
			ict3 -> next = ics4;
			ics4 -> prev = ict3;
		}
		else{
			ics2 -> next = ics4;
			ics4 -> prev = ics2;
		}
		ics4 -> next = ics5;
		ics5 -> prev = ics4;
		ics5 -> next = NULL;

		return ics0;
	}
}

InterCodes* translate_StmtList(node *p){
	if(p -> children[1] == NULL){
		node *q = p -> children[0];// Stmt
		return translate_Stmt(q);
	}
	else{
		InterCodes *ics0, *ics1;
		ics0 = translate_Stmt(p -> children[0]);
		ics1 = translate_StmtList(p -> children[1]);

		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			InterCodes* ict = ics0;
			for(; ict -> next != NULL; ict = ict -> next);
			ict -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict;
			}
			//print_intercode(ics1);
			//printf("fenjiexian\n");
			return ics0;
		}
	}
}

InterCodes* translate_CompSt(node* p){
	if(p -> numOfChildren == 2){
		return NULL;
	}
	else if(p -> numOfChildren == 3){
		if(strcmp(p -> children[1] -> name, "DefList") == 0){
			InterCodes* res = translate_DefList(p -> children[1]);	
			//printf("location\n");	
			return res;
		}
		else if(strcmp(p -> children[1] -> name, "StmtList") == 0){
			InterCodes* res = translate_StmtList(p -> children[1]);		
			return res;
		}
		else{
			printf("unexpected error!\n");
			return NULL;
		}
	}
	else if(p -> numOfChildren == 4){
		InterCodes *ics0, *ics1;
		ics0 = translate_DefList(p -> children[1]);
		//printf("DefList completed\n");
		ics1 = translate_StmtList(p -> children[2]);
		//printf("StmtList completed\n");

		if(ics0 == NULL){
			//print_intercode(ics1);
			//printf("fenjiexian\n");
			return ics1;
		}
		else{
			ics0 -> prev = NULL;
			InterCodes* ict = ics0;
			for(; ict -> next != NULL; ict = ict -> next);
			ict -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ict;
			}
			//print_intercode(ics0);
			//printf("fenjiexian\n");
			return ics0;
		}
	}
	else{
		printf("unexpected error!\n");
		return NULL;
	}
}

InterCodes* translate_ParamDec(node *p){
	if(p -> children[1] -> numOfChildren == 1){// bu shi shu zu
		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		ic -> kind = PARA;

		int i;
		for( i = 0; i < 100; i ++){
			if(sym_table[i] == NULL)
				break;
		}

		sym_table[i] = (char*)malloc(sizeof(20));
		strcpy(sym_table[i], (const char*)p -> children[1] -> children[0] -> val.type_ID);

		ic -> u.para_var_no = i;

		InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
		ics -> code = ic;
		ics -> prev = NULL;
		ics -> next = NULL;

		return ics;
	}
	else{// xing can wei shu zu
		if(p -> children[0] -> children[0] -> flag == 4){//TYPE
			InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
			ic -> kind = DEC;

			int i;
			for( i = 0; i < 100; i ++){
				if(sym_table[i] == NULL)
					break;
			}

			sym_table[i] = (char*)malloc(sizeof(20));
			strcpy(sym_table[i], (const char*)p -> children[1] -> children[0] -> children[0] -> val.type_ID);

			ic -> u.dec.var_no = i;

			int num = p -> children[1] -> children[2] -> val.type_int;
			node* q = p -> children[0] -> children[0];
			if(strcmp(q -> val.type_Type, "int") == 0){
				ic -> u.dec.size = num;
			}
			//else if(strcmp(q -> val.type_TYPE, "float") == 0){
				//ic -> u.dec.size = num * 8;
			//}

			InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
			ics -> code = ic;
			ics -> prev = NULL;
			ics -> next = NULL;

			return ics;
		}
		else{
			printf("error: do not allow structure array!\n");
		}
	}
}

InterCodes* translate_VarList(node *p){
	if(p -> numOfChildren == 1){
		return translate_ParamDec(p -> children[0]);
	}
	else{
		InterCodes *ics0, *ics1;
		ics0 = translate_ParamDec(p -> children[0]);
		ics1 = translate_VarList(p -> children[2]);

		if(ics0 == NULL)
			return ics1;
		else{
			ics0 -> prev = NULL;
			ics0 -> next = ics1;
			if(ics1 != NULL){
				ics1 -> prev = ics0;
			}

			return ics0;
		}
	}
}

InterCodes* translate_FunDec(node *p){
	if(strcmp(p -> children[2] -> name, "RP") == 0){// no arguments
		InterCode* res = (InterCode*)malloc(sizeof(InterCode));
		res -> kind = FUNC;
		res -> u.func = (char*)malloc(sizeof(20));
		strcpy(res -> u.func, (const char*)p -> children[0] -> val.type_ID);
	    
	    InterCodes* ics = (InterCodes*)malloc(sizeof(InterCodes));
	    ics -> code = res;
	    ics -> prev = NULL;
	    ics -> next = NULL;

	    return ics;
	}
	else if(strcmp(p -> children[2] -> name, "VarList") == 0){
		InterCode* res = (InterCode*)malloc(sizeof(InterCode));
		res -> kind = FUNC;
		res -> u.func = (char*)malloc(sizeof(20));
		strcpy(res -> u.func, (const char*)p -> children[0] -> val.type_ID);

		InterCodes* ics0 = (InterCodes*)malloc(sizeof(InterCodes));
		ics0 -> code = res;

	    InterCodes* ics1 = translate_VarList(p -> children[2]);
	    ics0 -> prev = NULL;
	    ics0 -> next = ics1;
	    if(ics1 != NULL){
	    	ics1 -> prev = ics0;
	    }
		return ics0;
	}	
	else{
		printf("There is an unexpected bug! \n");
		return NULL;
	}
}

InterCodes* translate_ExtDef(node *p){
	if(strcmp(p -> children[1] -> name, "ExtDecList") == 0){// definition of variables
		//do nothing for now
		return NULL;
	}
	else if(strcmp(p -> children[1] -> name, "SEMI") == 0){// handle the definition of a structure
		//do nothing for now
		return NULL;
	}
	else if(strcmp(p -> children[1] -> name, "FunDec") == 0 && strcmp(p -> children[2] -> name, "CompSt") == 0){// definition of a function
		InterCodes *ics0, *ics1;
		ics0 = translate_FunDec(p -> children[1]);
		ics1 = translate_CompSt(p -> children[2]);

		ics0 -> prev = NULL;
		InterCodes* ict = ics0;
		for(; ict -> next != NULL; ict = ict -> next);
		ict -> next = ics1;
		if(ics1 != NULL){
			ics1 -> prev = ict;
			//printf("!= NULL\n");
		}
		//printf("== NULL\n");
		return ics0;
	}
	else if(strcmp(p -> children[1] -> name, "FunDec") == 0 && strcmp(p -> children[2] -> name, "SEMI") == 0){// declaration of a function
		//do nothing for now
		return NULL;
	}
}

InterCodes* translate_ExtDefList(node *p){
	if(p -> children[1] == NULL){
		return translate_ExtDef(p -> children[0]);
	}
	else{
		InterCodes* ics0 = translate_ExtDef(p -> children[0]);
		InterCodes* ics1 = translate_ExtDefList(p -> children[1]);

		ics0 -> prev = NULL;
		InterCodes* ict = ics0 -> next;
		for(; ict -> next != NULL; ict = ict -> next);
		ict -> next = ics1;
		if(ics1 != NULL){
			ics1 -> prev = ict;
		}
		return ics0;
	}
}

InterCodes* translate_Program(node *p){
	if(p -> numOfChildren == 1)
		return translate_ExtDefList(p -> children[0]);
	else return NULL;
}


void translate(node *root){
	intercs = translate_Program(root);
	var_count = item_count(sym_table);
	temp_count = next_temp_no;
}