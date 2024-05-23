/**
 * @file synt.c
 * @author Prof. Ivairton M. Santos - UFMT - Computacao
 * @author Acad. Anthony M. P. de Oliveira  - UFMT - Computacao
 * @brief Codificacao do modulo do analisador sintatico
 * @version 0.4
 * @date 2022-02-04
 *
 */

// Inclusao do cabecalho
#include "synt.h"

// Variaveis globais
type_token *lookahead;
extern type_symbol_table_variables global_symbol_table_variables;
extern type_symbol_table_string symbol_table_string;
extern type_symbol_function symfuncs[MAX_FUNCS];
extern char output_file_name[MAX_CHAR];
extern FILE *output_file;
extern int symfuncspos;

/**
 * @brief Verifica se o proximo caracter (a frente) na cadeia eh o esperado
 *
 * @param token_tag (int) codigo do token a ser verificado
 * @return int true/false
 */
int match(int token_tag)
{
    if (lookahead->tag == token_tag)
    {
        lookahead = getToken(); // Pega o proximo token por meio do lexico
        return true;
    }
    printf("[ERRO] Entrada esperada: %s\n", lookahead->lexema);
    return false;
}

/**
 * @brief Regra de derivacao inicial
 */
void program(void)
{
    gen_preambule(); // Temporariamente cria um preambulo adicional que permite o uso das funcoes scanf e printf
    declarations();
    gen_preambule_code(); // Chamada do gerador de codigo para escrita do cabecalho da secao de codigo
    
    //#Begin
    if(lookahead->tag == BEGIN){
        match(BEGIN); //identifica inicio da função principal
        statements();
        if (lookahead->tag == END){
            //#end
            match(END);
            //#codigo das funcoes
            Func_code();

            gen_epilog_code();
            gen_data_section(); // Chamada do gerador de codigo para declaracao de variaveis
        } else{
            printf("[ERROR] Função principal esperando por comando de fechamento 'END' ");
        }
    }else{
        printf("[ERROR] Função principal não iniciada comando 'BEGIN' esperado");
    }
    
}

/**
 * @brief Regra de derivacao para declaracoes
 */
void declarations(void)
{
    while (declaration())
        ; // Laco para processamento continuo das declaracoes
}

/**
 * @brief Regra de derivacao declaracao
 * @return int true/false
 */
int declaration(void)
{
    char var_name[MAX_CHAR];
    int var_type;

    // Verifica o tipo da variavel
    var_type = lookahead->tag;
    if (var_type == INT || var_type == FLOAT || var_type == CHAR || var_type == STRING)
    {
        match(var_type);
        strcpy(var_name, lookahead->lexema);


        if (lookahead->tag == ID){
            match(ID);
        }else{
            printf("[ERRO] Impossivel realizar declaracao de '%s' simbolo id -> identificador esperado.\n", var_name);
            return false;
        }


        if (lookahead->tag == SEMICOLON){      
            
            if(declarationV(var_type, &var_name) != NULL){//declaracao da variavel
                return true;
            }else{
                return false;
            }
            
        }

        else if (lookahead->tag == OPEN_PAR){
             if(declarationF(var_type, &var_name) != NULL){ // processamento das declaracoes de funcoes
                 return true;
            }else{
                return false;
            }
        }else{
            printf("[ERROR] impossivel realizar declaracao codigo desconhecido esperado ';' ou '('\n");
            return false;
        }
        
    }
    else if (lookahead->tag == ENDTOKEN ||
             lookahead->tag == BEGIN ||
             lookahead->tag == READ ||
             lookahead->tag == WRITE)
    {
        // Verifica se fim de arquivo
        return false;
    }
    else
    {
        printf("[ERRO] Tipo desconhecido: %d %s.\n", lookahead->tag, lookahead->lexema);
        return false;
    }
}


/**
 * @brief Regra de derivacao para variaveis
 */
type_symbol_table_entry *declarationV(int var_type, char *var_name){
    type_symbol_table_entry *search_symbol;
    type_symbol_table_entry *variavel; 
    int ok1;

    //Verifica se variavel ja foi cadastrada antes
    search_symbol = sym_find(var_name, &global_symbol_table_variables);

    //se ja foi cadastrada anteriormente
    if (search_symbol != NULL)
    {
        printf("[ERRO] Variavel '%s' ja declarada.\n", var_name);
        return NULL;
    }

    variavel = sym_declare(var_name, var_type, 0, &global_symbol_table_variables);       

    if (lookahead->tag == SEMICOLON){
            match(SEMICOLON); // Verifica se ; vem a seguir
            return variavel;
    } else if (lookahead->tag == COMMA || CLOSE_PAR){
        return variavel;

    } else{
        printf("[ERRO] Variavel '%s' não pode ser declarada simbolo ';' ou para variaveis de escopo de funcao eh esperado ',' ou ')'.\n", var_name);
        return NULL;
    } 
}


/**
 * @brief Regra de derivacao para declaracoes das funcoes
 */
type_symbol_table_entry *declarationF(int func_type, char *func_name){
    int nparams;
    type_symbol_function *search_func_symbol;
    type_symbol_table_entry *params[MAX_PARAMS];
    char func_begin[MAX_CHAR];
    int ok1, ok2;

    
    //Verifica se a funcao ja foi cadastrada antes
    search_func_symbol = sym_func_find(func_name);

    //se foi cadastrada
    if (search_func_symbol != NULL)
    {
        printf("[ERRO] Funcao '%s' ja declarada.\n", func_name);
        return NULL;
    }
    //Se não foi cadastrada
    else{
        int func_variables = true;  
        int nparams =0; // zera numero de parametros para nova funcao

        
        match(OPEN_PAR);//match no inicio da declaracao de variaveis da funcao

        while(func_variables && nparams < MAX_PARAMS){
            type_symbol_table_entry *variavel; 
            char *var_name[MAX_CHAR];
            int var_type;

            // Verifica o tipo davariavel
            var_type = lookahead->tag;
            if (var_type == INT || var_type == FLOAT || var_type == CHAR || var_type == STRING)
            {
                match(var_type);
                strcpy(var_name, lookahead->lexema);

                if(lookahead->tag == ID){
                    match(ID);
                }else{
                    printf("[ERROR] Esperado ID identificador da variavel da funcao\n"); 
                    return NULL;
                }

                variavel = declarationV(var_type, var_name);

                if( variavel != NULL){//declaracao da variavel
                    params[nparams++] = variavel;
                }else{
                    printf("[ERROR] criação de função mal sucedida\n");
                    return NULL;
                }                  

            } else if (lookahead->tag == COMMA){                   
                match(COMMA);
                if (lookahead->tag == INT || lookahead->tag == FLOAT || lookahead->tag == CHAR || lookahead->tag == STRING){
                    func_variables = true;
                }else{
                    printf("[ERROR] Criação na declaracao de funcao esperado declaracao de variavel após a ','\n");
                    return false;
                }
            }else if (lookahead->tag == CLOSE_PAR){                   
                func_variables = false;
            }else{
                printf("[ERROR] Criação de função mal sucedida simbolo ',' esperado\n entre uma declaracao das variaveis da funcao");
                return false;
            }

        }

        ok1 = match(CLOSE_PAR);
        ok2 = match(SEMICOLON);

        if (ok1 && ok2){       
            
            gen_label_name(&func_begin);            
            return sym_func_declare(func_name, func_type, params, nparams, &func_begin);

        }else{
            printf("[ERROR] criação de função mal sucedida simbolo '%s' esperado no final da declaracao de funcao", lookahead->lexema);
            return NULL;
        }

    }        
        
}       
                      

/**
 * @brief Regra de derivacao para comandos
 */
void statements(void)
{
    while (statement())
        ; // processa enquanto houver comandos
}

/**
 * @brief Regra de derivacao que processa os comandos
 *
 * @return int true/false
 */
int statement(void)
{
    char lexeme_of_id[MAX_CHAR];
    type_symbol_table_entry *search_symbol;
    type_symbol_table_string_entry *gen_string;
    int ok1, ok2, type;
    char string_value[MAX_CHAR];

    if (lookahead->tag == ID)
    {
        strcpy(lexeme_of_id, lookahead->lexema);
        
        match(ID);        
        if (lookahead->tag == ASSIGN){

            if (search_symbol != NULL){  

                search_symbol = sym_find(lexeme_of_id, &global_symbol_table_variables);
            
                match(ASSIGN);

                if (lookahead->tag == '(')
                {
                    E();
                    type = search_symbol->type;
                    gen_assing(lexeme_of_id, type);
                    if (lookahead->tag == ';')
                    {
                        match(SEMICOLON);
                    }
                    else
                    {
                        printf("[ERRO] Entrada esperada: %s\n", lookahead->lexema);
                        return false;
                    }
                }
                else
                {
                    printf("[ERRO] Expressão aritmética esperada");
                    return false;
                }
            }
            else{
                printf("[ERRO] Simbolo desconhecido (Variavel nao declarada): %s\n", lexeme_of_id);
                return false;
            
            }
        }
        else if (lookahead->tag == OPEN_PAR){
            if (func_call_cmd(lexeme_of_id)){
                return true;
            }else{
                printf("[ERRO] Chamada de funcao mal sucedida!");
                return false;
            }
        }
        else
        {
            printf("[ERRO] Comando desconhecido esperado simbolo de atribuicao");
            return false;
        }
       
    }
    else if (lookahead->tag == READ)
    {
        match(READ);
        strcpy(lexeme_of_id, lookahead->lexema);
        ok1 = match(ID);
        search_symbol = sym_find(lexeme_of_id, &global_symbol_table_variables);
        if (search_symbol != NULL)
        {
            type = search_symbol->type;
            gen_read(lexeme_of_id, type);
            ok2 = match(SEMICOLON);
            return ok1 && ok2;
        }
        else
        {
            printf("[ERRO] Simbolo desconhecido (Variavel nao declarada): %s\n", lexeme_of_id);
            return false;
        }
    }
    else if (lookahead->tag == WRITE)
    {
        match(WRITE);
        if (lookahead->tag == STRING)
        {
            strcpy(string_value, lookahead->lexema);
            // TODO: verificar se o valor da constante ja foi incluida na tabela de simbolos
            gen_string = sym_string_declare(string_value);
            match(STRING);
            if (gen_string != NULL)
            {
                strcpy(lexeme_of_id, gen_string->name);
                gen_write(lexeme_of_id, STRING);
                match(SEMICOLON);
            }
        }
        else if (lookahead->tag == ID)
        {
            strcpy(lexeme_of_id, lookahead->lexema);
            match(ID);
            search_symbol = sym_find(lexeme_of_id, &global_symbol_table_variables);
            if (search_symbol != NULL)
            {
                type = search_symbol->type;
                gen_write(lexeme_of_id, type);
                match(SEMICOLON);
                return true;
            }
            else
            {
                printf("[ERRO] Simbolo desconhecido (Variavel nao declarada): %s\n", lexeme_of_id);
                return false;
            }
        }
    }
    else if (lookahead->tag == IF)
    {
        char label_else[MAX_CHAR];
        char label_end[MAX_CHAR];
        gen_label_name(label_else);
        gen_label_name(label_end);

        match(IF);
        match(OPEN_PAR);
        B(); // Expressao booleana
        gen_cond_jump(label_else);
        match(CLOSE_PAR);

        match(BEGIN);
        statements();
        match(END);

        gen_incond_jump(label_end);
        gen_label(label_else);

        // Verifica se ocorre um ELSE
        if (lookahead->tag == ELSE)
        {
            match(ELSE);
            match(BEGIN);
            statements();
            match(END);
        }
        gen_label(label_end);
        return true;
    }
    else if (lookahead->tag == WHILE)
    {
        char label_begin[MAX_CHAR];
        char label_end[MAX_CHAR];
        gen_label_name(label_begin);
        gen_label_name(label_end);

        match(WHILE);
        match(OPEN_PAR);
        gen_label(label_begin);
        B(); // Expressao booleana
        gen_cond_jump(label_end);
        match(CLOSE_PAR);
        match(BEGIN);
        statements();
        match(END);
        gen_incond_jump(label_begin);
        gen_label(label_end);
        return true;
    }
    else if (lookahead->tag == ENDTOKEN || lookahead->tag == END)
    {
        return false;
    }
    else
    {
        printf("[ERRO] Comando desconhecido.\nTag=%d; Lexema=%s\n", lookahead->tag, lookahead->lexema);
        return false;
    }
}

/**
 * @brief Regra de derivação chamada de funcao
 *
 *
 */
////// TODO
int func_call_cmd(char *func_name)
{
    type_symbol_function *search_func_symbol;
    char label_retorno[MAX_CHAR];


     //Verifica se a funcao ja foi cadastrada antes
    search_func_symbol = sym_func_find(func_name);

    //se não cadastrada
    if (search_func_symbol == NULL)
    {
       printf("[ERRO] Funcao '%s' nao declarada.\n", func_name);
        return false;
    }
    //Se foi cadastrada
    else{
        match(OPEN_PAR);
        type_token call_params[MAX_PARAMS];
        int num_params = search_func_symbol->nparams, i = true, n = 0, k = 0;
        char value[MAX_CHAR];

        while(i){
            if (lookahead->tag == NUM){
                strcpy(call_params[n].lexema, lookahead->lexema);
                strcpy(value, lookahead->lexema);

                //verifica se lexema é um numero inteiro ou flutuante
                call_params[n].tag = 0;
                while(value[k] != '\0'){
        
                    while(isdigit(value[k])){
                        k++;
                    }

                    if ( value[k] == '.' ) {
                        k++;
                        while(isdigit(value[k])){
                            k++;
                        }
                        call_params[n].tag = FLOAT;
                    }            
                }
                if (call_params[n].tag == 0){
                    call_params[n].tag = INT;
                }

                match(lookahead->tag);
                n++;

            }else if (lookahead->tag == ID){
                type_symbol_table_entry *search_symbol = sym_find(lookahead->lexema, &global_symbol_table_variables);
               if (search_symbol != NULL)
               {
                   call_params[n].tag = ID; 
                   strcpy(call_params[n].lexema, search_symbol->name);
                   match(lookahead->tag);
                   n++;
               }
               else
               {
                   printf("[ERRO] Simbolo desconhecido (Variavel passada por parametro nao declarada): %s\n", lookahead->lexema);
                   return false;
                }
            }else if(lookahead->tag == CHAR || lookahead->tag == STRING){
                call_params[n].tag = lookahead->tag; 
                strcpy(call_params[n].lexema, lookahead->lexema);
                match(lookahead->tag);
                n++;
            }else if (lookahead->tag == COMMA){
                match(COMMA);   
                 if (lookahead->tag == NUM || lookahead->tag == CHAR || lookahead->tag == STRING){
                    i = true;
                }else{
                    printf("[ERROR] Criação na declaracao de funcao esperado declaracao de variavel após a ','");
                    return false;
                }
            } else if (lookahead->tag == CLOSE_PAR){
                i = false;
                match(CLOSE_PAR);
                break;
            }else{
                printf("[ERRO] Não foi possivel chamar a funcao parametros passados sao invalidos!");
                return false;
            }
        }

        if (n > num_params || n < num_params){
            printf("[ERROR] Numero de parametros passados eh inválido\n");
            return false;
        }else{

            int j=0;
            type_symbol_table_entry *var_func;
            while (j < num_params){

                var_func = sym_find(search_func_symbol->params[j].name, &global_symbol_table_variables);

                if (call_params[j].tag == ID){
                    type_symbol_table_entry *search_symbol = sym_find(call_params[j].lexema, &global_symbol_table_variables);
                    if(var_func->type != search_symbol->type){
                        printf("[ERROR] Parametro %s de tipo invalido, tipo esperado %d\n", call_params[j].lexema, search_symbol->type);
                        return false;
                    }
                }else if (var_func->type != call_params[j].tag){
                    printf("[ERROR] Parametro %s de tipo invalido, tipo esperado %d\n", call_params[j].lexema, call_params[j].tag);
                    return false;
                }                
                j++;
            }
        }

        if (lookahead->tag == SEMICOLON){
            match(SEMICOLON);

            //gera label de retorno
            gen_label_name(label_retorno);
            // armazena label de retorno dentro da funcao
            strcpy(search_func_symbol->label_retorno, label_retorno);
            //Imprime o label de retorno
            gen_label(label_retorno);
            //CHAMA LABEL DE CHAMADA DO PROTOTIPO DA FUNCAO AQUI
            gen_incond_jump(search_func_symbol->label_comandos);            
            return true;

        }else{
            printf("[ERROR] Comando invalido esperado %d\n", SEMICOLON);
        }
        

    }
    
}

/**
 * @brief Regra de derivacao para funcoes
 */
int Func_code(void)
{
    int nparams;
    type_symbol_function *func;
    type_symbol_table_entry func_params;
    int ok1, ok2;
    int func_type;
    char func_name[MAX_CHAR];

    int numero_funcs = symfuncspos;
    int conta_funcs = 0;
    while (conta_funcs < symfuncspos){

        // Verifica o tipo da funcao
        func_type = lookahead->tag;
        if (func_type == INT || func_type == FLOAT || func_type == CHAR || func_type == STRING)
        {
            match(func_type);

            if (lookahead->tag == ID){
                strcpy(func_name, lookahead->lexema);
                match(ID);

            }else{
                printf("[ERRO] Impossivel realizar declaracao da funcao simbolo 'ID' -> identificador esperado.\n");
                return false;
            }
        

            //Verifica se a funcao ja foi instanciada
            func = sym_func_find(func_name);    

            //se funcao não foi instânciada
            if (func == NULL){
                printf("[ERRO] Funcao %s não instânciada\n", func_name);
                return false;
            }else{

                //Verifica se tipo da funcao confere com o declarado na instancia
                if(func_type != func->type){
                    printf("[ERRO] Tipo da funcao esperado %d\n", func->type);
                    return false;
                }else{         

                    if(lookahead->tag == OPEN_PAR){
                        match(OPEN_PAR);
                    }else{
                        printf("[ERRO] Codigo da funcao desconhecido esperado %s\n",lookahead->lexema);
                        return false;
                    }
                }

            }

            //Verificacao sintatica de declaracao 
            int contador = 0;
            while(lookahead->tag != CLOSE_PAR){
                func_params.type = lookahead->tag;
                if (  func_params.type == INT ||   func_params.type == FLOAT ||
                    func_params.type == CHAR ||   func_params.type == STRING)
                {
                    match(func_params.type);
                    if (lookahead->tag == ID){
                        strcpy(func_params.name, lookahead->lexema);
                        match(ID);

                        //Verifica igualdade entre parametros da declaracao
                        if (func->params[contador].type != func_params.type ||
                        strcasecmp(func->params[contador].name, func_params.name) != 0 ){   

                            printf("[ERRO] Parametros fornecidos diferentes dos declarados\n");
                            return false;

                        }

                        if (lookahead->tag == COMMA){
                            match(COMMA);
                        }else if (lookahead->tag == CLOSE_PAR){
                            //pass
                        }else{
                            printf("[ERRO] Codigo desconhecido:\n Eh esperado ',' uma variavel e outra na chamada da funcao\n");
                            return false;
                        }
                    }else{
                        printf("[ERRO] Esperado 'ID' identificador de parametro\n");
                        return false;
                    }
                }else{
                    printf("[ERRO] Esperado tipo de parametro\n");
                    return false;
                }  
                contador++;
            }

            if (func->nparams != contador){
                printf("[ERRO] Numero de parametros passados na funcao incorreto");
                return false;
            }

            gen_label(func->label_comandos);//Imprime label
            match(CLOSE_PAR);
            if(lookahead->tag == BEGIN){//reconhece o begin
                match(BEGIN);
                statements(); //chama statments
                if(lookahead->tag == END){ //reconhece o end
                    match(END);
                    gen_incond_jump(func->label_retorno);//jump de retorno da chamda de funcao
                    conta_funcs++;
                }
            } 

        }else if(lookahead->tag == ENDTOKEN){
            if (conta_funcs == numero_funcs){
                return true;
            }    else{
                printf("[ERROR] funcao declarada nao esta sendo usada\n");
                return false;
            }
        }else{
            printf("[ERRO] Impossivel realizar declaracao da funcao indicador de 'TIPO' da funcao esperado.\n");
            return false;
        }
       
    }
}

/**
 * @brief Regra de derivação que analiza expressoes booleanas
 *        no padrao 'id op_rel expr'
 *
 */
////// TODO
int B()
{
    int operator;
    // char lexema_of_id[MAX_CHAR];
    // strcpy(lexema_of_id, lookahead->lexema);

    if (lookahead->tag == ID || lookahead->tag == NUM)
    {
        match(lookahead->tag);
    }
    else if (lookahead->tag = '(')
    {
        E();
    }
    else
    {
        printf("[ERRO] ID, numero ou expressão aritmetica experada\n");
        return false;
    }

    if (boolOperator(&operator))
    {
        if (lookahead->tag == NUM || lookahead->tag == ID)
        {
            match(lookahead->tag);
            gen_bool(operator);
            return true;
        }
        else if (lookahead->tag == '(')
        {
            E();
            gen_bool(operator);
            return true;
        }
        else
        {
            printf("[ERRO] ID, numero ou expressão aritmetica experada\n");
            return false;
        }
    }
}

int boolOperator(int *operator)
{
    int lookahead_tag;
    lookahead_tag = lookahead->tag;
    *operator= - 1;

    if (lookahead_tag == EQUAL ||
        lookahead_tag == NE ||
        lookahead_tag == LT ||
        lookahead_tag == GT ||
        lookahead_tag == LE ||
        lookahead_tag == GE)
    {
        *operator= lookahead_tag;
        match(lookahead_tag);
        return true;
    }
    else
    {
        printf("[ERRO] Operador relacional experado.\n");
        return false;
    }
}

//------
/* Funções que representam a gramatica que reconhece expressoes aritmeticas */
/* Elaborada nas primeiras aulas */
int E()
{
    int b1, b2;
    b1 = T();
    if (b1)
        b2 = ER();
    return b1 && b2;
}

int ER()
{
    if (lookahead->tag == '+')
    {
        int b1, b2;
        match('+');
        b1 = T();
        genAdd();
        if (b1)
            b2 = ER();
        return b1 && b2;
    }
    else if (lookahead->tag == '-')
    {
        int b1, b2;
        match('-');
        b1 = T();
        genSub();
        if (b1)
            b2 = ER();
        return b1 && b2;
    }
    else if (lookahead->tag == ')')
    {
        return true;
    }
    else if (lookahead->tag == ENDTOKEN)
    {
        return true;
    }
    else if (lookahead->tag == '*')
    {
        return true;
    }
    else if (lookahead->tag == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int T()
{
    int b1, b2;
    b1 = F();
    if (b1)
        b2 = TR();
    return b1 && b2;
}

int TR()
{
    if (lookahead->tag == '*')
    {
        int b1, b2;
        match('*');
        b1 = F();
        genMult();
        if (b1)
            b2 = TR();
        return b1 && b2;
    }
    else if (lookahead->tag == '/')
    {
        int b1, b2;
        match('/');
        b1 = F();
        genDiv();
        if (b1)
            b2 = TR();
        return b1 && b2;
    }
    else if (lookahead->tag == ')')
    {
        return true;
    }
    else if (lookahead->tag == ENDTOKEN)
    { // EOF
        return true;
    }
    else if (lookahead->tag == '+')
    {
        return true;
    }
    else if (lookahead->tag == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ATR()
{
    if (lookahead->tag == '*')
    {
        int b1, b2;
        match('*');
        b1 = F();
        genMult();
        if (b1)
            b2 = TR();
        return b1 && b2;
    }
    else if (lookahead->tag == '/')
    {
        int b1, b2;
        match('/');
        b1 = F();
        genDiv();
        if (b1)
            b2 = TR();
        return b1 && b2;
    }
    else if (lookahead->tag == '+')
    {
        return true;
    }
    else if (lookahead->tag == '-')
    {
        return true;
    }
    else
    {
        printf("[ERRO] Esperado operador aritmetico");
        return false;
    }
}

int F()
{
    if (lookahead->tag == '(')
    {
        int b1, b2;
        match('(');
        b1 = E();
        if (b1)
            b2 = match(')');
        return b1 && b2;
    }
    else if (lookahead->tag == NUM)
    {
        int b1;
        char lexema[MAX_TOKEN];
        strcpy(lexema, lookahead->lexema);
        b1 = match(NUM); // substituir 'id' por NUM
        genNum(lexema);
        return b1;
    }
    else if (lookahead->tag == ID)
    {
        int b1;
        char lexema[MAX_TOKEN];
        strcpy(lexema, lookahead->lexema);
        b1 = match(ID);
        genNum(lexema);
        return b1;
    }
    else
    {
        return false;
    }
}
/*fim da importação */
//------

//--------------------- MAIN -----------------------

/**
 * @brief Funcao principal (main) do compilador
 *
 * @return int
 */
int main(int argc, char *argv[])
{

    // Inicializa a tabela de simbolo global
    initSymbolTableVariables(&global_symbol_table_variables);
    //initSymbolTableFunctions(&global_symbol_table_functions);
    initSymbolTableString();

    // Verifica a passagem de parametro
    if (argc != 2)
    {
        printf("[ERRO]\n\tÉ necessário informar um arquivo de entrada (código) como parâmetro.\n\n");
        exit(EXIT_FAILURE);
    }

    initLex(argv[1]);       // Carrega codigo
    lookahead = getToken(); // Inicializacao do lookahead

    // Abre o arquivo de saida
    strcpy(output_file_name, argv[1]);
    strcat(output_file_name, ".asm");
    output_file = fopen(output_file_name, "w+");

    program(); // Chamada da derivacao/funcao inicial da gramatica

    fclose(output_file);
    return 1;
}