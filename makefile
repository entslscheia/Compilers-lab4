parser: syntax.tab.c lex.yy.c syntax.tab.c node.c symboltable.c intercode.c Output.c target.c
	gcc main.c syntax.tab.c node.c symboltable.c intercode.c Output.c target.c -lfl -ly -o parser

syntax.tab.c: syntax.y
	bison -d syntax.y

lex.yy.c: lexical.l
	flex lexical.l


clean:
	rm -rf parser
	rm -rf syntax.tab.h
	rm -rf syntax.tab.c
	rm -rf lex.yy.c
