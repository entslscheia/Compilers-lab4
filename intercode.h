#ifndef _INTERCODE_H_
#define _INTERCODE_H_

#include "node.h"

typedef struct Operand_* Operand;
typedef struct Operand_ Operand_;
typedef struct InterCode InterCode;
typedef struct  InterCodes InterCodes;
typedef struct sym_item sym_item;




struct Operand_ {
	enum { VARIABLE, CONSTANT, ADDRESS, TEMP, NEGATIVE, FUN, ARRA} kind;
	union {
		int var_no;
		int array_var_no;
		int addr_temp_no;
		int temp_no;
		int value;
		int neg_temp_no;
		char fun[20];
	} u;
};

struct InterCode
{
	enum { ASS, ADD, SUB, MUL, DIVIDE, FUNC, PARA, DEC, RET, LABEL, GOTO, IF1, IF2, READ, WRITE, CALL, ARG} kind; // IF1:IF t1 != #0 GOTO label_true 	IF2:IF t1 op t2 GOTO label_true
	union {
		struct { Operand right, left; } assign;
		struct { Operand result, op1, op2; } binop;
		char* func;
		int para_var_no;
		struct { int size; int var_no; } dec;
		int return_temp_no;
		int label_no;
		int goto_no;
		struct { int temp_no; int label_no; } if1;
		struct { int temp_no1; int temp_no2; int label_no; char* op; } if2;
		int read_no;
		int write_no;
		char call_func[20];
		int arg_var_no;// shi can bian liang xia biao
	} u;
};

struct InterCodes 
{ 
	InterCode* code; 
	InterCodes* prev;
	InterCodes* next; 
};

char* sym_table[100];

//void initial_codelist(InterCodes*);
//void add_code(InterCodes*, InterCode*);

void initial_table(char* []);
int insert(char* [], char *);
int lookup(char* [], char *);// fan hui id dui ying bian liang ming de xia biao
void translate(node *);
void print_intercode(InterCodes *, char *);
InterCodes* translate_Program(node *);
InterCodes* translate_ExtDefList(node *);
InterCodes* translate_ExtDef(node *);
InterCodes* translate_CompSt(node *);
InterCodes* translate_FunDec(node *);
InterCodes* translate_VarList(node*);// fan hui han shu xing can ge shu bing tian fu hao biao
InterCodes* translate_Exp(node *, char* [], int);
InterCodes* translate_Args(node *, int []);
InterCodes* translate_Cond(node *, int, int);
InterCodes* translate_ParamDec(node *);
InterCodes* translate_Def(node *);
InterCodes* translate_DefList(node *);
InterCodes* translate_StmtList(node *);
InterCodes* translate_DecList(node *);
InterCodes* translate_Dec(node *);
int translate_VarDec(node *);// ruo wei jian dan bian liang fan hui 1, gou ze fan hui shu zu da xiao
InterCodes* translate_Stmt(node *);


#endif