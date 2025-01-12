#include "../include/ast.h"
#define _malloc(T) _malloc_wrapper(sizeof(struct T), #T) 


static void factor_node_destroy(struct Factor_Node *factor_node);
static void s_factor_node_destroy(struct S_Factor_Node *s_factor_node);
static void term_expression_node_destroy(struct Term_Expression_Node *term_expression_node);
static void mult_expression_node_destroy(struct Mult_Expression_Node *mult_expression_node);
static void expression_node_destroy(struct Expression_Node *expression_node);
static void logical_expression_node_destroy(struct Logical_Expression_Node *logical_expression_node);
static void expression_print_list_node_destroy(struct Expression_Print_List_Node *expression_print_list_node);
static void print_statement_node_destroy(struct Print_Statement_Node *print_statement_node);
static void assignment_statement_node_destroy(struct Assignment_Statement_Node *assignment_statement_node);
static void simple_statement_node_destroy(struct Simple_Statement_Node *simple_statement_node);
static void simple_if_statement_node_destroy(struct Simple_If_Statement_Node *simple_if_statement_node);
static void block_if_statement_node_destroy(struct Block_If_Statement_Node *block_if_statement_node);
static void do_while_loop_node_destroy(struct Do_While_Loop_Node *do_while_loop);
static void statement_node_destroy(struct Statement_Node *statement_node);
static void statement_block_node_destroy(struct Statement_Block_Node *statement_block_node);
static void variable_declaration_node_destroy(struct Variable_Declaration_Node *variable_declaration_node);
static void variable_declaration_list_node_destroy(struct Variable_Declaration_List_Node *variable_declaration_list_node);
static void full_declaration_node_destroy(struct Full_Declaration_Node *full_declaration_node);
static void declaration_block_node_destroy(struct Declaration_Block_Node *declaration_block_node);

static void *_malloc_wrapper(size_t size, const char *func_name);

static void *_malloc_wrapper(size_t size, const char *name)
{
	void *out = malloc(size);
	if(out == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for %s\n", name);
		exit(3);
	}
	return out;
}


struct Symbol symbol_init(enum Symbol_Type type, void *data)
{
	struct Symbol out;

	if(data == NULL)
	{ 
		/*This won't be freed by symbol_destroy*/
		/*Other than that nothing in this symbol should be used*/
		out.type = SYMBOL_TYPE_INTEGER;
		return out;
	}

	out.type = type;
	switch(type)
	{
		case SYMBOL_TYPE_INTEGER:
			out.value.integer = *((int *)data);
			break;
		
		case SYMBOL_TYPE_REAL:
			out.value.real = *((double *)data);
			break;
		
		case SYMBOL_TYPE_STRING:
			out.value.string = malloc(strlen(data) + 1);
			if(out.value.string == NULL)
			{
				fprintf(stderr, "symbol_init: could not alloc\n");
				exit(3);
			}
			
			strcpy(out.value.string, data);
			break;
		case SYMBOL_TYPE_IDENT:
			out.value.string = malloc(strlen(data) + 1);
			if(out.value.string == NULL)
			{
				fprintf(stderr, "symbol_init: could not alloc\n");
				exit(3);
			}
			
			strcpy(out.value.string, data);
			break;
	}

	return out;
}

void symbol_destroy(struct Symbol symbol)
{
	if(symbol.type == SYMBOL_TYPE_STRING || symbol.type == SYMBOL_TYPE_IDENT)
	{
		free(symbol.value.string);
	}
}

struct Factor_Node *factor_node_init(struct Symbol symbol, struct Expression_Node *expression)
{
	struct Factor_Node *out = _malloc(Factor_Node);

	out->symbol = symbol;
	out->expression = expression;

	return out;
}

struct S_Factor_Node *s_factor_node_init(enum S_Factor_Operator op, struct Factor_Node *factor)
{
	struct S_Factor_Node *out = _malloc(S_Factor_Node);
	
	out->factor = factor;
	out->op = op;

	return out;
}

struct Term_Expression_Node *term_expression_node_init(struct S_Factor_Node *s_factor, struct Term_Expression_Node *exponent)
{
	struct Term_Expression_Node *out = _malloc(Term_Expression_Node);

	out->exponent = exponent;
	out->s_factor = s_factor;

	return out;
}

struct Mult_Expression_Node *mult_expression_node_init(struct Mult_Expression_Node *mult_expression, enum Mult_Expression_Operator op, struct Term_Expression_Node *term_expression)
{
	struct Mult_Expression_Node *out = _malloc(Mult_Expression_Node);
	
	out->mult_expression = mult_expression;
	out->op = op;
	out->term_expression = term_expression;

	return out;
}

struct Expression_Node *expression_node_init(struct Expression_Node *expression, enum Expression_Operator op, struct Mult_Expression_Node *mult_expression)
{
	struct Expression_Node *out = _malloc(Expression_Node);
	
	out->expression = expression;
	out->mult_expression = mult_expression;
	out->op = op;

	return out;
}

struct Logical_Expression_Node *logical_expression_node_init(struct Expression_Node *first_expression, enum Logical_Operator op, struct Expression_Node *second_expression)
{
	struct Logical_Expression_Node *out = _malloc(Logical_Expression_Node);
	
	out->first_expression = first_expression;
	out->op = op;
	out->second_expression = second_expression;

	return out;
}

struct Expression_Print_List_Node *expression_print_list_node_init(struct Expression_Print_List_Node *expression_print_list, struct Expression_Node *expression)
{
	struct Expression_Print_List_Node *new_node = _malloc(Expression_Print_List_Node);	
	struct Expression_Print_List_Node *current;

	new_node->expression = expression;
	new_node->expression_print_list = NULL;
	if(expression_print_list == NULL)
	{
		new_node->expression_print_list = NULL;
		return new_node;
	}

	current = expression_print_list;
	while(current->expression_print_list != NULL)
	{
		current = current->expression_print_list;
	}
	current->expression_print_list = new_node;

	return expression_print_list;
}

struct Print_Statement_Node *print_statement_node_init(struct Expression_Print_List_Node *expression_print_list)
{
	struct Print_Statement_Node *out = _malloc(Print_Statement_Node);
	
	out->expression_print_list = expression_print_list;
	
	return out;
}

struct Assignment_Statement_Node *assignment_statement_node_init(struct Symbol ident, struct Expression_Node *expression)
{
	struct Assignment_Statement_Node *out = _malloc(Assignment_Statement_Node);

	out->ident = ident;
	out->expression = expression;

	return out;
}

struct Simple_Statement_Node *simple_statement_node_init(enum Simple_Statement_Node_Type type, void *statement)
{
	struct Simple_Statement_Node *out = _malloc(Simple_Statement_Node);
	
	out->type = type;
	switch(type)
	{
		case SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT:
			out->statement.assignment_statement = statement;
			break;
		case SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT:
			out->statement.print_statement = statement;
			break;
	}

	return out;
}
struct Simple_If_Statement_Node *simple_if_statement_node_init(struct Logical_Expression_Node *logical_expression, struct Statement_Node *statement)
{
	struct Simple_If_Statement_Node *out = _malloc(Simple_If_Statement_Node);

	out->logical_expression = logical_expression;
	out->statement = statement;

	return out;
}

struct Block_If_Statement_Node *block_if_statement_init(struct Logical_Expression_Node *logical_expression, struct Statement_Block_Node *statement_block, struct Statement_Block_Node *else_statement_block)
{
	struct Block_If_Statement_Node *out = _malloc(Block_If_Statement_Node);
	
	out->logical_expression = logical_expression;
	out->statement_block = statement_block;
	out->else_statement_block = else_statement_block;

	return out;
}

struct Do_While_Loop_Node *do_while_loop_node_init(struct Logical_Expression_Node *logical_expression, struct Statement_Block_Node *statement_block)
{
	struct Do_While_Loop_Node *out = _malloc(Do_While_Loop_Node);

	out->logical_expression = logical_expression;
	out->statement_block = statement_block;

	return out;
}
struct Statement_Node *statement_node_init(enum Statement_Node_Type type, void *statement)
{
	struct Statement_Node *out = _malloc(Statement_Node);

	out->type = type;
	switch(type)
	{
		case STATEMENT_TYPE_BLOCK_IF_STATEMENT:
			out->statement.block_if_statement = statement;
			break;

		case STATEMENT_TYPE_SIMPLE_IF_STATEMENT:
			out->statement.simple_if_statement = statement;
			break;

		case STATEMENT_TYPE_SIMPLE_STATEMENT:
			out->statement.simple_statement = statement;
			break;

		case STATEMENT_TYPE_DO_WHILE_LOOP:
			out->statement.do_while_loop = statement;
			break;
	}

	return out;
}

struct Statement_Block_Node *statement_block_node_init(struct Statement_Node *statement, struct Statement_Block_Node *statement_block)
{
	struct Statement_Block_Node *out = _malloc(Statement_Block_Node);

	out->statement = statement;
	out->statement_block = statement_block;

	return out;
}

struct Variable_Declaration_Node *variable_declaration_node_init(struct Symbol variable_ident, struct Expression_Node *expression)
{
	struct Variable_Declaration_Node *out = _malloc(Variable_Declaration_Node);

	out->variable_ident = variable_ident;
	out->expression = expression;

	return out;
}

struct Variable_Declaration_List_Node *variable_declaration_list_node_init(struct Variable_Declaration_Node *variable_declaration, struct Variable_Declaration_List_Node *variable_declaration_list)
{
	struct Variable_Declaration_List_Node *out = _malloc(Variable_Declaration_Node);

	out->variable_declaration = variable_declaration;
	out->variable_declaration_list = variable_declaration_list;

	return out;
}

struct Full_Declaration_Node *full_declaration_node_init(enum Symbol_Type type, struct Variable_Declaration_List_Node *variable_declaration_list, int strlen_max)
{


	struct Full_Declaration_Node *out = _malloc(Full_Declaration_Node);

	out->type = type;
	out->variable_declaration_list = variable_declaration_list;
	out->strlen_max = strlen_max;

	return out;
}

struct Declaration_Block_Node *declaration_block_node_init(struct Full_Declaration_Node *full_declaration, struct Declaration_Block_Node *declaration_block)
{
	struct Declaration_Block_Node *out = _malloc(Declaration_Block_Node);

	out->declaration_block = declaration_block;
	out->full_declaration = full_declaration;

	return out;
}

struct Program_Body_Node *program_body_node_init(struct Declaration_Block_Node *declaration_block, struct Statement_Block_Node *statement_block)
{
	struct Program_Body_Node *out = _malloc(Program_Body_Node);

	out->declaration_block = declaration_block;
	out->statement_block = statement_block;

	return out;
}

static void factor_node_destroy(struct Factor_Node *factor_node)
{
	if(factor_node == NULL)
		return;

	symbol_destroy(factor_node->symbol);
	expression_node_destroy(factor_node->expression);
	free(factor_node);
}

static void s_factor_node_destroy(struct S_Factor_Node *s_factor_node)
{
	if(s_factor_node == NULL)
		return;

	factor_node_destroy(s_factor_node->factor);
	free(s_factor_node);
}

static void term_expression_node_destroy(struct Term_Expression_Node *term_expression_node)
{
	if(term_expression_node == NULL)
		return;

	s_factor_node_destroy(term_expression_node->s_factor);
	term_expression_node_destroy(term_expression_node->exponent);

	free(term_expression_node);
}

static void mult_expression_node_destroy(struct Mult_Expression_Node *mult_expression_node)
{
	if(mult_expression_node == NULL)
		return;

	mult_expression_node_destroy(mult_expression_node->mult_expression);
	term_expression_node_destroy(mult_expression_node->term_expression);

	free(mult_expression_node);
}

static void expression_node_destroy(struct Expression_Node *expression_node)
{
	if(expression_node == NULL)
		return;

	expression_node_destroy(expression_node->expression);
	mult_expression_node_destroy(expression_node->mult_expression);

	free(expression_node);
}

static void logical_expression_node_destroy(struct Logical_Expression_Node *logical_expression_node)
{
	if(logical_expression_node == NULL)
		return;

	expression_node_destroy(logical_expression_node->first_expression);
	expression_node_destroy(logical_expression_node->second_expression);

	free(logical_expression_node);
}

static void expression_print_list_node_destroy(struct Expression_Print_List_Node *expression_print_list_node)
{
	if(expression_print_list_node == NULL)
		return;

	expression_print_list_node_destroy(expression_print_list_node->expression_print_list);
	expression_node_destroy(expression_print_list_node->expression);

	free(expression_print_list_node);
}

static void print_statement_node_destroy(struct Print_Statement_Node *print_statement_node)
{
	if(print_statement_node == NULL)
		return;

	expression_print_list_node_destroy(print_statement_node->expression_print_list);
	
	free(print_statement_node);
}

static void assignment_statement_node_destroy(struct Assignment_Statement_Node *assignment_statement_node)
{
	if(assignment_statement_node == NULL)
		return;

	symbol_destroy(assignment_statement_node->ident);
	expression_node_destroy(assignment_statement_node->expression);

	free(assignment_statement_node);
}

static void simple_statement_node_destroy(struct Simple_Statement_Node *simple_statement_node)
{
	if(simple_statement_node == NULL)
		return;

	switch(simple_statement_node->type)
	{
		case SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT:
			assignment_statement_node_destroy(simple_statement_node->statement.assignment_statement);
			break;
		case SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT:
			print_statement_node_destroy(simple_statement_node->statement.print_statement);
			break;
	}

	free(simple_statement_node);
}

static void simple_if_statement_node_destroy(struct Simple_If_Statement_Node *simple_if_statement_node)
{
	if(simple_if_statement_node == NULL)
		return;

	logical_expression_node_destroy(simple_if_statement_node->logical_expression);
	statement_node_destroy(simple_if_statement_node->statement);

	free(simple_if_statement_node);
}

static void block_if_statement_node_destroy(struct Block_If_Statement_Node *block_if_statement_node)
{
	if(block_if_statement_node == NULL)
		return;
	
	logical_expression_node_destroy(block_if_statement_node->logical_expression);
	statement_block_node_destroy(block_if_statement_node->statement_block);
	statement_block_node_destroy(block_if_statement_node->else_statement_block);

	free(block_if_statement_node);
}
static void do_while_loop_node_destroy(struct Do_While_Loop_Node *do_while_loop)
{
	if(do_while_loop == NULL)
		return;
	logical_expression_node_destroy(do_while_loop->logical_expression);
	statement_block_node_destroy(do_while_loop->statement_block);
	
	free(do_while_loop);
}
static void statement_node_destroy(struct Statement_Node *statement_node)
{
	if(statement_node == NULL)
		return;

	switch(statement_node->type)
	{
		case STATEMENT_TYPE_BLOCK_IF_STATEMENT:
			block_if_statement_node_destroy(statement_node->statement.block_if_statement);
			break;

		case STATEMENT_TYPE_SIMPLE_IF_STATEMENT:
			simple_if_statement_node_destroy(statement_node->statement.simple_if_statement);
			break;

		case STATEMENT_TYPE_SIMPLE_STATEMENT:
			simple_statement_node_destroy(statement_node->statement.simple_statement);
			break;

		case STATEMENT_TYPE_DO_WHILE_LOOP:
			do_while_loop_node_destroy(statement_node->statement.do_while_loop);
			break;
	}

	free(statement_node);
}

static void statement_block_node_destroy(struct Statement_Block_Node *statement_block_node)
{
	if(statement_block_node == NULL)
		return;

	statement_node_destroy(statement_block_node->statement);
	statement_block_node_destroy(statement_block_node->statement_block);

	free(statement_block_node);
}

static void variable_declaration_node_destroy(struct Variable_Declaration_Node *variable_declaration_node)
{
	if(variable_declaration_node == NULL)
		return;

	symbol_destroy(variable_declaration_node->variable_ident);
	expression_node_destroy(variable_declaration_node->expression);

	free(variable_declaration_node);
}

static void variable_declaration_list_node_destroy(struct Variable_Declaration_List_Node *variable_declaration_list_node)
{
	if(variable_declaration_list_node == NULL)
		return;

	variable_declaration_node_destroy(variable_declaration_list_node->variable_declaration);
	variable_declaration_list_node_destroy(variable_declaration_list_node->variable_declaration_list);

	free(variable_declaration_list_node);
}

static void full_declaration_node_destroy(struct Full_Declaration_Node *full_declaration_node)
{
	if(full_declaration_node == NULL)
		return;

	variable_declaration_list_node_destroy(full_declaration_node->variable_declaration_list);

	free(full_declaration_node);
}

static void declaration_block_node_destroy(struct Declaration_Block_Node *declaration_block_node)
{
	if(declaration_block_node == NULL)
		return;

	full_declaration_node_destroy(declaration_block_node->full_declaration);
	declaration_block_node_destroy(declaration_block_node->declaration_block);

	free(declaration_block_node);
}

void program_body_node_destroy(struct Program_Body_Node *program_body)
{
	declaration_block_node_destroy(program_body->declaration_block);
	statement_block_node_destroy(program_body->statement_block);

	free(program_body);
}
