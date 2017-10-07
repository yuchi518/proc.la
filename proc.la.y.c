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
#define YYLAST   525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

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
      72,    64,    77,    73,    69,    74,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    86,
      80,     2,    81,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    83,     2,     2,     2,     2,     2,
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
      46,    49,    52,    55,    61,    67,    68,    69,    73,    77,
      78,    79,    80,    84,    87,    93,    99,   105,   112,   115,
     121,   124,   130,   133,   139,   140,   143,   148,   149,   150,
     151,   158,   161,   164,   172,   173,   176,   179,   185,   188,
     191,   194,   200,   201,   204,   207,   213,   214,   217,   223,
     224,   227,   233,   234,   237,   240,   243,   249,   250,   253,
     259,   260,   266,   267,   273,   274,   280,   281,   287,   288,
     294,   295,   301,   305,   306,   309,   312,   315,   321,   322,
     325,   333,   336,   339,   342,   348,   351,   354,   357,   365,
     366,   367,   368,   369,   370,   374,   380,   383,   389,   392,
     396,   401,   407,   408,   414,   418,   419,   420,   426,   427,
     437,   438,   439,   447,   448,   461,   464,   470,   481,   484,
     491,   494,   497,   500,   506,   512,   518,   519,   523,   526,
     532,   536,   539
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
  "':'", "')'", "\"[]\"", "\"{}\"", "'['", "']'", "','", "'{'", "'}'",
  "'('", "'+'", "'-'", "'~'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "'&'", "'^'", "'|'", "'?'", "';'", "$accept", "basic_var_type_specifier",
  "combined_var_type_specifier", "var_declaration", "constant", "string",
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
  "var_type_specifier", "type_list_declaration", "la_input_declaration",
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
     315,   316,   317,    58,    41,   318,   319,    91,    93,    44,
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
      49,     3,    -6,   -92,   -92,   -92,   -92,   -10,   -10,    55,
     -43,    58,   -92,   -10,   -92,    47,    33,    59,    96,   157,
     300,   -92,    29,    70,    39,    68,    54,   -92,   -92,   -92,
     -92,   449,   449,    85,    90,   162,   130,   134,   273,   144,
     220,   347,   157,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -27,   -92,   112,   -92,
     449,    43,   104,   146,   -21,   141,   143,   151,   142,   203,
     -31,   -92,   -92,     5,   -92,   -92,   -92,   -92,   215,   -92,
     -92,   -92,   -92,   178,   -92,   391,   -28,   137,    20,   -92,
      29,   -92,   -92,    63,   -92,   -92,   -92,   -92,   156,   391,
     391,   -92,   391,   -92,   -92,   116,   137,   103,    -5,   391,
     391,   -92,   -92,   -92,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   391,   433,   -92,   -92,   -92,   -92,   484,   -92,
     -92,   374,   -92,   -92,   484,   148,   -92,   391,   449,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   121,   125,
     -92,    31,   -92,   -92,   -92,   -92,   124,   217,   235,   -92,
     391,   391,   -92,   391,    84,    26,   -92,   -92,   -92,    43,
      43,   104,   104,   146,   146,   146,   146,   -21,   -21,   141,
     143,   151,   142,   203,   275,   158,   -92,   -92,   -92,   -92,
     175,   -92,   -92,   137,   -92,   -92,   -92,   -92,   -92,   484,
     273,   176,   273,   137,   367,   137,   -92,   -92,   449,   -92,
     -92,   198,    87,   -92,   391,   -92,   273,   391,   185,   -92,
      -8,   137,   -92,   454,   273,   -92,   -92,   273,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   140,   137,   136,   139,   142,     0,     0,
       0,     0,   138,   141,     1,     0,     0,     0,     0,     0,
       0,   127,   133,     0,     0,     0,    21,    16,    17,    18,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,    48,    49,    50,    51,    88,    22,
      19,    20,    34,    37,    38,    39,    40,    41,    44,    52,
       0,    56,    59,    62,    67,    70,    72,    74,    76,    78,
      80,    82,    83,     0,   101,   114,    99,   100,     0,   112,
     102,   103,   104,    21,    31,     0,     0,    32,     0,   132,
     131,   134,   135,     0,    45,    46,   122,   121,     0,     0,
       0,   118,     0,    87,    24,     0,    25,     0,     0,     0,
       0,    42,    43,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,     0,    89,
      85,     0,   111,   113,     0,     0,    30,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,   129,   123,   124,
     126,     0,   130,   105,    14,   120,     0,     0,     0,    23,
       0,     0,    27,     0,     0,     0,    53,    54,    55,    57,
      58,    61,    60,    65,    66,    63,    64,    68,    69,    71,
      73,    75,    77,    79,     0,     0,    84,    86,    93,    91,
      39,    94,    92,    33,    10,    11,    12,    13,   128,     0,
       0,     0,     0,    26,     0,    28,    35,    36,     0,    90,
     125,   115,     0,   119,     0,    81,     0,     0,     0,   109,
       0,    29,   116,     0,     0,   117,   108,     0,   107,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -13,   -92,   -92,   -92,   -92,   -22,   -92,    78,    79,
     -36,    89,   122,   132,   123,   128,   131,   -92,    45,   -91,
     -20,   -92,   -92,   -92,   -37,   -92,    34,   -92,   -15,   -92,
     187,   -92,   -92,   -92,   -85,   -92,   -92,   179,   159,   -92,
     -92,    -2,   264,   -92,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   158,   159,    49,    50,    51,    52,    53,   105,    54,
     107,    55,    86,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   140,   141,    75,    76,   229,   230,    77,    78,
      79,    80,    81,    82,   164,   161,    23,    89,    24,     4,
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
     151,   152,   153,   154,   155,   156,   146,   227,   113,   228,
     109,   147,   196,   110,   148,   134,   135,   136,   137,     1,
     201,     2,   138,   197,   132,    14,   163,   196,   173,   123,
     124,    16,   138,   235,    17,   145,    26,    27,    28,    29,
      30,   149,   150,   151,   152,   153,   154,   155,   156,   166,
     167,   139,   168,   138,   157,   183,   184,   185,   186,   174,
     175,   139,   176,   177,   178,   208,    18,   217,    31,    32,
     209,    88,   148,   134,   135,   136,   137,    33,     1,    34,
       2,     3,   194,    25,    35,    36,    37,    93,    38,    39,
     114,   115,   116,    40,   220,    91,    22,   203,   200,    19,
      41,    20,   227,    42,   228,    20,    44,    45,    46,    47,
      19,   138,   148,   134,   135,   136,   137,   111,   112,    48,
     213,   214,   216,   215,    92,   148,   134,   135,   136,   137,
      26,    27,    28,    29,    30,    98,   148,   134,   135,   136,
     137,    96,   171,   221,   172,   223,    97,   117,   118,   119,
     120,   138,   125,   126,   169,   170,   204,   205,   210,   232,
     206,   207,    31,    32,   138,   179,   180,   238,   181,   182,
     239,    33,    99,    34,   231,   138,   100,   233,    35,    36,
      37,   173,    38,    39,   187,   188,   102,    40,    26,    27,
      28,    29,    30,   103,    41,   127,   129,    42,    43,    20,
      44,    45,    46,    47,   128,   148,   134,   135,   136,   137,
     130,   144,   165,    48,   219,  -127,   222,   226,   234,   189,
      31,    32,   191,   148,   134,   135,   136,   137,   192,    33,
     190,    34,   193,   225,   236,   143,    35,    36,    37,   162,
      38,    39,    13,     0,   138,    40,    26,    27,    28,    29,
      30,   211,    41,     0,     0,    42,   142,    20,    44,    45,
      46,    47,   138,   148,   134,   135,   136,   137,     0,   212,
     202,    48,     0,    83,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    34,
       0,     0,     0,     0,    35,    36,    37,     0,    38,    39,
       0,     0,   138,    40,     0,    31,    32,     0,   218,     0,
      41,     0,     0,    42,     0,    20,    44,    45,    46,    47,
      83,    27,    28,    29,    30,     0,     0,     0,     0,    48,
      40,     0,     0,     0,    84,     0,     0,    41,     0,     0,
      85,     0,    20,    44,    45,    46,    47,    83,    27,    28,
      29,    30,    31,    32,     0,   148,   134,   135,   136,   137,
       0,     0,     0,     0,    83,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,    31,
      32,     0,     0,     0,    41,   104,     0,    85,     0,    20,
      44,    45,    46,    47,   138,     0,    31,    32,     0,     0,
     224,     0,   198,     0,     0,   199,    83,    27,    28,    29,
      30,    41,     0,     0,    42,     0,    20,    44,    45,    46,
      47,    40,    83,    27,    28,    29,    30,     0,    41,     0,
       0,    85,     0,    20,    44,    45,    46,    47,    31,    32,
       0,     0,   148,   134,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,     0,     0,     0,
       0,   195,   149,   150,   151,   152,   153,   154,   155,   156,
      41,     0,     0,    85,     0,    20,    44,    45,    46,    47,
       0,   138,     0,     0,     0,     0,    41,   237,     0,    85,
       0,    20,    44,    45,    46,    47
};

static const yytype_int16 yycheck[] =
{
      20,    38,    17,    88,    17,     7,     3,    38,    23,    31,
      32,    13,    18,    18,    19,    20,    21,    22,    39,    40,
      63,    41,    42,    18,    19,    20,    21,    22,     8,     9,
      10,    11,    12,    13,    14,    15,    64,    45,    60,    47,
      67,    69,   133,    70,    18,    19,    20,    21,    22,    59,
     141,    61,    57,   138,    85,     0,    93,   148,    63,    80,
      81,     3,    57,    71,    17,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    99,
     100,    86,   102,    57,    64,   121,   122,   123,   124,   109,
     110,    86,   114,   115,   116,    64,    63,    71,    35,    36,
      69,    72,    18,    19,    20,    21,    22,    44,    59,    46,
      61,    62,   132,    17,    51,    52,    53,    63,    55,    56,
      77,    78,    79,    60,   209,    86,   141,   147,   141,    70,
      67,    72,    45,    70,    47,    72,    73,    74,    75,    76,
      70,    57,    18,    19,    20,    21,    22,    35,    36,    86,
     170,   171,    68,   173,    86,    18,    19,    20,    21,    22,
       3,     4,     5,     6,     7,     3,    18,    19,    20,    21,
      22,    86,    69,   210,    71,   212,    86,    73,    74,    33,
      34,    57,    41,    42,    68,    69,    65,    66,    64,   226,
      65,    66,    35,    36,    57,   117,   118,   234,   119,   120,
     237,    44,    72,    46,   224,    57,    72,   227,    51,    52,
      53,    63,    55,    56,   125,   126,    72,    60,     3,     4,
       5,     6,     7,     3,    67,    82,    84,    70,    71,    72,
      73,    74,    75,    76,    83,    18,    19,    20,    21,    22,
      37,    63,    86,    86,    86,    70,    70,    49,    63,   127,
      35,    36,   129,    18,    19,    20,    21,    22,   130,    44,
     128,    46,   131,   218,   230,    78,    51,    52,    53,    90,
      55,    56,     8,    -1,    57,    60,     3,     4,     5,     6,
       7,    64,    67,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    57,    18,    19,    20,    21,    22,    -1,    64,
     141,    86,    -1,     3,     4,     5,     6,     7,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,    56,
      -1,    -1,    57,    60,    -1,    35,    36,    -1,    63,    -1,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    86,
      60,    -1,    -1,    -1,    64,    -1,    -1,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,    35,    36,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    35,
      36,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,    72,
      73,    74,    75,    76,    57,    -1,    35,    36,    -1,    -1,
      63,    -1,    58,    -1,    -1,    61,     3,     4,     5,     6,
       7,    67,    -1,    -1,    70,    -1,    72,    73,    74,    75,
      76,    60,     3,     4,     5,     6,     7,    -1,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    35,    36,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    58,     8,     9,    10,    11,    12,    13,    14,    15,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
      -1,    57,    -1,    -1,    -1,    -1,    67,    63,    -1,    70,
      -1,    72,    73,    74,    75,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    61,    62,   136,   137,   138,   139,   140,   141,
       3,    18,   138,   139,     0,    63,     3,    17,    63,    70,
      72,    98,   125,   133,   135,    17,     3,     4,     5,     6,
       7,    35,    36,    44,    46,    51,    52,    53,    55,    56,
      60,    67,    70,    71,    73,    74,    75,    76,    86,    90,
      91,    92,    93,    94,    96,    98,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,   122,   125,   126,   127,
     128,   129,   130,     3,    64,    70,    99,   117,    72,   134,
     125,    86,    86,    63,   103,   103,    86,    86,     3,    72,
      72,   121,    72,     3,    68,    95,   117,    97,   117,    67,
      70,    35,    36,   103,    77,    78,    79,    73,    74,    33,
      34,    39,    40,    80,    81,    41,    42,    82,    83,    84,
      37,    38,    85,    18,    19,    20,    21,    22,    57,    86,
     119,   120,    71,   127,    63,   117,    64,    69,    18,     8,
       9,    10,    11,    12,    13,    14,    15,    64,    88,    89,
     131,   132,   134,   121,   131,    86,   117,   117,   117,    68,
      69,    69,    71,    63,   117,   117,   103,   103,   103,   105,
     105,   106,   106,   107,   107,   107,   107,   108,   108,   109,
     110,   111,   112,   113,   117,    58,   116,   131,    58,    61,
      98,   116,   135,   117,    65,    66,    65,    66,    64,    69,
      64,    64,    64,   117,   117,   117,    68,    71,    63,    86,
     131,   121,    70,   121,    63,   115,    49,    45,    47,   123,
     124,   117,   121,   117,    63,    71,   123,    63,   121,   121
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    91,    91,    91,    92,    93,
      93,    93,    93,    94,    94,    95,    95,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   104,   105,   105,   105,   105,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   134,   134,
     135,   135,   135,   135,   136,   137,   138,   138,   139,   139,
     140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     3,     3,     5,
       3,     2,     1,     3,     1,     4,     4,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     3,     2,     3,     2,     1,     2,
       4,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     1,
       2,     3,     1,     2,     1,     5,     7,     7,     2,     5,
       3,     2,     2,     1,     1,     3,     1,     1,     3,     2,
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
#line 1520 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 11:
#line 49 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1528 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 12:
#line 52 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1536 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 13:
#line 55 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1544 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 14:
#line 61 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_declare((yyvsp[0]), (yyvsp[-2]));
    }
#line 1552 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 23:
#line 84 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1560 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 24:
#line 87 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1568 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 25:
#line 93 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[0]), null, ast_container_type_list);
    }
#line 1576 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 26:
#line 99 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[-2]), (yyvsp[0]), ast_container_type_list);
    }
#line 1584 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 27:
#line 105 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1592 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 28:
#line 112 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container(ast_create_pair((yyvsp[-2]), (yyvsp[0])), null, ast_container_type_map);
    }
#line 1600 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 29:
#line 115 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[-4]), ast_create_pair((yyvsp[-2]), (yyvsp[0])), ast_container_type_map);
    }
#line 1608 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 30:
#line 121 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_close_container((yyvsp[-1]));
    }
#line 1616 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 31:
#line 124 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1624 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 32:
#line 130 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_container((yyvsp[0]), null, ast_container_type_tuple);
    }
#line 1632 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 33:
#line 133 "proc.la.y" /* yacc.c:1661  */
    {
         (yyval) = ast_create_container((yyvsp[-2]), (yyvsp[0]), ast_container_type_tuple);
    }
#line 1640 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 35:
#line 140 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_list_access);
    }
#line 1648 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 36:
#line 143 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_map_access);
    }
#line 1656 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 42:
#line 161 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_inc_l);
	}
#line 1664 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 43:
#line 164 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_dec_l);
	}
#line 1672 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 45:
#line 173 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_inc_f);
    }
#line 1680 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 46:
#line 176 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_dec_f);
    }
#line 1688 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 47:
#line 179 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr_ex((yyvsp[0]), (yyvsp[-1]));
    }
#line 1696 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 48:
#line 185 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_plus);
	}
#line 1704 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 49:
#line 188 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_minus);
	}
#line 1712 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 50:
#line 191 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_invert);
	}
#line 1720 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 51:
#line 194 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_not);
	}
#line 1728 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 53:
#line 201 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_multiply);
	}
#line 1736 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 54:
#line 204 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_divide);
	}
#line 1744 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 55:
#line 207 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_modulo);
	}
#line 1752 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 57:
#line 214 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_add);
	}
#line 1760 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 58:
#line 217 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_subtract);
	}
#line 1768 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 60:
#line 224 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_left);
	}
#line 1776 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 61:
#line 227 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_right);
	}
#line 1784 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 63:
#line 234 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less);
	}
#line 1792 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 64:
#line 237 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great);
	}
#line 1800 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 65:
#line 240 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less_or_equal);
	}
#line 1808 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 66:
#line 243 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great_or_equal);
	}
#line 1816 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 68:
#line 250 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_equal);
	}
#line 1824 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 69:
#line 253 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_not_equal);
	}
#line 1832 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 71:
#line 260 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_and);
	}
#line 1840 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 73:
#line 267 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_xor);
	}
#line 1848 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 75:
#line 274 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_or);
	}
#line 1856 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 77:
#line 281 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_and);
	}
#line 1864 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 79:
#line 288 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_or);
	}
#line 1872 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 81:
#line 295 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_ternary_op_expr((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]), ast_ternary_op_conditional);
	}
#line 1880 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 84:
#line 306 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_apply_to);
    }
#line 1888 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 85:
#line 309 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[0]), (yyvsp[-1]));
	}
#line 1896 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 86:
#line 312 "proc.la.y" /* yacc.c:1661  */
    {
	    // TODO:  ???
	}
#line 1904 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 87:
#line 315 "proc.la.y" /* yacc.c:1661  */
    {
	    // TODO:
	}
#line 1912 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 89:
#line 322 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = (yyvsp[-1]);
	}
#line 1920 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 90:
#line 325 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_apply_to);
    }
#line 1928 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 91:
#line 333 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1936 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 92:
#line 336 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1944 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 93:
#line 339 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1952 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 94:
#line 342 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[-1]), (yyvsp[0]));
    }
#line 1960 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 95:
#line 348 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_1to1);
    }
#line 1968 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 96:
#line 351 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_reduce);
    }
#line 1976 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 97:
#line 354 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_expand);
    }
#line 1984 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 98:
#line 357 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_inject);
    }
#line 1992 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 105:
#line 374 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_block(ast_create_stmt_address((yyvsp[-2])), (yyvsp[0]));
	}
#line 2000 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 106:
#line 380 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block(ast_create_case((yyvsp[-2])), (yyvsp[0]));
    }
#line 2008 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 107:
#line 383 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block(ast_create_case(null), (yyvsp[0]));
    }
#line 2016 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 108:
#line 389 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_block((yyvsp[-1]), (yyvsp[0]));
    }
#line 2024 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 110:
#line 396 "proc.la.y" /* yacc.c:1661  */
    {
        // This is also a empty map.
	    //$$ = ast_close_block(ast_create_block(null, null));
	    (yyval) = ast_create_none();
	}
#line 2034 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 111:
#line 401 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_close_block((yyvsp[-1]));
	}
#line 2042 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 113:
#line 408 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_block((yyvsp[-1]), (yyvsp[0]));
	}
#line 2050 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 117:
#line 420 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_switch((yyvsp[-4]), ast_close_block((yyvsp[-1])));
	}
#line 2058 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 125:
#line 461 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 2066 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 126:
#line 464 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[0]), null);
    }
#line 2074 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 128:
#line 481 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 2082 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 129:
#line 484 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    }
#line 2091 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 130:
#line 491 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 2099 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 131:
#line 494 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-1]), (yyvsp[0]), null);
    }
#line 2107 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 132:
#line 497 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-1]), (yyvsp[0]));
    }
#line 2115 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 133:
#line 500 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[0]), null);
    }
#line 2123 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 134:
#line 506 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-2]), (yyvsp[-4]), (yyvsp[-1]));
    }
#line 2131 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 135:
#line 512 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-1]), (yyvsp[-3]), (yyvsp[-5]));
    }
#line 2139 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 138:
#line 523 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[-1]), (yyvsp[0]));
    }
#line 2147 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 139:
#line 526 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[0]), null);
    }
#line 2155 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 141:
#line 536 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la((yyvsp[-1]), (yyvsp[0]));
    }
#line 2163 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 142:
#line 539 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[0]));
    }
#line 2171 "proc.la.y.c" /* yacc.c:1661  */
    break;


#line 2175 "proc.la.y.c" /* yacc.c:1661  */
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
#line 544 "proc.la.y" /* yacc.c:1906  */


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
