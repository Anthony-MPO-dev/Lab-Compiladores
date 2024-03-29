%{ 
        #include <stdio.h>
        int yylex(void); 
        void yyerror(char *); 
        int sym[26];
%}

%token INTEGER VARIABLE
%left '+''-''*''/'')''('
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
        program statement '\n'
        |
        ; 

statement: 
        E { printf("%d\n", $1); }
        ;
E: 
        
        E '+' T		{ $$ = $1 + $3; } 
	| E '-' T       { $$ = $1 - $3; }
        | T             
        ;               
T:      
        T '*' F		{ $$ = $1 * $3; } 
        | T '/' F	{ $$ = $1 / $3; }
        | F  
        ;
F:      
        '(' E ')'            {$$ = $2; }
        | INTEGER             { $$ = $1; } 
        ;
%% 
void yyerror(char *s) { 
        printf( "%s\n", s); 
} 

int main(void) { 
        yyparse(); 
        return 0; 
} 
