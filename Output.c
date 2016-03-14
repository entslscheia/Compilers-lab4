#include "node.h"
#include "intercode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *stream;
//ASSIGN, ADD, SUB, MUL, DIVIDE, FUNC, PARA, DEC, RETURN, LABEL, GOTO, IF1, IF2, READ, WRITE, CALL, ARG
void print_intercode(InterCodes* ics, char* filename){
	stream = fopen( filename, "w+" );
	InterCodes* q = ics;
	for(; q != NULL; q = q -> next){
		InterCode* p = q -> code;
		if(p -> kind == ASS){
			if(p -> u.assign.left -> kind == VARIABLE){
				//VARIABLE, CONSTANT, ADDRESS, TEMP, NEGATIVE, FUN
				if(p -> u.assign.right -> kind == VARIABLE){
					fprintf(stream, "v%d := v%d\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.var_no);
				}
				else if(p -> u.assign.right -> kind == CONSTANT){
					fprintf(stream, "v%d := #%d\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.value);
				}
				else if(p -> u.assign.right -> kind == TEMP){
					fprintf(stream, "v%d := t%d\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == NEGATIVE){
					fprintf(stream, "v%d := #0 - t%d\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == FUN){
					fprintf(stream, "v%d := CALL %s\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.fun);
				}
				else if(p -> u.assign.right -> kind == ADDRESS){
					fprintf(stream, "v%d := *t%d\n", p -> u.assign.left -> u.var_no, p -> u.assign.right -> u.addr_temp_no);
				}
			}
			else if(p -> u.assign.left -> kind == TEMP){
				if(p -> u.assign.right -> kind == VARIABLE){
					fprintf(stream, "t%d := v%d\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.var_no);
				}
				else if(p -> u.assign.right -> kind == CONSTANT){
					fprintf(stream, "t%d := #%d\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.value);
				}
				else if(p -> u.assign.right -> kind == TEMP){
					fprintf(stream, "t%d := v%d\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == NEGATIVE){
					fprintf(stream, "t%d := #0 - t%d\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == FUN){
					fprintf(stream, "t%d := CALL %s\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.fun);
				}
				else if(p -> u.assign.right -> kind == ADDRESS){
					fprintf(stream, "t%d := *t%d\n", p -> u.assign.left -> u.temp_no, p -> u.assign.right -> u.addr_temp_no);
				}
			}
			else if(p -> u.assign.left -> kind == ADDRESS){
				if(p -> u.assign.right -> kind == VARIABLE){
					fprintf(stream, "*t%d := v%d\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.var_no);
				}
				else if(p -> u.assign.right -> kind == CONSTANT){
					fprintf(stream, "*t%d := #%d\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.value);
				}
				else if(p -> u.assign.right -> kind == TEMP){
					fprintf(stream, "*t%d := t%d\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == NEGATIVE){
					fprintf(stream, "*t%d := #0 - t%d\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.temp_no);
				}
				else if(p -> u.assign.right -> kind == FUN){
					fprintf(stream, "*t%d := CALL %s\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.fun);
				}
				else if(p -> u.assign.right -> kind == ADDRESS){
					fprintf(stream, "*t%d := *t%d\n", p -> u.assign.left -> u.addr_temp_no, p -> u.assign.right -> u.addr_temp_no);
				}
			}
		}
		else if(p -> kind == ADD){
			if(p -> u.binop.result -> kind == VARIABLE){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := v%d + v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := v%d + t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := v%d + #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := t%d + v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := t%d + t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := t%d + #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := #%d + v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := #%d + t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := #%d + #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == ARRA){
					fprintf(stream, "v%d := &t%d + t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.addr_temp_no, p -> u.binop.op2 -> u.temp_no);
				}
			}
			else if(p -> u.binop.result -> kind == TEMP){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := v%d + v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := v%d + t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := v%d + #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := t%d + v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := t%d + t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := t%d + #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := #%d + v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := #%d + t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := #%d + #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == ARRA){
					fprintf(stream, "t%d := &v%d + t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.array_var_no, p -> u.binop.op2 -> u.temp_no);
				}
			}
		}
		else if(p -> kind == SUB){
						if(p -> u.binop.result -> kind == VARIABLE){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := v%d - v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := v%d - t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := v%d - #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := t%d - v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := t%d - t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := t%d - #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := #%d - v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := #%d - t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := #%d - #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
			else if(p -> u.binop.result -> kind == TEMP){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := v%d - v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := v%d - t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := v%d - #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := t%d - v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := t%d - t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := t%d - #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := #%d - v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := #%d - t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := #%d - #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
		}
		else if(p -> kind == MUL){
						if(p -> u.binop.result -> kind == VARIABLE){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := v%d * v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := v%d * t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := v%d * #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := t%d * v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := t%d * t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := t%d * #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := #%d * v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := #%d * t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := #%d * #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
			else if(p -> u.binop.result -> kind == TEMP){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := v%d * v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := v%d * t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := v%d * #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := t%d * v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := t%d * t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						
						fprintf(stream, "t%d := t%d * #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := #%d * v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := #%d * t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := #%d * #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
		}
		else if(p -> kind == DIVIDE){
						if(p -> u.binop.result -> kind == VARIABLE){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := v%d / v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := v%d / t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := v%d / #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := t%d / v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := t%d / t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := t%d / #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "v%d := #%d / v%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "v%d := #%d / t%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "v%d := #%d / #%d\n", p -> u.binop.result -> u.var_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
			else if(p -> u.binop.result -> kind == TEMP){
				if(p -> u.binop.op1 -> kind == VARIABLE){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := v%d / v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := v%d / t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := v%d / #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.var_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == TEMP){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := t%d / v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := t%d / t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := t%d / #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.temp_no, p -> u.binop.op2 -> u.value);
					}
				}
				else if(p -> u.binop.op1 -> kind == CONSTANT){
					if(p -> u.binop.op2 -> kind == VARIABLE){
						fprintf(stream, "t%d := #%d / v%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.var_no);
					}
					else if(p -> u.binop.op2 -> kind == TEMP){
						fprintf(stream, "t%d := #%d / t%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.temp_no);
					}
					else if(p -> u.binop.op2 -> kind == CONSTANT){
						fprintf(stream, "t%d := #%d / #%d\n", p -> u.binop.result -> u.temp_no, p -> u.binop.op1 -> u.value, p -> u.binop.op2 -> u.value);
					}
				}
			}
		}
		else if(p -> kind == FUNC){
			fprintf(stream, "FUNCTION ");
			fprintf(stream, "%s ", p -> u.func);
			fprintf(stream, ":\n");
		}
		else if(p -> kind == PARA){
			fprintf(stream, "PARAM ");
			fprintf(stream, "v%d\n", p -> u.para_var_no);
		}
		else if(p -> kind == DEC){
			fprintf(stream, "DEC ");
			fprintf(stream, "v%d ", p -> u.dec.var_no);
			fprintf(stream, "%d\n", 4 * p -> u.dec.size);
		}
		else if(p -> kind == RET){
			fprintf(stream, "RETURN ");
			fprintf(stream, "t%d\n", p -> u.return_temp_no);
		}
		else if(p -> kind == LABEL){
			fprintf(stream, "LABEL ");
			fprintf(stream, "label%d ", p -> u.label_no);
			fprintf(stream, ":\n");
		}
		else if(p -> kind == GOTO){
			fprintf(stream, "GOTO label%d\n", p -> u.goto_no);
		}
		else if(p -> kind == IF1){
			fprintf(stream, "IF t%d != #0 GOTO label%d\n", p -> u.if1.temp_no, p -> u.if1.label_no);
		}
		else if(p -> kind == IF2){
			//IF t1 op t2 GOTO label_true
			fprintf(stream, "IF t%d %s t%d GOTO label%d\n", p -> u.if2.temp_no1, p -> u.if2.op, p -> u.if2.temp_no2, p -> u.if2.label_no);
		}
		else if(p -> kind == READ){
			fprintf(stream, "READ t%d\n", p -> u.read_no);
		}
		else if(p -> kind == WRITE){
			fprintf(stream, "WRITE t%d\n", p -> u.write_no);
		}
		else if(p -> kind == CALL){
			fprintf(stream, "CALL %s\n", p -> u.call_func);
		}
		else if(p -> kind == ARG){
			fprintf(stream, "ARG t%d\n", p -> u.arg_var_no);
		}
	}
}