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
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     LIST = 273,
     MAP = 274,
     APPLY_TO = 275,
     PIPE_1_TO_1 = 276,
     PIPE_REDUCE = 277,
     PIPE_EXPAND = 278,
     PIPE_INJECT = 279,
     RIGHT_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     ADD_ASSIGN = 282,
     SUB_ASSIGN = 283,
     MUL_ASSIGN = 284,
     DIV_ASSIGN = 285,
     MOD_ASSIGN = 286,
     AND_ASSIGN = 287,
     XOR_ASSIGN = 288,
     OR_ASSIGN = 289,
     RIGHT_OP = 290,
     LEFT_OP = 291,
     INC_OP = 292,
     DEC_OP = 293,
     AND_OP = 294,
     OR_OP = 295,
     LE_OP = 296,
     GE_OP = 297,
     EQ_OP = 298,
     NE_OP = 299,
     AUTO = 300,
     BREAK = 301,
     CASE = 302,
     CONTINUE = 303,
     DEFAULT = 304,
     DO = 305,
     ELSE = 306,
     FOR = 307,
     GOTO = 308,
     IF = 309,
     SWITCH = 310,
     WHILE = 311,
     LOOP = 312,
     EACH = 313,
     IS = 314,
     OUT = 315,
     DECLARE = 316,
     SYNC = 317,
     DOMAIN_NAME = 318,
     PACKAGE_NAME = 319
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define N_CONSTANT 262
#define INT 263
#define LONG 264
#define FLOAT 265
#define DOUBLE 266
#define NUMBER 267
#define STRING 268
#define RAW 269
#define VAR 270
#define PROC 271
#define LA 272
#define LIST 273
#define MAP 274
#define APPLY_TO 275
#define PIPE_1_TO_1 276
#define PIPE_REDUCE 277
#define PIPE_EXPAND 278
#define PIPE_INJECT 279
#define RIGHT_ASSIGN 280
#define LEFT_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define MUL_ASSIGN 284
#define DIV_ASSIGN 285
#define MOD_ASSIGN 286
#define AND_ASSIGN 287
#define XOR_ASSIGN 288
#define OR_ASSIGN 289
#define RIGHT_OP 290
#define LEFT_OP 291
#define INC_OP 292
#define DEC_OP 293
#define AND_OP 294
#define OR_OP 295
#define LE_OP 296
#define GE_OP 297
#define EQ_OP 298
#define NE_OP 299
#define AUTO 300
#define BREAK 301
#define CASE 302
#define CONTINUE 303
#define DEFAULT 304
#define DO 305
#define ELSE 306
#define FOR 307
#define GOTO 308
#define IF 309
#define SWITCH 310
#define WHILE 311
#define LOOP 312
#define EACH 313
#define IS 314
#define OUT 315
#define DECLARE 316
#define SYNC 317
#define DOMAIN_NAME 318
#define PACKAGE_NAME 319




/* Copy the first part of user declarations.  */
#line 1 "proc.la.y"

    #include "ast.h"
    typedef AstNode YYSTYPE;
    #define YYSTYPE_IS_DECLARED     1
    void yyerror (char const *s);
    int yylex();


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 254 "/Users/yuchi/projects/proc.la/autogen/proc.la.y.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   735

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    79,    82,     2,
      72,    66,    77,    73,    67,    74,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    86,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    22,    25,    28,    31,    33,    35,    39,    41,    45,
      47,    49,    51,    53,    55,    57,    59,    61,    65,    69,
      72,    74,    76,    80,    84,    88,    90,    94,   100,   104,
     108,   111,   113,   117,   119,   124,   129,   131,   133,   135,
     137,   139,   142,   145,   147,   150,   153,   156,   158,   160,
     162,   164,   166,   170,   174,   178,   180,   184,   188,   190,
     194,   198,   200,   204,   208,   212,   216,   218,   222,   226,
     228,   232,   234,   238,   240,   244,   246,   250,   252,   256,
     258,   264,   266,   268,   272,   275,   279,   281,   284,   289,
     292,   295,   298,   301,   303,   305,   307,   309,   311,   313,
     315,   317,   319,   321,   325,   328,   332,   337,   341,   344,
     346,   349,   353,   355,   358,   360,   366,   372,   380,   388,
     396,   404,   407,   413,   417,   420,   423,   425,   429,   433,
     436,   440,   443,   446,   448,   455,   462,   464,   466,   469,
     471,   473,   476
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,     8,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,    88,
      18,    -1,    88,    19,    -1,    89,    18,    -1,    89,    19,
      -1,    88,    -1,    89,    -1,    91,    67,    90,    -1,    90,
      -1,     3,    65,    90,    -1,     7,    -1,     4,    -1,     5,
      -1,     6,    -1,    93,    -1,    94,    -1,     3,    -1,    92,
      -1,    68,    97,    69,    -1,    68,     1,    69,    -1,    68,
      69,    -1,    18,    -1,   119,    -1,    97,    67,   119,    -1,
      70,    99,    71,    -1,    70,     1,    71,    -1,    19,    -1,
     119,    65,   119,    -1,    99,    67,   119,    65,   119,    -1,
      72,   101,    66,    -1,    72,     1,    66,    -1,    72,    66,
      -1,   119,    -1,   101,    67,   119,    -1,    95,    -1,   102,
      68,   119,    69,    -1,   102,    70,   119,    71,    -1,    96,
      -1,    98,    -1,   100,    -1,   102,    -1,   103,    -1,   104,
      37,    -1,   104,    38,    -1,   104,    -1,    37,   105,    -1,
      38,   105,    -1,   106,   105,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,   105,    -1,   107,    77,   105,    -1,
     107,    78,   105,    -1,   107,    79,   105,    -1,   107,    -1,
     108,    73,   107,    -1,   108,    74,   107,    -1,   108,    -1,
     109,    36,   108,    -1,   109,    35,   108,    -1,   109,    -1,
     110,    80,   109,    -1,   110,    81,   109,    -1,   110,    41,
     109,    -1,   110,    42,   109,    -1,   110,    -1,   111,    43,
     110,    -1,   111,    44,   110,    -1,   111,    -1,   112,    82,
     111,    -1,   112,    -1,   113,    83,   112,    -1,   113,    -1,
     114,    84,   113,    -1,   114,    -1,   115,    39,   114,    -1,
     115,    -1,   116,    40,   115,    -1,   116,    -1,   116,    85,
     119,    65,   117,    -1,   117,    -1,   118,    -1,   119,    20,
     118,    -1,   119,   121,    -1,   119,    59,    90,    -1,    86,
      -1,   119,    86,    -1,   119,    20,    60,    86,    -1,   122,
      63,    -1,   122,   135,    -1,   122,    60,    -1,   122,   118,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,   124,
      -1,   127,    -1,   120,    -1,   130,    -1,   131,    -1,   132,
      -1,    62,     3,    86,    -1,     1,    86,    -1,     3,    65,
     123,    -1,    47,   119,    65,   123,    -1,    49,    65,   123,
      -1,   126,   125,    -1,   125,    -1,    70,    71,    -1,    70,
     128,    71,    -1,   129,    -1,   128,   129,    -1,   123,    -1,
      54,    72,   119,    66,   123,    -1,    54,    72,     1,    66,
     123,    -1,    54,    72,   119,    66,   123,    51,   123,    -1,
      54,    72,     1,    66,   123,    51,   123,    -1,    55,    72,
     119,    66,    70,   126,    71,    -1,    55,    72,     1,    66,
      70,   126,    71,    -1,    57,   123,    -1,    58,    72,   119,
      66,   123,    -1,    53,     3,    86,    -1,    48,    86,    -1,
      46,    86,    -1,   100,    -1,    72,    91,    66,    -1,    72,
       1,    66,    -1,    72,    66,    -1,   133,   127,   134,    -1,
     133,   127,    -1,   127,   134,    -1,   127,    -1,    61,     3,
      65,    17,   135,    86,    -1,    63,    20,     3,    65,    17,
      86,    -1,   137,    -1,   136,    -1,   139,   138,    -1,   138,
      -1,    64,    -1,   140,   139,    -1,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    38,    39,    40,    41,    42,    43,    44,
      48,    51,    54,    57,    63,    64,    68,    71,    77,    83,
      84,    85,    89,    93,    94,    95,    96,   100,   103,   106,
     109,   115,   121,   127,   130,   134,   140,   143,   149,   152,
     155,   161,   164,   170,   171,   174,   179,   180,   181,   182,
     189,   192,   195,   203,   204,   207,   210,   216,   219,   222,
     225,   231,   232,   235,   238,   244,   245,   248,   254,   255,
     258,   264,   265,   268,   271,   274,   280,   281,   284,   290,
     291,   297,   298,   304,   305,   311,   312,   318,   319,   325,
     326,   332,   336,   337,   340,   343,   349,   350,   353,   361,
     364,   367,   370,   376,   379,   382,   385,   393,   394,   395,
     396,   397,   398,   399,   402,   408,   414,   417,   423,   426,
     430,   435,   441,   444,   453,   457,   460,   463,   466,   469,
     472,   478,   481,   487,   490,   493,   501,   505,   508,   511,
     518,   521,   524,   527,   533,   539,   545,   546,   550,   553,
     559,   563,   566
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "N_CONSTANT", "INT", "LONG", "FLOAT", "DOUBLE",
  "NUMBER", "STRING", "RAW", "VAR", "PROC", "LA", "LIST", "MAP",
  "APPLY_TO", "PIPE_1_TO_1", "PIPE_REDUCE", "PIPE_EXPAND", "PIPE_INJECT",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "LEFT_OP", "INC_OP", "DEC_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AUTO", "BREAK", "CASE", "CONTINUE",
  "DEFAULT", "DO", "ELSE", "FOR", "GOTO", "IF", "SWITCH", "WHILE", "LOOP",
  "EACH", "IS", "OUT", "DECLARE", "SYNC", "DOMAIN_NAME", "PACKAGE_NAME",
  "':'", "')'", "','", "'['", "']'", "'{'", "'}'", "'('", "'+'", "'-'",
  "'~'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "'?'", "';'", "$accept", "basic_var_type_specifier",
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
  "external_declaration_list", "package_declare", "a_proc_la", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    58,    41,    44,    91,    93,
     123,   125,    40,    43,    45,   126,    33,    42,    47,    37,
      60,    62,    38,    94,   124,    63,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    93,    94,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   110,   111,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   119,   119,   119,   119,   120,   120,   120,   121,
     121,   121,   121,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   130,   130,   130,   130,   130,
     130,   131,   131,   132,   132,   132,   133,   134,   134,   134,
     135,   135,   135,   135,   136,   137,   138,   138,   139,   139,
     140,   141,   141
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       1,     1,     3,     3,     3,     1,     3,     5,     3,     3,
       2,     1,     3,     1,     4,     4,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     3,     2,     3,     1,     2,     4,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     4,     3,     2,     1,
       2,     3,     1,     2,     1,     5,     5,     7,     7,     7,
       7,     2,     5,     3,     2,     2,     1,     3,     3,     2,
       3,     2,     2,     1,     6,     6,     1,     1,     2,     1,
       1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   150,   147,   146,   149,   152,     0,     0,
       0,     0,   148,   151,     1,     0,     0,     0,     0,     0,
       0,   136,   143,     0,     0,     0,     0,    25,    20,    21,
      22,    19,    30,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,    57,    58,    59,
      60,    96,    26,    23,    24,    43,    46,    47,    48,    49,
      50,    53,    61,     0,    65,    68,    71,    76,    79,    81,
      83,    85,    87,    89,    91,    92,     0,   109,   124,   107,
     108,     0,   122,   110,   111,   112,     0,    25,    40,     0,
       0,    41,     0,   142,   141,   144,   145,   114,     0,    54,
      55,   135,   134,     0,     0,     0,   131,     0,     0,     0,
      29,     0,    31,     0,     0,     0,     0,     0,    51,    52,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,     0,    97,    94,     0,   121,
     123,    39,     0,     0,     0,    38,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,   139,    14,    15,
      17,     0,   140,    18,   115,   133,     0,     0,     0,     0,
       0,   113,    28,     0,    27,    34,     0,    33,     0,     0,
       0,    62,    63,    64,    66,    67,    70,    69,    74,    75,
      72,    73,    77,    78,    80,    82,    84,    86,    88,     0,
       0,    93,    95,   101,    99,    48,   102,   100,    42,   138,
      10,    11,    12,    13,   137,     0,     0,     0,     0,     0,
       0,    32,     0,    36,    44,    45,     0,    98,    16,   126,
     125,     0,     0,   132,     0,    90,     0,     0,     0,     0,
     119,     0,     0,    37,   128,   127,     0,     0,   130,   118,
     129,     0,   117,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   168,   169,   173,   171,    52,    53,    54,    55,    56,
     111,    57,   114,    58,    90,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   147,   148,    78,    79,   250,   251,
      80,    81,    82,    83,    84,    85,    23,    93,    24,     4,
       5,     6,     7,     8,     9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      38,    13,     6,   -91,   -91,   -91,   -91,    63,    63,    47,
     -12,    62,   -91,    63,   -91,    54,    33,     2,    87,   192,
     398,   -91,    46,    58,    52,    72,    95,    84,   -91,   -91,
     -91,   -91,   -91,   -91,    57,    57,   108,   119,   166,   101,
     113,   372,   144,   168,   474,   252,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    83,
     -91,   104,   -91,    57,    11,   106,   148,    81,   165,   138,
     153,   143,   198,   -33,   -91,   -91,    14,   -91,   -91,   -91,
     -91,   312,   -91,   -91,   -91,   -91,   175,   177,   -91,   483,
     125,   180,   271,   -91,    46,   -91,   -91,   -91,   102,   -91,
     -91,   -91,   -91,   145,   559,   568,   -91,    57,   157,   179,
     -91,    85,   180,   -32,   -22,    -9,    57,    57,   -91,   -91,
     -91,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
     659,   -91,   -91,   -91,   -91,   332,   -91,   -91,   585,   -91,
     -91,   -91,   332,   173,   373,   -91,    57,    57,   185,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   194,   196,
     -91,   152,   -91,   -91,   -91,   -91,   186,    20,   195,   123,
     273,   -91,   -91,    57,   -91,   -91,    57,   -91,    57,    -2,
       7,   -91,   -91,   -91,    11,    11,   106,   106,   148,   148,
     148,   148,    81,    81,   165,   138,   153,   143,   198,   391,
     183,   -91,   -91,   -91,   -91,   203,   -91,   -91,   180,   -91,
     -91,   -91,   -91,   -91,   -91,   332,   372,   372,   204,   205,
     372,   180,   439,   180,   -91,   -91,    57,   -91,   -91,   225,
     226,   118,   118,   -91,    57,   -91,   372,   372,    57,   222,
     -91,   -39,    -1,   180,   -91,   -91,   502,   372,   -91,   -91,
     -91,   372,   -91,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -90,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -11,   -91,   -91,   -91,   -91,   -30,   -91,
      98,    99,   -48,   100,   154,   156,   163,   155,   164,   -91,
      65,   -89,   -20,   -91,   -91,   -91,   -40,   -91,   -17,    61,
     -14,   -91,   223,   -91,   -91,   -91,   -91,   214,   181,   -91,
     -91,    10,   303,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -137
static const yytype_int16 yytable[] =
{
      91,   106,   170,    22,    99,   100,    21,   138,   248,    94,
     249,   140,   141,   142,   143,   144,    10,    12,   157,   141,
     142,   143,   144,    12,   112,   115,    11,   157,   141,   142,
     143,   144,   258,   120,   140,   141,   142,   143,   144,   185,
     157,   141,   142,   143,   144,   186,   248,    14,   249,   187,
     145,   211,   139,    15,    97,   212,   188,   145,   174,   216,
      87,    28,    29,    30,    31,    16,   145,   234,   211,   154,
     260,    17,    19,   145,    20,    32,    33,   146,   235,   145,
     198,   199,   200,   201,   177,   179,   227,   180,   121,   122,
     123,   191,   192,   193,    34,    35,   189,   190,    18,     1,
     146,     2,     3,    26,    25,    27,    28,    29,    30,    31,
     159,   160,   161,   162,   163,   164,   165,   166,    92,   209,
      32,    33,   128,   129,     1,    44,     2,    89,    19,    20,
      47,    48,    49,    50,    22,   238,   218,   215,    95,    34,
      35,   118,   119,   157,   141,   142,   143,   144,    36,    98,
      37,   116,   183,   117,   184,    38,    39,    40,    96,    41,
      42,   130,   131,   231,    43,   248,   232,   249,   233,   103,
      44,   108,    45,   104,    20,    47,    48,    49,    50,   124,
     125,    97,   145,   126,   127,   105,   239,   240,    51,   229,
     243,   155,   156,    26,   101,    27,    28,    29,    30,    31,
     157,   141,   142,   143,   144,   102,   254,   255,   132,   133,
      32,    33,   220,   221,   222,   223,   107,   262,   224,   225,
     134,   263,   194,   195,   253,   196,   197,   136,   256,    34,
      35,   175,   202,   203,   259,   259,   135,   137,    36,   145,
      37,   151,   152,   181,   185,    38,    39,    40,   182,    41,
      42,   219,   226,   113,    43,    27,    28,    29,    30,    31,
      44,   228,    45,    46,    20,    47,    48,    49,    50,   237,
      32,    33,   158,  -136,   241,   242,   246,   247,    51,   159,
     160,   161,   162,   163,   164,   165,   166,   257,   204,    34,
      35,   205,   207,   157,   141,   142,   143,   144,    36,   206,
      37,   245,   208,   252,   150,    38,    39,    40,   172,    41,
      42,    13,     0,    26,    43,    27,    28,    29,    30,    31,
      44,     0,    45,    46,    20,    47,    48,    49,    50,   217,
      32,    33,   145,     0,     0,     0,     0,   167,    51,   230,
     159,   160,   161,   162,   163,   164,   165,   166,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      37,     0,     0,     0,     0,    38,    39,    40,     0,    41,
      42,     0,     0,    26,    43,    27,    28,    29,    30,    31,
      44,     0,    45,   149,    20,    47,    48,    49,    50,     0,
      32,    33,     0,   157,   141,   142,   143,   144,    51,    86,
       0,    87,    28,    29,    30,    31,     0,     0,     0,    34,
      35,   157,   141,   142,   143,   144,    32,    33,    36,     0,
      37,     0,     0,     0,     0,    38,    39,    40,     0,    41,
      42,     0,   145,     0,    43,    34,    35,     0,   188,     0,
      44,     0,    45,     0,    20,    47,    48,    49,    50,     0,
     145,     0,     0,     0,     0,     0,   236,     0,    51,   157,
     141,   142,   143,   144,    88,     0,    44,     0,    89,     0,
      20,    47,    48,    49,    50,   109,     0,    87,    28,    29,
      30,    31,     0,     0,   153,     0,    87,    28,    29,    30,
      31,     0,    32,    33,     0,     0,     0,     0,   145,     0,
       0,    32,    33,     0,   244,     0,     0,     0,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
      34,    35,   157,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   110,    89,     0,    20,    47,    48,    49,
      50,    44,     0,    89,     0,    20,    47,    48,    49,    50,
     176,   145,    87,    28,    29,    30,    31,   261,     0,   178,
       0,    87,    28,    29,    30,    31,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    87,    28,
      29,    30,    31,     0,     0,     0,    34,    35,     0,     0,
       0,     0,     0,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,     0,    44,     0,    89,
       0,    20,    47,    48,    49,    50,    44,     0,    89,     0,
      20,    47,    48,    49,    50,   213,     0,     0,   214,     0,
       0,     0,     0,    44,     0,    45,     0,    20,    47,    48,
      49,    50,    87,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    89,
       0,    20,    47,    48,    49,    50
};

static const yytype_int16 yycheck[] =
{
      20,    41,    92,    17,    34,    35,    17,    40,    47,    23,
      49,    20,    21,    22,    23,    24,     3,     7,    20,    21,
      22,    23,    24,    13,    44,    45,    20,    20,    21,    22,
      23,    24,    71,    63,    20,    21,    22,    23,    24,    71,
      20,    21,    22,    23,    24,    67,    47,     0,    49,    71,
      59,   140,    85,    65,    86,   145,    65,    59,    98,   148,
       3,     4,     5,     6,     7,     3,    59,    69,   157,    89,
      71,    17,    70,    59,    72,    18,    19,    86,    71,    59,
     128,   129,   130,   131,   104,   105,    66,   107,    77,    78,
      79,   121,   122,   123,    37,    38,   116,   117,    65,    61,
      86,    63,    64,     1,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    72,   139,
      18,    19,    41,    42,    61,    68,    63,    70,    70,    72,
      73,    74,    75,    76,   148,   225,   156,   148,    86,    37,
      38,    37,    38,    20,    21,    22,    23,    24,    46,    65,
      48,    68,    67,    70,    69,    53,    54,    55,    86,    57,
      58,    80,    81,   183,    62,    47,   186,    49,   188,     3,
      68,     3,    70,    72,    72,    73,    74,    75,    76,    73,
      74,    86,    59,    35,    36,    72,   226,   227,    86,    66,
     230,    66,    67,     1,    86,     3,     4,     5,     6,     7,
      20,    21,    22,    23,    24,    86,   246,   247,    43,    44,
      18,    19,    18,    19,    18,    19,    72,   257,    66,    67,
      82,   261,   124,   125,   244,   126,   127,    84,   248,    37,
      38,    86,   132,   133,   251,   252,    83,    39,    46,    59,
      48,    66,    65,    86,    71,    53,    54,    55,    69,    57,
      58,    66,    66,     1,    62,     3,     4,     5,     6,     7,
      68,    66,    70,    71,    72,    73,    74,    75,    76,    86,
      18,    19,     1,    70,    70,    70,    51,    51,    86,     8,
       9,    10,    11,    12,    13,    14,    15,    65,   134,    37,
      38,   135,   137,    20,    21,    22,    23,    24,    46,   136,
      48,   236,   138,   242,    81,    53,    54,    55,    94,    57,
      58,     8,    -1,     1,    62,     3,     4,     5,     6,     7,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,   148,
      18,    19,    59,    -1,    -1,    -1,    -1,    66,    86,    66,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    57,
      58,    -1,    -1,     1,    62,     3,     4,     5,     6,     7,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      18,    19,    -1,    20,    21,    22,    23,    24,    86,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    37,
      38,    20,    21,    22,    23,    24,    18,    19,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    57,
      58,    -1,    59,    -1,    62,    37,    38,    -1,    65,    -1,
      68,    -1,    70,    -1,    72,    73,    74,    75,    76,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    86,    20,
      21,    22,    23,    24,    66,    -1,    68,    -1,    70,    -1,
      72,    73,    74,    75,    76,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    18,    19,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    18,    19,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    68,    -1,    70,    -1,    72,    73,    74,    75,    76,
       1,    59,     3,     4,     5,     6,     7,    65,    -1,     1,
      -1,     3,     4,     5,     6,     7,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    18,    19,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    73,    74,    75,    76,    68,    -1,    70,    -1,
      72,    73,    74,    75,    76,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    73,    74,
      75,    76,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72,    73,    74,    75,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    63,    64,   136,   137,   138,   139,   140,   141,
       3,    20,   138,   139,     0,    65,     3,    17,    65,    70,
      72,   100,   127,   133,   135,    17,     1,     3,     4,     5,
       6,     7,    18,    19,    37,    38,    46,    48,    53,    54,
      55,    57,    58,    62,    68,    70,    71,    73,    74,    75,
      76,    86,    92,    93,    94,    95,    96,    98,   100,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   123,   124,
     127,   128,   129,   130,   131,   132,     1,     3,    66,    70,
     101,   119,    72,   134,   127,    86,    86,    86,    65,   105,
     105,    86,    86,     3,    72,    72,   123,    72,     3,     1,
      69,    97,   119,     1,    99,   119,    68,    70,    37,    38,
     105,    77,    78,    79,    73,    74,    35,    36,    41,    42,
      80,    81,    43,    44,    82,    83,    84,    39,    40,    85,
      20,    21,    22,    23,    24,    59,    86,   121,   122,    71,
     129,    66,    65,     1,   119,    66,    67,    20,     1,     8,
       9,    10,    11,    12,    13,    14,    15,    66,    88,    89,
      90,    91,   134,    90,   123,    86,     1,   119,     1,   119,
     119,    86,    69,    67,    69,    71,    67,    71,    65,   119,
     119,   105,   105,   105,   107,   107,   108,   108,   109,   109,
     109,   109,   110,   110,   111,   112,   113,   114,   115,   119,
      60,   118,    90,    60,    63,   100,   118,   135,   119,    66,
      18,    19,    18,    19,    66,    67,    66,    66,    66,    66,
      66,   119,   119,   119,    69,    71,    65,    86,    90,   123,
     123,    70,    70,   123,    65,   117,    51,    51,    47,    49,
     125,   126,   126,   119,   123,   123,   119,    65,    71,   125,
      71,    65,   123,   123
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
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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
        case 10:
#line 48 "proc.la.y"
    {
        (yyval) = ast_create_combined_type((yyvsp[(1) - (2)]), ast_type_list);
    ;}
    break;

  case 11:
#line 51 "proc.la.y"
    {
        (yyval) = ast_create_combined_type((yyvsp[(1) - (2)]), ast_type_map);
    ;}
    break;

  case 12:
#line 54 "proc.la.y"
    {
        (yyval) = ast_create_combined_type((yyvsp[(1) - (2)]), ast_type_list);
    ;}
    break;

  case 13:
#line 57 "proc.la.y"
    {
        (yyval) = ast_create_combined_type((yyvsp[(1) - (2)]), ast_type_map);
    ;}
    break;

  case 16:
#line 68 "proc.la.y"
    {
        (yyval) = ast_create_type_list((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
    ;}
    break;

  case 17:
#line 71 "proc.la.y"
    {
        (yyval) = ast_create_type_list((yyvsp[(1) - (1)]), null);
    ;}
    break;

  case 18:
#line 77 "proc.la.y"
    {
        (yyval) = ast_create_var_declare((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    ;}
    break;

  case 27:
#line 100 "proc.la.y"
    {
        (yyval) = ast_close_container((yyvsp[(2) - (3)]));
    ;}
    break;

  case 28:
#line 103 "proc.la.y"
    {
        (yyval) = ast_create_error_recovery_ex("list", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
    ;}
    break;

  case 29:
#line 106 "proc.la.y"
    {
        (yyval) = ast_create_none();
    ;}
    break;

  case 30:
#line 109 "proc.la.y"
    {
        (yyval) = ast_create_none();
    ;}
    break;

  case 31:
#line 115 "proc.la.y"
    {
        (yyval) = ast_create_container((yyvsp[(1) - (1)]), null, ast_container_type_list);
    ;}
    break;

  case 32:
#line 121 "proc.la.y"
    {
        (yyval) = ast_create_container((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_container_type_list);
    ;}
    break;

  case 33:
#line 127 "proc.la.y"
    {
        (yyval) = ast_close_container((yyvsp[(2) - (3)]));
    ;}
    break;

  case 34:
#line 130 "proc.la.y"
    {
        (yyval) = ast_create_error_recovery_ex("map", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
    ;}
    break;

  case 35:
#line 134 "proc.la.y"
    {
        (yyval) = ast_create_none();
    ;}
    break;

  case 36:
#line 140 "proc.la.y"
    {
        (yyval) = ast_create_container(ast_create_pair((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])), null, ast_container_type_map);
    ;}
    break;

  case 37:
#line 143 "proc.la.y"
    {
        (yyval) = ast_create_container((yyvsp[(1) - (5)]), ast_create_pair((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])), ast_container_type_map);
    ;}
    break;

  case 38:
#line 149 "proc.la.y"
    {
        (yyval) = ast_close_container((yyvsp[(2) - (3)]));
    ;}
    break;

  case 39:
#line 152 "proc.la.y"
    {
        (yyval) = ast_create_error_recovery_ex("tuple", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
    ;}
    break;

  case 40:
#line 155 "proc.la.y"
    {
        (yyval) = ast_create_none();
    ;}
    break;

  case 41:
#line 161 "proc.la.y"
    {
        (yyval) = ast_create_container((yyvsp[(1) - (1)]), null, ast_container_type_tuple);
    ;}
    break;

  case 42:
#line 164 "proc.la.y"
    {
         (yyval) = ast_create_container((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_container_type_tuple);
    ;}
    break;

  case 44:
#line 171 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), ast_binary_op_list_access);
    ;}
    break;

  case 45:
#line 174 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), ast_binary_op_map_access);
    ;}
    break;

  case 51:
#line 192 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[(1) - (2)]), ast_unary_op_inc_l);
	;}
    break;

  case 52:
#line 195 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr((yyvsp[(1) - (2)]), ast_unary_op_dec_l);
	;}
    break;

  case 54:
#line 204 "proc.la.y"
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[(2) - (2)]), ast_unary_op_inc_f);
    ;}
    break;

  case 55:
#line 207 "proc.la.y"
    {
        (yyval) = ast_create_unary_op_expr((yyvsp[(2) - (2)]), ast_unary_op_dec_f);
    ;}
    break;

  case 56:
#line 210 "proc.la.y"
    {
        (yyval) = ast_create_unary_op_expr_ex((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    ;}
    break;

  case 57:
#line 216 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_plus);
	;}
    break;

  case 58:
#line 219 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_minus);
	;}
    break;

  case 59:
#line 222 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_invert);
	;}
    break;

  case 60:
#line 225 "proc.la.y"
    {
	    (yyval) = ast_create_unary_op_expr(null, ast_unary_op_not);
	;}
    break;

  case 62:
#line 232 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_multiply);
	;}
    break;

  case 63:
#line 235 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_divide);
	;}
    break;

  case 64:
#line 238 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_modulo);
	;}
    break;

  case 66:
#line 245 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_add);
	;}
    break;

  case 67:
#line 248 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_subtract);
	;}
    break;

  case 69:
#line 255 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_shift_left);
	;}
    break;

  case 70:
#line 258 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_shift_right);
	;}
    break;

  case 72:
#line 265 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_less);
	;}
    break;

  case 73:
#line 268 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_great);
	;}
    break;

  case 74:
#line 271 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_less_or_equal);
	;}
    break;

  case 75:
#line 274 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_great_or_equal);
	;}
    break;

  case 77:
#line 281 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_equal);
	;}
    break;

  case 78:
#line 284 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_not_equal);
	;}
    break;

  case 80:
#line 291 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_bit_and);
	;}
    break;

  case 82:
#line 298 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_bit_xor);
	;}
    break;

  case 84:
#line 305 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_bit_or);
	;}
    break;

  case 86:
#line 312 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_and);
	;}
    break;

  case 88:
#line 319 "proc.la.y"
    {
	    (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_or);
	;}
    break;

  case 90:
#line 326 "proc.la.y"
    {
	    (yyval) = ast_create_ternary_op_expr((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), ast_ternary_op_conditional);
	;}
    break;

  case 93:
#line 337 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ast_binary_op_apply_to);
    ;}
    break;

  case 94:
#line 340 "proc.la.y"
    {
	    (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	;}
    break;

  case 95:
#line 343 "proc.la.y"
    {
	    (yyval) = ast_create_is_expr((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	;}
    break;

  case 97:
#line 350 "proc.la.y"
    {
	    (yyval) = (yyvsp[(1) - (2)]);
	;}
    break;

  case 98:
#line 353 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), ast_binary_op_apply_to);
    ;}
    break;

  case 99:
#line 361 "proc.la.y"
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 100:
#line 364 "proc.la.y"
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 101:
#line 367 "proc.la.y"
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 102:
#line 370 "proc.la.y"
    {
        (yyval) = ast_apply_binary_op_expr_w_expr_b((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 103:
#line 376 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_1to1);
    ;}
    break;

  case 104:
#line 379 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_reduce);
    ;}
    break;

  case 105:
#line 382 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_expand);
    ;}
    break;

  case 106:
#line 385 "proc.la.y"
    {
        (yyval) = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_inject);
    ;}
    break;

  case 113:
#line 399 "proc.la.y"
    {
	    (yyval) = ast_create_sync((yyvsp[(2) - (3)]));
	;}
    break;

  case 114:
#line 402 "proc.la.y"
    {
	    (yyval) = ast_create_error_recovery_ex("statement", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_line, (yylsp[(1) - (2)]).last_column);
	;}
    break;

  case 115:
#line 408 "proc.la.y"
    {
	    (yyval) = ast_create_block(ast_create_anchor((yyvsp[(1) - (3)])), (yyvsp[(3) - (3)]));
	;}
    break;

  case 116:
#line 414 "proc.la.y"
    {
        (yyval) = ast_create_block(ast_create_case((yyvsp[(2) - (4)])), (yyvsp[(4) - (4)]));
    ;}
    break;

  case 117:
#line 417 "proc.la.y"
    {
        (yyval) = ast_create_block(ast_create_case(null), (yyvsp[(3) - (3)]));
    ;}
    break;

  case 118:
#line 423 "proc.la.y"
    {
        (yyval) = ast_create_block((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 120:
#line 430 "proc.la.y"
    {
        // This is also a empty map.
	    //$$ = ast_close_block(ast_create_block(null, null));
	    (yyval) = ast_create_none();
	;}
    break;

  case 121:
#line 435 "proc.la.y"
    {
	    (yyval) = ast_close_block((yyvsp[(2) - (3)]));
	;}
    break;

  case 122:
#line 441 "proc.la.y"
    {
	    (yyval) = ast_create_block((yyvsp[(1) - (1)]), null);
	;}
    break;

  case 123:
#line 444 "proc.la.y"
    {
	    (yyval) = ast_create_block((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	;}
    break;

  case 125:
#line 457 "proc.la.y"
    {
	    (yyval) = ast_create_ifelse((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), null);
	;}
    break;

  case 126:
#line 460 "proc.la.y"
    {
	    (yyval) = ast_create_error_recovery_ex("selection", (yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column);
	;}
    break;

  case 127:
#line 463 "proc.la.y"
    {
	    (yyval) = ast_create_ifelse((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
	;}
    break;

  case 128:
#line 466 "proc.la.y"
    {
        (yyval) = ast_create_error_recovery_ex("selection", (yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, (yylsp[(4) - (7)]).last_line, (yylsp[(4) - (7)]).last_column);
    ;}
    break;

  case 129:
#line 469 "proc.la.y"
    {
	    (yyval) = ast_create_switch((yyvsp[(3) - (7)]), ast_close_block((yyvsp[(6) - (7)])));
	;}
    break;

  case 130:
#line 472 "proc.la.y"
    {
	    (yyval) = ast_create_error_recovery_ex("selection", (yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, (yylsp[(4) - (7)]).last_line, (yylsp[(4) - (7)]).last_column);
	;}
    break;

  case 131:
#line 478 "proc.la.y"
    {
        (yyval) = ast_create_loop((yyvsp[(2) - (2)]));
    ;}
    break;

  case 132:
#line 481 "proc.la.y"
    {
        (yyval) = ast_create_each((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
    ;}
    break;

  case 133:
#line 487 "proc.la.y"
    {
	    (yyval) = ast_create_jump(ast_jump_type_goto, (yyvsp[(2) - (3)]));
	;}
    break;

  case 134:
#line 490 "proc.la.y"
    {
	    (yyval) = ast_create_jump(ast_jump_type_continue, null);
	;}
    break;

  case 135:
#line 493 "proc.la.y"
    {
	    (yyval) = ast_create_jump(ast_jump_type_break, null);
	;}
    break;

  case 137:
#line 505 "proc.la.y"
    {
        (yyval) = (yyvsp[(2) - (3)]);
    ;}
    break;

  case 138:
#line 508 "proc.la.y"
    {
        (yyval) = ast_create_error_recovery_ex("output", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
    ;}
    break;

  case 139:
#line 511 "proc.la.y"
    {
        // create an empty list
        (yyval) = ast_create_type_list(null, null);
    ;}
    break;

  case 140:
#line 518 "proc.la.y"
    {
        (yyval) = ast_create_la_declaration((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
    ;}
    break;

  case 141:
#line 521 "proc.la.y"
    {
        (yyval) = ast_create_la_declaration((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), null);
    ;}
    break;

  case 142:
#line 524 "proc.la.y"
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 143:
#line 527 "proc.la.y"
    {
        (yyval) = ast_create_la_declaration(null, (yyvsp[(1) - (1)]), null);
    ;}
    break;

  case 144:
#line 533 "proc.la.y"
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
    ;}
    break;

  case 145:
#line 539 "proc.la.y"
    {
        (yyval) = ast_create_var_instance_ex((yyvsp[(5) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(1) - (6)]));
    ;}
    break;

  case 148:
#line 550 "proc.la.y"
    {
        (yyval) = ast_create_external_declarations((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 149:
#line 553 "proc.la.y"
    {
        (yyval) = ast_create_external_declarations((yyvsp[(1) - (1)]), null);
    ;}
    break;

  case 151:
#line 563 "proc.la.y"
    {
        (yyval) = ast_create_a_proc_la((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    ;}
    break;

  case 152:
#line 566 "proc.la.y"
    {
        (yyval) = ast_create_a_proc_la(null, (yyvsp[(1) - (1)]));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2544 "/Users/yuchi/projects/proc.la/autogen/proc.la.y.c"
      default: break;
    }
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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
		 yytoken, &yylval, &yylloc);
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


#line 571 "proc.la.y"


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}
