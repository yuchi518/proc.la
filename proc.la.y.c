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
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

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
       2,     2,     2,    75,     2,     2,     2,    78,    81,     2,
      67,    64,    76,    72,    85,    73,     2,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    86,
      79,     2,    80,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    83,    71,    74,     2,     2,     2,
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
       0,    34,    34,    35,    36,    37,    38,    39,    40,    41,
      45,    48,    51,    54,    61,    62,    63,    64,    69,    70,
      71,    72,    76,    77,    78,    82,    88,    89,    90,    93,
      94,   100,   101,   102,   103,   107,   108,   109,   110,   114,
     115,   116,   117,   121,   122,   123,   127,   128,   129,   133,
     134,   135,   136,   137,   141,   142,   143,   147,   148,   152,
     153,   157,   158,   162,   163,   167,   168,   172,   173,   177,
     181,   182,   183,   187,   188,   192,   193,   197,   198,   199,
     200,   201,   202,   203,   204,   208,   209,   210,   211,   222,
     223,   224,   225,   229,   230,   231,   232,   253,   254,   255,
     256,   257,   258,   262,   266,   267,   271,   272,   276,   280,
     286,   287,   294,   298,   299,   300,   304,   305,   315,   316,
     317,   325,   326,   330,   336,   339,   345,   348,   354,   357,
     364,   367,   377,   383,   389,   392,   398,   404,   410,   411,
     415,   418,   424,   428,   431
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
  "':'", "')'", "\"[]\"", "\"{}\"", "'('", "'['", "']'", "'{'", "'}'",
  "'+'", "'-'", "'~'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'",
  "'^'", "'|'", "'?'", "','", "';'", "$accept", "basic_var_type_specifier",
  "combined_var_type_specifier", "primary_expression", "value_expression",
  "constant", "string", "postfix_expression", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression",
  "container_expression", "list_initializer_list", "map_initializer_list",
  "expression", "expression_statement", "la_statement", "pipe_op",
  "statement", "labeled_statement", "case_statement",
  "cases_block_statement", "compound_statement", "block_item_list",
  "block_item", "selection_statement", "iteration_statement",
  "jump_statement", "var_type_specifier", "var_declaration",
  "var_list_declaration", "type_list_declaration", "la_input_declaration",
  "la_output_declaration", "la_body_declaration", "la_declaration",
  "la_alias", "external_declaration", "external_declaration_list",
  "package_declare", "a_proc_la", YY_NULLPTR
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
     315,   316,   317,    58,    41,   318,   319,    40,    91,    93,
     123,   125,    43,    45,   126,    33,    42,    47,    37,    60,
      62,    38,    94,   124,    63,    44,    59
};
# endif

#define YYPACT_NINF -208

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-208)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    42,    17,  -208,  -208,  -208,  -208,    94,    94,    50,
       2,    71,  -208,    94,  -208,    51,    16,   -23,    86,     9,
      34,    43,    63,    49,    77,   107,  -208,  -208,   -55,   114,
    -208,  -208,  -208,  -208,   198,   198,   123,   140,   157,   126,
     131,   292,   133,   317,   365,    34,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,    88,  -208,   198,   119,   -16,
     109,    32,   105,    91,   145,   147,   191,   -18,  -208,  -208,
    -208,    -3,  -208,  -208,  -208,  -208,   233,  -208,  -208,  -208,
    -208,  -208,   433,  -208,    43,  -208,  -208,   471,  -208,   228,
     208,  -208,   390,  -208,  -208,  -208,  -208,   146,   390,   390,
    -208,   390,   107,  -208,   229,     3,  -208,   -42,   178,   -39,
    -208,  -208,   390,   390,  -208,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   390,     5,  -208,  -208,  -208,  -208,   198,
    -208,   118,    55,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,   124,   142,  -208,   -51,  -208,  -208,
    -208,  -208,  -208,    97,   227,   313,   178,   228,  -208,    78,
    -208,   365,   365,  -208,   229,   336,   388,  -208,  -208,  -208,
     119,   119,   -16,   -16,   109,   109,   109,   109,    32,    32,
     105,    91,   145,   147,   191,   393,   156,  -208,  -208,   107,
     164,    74,  -208,  -208,   130,   130,  -208,  -208,  -208,  -208,
    -208,   471,   292,   181,   292,  -208,  -208,   190,  -208,  -208,
     198,  -208,  -208,   130,   130,  -208,  -208,  -208,   206,   112,
    -208,   365,  -208,  -208,  -208,   292,   162,   193,  -208,   -19,
    -208,  -208,  -208,   162,   194,  -208,  -208,   292,  -208,  -208,
     202,   292,  -208,  -208,  -208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   142,   139,   138,   141,   144,     0,     0,
       0,     0,   140,   143,     1,     0,     0,     0,     0,     0,
       0,   135,     0,     0,     0,     0,   129,   125,     0,    14,
      23,    24,    25,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,    35,    36,    37,
      38,    85,    26,    15,    16,    31,    39,     0,    43,    46,
      49,    54,    57,    59,    61,    63,    65,    67,    69,    70,
      77,     0,    99,   112,    97,    98,     0,   110,   100,   101,
     102,    79,     0,   134,   133,   136,   137,     0,   128,     0,
       0,    14,     0,    32,    33,   120,   119,     0,     0,     0,
     116,     0,    14,    80,     0,     0,    73,     0,    16,     0,
      29,    30,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      86,     0,     0,   109,   111,     2,     3,     4,     5,     6,
       7,     8,     9,   131,   121,   122,   127,     0,   132,   123,
     124,   103,   118,     0,     0,     0,     0,     0,    17,     0,
      71,     0,     0,    72,     0,     0,     0,    40,    41,    42,
      44,    45,    48,    47,    52,    53,    50,    51,    55,    56,
      58,    60,    62,    64,    66,     0,     0,    84,    78,    82,
       0,     0,    83,    81,     0,     0,    10,    11,    12,    13,
     130,     0,     0,     0,     0,    74,    75,     0,    27,    28,
       0,    88,    87,     0,     0,    89,    90,   126,   113,     0,
     117,     0,    68,    92,    91,     0,     0,     0,   107,     0,
      76,   114,    18,     0,     0,    19,    20,     0,   115,   106,
       0,     0,   105,    21,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,  -208,    15,  -207,   -44,  -208,   -24,  -208,
      65,    54,    56,    98,   134,   138,   144,   159,   155,  -208,
      72,   154,   -40,  -208,  -208,   -37,  -208,   231,  -110,   -41,
    -208,    70,  -208,   -15,  -208,   234,  -208,  -208,  -208,   -77,
      -5,  -208,  -208,  -208,   230,   -14,  -208,  -208,    35,   303,
    -208,  -208
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   154,   155,    52,   244,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   107,   109,    71,    72,   169,   142,    73,
      74,   238,   239,    75,    76,    77,    78,    79,    80,   159,
      81,    28,   157,    22,    83,   203,     4,     5,     6,     7,
       8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     100,   108,    21,    23,   106,   156,   105,    84,    25,    88,
      93,    94,    25,   210,    27,   134,   135,   136,   137,   138,
     132,   167,   135,   136,   137,   138,   236,   170,   237,   245,
      89,   201,   173,   114,   211,    11,   245,    29,    30,    31,
      32,    33,    12,   171,    19,    10,   174,    20,    12,   161,
      14,     1,   248,     2,     3,   105,   118,   119,   204,   201,
     166,   163,   164,   196,   165,    15,   133,   168,    17,    34,
      35,   122,   123,    26,    16,   175,   176,   223,    36,    18,
      37,   199,   139,   140,   160,    38,    39,    40,   139,    41,
      42,   177,   178,   179,   225,   226,   195,   135,   136,   137,
     138,    43,    44,    24,    45,    46,    47,    48,    49,    50,
      82,   124,   125,   233,   234,   167,   135,   136,   137,   138,
      51,   199,    19,   110,   111,    20,    21,    21,   205,   197,
     217,   215,   216,    20,   227,    85,   202,   135,   136,   137,
     138,    19,   120,   121,    20,    19,   126,   127,    20,   135,
     136,   137,   138,     1,    21,     2,   112,   236,   113,   237,
      97,   212,   197,    86,   202,   242,    30,    31,    32,    33,
      87,   228,   128,   230,   182,   183,   200,    90,   184,   185,
     186,   187,   139,   180,   181,    19,    21,   224,    20,   206,
     207,   240,   246,    98,   241,   115,   116,   117,    99,   246,
     101,    91,    30,    31,    32,    33,   252,   208,   209,    95,
     254,    29,    30,    31,    32,    33,   145,   146,   147,   148,
     149,   150,   151,   152,   188,   189,    96,   129,   131,   243,
     130,    25,   162,    34,    35,    32,    29,    30,    31,    32,
      33,   172,   221,    34,    35,   167,   135,   136,   137,   138,
     222,   229,    36,   231,    37,   235,   247,   251,   250,    38,
      39,    40,   190,    41,    42,    92,   253,   191,    34,    35,
      47,    48,    49,    50,   192,    43,    44,    36,    45,    37,
      47,    48,    49,    50,    38,    39,    40,   194,    41,    42,
     193,   213,   232,   198,    51,    29,    30,    31,    32,    33,
      43,    44,   141,    45,   143,    47,    48,    49,    50,   249,
     144,    13,   139,     0,   158,     0,     0,     0,     0,    51,
     102,    30,    31,    32,    33,     0,     0,    34,    35,     0,
       0,   167,   135,   136,   137,   138,    36,     0,    37,     0,
       0,     0,     0,    38,    39,    40,     0,    41,    42,     0,
       0,     0,    34,    35,   167,   135,   136,   137,   138,    43,
      44,     0,    45,     0,    47,    48,    49,    50,    91,    30,
      31,    32,    33,     0,     0,     0,     0,   214,    51,     0,
       0,   103,     0,     0,    43,    44,     0,   104,     0,    47,
      48,    49,    50,   102,    30,    31,    32,    33,   139,     0,
      34,    35,     0,     0,     0,   218,   167,   135,   136,   137,
     138,   167,   135,   136,   137,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,    92,    44,     0,   104,     0,    47,    48,    49,
      50,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,   220,    43,    44,   219,
     104,     0,    47,    48,    49,    50,     0,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   139,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153
};

static const yytype_int16 yycheck[] =
{
      41,    45,    17,    17,    44,    82,    43,    22,     3,    64,
      34,    35,     3,    64,    19,    18,    19,    20,    21,    22,
      38,    18,    19,    20,    21,    22,    45,    69,    47,   236,
      85,   141,    71,    57,    85,    18,   243,     3,     4,     5,
       6,     7,     7,    85,    67,     3,    85,    70,    13,    90,
       0,    59,    71,    61,    62,    92,    72,    73,     3,   169,
     104,    98,    99,    58,   101,    63,    84,    64,    17,    35,
      36,    39,    40,    64,     3,   112,   113,     3,    44,    63,
      46,     3,    85,    86,    89,    51,    52,    53,    85,    55,
      56,   115,   116,   117,   204,   205,   133,    19,    20,    21,
      22,    67,    68,    17,    70,    71,    72,    73,    74,    75,
      67,    79,    80,   223,   224,    18,    19,    20,    21,    22,
      86,     3,    67,    35,    36,    70,   141,   142,   142,   134,
     174,   171,   172,    70,   211,    86,   141,    19,    20,    21,
      22,    67,    33,    34,    70,    67,    41,    42,    70,    19,
      20,    21,    22,    59,   169,    61,    68,    45,    70,    47,
       3,    64,   167,    86,   169,     3,     4,     5,     6,     7,
      63,   212,    81,   214,   120,   121,    58,    63,   122,   123,
     124,   125,    85,   118,   119,    67,   201,   201,    70,    65,
      66,   231,   236,    67,   235,    76,    77,    78,    67,   243,
      67,     3,     4,     5,     6,     7,   247,    65,    66,    86,
     251,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   126,   127,    86,    82,    37,    67,
      83,     3,    86,    35,    36,     6,     3,     4,     5,     6,
       7,    63,    86,    35,    36,    18,    19,    20,    21,    22,
      86,    70,    44,    63,    46,    49,    63,    63,   243,    51,
      52,    53,   128,    55,    56,    67,    64,   129,    35,    36,
      72,    73,    74,    75,   130,    67,    68,    44,    70,    46,
      72,    73,    74,    75,    51,    52,    53,   132,    55,    56,
     131,    64,   220,   139,    86,     3,     4,     5,     6,     7,
      67,    68,    71,    70,    71,    72,    73,    74,    75,   239,
      76,     8,    85,    -1,    84,    -1,    -1,    -1,    -1,    86,
       3,     4,     5,     6,     7,    -1,    -1,    35,    36,    -1,
      -1,    18,    19,    20,    21,    22,    44,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    35,    36,    18,    19,    20,    21,    22,    67,
      68,    -1,    70,    -1,    72,    73,    74,    75,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    64,    86,    -1,
      -1,    64,    -1,    -1,    67,    68,    -1,    70,    -1,    72,
      73,    74,    75,     3,     4,     5,     6,     7,    85,    -1,
      35,    36,    -1,    -1,    -1,    69,    18,    19,    20,    21,
      22,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    70,    -1,    72,    73,    74,
      75,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    67,    68,    71,
      70,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    85,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    61,    62,   133,   134,   135,   136,   137,   138,
       3,    18,   135,   136,     0,    63,     3,    17,    63,    67,
      70,   120,   130,   132,    17,     3,    64,   127,   128,     3,
       4,     5,     6,     7,    35,    36,    44,    46,    51,    52,
      53,    55,    56,    67,    68,    70,    71,    72,    73,    74,
      75,    86,    90,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   112,   113,   116,   117,   120,   121,   122,   123,   124,
     125,   127,    67,   131,   120,    86,    86,    63,    64,    85,
      63,     3,    67,    95,    95,    86,    86,     3,    67,    67,
     116,    67,     3,    64,    70,   112,   109,   110,    93,   111,
      35,    36,    68,    70,    95,    76,    77,    78,    72,    73,
      33,    34,    39,    40,    79,    80,    41,    42,    81,    82,
      83,    37,    38,    84,    18,    19,    20,    21,    22,    85,
      86,   114,   115,    71,   122,     8,     9,    10,    11,    12,
      13,    14,    15,    64,    88,    89,   126,   129,   131,   126,
     127,   116,    86,   112,   112,   112,    93,    18,    64,   114,
      69,    85,    63,    71,    85,   112,   112,    95,    95,    95,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     101,   102,   103,   104,   105,   112,    58,   127,   108,     3,
      58,   115,   127,   132,     3,   132,    65,    66,    65,    66,
      64,    85,    64,    64,    64,   109,   109,    93,    69,    71,
      63,    86,    86,     3,   132,   115,   115,   126,   116,    70,
     116,    63,   107,   115,   115,    49,    45,    47,   118,   119,
     109,   116,     3,    67,    91,    92,    93,    63,    71,   118,
      91,    63,   116,    64,   116
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    92,    93,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    96,    96,    96,    96,    97,
      97,    97,    97,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   114,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   123,   123,   123,   124,   124,   125,   125,
     125,   126,   126,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   132,   132,   133,   134,   135,   135,
     136,   136,   137,   138,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     4,     4,     2,
       2,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       1,     3,     3,     1,     3,     3,     5,     1,     3,     1,
       2,     3,     3,     3,     3,     1,     2,     4,     4,     3,
       3,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     2,     3,
       1,     2,     1,     5,     7,     7,     2,     5,     3,     2,
       2,     1,     1,     3,     3,     1,     3,     1,     3,     2,
       3,     2,     3,     2,     2,     1,     6,     6,     1,     1,
       2,     1,     1,     2,     1
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
#line 45 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1519 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 11:
#line 48 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1527 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 12:
#line 51 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1535 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 13:
#line 54 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1543 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 108:
#line 276 "proc.la.y" /* yacc.c:1661  */
    {
        // TODO: refine the function
	    (yyval) = ast_create_ast_body(null, null);
	}
#line 1552 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 109:
#line 280 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = (yyvsp[-1]);
	}
#line 1560 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 111:
#line 287 "proc.la.y" /* yacc.c:1661  */
    {
	    // TODO: refine the function
	    (yyval) = ast_create_ast_body((yyvsp[-1]), (yyvsp[0]));
	}
#line 1569 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 123:
#line 330 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_declare((yyvsp[0]), (yyvsp[-2]));
    }
#line 1577 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 124:
#line 336 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1585 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 125:
#line 339 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_list((yyvsp[0]), null);
    }
#line 1593 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 126:
#line 345 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1601 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 127:
#line 348 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[0]), null);
    }
#line 1609 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 128:
#line 354 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 1617 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 129:
#line 357 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_var_list(null, null);
    }
#line 1626 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 130:
#line 364 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 1634 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 131:
#line 367 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    }
#line 1643 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 132:
#line 377 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1651 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 133:
#line 383 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-1]), (yyvsp[0]), null);
    }
#line 1659 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 134:
#line 389 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1667 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 135:
#line 392 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[0]), null);
    }
#line 1675 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 136:
#line 398 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-2]), (yyvsp[-4]), (yyvsp[-1]));
    }
#line 1683 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 137:
#line 404 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-1]), (yyvsp[-3]), (yyvsp[-5]));
    }
#line 1691 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 140:
#line 415 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[-1]), (yyvsp[0]));
    }
#line 1699 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 141:
#line 418 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[0]), null);
    }
#line 1707 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 143:
#line 428 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la((yyvsp[-1]), (yyvsp[0]));
    }
#line 1715 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 144:
#line 431 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[0]));
    }
#line 1723 "proc.la.y.c" /* yacc.c:1661  */
    break;


#line 1727 "proc.la.y.c" /* yacc.c:1661  */
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
#line 436 "proc.la.y" /* yacc.c:1906  */


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
