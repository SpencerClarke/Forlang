#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>

enum Symbol_Type
{
	SYMBOL_TYPE_INTEGER,
	SYMBOL_TYPE_REAL,
	SYMBOL_TYPE_STRING,
	SYMBOL_TYPE_IDENT
};

union Symbol_Data
{
	char *string;
	int integer;
	double real;
};

struct Symbol
{
	enum Symbol_Type type;
	union Symbol_Data value;
};
struct Symbol symbol_init(enum Symbol_Type type, void *data);
void symbol_destroy(struct Symbol symbol);

struct Program_Body_Node
{
	struct Declaration_Block_Node *declaration_block;
	struct Statement_Block_Node *statement_block;
};

struct Declaration_Block_Node
{
	struct Full_Declaration_Node *full_declaration;
	struct Declaration_Block_Node *declaration_block;
};

struct Full_Declaration_Node
{
	enum Symbol_Type type;
	struct Variable_Declaration_List_Node *variable_declaration_list;
	int strlen_max;
};

struct Variable_Declaration_List_Node
{
	struct Variable_Declaration_Node *variable_declaration;
	struct Variable_Declaration_List_Node *variable_declaration_list;
};

struct Variable_Declaration_Node
{
	struct Symbol variable_ident;
	struct Expression_Node *expression;
};

struct Statement_Block_Node
{
	struct Statement_Node *statement;
	struct Statement_Block_Node *statement_block;
};

enum Statement_Node_Type
{
	STATEMENT_TYPE_BLOCK_IF_STATEMENT,
	STATEMENT_TYPE_SIMPLE_IF_STATEMENT,
	STATEMENT_TYPE_SIMPLE_STATEMENT
};
union Statement_Node_Data
{
	struct Block_If_Statement_Node *block_if_statement;
	struct Simple_If_Statement_Node *simple_if_statement;
	struct Simple_Statement_Node *simple_statement;
};
struct Statement_Node
{
	enum Statement_Node_Type type;
	union Statement_Node_Data statement;
};

struct Block_If_Statement_Node
{
	struct Logical_Expression_Node *logical_expression;
	struct Statement_Block_Node *statement_block;
	struct Statement_Block_Node *else_statement_block;
};

struct Simple_If_Statement_Node
{
	struct Logical_Expression_Node *logical_expression;
	struct Statement_Node *statement;
};

enum Simple_Statement_Node_Type
{
	SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT,
	SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT
};
union Simple_Statement_Node_Data
{
	struct Assignment_Statement_Node *assignment_statement;
	struct Print_Statement_Node *print_statement;
};
struct Simple_Statement_Node
{
	enum Simple_Statement_Node_Type type;
	union Simple_Statement_Node_Data statement;
};

struct Assignment_Statement_Node
{
	struct Symbol ident;
	struct Expression_Node *expression;
};

struct Print_Statement_Node
{
	struct Expression_Print_List_Node *expression_print_list;
};

struct Expression_Print_List_Node
{
	struct Expression_Print_List_Node *expression_print_list;
	struct Expression_Node *expression;
};

enum Logical_Operator
{
	LOGICAL_OPERATOR_EQ,
	LOGICAL_OPERATOR_GTHAN,
	LOGICAL_OPERATOR_LTHAN
};
struct Logical_Expression_Node
{
	struct Expression_Node *first_expression;
	enum Logical_Operator op;
	struct Expression_Node *second_expression;
};

enum Expression_Operator
{
	EXPRESSION_OPERATOR_PLUS,
	EXPRESSION_OPERATOR_CAT,
	EXPRESSION_OPERATOR_MINUS
};

struct Expression_Node
{
	struct Expression_Node *expression;
	enum Expression_Operator op;
	struct Mult_Expression_Node *mult_expression;
};

enum Mult_Expression_Operator
{
	MULT_EXPRESSION_OPERATOR_MULT,
	MULT_EXPRESSION_OPERATOR_DIV
};
struct Mult_Expression_Node
{
	struct Mult_Expression_Node *mult_expression;
	enum Mult_Expression_Operator op;
	struct Term_Expression_Node *term_expression;
};

struct Term_Expression_Node 
{
	struct S_Factor_Node *s_factor;
	struct Term_Expression_Node *exponent;
};

enum S_Factor_Operator
{
	S_FACTOR_OPERATOR_UNARY_PLUS,
	S_FACTOR_OPERATOR_UNARY_MINUS
};
struct S_Factor_Node
{
	enum S_Factor_Operator op;
	struct Factor_Node *factor;
};
struct Factor_Node
{
	struct Symbol symbol;
	struct Expression_Node *expression;
};

struct Factor_Node *factor_node_init(struct Symbol symbol, struct Expression_Node *expression);
struct S_Factor_Node *s_factor_node_init(enum S_Factor_Operator op, struct Factor_Node *factor);
struct Term_Expression_Node *term_expression_node_init(struct S_Factor_Node *s_factor, struct Term_Expression_Node *exponent);
struct Mult_Expression_Node *mult_expression_node_init(struct Mult_Expression_Node *mult_expression, enum Mult_Expression_Operator op, struct Term_Expression_Node *term_expression);
struct Expression_Node *expression_node_init(struct Expression_Node *expression, enum Expression_Operator op, struct Mult_Expression_Node *mult_expression);
struct Logical_Expression_Node *logical_expression_node_init(struct Expression_Node *first_expression, enum Logical_Operator op, struct Expression_Node *second_expression);
struct Expression_Print_List_Node *expression_print_list_node_init(struct Expression_Print_List_Node *expression_print_list, struct Expression_Node *expression);
struct Print_Statement_Node *print_statement_node_init(struct Expression_Print_List_Node *expression_print_list);
struct Assignment_Statement_Node *assignment_statement_node_init(struct Symbol ident, struct Expression_Node *expression);
struct Simple_Statement_Node *simple_statement_node_init(enum Simple_Statement_Node_Type type, void *statement);
struct Simple_If_Statement_Node *simple_if_statement_node_init(struct Logical_Expression_Node *logical_expression, struct Statement_Node *statement);
struct Block_If_Statement_Node *block_if_statement_init(struct Logical_Expression_Node *logical_expression, struct Statement_Block_Node *statement_block, struct Statement_Block_Node *else_statement_block);
struct Statement_Node *statement_node_init(enum Statement_Node_Type type, void *statement);
struct Statement_Block_Node *statement_block_node_init(struct Statement_Node *statement, struct Statement_Block_Node *statement_block);
struct Variable_Declaration_Node *variable_declaration_node_init(struct Symbol variable_ident, struct Expression_Node *expression);
struct Variable_Declaration_List_Node *variable_declaration_list_node_init(struct Variable_Declaration_Node *variable_declaration, struct Variable_Declaration_List_Node *variable_declaration_list);
struct Full_Declaration_Node *full_declaration_node_init(enum Symbol_Type type, struct Variable_Declaration_List_Node *variable_declaration_list, int strlen_max);
struct Declaration_Block_Node *declaration_block_node_init(struct Full_Declaration_Node *full_declaration, struct Declaration_Block_Node *declaration_block);
struct Program_Body_Node *program_body_node_init(struct Declaration_Block_Node *declaration_block, struct Statement_Block_Node *statement_block);

void program_body_node_destroy(struct Program_Body_Node *program_body);

#endif
