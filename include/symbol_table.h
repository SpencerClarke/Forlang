#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

enum Expression_Type
{
	EXPRESSION_TYPE_REAL,
	EXPRESSION_TYPE_INTEGER,
	EXPRESSION_TYPE_STRING
};
union Expression_Data
{
	char *string;
	int integer;
	float real;
};
struct Expression_Record
{
	enum Expression_Type type;
	union Expression_Data data;
};

struct Symbol_Table_Entry
{
	struct Expression_Record value;
	size_t strlen_max;
};

struct Symbol_Table_Node
{
	int has_data;
	struct Symbol_Table_Entry entry;
	struct Symbol_Table_Node *left;
	struct Symbol_Table_Node *right;
};

struct Symbol_Table
{
	struct Symbol_Table_Node *root;
};

struct Symbol_Table symbol_table_init(void);
void symbol_table_update(struct Symbol_Table *table, const char *ident, struct Expression_Record record);
void symbol_table_insert_new(struct Symbol_Table *table, const char *ident, struct Expression_Record record, enum Expression_Type type, size_t strlen_max);
struct Expression_Record symbol_table_retrieve_record(struct Symbol_Table *table, const char *ident, int *found);
void symbol_table_destroy(struct Symbol_Table *table);

#endif
