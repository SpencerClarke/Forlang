/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 16 "src/parser.y"

	#include "ast.h"

#line 53 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ICONST = 258,                  /* ICONST  */
    IDENT = 259,                   /* IDENT  */
    RCONST = 260,                  /* RCONST  */
    SCONST = 261,                  /* SCONST  */
    NEWLINE = 262,                 /* NEWLINE  */
    PROGRAM = 263,                 /* PROGRAM  */
    END = 264,                     /* END  */
    ELSE = 265,                    /* ELSE  */
    IF = 266,                      /* IF  */
    CHARACTER = 267,               /* CHARACTER  */
    THEN = 268,                    /* THEN  */
    INTEGER = 269,                 /* INTEGER  */
    REAL = 270,                    /* REAL  */
    PRINT = 271,                   /* PRINT  */
    LEN = 272,                     /* LEN  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    MULT = 275,                    /* MULT  */
    DIV = 276,                     /* DIV  */
    POW = 277,                     /* POW  */
    ASSOP = 278,                   /* ASSOP  */
    EQ = 279,                      /* EQ  */
    LTHAN = 280,                   /* LTHAN  */
    GTHAN = 281,                   /* GTHAN  */
    CAT = 282,                     /* CAT  */
    COMMA = 283,                   /* COMMA  */
    LPAREN = 284,                  /* LPAREN  */
    RPAREN = 285,                  /* RPAREN  */
    DCOLON = 286,                  /* DCOLON  */
    DOT = 287                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "src/parser.y"

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

#line 128 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void **root);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
