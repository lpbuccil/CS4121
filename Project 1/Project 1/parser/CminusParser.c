/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse Cminus_parse
#define yylex   Cminus_lex
#define yyerror Cminus_error
#define yylval  Cminus_lval
#define yychar  Cminus_char
#define yydebug Cminus_debug
#define yynerrs Cminus_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ELSE = 259,
     EXIT = 260,
     FOR = 261,
     IF = 262,
     INTEGER = 263,
     NOT = 264,
     OR = 265,
     READ = 266,
     WHILE = 267,
     WRITE = 268,
     LBRACE = 269,
     RBRACE = 270,
     LE = 271,
     LT = 272,
     GE = 273,
     GT = 274,
     EQ = 275,
     NE = 276,
     ASSIGN = 277,
     COMMA = 278,
     SEMICOLON = 279,
     LBRACKET = 280,
     RBRACKET = 281,
     LPAREN = 282,
     RPAREN = 283,
     PLUS = 284,
     TIMES = 285,
     IDENTIFIER = 286,
     DIVIDE = 287,
     RETURN = 288,
     STRING = 289,
     INTCON = 290,
     MINUS = 291,
     DIVDE = 292
   };
#endif
/* Tokens.  */
#define AND 258
#define ELSE 259
#define EXIT 260
#define FOR 261
#define IF 262
#define INTEGER 263
#define NOT 264
#define OR 265
#define READ 266
#define WHILE 267
#define WRITE 268
#define LBRACE 269
#define RBRACE 270
#define LE 271
#define LT 272
#define GE 273
#define GT 274
#define EQ 275
#define NE 276
#define ASSIGN 277
#define COMMA 278
#define SEMICOLON 279
#define LBRACKET 280
#define RBRACKET 281
#define LPAREN 282
#define RPAREN 283
#define PLUS 284
#define TIMES 285
#define IDENTIFIER 286
#define DIVIDE 287
#define RETURN 288
#define STRING 289
#define INTCON 290
#define MINUS 291
#define DIVDE 292




/* Copy the first part of user declarations.  */
#line 7 "CminusParser.y"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include <util/string_utils.h>
#include <unistd.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(const char*));

EXTERN(int,Cminus_lex,(void));

char *fileName;

SymTable symtab;

extern int Cminus_lineno;

extern FILE *Cminus_in;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 86 "CminusParser.y"
{
	char* name;
	int symIndex;
	int ivalue;
	char* svalue;
}
/* Line 193 of yacc.c.  */
#line 215 "CminusParser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 228 "CminusParser.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    12,    15,    18,    20,
      26,    29,    33,    38,    40,    44,    46,    51,    53,    55,
      57,    59,    61,    63,    65,    67,    72,    77,    80,    83,
      87,    91,    95,    97,   103,   109,   115,   119,   122,   126,
     128,   131,   133,   137,   141,   144,   146,   150,   154,   158,
     162,   166,   170,   172,   176,   180,   182,   186,   190,   192,
     194,   198,   202,   204,   209,   211
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    45,    40,    -1,    41,    40,
      -1,    -1,    42,    44,    -1,    43,    45,    -1,    43,    -1,
      48,    31,    27,    28,    14,    -1,    61,    15,    -1,    48,
      46,    24,    -1,    45,    48,    46,    24,    -1,    47,    -1,
      46,    23,    47,    -1,    31,    -1,    31,    25,    35,    26,
      -1,     8,    -1,    50,    -1,    51,    -1,    54,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    67,    22,    62,
      24,    -1,     7,    52,     4,    60,    -1,     7,    52,    -1,
      53,    60,    -1,    27,    62,    28,    -1,    56,    55,    49,
      -1,    27,    62,    28,    -1,    12,    -1,    11,    27,    67,
      28,    24,    -1,    13,    27,    62,    28,    24,    -1,    13,
      27,    68,    28,    24,    -1,    33,    62,    24,    -1,     5,
      24,    -1,    14,    61,    15,    -1,    49,    -1,    61,    49,
      -1,    63,    -1,    62,    10,    63,    -1,    62,     3,    63,
      -1,     9,    63,    -1,    64,    -1,    63,    20,    64,    -1,
      63,    21,    64,    -1,    63,    16,    64,    -1,    63,    17,
      64,    -1,    63,    18,    64,    -1,    63,    19,    64,    -1,
      65,    -1,    64,    29,    65,    -1,    64,    36,    65,    -1,
      66,    -1,    65,    30,    66,    -1,    65,    32,    66,    -1,
      67,    -1,    69,    -1,    31,    27,    28,    -1,    27,    62,
      28,    -1,    31,    -1,    31,    25,    62,    26,    -1,    34,
      -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   104,   110,   115,   120,   126,   130,   136,
     142,   149,   153,   160,   166,   172,   176,   182,   188,   192,
     196,   200,   204,   208,   212,   218,   225,   229,   236,   242,
     249,   255,   261,   268,   276,   281,   288,   295,   301,   307,
     311,   317,   322,   327,   332,   339,   344,   349,   354,   359,
     364,   369,   376,   381,   387,   394,   399,   405,   413,   418,
     423,   427,   434,   440,   446,   453
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ELSE", "EXIT", "FOR", "IF",
  "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE", "RBRACE",
  "LE", "LT", "GE", "GT", "EQ", "NE", "ASSIGN", "COMMA", "SEMICOLON",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES",
  "IDENTIFIER", "DIVIDE", "RETURN", "STRING", "INTCON", "MINUS", "DIVDE",
  "$accept", "Program", "Procedures", "ProcedureDecl", "ProcedureHead",
  "FunctionDecl", "ProcedureBody", "DeclList", "IdentifierList", "VarDecl",
  "Type", "Statement", "Assignment", "IfStatement", "TestAndThen", "Test",
  "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "ReturnStatement", "ExitStatement", "CompoundStatement", "StatementList",
  "Expr", "SimpleExpr", "AddExpr", "MulExpr", "Factor", "Variable",
  "StringConstant", "Constant", 0
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    42,    42,    43,
      44,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      49,    49,    49,    49,    49,    50,    51,    51,    52,    53,
      54,    55,    56,    57,    57,    57,    58,    59,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    68,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     2,     2,     1,     5,
       2,     3,     4,     1,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     2,     3,
       3,     3,     1,     5,     5,     5,     3,     2,     3,     1,
       2,     1,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     1,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    17,     0,     2,     5,     0,     8,     5,     0,     1,
       4,     0,     0,     0,     0,    32,     0,     0,    62,     0,
       6,    39,    18,    19,    20,     0,    21,    22,    23,    24,
       0,     0,     7,     0,     3,     0,    15,     0,    13,     0,
      37,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      62,    65,     0,    41,    45,    52,    55,    58,    59,     0,
       0,    10,    40,     0,     0,    15,     0,     0,     0,     0,
      11,     0,     0,    28,     0,    64,     0,     0,    38,     0,
      44,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    12,
       0,     0,    14,    29,    26,     0,     0,     0,    63,    61,
      60,    43,    42,    48,    49,    50,    51,    46,    47,    53,
      54,    56,    57,    31,    25,    16,     9,    33,    34,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    20,     7,    37,    38,
       8,    21,    22,    23,    42,    43,    24,    60,    25,    26,
      27,    28,    29,    30,    52,    53,    54,    55,    56,    57,
      77,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
      30,   -65,    11,   -65,    30,    49,    30,    30,   -14,   -65,
     -65,    36,   -21,    20,    60,   -65,    64,    49,   100,    37,
     -65,   -65,   -65,   -65,   -65,    72,   -65,   -65,   -65,   -65,
       9,   104,    30,    76,   -65,   -14,    32,    52,   -65,   101,
     -65,    37,   123,   115,    99,    39,    38,    37,    66,    37,
      54,   -65,    85,    95,   -23,    68,   -65,   -65,   -65,    37,
      49,   -65,   -65,    37,    76,   106,    82,    97,   105,    76,
     -65,    16,   115,   -65,   107,   -65,    55,   108,   -65,     5,
      95,    74,   109,    66,    66,   -65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    75,   -65,    86,   -65,
     112,   120,   -65,   -65,   -65,   116,   117,   118,   -65,   -65,
     -65,    95,    95,   -23,   -23,   -23,   -23,   -23,   -23,    68,
      68,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,    23,   -65,   -65,   -65,   -65,   133,   -31,    77,
       3,   -28,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -38,   126,    45,   -47,    31,   -64,    29,    -5,
     -65,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    80,    62,    40,    66,    73,    92,    11,    83,    33,
      35,     9,    31,    93,    12,    84,    13,    36,    62,    83,
      14,    15,    16,    17,    61,    31,    84,    10,   119,   120,
      34,   108,    97,    66,   104,    64,   111,   112,     1,    74,
      18,    31,    19,    12,   103,    13,    48,    41,    48,    14,
      15,    16,    17,    78,    12,    31,    13,    67,    83,    68,
      14,    15,    16,    17,    49,    84,    49,    39,    50,    18,
      50,    19,    51,    75,    51,    69,    70,    83,    83,    47,
      18,    82,    19,   106,    84,    84,    71,    44,    83,    83,
      76,    45,    79,    49,    81,    84,    84,    50,    94,    59,
      95,    51,   109,   123,    96,    69,    99,    65,    98,    85,
     124,    86,    87,    88,    89,    90,    91,   113,   114,   115,
     116,   117,   118,   121,   122,    47,    63,    72,    68,    17,
      18,    67,   100,   101,   126,   105,   107,   110,   125,    32,
     127,   128,   129,    46,     0,     0,   102
};

static const yytype_int8 yycheck[] =
{
       5,    48,    30,    24,    35,    43,    29,     4,     3,     6,
       7,     0,    17,    36,     5,    10,     7,    31,    46,     3,
      11,    12,    13,    14,    15,    30,    10,     4,    92,    93,
       7,    26,    60,    64,    72,    32,    83,    84,     8,    44,
      31,    46,    33,     5,    28,     7,     9,    27,     9,    11,
      12,    13,    14,    15,     5,    60,     7,    25,     3,    27,
      11,    12,    13,    14,    27,    10,    27,    31,    31,    31,
      31,    33,    35,    34,    35,    23,    24,     3,     3,    25,
      31,    27,    33,    28,    10,    10,    41,    27,     3,     3,
      45,    27,    47,    27,    49,    10,    10,    31,    30,    27,
      32,    35,    28,    28,    59,    23,    24,    31,    63,    24,
      24,    16,    17,    18,    19,    20,    21,    86,    87,    88,
      89,    90,    91,    94,    95,    25,    22,     4,    27,    14,
      31,    25,    35,    28,    14,    28,    28,    28,    26,     6,
      24,    24,    24,    17,    -1,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    39,    40,    41,    42,    43,    45,    48,     0,
      40,    48,     5,     7,    11,    12,    13,    14,    31,    33,
      44,    49,    50,    51,    54,    56,    57,    58,    59,    60,
      61,    67,    45,    48,    40,    48,    31,    46,    47,    31,
      24,    27,    52,    53,    27,    27,    61,    25,     9,    27,
      31,    35,    62,    63,    64,    65,    66,    67,    69,    27,
      55,    15,    49,    22,    48,    31,    46,    25,    27,    23,
      24,    62,     4,    60,    67,    34,    62,    68,    15,    62,
      63,    62,    27,     3,    10,    24,    16,    17,    18,    19,
      20,    21,    29,    36,    30,    32,    62,    49,    62,    24,
      35,    28,    47,    28,    60,    28,    28,    28,    26,    28,
      28,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    28,    24,    26,    14,    24,    24,    24
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "CminusParser.y"
    {
			//printf("<Program> -> <Procedures>\n");
		;}
    break;

  case 3:
#line 105 "CminusParser.y"
    {
			//printf("<Program> -> <DeclList> <Procedures>\n");
		;}
    break;

  case 4:
#line 111 "CminusParser.y"
    {
			//printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		;}
    break;

  case 5:
#line 115 "CminusParser.y"
    {
			//printf("<Procedures> -> epsilon\n");
		;}
    break;

  case 6:
#line 121 "CminusParser.y"
    {
			//printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		;}
    break;

  case 7:
#line 127 "CminusParser.y"
    {
			//printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		;}
    break;

  case 8:
#line 131 "CminusParser.y"
    {
			//printf("<ProcedureHead> -> <FunctionDecl>\n");
		;}
    break;

  case 9:
#line 137 "CminusParser.y"
    {
			//printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
		;}
    break;

  case 10:
#line 143 "CminusParser.y"
    {
			//printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		;}
    break;

  case 11:
#line 150 "CminusParser.y"
    {
			//printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
		;}
    break;

  case 12:
#line 154 "CminusParser.y"
    {
			//printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	;}
    break;

  case 13:
#line 161 "CminusParser.y"
    {
			//printf("<IdentifierList> -> <VarDecl>\n");
			
		;}
    break;

  case 14:
#line 167 "CminusParser.y"
    {
			//printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		;}
    break;

  case 15:
#line 173 "CminusParser.y"
    { 
			//printf("<VarDecl> -> <IDENTIFIER>\n");
		;}
    break;

  case 16:
#line 177 "CminusParser.y"
    {
			//printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		;}
    break;

  case 17:
#line 183 "CminusParser.y"
    { 
			//printf("<Type> -> <INTEGER>\n");
		;}
    break;

  case 18:
#line 189 "CminusParser.y"
    { 
			//printf("<Statement> -> <Assignment>\n");
		;}
    break;

  case 19:
#line 193 "CminusParser.y"
    { 
			//printf("<Statement> -> <IfStatement>\n");
		;}
    break;

  case 20:
#line 197 "CminusParser.y"
    { 
			//printf("<Statement> -> <WhileStatement>\n");
		;}
    break;

  case 21:
#line 201 "CminusParser.y"
    { 
			//printf("<Statement> -> <IOStatement>\n");
		;}
    break;

  case 22:
#line 205 "CminusParser.y"
    { 
			//printf("<Statement> -> <ReturnStatement>\n");
		;}
    break;

  case 23:
#line 209 "CminusParser.y"
    { 
			//printf("<Statement> -> <ExitStatement>\n");
		;}
    break;

  case 24:
#line 213 "CminusParser.y"
    { 
			//printf("<Statement> -> <CompoundStatement>\n");
		;}
    break;

  case 25:
#line 219 "CminusParser.y"
    {
			//store the value in symtable at the index given by variable
			SymPutFieldByIndex(symtab, (yyvsp[(1) - (4)].symIndex), SYMTAB_VALUE_FIELD, (Generic) (yyvsp[(3) - (4)].ivalue));
		;}
    break;

  case 26:
#line 226 "CminusParser.y"
    {
			//printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		;}
    break;

  case 27:
#line 230 "CminusParser.y"
    {
			//printf("<IfStatement> -> <IF> <TestAndThen>\n");
		;}
    break;

  case 28:
#line 237 "CminusParser.y"
    {
			//printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		;}
    break;

  case 29:
#line 243 "CminusParser.y"
    {
			//printf("<Test> -> <LP> <Expr> <RP>\n");
		;}
    break;

  case 30:
#line 250 "CminusParser.y"
    {
			//printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		;}
    break;

  case 31:
#line 256 "CminusParser.y"
    {
			//printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
		;}
    break;

  case 32:
#line 262 "CminusParser.y"
    {
			//printf("<WhileToken> -> <WHILE>\n");
		;}
    break;

  case 33:
#line 269 "CminusParser.y"
    {
			//read in a value and store it into the symtable from the variables index
			char temp[100];
			memset(temp, 0, sizeof(temp));
			read(0, temp, sizeof(temp));
			SymPutFieldByIndex(symtab, (yyvsp[(3) - (5)].symIndex), SYMTAB_VALUE_FIELD, (Generic) atoi(temp));
		;}
    break;

  case 34:
#line 277 "CminusParser.y"
    {
			//printf("<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>\n");
			printf("%d\n", (yyvsp[(3) - (5)].ivalue));
		;}
    break;

  case 35:
#line 282 "CminusParser.y"
    {
			//printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
			printf("%s\n", (yyvsp[(3) - (5)].svalue));
		;}
    break;

  case 36:
#line 289 "CminusParser.y"
    {
			//printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
			(yyval.ivalue) = (yyvsp[(2) - (3)].ivalue);
		;}
    break;

  case 37:
#line 296 "CminusParser.y"
    {
			//printf("<ExitStatement> -> <EXIT> <SC>\n");
		;}
    break;

  case 38:
#line 302 "CminusParser.y"
    {
			//printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		;}
    break;

  case 39:
#line 308 "CminusParser.y"
    {		
			//printf("<StatementList> -> <Statement>\n");
		;}
    break;

  case 40:
#line 312 "CminusParser.y"
    {		
			//printf("<StatementList> -> <StatementList> <Statement>\n");
		;}
    break;

  case 41:
#line 318 "CminusParser.y"
    {
			//printf("<Expr> -> <SimpleExpr>\n");
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;

  case 42:
#line 323 "CminusParser.y"
    {
			//printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) | (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 43:
#line 328 "CminusParser.y"
    {
			//printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) && (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 44:
#line 333 "CminusParser.y"
    {
			//printf("<Expr> -> <NOT> <SimpleExpr> \n");
			(yyval.ivalue) = (!(yyvsp[(2) - (2)].ivalue));
		;}
    break;

  case 45:
#line 340 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <AddExpr>\n");
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;

  case 46:
#line 345 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) == (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 47:
#line 350 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) != (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 48:
#line 355 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) <= (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 49:
#line 360 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) < (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 50:
#line 365 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) >= (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 51:
#line 370 "CminusParser.y"
    {
			//printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
			(yyval.ivalue) = ((yyvsp[(1) - (3)].ivalue) > (yyvsp[(3) - (3)].ivalue));
		;}
    break;

  case 52:
#line 377 "CminusParser.y"
    {
			//printf("<AddExpr> -> <MulExpr>\n");
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;

  case 53:
#line 382 "CminusParser.y"
    {
			//printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
			//printf("%d + %d\n", $1, $3);
			(yyval.ivalue) = (yyvsp[(1) - (3)].ivalue) + (yyvsp[(3) - (3)].ivalue);
		;}
    break;

  case 54:
#line 388 "CminusParser.y"
    {
			//printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
			(yyval.ivalue) = (yyvsp[(1) - (3)].ivalue) - (yyvsp[(3) - (3)].ivalue);
		;}
    break;

  case 55:
#line 395 "CminusParser.y"
    {
			//printf("<MulExpr> -> <Factor>\n");
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;

  case 56:
#line 400 "CminusParser.y"
    {
			//printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
			//printf("%d * %d\n", $1, $3);
			(yyval.ivalue) = (yyvsp[(1) - (3)].ivalue) * (yyvsp[(3) - (3)].ivalue);
		;}
    break;

  case 57:
#line 406 "CminusParser.y"
    {
			//printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
			//printf("%d / %d\n", $1, $3);
			(yyval.ivalue) = (yyvsp[(1) - (3)].ivalue) / (yyvsp[(3) - (3)].ivalue);
		;}
    break;

  case 58:
#line 414 "CminusParser.y"
    { 
			//gets the int value from the symtable given the index from variable
			(yyval.ivalue) = (int) SymGetFieldByIndex(symtab, (yyvsp[(1) - (1)].symIndex), SYMTAB_VALUE_FIELD);
		;}
    break;

  case 59:
#line 419 "CminusParser.y"
    { 
			//since it is a constant, we have not save it to the symtable and we can just pass by value
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;

  case 60:
#line 424 "CminusParser.y"
    {	
			//printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		;}
    break;

  case 61:
#line 428 "CminusParser.y"
    {
			//printf("<Factor> -> <LP> <Expr> <RP>\n");
			(yyval.ivalue) = (yyvsp[(2) - (3)].ivalue);
		;}
    break;

  case 62:
#line 435 "CminusParser.y"
    {
			//Gets the index of the Identifier
			int index = SymIndex(symtab, (yyvsp[(1) - (1)].name));
			(yyval.symIndex) = index;
		;}
    break;

  case 63:
#line 441 "CminusParser.y"
    {
			//printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	;}
    break;

  case 64:
#line 447 "CminusParser.y"
    { 
			//returns the string
			(yyval.svalue) = (yyvsp[(1) - (1)].svalue);
		;}
    break;

  case 65:
#line 454 "CminusParser.y"
    { 
			//returns the value of the integer constant
			(yyval.ivalue) = (yyvsp[(1) - (1)].ivalue);
		;}
    break;


/* Line 1267 of yacc.c.  */
#line 2023 "CminusParser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 461 "CminusParser.y"



/********************C ROUTINES *********************************/

void Cminus_error(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap() {
	return 1;
}

static void initialize(char* inputFileName) {

	/*initalize symtab and symtab field*/
    symtab = SymInit(SYMTABLE_SIZE);
	SymInitField(symtab, SYMTAB_VALUE_FIELD, (Generic) - 1, NULL);

	Cminus_in = fopen(inputFileName,"r");
        if (Cminus_in == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }

}

static void finalize() {

    fclose(Cminus_in);
    fclose(stdout);
	/*remove symtab*/
	SymKillField(symtab, SYMTAB_VALUE_FIELD);
	SymKill(symtab);
    

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        Cminus_parse();
  
  	finalize();
  
  	return 0;
}
/******************END OF C ROUTINES**********************/

