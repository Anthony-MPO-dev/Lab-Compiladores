%{
	#include <string.h>
	#include <stdio.h>
	#include "sintatico.tab.h"
	#include "symbolTable.h"
	void yyerror(char *); 
%}

ws [\t ]
letter [A-Za-z]
digit [0-9]


%%

"//".*\n\r  {
	cont_lines++;
}
"//".*\r\n  {
	cont_lines++;
}

"int"	{
	printf("Lexic: int found\n");
	strcpy(yylval.c.str, yytext);
	return INT;
}

"float"	{
	printf("Lexic: float found\n");
	strcpy(yylval.c.str, yytext);
	return FLOAT;
}

"string"	{
	printf("Lexic: string found\n");
	strcpy(yylval.c.str, yytext);
	return STR;
}

"read"	{
	printf("Lexic: read found\n");
	strcpy(yylval.c.str, yytext);
	return READ;
}

"write"	{
	printf("Lexic: write found\n");
	strcpy(yylval.c.str, yytext);
	return WRITE;
}

"if"	{
	printf("Lexic: if found\n");
	strcpy(yylval.c.str, yytext);
	return IF;
}

"else"	{
	printf("Lexic: else found\n");
	strcpy(yylval.c.str, yytext);
	return ELSE;
}

"while"	{
	printf("Lexic: while found\n");
	strcpy(yylval.c.str, yytext);
	return WHILE;
}

{digit}+ {
	printf("Lexic: int digit found\n");
	strcpy(yylval.c.str, yytext);
	return NUM_INT;
}

{digit}+[.]{digit}+  {
	printf("Lexic: float digit found\n");
	strcpy(yylval.c.str, yytext);
	return NUM_FLOAT;
}


{letter}({letter}|{digit}|_)* {
	printf("Lexic: id found\n");
	strcpy(yylval.c.str, yytext);
	return ID;
}

["]{letter}({letter}|{digit}|[.-;:={}+*()<>/%]|[ ]|_)*["] {
	printf("Lexic: literal_string found\n");
	strcpy(yylval.c.str, yytext);
	return LITERAL_STR;
}

"<="	{
	printf("Lexic: LE found\n");
	strcpy(yylval.c.str, yytext);
	return LE;
}

"=="	{
	printf("Lexic: == found\n");
	strcpy(yylval.c.str, yytext);
	return EQ;
}

">="	{
	printf("Lexic: GE found\n");
	strcpy(yylval.c.str, yytext);
	return GE;
}

"!="	{
	printf("Lexic: NE found\n");
	strcpy(yylval.c.str, yytext);
	return NE;
}



[-;:={}+*()<>/%"] {
	printf("Lexic: %c found\n", *yytext);
	//strcpy(yylval.str, yytext);
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
