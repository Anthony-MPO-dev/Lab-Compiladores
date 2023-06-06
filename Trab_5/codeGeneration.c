#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "codeGeneration.h"

// Labels para os jumps
void makeLabel(char* out_label)
{
    static int label_count = 0;
    strcpy(out_label, "label");
    
    char s[10];
    sprintf(s, "%d", label_count);
    strcat(out_label, s);

    label_count++;
}


// Codigo para declaracao de variaveis
void makeCodeDeclaration(char* dest, Type type, char* identifier, char* value)
{
    if (type == INTEGER)
    {
        if (value == NULL)
            sprintf(dest, "%s: dq 0\n", identifier);

        else
        {
            int x = atoi(value);
            sprintf(dest, "%s: dq %d\n", identifier, x);
        }
    }

    // armazena tipo real 
    else if (type == REAL)
    {
        if (value == NULL)
            sprintf(dest, "%s: dq 0\n", identifier);

        else
        {
            double x = atof(value);
            sprintf(dest, "%s: dq %f\n", identifier, x);
        }
    }

    // armazena tipo string
    else if (type == STRING)
    {
        if (value == NULL)
            sprintf(dest, "%s: times %d db 0 \n", identifier, STRING_SIZE);

        else
        {
            sprintf(dest, "%s: db %s, 0\n", identifier, value);
        }
    }

    else{
        fprintf(stderr, "Error[incompatible type]: in line %d \n", cont_lines);
    }

}


// Termino da secao de dados e comeco da secao de codigo
void dumpCodeDeclarationEnd()
{
    fprintf(out_file, "\nsection .text\n");
    fprintf(out_file, "global main\n");
    fprintf(out_file, "\nmain:\n");
}


// Codigo para leitura (scanf)
int makeCodeRead(char* dest, char *id)
{
    SymTableEntry* ret = findSymTable(&local_table,id);
    dest[0] = '\0';

    if (ret == NULL)
    {
        // Se não encontrar, verifica a tabela de simbolos global
        ret = findSymTable(&global_table, id);

        if (ret == NULL){
            fprintf(stderr, "Error[impossible to read]: %s is not readable at line %d not found variable in the symtable\n", id, cont_lines);
            return 0;
        }
    }

    // Leitura de Inteiros 
    if (ret->type == INTEGER)
    {
        sprintf(dest + strlen(dest), "mov rdi,fmt_d\n");
        sprintf(dest + strlen(dest), "mov rsi,%s\n", ret->identifier);
    }

    // Leitura de Reais
    else if (ret->type == REAL)
    {
        sprintf(dest + strlen(dest), "mov rdi,fmt_f\n");
        sprintf(dest + strlen(dest), "mov rsi,%s\n", ret->identifier);
    }

    // Leitura de Strings
    else
    {
        sprintf(dest + strlen(dest), "mov rdi,fmt_s\n");
        sprintf(dest + strlen(dest), "mov rsi,%s\n", ret->identifier);
    }

    sprintf(dest + strlen(dest), "mov rax,0\n");
    sprintf(dest + strlen(dest), "call scanf\n");

    return 1;

}


// Codigo para escrita (printf)
int makeCodeWrite(char* dest, char *id, int ln)
{

    dest[0] = '\0';

    SymTableEntry* ret = findSymTable(&local_table,id);
    

    if (ret == NULL)
    {
        // Se não encontrar, verifica a tabela de simbolos global
        ret = findSymTable(&global_table, id);

        if (ret == NULL){
            fprintf(stderr, "Error[impossible to write variable]: %s is not readable at line %d not found variable in the symtable\n", id, cont_lines);
            return 0;
        }
    }

    // Escrita de Inteiros
    if (ret->type == INTEGER)
    {
        if (ln) sprintf(dest + strlen(dest), "mov rdi,fmt_dln\n");
        else sprintf(dest + strlen(dest), "mov rdi,fmt_d\n");
        sprintf(dest + strlen(dest), "mov rsi,[%s]\n", ret->identifier);
    }

    // Escrita de Reais
    else if (ret->type == REAL)
    {
        if (ln) sprintf(dest + strlen(dest), "mov rdi,fmt_fln\n");
        else sprintf(dest + strlen(dest), "mov rdi,fmt_f\n");
        sprintf(dest + strlen(dest), "mov rsi,[%s]\n", ret->identifier);
    }

    // Escrita de Strings
    else
    {
        if (ln) sprintf(dest + strlen(dest), "mov rdi,fmt_sln\n");
        else sprintf(dest + strlen(dest), "mov rdi,fmt_s\n");
        sprintf(dest + strlen(dest), "mov rsi,%s\n", ret->identifier);
    }

    sprintf(dest + strlen(dest), "mov rax,0\n");
    sprintf(dest + strlen(dest), "call printf\n");

    return 1;
}

int makeCodeWrite0(char* dest, char *value, int ln){
    dest[0] = '\0';

    // Caso de Strings
    if (ln) sprintf(dest + strlen(dest), "mov rdi,fmt_sln\n");
    else sprintf(dest + strlen(dest), "mov rdi,fmt_s\n");
    sprintf(dest + strlen(dest), "mov rsi, %s\n", value);
    
    // Caso de Inteiros
    sprintf(dest + strlen(dest), "mov rax,0\n");
    sprintf(dest + strlen(dest), "call printf\n"); 

    return 1;
}



int makeCodeAssignment(char* dest, char* id, char* expr, int typeValue)
{   
    SymTableEntry *ret;

    ret = findSymTable(&local_table, id);
    dest[0] = '\0';

    if (ret == NULL)
    {
        // Se não encontrar, verifica a tabela de simbolos global
        ret = findSymTable(&global_table, id);

        if (ret == NULL){
            fprintf(stderr, "Error: %s not recognized at line %d\n", id, cont_lines);
            return 0;
        }
    }
	
    if (typeValue == 0) {

        if (ret->type == INTEGER)
        {   
            printf("ATRIBUICAO DE INTEIRO\n");
            sprintf(dest + strlen(dest), "%s", expr);
            sprintf(dest + strlen(dest), "pop rbx\n");
            sprintf(dest + strlen(dest), "mov [%s],rbx\n", ret->identifier);
        }else if(ret->type == REAL)
        {
            printf("ATRIBUICAO DE REAL\n");
            sprintf(dest + strlen(dest), "%s", expr);
            sprintf(dest + strlen(dest), "pop rbx\n");
            sprintf(dest + strlen(dest), "movss [%s], xmm0\n", ret->identifier);
        }else{
            fprintf(stderr, "ERROR[Variable type does not match the provided value] on line %d\n",
            cont_lines);
            return 0;
        }
    }else if (typeValue == 1){
        if(ret->type == STRING)
        {
            printf("ATRIBUICAO DE STRING\n");
            sprintf(dest + strlen(dest), "%s", expr);
            sprintf(dest + strlen(dest), "pop rbx\n");
            sprintf(dest + strlen(dest), "mov [%s],rbx\n", ret->identifier);
        }else{
            fprintf(stderr, "ERROR[Variable type does not match the provided value] on line %d\n",
            cont_lines);
            return 0;
        }
    }else
    {
        fprintf(stderr, "Unsuported operation %d\n",
            cont_lines);
        return 0;
    }

    return 1;
}


int makeCodeLoad(char* dest, char* id, int ref)
{
    dest[0] = '\0';

    if (ref == 0)
    {
        sprintf(dest + strlen(dest), "mov rbx,%s\n", id);
        sprintf(dest + strlen(dest), "push rbx\n");
        return 1;
    }

    // Verifica primeiro tabela de simbolos local
    SymTableEntry *ret; 
    ret = findSymTable(&local_table, id);

    if (ret == NULL)
    {
        
        // Se não encontrar, verifica a tabela de simbolos global
        ret = findSymTable(&global_table, id);

        if (ret == NULL){
            fprintf(stderr, "Error: %s not recognized at line %d\n", id, cont_lines);
            return 0;
        }

    }

    if (ret->type == STRING)
        sprintf(dest + strlen(dest), "mov rbx,%s\n", ret->identifier);
    else
        sprintf(dest + strlen(dest), "mov rbx,[%s]\n", ret->identifier);
    
    sprintf(dest + strlen(dest), "push rbx\n");
    return 1;
}


void makeCodeAdd(char* dest, char* value)
{
    sprintf(dest + strlen(dest), "%s", value);
    sprintf(dest + strlen(dest), "pop rcx\n");
    sprintf(dest + strlen(dest), "pop rbx\n");
    sprintf(dest + strlen(dest), "add rbx,rcx\n");
    sprintf(dest + strlen(dest), "push rbx\n");
}


void makeCodeSub(char* dest, char* value)
{   
    sprintf(dest + strlen(dest), "%s", value);
    sprintf(dest + strlen(dest), "pop rcx\n");
    sprintf(dest + strlen(dest), "pop rbx\n");
    sprintf(dest + strlen(dest), "sub rbx,rcx\n");
    sprintf(dest + strlen(dest), "push rbx\n");

}

void makeCodeMul(char* dest, char* value2)
{
    sprintf(dest + strlen(dest), "%s", value2);
    sprintf(dest + strlen(dest), "pop rcx\n");
    sprintf(dest + strlen(dest), "pop rbx\n");
    sprintf(dest + strlen(dest), "imul rbx,rcx\n");
    sprintf(dest + strlen(dest), "push rbx\n");
}


void makeCodeDiv(char* dest, char* value2)
{
    sprintf(dest + strlen(dest), "%s", value2);
    sprintf(dest + strlen(dest), "pop r8\n");
    sprintf(dest + strlen(dest), "pop rax\n");
    sprintf(dest + strlen(dest), "xor rdx,rdx\n");
    sprintf(dest + strlen(dest), "idiv r8\n");
    sprintf(dest + strlen(dest), "push rax\n");
}


void makeCodeMod(char* dest, char* value2)
{
    sprintf(dest + strlen(dest), "%s", value2);
    sprintf(dest + strlen(dest), "pop r8\n");
    sprintf(dest + strlen(dest), "pop rax\n");
    sprintf(dest + strlen(dest), "xor rdx,rdx\n");
    sprintf(dest + strlen(dest), "idiv r8\n");
    sprintf(dest + strlen(dest), "push rdx\n");
}


int makeCodeComp(char* dest, char* id, char* expr)
{
    SymTableEntry *ret; 
    ret = findSymTable(&local_table, id);
    dest[0] = '\0';

    if (ret == NULL)
    {
         // Se não encontrar, verifica a tabela de simbolos global
        ret = findSymTable(&global_table, id);

        if (ret == NULL){
            fprintf(stderr, "Error: %s not recognized at line %d\n", id, cont_lines);
            return 0;
        }

    }

    if (ret->type == STRING)
    {
        fprintf(stderr, "Unsuported operation envolving string at line %d\n",
            cont_lines);
        return 0;
    }

    sprintf(dest + strlen(dest), "%s", expr);
    sprintf(dest + strlen(dest), "pop rcx\n");
    sprintf(dest + strlen(dest), "mov rbx, [%s]\n", ret->identifier);
    sprintf(dest + strlen(dest), "cmp rbx, rcx\n");

    return 1;
}


void makeCodeIf(char* dest, char* expr_code, int expr_jump, char* block_code)
{
    char label[16];
    makeLabel(label);

    dest[0] = '\0';

    sprintf(dest + strlen(dest), "%s", expr_code);
    sprintf(dest + strlen(dest), "%s %s\n", jumps[expr_jump + JUMPS_ARRAY_OFFSET],
        label);
    sprintf(dest + strlen(dest), "%s", block_code);
    sprintf(dest + strlen(dest), "%s:\n", label);
}


void makeCodeIfElse(char* dest, char* expr_code, int expr_jump,
    char* block_code_if, char* block_code_else)
{
    char else_label[16];
    char final_label[16];

    makeLabel(else_label);
    makeLabel(final_label);

    dest[0] = '\0';

    
    sprintf(dest + strlen(dest), "%s", expr_code);
    sprintf(dest + strlen(dest), "%s %s\n", jumps[expr_jump + JUMPS_ARRAY_OFFSET], else_label);
    sprintf(dest + strlen(dest), "%s", block_code_if);
    sprintf(dest + strlen(dest), "jmp %s\n", final_label);
    sprintf(dest + strlen(dest), "%s:\n", else_label);
    sprintf(dest + strlen(dest), "%s", block_code_else);
    sprintf(dest + strlen(dest), "%s:\n", final_label);
}


void makeCodeWhile(char* dest, char* expr_code, int expr_jump, char* block_code)
{
    char loop_label[16];
    char final_label[16];

    makeLabel(loop_label);
    makeLabel(final_label);

    dest[0] = '\0';

    
    sprintf(dest + strlen(dest), "%s:\n", loop_label);
    sprintf(dest + strlen(dest), "%s", expr_code);
    sprintf(dest + strlen(dest), "%s %s\n", jumps[expr_jump + JUMPS_ARRAY_OFFSET],
        final_label);
    sprintf(dest + strlen(dest), "%s", block_code);
    sprintf(dest + strlen(dest), "jmp %s\n", loop_label);
    sprintf(dest + strlen(dest), "%s:\n", final_label);
}

