/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "syntax.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "intercode.h"
#include "target.h"
#include "lex.yy.c"

extern node *root;
extern int flex_error;
int bison_error = 0;

/* Line 371 of yacc.c  */
#line 82 "syntax.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     ID = 259,
     FLOAT = 260,
     RETURN = 261,
     IF = 262,
     WHILE = 263,
     TYPE = 264,
     STRUCT = 265,
     OCT = 266,
     HEX = 267,
     COMMA = 268,
     SEMI = 269,
     LC = 270,
     RC = 271,
     ASSIGN = 272,
     NOT = 273,
     DOT = 274,
     RB = 275,
     LB = 276,
     RP = 277,
     LP = 278,
     DIV = 279,
     STAR = 280,
     MINUS = 281,
     PLUS = 282,
     RELOP = 283,
     OR = 284,
     AND = 285,
     LOWER_THAN_ELSE = 286,
     ELSE = 287
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 15 "syntax.y"

	node* no;


/* Line 387 of yacc.c  */
#line 162 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "syntax.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    16,    20,    24,
      26,    30,    32,    34,    40,    43,    45,    46,    48,    50,
      55,    60,    64,    67,    71,    73,    76,    81,    84,    87,
      90,    91,    94,    97,    99,   103,   109,   117,   123,   126,
     127,   131,   133,   137,   139,   143,   147,   151,   155,   159,
     163,   167,   171,   175,   179,   182,   185,   190,   194,   199,
     203,   205,   207,   209,   211,   213,   216,   219,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    36,    35,    -1,    -1,    38,
      37,    14,    -1,    38,    14,    -1,    38,    43,    46,    -1,
      38,    43,    14,    -1,    42,    -1,    42,    13,    37,    -1,
       9,    -1,    39,    -1,    10,    40,    15,    49,    16,    -1,
      10,    41,    -1,     4,    -1,    -1,     4,    -1,     4,    -1,
      42,    21,     3,    20,    -1,     4,    23,    44,    22,    -1,
       4,    23,    22,    -1,     1,    22,    -1,    45,    13,    44,
      -1,    45,    -1,    38,    42,    -1,    15,    49,    47,    16,
      -1,     1,    16,    -1,     1,    22,    -1,    48,    47,    -1,
      -1,    53,    14,    -1,     1,    14,    -1,    46,    -1,     6,
      53,    14,    -1,     7,    23,    53,    22,    48,    -1,     7,
      23,    53,    22,    48,    32,    48,    -1,     8,    23,    53,
      22,    48,    -1,    50,    49,    -1,    -1,    38,    51,    14,
      -1,    52,    -1,    52,    13,    51,    -1,    42,    -1,    42,
      17,    53,    -1,    53,    17,    53,    -1,    53,    30,    53,
      -1,    53,    29,    53,    -1,    53,    28,    53,    -1,    53,
      27,    53,    -1,    53,    26,    53,    -1,    53,    25,    53,
      -1,    53,    24,    53,    -1,    23,    53,    22,    -1,    26,
      53,    -1,    18,    53,    -1,     4,    23,    54,    22,    -1,
       4,    23,    22,    -1,    53,    21,    53,    20,    -1,    53,
      19,     4,    -1,     4,    -1,     3,    -1,     5,    -1,    11,
      -1,    12,    -1,     1,    22,    -1,     1,    20,    -1,    53,
      13,    54,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    40,    45,    48,    55,    61,    67,    75,
      79,    87,    94,    99,   111,   118,   125,   128,   136,   143,
     155,   167,   178,   180,   187,   192,   198,   207,   209,   211,
     216,   219,   225,   226,   230,   238,   249,   263,   275,   282,
     285,   293,   297,   305,   309,   317,   324,   331,   338,   344,
     351,   358,   365,   372,   380,   386,   393,   406,   418,   428,
     438,   446,   453,   460,   467,   473,   474,   476,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "FLOAT", "RETURN", "IF",
  "WHILE", "TYPE", "STRUCT", "OCT", "HEX", "COMMA", "SEMI", "LC", "RC",
  "ASSIGN", "NOT", "DOT", "RB", "LB", "RP", "LP", "DIV", "STAR", "MINUS",
  "PLUS", "RELOP", "OR", "AND", "LOWER_THAN_ELSE", "ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    42,    42,
      43,    43,    43,    44,    44,    45,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     1,
       3,     1,     1,     5,     2,     1,     0,     1,     1,     4,
       4,     3,     2,     3,     1,     2,     4,     2,     2,     2,
       0,     2,     2,     1,     3,     5,     7,     5,     2,     0,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     1,     1,     2,     2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    11,    16,     0,     2,     4,     0,    12,    17,     0,
      14,     1,     3,     0,    18,     6,     0,     9,     0,    39,
      22,     0,     5,     0,     0,     0,     8,    39,     7,     0,
       0,    39,    21,     0,     0,    24,    18,    10,     0,    27,
      28,     0,    43,     0,    41,    13,    38,    25,    20,     0,
      19,     0,    61,    60,    62,     0,     0,     0,    63,    64,
       0,     0,     0,    33,     0,     0,     0,     0,    40,     0,
      23,    32,    66,    28,     0,     0,     0,     0,     0,    55,
       0,    54,    26,    29,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    42,    57,    68,     0,
      65,    34,     0,     0,    53,    45,    59,     0,    52,    51,
      50,    49,    48,    47,    46,     0,    56,     0,     0,    58,
      67,    35,    37,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    29,     7,     9,    10,    17,
      18,    34,    35,    63,    64,    65,    30,    31,    43,    44,
      66,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
      85,   -56,    24,    11,   -56,    85,    17,   -56,    26,    33,
     -56,   -56,   -56,   -18,    30,   -56,    44,   -11,     0,    85,
     -56,     7,   -56,    52,    58,     4,   -56,    85,   -56,    52,
      57,    85,   -56,    52,    55,    66,   -56,   -56,    65,   -56,
     -56,    39,    42,    78,    90,   -56,   -56,    83,   -56,    85,
     -56,    94,   -56,    86,   -56,    95,    89,    97,   -56,   -56,
      95,    95,    95,   -56,   114,    39,   115,    95,   -56,    52,
     -56,   -56,   -56,   149,    79,     5,   132,    95,    95,   219,
     163,   -56,   -56,   -56,   -56,    95,   127,    95,    95,    95,
      95,    95,    95,    95,    95,   219,   -56,   -56,    98,   111,
     -56,   -56,   177,   191,   -56,   219,   -56,   205,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,    95,   -56,    63,    63,   -56,
     -56,   103,   -56,    63,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   133,   -56,   124,     3,   -56,   -56,   -56,   -20,
     -56,    88,   -56,   130,    87,   -30,    45,   -56,    81,   -56,
     -55,    40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int8 yytable[] =
{
      76,    25,    23,     6,    20,    79,    80,    81,     6,    42,
      24,    11,    95,    47,    26,    27,     1,     2,    13,    98,
      39,    14,   102,   103,    33,    72,    40,   100,     8,    32,
     105,    15,   107,   108,   109,   110,   111,   112,   113,   114,
      51,   -15,    52,    53,    54,    55,    56,    57,    19,    42,
      58,    59,    33,    21,    27,   -30,    36,    60,    22,    67,
      98,    38,    61,    24,    51,    62,    52,    53,    54,    55,
      56,    57,    41,    45,    58,    59,    46,    48,    27,    49,
      75,    60,    52,    53,    54,    50,    61,   121,   122,    62,
      58,    59,    68,   124,     1,     2,    75,    60,    52,    53,
      54,    97,    61,    69,    24,    62,    58,    59,    71,    74,
      39,   115,    77,    60,    72,    85,    73,    86,    61,    87,
      78,    62,    88,    89,    90,    91,    92,    93,    94,    84,
      82,   106,    85,   116,    86,   123,    87,    70,    12,    88,
      89,    90,    91,    92,    93,    94,   101,    37,    28,    85,
      96,    86,    83,    87,     0,   120,    88,    89,    90,    91,
      92,    93,    94,   -65,     0,     0,   -65,     0,   -65,     0,
     -65,     0,     0,   -65,   -65,     0,   -65,   -65,   -65,   -65,
      85,     0,    86,     0,    87,   104,     0,    88,    89,    90,
      91,    92,    93,    94,    85,     0,    86,     0,    87,   117,
       0,    88,    89,    90,    91,    92,    93,    94,    85,     0,
      86,     0,    87,   118,     0,    88,    89,    90,    91,    92,
      93,    94,    85,     0,    86,   119,    87,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    85,     0,    86,     0,
      87,     0,     0,    88,    89,    90,    91,    92,    93,    94
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      55,     1,    13,     0,    22,    60,    61,    62,     5,    29,
      21,     0,    67,    33,    14,    15,     9,    10,     1,    74,
      16,     4,    77,    78,    21,    20,    22,    22,     4,    22,
      85,    14,    87,    88,    89,    90,    91,    92,    93,    94,
       1,    15,     3,     4,     5,     6,     7,     8,    15,    69,
      11,    12,    49,    23,    15,    16,     4,    18,    14,    17,
     115,     3,    23,    21,     1,    26,     3,     4,     5,     6,
       7,     8,    27,    16,    11,    12,    31,    22,    15,    13,
       1,    18,     3,     4,     5,    20,    23,   117,   118,    26,
      11,    12,    14,   123,     9,    10,     1,    18,     3,     4,
       5,    22,    23,    13,    21,    26,    11,    12,    14,    23,
      16,    13,    23,    18,    20,    17,    22,    19,    23,    21,
      23,    26,    24,    25,    26,    27,    28,    29,    30,    14,
      16,     4,    17,    22,    19,    32,    21,    49,     5,    24,
      25,    26,    27,    28,    29,    30,    14,    23,    18,    17,
      69,    19,    65,    21,    -1,   115,    24,    25,    26,    27,
      28,    29,    30,    14,    -1,    -1,    17,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    -1,    27,    28,    29,    30,
      17,    -1,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    17,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    17,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    17,    -1,    19,    20,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    17,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    34,    35,    36,    38,    39,     4,    40,
      41,     0,    35,     1,     4,    14,    37,    42,    43,    15,
      22,    23,    14,    13,    21,     1,    14,    15,    46,    38,
      49,    50,    22,    38,    44,    45,     4,    37,     3,    16,
      22,    49,    42,    51,    52,    16,    49,    42,    22,    13,
      20,     1,     3,     4,     5,     6,     7,     8,    11,    12,
      18,    23,    26,    46,    47,    48,    53,    17,    14,    13,
      44,    14,    20,    22,    23,     1,    53,    23,    23,    53,
      53,    53,    16,    47,    14,    17,    19,    21,    24,    25,
      26,    27,    28,    29,    30,    53,    51,    22,    53,    54,
      22,    14,    53,    53,    22,    53,     4,    53,    53,    53,
      53,    53,    53,    53,    53,    13,    22,    22,    22,    20,
      54,    48,    48,    32,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
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
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 30 "syntax.y"
    {
							(yyval.no) = construct("Program", (yyloc).first_line, 0);
                					add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
							root = (yyval.no);
							if(flex_error == 0 && bison_error == 0) //print_tree(root, 0);
							//yuyifenxi(root);
							translate(root);
							
						}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 40 "syntax.y"
    {
							(yyval.no) = construct("ExtDefList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 45 "syntax.y"
    {	(yyval.no) = NULL;
						}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 48 "syntax.y"
    {
							(yyvsp[(3) - (3)].no) = construct("SEMI", (yylsp[(3) - (3)]).first_line, 0);
							(yyval.no) = construct("ExtDef", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));				
						}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 55 "syntax.y"
    {
							(yyvsp[(2) - (2)].no) = construct("SEMI", (yylsp[(2) - (2)]).first_line, 0);
							(yyval.no) = construct("ExtDef", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 61 "syntax.y"
    {
							(yyval.no) = construct("ExtDef", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 67 "syntax.y"
    {
							(yyvsp[(3) - (3)].no) = construct("SEMI", (yylsp[(3) - (3)]).first_line, 0);
							(yyval.no) = construct("ExtDef", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 75 "syntax.y"
    {
							(yyval.no) = construct("ExtDecList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 79 "syntax.y"
    {
							(yyval.no) = construct("ExtDecList", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("COMMA", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 87 "syntax.y"
    {
							(yyvsp[(1) - (1)].no) = construct("TYPE",(yylsp[(1) - (1)]).first_line,4);							
							(yyval.no) = construct("Specifier", (yyloc).first_line, 0);
							memset((yyvsp[(1) - (1)].no)->val.type_Type, 0, 20);
							memcpy((yyvsp[(1) - (1)].no)->val.type_Type, yylval.no->val.type_Type,20);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 94 "syntax.y"
    {
							(yyval.no) = construct("Specifier", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 99 "syntax.y"
    {	//printf("halaha\n");
							(yyvsp[(1) - (5)].no) = construct("STRUCT", (yylsp[(1) - (5)]).first_line, 0);
							(yyvsp[(3) - (5)].no) = construct("LC", (yylsp[(3) - (5)]).first_line, 0);
							(yyvsp[(5) - (5)].no) = construct("RC", (yylsp[(5) - (5)]).first_line, 0);
							(yyval.no) = construct("StructSpecifier", (yyloc).first_line, 0);
							//printf("lalaha\n");
							add_child(&(yyval.no), (yyvsp[(1) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(5) - (5)].no));
						}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 111 "syntax.y"
    {
							(yyval.no) = construct("StructSpecifier", (yyloc).first_line, 0);
							(yyvsp[(1) - (2)].no) = construct("STRUCT", (yylsp[(1) - (2)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 118 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							(yyval.no) = construct("OptTag", (yyloc).first_line, 0);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 125 "syntax.y"
    {	(yyval.no) = NULL;
						}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 128 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							(yyval.no) = construct("Tag", (yyloc).first_line, 0);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 136 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							(yyval.no) = construct("VarDec", (yyloc).first_line, 0);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 143 "syntax.y"
    {
							(yyval.no) = construct("VarDec", (yyloc).first_line, 0);
							(yyvsp[(2) - (4)].no) = construct("LB", (yylsp[(2) - (4)]).first_line, 0);
							(yyvsp[(4) - (4)].no) = construct("RB", (yylsp[(4) - (4)]).first_line, 0);
							(yyvsp[(3) - (4)].no) = construct("INT", (yylsp[(3) - (4)]).first_line, 1);
							(yyvsp[(3) - (4)].no)->val.type_int = yylval.no->val.type_int;
							add_child(&(yyval.no), (yyvsp[(1) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (4)].no));
						}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 155 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							(yyval.no) = construct("FunDec", (yyloc).first_line, 0);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							(yyvsp[(2) - (4)].no) = construct("LP", (yylsp[(2) - (4)]).first_line, 0);
							(yyvsp[(4) - (4)].no) = construct("RP", (yylsp[(4) - (4)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (4)].no));
						}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 167 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							(yyval.no) = construct("FunDec", (yyloc).first_line, 0);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							(yyvsp[(2) - (3)].no) = construct("LP", (yylsp[(2) - (3)]).first_line, 0);
							(yyvsp[(3) - (3)].no) = construct("RP", (yylsp[(3) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 180 "syntax.y"
    {
							(yyval.no) = construct("VarList", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("COMMA", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 187 "syntax.y"
    {
							(yyval.no) = construct("VarList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 192 "syntax.y"
    {
							(yyval.no) = construct("ParamDec", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 198 "syntax.y"
    {
							(yyvsp[(1) - (4)].no) = construct("LC", (yylsp[(1) - (4)]).first_line, 0);
							(yyvsp[(4) - (4)].no) = construct("RC", (yylsp[(4) - (4)]).first_line, 0);
							(yyval.no) = construct("CompSt", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (4)].no));
						}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 211 "syntax.y"
    {
							(yyval.no) = construct("StmtList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 216 "syntax.y"
    {	(yyval.no) = NULL;
						}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 219 "syntax.y"
    {
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							(yyvsp[(2) - (2)].no) = construct("SEMI", (yylsp[(2) - (2)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
             					}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 226 "syntax.y"
    {
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));	
						}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 230 "syntax.y"
    {
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							(yyvsp[(1) - (3)].no) = construct("RETURN", (yylsp[(1) - (3)]).first_line, 0);
							(yyvsp[(3) - (3)].no) = construct("SEMI", (yylsp[(3) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 238 "syntax.y"
    {
							(yyvsp[(1) - (5)].no) = construct("IF", (yylsp[(1) - (5)]).first_line, 0);
							(yyvsp[(2) - (5)].no) = construct("LP", (yylsp[(2) - (5)]).first_line, 0);
							(yyvsp[(4) - (5)].no) = construct("RP", (yylsp[(4) - (5)]).first_line, 0);
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(5) - (5)].no));
						}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 249 "syntax.y"
    {
							(yyvsp[(1) - (7)].no) = construct("IF", (yylsp[(1) - (7)]).first_line, 0);
							(yyvsp[(2) - (7)].no) = construct("LP", (yylsp[(2) - (7)]).first_line, 0);
							(yyvsp[(4) - (7)].no) = construct("RP", (yylsp[(4) - (7)]).first_line, 0);
							(yyvsp[(6) - (7)].no) = construct("ELSE", (yylsp[(6) - (7)]).first_line, 0);
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(5) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(6) - (7)].no));
							add_child(&(yyval.no), (yyvsp[(7) - (7)].no));
						}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 263 "syntax.y"
    {
							(yyvsp[(1) - (5)].no) = construct("WHILE", (yylsp[(1) - (5)]).first_line, 0);
							(yyvsp[(2) - (5)].no) = construct("LP", (yylsp[(2) - (5)]).first_line, 0);
							(yyvsp[(4) - (5)].no) = construct("RP", (yylsp[(4) - (5)]).first_line, 0);
							(yyval.no) = construct("Stmt", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (5)].no));
							add_child(&(yyval.no), (yyvsp[(5) - (5)].no));
						}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 275 "syntax.y"
    {
							(yyval.no) = construct("DefList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							//printf("lalaha\n");
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
							//printf("lalaha\n");
						}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 282 "syntax.y"
    {	(yyval.no) = NULL;
						}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 285 "syntax.y"
    {
							(yyval.no) = construct("Def", (yyloc).first_line, 0);
							(yyvsp[(3) - (3)].no) = construct("SEMI", (yylsp[(3) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 293 "syntax.y"
    {
							(yyval.no) = construct("DecList", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 297 "syntax.y"
    {
							(yyval.no) = construct("DecList", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("COMMA", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 305 "syntax.y"
    {
							(yyval.no) = construct("Dec", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 309 "syntax.y"
    {
							(yyval.no) = construct("Dec", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("ASSIGN", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 317 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("ASSIGN", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 324 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("AND", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 331 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("OR", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 338 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 344 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("PLUS", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 351 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("MINUS", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 358 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("STAR", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 365 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("DIV", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 372 "syntax.y"
    {
							(yyvsp[(1) - (3)].no) = construct("LP", (yylsp[(1) - (3)]).first_line, 0);
							(yyvsp[(3) - (3)].no) = construct("RP", (yylsp[(3) - (3)]).first_line, 0);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 380 "syntax.y"
    {
							(yyvsp[(1) - (2)].no) = construct("MINUS", (yylsp[(1) - (2)]).first_line, 0);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 386 "syntax.y"
    {
							(yyvsp[(1) - (2)].no) = construct("NOT", (yylsp[(1) - (2)]).first_line, 0);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							add_child(&(yyval.no), (yyvsp[(1) - (2)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (2)].no));
						}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 393 "syntax.y"
    {// han shu diao yong
							//$1 = construct("ID", @1.first_line, 3);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							(yyvsp[(2) - (4)].no) = construct("LP", (yylsp[(2) - (4)]).first_line, 0);
							(yyvsp[(4) - (4)].no) = construct("RP", (yylsp[(4) - (4)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (4)].no));
						}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 406 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							(yyvsp[(2) - (3)].no) = construct("LP", (yylsp[(2) - (3)]).first_line, 0);
							(yyvsp[(3) - (3)].no) = construct("RP", (yylsp[(3) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 418 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (4)].no) = construct("LB", (yylsp[(2) - (4)]).first_line, 0);
							(yyvsp[(4) - (4)].no) = construct("RB", (yylsp[(4) - (4)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (4)].no));
							add_child(&(yyval.no), (yyvsp[(4) - (4)].no));
		
						}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 428 "syntax.y"
    {
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("DOT", (yylsp[(2) - (3)]).first_line, 0);
							//$3 = construct("ID", @3.first_line, 3);
							//memset($3->val.type_ID, 0, 20);
							//memcpy($3->val.type_ID, yylval.no->val.type_ID,20);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 438 "syntax.y"
    {
							//$1 = construct("ID", @1.first_line, 3);
							//memset($1->val.type_ID, 0, 20);
							//memcpy($1->val.type_ID, yylval.no->val.type_ID,20);
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
					
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 446 "syntax.y"
    {
							(yyvsp[(1) - (1)].no) = construct("INT", (yylsp[(1) - (1)]).first_line, 1);
							(yyvsp[(1) - (1)].no)->val.type_int = yylval.no->val.type_int;
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 453 "syntax.y"
    {
							(yyvsp[(1) - (1)].no) = construct("FLOAT", (yylsp[(1) - (1)]).first_line, 2);
							(yyvsp[(1) - (1)].no)->val.type_float = yylval.no->val.type_float;
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 460 "syntax.y"
    {
							(yyvsp[(1) - (1)].no) = construct("INT", (yylsp[(1) - (1)]).first_line, 1);
							(yyvsp[(1) - (1)].no)->val.type_int = yylval.no->val.type_int;
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 467 "syntax.y"
    {	(yyvsp[(1) - (1)].no) = construct("INT", (yylsp[(1) - (1)]).first_line, 1);
							(yyvsp[(1) - (1)].no)->val.type_int = yylval.no->val.type_int;
							(yyval.no) = construct("Exp", (yyloc).first_line, 0);
							
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 476 "syntax.y"
    {
							(yyval.no) = construct("Args", (yyloc).first_line, 0);
							(yyvsp[(2) - (3)].no) = construct("COMMA", (yylsp[(2) - (3)]).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(2) - (3)].no));
							add_child(&(yyval.no), (yyvsp[(3) - (3)].no));
						}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 483 "syntax.y"
    {
							(yyval.no) = construct("Args", (yyloc).first_line, 0);
							add_child(&(yyval.no), (yyvsp[(1) - (1)].no));
						}
    break;


/* Line 1787 of yacc.c  */
#line 2368 "syntax.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 488 "syntax.y"

yyerror(char* msg) {
	printf("Error type B at line %d: %s \n", yylineno, msg);
	bison_error = 1;
}
