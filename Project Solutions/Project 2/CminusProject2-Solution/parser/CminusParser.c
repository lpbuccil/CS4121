/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         Cminus_parse
#define yylex           Cminus_lex
#define yyerror         Cminus_error
#define yydebug         Cminus_debug
#define yynerrs         Cminus_nerrs

#define yylval          Cminus_lval
#define yychar          Cminus_char

/* Copy the first part of user declarations.  */
#line 7 "CminusParser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include <util/string_utils.h>
#include <codegen/symfields.h>
#include <codegen/types.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>

#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(char*));

EXTERN(int,Cminus_lex,(void));

SymTable symtab;

static DList instList;
static DList dataList;

char *fileName;

static int functionOffset;
int globalOffset = 0;
static char* functionName;

extern union YYSTYPE yylval;

extern int Cminus_lineno;


#line 114 "CminusParser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "CminusParser.h".  */
#ifndef YY_CMINUS_CMINUSPARSER_H_INCLUDED
# define YY_CMINUS_CMINUSPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Cminus_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ELSE = 259,
    EXIT = 260,
    FLOAT = 261,
    FOR = 262,
    IF = 263,
    INTEGER = 264,
    NOT = 265,
    OR = 266,
    READ = 267,
    WHILE = 268,
    WRITE = 269,
    LBRACE = 270,
    RBRACE = 271,
    LE = 272,
    LT = 273,
    GE = 274,
    GT = 275,
    EQ = 276,
    NE = 277,
    ASSIGN = 278,
    COMMA = 279,
    SEMICOLON = 280,
    LBRACKET = 281,
    RBRACKET = 282,
    LPAREN = 283,
    RPAREN = 284,
    PLUS = 285,
    TIMES = 286,
    IDENTIFIER = 287,
    DIVIDE = 288,
    RETURN = 289,
    STRING = 290,
    INTCON = 291,
    FLOATCON = 292,
    MINUS = 293,
    DIVDE = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "CminusParser.y" /* yacc.c:355  */

	char*	name;
	int     symIndex;
	DList	idList;
	int 	offset;

#line 201 "CminusParser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE Cminus_lval;

int Cminus_parse (void);

#endif /* !YY_CMINUS_CMINUSPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "CminusParser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   116,   124,   125,   128,   134,   140,   148,
     154,   158,   170,   184,   193,   201,   205,   211,   212,   215,
     216,   217,   218,   219,   220,   221,   224,   230,   231,   235,
     238,   242,   245,   248,   252,   256,   260,   266,   269,   275,
     278,   280,   284,   288,   292,   296,   302,   306,   310,   314,
     318,   322,   326,   332,   336,   340,   346,   350,   354,   360,
     364,   368,   372,   378,   386,   392,   399
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ELSE", "EXIT", "FLOAT", "FOR",
  "IF", "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE",
  "RBRACE", "LE", "LT", "GE", "GT", "EQ", "NE", "ASSIGN", "COMMA",
  "SEMICOLON", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES",
  "IDENTIFIER", "DIVIDE", "RETURN", "STRING", "INTCON", "FLOATCON",
  "MINUS", "DIVDE", "$accept", "Program", "Procedures", "ProcedureDecl",
  "ProcedureHead", "FunctionDecl", "ProcedureBody", "DeclList",
  "IdentifierList", "VarDecl", "Type", "Statement", "Assignment",
  "IfStatement", "TestAndThen", "Test", "WhileStatement", "WhileExpr",
  "WhileToken", "IOStatement", "ReturnStatement", "ExitStatement",
  "CompoundStatement", "StatementList", "Expr", "SimpleExpr", "AddExpr",
  "MulExpr", "Factor", "Variable", "StringConstant", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -49,   -49,     3,   -49,    -2,    37,    -2,    -2,   -12,
     -49,   -49,     6,    18,    46,    64,   -49,    80,    37,    52,
      34,   -49,   -49,   -49,   -49,   -49,    95,   -49,   -49,   -49,
     -49,     1,    40,    -2,    72,   -49,   -12,   -18,    76,   -49,
      98,   -49,    34,   125,   115,    99,    48,    14,    34,    66,
      34,    71,   -49,    78,    94,    35,    44,   -49,   -49,   -49,
      34,    37,   -49,   -49,    34,    72,   106,    82,    97,   105,
      72,   -49,    50,   115,   -49,   107,   -49,    56,   108,   -49,
      20,    94,    57,   109,    66,    66,   -49,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    61,   -49,    85,
     -49,   112,   120,   -49,   -49,   -49,   116,   117,   118,   -49,
     -49,   -49,    94,    94,    35,    35,    35,    35,    35,    35,
      44,    44,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    18,    17,     0,     2,     5,     0,     8,     5,     0,
       1,     4,     0,     0,     0,     0,    33,     0,     0,    63,
       0,     6,    40,    19,    20,    21,     0,    22,    23,    24,
      25,     0,     0,     7,     0,     3,     0,    15,     0,    13,
       0,    38,     0,    28,     0,     0,     0,     0,     0,     0,
       0,    63,    66,     0,    42,    46,    53,    56,    59,    60,
       0,     0,    10,    41,     0,     0,    15,     0,     0,     0,
       0,    11,     0,     0,    29,     0,    65,     0,     0,    39,
       0,    45,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      12,     0,     0,    14,    30,    27,     0,     0,     0,    64,
      62,    61,    44,    43,    49,    50,    51,    52,    47,    48,
      54,    55,    57,    58,    32,    26,    16,     9,    34,    35,
      36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,    16,   -49,   -49,   -49,   -49,   133,   -31,    74,
      49,   -29,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -33,   127,    45,   -48,    30,    31,    32,    -6,
     -49,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    21,     8,    38,    39,
       9,    22,    23,    24,    43,    44,    25,    61,    26,    27,
      28,    29,    30,    31,    53,    54,    55,    56,    57,    58,
      78,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    81,    63,    10,     1,    67,    13,     2,    68,    14,
      69,    74,    32,    15,    16,    17,    18,    62,    63,    13,
      37,    11,    14,    84,    35,    32,    15,    16,    17,    18,
      79,    85,    98,    19,    67,    20,   112,   113,    40,    75,
     105,    32,    13,    41,    49,    14,    19,   109,    20,    15,
      16,    17,    18,    84,    12,    32,    34,    36,    49,    84,
      84,    85,    50,    64,    84,    93,    51,    85,    85,    19,
      52,    20,    85,    94,    42,    95,    50,    96,    48,   104,
      51,    84,    65,    76,    52,   107,   110,    72,    84,    85,
     124,    77,    45,    80,    50,    82,    85,    48,    51,    83,
      70,    71,    52,    86,    66,    97,    70,   100,    46,    99,
     125,    87,    88,    89,    90,    91,    92,   114,   115,   116,
     117,   118,   119,    60,   120,   121,    69,   122,   123,    73,
      18,    19,    68,   101,   102,   127,   106,   108,   111,   126,
      33,   128,   129,   130,   103,    47
};

static const yytype_uint8 yycheck[] =
{
       6,    49,    31,     0,     6,    36,     5,     9,    26,     8,
      28,    44,    18,    12,    13,    14,    15,    16,    47,     5,
      32,     5,     8,     3,     8,    31,    12,    13,    14,    15,
      16,    11,    61,    32,    65,    34,    84,    85,    32,    45,
      73,    47,     5,    25,    10,     8,    32,    27,    34,    12,
      13,    14,    15,     3,     5,    61,     7,     8,    10,     3,
       3,    11,    28,    23,     3,    30,    32,    11,    11,    32,
      36,    34,    11,    38,    28,    31,    28,    33,    26,    29,
      32,     3,    33,    35,    36,    29,    29,    42,     3,    11,
      29,    46,    28,    48,    28,    50,    11,    26,    32,    28,
      24,    25,    36,    25,    32,    60,    24,    25,    28,    64,
      25,    17,    18,    19,    20,    21,    22,    87,    88,    89,
      90,    91,    92,    28,    93,    94,    28,    95,    96,     4,
      15,    32,    26,    36,    29,    15,    29,    29,    29,    27,
       7,    25,    25,    25,    70,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    41,    42,    43,    44,    45,    47,    50,
       0,    42,    50,     5,     8,    12,    13,    14,    15,    32,
      34,    46,    51,    52,    53,    56,    58,    59,    60,    61,
      62,    63,    69,    47,    50,    42,    50,    32,    48,    49,
      32,    25,    28,    54,    55,    28,    28,    63,    26,    10,
      28,    32,    36,    64,    65,    66,    67,    68,    69,    71,
      28,    57,    16,    51,    23,    50,    32,    48,    26,    28,
      24,    25,    64,     4,    62,    69,    35,    64,    70,    16,
      64,    65,    64,    28,     3,    11,    25,    17,    18,    19,
      20,    21,    22,    30,    38,    31,    33,    64,    51,    64,
      25,    36,    29,    49,    29,    62,    29,    29,    29,    27,
      29,    29,    65,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    29,    25,    27,    15,    25,    25,
      25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    44,    44,    45,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    52,    53,    53,    54,
      55,    56,    57,    58,    59,    59,    59,    60,    61,    62,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     2,     2,     1,     5,
       2,     3,     4,     1,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     2,
       3,     3,     3,     1,     5,     5,     5,     3,     2,     3,
       1,     2,     1,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     1,     4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 112 "CminusParser.y" /* yacc.c:1646  */
    {
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
#line 1394 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "CminusParser.y" /* yacc.c:1646  */
    {
			globalOffset = (yyvsp[-1].offset);
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
#line 1404 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "CminusParser.y" /* yacc.c:1646  */
    {
			emitExit(instList);
               }
#line 1412 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "CminusParser.y" /* yacc.c:1646  */
    {
			emitProcedurePrologue(instList,symtab,(yyvsp[-1].symIndex),(yyvsp[0].offset));
			functionOffset = (yyvsp[0].offset);
			(yyval.symIndex) = (yyvsp[-1].symIndex);
		}
#line 1422 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 141 "CminusParser.y" /* yacc.c:1646  */
    {
			emitProcedurePrologue(instList,symtab,(yyvsp[0].symIndex),0);
			functionOffset = 0;
			(yyval.symIndex) = (yyvsp[0].symIndex);
		}
#line 1432 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = SymIndex(symtab,(yyvsp[-3].name));
		}
#line 1440 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "CminusParser.y" /* yacc.c:1646  */
    {
			AddIdStructPtr data = (AddIdStructPtr)malloc(sizeof(AddIdStruct));
			data->offset = 0;
			data->offsetDirection = 1;
			data->symtab = symtab;
			dlinkApply1((yyvsp[-1].idList),(DLinkApply1Func)addIdToSymtab,(Generic)data);
			(yyval.offset) = data->offset;
			dlinkFreeNodes((yyvsp[-1].idList));
			
			free(data);
		}
#line 1456 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 171 "CminusParser.y" /* yacc.c:1646  */
    {
			AddIdStructPtr data = (AddIdStructPtr)malloc(sizeof(AddIdStruct));
			data->offset = (yyvsp[-3].offset);
			data->offsetDirection = 1;
			data->symtab = symtab;
			dlinkApply1((yyvsp[-1].idList),(DLinkApply1Func)addIdToSymtab,(Generic)data);
			(yyval.offset) = data->offset;
			dlinkFreeNodes((yyvsp[-1].idList));
			free(data);
	 	}
#line 1471 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.idList) = dlinkListAlloc(NULL);
			dlinkAppend((yyval.idList),dlinkNodeAlloc((Generic)(yyvsp[0].symIndex)));
			
			
			
		}
#line 1483 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 194 "CminusParser.y" /* yacc.c:1646  */
    {
			dlinkAppend((yyvsp[-2].idList),dlinkNodeAlloc((Generic)(yyvsp[0].symIndex)));
			
			(yyval.idList) = (yyvsp[-2].idList);
		}
#line 1493 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "CminusParser.y" /* yacc.c:1646  */
    { 
			(yyval.symIndex) = SymIndex(symtab,(yyvsp[0].name));
		}
#line 1501 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = SYM_INVALID_INDEX;
		}
#line 1509 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 225 "CminusParser.y" /* yacc.c:1646  */
    {
			emitAssignment(instList,symtab,(yyvsp[-3].symIndex),(yyvsp[-1].symIndex));
		}
#line 1517 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 253 "CminusParser.y" /* yacc.c:1646  */
    {
			emitReadVariable(instList,symtab,(yyvsp[-2].symIndex));
		}
#line 1525 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "CminusParser.y" /* yacc.c:1646  */
    {
			emitWriteExpression(instList,symtab,(yyvsp[-2].symIndex),SYSCALL_PRINT_INTEGER);
		}
#line 1533 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "CminusParser.y" /* yacc.c:1646  */
    {
			emitWriteExpression(instList,symtab,(yyvsp[-2].symIndex),SYSCALL_PRINT_STRING);
		}
#line 1541 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 270 "CminusParser.y" /* yacc.c:1646  */
    {
			emitExit(instList);
		}
#line 1549 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 285 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = (yyvsp[0].symIndex); 
		}
#line 1557 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 289 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitOrExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1565 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 293 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitAndExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1573 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 297 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitNotExpression(instList,symtab,(yyvsp[0].symIndex));
		}
#line 1581 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 303 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = (yyvsp[0].symIndex); 
		}
#line 1589 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 307 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitEqualExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1597 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 311 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitNotEqualExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1605 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 315 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitLessEqualExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1613 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 319 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitLessThanExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1621 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 323 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitGreaterEqualExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1629 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 327 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitGreaterThanExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1637 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 333 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = (yyvsp[0].symIndex); 
		}
#line 1645 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 337 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitAddExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1653 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitSubtractExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1661 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 347 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = (yyvsp[0].symIndex); 
		}
#line 1669 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 351 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitMultiplyExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1677 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 355 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = emitDivideExpression(instList,symtab,(yyvsp[-2].symIndex),(yyvsp[0].symIndex));
		}
#line 1685 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 361 "CminusParser.y" /* yacc.c:1646  */
    { 
			(yyval.symIndex) = emitLoadVariable(instList,symtab,(yyvsp[0].symIndex));
		}
#line 1693 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 365 "CminusParser.y" /* yacc.c:1646  */
    { 
			(yyval.symIndex) = (yyvsp[0].symIndex);
		}
#line 1701 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 369 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = SYM_INVALID_INDEX;
		}
#line 1709 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 373 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = (yyvsp[-1].symIndex);
		}
#line 1717 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 379 "CminusParser.y" /* yacc.c:1646  */
    {
			int symIndex = SymQueryIndex(symtab,(yyvsp[0].name));
			(yyval.symIndex) = emitComputeVariableAddress(instList,symtab,symIndex);
			int offset = (int)SymGetFieldByIndex(symtab,symIndex,SYMTAB_OFFSET_FIELD);
	
			
		}
#line 1729 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 387 "CminusParser.y" /* yacc.c:1646  */
    {
			(yyval.symIndex) = SYM_INVALID_INDEX;
		}
#line 1737 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 393 "CminusParser.y" /* yacc.c:1646  */
    { 
			int symIndex = SymIndex(symtab,(yyvsp[0].name));
			(yyval.symIndex) = emitLoadStringConstantAddress(instList,dataList,symtab,symIndex); 
		}
#line 1746 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 400 "CminusParser.y" /* yacc.c:1646  */
    { 
			int symIndex = SymIndex(symtab,(yyvsp[0].name));
			(yyval.symIndex) = emitLoadIntegerConstant(instList,symtab,symIndex); 
		}
#line 1755 "CminusParser.c" /* yacc.c:1646  */
    break;


#line 1759 "CminusParser.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 406 "CminusParser.y" /* yacc.c:1906  */



/********************C ROUTINES *********************************/

void Cminus_error(char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap() {
	return 1;
}

static void initSymTable() {

	symtab = SymInit(SYMTABLE_SIZE); 

	SymInitField(symtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	SymInitField(symtab,SYMTAB_REGISTER_INDEX_FIELD,(Generic)-1,NULL);
}

static void deleteSymTable() {
    SymKillField(symtab,SYMTAB_REGISTER_INDEX_FIELD);
    SymKillField(symtab,SYMTAB_OFFSET_FIELD);
    SymKill(symtab);

}

static void initialize(char* inputFileName) {

	stdin = freopen(inputFileName,"r", stdin);
        if (stdin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w", stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
       } 

	initSymTable();
	
	initRegisters();
	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);

}

static void finalize() {

    fclose(stdin);
    /*fclose(stdout);*/
    
    deleteSymTable();
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

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
