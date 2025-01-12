#include "interpreter.h" 


#define MAX_STRING_LENGTH (INT_MAX/2 + 1)
/* This limit is very important.
 * Every string ever will be limited to INT_MAX/2 + 1 characters.
 * This means the largest string production tried with snprintf will span INT_MAX - 1 characters (INT_MAX is odd)
 * The return value of snprintf for any string greater than this limit is undefined.
 */


static void *_malloc(size_t n);
static int ipow(int a, int b);
static void exec_declaration_block(struct Declaration_Block_Node *declaration_block, struct Symbol_Table *symbol_table);
static void exec_variable_declaration_list(struct Variable_Declaration_List_Node *variable_declaration_list, enum Symbol_Type variable_type, size_t strlen_max, struct Symbol_Table *symbol_table);
static void exec_variable_declaration(struct Variable_Declaration_Node *variable_declaration, enum Expression_Type variable_type, size_t strlen_max, struct Symbol_Table *symbol_table);
static void exec_statement_block(struct Statement_Block_Node *statement_block, struct Symbol_Table *symbol_table);
static void exec_statement(struct Statement_Node *statement, struct Symbol_Table *symbol_table);
static void exec_block_if_statement(struct Block_If_Statement_Node *block_if_statement, struct Symbol_Table *symbol_table);
static void exec_simple_if_statement(struct Simple_If_Statement_Node *simple_if_statement, struct Symbol_Table *symbol_table);
static void exec_assignment_statement(struct Assignment_Statement_Node *assignment_statement, struct Symbol_Table *symbol_table);
static void exec_print_statement(struct Print_Statement_Node *print_statement, struct Symbol_Table *symbol_table);

static int eval_logical_expression(struct Logical_Expression_Node *expression, struct Symbol_Table *symbol_table);
static struct Expression_Record eval_expression(struct Expression_Node *expression, struct Symbol_Table *symbol_table);
static struct Expression_Record eval_mult_expression(struct Mult_Expression_Node *mult_expression, struct Symbol_Table *symbol_table);
static struct Expression_Record eval_term_expression(struct Term_Expression_Node *term_expression, struct Symbol_Table *symbol_table);
static struct Expression_Record eval_s_factor(struct S_Factor_Node *s_factor, struct Symbol_Table *symbol_table);
static struct Expression_Record eval_factor(struct Factor_Node *factor, struct Symbol_Table *symbol_table);

static void *_malloc(size_t n)
{
	void *out = malloc(n);
	if(out == NULL)
	{
		fprintf(stderr, "_malloc: failed to alloc\n");
		exit(4);
	}
	return out;
}

static int ipow(int a, int b)
{
	int out = 1;
	int count = 0;
	for(count = 0; count < b; count++)
	{
		out = out * a;
	}
	return out;
}

void exec_program(struct Program_Body_Node *root)
{
	struct Symbol_Table symbol_table;
	
	if(root == NULL)
		return;

	symbol_table = symbol_table_init();

	exec_declaration_block(root->declaration_block, &symbol_table);
	exec_statement_block(root->statement_block, &symbol_table);

	symbol_table_destroy(&symbol_table);
}

static void exec_declaration_block(struct Declaration_Block_Node *declaration_block, struct Symbol_Table *symbol_table)
{
	while(declaration_block != NULL)
	{
		int strlen_max = declaration_block->full_declaration->strlen_max;
		if(strlen_max < 0)
		{
			fprintf(stderr, "interpreter: The declared string length cannot be negative\n");
			exit(4);
		}
		exec_variable_declaration_list
		(
			declaration_block->full_declaration->variable_declaration_list, 
			declaration_block->full_declaration->type,
			strlen_max,
			symbol_table
		);
		declaration_block = declaration_block->declaration_block;
	}
}
static void exec_variable_declaration_list(struct Variable_Declaration_List_Node *variable_declaration_list, enum Symbol_Type variable_type, size_t strlen_max, struct Symbol_Table *symbol_table)
{
	enum Expression_Type expr_type;

	switch(variable_type)
	{
		case SYMBOL_TYPE_INTEGER:
			expr_type = EXPRESSION_TYPE_INTEGER;
			break;
		case SYMBOL_TYPE_REAL:
			expr_type = EXPRESSION_TYPE_REAL;
			break;
		case SYMBOL_TYPE_STRING:
			expr_type = EXPRESSION_TYPE_STRING;
			break;
		default:
			fprintf(stderr, "interpreter: malformed declared variable type (this should not happen)\n");
			exit(3);
	}
	while(variable_declaration_list != NULL)
	{
		exec_variable_declaration(variable_declaration_list->variable_declaration, expr_type, strlen_max, symbol_table);
		variable_declaration_list = variable_declaration_list->variable_declaration_list;
	}
}
static void exec_variable_declaration(struct Variable_Declaration_Node *variable_declaration, enum Expression_Type variable_type, size_t strlen_max, struct Symbol_Table *symbol_table)
{
	struct Expression_Record new_record;

	if(variable_declaration == NULL)
		return;

	if(variable_declaration->expression != NULL)
	{
		new_record = eval_expression(variable_declaration->expression, symbol_table);
	}
	else
	{
		switch(variable_type)
		{
			case EXPRESSION_TYPE_INTEGER:
				new_record.data.integer = 0;
				new_record.type = EXPRESSION_TYPE_INTEGER;
				break;
			case EXPRESSION_TYPE_REAL:
				new_record.data.real = 0.0;
				new_record.type = EXPRESSION_TYPE_REAL;
				break;

			case EXPRESSION_TYPE_STRING:
				new_record.data.string = _malloc(1);
				new_record.data.string[0] = '\0';
				new_record.type = EXPRESSION_TYPE_STRING;
				break;
		}
	}

	symbol_table_insert_new(symbol_table, variable_declaration->variable_ident.value.string, new_record, variable_type, strlen_max);
}
static void exec_statement_block(struct Statement_Block_Node *statement_block, struct Symbol_Table *symbol_table)
{
	while(statement_block != NULL)
	{
		struct Statement_Node *current_statement = statement_block->statement;
		exec_statement(current_statement, symbol_table);
		statement_block = statement_block->statement_block;
	}
}
static void exec_statement(struct Statement_Node *statement, struct Symbol_Table *symbol_table)
{
		switch(statement->type)
		{
			case STATEMENT_TYPE_BLOCK_IF_STATEMENT:
				exec_block_if_statement(statement->statement.block_if_statement, symbol_table);
				break;

			case STATEMENT_TYPE_SIMPLE_IF_STATEMENT:
				exec_simple_if_statement(statement->statement.simple_if_statement, symbol_table);
				break;

			case STATEMENT_TYPE_SIMPLE_STATEMENT:
				if(statement->statement.simple_statement->type == SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT)
				{
					exec_assignment_statement(statement->statement.simple_statement->statement.assignment_statement, symbol_table);
				}
				else if(statement->statement.simple_statement->type == SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT)
				{
					exec_print_statement(statement->statement.simple_statement->statement.print_statement, symbol_table);
				}
				break;
		}
}
static void exec_block_if_statement(struct Block_If_Statement_Node *block_if_statement, struct Symbol_Table *symbol_table)
{
	if(block_if_statement == NULL)
		return;

	int condition = eval_logical_expression(block_if_statement->logical_expression, symbol_table);
	if(condition)
	{
		exec_statement_block(block_if_statement->statement_block, symbol_table);
	}
	else
	{
		exec_statement_block(block_if_statement->else_statement_block, symbol_table);
	}
}
static void exec_simple_if_statement(struct Simple_If_Statement_Node *simple_if_statement, struct Symbol_Table *symbol_table)
{
	if(simple_if_statement == NULL)
		return;

	int condition = eval_logical_expression(simple_if_statement->logical_expression, symbol_table);
	if(condition)
	{
		exec_statement(simple_if_statement->statement, symbol_table);
	}
}
static void exec_assignment_statement(struct Assignment_Statement_Node *assignment_statement, struct Symbol_Table *symbol_table)
{
	struct Expression_Record expression = eval_expression(assignment_statement->expression, symbol_table);

	symbol_table_update(symbol_table, assignment_statement->ident.value.string, expression);
}
static void exec_print_statement(struct Print_Statement_Node *print_statement, struct Symbol_Table *symbol_table)
{
	struct Expression_Print_List_Node *current = print_statement->expression_print_list;
	while(current != NULL)
	{
		struct Expression_Record expression = eval_expression(current->expression, symbol_table);
		switch(expression.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				printf("%d", expression.data.integer);
				break;
			case EXPRESSION_TYPE_REAL:
				printf("%.4f", expression.data.real);
				break;
			case EXPRESSION_TYPE_STRING:
				printf("%s", expression.data.string);
				free(expression.data.string);
				break;
		}
		if(current->expression_print_list != NULL)
		{
			printf(" ");
		}
		current = current->expression_print_list;
	}
	printf("\n");
}

static int eval_logical_expression(struct Logical_Expression_Node *expression, struct Symbol_Table *symbol_table)
{
	int out = 0;
	struct Expression_Record expr1_record = eval_expression(expression->first_expression, symbol_table);

	if(expression->second_expression == NULL)
	{
		switch(expr1_record.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				if(expr1_record.data.integer != 0)
				{
					out = 1;
				}
				break;
			case EXPRESSION_TYPE_REAL:
				if(expr1_record.data.real != 0.0)
				{
					out = 1;
				}
				break;
			case EXPRESSION_TYPE_STRING:
				if(expr1_record.data.string[0] != '\0')
				{
					out = 1;
				}
				break;
		}
		return out;
	}
	
	struct Expression_Record expr2_record = eval_expression(expression->second_expression, symbol_table);
	switch(expr1_record.type)
	{
		case EXPRESSION_TYPE_INTEGER:
			switch(expr2_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(expression->op)
					{
						case LOGICAL_OPERATOR_EQ:
							out = expr1_record.data.integer == expr2_record.data.integer;
							break;
						case LOGICAL_OPERATOR_GTHAN:
							out = expr1_record.data.integer > expr2_record.data.integer;
							break;
						case LOGICAL_OPERATOR_LTHAN:
							out = expr1_record.data.integer < expr2_record.data.integer;
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(expression->op)
					{
						case LOGICAL_OPERATOR_EQ:
							out = expr1_record.data.integer == expr2_record.data.real;
							break;
						case LOGICAL_OPERATOR_GTHAN:
							out = expr1_record.data.integer > expr2_record.data.real;
							break;
						case LOGICAL_OPERATOR_LTHAN:
							out = expr1_record.data.integer < expr2_record.data.real;
							break;
					}
					break;
				
				case EXPRESSION_TYPE_STRING:
					out = 0;
					break;
			}
			break;
		case EXPRESSION_TYPE_REAL:
			switch(expr2_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(expression->op)
					{
						case LOGICAL_OPERATOR_EQ:
							out = expr1_record.data.real == expr2_record.data.integer;
							break;
						case LOGICAL_OPERATOR_GTHAN:
							out = expr1_record.data.real > expr2_record.data.integer;
							break;
						case LOGICAL_OPERATOR_LTHAN:
							out = expr1_record.data.real < expr2_record.data.integer;
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(expression->op)
					{
						case LOGICAL_OPERATOR_EQ:
							out = expr1_record.data.real == expr2_record.data.real;
							break;
						case LOGICAL_OPERATOR_GTHAN:
							out = expr1_record.data.real > expr2_record.data.real;
							break;
						case LOGICAL_OPERATOR_LTHAN:
							out = expr1_record.data.real < expr2_record.data.real;
							break;
					}
					break;
					
				case EXPRESSION_TYPE_STRING:
					out = 0;
					break;
			}
			break;
			
		case EXPRESSION_TYPE_STRING:
			switch(expr2_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					out = 0;
					break;
				case EXPRESSION_TYPE_REAL:
					out = 0;
					break;
					
				case EXPRESSION_TYPE_STRING:
					out = !strcmp(expr1_record.data.string, expr2_record.data.string);
					free(expr1_record.data.string);
					free(expr2_record.data.string);
					break;
			}
			break;
	}
	return out;
}
static struct Expression_Record eval_expression(struct Expression_Node *expression, struct Symbol_Table *symbol_table)
{
	struct Expression_Record out;
	struct Expression_Record mult_expression_record = eval_mult_expression(expression->mult_expression, symbol_table);
	if(expression->expression == NULL)
	{
		return mult_expression_record;
	}
	struct Expression_Record expression_record = eval_expression(expression->expression, symbol_table);
	int nbytes;

	switch(expression_record.type)
	{
		case EXPRESSION_TYPE_INTEGER:
			switch(mult_expression_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							out.type = EXPRESSION_TYPE_INTEGER;
							out.data.integer = expression_record.data.integer + mult_expression_record.data.integer;
							break;
						case EXPRESSION_OPERATOR_MINUS:
							out.type = EXPRESSION_TYPE_INTEGER;
							out.data.integer = expression_record.data.integer - mult_expression_record.data.integer;
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%d%d", expression_record.data.integer, mult_expression_record.data.integer) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%d%d", expression_record.data.integer, mult_expression_record.data.integer);
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.integer + mult_expression_record.data.real;
							break;
						case EXPRESSION_OPERATOR_MINUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.integer - mult_expression_record.data.real;
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%d%.4f", expression_record.data.integer, mult_expression_record.data.real) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%d%.4f", expression_record.data.integer, mult_expression_record.data.real);
							break;
					}
					break;
					
				case EXPRESSION_TYPE_STRING:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							fprintf(stderr, "interpreter: invalid operands '%d' + '%s'\n", expression_record.data.integer, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_MINUS:
							fprintf(stderr, "interpreter: invalid operands '%d' - '%s'\n", expression_record.data.integer, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%d%s", expression_record.data.integer, mult_expression_record.data.string) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%d%s", expression_record.data.integer, mult_expression_record.data.string);
							free(mult_expression_record.data.string);
							break;
					}
					break;
			}
			break;
		case EXPRESSION_TYPE_REAL:
			switch(mult_expression_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.real + mult_expression_record.data.integer;
							break;
						case EXPRESSION_OPERATOR_MINUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.real - mult_expression_record.data.integer;
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%.4f%d", expression_record.data.real, mult_expression_record.data.integer) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%.4f%d", expression_record.data.real, mult_expression_record.data.integer);
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.real + mult_expression_record.data.real;
							break;
						case EXPRESSION_OPERATOR_MINUS:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = expression_record.data.real - mult_expression_record.data.real;
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%.4f%.4f", expression_record.data.real, mult_expression_record.data.real) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%.4f%.4f", expression_record.data.real, mult_expression_record.data.real);
							break;
					}
					break;
				
				case EXPRESSION_TYPE_STRING:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							fprintf(stderr, "interpreter: invalid operands '%.4f' + '%s'\n", expression_record.data.real, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_MINUS:
							fprintf(stderr, "interpreter: invalid operands '%.4f' - '%s'\n", expression_record.data.real, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%.4f%s", expression_record.data.real, mult_expression_record.data.string) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%.4f%s", expression_record.data.real, mult_expression_record.data.string);
							free(mult_expression_record.data.string);
							break;
					}
					break;
			}
			break;
			
		case EXPRESSION_TYPE_STRING:
			switch(mult_expression_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							fprintf(stderr, "interpreter: invalid operands '%s' + '%d'\n", expression_record.data.string, mult_expression_record.data.integer);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_MINUS:
							fprintf(stderr, "interpreter: invalid operands '%s' - '%d'\n", expression_record.data.string, mult_expression_record.data.integer);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%s%d", expression_record.data.string, mult_expression_record.data.integer) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%s%d", expression_record.data.string, mult_expression_record.data.integer);
							free(expression_record.data.string);
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							fprintf(stderr, "interpreter: invalid operands '%s' + '%.4f'\n", expression_record.data.string, mult_expression_record.data.real);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_MINUS:
							fprintf(stderr, "interpreter: invalid operands '%s' - '%.4f'\n", expression_record.data.string, mult_expression_record.data.real);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%s%.4f", expression_record.data.string, mult_expression_record.data.real) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%s%.4f", expression_record.data.string, mult_expression_record.data.real);
							free(expression_record.data.string);
							break;
					}
					break;
					
				case EXPRESSION_TYPE_STRING:
					switch(expression->op)
					{
						case EXPRESSION_OPERATOR_PLUS:
							fprintf(stderr, "interpreter: invalid operands '%s' + '%s'\n", expression_record.data.string, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_MINUS:
							out.type = EXPRESSION_TYPE_STRING;
							fprintf(stderr, "interpreter: invalid operands '%s' - '%s'\n", expression_record.data.string, mult_expression_record.data.string);
							exit(3);
							break;
						case EXPRESSION_OPERATOR_CAT:
							out.type = EXPRESSION_TYPE_STRING;
							nbytes = snprintf(NULL, 0, "%s%s", expression_record.data.string, mult_expression_record.data.string) + 1;
							out.data.string = _malloc(nbytes + 1);
							sprintf(out.data.string, "%s%s", expression_record.data.string, mult_expression_record.data.string);
							free(expression_record.data.string);
							free(mult_expression_record.data.string);
							break;
					}
					break;
			}
			break;
	}	

	if(out.type == EXPRESSION_TYPE_STRING && strlen(out.data.string) > MAX_STRING_LENGTH)
	{
		fprintf(stderr, "String value '%s' exceeds maximum string length of %d\n", out.data.string, MAX_STRING_LENGTH);
		exit(3);
	}
	return out;
}
static struct Expression_Record eval_mult_expression(struct Mult_Expression_Node *mult_expression, struct Symbol_Table *symbol_table)
{
	struct Expression_Record term_expression_record = eval_term_expression(mult_expression->term_expression, symbol_table);
	if(mult_expression->mult_expression == NULL)
	{
		return term_expression_record;
	}
	struct Expression_Record mult_expression_record = eval_mult_expression(mult_expression->mult_expression, symbol_table);
	struct Expression_Record out;
	switch(mult_expression_record.type)
	{
		case EXPRESSION_TYPE_INTEGER:
			switch(term_expression_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(mult_expression->op)
					{
						case MULT_EXPRESSION_OPERATOR_DIV:
							if(term_expression_record.data.integer == 0)
							{
								fprintf(stderr, "interpreter: divide by 0\n");
								exit(3);
							}
							out.type = EXPRESSION_TYPE_INTEGER;
							out.data.integer = mult_expression_record.data.integer / term_expression_record.data.integer;
							break;
						case MULT_EXPRESSION_OPERATOR_MULT:
							out.type = EXPRESSION_TYPE_INTEGER;
							out.data.integer = mult_expression_record.data.integer * term_expression_record.data.integer;
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(mult_expression->op)
					{
						case MULT_EXPRESSION_OPERATOR_DIV:
							if(term_expression_record.data.real == 0.0)
							{
								fprintf(stderr, "interpreter: tried to divide by 0.0\n");
								exit(3);
							}
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.integer / term_expression_record.data.real;
							break;
						case MULT_EXPRESSION_OPERATOR_MULT:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.integer * term_expression_record.data.real;
							break;
					}
					break;
					
				case EXPRESSION_TYPE_STRING:
					fprintf(stderr, "interpreter: invalid operand '%s' for * or / operator\n", term_expression_record.data.string);
					exit(3);
					break;
			}
			break;
		case EXPRESSION_TYPE_REAL:
			switch(term_expression_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					switch(mult_expression->op)
					{
						case MULT_EXPRESSION_OPERATOR_DIV:
							if(term_expression_record.data.integer == 0)
							{
								fprintf(stderr, "interpreter: tried to divide by 0\n");
								exit(3);
							}
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.real / term_expression_record.data.integer;
							break;
						case MULT_EXPRESSION_OPERATOR_MULT:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.real * term_expression_record.data.integer;
							break;
					}
					break;
				case EXPRESSION_TYPE_REAL:
					switch(mult_expression->op)
					{
						case MULT_EXPRESSION_OPERATOR_DIV:
							if(term_expression_record.data.real == 0.0)
							{
								fprintf(stderr, "interpreter: tried to divide by 0.0\n");
								exit(3);
							}
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.real / term_expression_record.data.real;
							break;
						case MULT_EXPRESSION_OPERATOR_MULT:
							out.type = EXPRESSION_TYPE_REAL;
							out.data.real = mult_expression_record.data.real * term_expression_record.data.real;
							break;
					}
					break;
					
				case EXPRESSION_TYPE_STRING:
					fprintf(stderr, "interpreter: invalid operand '%s' for * or / operator\n", term_expression_record.data.string);
					exit(3);
					break;
			}
			break;
			
		case EXPRESSION_TYPE_STRING:
			fprintf(stderr, "interpreter: invalid operand '%s' for * or / operator\n", mult_expression_record.data.string);
			exit(3);
			break;
	}
	return out;
}
static struct Expression_Record eval_term_expression(struct Term_Expression_Node *term_expression, struct Symbol_Table *symbol_table)
{
	struct Expression_Record s_factor_record = eval_s_factor(term_expression->s_factor, symbol_table);
	if(term_expression->exponent == NULL)
	{
		return s_factor_record;
	}

	struct Expression_Record exponent_record = eval_term_expression(term_expression->exponent, symbol_table);
	struct Expression_Record out;

	switch(s_factor_record.type)
	{
		case EXPRESSION_TYPE_INTEGER:
			switch(exponent_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					out.type = EXPRESSION_TYPE_INTEGER;
					out.data.integer = ipow(s_factor_record.data.integer, exponent_record.data.integer);
					break;
				case EXPRESSION_TYPE_REAL:
					out.type = EXPRESSION_TYPE_REAL;
					out.data.real = pow(s_factor_record.data.integer, exponent_record.data.real);
					break;
					
				case EXPRESSION_TYPE_STRING:
					fprintf(stderr, "interpreter: invalid operand '%s' for exponentiation\n", exponent_record.data.string);
					exit(3);
					break;
			}
			break;
		case EXPRESSION_TYPE_REAL:
			switch(exponent_record.type)
			{
				case EXPRESSION_TYPE_INTEGER:
					out.type = EXPRESSION_TYPE_REAL;
					out.data.real = pow(s_factor_record.data.real, exponent_record.data.integer);
					break;
				case EXPRESSION_TYPE_REAL:
					out.type = EXPRESSION_TYPE_REAL;
					out.data.real = pow(s_factor_record.data.real, exponent_record.data.real);
					break;
					
				case EXPRESSION_TYPE_STRING:
					fprintf(stderr, "interpreter: invalid exponent '%s' for exponentiation\n", exponent_record.data.string);
					exit(3);
					break;
			}
			break;
			
		case EXPRESSION_TYPE_STRING:
			fprintf(stderr, "interpreter: invalid base '%s' for exponentiation\n", s_factor_record.data.string);
			exit(3);
			break;
	}
	return out;
}
static struct Expression_Record eval_s_factor(struct S_Factor_Node *s_factor, struct Symbol_Table *symbol_table)
{
	struct Expression_Record factor_record = eval_factor(s_factor->factor, symbol_table);
	struct Expression_Record out;

	if(s_factor->op == S_FACTOR_OPERATOR_UNARY_MINUS)
	{
		switch(factor_record.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				out.type = EXPRESSION_TYPE_INTEGER;
				out.data.integer = -(factor_record.data.integer);
				break;
			case EXPRESSION_TYPE_REAL:
				out.type = EXPRESSION_TYPE_REAL;
				out.data.real = -(factor_record.data.real);
				break;
				
			case EXPRESSION_TYPE_STRING:
				fprintf(stderr, "interpreter: nvalid operand for unary minus '%s'\n", factor_record.data.string);
				exit(3);
				break;
		}
	}
	else
	{
		out = factor_record;
	}
	return out;
}
static struct Expression_Record eval_factor(struct Factor_Node *factor, struct Symbol_Table *symbol_table)
{
	if(factor->expression != NULL)
	{
		return eval_expression(factor->expression, symbol_table);
	}

	struct Expression_Record out_record;
	int found;
	struct Expression_Record temp;

	switch(factor->symbol.type)
	{
		case SYMBOL_TYPE_INTEGER:
			out_record.type = EXPRESSION_TYPE_INTEGER;
			out_record.data.integer = factor->symbol.value.integer;
			break;
		case SYMBOL_TYPE_REAL:
			out_record.type = EXPRESSION_TYPE_REAL;
			out_record.data.real = factor->symbol.value.real;
			break;
		case SYMBOL_TYPE_STRING:
			out_record.type = EXPRESSION_TYPE_STRING;
			out_record.data.string = _malloc(strlen(factor->symbol.value.string) + 1);
			strcpy(out_record.data.string, factor->symbol.value.string);
			break;
		case SYMBOL_TYPE_IDENT:
			temp = symbol_table_retrieve_record(symbol_table, factor->symbol.value.string, &found);
			if(!found)
			{
				fprintf(stderr, "interpreter: Tried to use undeclared identifier '%s'\n", factor->symbol.value.string);
				exit(2);
			}
			if(temp.type == EXPRESSION_TYPE_STRING)
			{
				out_record.type = EXPRESSION_TYPE_STRING;
				out_record.data.string = _malloc(strlen(temp.data.string) + 1);
				strcpy(out_record.data.string , temp.data.string);
			}
			else
			{
				out_record = temp;
			}
			return out_record;
	}
	
	if(out_record.type == EXPRESSION_TYPE_STRING && strlen(out_record.data.string) > MAX_STRING_LENGTH)
	{
		fprintf(stderr, "String value '%s' exceeds maximum string length of %d\n", out_record.data.string, MAX_STRING_LENGTH);
		exit(3);
	}

	return out_record;
}
