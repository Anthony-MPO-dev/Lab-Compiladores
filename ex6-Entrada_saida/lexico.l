%{
	#include <string.h>
	#include <stdio.h>
	#include "sintatico.tab.h"
	#include "symbolTable.h"
	void yyerror(char *); 
%}

ws [ \t]
letter [A-Za-z]
digit [0-9]



%%

"//".*\n\r  {
	cont_lines++;
}
"//".*\r\n  {
	cont_lines++;
}

"var"	{
	printf("Lexic: var found\n");
	strcpy(yylval.c.str, yytext);
	return VAR;
}

"int"	{
	printf("Lexic: int found\n");
	strcpy(yylval.c.str, yytext);
	return INT;
}

"read"	{
	printf("Lexic: READ\n");
	strcpy(yylval.c.str, yytext);
	return READ;
}

"write"	{
	printf("Lexic: WRITE\n");
	strcpy(yylval.c.str, yytext);
	return WRITE;
}

"writeln"	{
	printf("Lexic: WRITELN\n");
	strcpy(yylval.c.str, yytext);
	return WRITELN;
}

{digit}+  {
	strcpy(yylval.c.str, yytext);
	return NUM;
}


{letter}({letter}|{digit}|_)*	{
	printf("Lexic: ID\n");
	strcpy(yylval.c.str, yytext);
	return ID;
}


[-;:={}+*()<>/%] {
	printf("Lexic: %c found\n", *yytext);
	// strcpy(yylval.str, yytext);
	return *yytext;
}


{ws}           { }

\n\r             { cont_lines++; }
\r\n             { cont_lines++; }


. { yyerror("Invalid character"); }

%%

int yywrap (void)
{
 	return 1;
}
