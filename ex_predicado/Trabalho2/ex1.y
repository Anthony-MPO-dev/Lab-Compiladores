%{
        #include <string.h>
        #include <stdio.h>
        int yylex(void);
        void yyerror(char *);
%}

%union {
        char str[64];
};

%type <str> art subst sujeito predicado verbo complemento oracao
%token <str> O A GATO GATA CACHORRO COMIDA BISCOITO EH COME BONITO FEIO LINDA GOSTOSA

%%
oracao : sujeito predicado {
        strcpy($$,$1);
        strcat($$," ");
        strcat($$, $2);
        printf("A oração e: %s\n", $$);
        }

sujeito	: art subst { 
                strcpy($$,$1);
                strcat($$," ");
                strcat($$, $2);
                printf("O sujeito e: %s\n", $$);
		}
        ;                

art	: O { 
                printf("ART: %s\n",$$);
		}
        | A {
                printf("ART: %s\n",$$);
		}
        ;
        
subst	: GATO {
                printf("SUBST: %s\n",$$);
		}
        | GATA {
                printf("SUBST: %s\n",$$);
		}
        | CACHORRO {
                printf("SUBST: %s\n",$$);
		}
        | COMIDA { 
                printf("SUBST: %s\n",$$);
		}
        | BISCOITO {
                printf("SUBST: %s\n", $$);
                }
        | GOSTOSA {
                printf("SUBST: %s\n", $$);
                }
        ;

predicado: verbo complemento {
        strcpy($$,$1);
        strcat($$," ");
        strcat($$, $2);
        printf("O predicado e: %s\n", $$);
        }
        ;

verbo:  EH {
        printf("VERBO: %s\n",$$);
        }
        | COME {
        printf("VERBO: %s\n",$$);        
        }
        ;

complemento: BONITO {
        printf("COMPLEMENTO: %s\n",$$);
        }
        | FEIO {
        printf("COMPLEMENTO: %s\n",$$);        
        }
        | LINDA {
        printf("COMPLEMENTO: %s\n",$$);        
        }
        | subst {
        printf("SUBSTANTIVO: %s\n", $$);
        }
        ;


%%

void yyerror(char *s) {
        printf("%s\n",s);

}

int main (void) {
        yyparse();
        return 0;
}