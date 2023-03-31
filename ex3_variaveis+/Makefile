run: 
	bison -d tab_simb.y
	flex  tab_simb.l
	gcc -c tab_simb.tab.c
	gcc -c lex.yy.c
	gcc -o comp tab_simb.tab.o lex.yy.o
	rm -f *.o *.c *.h

clear:
	rm -f comp
