scc:  sintatico.tab.o  lex.yy.o main.o codeGeneration.o
	gcc lex.yy.o sintatico.tab.o main.o codeGeneration.o -o scc
	
	
lex.yy.o:   lex.yy.c
	gcc -c lex.yy.c
	
sintatico.tab.o:  sintatico.tab.c
	gcc -c sintatico.tab.c

lex.yy.c:  lexico.l
	flex lexico.l

	
sintatico.tab.c:   sintatico.y
	bison -d sintatico.y -o sintatico.tab.c
	
main.o:  main.c
	gcc -c main.c 

codeGeneration.o: codeGeneration.c 
	gcc -c codeGeneration.c  