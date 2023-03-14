%{ 
    #include <stdio.h>
    int yylex(void); 
    void yyerror(char *); 
%} 
%token INTEGER 
%left '+' '-' '*' '/' ')' '('
%% 

/*
        G = { {E,T,F,NUM}, {+,-,*,/,(,),0,1,2,3,4,5,6,7,8,9}, E, P}, onde 
        P = {
        E --> E + T | E - T | T , 
        T --> T * F | T / F | F , 
        F --> ( E ) | NUM
        NUM --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
        }
*/ 
program: 
        program expr '\n'       { printf("%d\n", $2); } 
        | '(' expr ')' '\n'          { printf("(%d)\n", $2);}
	| /* Empty */ 
        ; 
expr: 
        INTEGER                 { $$ = $1; } 
	| expr '+' expr		{ $$ = $1 + $3; } 
	| expr '-' expr         { $$ = $1 - $3; }
        | expr '*' expr		{ $$ = $1 * $3; } 
        | expr '/' expr		{ $$ = $1 * $3; }  
        ; 
%% 
void yyerror(char *s) { 
    printf( "%s\n", s); 
} 

int main(void) { 
    yyparse(); 
    return 0; 
} 
