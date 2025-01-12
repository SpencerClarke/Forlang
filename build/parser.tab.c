/* A Bison parser, made by GNU Bison 3.8.  */

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
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

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

	extern int yylex();

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
  YYSYMBOL_NEWLINE = 7,                    /* NEWLINE  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_END = 9,                        /* END  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_CHARACTER = 12,                 /* CHARACTER  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_INTEGER = 14,                   /* INTEGER  */
  YYSYMBOL_REAL = 15,                      /* REAL  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_LEN = 17,                       /* LEN  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MULT = 20,                      /* MULT  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_POW = 22,                       /* POW  */
  YYSYMBOL_ASSOP = 23,                     /* ASSOP  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_LTHAN = 25,                     /* LTHAN  */
  YYSYMBOL_GTHAN = 26,                     /* GTHAN  */
  YYSYMBOL_CAT = 27,                       /* CAT  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_DCOLON = 31,                    /* DCOLON  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_program_body = 35,              /* program_body  */
  YYSYMBOL_declaration_block = 36,         /* declaration_block  */
  YYSYMBOL_full_declaration = 37,          /* full_declaration  */
  YYSYMBOL_declared_variable_type = 38,    /* declared_variable_type  */
  YYSYMBOL_variable_declaration_list = 39, /* variable_declaration_list  */
  YYSYMBOL_variable_declaration = 40,      /* variable_declaration  */
  YYSYMBOL_statement_block = 41,           /* statement_block  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_block_if_statement = 43,        /* block_if_statement  */
  YYSYMBOL_simple_if_statement = 44,       /* simple_if_statement  */
  YYSYMBOL_simple_statement = 45,          /* simple_statement  */
  YYSYMBOL_assignment_statement = 46,      /* assignment_statement  */
  YYSYMBOL_print_statement = 47,           /* print_statement  */
  YYSYMBOL_expression_print_list = 48,     /* expression_print_list  */
  YYSYMBOL_logical_expression = 49,        /* logical_expression  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_mult_expression = 51,           /* mult_expression  */
  YYSYMBOL_term_expression = 52,           /* term_expression  */
  YYSYMBOL_s_factor = 53,                  /* s_factor  */
  YYSYMBOL_factor = 54                     /* factor  */
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
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  99

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    89,    92,    95,   101,   104,   110,   113,
     116,   123,   126,   132,   136,   142,   147,   156,   159,   165,
     168,   171,   177,   180,   186,   192,   195,   201,   209,   215,
     218,   223,   226,   229,   232,   239,   242,   245,   248,   254,
     257,   260,   267,   270,   275,   278,   281,   287,   291,   296,
     302,   308
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
  "RCONST", "SCONST", "NEWLINE", "PROGRAM", "END", "ELSE", "IF",
  "CHARACTER", "THEN", "INTEGER", "REAL", "PRINT", "LEN", "PLUS", "MINUS",
  "MULT", "DIV", "POW", "ASSOP", "EQ", "LTHAN", "GTHAN", "CAT", "COMMA",
  "LPAREN", "RPAREN", "DCOLON", "DOT", "$accept", "program",
  "program_body", "declaration_block", "full_declaration",
  "declared_variable_type", "variable_declaration_list",
  "variable_declaration", "statement_block", "statement",
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

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,    21,    24,    15,   -27,     9,    11,   -26,   -27,   -27,
      28,    48,    45,     3,    23,   -27,    45,   -27,   -27,   -27,
     -27,   -27,     4,     4,    49,    55,    40,    73,   -27,   -27,
      55,   -27,   -27,   -27,   -27,   -27,     8,     8,     4,    33,
       0,   -27,    60,   -27,    53,    52,    61,    62,   -27,    58,
       4,    83,   -27,   -27,   -27,    20,     4,     4,     4,     4,
       4,     4,    42,     4,     4,     4,    85,     4,    55,    64,
      33,   -27,   -27,     0,     0,     0,   -27,   -27,   -27,    45,
     -27,    33,    33,    33,    59,    33,   -27,     4,    63,    65,
      33,    79,    45,    55,   -27,    82,   -27,    84,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,    12,    11,
       0,     0,     5,     7,     0,     4,    18,    19,    20,    21,
      25,    26,     0,     0,     0,     0,     0,     0,     3,     6,
       0,    17,    47,    49,    48,    50,     0,     0,     0,    27,
      38,    41,    43,    46,     0,    31,     0,    15,    10,    14,
       0,     0,     8,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      30,     2,    51,    35,    37,    36,    39,    40,    42,     0,
      24,    32,    34,    33,     0,    16,    13,     0,     0,     0,
      29,     0,     0,     0,    22,     0,     9,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,    80,   -27,   -27,   -24,   -27,   -12,    32,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -22,     6,   -25,
     -27,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    11,    12,    13,    14,    48,    49,    15,    16,
      17,    18,    19,    20,    21,    69,    44,    39,    40,    41,
      42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    45,     1,    24,    31,    25,    52,    32,    33,    34,
      35,    32,    33,    34,    35,     7,    55,     8,     9,     5,
      59,    60,    36,    37,     4,     3,     6,     7,    70,     8,
       9,    10,    22,    38,    76,    77,    78,    38,    56,    57,
      23,    81,    82,    83,    86,    85,     5,    58,    26,     5,
      72,    56,    57,     6,    30,    79,     6,    27,    10,    47,
      58,    10,    73,    74,    75,    90,    46,    88,    50,    96,
      56,    57,    91,    92,    53,    54,    63,    64,    65,    58,
      95,    51,    61,    62,    66,    67,    68,    71,    84,    89,
      94,    97,    87,    29,    80,    98,    93
};

static const yytype_int8 yycheck[] =
{
      12,    23,     8,    29,    16,    31,    30,     3,     4,     5,
       6,     3,     4,     5,     6,    12,    38,    14,    15,     4,
      20,    21,    18,    19,     0,     4,    11,    12,    50,    14,
      15,    16,    23,    29,    59,    60,    61,    29,    18,    19,
      29,    63,    64,    65,    68,    67,     4,    27,    20,     4,
      30,    18,    19,    11,    31,    13,    11,     9,    16,     4,
      27,    16,    56,    57,    58,    87,    17,    79,    28,    93,
      18,    19,     9,    10,    36,    37,    24,    25,    26,    27,
      92,     8,    22,    30,    23,    23,    28,     4,     3,    30,
      11,     9,    28,    13,    62,    11,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    34,     4,     0,     4,    11,    12,    14,    15,
      16,    35,    36,    37,    38,    41,    42,    43,    44,    45,
      46,    47,    23,    29,    29,    31,    20,     9,    41,    36,
      31,    41,     3,     4,     5,     6,    18,    19,    29,    50,
      51,    52,    53,    54,    49,    50,    17,     4,    39,    40,
      28,     8,    39,    54,    54,    50,    18,    19,    27,    20,
      21,    22,    30,    24,    25,    26,    23,    23,    28,    48,
      50,     4,    30,    51,    51,    51,    52,    52,    52,    13,
      42,    50,    50,    50,     3,    50,    39,    28,    41,    30,
      50,     9,    10,    31,    11,    41,    39,     9,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    36,    36,    37,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    42,    43,    43,    44,    45,    45,    46,    47,    48,
      48,    49,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    51,    52,    52,    53,    53,    53,    54,    54,    54,
      54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     1,     1,     2,     1,     3,     8,
       3,     1,     1,     3,     1,     1,     3,     2,     1,     1,
       1,     1,     8,    10,     5,     1,     1,     3,     4,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     3
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
#line 81 "src/parser.y"
                                                     {
		free((yyvsp[-4].strval));
		free((yyvsp[0].strval));
		*((struct Program_Body_Node **)root) = (yyvsp[-3].program_body_node);
	}
#line 1312 "build/parser.tab.c"
    break;

  case 3: /* program_body: declaration_block statement_block  */
#line 89 "src/parser.y"
                                          {
		(yyval.program_body_node) = program_body_node_init((yyvsp[-1].declaration_block_node), (yyvsp[0].statement_block_node));
	}
#line 1320 "build/parser.tab.c"
    break;

  case 4: /* program_body: statement_block  */
#line 92 "src/parser.y"
                          {
		(yyval.program_body_node) = program_body_node_init(NULL, (yyvsp[0].statement_block_node));
	}
#line 1328 "build/parser.tab.c"
    break;

  case 5: /* program_body: declaration_block  */
#line 95 "src/parser.y"
                            {
		(yyval.program_body_node) = program_body_node_init((yyvsp[0].declaration_block_node), NULL);
	}
#line 1336 "build/parser.tab.c"
    break;

  case 6: /* declaration_block: full_declaration declaration_block  */
#line 101 "src/parser.y"
                                           {
		(yyval.declaration_block_node) = declaration_block_node_init((yyvsp[-1].full_declaration_node), (yyvsp[0].declaration_block_node));
	}
#line 1344 "build/parser.tab.c"
    break;

  case 7: /* declaration_block: full_declaration  */
#line 104 "src/parser.y"
                           {
		(yyval.declaration_block_node) = declaration_block_node_init((yyvsp[0].full_declaration_node), NULL);
	}
#line 1352 "build/parser.tab.c"
    break;

  case 8: /* full_declaration: declared_variable_type DCOLON variable_declaration_list  */
#line 110 "src/parser.y"
                                                                {
		(yyval.full_declaration_node) = full_declaration_node_init((yyvsp[-2].declared_variable_type_value), (yyvsp[0].variable_declaration_list_node), 0);
	}
#line 1360 "build/parser.tab.c"
    break;

  case 9: /* full_declaration: CHARACTER LPAREN LEN ASSOP ICONST RPAREN DCOLON variable_declaration_list  */
#line 113 "src/parser.y"
                                                                                    {
		(yyval.full_declaration_node) = full_declaration_node_init(SYMBOL_TYPE_STRING, (yyvsp[0].variable_declaration_list_node), (yyvsp[-3].intval));
	}
#line 1368 "build/parser.tab.c"
    break;

  case 10: /* full_declaration: CHARACTER DCOLON variable_declaration_list  */
#line 116 "src/parser.y"
                                                     {
		/*Default strlen_max for character is 1 in fortran*/
		(yyval.full_declaration_node) = full_declaration_node_init(SYMBOL_TYPE_STRING, (yyvsp[0].variable_declaration_list_node), 1);
	}
#line 1377 "build/parser.tab.c"
    break;

  case 11: /* declared_variable_type: REAL  */
#line 123 "src/parser.y"
             {
		(yyval.declared_variable_type_value) = SYMBOL_TYPE_REAL;
	}
#line 1385 "build/parser.tab.c"
    break;

  case 12: /* declared_variable_type: INTEGER  */
#line 126 "src/parser.y"
                  {
		(yyval.declared_variable_type_value) = SYMBOL_TYPE_INTEGER;
	}
#line 1393 "build/parser.tab.c"
    break;

  case 13: /* variable_declaration_list: variable_declaration COMMA variable_declaration_list  */
#line 132 "src/parser.y"
                                                             {
		(yyval.variable_declaration_list_node) = variable_declaration_list_node_init((yyvsp[-2].variable_declaration_node), (yyvsp[0].variable_declaration_list_node));
	}
#line 1401 "build/parser.tab.c"
    break;

  case 14: /* variable_declaration_list: variable_declaration  */
#line 136 "src/parser.y"
                             {
		(yyval.variable_declaration_list_node) = variable_declaration_list_node_init((yyvsp[0].variable_declaration_node), NULL);
	}
#line 1409 "build/parser.tab.c"
    break;

  case 15: /* variable_declaration: IDENT  */
#line 142 "src/parser.y"
              {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[0].strval));
		(yyval.variable_declaration_node) = variable_declaration_node_init(variable_ident, NULL);
		free((yyvsp[0].strval));
	}
#line 1419 "build/parser.tab.c"
    break;

  case 16: /* variable_declaration: IDENT ASSOP expression  */
#line 147 "src/parser.y"
                                 {
		struct Symbol variable_ident = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[-2].strval));
		(yyval.variable_declaration_node) = variable_declaration_node_init(variable_ident, (yyvsp[0].expression_node));
		free((yyvsp[-2].strval));
	}
#line 1429 "build/parser.tab.c"
    break;

  case 17: /* statement_block: statement statement_block  */
#line 156 "src/parser.y"
                                  {
		(yyval.statement_block_node) = statement_block_node_init((yyvsp[-1].statement_node), (yyvsp[0].statement_block_node));
	}
#line 1437 "build/parser.tab.c"
    break;

  case 18: /* statement_block: statement  */
#line 159 "src/parser.y"
                    {
		(yyval.statement_block_node) = statement_block_node_init((yyvsp[0].statement_node), NULL);
	}
#line 1445 "build/parser.tab.c"
    break;

  case 19: /* statement: block_if_statement  */
#line 165 "src/parser.y"
                           {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_BLOCK_IF_STATEMENT, (yyvsp[0].block_if_statement_node));
	}
#line 1453 "build/parser.tab.c"
    break;

  case 20: /* statement: simple_if_statement  */
#line 168 "src/parser.y"
                              {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_SIMPLE_IF_STATEMENT, (yyvsp[0].simple_if_statement_node));
	}
#line 1461 "build/parser.tab.c"
    break;

  case 21: /* statement: simple_statement  */
#line 171 "src/parser.y"
                           {
		(yyval.statement_node) = statement_node_init(STATEMENT_TYPE_SIMPLE_STATEMENT, (yyvsp[0].simple_statement_node));
	}
#line 1469 "build/parser.tab.c"
    break;

  case 22: /* block_if_statement: IF LPAREN logical_expression RPAREN THEN statement_block END IF  */
#line 177 "src/parser.y"
                                                                        {
		(yyval.block_if_statement_node) = block_if_statement_init((yyvsp[-5].logical_expression_node), (yyvsp[-2].statement_block_node), NULL);
	}
#line 1477 "build/parser.tab.c"
    break;

  case 23: /* block_if_statement: IF LPAREN logical_expression RPAREN THEN statement_block ELSE statement_block END IF  */
#line 180 "src/parser.y"
                                                                                               {
		(yyval.block_if_statement_node) = block_if_statement_init((yyvsp[-7].logical_expression_node), (yyvsp[-4].statement_block_node), (yyvsp[-2].statement_block_node));
	}
#line 1485 "build/parser.tab.c"
    break;

  case 24: /* simple_if_statement: IF LPAREN logical_expression RPAREN statement  */
#line 186 "src/parser.y"
                                                      {
		(yyval.simple_if_statement_node) = simple_if_statement_node_init((yyvsp[-2].logical_expression_node), (yyvsp[0].statement_node));
	}
#line 1493 "build/parser.tab.c"
    break;

  case 25: /* simple_statement: assignment_statement  */
#line 192 "src/parser.y"
                             {
		(yyval.simple_statement_node) = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_ASSIGNMENT_STATEMENT, (yyvsp[0].assignment_statement_node));
	}
#line 1501 "build/parser.tab.c"
    break;

  case 26: /* simple_statement: print_statement  */
#line 195 "src/parser.y"
                          {
		(yyval.simple_statement_node) = simple_statement_node_init(SIMPLE_STATEMENT_TYPE_PRINT_STATEMENT, (yyvsp[0].print_statement_node));
	}
#line 1509 "build/parser.tab.c"
    break;

  case 27: /* assignment_statement: IDENT ASSOP expression  */
#line 201 "src/parser.y"
                               {
		struct Symbol ident_symbol = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[-2].strval));
		(yyval.assignment_statement_node) = assignment_statement_node_init(ident_symbol, (yyvsp[0].expression_node));
		free((yyvsp[-2].strval));
	}
#line 1519 "build/parser.tab.c"
    break;

  case 28: /* print_statement: PRINT MULT COMMA expression_print_list  */
#line 209 "src/parser.y"
                                               {
		(yyval.print_statement_node) = print_statement_node_init((yyvsp[0].expression_print_list_node));
	}
#line 1527 "build/parser.tab.c"
    break;

  case 29: /* expression_print_list: expression_print_list COMMA expression  */
#line 215 "src/parser.y"
                                               {
		(yyval.expression_print_list_node) = expression_print_list_node_init((yyvsp[-2].expression_print_list_node), (yyvsp[0].expression_node));
	}
#line 1535 "build/parser.tab.c"
    break;

  case 30: /* expression_print_list: expression  */
#line 218 "src/parser.y"
                     {
		(yyval.expression_print_list_node) = expression_print_list_node_init(NULL, (yyvsp[0].expression_node));
	}
#line 1543 "build/parser.tab.c"
    break;

  case 31: /* logical_expression: expression  */
#line 223 "src/parser.y"
                   {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[0].expression_node), LOGICAL_OPERATOR_EQ, NULL);
	}
#line 1551 "build/parser.tab.c"
    break;

  case 32: /* logical_expression: expression EQ expression  */
#line 226 "src/parser.y"
                                   {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_EQ, (yyvsp[0].expression_node));
	}
#line 1559 "build/parser.tab.c"
    break;

  case 33: /* logical_expression: expression GTHAN expression  */
#line 229 "src/parser.y"
                                       {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_GTHAN, (yyvsp[0].expression_node));
	}
#line 1567 "build/parser.tab.c"
    break;

  case 34: /* logical_expression: expression LTHAN expression  */
#line 232 "src/parser.y"
                                      {
		(yyval.logical_expression_node) = logical_expression_node_init((yyvsp[-2].expression_node), LOGICAL_OPERATOR_LTHAN, (yyvsp[0].expression_node));
	}
#line 1575 "build/parser.tab.c"
    break;

  case 35: /* expression: expression PLUS mult_expression  */
#line 239 "src/parser.y"
                                        {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_PLUS, (yyvsp[0].mult_expression_node));
	}
#line 1583 "build/parser.tab.c"
    break;

  case 36: /* expression: expression CAT mult_expression  */
#line 242 "src/parser.y"
                                         {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_CAT, (yyvsp[0].mult_expression_node));
	}
#line 1591 "build/parser.tab.c"
    break;

  case 37: /* expression: expression MINUS mult_expression  */
#line 245 "src/parser.y"
                                           {
		(yyval.expression_node) = expression_node_init((yyvsp[-2].expression_node), EXPRESSION_OPERATOR_MINUS, (yyvsp[0].mult_expression_node));
	}
#line 1599 "build/parser.tab.c"
    break;

  case 38: /* expression: mult_expression  */
#line 248 "src/parser.y"
                           {
		(yyval.expression_node) = expression_node_init(NULL, EXPRESSION_OPERATOR_PLUS, (yyvsp[0].mult_expression_node));
	}
#line 1607 "build/parser.tab.c"
    break;

  case 39: /* mult_expression: mult_expression MULT term_expression  */
#line 254 "src/parser.y"
                                             {
		(yyval.mult_expression_node) = mult_expression_node_init((yyvsp[-2].mult_expression_node), MULT_EXPRESSION_OPERATOR_MULT, (yyvsp[0].term_expression_node));
	}
#line 1615 "build/parser.tab.c"
    break;

  case 40: /* mult_expression: mult_expression DIV term_expression  */
#line 257 "src/parser.y"
                                              {
		(yyval.mult_expression_node) = mult_expression_node_init((yyvsp[-2].mult_expression_node), MULT_EXPRESSION_OPERATOR_DIV, (yyvsp[0].term_expression_node));
	}
#line 1623 "build/parser.tab.c"
    break;

  case 41: /* mult_expression: term_expression  */
#line 260 "src/parser.y"
                          {
		(yyval.mult_expression_node) = mult_expression_node_init(NULL, MULT_EXPRESSION_OPERATOR_DIV, (yyvsp[0].term_expression_node));
	}
#line 1631 "build/parser.tab.c"
    break;

  case 42: /* term_expression: s_factor POW term_expression  */
#line 267 "src/parser.y"
                                     {
		(yyval.term_expression_node) = term_expression_node_init((yyvsp[-2].s_factor_node), (yyvsp[0].term_expression_node));
	}
#line 1639 "build/parser.tab.c"
    break;

  case 43: /* term_expression: s_factor  */
#line 270 "src/parser.y"
                   {
		(yyval.term_expression_node) = term_expression_node_init((yyvsp[0].s_factor_node), NULL);
	}
#line 1647 "build/parser.tab.c"
    break;

  case 44: /* s_factor: PLUS factor  */
#line 275 "src/parser.y"
                    {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, (yyvsp[0].factor_node));
	}
#line 1655 "build/parser.tab.c"
    break;

  case 45: /* s_factor: MINUS factor  */
#line 278 "src/parser.y"
                       {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_MINUS, (yyvsp[0].factor_node));
	}
#line 1663 "build/parser.tab.c"
    break;

  case 46: /* s_factor: factor  */
#line 281 "src/parser.y"
                 {
		(yyval.s_factor_node) = s_factor_node_init(S_FACTOR_OPERATOR_UNARY_PLUS, (yyvsp[0].factor_node));
	}
#line 1671 "build/parser.tab.c"
    break;

  case 47: /* factor: ICONST  */
#line 287 "src/parser.y"
               {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_INTEGER, &((yyvsp[0].intval)));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
	}
#line 1680 "build/parser.tab.c"
    break;

  case 48: /* factor: RCONST  */
#line 292 "src/parser.y"
        {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_REAL, &((yyvsp[0].dval)));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
	}
#line 1689 "build/parser.tab.c"
    break;

  case 49: /* factor: IDENT  */
#line 296 "src/parser.y"
                 {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, (yyvsp[0].strval));
		(yyval.factor_node) = factor_node_init(symbol, NULL);

		free((yyvsp[0].strval));
	}
#line 1700 "build/parser.tab.c"
    break;

  case 50: /* factor: SCONST  */
#line 302 "src/parser.y"
                 {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_STRING, (yyvsp[0].strval));
		(yyval.factor_node) = factor_node_init(symbol, NULL);
		
		free((yyvsp[0].strval));
	}
#line 1711 "build/parser.tab.c"
    break;

  case 51: /* factor: LPAREN expression RPAREN  */
#line 308 "src/parser.y"
                                   {
		struct Symbol symbol = symbol_init(SYMBOL_TYPE_IDENT, NULL);
		(yyval.factor_node) = factor_node_init(symbol, (yyvsp[-1].expression_node));
	}
#line 1720 "build/parser.tab.c"
    break;


#line 1724 "build/parser.tab.c"

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

#line 314 "src/parser.y"


void yyerror(void **root, const char *s)
{
	extern int yylineno;
	*((struct Program_Body_Node **)root) = NULL;
	fprintf(stderr, "parser: error on line %d: %s\n", yylineno, s);
}
