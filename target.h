#ifndef _TARGET_H_
#define _TARGET_H_
#include <stdio.h>

int offset_sum;
int arg_num;
int max_offset;
int* offset_record;
FILE* f2; //= fopen("out_target.txt", "w+" );

void trans_code(char *filename);

#endif