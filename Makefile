all: codefr

codefr: lex.yy.c parser.tab.c main.c expression.c ast.c symbol.c helpers.c module.c
	gcc -o codefr lex.yy.c parser.tab.c main.c ast.c expression.c symbol.c helpers.c module.c -lm

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

clean:
	rm -f codefr lex.yy.c parser.tab.c parser.tab.h