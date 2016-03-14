#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "intercode.h"

extern FILE* yyin;
node *root = NULL;
InterCodes* intercs;
int main(int argc, char** argv)
{
	if ( argc <= 3 ) return 1;
	FILE* f = fopen(argv[1], "r");
	if ( !f )
	{
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	print_intercode(intercs, argv[2]);
	trans_code(argv[3]);
	return 0;
}


