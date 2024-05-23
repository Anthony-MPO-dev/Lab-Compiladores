/**
 * @file synt.h
 * @author Prof. Ivairton M. Santos - UFMT - Computacao
 * @author Acad. Anthony M. P. de Oliveira  - UFMT - Computacao
 * @brief Modulo do analisado sintatico
 * @version 0.5
 * @date 2022-03-17
 * 
 */

#ifndef _SYNT_H_
#define _SYNT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct_compiler.h"
#include "lex.h"
#include "gen.h"
#include "symbols.h"

/*
 * Gramatica: 
 *      program -> declarations begin  statements end func_statements
 *      declarations-> declaration declarations | [vazio]
 *      declaration -> {int | float | string | char} id {declarationV | declarationF}
 *      declarationV -> ;
 *      declarationF -> ( { {int | float | string | char} id,} * | [vazio] });
 *      statements --> statement statements | [vazio]
 *      statement  --> read_stmt | write_stmt | if_stmt | if_else_stmt | while_stmt | assign_stmt
 *      read_stmt  --> read id;
 *      write_stmt --> write id;
 *      if_stmt    --> if '(' rel_expr ')' begin statements end [ else begin statements end  ]  (ideal, ainda por fazer)
 *      if_stmt    --> if '(' E ')' begin statements end [ else begin statements end ] (implementado)
 *      assign_stmt -> id '=' E;
 *      rel_expr   --> id rel_operator E
 *      rel_operator -->  '<' | '>' | '<=' | '>=' | '==' | '!='
 *      E          --> expressões com numeros inteiros, cujo resultado final fica na pilha.
 */


// Prototipos
void program (void);
void declarations(void);
void statements (void);
int declaration(void);
type_symbol_table_entry *declarationV(int var_type, char *var_name);
type_symbol_table_entry *declarationF(int func_type, char *func_name);
int statement(void);
int func_call_cmd(char *func_name);
int Func_code(void);

int B(void);
int boolOperator(int*);

int E();
int ER();
int T();
int TR();
int F();

int main();

#endif //_SYNT_H_