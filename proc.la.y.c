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
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
      78,    79,    80,    84,    85,    91,    92,    96,   101,   102,
     106,   107,   113,   114,   118,   119,   122,   127,   128,   129,
     130,   137,   146,   149,   157,   158,   161,   164,   170,   173,
     176,   179,   185,   186,   189,   192,   198,   199,   202,   208,
     209,   212,   218,   219,   222,   225,   228,   234,   235,   238,
     244,   245,   251,   252,   258,   259,   265,   266,   272,   273,
     279,   280,   286,   290,   291,   292,   296,   297,   298,   304,
     305,   306,   307,   311,   312,   313,   314,   335,   336,   337,
     338,   339,   340,   344,   348,   349,   353,   354,   358,   363,
     369,   370,   377,   381,   382,   383,   387,   388,   398,   399,
     400,   408,   409,   422,   425,   431,   442,   445,   455,   461,
     467,   470,   476,   482,   488,   489,   493,   496,   502,   506,
     509
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

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     176,    60,    54,  -121,  -121,  -121,  -121,    36,    36,    76,
      26,    99,  -121,    36,  -121,   100,   107,     3,   170,    63,
      10,  -121,   105,   128,   131,   166,   144,  -121,  -121,  -121,
    -121,   378,   378,   168,   169,   188,   147,   164,   261,   184,
     357,    63,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,    -5,  -121,    96,  -121,   378,
      34,   -51,     5,    65,   142,   175,   178,   185,   233,    23,
    -121,  -121,    14,  -121,  -121,  -121,  -121,   207,  -121,  -121,
    -121,  -121,   208,  -121,   378,   -45,   133,    39,  -121,   105,
    -121,  -121,   153,  -121,  -121,  -121,  -121,   186,   378,   378,
    -121,   378,  -121,   126,   133,    51,     8,   378,   378,  -121,
    -121,  -121,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   368,  -121,  -121,  -121,  -121,  -121,  -121,   283,  -121,
    -121,   386,   212,  -121,   378,   378,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,   136,   150,  -121,    32,  -121,
    -121,  -121,  -121,   122,   154,   160,  -121,   378,   378,  -121,
     378,    38,    22,  -121,  -121,  -121,    34,    34,   -51,   -51,
       5,     5,     5,     5,    65,    65,   142,   175,   178,   185,
     233,   228,   187,  -121,  -121,  -121,   206,  -121,  -121,   133,
    -121,  -121,  -121,  -121,  -121,   386,   261,   214,   261,   133,
     280,   133,  -121,  -121,   378,  -121,  -121,   236,   145,  -121,
     378,  -121,   261,   378,   229,  -121,   -40,   133,  -121,   302,
     261,  -121,  -121,   261,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   138,   135,   134,   137,   140,     0,     0,
       0,     0,   136,   139,     1,     0,     0,     0,     0,     0,
       0,   125,   131,     0,     0,     0,    21,    16,    17,    18,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,    48,    49,    50,    51,    86,    22,    19,
      20,    34,    37,    38,    39,    40,    41,    44,    52,     0,
      56,    59,    62,    67,    70,    72,    74,    76,    78,    80,
      82,    83,     0,    99,   112,    97,    98,     0,   110,   100,
     101,   102,    21,    31,     0,     0,    32,     0,   130,   129,
     132,   133,     0,    45,    46,   120,   119,     0,     0,     0,
     116,     0,    24,     0,    25,     0,     0,     0,     0,    42,
      43,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    87,    85,     0,   109,
     111,     0,     0,    30,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,   127,   121,   122,   124,     0,   128,
     103,    14,   118,     0,     0,     0,    23,     0,     0,    27,
       0,     0,     0,    53,    54,    55,    57,    58,    61,    60,
      65,    66,    63,    64,    68,    69,    71,    73,    75,    77,
      79,     0,     0,    84,    91,    89,    39,    92,    90,    33,
      10,    11,    12,    13,   126,     0,     0,     0,     0,    26,
       0,    28,    35,    36,     0,    88,   123,   113,     0,   117,
       0,    81,     0,     0,     0,   107,     0,    29,   114,     0,
       0,   115,   106,     0,   105,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   -13,  -121,  -121,  -121,  -121,   -22,  -121,   106,   123,
       7,   121,   179,   177,   167,   180,   181,  -121,    81,  -120,
     -20,  -121,  -121,  -121,   -37,  -121,    80,  -121,   -15,  -121,
     232,  -121,  -121,  -121,   -84,  -121,  -121,   222,   189,  -121,
    -121,    -1,   307,  -121,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   155,   156,    48,    49,    50,    51,    52,   103,    53,
     105,    54,    85,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,   137,   138,    74,    75,   225,   226,    76,    77,
      78,    79,    80,    81,   161,   158,    23,    88,    24,     4,
       5,     6,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   100,    22,   157,    21,   223,    12,   224,    89,    93,
      94,   193,    12,    82,    27,    28,    29,    30,   197,   143,
     104,   106,   115,   116,   144,   193,   131,   132,   133,   134,
     135,   231,   131,   132,   133,   134,   135,   111,   117,   118,
     145,   132,   133,   134,   135,    31,    32,   146,   147,   148,
     149,   150,   151,   152,   153,   160,   145,   132,   133,   134,
     135,   129,   107,    10,   142,   108,    26,    27,    28,    29,
      30,   170,    11,    19,    83,    20,    14,    40,   163,   164,
      84,   165,    20,    43,    44,    45,    46,   171,   172,    15,
     173,   174,   175,   213,   136,     1,   204,     2,    31,    32,
     136,   205,    16,   154,   119,   120,   212,    33,   130,    34,
     191,   112,   113,   114,    35,    36,    37,    17,    38,    39,
     168,   216,   169,    22,   199,   196,   180,   181,   182,   183,
      40,   109,   110,    41,    42,    20,    43,    44,    45,    46,
     145,   132,   133,   134,   135,   121,   122,   209,   210,    47,
     211,   145,   132,   133,   134,   135,    26,    27,    28,    29,
      30,   146,   147,   148,   149,   150,   151,   152,   153,   217,
      18,   219,   145,   132,   133,   134,   135,    87,   145,   132,
     133,   134,   135,   123,   124,   228,   206,    25,    31,    32,
     223,    97,   224,   234,   166,   167,   235,    33,    19,    34,
     227,   200,   201,   229,    35,    36,    37,    92,    38,    39,
      26,    27,    28,    29,    30,   202,   203,    90,   207,    98,
      40,   176,   177,    41,   208,    20,    43,    44,    45,    46,
     145,   132,   133,   134,   135,     1,    99,     2,     3,    47,
     178,   179,    31,    32,   184,   185,   145,   132,   133,   134,
     135,    33,    91,    34,    95,    96,   101,   125,    35,    36,
      37,   126,    38,    39,    26,    27,    28,    29,    30,   127,
     128,   141,   162,   215,    40,   170,  -125,    41,   139,    20,
      43,    44,    45,    46,   218,   222,    82,    27,    28,    29,
      30,   214,   230,    47,   188,   221,    31,    32,   145,   132,
     133,   134,   135,   187,   186,    33,   232,    34,   189,   140,
     190,   159,    35,    36,    37,    13,    38,    39,    31,    32,
     145,   132,   133,   134,   135,     0,     0,   198,    40,     0,
       0,    41,     0,    20,    43,    44,    45,    46,     0,     0,
       0,   194,     0,   220,   195,     0,     0,    47,     0,     0,
      40,     0,     0,    41,     0,    20,    43,    44,    45,    46,
      82,    27,    28,    29,    30,   233,     0,     0,     0,     0,
       0,    82,    27,    28,    29,    30,     0,     0,     0,     0,
       0,    82,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,    31,    32,   146,   147,   148,   149,   150,   151,
     152,   153,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,   102,   192,    84,     0,    20,
      43,    44,    45,    46,     0,    40,     0,     0,    84,     0,
      20,    43,    44,    45,    46,    40,     0,     0,    84,     0,
      20,    43,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      20,    38,    17,    87,    17,    45,     7,    47,    23,    31,
      32,   131,    13,     3,     4,     5,     6,     7,   138,    64,
      40,    41,    73,    74,    69,   145,    18,    19,    20,    21,
      22,    71,    18,    19,    20,    21,    22,    59,    33,    34,
      18,    19,    20,    21,    22,    35,    36,     8,     9,    10,
      11,    12,    13,    14,    15,    92,    18,    19,    20,    21,
      22,    38,    67,     3,    84,    70,     3,     4,     5,     6,
       7,    63,    18,    70,    64,    72,     0,    67,    98,    99,
      70,   101,    72,    73,    74,    75,    76,   107,   108,    63,
     112,   113,   114,    71,    86,    59,    64,    61,    35,    36,
      86,    69,     3,    64,    39,    40,    68,    44,    85,    46,
     130,    77,    78,    79,    51,    52,    53,    17,    55,    56,
      69,   205,    71,   138,   144,   138,   119,   120,   121,   122,
      67,    35,    36,    70,    71,    72,    73,    74,    75,    76,
      18,    19,    20,    21,    22,    80,    81,   167,   168,    86,
     170,    18,    19,    20,    21,    22,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   206,
      63,   208,    18,    19,    20,    21,    22,    72,    18,    19,
      20,    21,    22,    41,    42,   222,    64,    17,    35,    36,
      45,     3,    47,   230,    68,    69,   233,    44,    70,    46,
     220,    65,    66,   223,    51,    52,    53,    63,    55,    56,
       3,     4,     5,     6,     7,    65,    66,    86,    64,    72,
      67,   115,   116,    70,    64,    72,    73,    74,    75,    76,
      18,    19,    20,    21,    22,    59,    72,    61,    62,    86,
     117,   118,    35,    36,   123,   124,    18,    19,    20,    21,
      22,    44,    86,    46,    86,    86,    72,    82,    51,    52,
      53,    83,    55,    56,     3,     4,     5,     6,     7,    84,
      37,    63,    86,    86,    67,    63,    70,    70,    71,    72,
      73,    74,    75,    76,    70,    49,     3,     4,     5,     6,
       7,    63,    63,    86,   127,   214,    35,    36,    18,    19,
      20,    21,    22,   126,   125,    44,   226,    46,   128,    77,
     129,    89,    51,    52,    53,     8,    55,    56,    35,    36,
      18,    19,    20,    21,    22,    -1,    -1,   138,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    58,    -1,    63,    61,    -1,    -1,    86,    -1,    -1,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
       3,     4,     5,     6,     7,    63,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    58,    70,    -1,    72,
      73,    74,    75,    76,    -1,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    61,    62,   136,   137,   138,   139,   140,   141,
       3,    18,   138,   139,     0,    63,     3,    17,    63,    70,
      72,    98,   125,   133,   135,    17,     3,     4,     5,     6,
       7,    35,    36,    44,    46,    51,    52,    53,    55,    56,
      67,    70,    71,    73,    74,    75,    76,    86,    90,    91,
      92,    93,    94,    96,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   121,   122,   125,   126,   127,   128,
     129,   130,     3,    64,    70,    99,   117,    72,   134,   125,
      86,    86,    63,   103,   103,    86,    86,     3,    72,    72,
     121,    72,    68,    95,   117,    97,   117,    67,    70,    35,
      36,   103,    77,    78,    79,    73,    74,    33,    34,    39,
      40,    80,    81,    41,    42,    82,    83,    84,    37,    38,
      85,    18,    19,    20,    21,    22,    86,   119,   120,    71,
     127,    63,   117,    64,    69,    18,     8,     9,    10,    11,
      12,    13,    14,    15,    64,    88,    89,   131,   132,   134,
     121,   131,    86,   117,   117,   117,    68,    69,    69,    71,
      63,   117,   117,   103,   103,   103,   105,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   110,   111,   112,
     113,   117,    58,   116,    58,    61,    98,   116,   135,   117,
      65,    66,    65,    66,    64,    69,    64,    64,    64,   117,
     117,   117,    68,    71,    63,    86,   131,   121,    70,   121,
      63,   115,    49,    45,    47,   123,   124,   117,   121,   117,
      63,    71,   123,    63,   121,   121
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
     115,   115,   116,   117,   117,   117,   118,   118,   118,   119,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   128,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   134,   134,   135,   135,
     135,   135,   136,   137,   138,   138,   139,   139,   140,   141,
     141
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
       1,     5,     1,     1,     3,     2,     1,     2,     4,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     2,     3,
       1,     2,     1,     5,     7,     7,     2,     5,     3,     2,
       2,     1,     1,     3,     1,     1,     3,     2,     3,     2,
       2,     1,     6,     6,     1,     1,     2,     1,     1,     2,
       1
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
#line 1506 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 11:
#line 49 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1514 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 12:
#line 52 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_list);
    }
#line 1522 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 13:
#line 55 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_combined_type((yyvsp[-1]), ast_type_map);
    }
#line 1530 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 14:
#line 61 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_declare((yyvsp[0]), (yyvsp[-2]));
    }
#line 1538 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 24:
#line 85 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1546 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 31:
#line 107 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_none();
    }
#line 1554 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 35:
#line 119 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_list_access);
    }
#line 1562 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 36:
#line 122 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[-3]), (yyvsp[-1]), ast_binary_op_map_access);
    }
#line 1570 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 42:
#line 146 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_inc_f);
	}
#line 1578 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 43:
#line 149 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[-1]), ast_unary_op_dec_l);
	}
#line 1586 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 45:
#line 158 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_inc_f);
    }
#line 1594 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 46:
#line 161 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[0]), ast_unary_op_dec_f);
    }
#line 1602 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 47:
#line 164 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_unary_op_expr_ex((yyvsp[0]), (yyvsp[-1]));
    }
#line 1610 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 48:
#line 170 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_plus);
	}
#line 1618 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 49:
#line 173 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_minus);
	}
#line 1626 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 50:
#line 176 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_invert);
	}
#line 1634 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 51:
#line 179 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_not);
	}
#line 1642 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 53:
#line 186 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_multiply);
	}
#line 1650 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 54:
#line 189 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_divide);
	}
#line 1658 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 55:
#line 192 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_modulo);
	}
#line 1666 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 57:
#line 199 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_add);
	}
#line 1674 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 58:
#line 202 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_subtract);
	}
#line 1682 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 60:
#line 209 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_left);
	}
#line 1690 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 61:
#line 212 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_shift_right);
	}
#line 1698 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 63:
#line 219 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less);
	}
#line 1706 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 64:
#line 222 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great);
	}
#line 1714 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 65:
#line 225 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_less_or_equal);
	}
#line 1722 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 66:
#line 228 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_great_or_equal);
	}
#line 1730 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 68:
#line 235 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_equal);
	}
#line 1738 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 69:
#line 238 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_not_equal);
	}
#line 1746 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 71:
#line 245 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_and);
	}
#line 1754 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 73:
#line 252 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_xor);
	}
#line 1762 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 75:
#line 259 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_bit_or);
	}
#line 1770 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 77:
#line 266 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_and);
	}
#line 1778 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 79:
#line 273 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[-2]), (yyvsp[0]), ast_binary_op_or);
	}
#line 1786 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 81:
#line 280 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = ast_create_ternary_op_expr((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]), ast_ternary_op_conditional);
	}
#line 1794 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 108:
#line 358 "proc.la.y" /* yacc.c:1661  */
    {
        // TODO: refine the function
        // This is also a empty map.
	    (yyval) = ast_create_block(null, null);
	}
#line 1804 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 109:
#line 363 "proc.la.y" /* yacc.c:1661  */
    {
	    (yyval) = (yyvsp[-1]);
	}
#line 1812 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 111:
#line 370 "proc.la.y" /* yacc.c:1661  */
    {
	    // TODO: refine the function
	    (yyval) = ast_create_block((yyvsp[-1]), (yyvsp[0]));
	}
#line 1821 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 123:
#line 422 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[-2]), (yyvsp[0]));
    }
#line 1829 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 124:
#line 425 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_type_list((yyvsp[0]), null);
    }
#line 1837 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 126:
#line 442 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = (yyvsp[-1]);
    }
#line 1845 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 127:
#line 445 "proc.la.y" /* yacc.c:1661  */
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    }
#line 1854 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 128:
#line 455 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1862 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 129:
#line 461 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration((yyvsp[-1]), (yyvsp[0]), null);
    }
#line 1870 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 130:
#line 467 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1878 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 131:
#line 470 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[0]), null);
    }
#line 1886 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 132:
#line 476 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-2]), (yyvsp[-4]), (yyvsp[-1]));
    }
#line 1894 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 133:
#line 482 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[-1]), (yyvsp[-3]), (yyvsp[-5]));
    }
#line 1902 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 136:
#line 493 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[-1]), (yyvsp[0]));
    }
#line 1910 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 137:
#line 496 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_external_declarations((yyvsp[0]), null);
    }
#line 1918 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 139:
#line 506 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la((yyvsp[-1]), (yyvsp[0]));
    }
#line 1926 "proc.la.y.c" /* yacc.c:1661  */
    break;

  case 140:
#line 509 "proc.la.y" /* yacc.c:1661  */
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[0]));
    }
#line 1934 "proc.la.y.c" /* yacc.c:1661  */
    break;


#line 1938 "proc.la.y.c" /* yacc.c:1661  */
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
#line 514 "proc.la.y" /* yacc.c:1906  */


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
