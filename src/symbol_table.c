#include "../include/symbol_table.h"

static void *_malloc(size_t n);
static struct Symbol_Table_Node *_symbol_table_get_node(struct Symbol_Table *table, const char *ident, int write);
static struct Symbol_Table_Node *_symbol_table_node_init();
static void _symbol_table_destroy(struct Symbol_Table_Node *current);
static void symbol_table_insert_integer(struct Symbol_Table *table, const char *ident, int value);
static void symbol_table_insert_real(struct Symbol_Table *table, const char *ident, double value);
static void symbol_table_insert_string(struct Symbol_Table *table, const char *ident, char *value);
static void symbol_table_insert_new_string(struct Symbol_Table *table, const char *ident, char *value, int strlen_max);

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

static struct Symbol_Table_Node *_symbol_table_node_init()
{
	struct Symbol_Table_Node *out = _malloc(sizeof(struct Symbol_Table_Node));

	out->left = out->right = NULL;
	out->has_data = 0;
	
	return out;
}

struct Symbol_Table symbol_table_init(void)
{
	struct Symbol_Table out;

	out.root = NULL;
	
	return out;
}

static struct Symbol_Table_Node *_symbol_table_get_node(struct Symbol_Table *table, const char *ident, int write)
{
	struct Symbol_Table_Node *current;
	const char *p;

	if(table->root == NULL)
	{
		if(!write)
		{
			return NULL;
		}
		table->root = _symbol_table_node_init();
	}

	current = table->root;
	for(p = ident; *p != '\0'; p++)
	{
		int bit_offset;
		for(bit_offset = 0; bit_offset < CHAR_BIT; bit_offset++)
		{
			struct Symbol_Table_Node **child;
			
			if((*p) & (1 << bit_offset))
			{
				child = &(current->left);
			}
			else
			{
				child = &(current->right);
			}
			if(*child == NULL)
			{
				if(!write)
				{
					return NULL;
				}

				*child = _symbol_table_node_init();
			}
			current = *child;
		}
	}
	return current;
}

static void symbol_table_insert_integer(struct Symbol_Table *table, const char *ident, int value)
{
	struct Symbol_Table_Node *node = _symbol_table_get_node(table, ident, 1);

	if(node->has_data && node->entry.value.type != EXPRESSION_TYPE_INTEGER)
	{
		fprintf(stderr, "symbol_table_insert_integer: Tried to assign an integer value into a non-integer symbol\n");
		exit(3);
	}

	node->entry.value.type = EXPRESSION_TYPE_INTEGER;
	node->has_data = 1;
	node->entry.value.data.integer = value;
}

static void symbol_table_insert_real(struct Symbol_Table *table, const char *ident, double value)
{
	struct Symbol_Table_Node *node = _symbol_table_get_node(table, ident, 1);
	if(node->has_data && node->entry.value.type != EXPRESSION_TYPE_REAL)
	{
		fprintf(stderr, "symbol_table_insert_real: Tried to assign a real value into a non-real symbol\n");
		exit(3);
	}
	node->entry.value.type = EXPRESSION_TYPE_REAL;
	node->has_data = 1;
	node->entry.value.data.real = value;
}

static void symbol_table_insert_new_string(struct Symbol_Table *table, const char *ident, char *value, int strlen_max)
{
	struct Symbol_Table_Node *node = _symbol_table_get_node(table, ident, 1);
	
	if(node->has_data && node->entry.value.type != EXPRESSION_TYPE_STRING)
	{
		fprintf(stderr, "symbol_table_insert_string: Tried to assign an string value into a non-string symbol\n");
		exit(3);
	}

	if(node->has_data && node->entry.value.type == EXPRESSION_TYPE_STRING)
	{
		if(strlen(value) > node->entry.strlen_max)
		{
			fprintf
			(
				stderr, 
				"String '%s' too large for variable '%s' with maximum string length %zu\n", 
				value,
				ident,
				node->entry.strlen_max
			);
			exit(3);
		}
		free(node->entry.value.data.string);
	}
	node->entry.value.type = EXPRESSION_TYPE_STRING;
	node->has_data = 1;
	node->entry.value.data.string = value;
	node->entry.strlen_max = strlen_max;
}

static void symbol_table_insert_string(struct Symbol_Table *table, const char *ident, char *value)
{
	struct Symbol_Table_Node *node = _symbol_table_get_node(table, ident, 0);
	
	if(node->has_data && node->entry.value.type != EXPRESSION_TYPE_STRING)
	{
		fprintf(stderr, "symbol_table_insert_string: Tried to assign an string value into a non-string symbol\n");
		exit(3);
	}
	
	if(node->entry.value.type == EXPRESSION_TYPE_STRING)
	{
		if(strlen(value) > node->entry.strlen_max)
		{
			fprintf
			(
				stderr, 
				"String '%s' too large for variable '%s' with maximum string length %zu\n", 
				value,
				ident,
				node->entry.strlen_max
			);
			exit(3);
		}
	}

	if(node->has_data && node->entry.value.type == EXPRESSION_TYPE_STRING)
	{
		free(node->entry.value.data.string);
	}
	node->entry.value.type = EXPRESSION_TYPE_STRING;
	node->has_data = 1;
	node->entry.value.data.string = value;
}

struct Expression_Record symbol_table_retrieve_record(struct Symbol_Table *table, const char *ident, int *found)
{
	struct Expression_Record out;

	out.data.integer = 0;
	out.type = EXPRESSION_TYPE_INTEGER;
	*found = 1;
	struct Symbol_Table_Node *node = _symbol_table_get_node(table, ident, 0);
	if(node == NULL || !node->has_data)
	{
		*found = 0;
		return out;
	}
	return node->entry.value; 
}

void symbol_table_insert_new(struct Symbol_Table *table, const char *ident, struct Expression_Record record, enum Expression_Type type, size_t strlen_max)
{
	int symbol_found;
	symbol_table_retrieve_record(table, ident, &symbol_found);
	if(symbol_found)
	{
		fprintf(stderr, "Error: redeclaration of identifier %s\n", ident);
		exit(3);
	}

	switch(type)
	{
		char *temp;
		case EXPRESSION_TYPE_INTEGER:
			symbol_table_insert_integer(table, ident, 0);
			break;

		case EXPRESSION_TYPE_REAL:
			symbol_table_insert_real(table, ident, 0.0);
			break;

		case EXPRESSION_TYPE_STRING:
			temp = _malloc(1);
			*temp = '\0';
			symbol_table_insert_new_string(table, ident, temp, strlen_max);
			break;
	}
	symbol_table_update(table, ident, record);
}

void symbol_table_update(struct Symbol_Table *table, const char *ident, struct Expression_Record record)
{
	int symbol_found;
	struct Expression_Record temp = symbol_table_retrieve_record(table, ident, &symbol_found);
	enum Expression_Type type = temp.type;

	if(!symbol_found)
	{
		fprintf(stderr, "Error: Usage of undeclared identifier %s\n", ident);
		exit(4);
	}

	if(type == EXPRESSION_TYPE_INTEGER)
	{
		switch(record.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				symbol_table_insert_integer(table, ident, record.data.integer);
				break;

			case EXPRESSION_TYPE_REAL:
				symbol_table_insert_integer(table, ident, record.data.real);
				break;

			case EXPRESSION_TYPE_STRING:
				fprintf(stderr, "Error: Tried to assign a value of type string to a variable of type integer\n");
				exit(3);
				break;
		}
		
	}
	else if(type == EXPRESSION_TYPE_REAL)
	{
		switch(record.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				symbol_table_insert_real(table, ident, record.data.integer);
				break;

			case EXPRESSION_TYPE_REAL:
				symbol_table_insert_real(table, ident, record.data.real);
				break;

			case EXPRESSION_TYPE_STRING:
				fprintf(stderr, "Error: Tried to assign a value of type string to a variable of type real\n");
				exit(3);
				break;
		}
	}
	else if(type == EXPRESSION_TYPE_STRING)
	{
		int nbytes;
		char *new_string;
		
		switch(record.type)
		{
			case EXPRESSION_TYPE_INTEGER:
				nbytes = snprintf(NULL, 0, "%d", record.data.integer) + 1;
				new_string = _malloc(nbytes);
				sprintf(new_string, "%d", record.data.integer);
				symbol_table_insert_string(table, ident, new_string);
				break;

			case EXPRESSION_TYPE_REAL:
				nbytes = snprintf(NULL, 0, "%.4f", record.data.real) + 1;
				new_string = _malloc(nbytes);
				sprintf(new_string, "%.4f", record.data.real);
				symbol_table_insert_string(table, ident, new_string);
				break;
				
			case EXPRESSION_TYPE_STRING:
				symbol_table_insert_string(table, ident, record.data.string);
				break;
		}
	}
}

static void _symbol_table_destroy(struct Symbol_Table_Node *current)
{
	if(current == NULL)
	{
		return;
	}
	if(current->has_data && current->entry.value.type == EXPRESSION_TYPE_STRING)
	{
		free(current->entry.value.data.string);
	}
	_symbol_table_destroy(current->left);
	_symbol_table_destroy(current->right);

	free(current);
}
void symbol_table_destroy(struct Symbol_Table *table)
{
	_symbol_table_destroy(table->root);
}
