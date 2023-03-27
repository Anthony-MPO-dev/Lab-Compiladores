%{
#include <string.h>
#include <stdio.h>
#include "ex1.tab.h"

%}
ws [ \t]
%%
ws           { }

"o"          { strcpy( yylval.str,yytext);  return O;}
"a"          { strcpy(yylval.str,yytext); return A; }
"gato"       { strcpy( yylval.str,yytext);  return GATO; }
"gata"       { strcpy( yylval.str,yytext);  return GATA; }
"cachorro"   { strcpy(yylval.str,yytext); return CACHORRO;}
"cachorro"   { strcpy(yylval.str,yytext); return CACHORRO;}
"comida"     { strcpy(yylval.str,yytext); return COMIDA;}
"biscoito"   { strcpy(yylval.str,yytext); return BISCOITO;}
"eh"         { strcpy(yylval.str,yytext); return EH;}
"come"       { strcpy(yylval.str,yytext); return COME;}
"bonito"     { strcpy(yylval.str,yytext); return BONITO;}
"feio"       { strcpy(yylval.str,yytext); return FEIO;}
"linda"      { strcpy(yylval.str,yytext); return LINDA;}
"gostosa"    { strcpy(yylval.str,yytext); return GOSTOSA;}

%%

int yywrap (void)
{
  return 1;
}