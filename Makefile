all: codefr

codefr: lex.yy.c parser.tab.c main.c codefr.c
	gcc -o codefr lex.yy.c parser.tab.c main.c codefr.c

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

clean:
	rm -f codefr lex.yy.c parser.tab.c parser.tab.h
