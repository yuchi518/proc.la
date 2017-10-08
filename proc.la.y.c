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




/* Copy the first part of user declarations.  */
#line 1 "proc.la.y" /* yacc.c:339  */

    #include "ast.h"
    typedef AstNode YYSTYPE;
    #define YYSTYPE_IS_DECLARED     1
    void yyerror (char const *s);
    int yylex();

#line 74 "proc.la.y.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    N_CONSTANT = 262,
    INT = 263,
    LONG = 264,
    FLOAT = 265,
    DOUBLE = 266,
    NUMBER = 267,
    STRING = 268,
    RAW = 269,
    VAR = 270,
    PROC = 271,
    LA = 272,
    APPLY_TO = 273,
    PIPE_1_TO_1 = 274,
    PIPE_REDUCE = 275,
    PIPE_EXPAND = 276,
    PIPE_INJECT = 277,
    RIGHT_ASSIGN = 278,
    LEFT_ASSIGN = 279,
    ADD_ASSIGN = 280,
    SUB_ASSIGN = 281,
    MUL_ASSIGN = 282,
    DIV_ASSIGN = 283,
    MOD_ASSIGN = 284,
    AND_ASSIGN = 285,
    XOR_ASSIGN = 286,
    OR_ASSIGN = 287,
    RIGHT_OP = 288,
    LEFT_OP = 289,
    INC_OP = 290,
    DEC_OP = 291,
    AND_OP = 292,
    OR_OP = 293,
    LE_OP = 294,
    GE_OP = 295,
    EQ_OP = 296,
    NE_OP = 297,
    AUTO = 298,
    BREAK = 299,
    CASE = 300,
    CONTINUE = 301,
    DEFAULT = 302,
    DO = 303,
    ELSE = 304,
    FOR = 305,
    GOTO = 306,
    IF = 307,
    SWITCH = 308,
    WHILE = 309,
    LOOP = 310,
    EACH = 311,
    IS = 312,
    OUT = 313,
    DECLARE = 314,
    SYNC = 315,
    DOMAIN_NAME = 316,
    PACKAGE_NAME = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 185 "proc.la.y.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    79,    82,     2,
      72,    64,    77,    73,    67,    74,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    86,
      80,     2,    81,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    84,    71,    75,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    36,    37,    38,    39,    40,    41,    42,
      46,    49,    52,    55,    61,    62,    66,    69,    75,    81,
      82,    83,    87,    91,    92,    93,    94,    98,   101,   107,
     113,   119,   126,   129,   135,   138,   144,   147,   153,   154,
     157,   162,   163,   164,   165,   172,   175,   178,   186,   187,
     190,   193,   199,   202,   205,   208,   214,   215,   218,   221,
     227,   228,   231,   237,   238,   241,   247,   248,   251,   254,
     257,   263,   264,   267,   273,   274,   280,   281,   287,   288,
     294,   295,   301,   302,   308,   309,   315,   319,   320,   323,
     326,   332,   333,   336,   344,   347,   350,   353,   359,   362,
     365,   368,   376,   377,   378,   379,   380,   381,   382,   388,
     394,   397,   403,   406,   410,   415,   421,   424,   430,   434,
     437,   440,   446,   449,   455,   458,   461,   469,   473,   476,
     483,   486,   489,   492,   498,   504,   510,   511,   515,   518,
     524,   528,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "N_CONSTANT", "INT", "LONG", "FLOAT", "DOUBLE",
  "NUMBER", "STRING", "RAW", "VAR", "PROC", "LA", "APPLY_TO",
  "PIPE_1_TO_1", "PIPE_REDUCE", "PIPE_EXPAND", "PIPE_INJECT",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "LEFT_OP", "INC_OP", "DEC_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AUTO", "BREAK", "CASE", "CONTINUE",
  "DEFAULT", "DO", "ELSE", "FOR", "GOTO", "IF", "SWITCH", "WHILE", "LOOP",
  "EACH", "IS", "OUT", "DECLARE", "SYNC", "DOMAIN_NAME", "PACKAGE_NAME",
  "':'", "')'", "\"[]\"", "\"{}\"", "','", "'['", "']'", "'{'", "'}'",
  "'('", "'+'", "'-'", "'~'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "'&'", "'^'", "'|'", "'?'", "';'", "$accept", "basic_var_type_specifier",
  "combined_var_type_specifier", "var_type_specifier",
  "type_list_declaration", "var_declaration", "constant", "string",
  "primary_expression", "list_expression", "list_item_list",
  "map_expression", "map_item_list", "tuple_expression", "tuple_item_list",
  "container_access_expression", "container_expression",
  "postfix_expression", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "expression_statement", "la_statement", "pipe_op", "statement",
  "labeled_statement", "case_statement", "cases_block_statement",
  "block_statement", "block_item_list", "block_item",
  "selection_statement", "iteration_statement", "jump_statement",
  "la_input_declaration", "la_output_declaration", "la_body_declaration",
  "la_declaration", "la_alias", "external_declaration",
  "external_declaration_list", "package_declare", "a_proc_la", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    58,    41,   318,   319,    44,    91,    93,
     123,   125,    40,    43,    45,   126,    33,    42,    47,    37,
      60,    62,    38,    94,   124,    63,    59
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,     3,    -6,   -92,   -92,   -92,   -92,    71,    71,    36,
     -43,    38,   -92,    71,   -92,    32,    50,   103,   100,   158,
     348,   -92,    52,    59,    48,    54,    88,   -92,   -92,   -92,
     -92,   374,   374,    69,    80,   169,   115,   117,   274,   135,
     180,   359,   158,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   109,   -92,    60,   -92,
     374,    43,    27,   114,   -21,   144,   121,   134,   143,   198,
     -31,   -92,   -92,     5,   -92,   -92,   -92,   -92,   216,   -92,
     -92,   -92,   -92,   178,   -92,   374,   -24,   138,    20,   -92,
      52,   -92,   -92,    63,   -92,   -92,   -92,   -92,   156,   374,
     374,   -92,   374,   157,   -92,   111,   138,   -16,    -5,   374,
     374,   -92,   -92,   -92,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   401,   -92,   -92,   -92,   -92,   377,   -92,
     -92,   300,   -92,   -92,   377,   149,   -92,   374,   374,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   126,   131,
     -92,    -3,   -92,   -92,   -92,   -92,   124,   218,   236,   -92,
     374,   -92,   374,   -92,   374,    84,    26,   -92,   -92,   -92,
      43,    43,    27,    27,   114,   114,   114,   114,   -21,   -21,
     144,   121,   134,   143,   198,   276,   159,   -92,   -92,   -92,
     -92,   176,   -92,   -92,   138,   -92,   -92,   -92,   -92,   -92,
     377,   274,   177,   274,   138,   433,   138,   -92,   -92,   374,
     -92,   -92,   199,   137,   -92,   374,   -92,   274,   374,   186,
     -92,    -8,   138,   -92,   442,   274,   -92,   -92,   274,   -92,
     -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   140,   137,   136,   139,   142,     0,     0,
       0,     0,   138,   141,     1,     0,     0,     0,     0,     0,
       0,   127,   133,     0,     0,     0,    25,    20,    21,    22,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,    52,    53,    54,    55,    91,    26,
      23,    24,    38,    41,    42,    43,    44,    45,    48,    56,
       0,    60,    63,    66,    71,    74,    76,    78,    80,    82,
      84,    86,    87,     0,   104,   118,   102,   103,     0,   116,
     105,   106,   107,    25,    35,     0,     0,    36,     0,   132,
     131,   134,   135,     0,    49,    50,   126,   125,     0,     0,
       0,   122,     0,     0,    28,     0,    29,     0,     0,     0,
       0,    46,    47,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,     0,    92,
      89,     0,   115,   117,     0,     0,    34,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,   129,    14,    15,
      17,     0,   130,    18,   109,   124,     0,     0,     0,   108,
       0,    27,     0,    31,     0,     0,     0,    57,    58,    59,
      61,    62,    65,    64,    69,    70,    67,    68,    72,    73,
      75,    77,    79,    81,    83,     0,     0,    88,    90,    96,
      94,    43,    97,    95,    37,    10,    11,    12,    13,   128,
       0,     0,     0,     0,    30,     0,    32,    39,    40,     0,
      93,    16,   119,     0,   123,     0,    85,     0,     0,     0,
     113,     0,    33,   120,     0,     0,   121,   112,     0,   111,
     110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -85,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -13,   -92,   -92,   -92,   -92,   -22,   -92,
      82,    96,   -36,    99,   123,   125,   130,   133,   139,   -92,
      42,   -91,   -20,   -92,   -92,   -92,   -37,   -92,    33,   -92,
     -15,   -92,   187,   -92,   -92,   -92,   -92,   183,   142,   -92,
     -92,    -2,   258,   -92,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   158,   159,   163,   161,    49,    50,    51,    52,    53,
     105,    54,   107,    55,    86,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   140,   141,    75,    76,   230,   231,
      77,    78,    79,    80,    81,    82,    23,    89,    24,     4,
       5,     6,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   101,    22,   160,    21,    12,    10,   131,    90,    94,
      95,    12,    11,   133,   134,   135,   136,   137,   121,   122,
      15,   106,   108,   133,   134,   135,   136,   137,   149,   150,
     151,   152,   153,   154,   155,   156,    14,   228,   113,   229,
     146,    16,   197,   147,   148,   134,   135,   136,   137,    17,
     202,   172,   138,   198,   132,   173,   164,   197,   174,   123,
     124,   209,   138,   236,   210,   145,    26,    27,    28,    29,
      30,   149,   150,   151,   152,   153,   154,   155,   156,   166,
     167,   139,   168,   138,   157,   184,   185,   186,   187,   175,
     176,   139,   177,   178,   179,   111,   112,   218,    31,    32,
     117,   118,   148,   134,   135,   136,   137,    33,     1,    34,
       2,     3,   195,    18,    35,    36,    37,    25,    38,    39,
     114,   115,   116,    40,    88,   221,    22,   204,   201,    19,
       1,    41,     2,    42,    91,    20,    44,    45,    46,    47,
      92,   138,   148,   134,   135,   136,   137,   119,   120,    48,
     214,    93,   215,   217,   216,    96,   148,   134,   135,   136,
     137,    26,    27,    28,    29,    30,    97,   148,   134,   135,
     136,   137,    98,    19,   222,    20,   224,   109,   170,   110,
     171,   138,   228,   103,   229,   125,   126,    99,   211,   100,
     233,   205,   206,    31,    32,   138,   207,   208,   239,   180,
     181,   240,    33,   127,    34,   232,   138,   102,   234,    35,
      36,    37,   174,    38,    39,   182,   183,   128,    40,    26,
      27,    28,    29,    30,   188,   189,    41,   129,    42,    43,
      20,    44,    45,    46,    47,   130,   148,   134,   135,   136,
     137,   144,   165,   169,    48,   220,  -127,   223,   227,   235,
     190,    31,    32,   191,   148,   134,   135,   136,   137,   192,
      33,   226,    34,   193,   237,   143,    13,    35,    36,    37,
     194,    38,    39,   162,     0,   138,    40,    26,    27,    28,
      29,    30,   212,   203,    41,     0,    42,   142,    20,    44,
      45,    46,    47,   138,   148,   134,   135,   136,   137,     0,
     213,     0,    48,    83,    27,    28,    29,    30,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      34,     0,     0,     0,     0,    35,    36,    37,     0,    38,
      39,     0,     0,   138,    40,    31,    32,     0,     0,   219,
       0,     0,    41,     0,    42,     0,    20,    44,    45,    46,
      47,    83,    27,    28,    29,    30,     0,     0,   199,     0,
      48,   200,    83,    27,    28,    29,    30,     0,    41,     0,
      42,     0,    20,    44,    45,    46,    47,    83,    27,    28,
      29,    30,     0,    31,    32,   149,   150,   151,   152,   153,
     154,   155,   156,     0,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    27,    28,    29,    30,    31,
      32,     0,    84,     0,     0,     0,    41,     0,    85,     0,
      20,    44,    45,    46,    47,     0,     0,    41,   104,    85,
       0,    20,    44,    45,    46,    47,    31,    32,     0,     0,
       0,     0,    41,     0,    85,     0,    20,    44,    45,    46,
      47,   148,   134,   135,   136,   137,     0,     0,     0,   196,
     148,   134,   135,   136,   137,     0,     0,     0,     0,    41,
       0,    85,     0,    20,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   225,     0,     0,   138,
       0,     0,     0,     0,     0,   238
};

static const yytype_int16 yycheck[] =
{
      20,    38,    17,    88,    17,     7,     3,    38,    23,    31,
      32,    13,    18,    18,    19,    20,    21,    22,    39,    40,
      63,    41,    42,    18,    19,    20,    21,    22,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    45,    60,    47,
      64,     3,   133,    67,    18,    19,    20,    21,    22,    17,
     141,    67,    57,   138,    85,    71,    93,   148,    63,    80,
      81,    64,    57,    71,    67,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    99,
     100,    86,   102,    57,    64,   121,   122,   123,   124,   109,
     110,    86,   114,   115,   116,    35,    36,    71,    35,    36,
      73,    74,    18,    19,    20,    21,    22,    44,    59,    46,
      61,    62,   132,    63,    51,    52,    53,    17,    55,    56,
      77,    78,    79,    60,    72,   210,   141,   147,   141,    70,
      59,    68,    61,    70,    86,    72,    73,    74,    75,    76,
      86,    57,    18,    19,    20,    21,    22,    33,    34,    86,
     170,    63,   172,    69,   174,    86,    18,    19,    20,    21,
      22,     3,     4,     5,     6,     7,    86,    18,    19,    20,
      21,    22,     3,    70,   211,    72,   213,    68,    67,    70,
      69,    57,    45,     3,    47,    41,    42,    72,    64,    72,
     227,    65,    66,    35,    36,    57,    65,    66,   235,   117,
     118,   238,    44,    82,    46,   225,    57,    72,   228,    51,
      52,    53,    63,    55,    56,   119,   120,    83,    60,     3,
       4,     5,     6,     7,   125,   126,    68,    84,    70,    71,
      72,    73,    74,    75,    76,    37,    18,    19,    20,    21,
      22,    63,    86,    86,    86,    86,    70,    70,    49,    63,
     127,    35,    36,   128,    18,    19,    20,    21,    22,   129,
      44,   219,    46,   130,   231,    78,     8,    51,    52,    53,
     131,    55,    56,    90,    -1,    57,    60,     3,     4,     5,
       6,     7,    64,   141,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    57,    18,    19,    20,    21,    22,    -1,
      64,    -1,    86,     3,     4,     5,     6,     7,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      56,    -1,    -1,    57,    60,    35,    36,    -1,    -1,    63,
      -1,    -1,    68,    -1,    70,    -1,    72,    73,    74,    75,
      76,     3,     4,     5,     6,     7,    -1,    -1,    58,    -1,
      86,    61,     3,     4,     5,     6,     7,    -1,    68,    -1,
      70,    -1,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,    -1,    35,    36,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    35,
      36,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,    -1,
      72,    73,    74,    75,    76,    -1,    -1,    68,    69,    70,
      -1,    72,    73,    74,    75,    76,    35,    36,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    72,    73,    74,    75,
      76,    18,    19,    20,    21,    22,    -1,    -1,    -1,    58,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    61,    62,   136,   137,   138,   139,   140,   141,
       3,    18,   138,   139,     0,    63,     3,    17,    63,    70,
      72,   100,   127,   133,   135,    17,     3,     4,     5,     6,
       7,    35,    36,    44,    46,    51,    52,    53,    55,    56,
      60,    68,    70,    71,    73,    74,    75,    76,    86,    92,
      93,    94,    95,    96,    98,   100,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   123,   124,   127,   128,   129,
     130,   131,   132,     3,    64,    70,   101,   119,    72,   134,
     127,    86,    86,    63,   105,   105,    86,    86,     3,    72,
      72,   123,    72,     3,    69,    97,   119,    99,   119,    68,
      70,    35,    36,   105,    77,    78,    79,    73,    74,    33,
      34,    39,    40,    80,    81,    41,    42,    82,    83,    84,
      37,    38,    85,    18,    19,    20,    21,    22,    57,    86,
     121,   122,    71,   129,    63,   119,    64,    67,    18,     8,
       9,    10,    11,    12,    13,    14,    15,    64,    88,    89,
      90,    91,   134,    90,   123,    86,   119,   119,   119,    86,
      67,    69,    67,    71,    63,   119,   119,   105,   105,   105,
     107,   107,   108,   108,   109,   109,   109,   109,   110,   110,
     111,   112,   113,   114,   115,   119,    58,   118,    90,    58,
      61,   100,   118,   135,   119,    65,    66,    65,    66,    64,
      67,    64,    64,    64,   119,   119,   119,    69,    71,    63,
      86,    90,   123,    70,   123,    63,   117,    49,    45,    47,
     125,   126,   119,   123,   119,    63,    71,   125,    63,   123,
     123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    93,    94,    95,    95,    95,    95,    96,    96,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     102,   103,   103,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   109,   109,   109,   110,   110,   110,   110,
     110,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   119,   119,   119,
     119,   120,   120,   120,   121,   121,   121,   121,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   130,
     130,   130,   131,   131,   132,   132,   132,   133,   134,   134,
     135,   135,   135,   135,   136,   137,   138,   138,   139,   139,
     140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     3,     3,     5,     3,     2,     1,     3,     1,     4,
       4,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     1,     3,     2,
       3,     1,     2,     4,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     3,     2,     1,     2,     3,     1,     2,     1,     5,
       7,     7,     2,     5,     3,     2,     2,     1,     3,     2,
       3,     2,     2,     1,     6,     6,     1,     1,     2,     1,
       1,     2,     1
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
        case 10:
#line 46 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1519 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 11:
#line 49 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1527 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 12:
#line 52 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1535 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 13:
#line 55 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1543 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 16:
#line 66 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1551 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 17:
#line 69 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[0]), null);
    }
#line 1559 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 18:
#line 75 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_declare((yyvsp[0]), (yyvsp[-2]));
    }
#line 1567 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 27:
#line 98 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1575 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 28:
#line 101 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1583 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 29:
#line 107 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[0]), null, ast_container_type_list);
    }
#line 1591 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 30:
#line 113 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[-2]), (yyvsp[0]), ast_container_type_list);
    }
#line 1599 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 31:
#line 119 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1607 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 32:
#line 126 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container(ast_create_pair((yyvsp[-2]), (yyvsp[0])), null, ast_container_type_map);
    }
#line 1615 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 33:
#line 129 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[-4]), ast_create_pair((yyvsp[-2]), (yyvsp[0])), ast_container_type_map);
    }
#line 1623 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 34:
#line 135 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1631 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 35:
#line 138 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1639 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 36:
#line 144 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[0]), null, ast_container_type_tuple);
    }
#line 1647 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 37:
#line 147 "proc.la.y" /* yacc.c:1661  */
    {
         (yyval) = ast_create_container((yyvsp[-2]), (yyvsp[0]), ast_container_type_tuple);
    }
#line 1655 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 39:
#line 154 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_list_access);
    }
#line 1663 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 40:
#line 157 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_map_access);
    }
#line 1671 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 46:
#line 175 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_inc_l);
	}
#line 1679 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 47:
#line 178 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_dec_l);
	}
#line 1687 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 49:
#line 187 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_inc_f);
    }
#line 1695 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 50:
#line 190 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_dec_f);
    }
#line 1703 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 51:
#line 193 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr_ex((yyvsp[0]), (yyvsp[-1]));
    }
#line 1711 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 52:
#line 199 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_plus);
	}
#line 1719 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 53:
#line 202 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_minus);
	}
#line 1727 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 54:
#line 205 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_invert);
	}
#line 1735 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 55:
#line 208 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_not);
	}
#line 1743 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 57:
#line 215 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_multiply);
	}
#line 1751 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 58:
#line 218 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_divide);
	}
#line 1759 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 59:
#line 221 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_modulo);
	}
#line 1767 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 61:
#line 228 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_add);
	}
#line 1775 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 62:
#line 231 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_subtract);
	}
#line 1783 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 64:
#line 238 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_left);
	}
#line 1791 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 65:
#line 241 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_right);
	}
#line 1799 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 67:
#line 248 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less);
	}
#line 1807 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 68:
#line 251 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great);
	}
#line 1815 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 69:
#line 254 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less_or_equal);
	}
#line 1823 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 70:
#line 257 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great_or_equal);
	}
#line 1831 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 72:
#line 264 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_equal);
	}
#line 1839 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 73:
#line 267 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_not_equal);
	}
#line 1847 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 75:
#line 274 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_and);
	}
#line 1855 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 77:
#line 281 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_xor);
	}
#line 1863 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 79:
#line 288 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_or);
	}
#line 1871 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 81:
#line 295 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_and);
	}
#line 1879 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 83:
#line 302 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_or);
	}
#line 1887 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 85:
#line 309 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_ternary_op_expr((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]), ast_ternary_op_conditional);
	}
#line 1895 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 88:
#line 320 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_apply_to);
    }
#line 1903 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 89:
#line 323 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[0]), (yyvsp[-1]));
	}
#line 1911 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 90:
#line 326 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_is_expr((yyvsp[-2]), (yyvsp[0]));
	}
#line 1919 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 92:
#line 333 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = (yyvsp[-1]);
	}
#line 1927 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 93:
#line 336 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_apply_to);
    }
#line 1935 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 94:
#line 344 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1943 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 95:
#line 347 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1951 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 96:
#line 350 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1959 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 97:
#line 353 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1967 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 98:
#line 359 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_1to1);
    }
#line 1975 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 99:
#line 362 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_reduce);
    }
#line 1983 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 100:
#line 365 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_expand);
    }
#line 1991 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 101:
#line 368 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_inject);
    }
#line 1999 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 108:
#line 382 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_sync((yyvsp[-1]));
	}
#line 2007 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 109:
#line 388 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_block(ast_create_anchor((yyvsp[-2])), (yyvsp[0]));
	}
#line 2015 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 110:
#line 394 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block(ast_create_case((yyvsp[-2])), (yyvsp[0]));
    }
#line 2023 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 111:
#line 397 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block(ast_create_case(null), (yyvsp[0]));
    }
#line 2031 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 112:
#line 403 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block((yyvsp[-1]), (yyvsp[0]));
    }
#line 2039 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 114:
#line 410 "proc.la.y" /* yacc.c:1661  */
    {
        // This is also a empty map.
	    //$$ = ast_close_block(ast_create_block(null, null));
	    (yyval) = ast_create_none();
	}
#line 2049 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 115:
#line 415 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_close_block((yyvsp[-1]));
	}
#line 2057 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 116:
#line 421 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_block((yyvsp[0]), null);
	}
#line 2065 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 117:
#line 424 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_block((yyvsp[-1]), (yyvsp[0]));
	}
#line 2073 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 119:
#line 434 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_ifelse((yyvsp[-2]), (yyvsp[0]), null);
	}
#line 2081 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 120:
#line 437 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_ifelse((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
	}
#line 2089 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 121:
#line 440 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_switch((yyvsp[-4]), ast_close_block((yyvsp[-1])));
	}
#line 2097 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 122:
#line 446 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_loop((yyvsp[0]));
    }
#line 2105 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 123:
#line 449 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_each((yyvsp[-2]), (yyvsp[0]));
    }
#line 2113 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 124:
#line 455 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_jump(ast_jump_type_goto, (yyvsp[-1]));
	}
#line 2121 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 125:
#line 458 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_jump(ast_jump_type_continue, null);
	}
#line 2129 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 126:
#line 461 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_jump(ast_jump_type_break, null);
	}
#line 2137 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 128:
#line 473 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 2145 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 129:
#line 476 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    }
#line 2154 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 130:
#line 483 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2162 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 131:
#line 486 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-1]), (yyvsp[0]), null);
    }
#line 2170 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 132:
#line 489 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-1]), (yyvsp[0]));
    }
#line 2178 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 133:
#line 492 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[0]), null);
    }
#line 2186 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 134:
#line 498 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-2]), (yyvsp[-4]), (yyvsp[-1]));
    }
#line 2194 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 135:
#line 504 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-1]), (yyvsp[-3]), (yyvsp[-5]));
    }
#line 2202 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 138:
#line 515 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[-1]), (yyvsp[0]));
    }
#line 2210 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 139:
#line 518 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[0]), null);
    }
#line 2218 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 141:
#line 528 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la((yyvsp[-1]), (yyvsp[0]));
    }
#line 2226 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 142:
#line 531 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[0]));
    }
#line 2234 "proc.la.y.c" /* yacc.c:1661  */
    break;


#line 2238 "proc.la.y.c" /* yacc.c:1661  */
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
#line 536 "proc.la.y" /* yacc.c:1906  */


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
