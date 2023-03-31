%{ 
    #include <stdio.h>
    #include <stdlib.h> 
    void yyerror(char *); 
    #include "tab_simb.tab.h" 
%} 

%% 

[a-zA-Z][a-zA-Z0-9]*   {yylval = 0;

    for (int i = 0; yytext[i] != '\0'; i++) {
        yylval += yytext[i] - 'a' + 1;
    }

    printf("Variavel: %s - indice %d\n", yytext, yylval);
    return VARIABLE; 
} 

[0-9]+      { 	yylval = atoi(yytext);
		printf("Valor inteiro: %d\n",yylval);
                return INTEGER; } 
[-+()=/*\n] { 	
		printf("Operador: %c\n", yytext[0]);
		return *yytext; } 

[ \t]    	; 

.             	yyerror("invalid character"); 

%%

int yywrap(void) { 
    return 1; 
} 
