digit [0-9]

%%

{digit}+ {printf ("Voce digitou o numero: %s", yytext); }
[a] {printf ("Voce digitou a !"); }
"se" {printf ("Voce digitou %s !", yytext); }
. ECHO;
\n ECHO;


%%

int yywrap (void) {
  return 1;
}

int main (void) {
  yylex();
  return 0;
}