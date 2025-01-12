%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdint.h>
	#include <limits.h>
	#include <errno.h>
	
	/*For some reason bison places the ast.h include below this declaration*/
	/*So, it will have to take in void ** and then cast it to Program_Body_Node ** */
	void yyerror(void **root, const char *s);

	int yylex();
%}

%code requires{
	#include "ast.h"
}

%locations

%parse-param {void **root}

%union{
	int intval;
	double dval;
	char *strval;
	struct Program_Body_Node *program_body_node;
	struct Declaration_Block_Node *declaration_block_node;
	struct Variable_Declaration_Node *variable_declaration_node;
	struct Full_Declaration_Node *full_declaration_node;
	struct Variable_Declaration_List_Node *variable_declaration_list_node;
	struct Statement_Block_Node *statement_block_node;
	struct Statement_Node *statement_node;
	struct Do_While_Loop_Node *do_while_loop_node;
	struct Block_If_Statement_Node *block_if_statement_node;
	struct Simple_If_Statement_Node *simple_if_statement_node;
	struct Simple_Statement_Node *simple_statement_node;
	struct Assignment_Statement_Node *assignment_statement_node;
	struct Print_Statement_Node *print_statement_node;
	struct Expression_Print_List_Node *expression_print_list_node;
	struct Logical_Expression_Node *logical_expression_node;
	struct Expression_Node *expression_node;
	struct Mult_Expression_Node *mult_expression_node;
	struct Term_Expression_Node *term_expression_node;
	struct S_Factor_Node *s_factor_node;
	enum Symbol_Type declared_variable_type_value;
	struct Factor_Node *factor_node;
}
/* declare tokens */
%token <intval> ICONST
%token <strval> IDENT
%token <dval> RCONST
%token <strval> SCONST
%token DO WHILE NEWLINE PROGRAM END ELSE IF CHARACTER THEN INTEGER REAL PRINT LEN PLUS MINUS MULT DIV POW ASSOP EQ LTHAN GTHAN CAT COMMA LPAREN RPAREN DCOLON DOT DEF

%type <program_body_node> program
%type <program_body_node> program_body
%type <declaration_block_node> declaration_block
%type <full_declaration_node> full_declaration
%type <declared_variable_type_value> declared_variable_type
%type <variable_declaration_list_node> variable_declaration_list
%type <variable_declaration_node> variable_declaration
%type <statement_block_node> statement_block
%type <statement_node> statement
%type <do_while_loop_node> do_while_loop
%type <block_if_statement_node> block_if_statement
%type <simple_if_statement_node> simple_if_statement
%type <simple_statement_node> simple_statement
%type <assignment_statement_node> assignment_statement
%type <expression_print_list_node> expression_print_list
%type <print_statement_node> print_statement
%type <logical_expression_node> logical_expression
%type <expression_node> expression
%type <mult_expression_node> mult_expression
%type <term_expression_node> term_expression
%type <s_factor_node> s_factor
%type <factor_node> factor

%%

program:
	PROGRAM IDENT program_body END PROGRAM IDENT {
		free($2);
		free($6);
		*((struct Program_Body_Node **)root) = $3;
	}
	;

program_body:
	declaration_block statement_block {
		$$ = program_body_node_init($1, $2);
	}
	| statement_block {
		$$ = program_body_node_init(NULL, $1);
	}
	| declaration_block {
		$$ = program_body_node_init($1, NULL);
	}
	;

declaration_block:
	full_declaration declaration_block {
		$$ = declaration_block_node_init($1, $2);
	}
	| full_declaration {
		$$ = declaration_block_node_init($1, NULL);
	}
	;

full_declaration:
	declared_variable_type DCOLON variable_declaration_list {
		$$ = full_declaration_node_init($1, $3, 0);
	}
	| CHARACTER LPAREN LEN ASSOP ICONST RPAREN DCOLON variable_declaration_list {
		$$ = full_declaration_node_init(SYMBOL_TYPE_STRING, $8, $5);
	}
	| CHARACTER DCOLON variable_declaration_list {
		/*Default strlen_max for character is 1 in fortran*/
		$$ = full_declaration_node_init(SYMBOL_TYPE_STRING, $3, 1);
	}
	;

declared_variable_type:
	REAL {
		$$ = SYMBOL_TYPE_REAL;
	}
	| INTEGER {
		$$ = SYMBOL_TYPE_INTEGER;
	}
	;

variable_declaration_list:
	variable_declaration COMMA variable_declaration_list {
		$$ = variable_declaration_list_node_init($1, $3);
	}
	|
	variable_declaration {
		$$ = variable_declaration_list_node_init($1, NULL);
	}
	;

variable_declaration:
	IDENT {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, $1);
		$$ = variable_declaration_node_init(variable_ident, NULL);
		free($1);
	}
	| IDENT ASSOP expression {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, $1);
		$$ = variable_declaration_node_init(variable_ident, $3);
		free($1);
	}
	;


statement_block:
	statement statement_block {
		$$ = statement_block_node_init($1, $2);
	}
	| statement {
		$$ = statement_block_node_init($1, NULL);
	}
	;

statement:
	block_if_statement {
		$$ = statement_node_init(STATEMENT_TYPE_BLOCK_IF_STATEMENT, $1);
	}
	| simple_if_statement {
		$$ = statement_node_init(STATEMENT_TYPE_SIMPLE_IF_STATEMENT, $1);
	}
	| simple_statement {
		$$ = statement_node_init(STATEMENT_TYPE_SIMPLE_STATEMENT, $1);
	}
	| do_while_loop {
		$$ = statement_node_init(STATEMENT_TYPE_DO_WHILE_LOOP, $1);
	}
	;

do_while_loop:
	DO WHILE LPAREN logical_expression RPAREN statement_block END DO {
		$$ = do_while_loop_node_init($4, $6);
	}
	;

block_if_statement:
	IF LPAREN logical_expression RPAREN THEN statement_block END IF {
		$$ = block_if_statement_init($3, $6, NULL);
	}
	| IF LPAREN logical_expression RPAREN THEN statement_block ELSE statement_block END IF {
		$$ = block_if_statement_init($3, $6, $8);
	}
	;

simple_if_statement:
	IF LPAREN logical_expression RPAREN statement {
		$$ = simple_if_statement_node_init($3, $5);
	}
	;

simple_statement:
	assignment_statement {
		$$ = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT, $1);
	}
	| print_statement {
		$$ = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT, $1);
	}
	;

assignment_statement:
	IDENT ASSOP expression {
		struct Symbol ident_symbol = symbol_init(SYMBOL_TYPE_STRING, $1);
		$$ = assignment_statement_node_init(ident_symbol, $3);
		free($1);
	}
	;

print_statement:
	PRINT MULT COMMA expression_print_list {
		$$ = print_statement_node_init($4);
	}
	;

expression_print_list:
	expression_print_list COMMA expression {
		$$ = expression_print_list_node_init($1, $3);
	}
	| expression {
		$$ = expression_print_list_node_init(NULL, $1);
	}
	;
logical_expression:
	expression {
		$$ = logical_expression_node_init($1, LOGICAL_OPERATOR_EQ, NULL);
	}
	| expression EQ expression {
		$$ = logical_expression_node_init($1, LOGICAL_OPERATOR_EQ, $3);
	}
	| expression GTHAN expression  {
		$$ = logical_expression_node_init($1, LOGICAL_OPERATOR_GTHAN, $3);
	}
	| expression LTHAN expression {
		$$ = logical_expression_node_init($1, LOGICAL_OPERATOR_LTHAN, $3);
	}
	;


expression:
	expression PLUS mult_expression {
		$$ = expression_node_init($1, EXPRESSION_OPERATOR_PLUS, $3);
	}
	| expression CAT mult_expression {
		$$ = expression_node_init($1, EXPRESSION_OPERATOR_CAT, $3);
	}
	| expression MINUS mult_expression {
		$$ = expression_node_init($1, EXPRESSION_OPERATOR_MINUS, $3);
	}
	| mult_expression  {
		$$ = expression_node_init(NULL, EXPRESSION_OPERATOR_PLUS, $1);
	}
	;

mult_expression:
	mult_expression MULT term_expression {
		$$ = mult_expression_node_init($1, MULT_EXPRESSION_OPERATOR_MULT, $3);
	}
	| mult_expression DIV term_expression {
		$$ = mult_expression_node_init($1, MULT_EXPRESSION_OPERATOR_DIV, $3);
	}
	| term_expression {
		$$ = mult_expression_node_init(NULL, MULT_EXPRESSION_OPERATOR_DIV, $1);
	}
	;


term_expression:
	s_factor POW term_expression {
		$$ = term_expression_node_init($1, $3);
	}
	| s_factor {
		$$ = term_expression_node_init($1, NULL);
	}

s_factor: 
	PLUS factor {
		$$ = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, $2);
	}
	| MINUS factor {
		$$ = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_MINUS, $2);
	}
	| factor {
		$$ = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, $1);
	}
	;

factor:
	ICONST {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_INTEGER, &($1));
		$$ = factor_node_init(symbol, NULL);
	}
	| RCONST
	{
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_REAL, &($1));
		$$ = factor_node_init(symbol, NULL);
	}
	| IDENT  {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, $1);
		$$ = factor_node_init(symbol, NULL);

		free($1);
	}
	| SCONST {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_STRING, $1);
		$$ = factor_node_init(symbol, NULL);
		
		free($1);
	}
	| LPAREN expression RPAREN {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, NULL);
		$$ = factor_node_init(symbol, $2);
	}
	;

%%

void yyerror(void **root, const char *s)
{
	extern int yylineno;
	*((struct Program_Body_Node **)root) = NULL;
	fprintf(stderr, "parser: error on line %d: %s\n", yylineno, s);
}
