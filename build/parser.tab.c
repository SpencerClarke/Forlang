/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

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

#line 86 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ICONST = 3,                     /* ICONST  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_RCONST = 5,                     /* RCONST  */
  YYSYMBOL_SCONST = 6,                     /* SCONST  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_NEWLINE = 9,                    /* NEWLINE  */
  YYSYMBOL_PROGRAM = 10,                   /* PROGRAM  */
  YYSYMBOL_END = 11,                       /* END  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_CHARACTER = 14,                 /* CHARACTER  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_INTEGER = 16,                   /* INTEGER  */
  YYSYMBOL_REAL = 17,                      /* REAL  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_LEN = 19,                       /* LEN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_MULT = 22,                      /* MULT  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_POW = 24,                       /* POW  */
  YYSYMBOL_ASSOP = 25,                     /* ASSOP  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_LTHAN = 27,                     /* LTHAN  */
  YYSYMBOL_GTHAN = 28,                     /* GTHAN  */
  YYSYMBOL_CAT = 29,                       /* CAT  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_LPAREN = 31,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 32,                    /* RPAREN  */
  YYSYMBOL_DCOLON = 33,                    /* DCOLON  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_DEF = 35,                       /* DEF  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_program_body = 38,              /* program_body  */
  YYSYMBOL_declaration_block = 39,         /* declaration_block  */
  YYSYMBOL_full_declaration = 40,          /* full_declaration  */
  YYSYMBOL_declared_variable_type = 41,    /* declared_variable_type  */
  YYSYMBOL_variable_declaration_list = 42, /* variable_declaration_list  */
  YYSYMBOL_variable_declaration = 43,      /* variable_declaration  */
  YYSYMBOL_statement_block = 44,           /* statement_block  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_do_while_loop = 46,             /* do_while_loop  */
  YYSYMBOL_block_if_statement = 47,        /* block_if_statement  */
  YYSYMBOL_simple_if_statement = 48,       /* simple_if_statement  */
  YYSYMBOL_simple_statement = 49,          /* simple_statement  */
  YYSYMBOL_assignment_statement = 50,      /* assignment_statement  */
  YYSYMBOL_print_statement = 51,           /* print_statement  */
  YYSYMBOL_expression_print_list = 52,     /* expression_print_list  */
  YYSYMBOL_logical_expression = 53,        /* logical_expression  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_mult_expression = 55,           /* mult_expression  */
  YYSYMBOL_term_expression = 56,           /* term_expression  */
  YYSYMBOL_s_factor = 57,                  /* s_factor  */
  YYSYMBOL_factor = 58                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    91,    94,    97,   103,   106,   112,   115,
     118,   125,   128,   134,   138,   144,   149,   158,   161,   167,
     170,   173,   176,   182,   188,   191,   197,   203,   206,   212,
     220,   226,   229,   234,   237,   240,   243,   250,   253,   256,
     259,   265,   268,   271,   278,   281,   286,   289,   292,   298,
     302,   307,   313,   319
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ICONST", "IDENT",
  "RCONST", "SCONST", "DO", "WHILE", "NEWLINE", "PROGRAM", "END", "ELSE",
  "IF", "CHARACTER", "THEN", "INTEGER", "REAL", "PRINT", "LEN", "PLUS",
  "MINUS", "MULT", "DIV", "POW", "ASSOP", "EQ", "LTHAN", "GTHAN", "CAT",
  "COMMA", "LPAREN", "RPAREN", "DCOLON", "DOT", "DEF", "$accept",
  "program", "program_body", "declaration_block", "full_declaration",
  "declared_variable_type", "variable_declaration_list",
  "variable_declaration", "statement_block", "statement", "do_while_loop",
  "block_if_statement", "simple_if_statement", "simple_statement",
  "assignment_statement", "print_statement", "expression_print_list",
  "logical_expression", "expression", "mult_expression", "term_expression",
  "s_factor", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -8,     3,    28,    16,   -26,    17,    48,    31,   -14,   -26,
     -26,    41,    64,    47,   -11,    44,   -26,    47,   -26,   -26,
     -26,   -26,   -26,   -26,     6,    52,     6,    59,    80,    55,
      76,   -26,   -26,    80,   -26,   -26,   -26,   -26,   -26,    10,
      10,     6,    37,    -1,   -26,    65,   -26,     6,    56,    53,
      66,    67,   -26,    60,     6,    89,   -26,   -26,   -26,    23,
       6,     6,     6,     6,     6,     6,    62,    46,     6,     6,
       6,    92,     6,    80,    68,    37,   -26,   -26,    -1,    -1,
      -1,   -26,   -26,   -26,    47,    47,   -26,    37,    37,    37,
      69,    37,   -26,     6,    85,    13,    70,    37,    90,    86,
      47,    80,   -26,   -26,    91,   -26,    87,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,    12,
      11,     0,     0,     5,     7,     0,     4,    18,    22,    19,
      20,    21,    27,    28,     0,     0,     0,     0,     0,     0,
       0,     3,     6,     0,    17,    49,    51,    50,    52,     0,
       0,     0,    29,    40,    43,    45,    48,     0,     0,    33,
       0,    15,    10,    14,     0,     0,     8,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    32,     2,    53,    37,    39,
      38,    41,    42,    44,     0,     0,    26,    34,    36,    35,
       0,    16,    13,     0,     0,     0,     0,    31,     0,     0,
       0,     0,    23,    24,     0,     9,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,    93,   -26,   -26,   -25,   -26,   -13,    38,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,    57,   -23,   -22,
       4,   -26,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    12,    13,    14,    15,    52,    53,    16,    17,
      18,    19,    20,    21,    22,    23,    74,    48,    49,    43,
      44,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    42,     1,     8,    34,     9,    10,     3,    56,    35,
      36,    37,    38,    35,    36,    37,    38,    27,    59,    28,
       5,    63,    64,     6,    99,   100,    39,    40,     4,     7,
       8,    75,     9,    10,    11,    57,    58,    41,    78,    79,
      80,    41,    24,    60,    61,    87,    88,    89,    92,    91,
       5,     5,    62,     6,     6,    77,    25,    60,    61,     7,
       7,    85,    26,    29,    11,    11,    62,    81,    82,    83,
      97,    94,    95,    60,    61,    30,   105,    33,    50,    68,
      69,    70,    62,    47,    51,    54,    55,   104,    67,    65,
      73,    71,    72,    76,    84,    90,    98,   102,    93,   103,
     107,    96,   106,   101,    66,    86,     0,    32
};

static const yytype_int8 yycheck[] =
{
      13,    24,    10,    14,    17,    16,    17,     4,    33,     3,
       4,     5,     6,     3,     4,     5,     6,    31,    41,    33,
       4,    22,    23,     7,    11,    12,    20,    21,     0,    13,
      14,    54,    16,    17,    18,    39,    40,    31,    60,    61,
      62,    31,    25,    20,    21,    68,    69,    70,    73,    72,
       4,     4,    29,     7,     7,    32,     8,    20,    21,    13,
      13,    15,    31,    22,    18,    18,    29,    63,    64,    65,
      93,    84,    85,    20,    21,    11,   101,    33,    19,    26,
      27,    28,    29,    31,     4,    30,    10,   100,    32,    24,
      30,    25,    25,     4,    32,     3,    11,     7,    30,    13,
      13,    32,    11,    33,    47,    67,    -1,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    37,     4,     0,     4,     7,    13,    14,    16,
      17,    18,    38,    39,    40,    41,    44,    45,    46,    47,
      48,    49,    50,    51,    25,     8,    31,    31,    33,    22,
      11,    44,    39,    33,    44,     3,     4,     5,     6,    20,
      21,    31,    54,    55,    56,    57,    58,    31,    53,    54,
      19,     4,    42,    43,    30,    10,    42,    58,    58,    54,
      20,    21,    29,    22,    23,    24,    53,    32,    26,    27,
      28,    25,    25,    30,    52,    54,     4,    32,    55,    55,
      55,    56,    56,    56,    32,    15,    45,    54,    54,    54,
       3,    54,    42,    30,    44,    44,    32,    54,    11,    11,
      12,    33,     7,    13,    44,    42,    11,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    39,    39,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    45,    45,    46,    47,    47,    48,    49,    49,    50,
      51,    52,    52,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     1,     1,     2,     1,     3,     8,
       3,     1,     1,     3,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     8,     8,    10,     5,     1,     1,     3,
       4,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void **root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (root);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void **root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void **root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void **root)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void **root)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM IDENT program_body END PROGRAM IDENT  */
#line 83 "src/parser.y"
                                                     {
		free((yyvsp[-4].strval));
		free((yyvsp[0].strval));
		*((struct Program_Body_Node **)root) = (yyvsp[-3].program_body_node);
	}
#line 1322 "build/parser.tab.c"
    break;

  case 3: /* program_body: declaration_block statement_block  */
#line 91 "src/parser.y"
                                          {
		(yyval.program_body_node) = program_body_node_init((yyvsp[-1].declaration_block_node), (yyvsp[0].statement_block_node));
	}
#line 1330 "build/parser.tab.c"
    break;

  case 4: /* program_body: statement_block  */
#line 94 "src/parser.y"
                          {
		(yyval.program_body_node) = program_body_node_init(NULL, (yyvsp[0].statement_block_node));
	}
#line 1338 "build/parser.tab.c"
    break;

  case 5: /* program_body: declaration_block  */
#line 97 "src/parser.y"
                            {
		(yyval.program_body_node) = program_body_node_init((yyvsp[0].declaration_block_node), NULL);
	}
#line 1346 "build/parser.tab.c"
    break;

  case 6: /* declaration_block: full_declaration declaration_block  */
#line 103 "src/parser.y"
                                           {
		(yyval.declaration_block_node) = declaration_block_node_init((yyvsp[-1].full_declaration_node), (yyvsp[0].declaration_block_node));
	}
#line 1354 "build/parser.tab.c"
    break;

  case 7: /* declaration_block: full_declaration  */
#line 106 "src/parser.y"
                           {
		(yyval.declaration_block_node) = declaration_block_node_init((yyvsp[0].full_declaration_node), NULL);
	}
#line 1362 "build/parser.tab.c"
    break;

  case 8: /* full_declaration: declared_variable_type DCOLON variable_declaration_list  */
#line 112 "src/parser.y"
                                                                {
		(yyval.full_declaration_node) = full_declaration_node_init((yyvsp[-2].declared_variable_type_value), (yyvsp[0].variable_declaration_list_node), 0);
	}
#line 1370 "build/parser.tab.c"
    break;

  case 9: /* full_declaration: CHARACTER LPAREN LEN ASSOP ICONST RPAREN DCOLON variable_declaration_list  */
#line 115 "src/parser.y"
                                                                                    {
		(yyval.full_declaration_node) = full_declaration_node_init(SYMBOL_TYPE_STRING, (yyvsp[0].variable_declaration_list_node), (yyvsp[-3].intval));
	}
#line 1378 "build/parser.tab.c"
    break;

  case 10: /* full_declaration: CHARACTER DCOLON variable_declaration_list  */
#line 118 "src/parser.y"
                                                     {
		/*Default strlen_max for character is 1 in fortran*/
		(yyval.full_declaration_node) = full_declaration_node_init(SYMBOL_TYPE_STRING, (yyvsp[0].variable_declaration_list_node), 1);
	}
#line 1387 "build/parser.tab.c"
    break;

  case 11: /* declared_variable_type: REAL  */
#line 125 "src/parser.y"
             {
		(yyval.declared_variable_type_value) = SYMBOL_TYPE_REAL;
	}
#line 1395 "build/parser.tab.c"
    break;

  case 12: /* declared_variable_type: INTEGER  */
#line 128 "src/parser.y"
                  {
		(yyval.declared_variable_type_value) = SYMBOL_TYPE_INTEGER;
	}
#line 1403 "build/parser.tab.c"
    break;

  case 13: /* variable_declaration_list: variable_declaration COMMA variable_declaration_list  */
#line 134 "src/parser.y"
                                                             {
		(yyval.variable_declaration_list_node) = variable_declaration_list_node_init((yyvsp[-2].variable_declaration_node), (yyvsp[0].variable_declaration_list_node));
	}
#line 1411 "build/parser.tab.c"
    break;

  case 14: /* variable_declaration_list: variable_declaration  */
#line 138 "src/parser.y"
                             {
		(yyval.variable_declaration_list_node) = variable_declaration_list_node_init((yyvsp[0].variable_declaration_node), NULL);
	}
#line 1419 "build/parser.tab.c"
    break;

  case 15: /* variable_declaration: IDENT  */
#line 144 "src/parser.y"
              {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[0].strval));
		(yyval.variable_declaration_node) = variable_declaration_node_init(variable_ident, NULL);
		free((yyvsp[0].strval));
	}
#line 1429 "build/parser.tab.c"
    break;

  case 16: /* variable_declaration: IDENT ASSOP expression  */
#line 149 "src/parser.y"
                                 {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[-2].strval));
		(yyval.variable_declaration_node) = variable_declaration_node_init(variable_ident, (yyvsp[0].expression_node));
		free((yyvsp[-2].strval));
	}
#line 1439 "build/parser.tab.c"
    break;

  case 17: /* statement_block: statement statement_block  */
#line 158 "src/parser.y"
                                  {
		(yyval.statement_block_node) = statement_block_node_init((yyvsp[-1].statement_node), (yyvsp[0].statement_block_node));
	}
#line 1447 "build/parser.tab.c"
    break;

  case 18: /* statement_block: statement  */
#line 161 "src/parser.y"
                    {
		(yyval.statement_block_node) = statement_block_node_init((yyvsp[0].statement_node), NULL);
	}
#line 1455 "build/parser.tab.c"
    break;

  case 19: /* statement: block_if_statement  */
#line 167 "src/parser.y"
                           {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_BLOCK_IF_STATEMENT, (yyvsp[0].block_if_statement_node));
	}
#line 1463 "build/parser.tab.c"
    break;

  case 20: /* statement: simple_if_statement  */
#line 170 "src/parser.y"
                              {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_SIMPLE_IF_STATEMENT, (yyvsp[0].simple_if_statement_node));
	}
#line 1471 "build/parser.tab.c"
    break;

  case 21: /* statement: simple_statement  */
#line 173 "src/parser.y"
                           {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_SIMPLE_STATEMENT, (yyvsp[0].simple_statement_node));
	}
#line 1479 "build/parser.tab.c"
    break;

  case 22: /* statement: do_while_loop  */
#line 176 "src/parser.y"
                        {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_DO_WHILE_LOOP, (yyvsp[0].do_while_loop_node));
	}
#line 1487 "build/parser.tab.c"
    break;

  case 23: /* do_while_loop: DO WHILE LPAREN logical_expression RPAREN statement_block END DO  */
#line 182 "src/parser.y"
                                                                         {
		(yyval.do_while_loop_node) = do_while_loop_node_init((yyvsp[-4].logical_expression_node), (yyvsp[-2].statement_block_node));
	}
#line 1495 "build/parser.tab.c"
    break;

  case 24: /* block_if_statement: IF LPAREN logical_expression RPAREN THEN statement_block END IF  */
#line 188 "src/parser.y"
                                                                        {
		(yyval.block_if_statement_node) = block_if_statement_init((yyvsp[-5].logical_expression_node), (yyvsp[-2].statement_block_node), NULL);
	}
#line 1503 "build/parser.tab.c"
    break;

  case 25: /* block_if_statement: IF LPAREN logical_expression RPAREN THEN statement_block ELSE statement_block END IF  */
#line 191 "src/parser.y"
                                                                                               {
		(yyval.block_if_statement_node) = block_if_statement_init((yyvsp[-7].logical_expression_node), (yyvsp[-4].statement_block_node), (yyvsp[-2].statement_block_node));
	}
#line 1511 "build/parser.tab.c"
    break;

  case 26: /* simple_if_statement: IF LPAREN logical_expression RPAREN statement  */
#line 197 "src/parser.y"
                                                      {
		(yyval.simple_if_statement_node) = simple_if_statement_node_init((yyvsp[-2].logical_expression_node), (yyvsp[0].statement_node));
	}
#line 1519 "build/parser.tab.c"
    break;

  case 27: /* simple_statement: assignment_statement  */
#line 203 "src/parser.y"
                             {
		(yyval.simple_statement_node) = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT, (yyvsp[0].assignment_statement_node));
	}
#line 1527 "build/parser.tab.c"
    break;

  case 28: /* simple_statement: print_statement  */
#line 206 "src/parser.y"
                          {
		(yyval.simple_statement_node) = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT, (yyvsp[0].print_statement_node));
	}
#line 1535 "build/parser.tab.c"
    break;

  case 29: /* assignment_statement: IDENT ASSOP expression  */
#line 212 "src/parser.y"
                               {
		struct Symbol ident_symbol = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[-2].strval));
		(yyval.assignment_statement_node) = assignment_statement_node_init(ident_symbol, (yyvsp[0].expression_node));
		free((yyvsp[-2].strval));
	}
#line 1545 "build/parser.tab.c"
    break;

  case 30: /* print_statement: PRINT MULT COMMA expression_print_list  */
#line 220 "src/parser.y"
                                               {
		(yyval.print_statement_node) = print_statement_node_init((yyvsp[0].expression_print_list_node));
	}
#line 1553 "build/parser.tab.c"
    break;

  case 31: /* expression_print_list: expression_print_list COMMA expression  */
#line 226 "src/parser.y"
                                               {
		(yyval.expression_print_list_node) = expression_print_list_node_init((yyvsp[-2].expression_print_list_node), (yyvsp[0].expression_node));
	}
#line 1561 "build/parser.tab.c"
    break;

  case 32: /* expression_print_list: expression  */
#line 229 "src/parser.y"
                     {
		(yyval.expression_print_list_node) = expression_print_list_node_init(NULL, (yyvsp[0].expression_node));
	}
#line 1569 "build/parser.tab.c"
    break;

  case 33: /* logical_expression: expression  */
#line 234 "src/parser.y"
                   {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[0].expression_node), LOGICAL_OPERATOR_EQ, NULL);
	}
#line 1577 "build/parser.tab.c"
    break;

  case 34: /* logical_expression: expression EQ expression  */
#line 237 "src/parser.y"
                                   {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_EQ, (yyvsp[0].expression_node));
	}
#line 1585 "build/parser.tab.c"
    break;

  case 35: /* logical_expression: expression GTHAN expression  */
#line 240 "src/parser.y"
                                       {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_GTHAN, (yyvsp[0].expression_node));
	}
#line 1593 "build/parser.tab.c"
    break;

  case 36: /* logical_expression: expression LTHAN expression  */
#line 243 "src/parser.y"
                                      {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_LTHAN, (yyvsp[0].expression_node));
	}
#line 1601 "build/parser.tab.c"
    break;

  case 37: /* expression: expression PLUS mult_expression  */
#line 250 "src/parser.y"
                                        {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_PLUS, (yyvsp[0].mult_expression_node));
	}
#line 1609 "build/parser.tab.c"
    break;

  case 38: /* expression: expression CAT mult_expression  */
#line 253 "src/parser.y"
                                         {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_CAT, (yyvsp[0].mult_expression_node));
	}
#line 1617 "build/parser.tab.c"
    break;

  case 39: /* expression: expression MINUS mult_expression  */
#line 256 "src/parser.y"
                                           {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_MINUS, (yyvsp[0].mult_expression_node));
	}
#line 1625 "build/parser.tab.c"
    break;

  case 40: /* expression: mult_expression  */
#line 259 "src/parser.y"
                           {
		(yyval.expression_node) = expression_node_init(NULL, EXPRESSION_OPERATOR_PLUS, (yyvsp[0].mult_expression_node));
	}
#line 1633 "build/parser.tab.c"
    break;

  case 41: /* mult_expression: mult_expression MULT term_expression  */
#line 265 "src/parser.y"
                                             {
		(yyval.mult_expression_node) = mult_expression_node_init((yyvsp[-2].mult_expression_node), MULT_EXPRESSION_OPERATOR_MULT, (yyvsp[0].term_expression_node));
	}
#line 1641 "build/parser.tab.c"
    break;

  case 42: /* mult_expression: mult_expression DIV term_expression  */
#line 268 "src/parser.y"
                                              {
		(yyval.mult_expression_node) = mult_expression_node_init((yyvsp[-2].mult_expression_node), MULT_EXPRESSION_OPERATOR_DIV, (yyvsp[0].term_expression_node));
	}
#line 1649 "build/parser.tab.c"
    break;

  case 43: /* mult_expression: term_expression  */
#line 271 "src/parser.y"
                          {
		(yyval.mult_expression_node) = mult_expression_node_init(NULL, MULT_EXPRESSION_OPERATOR_DIV, (yyvsp[0].term_expression_node));
	}
#line 1657 "build/parser.tab.c"
    break;

  case 44: /* term_expression: s_factor POW term_expression  */
#line 278 "src/parser.y"
                                     {
		(yyval.term_expression_node) = term_expression_node_init((yyvsp[-2].s_factor_node), (yyvsp[0].term_expression_node));
	}
#line 1665 "build/parser.tab.c"
    break;

  case 45: /* term_expression: s_factor  */
#line 281 "src/parser.y"
                   {
		(yyval.term_expression_node) = term_expression_node_init((yyvsp[0].s_factor_node), NULL);
	}
#line 1673 "build/parser.tab.c"
    break;

  case 46: /* s_factor: PLUS factor  */
#line 286 "src/parser.y"
                    {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, (yyvsp[0].factor_node));
	}
#line 1681 "build/parser.tab.c"
    break;

  case 47: /* s_factor: MINUS factor  */
#line 289 "src/parser.y"
                       {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_MINUS, (yyvsp[0].factor_node));
	}
#line 1689 "build/parser.tab.c"
    break;

  case 48: /* s_factor: factor  */
#line 292 "src/parser.y"
                 {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, (yyvsp[0].factor_node));
	}
#line 1697 "build/parser.tab.c"
    break;

  case 49: /* factor: ICONST  */
#line 298 "src/parser.y"
               {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_INTEGER, &((yyvsp[0].intval)));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
	}
#line 1706 "build/parser.tab.c"
    break;

  case 50: /* factor: RCONST  */
#line 303 "src/parser.y"
        {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_REAL, &((yyvsp[0].dval)));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
	}
#line 1715 "build/parser.tab.c"
    break;

  case 51: /* factor: IDENT  */
#line 307 "src/parser.y"
                 {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, (yyvsp[0].strval));
		(yyval.factor_node) = factor_node_init(symbol, NULL);

		free((yyvsp[0].strval));
	}
#line 1726 "build/parser.tab.c"
    break;

  case 52: /* factor: SCONST  */
#line 313 "src/parser.y"
                 {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[0].strval));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
		
		free((yyvsp[0].strval));
	}
#line 1737 "build/parser.tab.c"
    break;

  case 53: /* factor: LPAREN expression RPAREN  */
#line 319 "src/parser.y"
                                   {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, NULL);
		(yyval.factor_node) = factor_node_init(symbol, (yyvsp[-1].expression_node));
	}
#line 1746 "build/parser.tab.c"
    break;


#line 1750 "build/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (root, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, root);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 325 "src/parser.y"


void yyerror(void **root, const char *s)
{
	extern int yylineno;
	*((struct Program_Body_Node **)root) = NULL;
	fprintf(stderr, "parser: error on line %d: %s\n", yylineno, s);
}
