run: 
	bison -d ex1.y
	flex ex1.l
	gcc -c ex1.tab.c
	gcc -c lex.yy.c
	gcc -o comp ex1.tab.o lex.yy.o
	rm -f *.o *.c *.h

clear:
	rm -f *.o *.c *.h comp
