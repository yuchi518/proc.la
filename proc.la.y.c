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
    IS = 310,
    OUT = 311,
    DECLARE = 312,
    SYNC = 313,
    DOMAIN_NAME = 314,
    PACKAGE_NAME = 315
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

#line 183 "proc.la.y.c" /* yacc.c:358  */

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
#define YYLAST   628

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    75,    78,     2,
      63,    64,    73,    69,    83,    70,     2,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      76,     2,    77,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    80,    68,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    32,    32,    33,    34,    35,    36,    37,    38,    39,
      43,    46,    49,    52,    59,    60,    61,    62,    67,    68,
      69,    70,    74,    75,    76,    80,    86,    87,    88,    91,
      92,    98,    99,   100,   101,   105,   106,   107,   108,   112,
     113,   114,   115,   119,   120,   121,   125,   126,   127,   131,
     132,   133,   134,   135,   139,   140,   141,   145,   146,   150,
     151,   155,   156,   160,   161,   165,   166,   170,   171,   175,
     179,   180,   181,   185,   186,   190,   191,   195,   196,   197,
     199,   200,   204,   205,   206,   207,   208,   214,   215,   219,
     220,   221,   222,   228,   232,   233,   237,   243,   244,   245,
     246,   247,   248,   252,   256,   257,   261,   262,   266,   270,
     276,   277,   284,   285,   289,   290,   291,   295,   296,   297,
     298,   299,   300,   304,   305,   306,   314,   315,   319,   325,
     328,   334,   337,   343,   346,   353,   356,   363,   366,   369,
     372,   375,   378,   381,   387,   393,   399,   400,   404,   407,
     413,   417,   420
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
  "DEFAULT", "DO", "ELSE", "FOR", "GOTO", "IF", "SWITCH", "WHILE", "IS",
  "OUT", "DECLARE", "SYNC", "DOMAIN_NAME", "PACKAGE_NAME", "\"[]\"",
  "\"{}\"", "'('", "')'", "'['", "']'", "'{'", "'}'", "'+'", "'-'", "'~'",
  "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'?'",
  "':'", "','", "';'", "$accept", "basic_var_type_specifier",
  "combined_var_type_specifier", "primary_expression", "value_expression",
  "constant", "string", "postfix_expression", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression",
  "container_expression", "list_initializer_list", "map_initializer_list",
  "expression", "expression_statement", "la_statement", "pipe_op",
  "declaration", "init_declarator", "declarator", "statement",
  "labeled_statement", "case_statement", "cases_block_statement",
  "compound_statement", "block_item_list", "block_item",
  "selection_statement", "iteration_statement", "jump_statement",
  "var_type_specifier", "var_declaration", "var_list_declaration",
  "type_list_declaration", "la_input_declaration", "la_output_declaration",
  "la_body_declaration", "la_declaration", "la_alias",
  "external_declaration", "external_declaration_list", "package_declare",
  "a_proc_la", YY_NULLPTR
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
     315,   316,   317,    40,    41,    91,    93,   123,   125,    43,
      45,   126,    33,    42,    47,    37,    60,    62,    38,    94,
     124,    63,    58,    44,    59
};
# endif

#define YYPACT_NINF -222

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-222)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     179,    59,    15,  -222,  -222,  -222,  -222,    16,    16,    65,
      -2,    88,  -222,    16,  -222,    81,    21,    77,    92,    31,
     198,    29,    -3,    51,    58,    32,  -222,  -222,   -28,    73,
    -222,  -222,  -222,  -222,    36,    36,    78,    87,   302,   118,
     209,   159,   161,   169,   394,   464,   198,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,    76,  -222,    36,   218,
      60,   175,    20,   217,   162,   156,   163,   225,     7,  -222,
    -222,   229,    -1,  -222,  -222,   180,  -222,  -222,  -222,  -222,
     250,  -222,  -222,  -222,  -222,  -222,   232,   564,  -222,   206,
     232,  -222,  -222,   178,  -222,   294,   113,  -222,   486,  -222,
    -222,  -222,  -222,   230,  -222,   245,   322,   239,   486,   486,
     486,  -222,   308,    10,  -222,    94,   234,   -30,  -222,  -222,
     486,   486,  -222,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,   486,   294,    13,  -222,  -222,  -222,  -222,    36,  -222,
     112,    77,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,   158,   210,  -222,   -27,   312,
    -222,  -222,  -222,  -222,   302,   268,    32,   372,   372,  -222,
      30,   196,   341,   234,   329,  -222,     3,  -222,   464,   464,
    -222,   308,   476,   256,  -222,  -222,  -222,   218,   218,    60,
      60,   175,   175,   175,   175,    20,    20,   217,   162,   156,
     163,   225,   483,  -222,  -222,   249,  -222,   251,   252,    77,
    -222,   208,  -222,  -222,  -222,  -222,  -222,   178,   232,   486,
     410,   448,   302,   273,   302,  -222,  -222,   259,  -222,  -222,
      36,  -222,  -222,  -222,   208,  -222,  -222,  -222,   488,   302,
     519,   302,   525,   293,   111,  -222,   464,  -222,  -222,   260,
    -222,   302,  -222,   302,   302,   147,   261,  -222,   127,  -222,
    -222,  -222,  -222,  -222,  -222,   147,   263,  -222,  -222,   302,
    -222,  -222,   283,   302,  -222,  -222,  -222
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   150,   147,   146,   149,   152,     0,     0,
       0,     0,   148,   151,     1,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,   134,   130,     0,    14,
      23,    24,    25,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,    35,    36,
      37,    38,    82,    26,    15,    16,    31,    39,     0,    43,
      46,    49,    54,    57,    59,    61,    63,    65,    67,    69,
      70,    77,     0,    99,   112,     0,    95,   113,    97,    98,
       0,   110,   100,   101,   102,    96,     0,     0,   142,     0,
     140,   144,   145,     0,   133,     0,     0,    14,     0,    32,
      33,   125,   124,    14,    77,     0,     0,     0,     0,     0,
       0,    79,     0,     0,    73,     0,    16,     0,    29,    30,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    83,
       0,     0,    93,   109,   111,   141,     2,     3,     4,     5,
       6,     7,     8,     9,   136,   126,   127,   132,     0,   139,
     138,   128,   129,   103,     0,     0,    14,     0,     0,   123,
       0,     0,     0,     0,     0,    17,     0,    71,     0,     0,
      72,     0,     0,     0,    40,    41,    42,    44,    45,    48,
      47,    52,    53,    50,    51,    55,    56,    58,    60,    62,
      64,    66,     0,    94,    81,     0,    78,     0,     0,     0,
      80,     0,    10,    11,    12,    13,   135,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,     0,    27,    28,
       0,    84,    85,    86,     0,    87,   131,   137,     0,     0,
       0,     0,     0,   115,     0,   117,     0,    68,    88,     0,
     119,     0,   121,     0,     0,     0,     0,   107,     0,    76,
     118,   120,   122,   114,    18,     0,     0,    19,    20,     0,
     116,   106,     0,     0,   105,    21,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,  -222,    74,  -221,   -44,  -222,   -23,  -222,
     154,   155,   157,   176,   215,   227,   228,   231,   240,  -222,
     128,   233,   -19,  -222,  -222,   -31,   -92,   310,  -140,   277,
    -222,   242,   -38,  -222,   120,  -222,   -13,  -222,   315,  -222,
    -222,  -222,   -81,   -11,  -222,  -222,  -222,   -83,   -12,  -222,
    -222,    50,   382,  -222,  -222
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   165,   166,    53,   276,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   104,   115,   117,    72,    73,   186,   151,    74,
      75,    76,    77,    78,   267,   268,    79,    80,    81,    82,
      83,    84,   171,    85,    28,   168,    22,    88,   220,     4,
       5,     6,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     105,    71,   116,   155,    21,    23,   167,   170,    27,    90,
     219,    99,   100,   113,   177,    89,   214,   143,   144,   145,
     146,   147,   144,   145,   146,   147,   114,    71,   184,   144,
     145,   146,   147,    11,    25,   122,    94,   226,   190,    97,
      30,    31,    32,    33,   277,   140,   219,    86,   184,   144,
     145,   146,   147,   191,   277,    95,   227,    12,   173,   130,
     131,    71,    10,    12,    20,    14,    19,   113,   183,   215,
      20,    34,    35,     1,   185,     2,   169,   180,   181,   182,
      15,   245,   148,   149,   172,   230,   231,    71,   141,   192,
     193,    16,    87,   148,   232,    26,   132,   133,    17,    98,
     194,   195,   196,    18,   258,    48,    49,    50,    51,    24,
     212,   118,   119,   148,    93,   217,   103,    30,    31,    32,
      33,   156,   157,   158,   159,   160,   161,   162,   163,   126,
     127,   144,   145,   146,   147,    91,   173,    21,    21,   221,
      19,   120,    92,   121,    20,   247,   246,   237,    34,    35,
     274,    30,    31,    32,    33,    96,   265,    36,   266,    37,
     187,    38,   101,    39,    40,    41,    42,    43,   218,   235,
     236,   102,   265,    21,   266,    19,    44,   188,    45,    20,
      46,   106,    48,    49,    50,    51,   156,   157,   158,   159,
     160,   161,   162,   163,   253,   280,   255,    52,   248,   250,
     252,    29,    30,    31,    32,    33,    21,   244,   128,   129,
     275,   260,   107,   262,   184,   144,   145,   146,   147,   222,
     223,   278,   108,   271,   109,   272,   273,   144,   145,   146,
     147,   278,   110,    34,    35,   137,     1,   269,     2,     3,
     136,   284,    36,   138,    37,   286,    38,   142,    39,    40,
      41,    42,    43,    29,    30,    31,    32,    33,   134,   135,
     233,    44,   139,    45,   152,    46,    47,    48,    49,    50,
      51,   224,   225,    20,   184,   144,   145,   146,   147,   148,
     197,   198,    52,   199,   200,    34,    35,   201,   202,   203,
     204,   123,   124,   125,    36,    87,    37,    25,    38,   175,
      39,    40,    41,    42,    43,   103,    30,    31,    32,    33,
     205,   206,   174,    44,    32,    45,   189,    46,   153,    48,
      49,    50,    51,   179,   239,   176,    30,    31,    32,    33,
     228,   229,   214,   241,    52,   242,   243,    34,    35,   148,
     254,   256,   264,   279,   270,   283,    36,   285,    37,   282,
      38,   207,    39,    40,    41,    42,    43,    34,    35,   184,
     144,   145,   146,   147,   208,    44,   209,    45,   257,    46,
     210,    48,    49,    50,    51,    97,    30,    31,    32,    33,
     211,   216,   150,   178,   213,    44,    52,    45,   281,   112,
      13,    48,    49,    50,    51,   154,     0,    97,    30,    31,
      32,    33,     0,     0,     0,   234,    52,    34,    35,     0,
       0,     0,     0,    97,    30,    31,    32,    33,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,    44,     0,    45,     0,   112,
       0,    48,    49,    50,    51,    34,    35,     0,     0,     0,
       0,    97,    30,    31,    32,    33,    52,    44,   111,    45,
       0,   112,     0,    48,    49,    50,    51,    97,    30,    31,
      32,    33,     0,    44,   249,    45,     0,   112,     0,    48,
      49,    50,    51,    34,    35,     0,     0,     0,     0,    97,
      30,    31,    32,    33,   184,   144,   145,   146,   147,    34,
      35,   184,   144,   145,   146,   147,   184,   144,   145,   146,
     147,    44,   251,    45,     0,   112,     0,    48,    49,    50,
      51,    34,    35,     0,     0,     0,     0,    98,     0,    45,
       0,   112,     0,    48,    49,    50,    51,   184,   144,   145,
     146,   147,   238,   184,   144,   145,   146,   147,     0,    44,
       0,    45,   259,   112,     0,    48,    49,    50,    51,   148,
       0,     0,     0,     0,     0,   240,   148,     0,     0,     0,
       0,   148,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,   261,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164
};

static const yytype_int16 yycheck[] =
{
      38,    20,    46,    86,    17,    17,    87,    90,    19,    22,
     150,    34,    35,    44,   106,    18,     3,    18,    19,    20,
      21,    22,    19,    20,    21,    22,    45,    46,    18,    19,
      20,    21,    22,    18,     3,    58,    64,    64,    68,     3,
       4,     5,     6,     7,   265,    38,   186,    18,    18,    19,
      20,    21,    22,    83,   275,    83,    83,     7,    96,    39,
      40,    80,     3,    13,    67,     0,    63,    98,   112,    56,
      67,    35,    36,    57,    64,    59,    89,   108,   109,   110,
      82,   221,    83,    84,    95,   177,   178,   106,    81,   120,
     121,     3,    63,    83,    64,    64,    76,    77,    17,    63,
     123,   124,   125,    82,   244,    69,    70,    71,    72,    17,
     141,    35,    36,    83,    82,     3,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    69,
      70,    19,    20,    21,    22,    84,   174,   150,   151,   151,
      63,    65,    84,    67,    67,   228,   227,   191,    35,    36,
       3,     4,     5,     6,     7,    82,    45,    44,    47,    46,
      66,    48,    84,    50,    51,    52,    53,    54,    56,   188,
     189,    84,    45,   186,    47,    63,    63,    83,    65,    67,
      67,    63,    69,    70,    71,    72,     8,     9,    10,    11,
      12,    13,    14,    15,   232,    68,   234,    84,   229,   230,
     231,     3,     4,     5,     6,     7,   219,   219,    33,    34,
      63,   249,     3,   251,    18,    19,    20,    21,    22,    61,
      62,   265,    63,   261,    63,   263,   264,    19,    20,    21,
      22,   275,    63,    35,    36,    79,    57,   256,    59,    60,
      78,   279,    44,    80,    46,   283,    48,    18,    50,    51,
      52,    53,    54,     3,     4,     5,     6,     7,    41,    42,
      64,    63,    37,    65,    84,    67,    68,    69,    70,    71,
      72,    61,    62,    67,    18,    19,    20,    21,    22,    83,
     126,   127,    84,   128,   129,    35,    36,   130,   131,   132,
     133,    73,    74,    75,    44,    63,    46,     3,    48,    54,
      50,    51,    52,    53,    54,     3,     4,     5,     6,     7,
     134,   135,    82,    63,     6,    65,    82,    67,    68,    69,
      70,    71,    72,    84,    68,     3,     4,     5,     6,     7,
      18,    63,     3,    84,    84,    84,    84,    35,    36,    83,
      67,    82,    49,    82,    84,    82,    44,    64,    46,   275,
      48,   136,    50,    51,    52,    53,    54,    35,    36,    18,
      19,    20,    21,    22,   137,    63,   138,    65,   240,    67,
     139,    69,    70,    71,    72,     3,     4,     5,     6,     7,
     140,   148,    72,   106,   142,    63,    84,    65,   268,    67,
       8,    69,    70,    71,    72,    80,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    64,    84,    35,    36,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    72,    35,    36,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    84,    63,    64,    65,
      -1,    67,    -1,    69,    70,    71,    72,     3,     4,     5,
       6,     7,    -1,    63,    64,    65,    -1,    67,    -1,    69,
      70,    71,    72,    35,    36,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    18,    19,    20,    21,    22,    35,
      36,    18,    19,    20,    21,    22,    18,    19,    20,    21,
      22,    63,    64,    65,    -1,    67,    -1,    69,    70,    71,
      72,    35,    36,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    67,    -1,    69,    70,    71,    72,    18,    19,    20,
      21,    22,    66,    18,    19,    20,    21,    22,    -1,    63,
      -1,    65,    64,    67,    -1,    69,    70,    71,    72,    83,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    83,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    59,    60,   134,   135,   136,   137,   138,   139,
       3,    18,   136,   137,     0,    82,     3,    17,    82,    63,
      67,   121,   131,   133,    17,     3,    64,   128,   129,     3,
       4,     5,     6,     7,    35,    36,    44,    46,    48,    50,
      51,    52,    53,    54,    63,    65,    67,    68,    69,    70,
      71,    72,    84,    88,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   110,   111,   114,   115,   116,   117,   118,   121,
     122,   123,   124,   125,   126,   128,    18,    63,   132,    18,
     121,    84,    84,    82,    64,    83,    82,     3,    63,    93,
      93,    84,    84,     3,   107,   117,    63,     3,    63,    63,
      63,    64,    67,   110,   107,   108,    91,   109,    35,    36,
      65,    67,    93,    73,    74,    75,    69,    70,    33,    34,
      39,    40,    76,    77,    41,    42,    78,    79,    80,    37,
      38,    81,    18,    18,    19,    20,    21,    22,    83,    84,
     112,   113,    84,    68,   123,   132,     8,     9,    10,    11,
      12,    13,    14,    15,    64,    86,    87,   127,   130,   121,
     132,   127,   128,   117,    82,    54,     3,   111,   114,    84,
     110,   110,   110,    91,    18,    64,   112,    66,    83,    82,
      68,    83,   110,   110,    93,    93,    93,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    98,    99,   100,   101,
     102,   103,   110,   116,     3,    56,   106,     3,    56,   113,
     133,   133,    61,    62,    61,    62,    64,    83,    18,    63,
     111,   111,    64,    64,    64,   107,   107,    91,    66,    68,
      82,    84,    84,    84,   133,   113,   127,   132,   110,    64,
     110,    64,   110,   117,    67,   117,    82,   105,   113,    64,
     117,    64,   117,    64,    49,    45,    47,   119,   120,   107,
      84,   117,   117,   117,     3,    63,    89,    90,    91,    82,
      68,   119,    89,    82,   117,    64,   117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    90,    90,    90,    91,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   115,   115,   116,   117,   117,   117,
     117,   117,   117,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   127,   127,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   134,   135,   136,   136,   137,   137,
     138,   139,   139
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
       1,     3,     3,     1,     3,     3,     5,     1,     3,     2,
       3,     3,     1,     2,     4,     4,     4,     3,     4,     1,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     2,     3,
       1,     2,     1,     1,     7,     5,     7,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     1,     1,     3,     3,
       1,     3,     1,     3,     2,     3,     2,     5,     3,     3,
       2,     3,     2,     1,     6,     6,     1,     1,     2,     1,
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
#line 43 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1556 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 11:
#line 46 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1564 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 12:
#line 49 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1572 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 13:
#line 52 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1580 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 108:
#line 266 "proc.la.y" /* yacc.c:1661  */
    {
        // TODO: refine the function
	    (yyval) = ast_create_ast_body(null, null);
	}
#line 1589 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 109:
#line 270 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = (yyvsp[-1]);
	}
#line 1597 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 111:
#line 277 "proc.la.y" /* yacc.c:1661  */
    {
	    // TODO: refine the function
	    (yyval) = ast_create_ast_body((yyvsp[-1]), (yyvsp[0]));
	}
#line 1606 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 128:
#line 319 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_declare((yyvsp[0]), (yyvsp[-2]));
    }
#line 1614 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 129:
#line 325 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1622 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 130:
#line 328 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_list((yyvsp[0]), null);
    }
#line 1630 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 131:
#line 334 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1638 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 132:
#line 337 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[0]), null);
    }
#line 1646 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 133:
#line 343 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 1654 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 134:
#line 346 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_var_list(null, null);
    }
#line 1663 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 135:
#line 353 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 1671 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 136:
#line 356 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    }
#line 1680 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 137:
#line 363 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
    }
#line 1688 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 138:
#line 366 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1696 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 139:
#line 369 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[0]), null);
    }
#line 1704 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 140:
#line 372 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-1]), (yyvsp[0]), null);
    }
#line 1712 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 141:
#line 375 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-2]), (yyvsp[0]));
    }
#line 1720 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 142:
#line 378 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1728 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 143:
#line 381 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[0]), null);
    }
#line 1736 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 144:
#line 387 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-2]), (yyvsp[-4]), (yyvsp[-1]));
    }
#line 1744 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 145:
#line 393 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-1]), (yyvsp[-3]), (yyvsp[-5]));
    }
#line 1752 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 148:
#line 404 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[-1]), (yyvsp[0]));
    }
#line 1760 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 149:
#line 407 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[0]), null);
    }
#line 1768 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 151:
#line 417 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la((yyvsp[-1]), (yyvsp[0]));
    }
#line 1776 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 152:
#line 420 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[0]));
    }
#line 1784 "proc.la.y.c" /* yacc.c:1661  */
    break;


#line 1788 "proc.la.y.c" /* yacc.c:1661  */
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
#line 425 "proc.la.y" /* yacc.c:1906  */


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
