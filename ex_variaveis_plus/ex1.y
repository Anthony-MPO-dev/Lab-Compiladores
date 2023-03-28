%{ 
        #include <stdio.h>
        int yylex(void); 
        void yyerror(char *); 
        int sym[1024];
%}

%token INTEGER VARIABLE
%left '+''-'
%left '*''/'
%left '('')'

%union {
  struct variable {
    char code[2048];
    char name[32];
    } var;

};

%% 

program: 
        program statement '\n'
        | /*Empty*/
        ; 

statement: 
        E                       { printf("%d\n", $1); }
        | VARIABLE '=' E        { sym[$1] = $3; }
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
        '(' E ')'            { $$ = $2; }
        | VARIABLE           { $$ = sym[$1]; }   
        | INTEGER            { $$ = $1; } 
        ;
%% 


void yyerror(char *s) { 
        printf( "%s\n", s); 
} 

int main(void) { 
        yyparse(); 
        return 0; 
} 
