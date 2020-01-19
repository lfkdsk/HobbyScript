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



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AEQ = 258,
     ISOPT = 259,
     AND = 260,
     OR = 261,
     NOEQ = 262,
     EQ = 263,
     REQ = 264,
     LEQ = 265,
     STRING_LITERAL = 266,
     ARRAY = 267,
     URIGHTMOVE = 268,
     RIGHTMOVE = 269,
     LEFTMOVE = 270,
     DEC = 271,
     INC = 272,
     BINARY = 273,
     EOL = 274,
     FEOF = 275,
     FUNC = 276,
     DOTS = 277,
     TYPE = 278,
     RGO = 279,
     WHEN_NULL = 280,
     ITYPE = 281,
     L_IDENTIFIER = 282,
     U_IDENTIFIER = 283,
     INTEGER = 284,
     FLOAT = 285,
     INT64 = 286,
     FLOAT64 = 287,
     BOOLEAN = 288,
     CALL = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     FOR = 293,
     RETURN = 294,
     CLASS = 295,
     INTERF = 296,
     PROTECTED = 297,
     PACKAGE = 298,
     IMPORT = 299,
     NULLPTR = 300,
     STATIC = 301,
     CONST = 302,
     ENUM = 303,
     SWITCH = 304,
     CASE = 305,
     DEFAULT = 306,
     SINGLETON = 307,
     TRY_TOKEN = 308,
     CATCH = 309,
     FINALLY = 310,
     GET_TOKEN = 311,
     SET_TOKEN = 312,
     OPERATOR = 313,
     NEW_TOKEN = 314,
     DELETE_TOKEN = 315,
     INIT_TOKEN = 316,
     FINALIZE_TOKEN = 317,
     GO_TOKEN = 318,
     BBRACKETS = 319
   };
#endif
/* Tokens.  */
#define AEQ 258
#define ISOPT 259
#define AND 260
#define OR 261
#define NOEQ 262
#define EQ 263
#define REQ 264
#define LEQ 265
#define STRING_LITERAL 266
#define ARRAY 267
#define URIGHTMOVE 268
#define RIGHTMOVE 269
#define LEFTMOVE 270
#define DEC 271
#define INC 272
#define BINARY 273
#define EOL 274
#define FEOF 275
#define FUNC 276
#define DOTS 277
#define TYPE 278
#define RGO 279
#define WHEN_NULL 280
#define ITYPE 281
#define L_IDENTIFIER 282
#define U_IDENTIFIER 283
#define INTEGER 284
#define FLOAT 285
#define INT64 286
#define FLOAT64 287
#define BOOLEAN 288
#define CALL 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define RETURN 294
#define CLASS 295
#define INTERF 296
#define PROTECTED 297
#define PACKAGE 298
#define IMPORT 299
#define NULLPTR 300
#define STATIC 301
#define CONST 302
#define ENUM 303
#define SWITCH 304
#define CASE 305
#define DEFAULT 306
#define SINGLETON 307
#define TRY_TOKEN 308
#define CATCH 309
#define FINALLY 310
#define GET_TOKEN 311
#define SET_TOKEN 312
#define OPERATOR 313
#define NEW_TOKEN 314
#define DELETE_TOKEN 315
#define INIT_TOKEN 316
#define FINALIZE_TOKEN 317
#define GO_TOKEN 318
#define BBRACKETS 319




/* Copy the first part of user declarations.  */
#line 1 "hobby.yy"


#include "object.h"
#define YYERROR_VERBOSE 1
#define YYDEBUG 1
#define YY_NO_UNISTD_H

extern "C" {
int yylex(void);
int yyparse(void);
}

void yyerror( const char* error );



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
#line 18 "hobby.yy"
{
	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;
}
/* Line 193 of yacc.c.  */
#line 247 "hobby.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 260 "hobby.tab.cpp"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  262
/* YYNRULES -- Number of states.  */
#define YYNSTATES  479

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
       2,     2,     2,    30,     2,     2,     2,    89,    24,     2,
      27,    28,    22,    20,    87,    21,     4,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    43,
      11,     3,    12,    88,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,    26,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    25,    42,    29,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    13,    16,    17,    18,    20,
      23,    26,    31,    33,    37,    41,    45,    49,    51,    54,
      57,    61,    63,    66,    68,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
     100,   102,   104,   109,   113,   115,   119,   122,   127,   130,
     132,   136,   142,   144,   148,   152,   154,   155,   158,   159,
     163,   165,   169,   175,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   199,   201,   207,   208,   211,   215,
     220,   222,   225,   227,   230,   234,   235,   241,   243,   245,
     247,   250,   257,   261,   269,   273,   275,   280,   282,   286,
     289,   291,   295,   300,   307,   309,   311,   315,   317,   321,
     327,   332,   339,   343,   349,   353,   357,   361,   366,   367,
     369,   373,   375,   377,   383,   386,   391,   394,   395,   397,
     401,   402,   404,   408,   410,   418,   427,   435,   436,   439,
     441,   443,   445,   449,   456,   460,   468,   472,   475,   477,
     480,   482,   484,   486,   488,   490,   492,   494,   496,   498,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   532,   536,   538,   540,   542,   544,
     546,   552,   554,   557,   562,   566,   568,   572,   577,   578,
     580,   583,   590,   592,   596,   597,   600,   606,   616,   617,
     619,   623,   627,   631,   635,   637,   639,   641,   643,   645,
     647,   649,   651,   653,   657,   660,   663,   665,   667,   669,
     671,   674,   677,   681,   687,   691,   695,   700,   704,   708,
     712,   716,   720,   724,   728,   732,   736,   740,   744,   748,
     752,   756,   760,   764,   768,   772,   776,   780,   782,   786,
     788,   791,   793,   795,   797,   799,   801,   808,   813,   816,
     822,   828,   832
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    94,    95,   101,    -1,    49,    -1,    93,
       4,    49,    -1,    65,    93,    -1,    -1,    -1,    96,    -1,
      95,    96,    -1,    66,    98,    -1,    66,    27,    99,    28,
      -1,    49,    -1,    97,     4,    49,    -1,    97,     4,    22,
      -1,    97,     4,    50,    -1,    97,     4,    49,    -1,    98,
      -1,    99,    98,    -1,    41,    42,    -1,    41,   101,    42,
      -1,   102,    -1,   101,   102,    -1,   132,    -1,   114,    -1,
     123,    -1,   135,    -1,   137,    -1,   174,    -1,   175,    -1,
     154,    -1,   172,    -1,   171,    -1,   159,    -1,   143,    -1,
     103,    -1,   108,    -1,   162,    -1,   166,    -1,   141,    -1,
     147,    -1,   140,    -1,    69,    49,     3,   175,    -1,    49,
       3,   175,    -1,   175,    -1,   105,    87,   175,    -1,   129,
      49,    -1,   129,    49,     3,   175,    -1,   130,    49,    -1,
     106,    -1,   107,    87,   106,    -1,    70,    50,    41,   109,
      42,    -1,   110,    -1,   109,    87,   110,    -1,    50,     3,
     175,    -1,    50,    -1,    -1,    46,   129,    -1,    -1,    11,
     113,    12,    -1,    50,    -1,   113,    87,    50,    -1,   115,
      50,   112,   111,   122,    -1,   182,   114,    -1,    62,    -1,
      74,    -1,   132,    -1,   127,    -1,   128,    -1,   117,    -1,
     120,    -1,   103,    -1,   143,    -1,    64,    46,    -1,   147,
      -1,    83,    27,   146,    28,   118,    -1,    -1,    41,    42,
      -1,    41,   119,    42,    -1,    83,    27,   138,    28,    -1,
     101,    -1,    84,   144,    -1,   116,    -1,   121,   116,    -1,
      41,   121,    42,    -1,    -1,    63,    49,    41,   125,    42,
      -1,   132,    -1,   126,    -1,   124,    -1,   125,   124,    -1,
      36,    49,    27,   146,    28,   148,    -1,    78,    49,   100,
      -1,    79,    49,    27,   129,    49,    28,   100,    -1,    79,
      49,   100,    -1,    50,    -1,    50,    11,   131,    12,    -1,
      48,    -1,   129,    44,    45,    -1,   129,    88,    -1,    36,
      -1,    36,    27,    28,    -1,    36,    27,   131,    28,    -1,
      36,    27,   131,    28,    46,   129,    -1,   129,    -1,   130,
      -1,   131,    87,   129,    -1,   106,    -1,   132,    87,    49,
      -1,   132,    87,    49,     3,   175,    -1,   129,    49,     5,
     175,    -1,   129,    27,   136,    28,     5,   175,    -1,    44,
     105,    45,    -1,    27,   175,    87,   105,    28,    -1,   136,
       5,   175,    -1,    49,    87,    49,    -1,   136,    87,    49,
      -1,    49,    27,   138,    28,    -1,    -1,   139,    -1,   138,
      87,   139,    -1,   175,    -1,   104,    -1,   129,    49,    27,
     138,    28,    -1,    82,   175,    -1,   129,    44,   175,    45,
      -1,   126,   144,    -1,    -1,   100,    -1,   129,    37,    49,
      -1,    -1,   107,    -1,   107,    87,   145,    -1,   145,    -1,
      80,   157,    27,   146,    28,   148,   144,    -1,    80,    27,
      28,    27,   146,    28,   148,   144,    -1,    80,    16,    27,
     146,    28,   148,   144,    -1,    -1,    46,   150,    -1,   106,
      -1,   129,    -1,   149,    -1,   150,    87,   149,    -1,    36,
      27,   146,    28,   148,   100,    -1,   175,    16,   100,    -1,
     175,    16,    27,   146,    28,   148,   100,    -1,    85,   148,
     100,    -1,    85,   175,    -1,    61,    -1,    61,   105,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    30,    -1,    11,    -1,    12,    -1,    89,    -1,
       4,    -1,    19,    -1,    18,    -1,    17,    -1,    14,    -1,
      13,    -1,    39,    -1,     8,    -1,     7,    -1,    26,    -1,
      29,    -1,   155,    -1,   156,    -1,    57,    27,   160,    28,
     161,    -1,   158,    58,   161,    -1,   158,    -1,   175,    -1,
     176,    -1,   102,    -1,   100,    -1,    71,   175,    41,   163,
      42,    -1,   164,    -1,   163,   164,    -1,    72,   165,    46,
     101,    -1,    73,    46,   101,    -1,   175,    -1,   165,    87,
     175,    -1,    75,   100,   167,   170,    -1,    -1,   168,    -1,
     167,   168,    -1,    76,    27,   169,    49,    28,   100,    -1,
     129,    -1,   169,    87,   129,    -1,    -1,    77,   100,    -1,
      59,    27,   175,    28,   161,    -1,    60,    27,   173,    43,
     175,    43,   175,    28,   161,    -1,    -1,   106,    -1,    49,
       3,   175,    -1,    49,     3,   100,    -1,    49,     5,   175,
      -1,   175,     3,   175,    -1,   178,    -1,   133,    -1,   151,
      -1,   137,    -1,   134,    -1,   153,    -1,   142,    -1,    67,
      -1,    49,    -1,    27,   175,    28,    -1,   156,   175,    -1,
     175,   156,    -1,   174,    -1,   179,    -1,   180,    -1,   181,
      -1,   175,    32,    -1,   175,    31,    -1,   175,    40,   175,
      -1,   175,    88,   175,    46,   175,    -1,    50,     4,    49,
      -1,    50,     4,    50,    -1,   129,    27,   138,    28,    -1,
     175,    20,   175,    -1,   175,    21,   175,    -1,   175,    22,
     175,    -1,   175,    23,   175,    -1,   175,    24,   175,    -1,
     175,    25,   175,    -1,   175,    11,   175,    -1,   175,    12,
     175,    -1,   175,    89,   175,    -1,   175,     4,   175,    -1,
     175,    19,   175,    -1,   175,    18,   175,    -1,   175,    17,
     175,    -1,   175,    14,   175,    -1,   175,    13,   175,    -1,
     175,    39,   175,    -1,   175,    10,   175,    -1,   175,     5,
     175,    -1,   175,     8,   175,    -1,   175,     7,   175,    -1,
     152,    -1,   175,     6,    48,    -1,    15,    -1,   177,    15,
      -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,   177,
      -1,   175,    44,   175,    46,   175,    45,    -1,   175,    44,
     175,    45,    -1,   175,   100,    -1,    90,    50,    27,   175,
      28,    -1,    90,    50,    27,   183,    28,    -1,    49,     3,
     175,    -1,   183,    87,    49,     3,   175,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    66,    67,    71,    72,    82,    84,    85,
      89,    90,    94,    95,    99,   100,   101,   105,   106,   110,
     111,   115,   116,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   142,   145,   149,   150,   155,   156,   157,   161,
     162,   168,   172,   173,   177,   178,   185,   186,   190,   191,
     195,   196,   200,   202,   206,   207,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   224,   229,   230,   231,   235,
     236,   240,   245,   246,   249,   250,   257,   261,   262,   266,
     267,   271,   279,   283,   284,   297,   298,   299,   300,   301,
     305,   306,   307,   308,   312,   313,   314,   318,   319,   320,
     321,   322,   326,   334,   338,   342,   343,   350,   354,   355,
     356,   360,   361,   371,   375,   381,   389,   393,   394,   399,
     404,   405,   406,   407,   415,   417,   419,   424,   425,   429,
     430,   434,   435,   439,   448,   450,   455,   457,   462,   463,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   490,
     491,   495,   496,   504,   508,   509,   513,   514,   518,   519,
     523,   529,   530,   534,   535,   539,   540,   547,   551,   552,
     553,   557,   561,   562,   566,   567,   575,   578,   582,   584,
     589,   590,   591,   592,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   646,   650,
     651,   655,   656,   657,   658,   659,   668,   676,   684,   690,
     691,   695,   696
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'.'", "AEQ", "ISOPT", "AND",
  "OR", "NOEQ", "EQ", "'<'", "'>'", "REQ", "LEQ", "STRING_LITERAL",
  "ARRAY", "URIGHTMOVE", "RIGHTMOVE", "LEFTMOVE", "'+'", "'-'", "'*'",
  "'/'", "'&'", "'|'", "'^'", "'('", "')'", "'~'", "'!'", "DEC", "INC",
  "BINARY", "EOL", "FEOF", "FUNC", "DOTS", "TYPE", "RGO", "WHEN_NULL",
  "'{'", "'}'", "';'", "'['", "']'", "':'", "'`'", "ITYPE", "L_IDENTIFIER",
  "U_IDENTIFIER", "INTEGER", "FLOAT", "INT64", "FLOAT64", "BOOLEAN",
  "CALL", "IF", "ELSE", "WHILE", "FOR", "RETURN", "CLASS", "INTERF",
  "PROTECTED", "PACKAGE", "IMPORT", "NULLPTR", "STATIC", "CONST", "ENUM",
  "SWITCH", "CASE", "DEFAULT", "SINGLETON", "TRY_TOKEN", "CATCH",
  "FINALLY", "GET_TOKEN", "SET_TOKEN", "OPERATOR", "NEW_TOKEN",
  "DELETE_TOKEN", "INIT_TOKEN", "FINALIZE_TOKEN", "GO_TOKEN", "BBRACKETS",
  "','", "'?'", "'%'", "'@'", "$accept", "package", "package_name",
  "package_name_line", "import", "import_line", "import_name_pre",
  "import_name", "import_names", "block", "lines", "line", "const",
  "equal", "exprs", "typeLet", "typeLets", "enum", "enum_list",
  "enum_assignment", "cls_inherit", "cls_template_list", "types", "cls",
  "cls_type", "cls_line", "cls_construct", "construct_block_or_none",
  "construct_block_lines", "cls_destory", "cls_lines", "cls_block",
  "interface", "interface_line", "interface_lines", "function_def", "get",
  "set", "def_type", "func_type", "def_types", "def", "sequence", "tuple",
  "tupleResolve", "tupleResolveParams", "call", "call_args", "call_arg",
  "class_new", "object_delete", "array_new", "function", "block_or_none",
  "function_variable", "function_parameters", "operator_overload",
  "function_ret", "return_tuple_elem", "return_tuple_elems", "lambda",
  "array_call", "go", "rtn", "operator_binary", "operator_unary",
  "operator", "if_cond", "if_else", "if_expr", "block_or_line", "switch",
  "cases", "case", "case_exprs", "try", "try_catchs", "try_catch",
  "try_types", "try_finally", "while_loop", "for_loop", "for_line",
  "assignment", "expr", "type_expr", "string_lite", "expr_value", "splice",
  "index", "object_block", "annotation", "annotation_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    46,   258,   259,   260,   261,   262,
     263,    60,    62,   264,   265,   266,   267,   268,   269,   270,
      43,    45,    42,    47,    38,   124,    94,    40,    41,   126,
      33,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   123,   125,    59,    91,    93,    58,    96,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    44,    63,    37,
      64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   104,   105,   105,   106,   106,   106,   107,
     107,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   118,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   124,   124,   125,
     125,   126,   127,   128,   128,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   131,   132,   132,   132,
     132,   132,   133,   134,   135,   136,   136,   137,   138,   138,
     138,   139,   139,   140,   141,   142,   143,   144,   144,   145,
     146,   146,   146,   146,   147,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   156,
     156,   157,   157,   158,   159,   159,   160,   160,   161,   161,
     162,   163,   163,   164,   164,   165,   165,   166,   167,   167,
     167,   168,   169,   169,   170,   170,   171,   172,   173,   173,
     174,   174,   174,   174,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   177,
     177,   178,   178,   178,   178,   178,   179,   180,   181,   182,
     182,   183,   183
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     2,     0,     0,     1,     2,
       2,     4,     1,     3,     3,     3,     3,     1,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     2,     4,     2,     1,
       3,     5,     1,     3,     3,     1,     0,     2,     0,     3,
       1,     3,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     0,     2,     3,     4,
       1,     2,     1,     2,     3,     0,     5,     1,     1,     1,
       2,     6,     3,     7,     3,     1,     4,     1,     3,     2,
       1,     3,     4,     6,     1,     1,     3,     1,     3,     5,
       4,     6,     3,     5,     3,     3,     3,     4,     0,     1,
       3,     1,     1,     5,     2,     4,     2,     0,     1,     3,
       0,     1,     3,     1,     7,     8,     7,     0,     2,     1,
       1,     1,     3,     6,     3,     7,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     1,     1,
       5,     1,     2,     4,     3,     1,     3,     4,     0,     1,
       2,     6,     1,     3,     0,     2,     5,     9,     0,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     1,     1,     1,
       2,     2,     3,     5,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     6,     4,     2,     5,
       5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       6,     0,     0,     7,     3,     5,     1,     0,     0,     8,
       0,     0,    12,     0,    10,   249,   169,     0,   170,     0,
       0,    97,   212,    95,   251,   252,   253,   254,     0,     0,
       0,   148,    64,     0,   211,     0,     0,     0,    65,     0,
       0,     0,   137,     0,     9,     2,    21,    35,   107,    36,
      24,     0,    25,   127,     0,     0,    23,   205,   208,    26,
       0,    27,    41,    39,   210,    34,    40,   206,   247,   209,
      30,     0,   175,    33,    37,    38,    32,    31,    28,    29,
     255,   204,   217,   218,   219,     0,     4,    17,     0,     0,
       0,   212,     0,   207,   216,     0,     0,     0,     0,    44,
       0,     0,   118,     0,     0,     0,     0,     0,   198,   149,
       0,     0,     0,     0,     0,   188,   160,   168,   167,   157,
     158,   165,   164,     0,   163,   162,   161,   150,   151,   152,
     153,   154,   155,     0,   156,   166,   159,   171,   172,     0,
     124,     0,     0,   147,     0,    22,    58,   128,   126,   118,
       0,    46,    99,    48,     0,     0,     0,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     220,     0,     0,     0,     0,     0,   258,   215,   250,    63,
      11,    18,    14,    16,    15,   130,   118,   213,     0,   101,
     100,    95,    49,   131,   104,   105,     0,   133,     0,   130,
     112,     0,   201,   200,   202,   212,   122,     0,   119,   121,
     115,   224,   225,   104,   105,     0,     0,   176,   177,     0,
     199,     0,     0,     0,     0,     0,     0,    19,     0,     0,
     194,   189,   130,     0,   130,   139,   140,   141,   138,   146,
       0,     0,    56,   212,     0,     0,    98,     0,     0,     0,
     118,   108,   114,   116,   179,   178,   174,   203,   236,   244,
     246,   245,   243,   233,   234,   241,   240,   130,   144,   239,
     238,   237,   227,   228,   229,   230,   231,   232,   242,   222,
       0,     0,   235,     0,     0,     0,     0,     0,     0,    46,
     102,     0,   137,     0,    45,     0,   117,     0,    96,     0,
       0,     0,     0,     0,    89,     0,    88,     0,    87,    42,
      55,     0,    52,     0,     0,     0,   181,    20,     0,     0,
     190,   187,     0,   130,     0,     0,   212,     0,     0,    60,
       0,     0,    85,     0,   226,   125,    47,   110,     0,     0,
       0,   257,     0,     0,   113,    50,   132,   129,     0,   106,
       0,   137,    43,   120,   173,   248,   196,     0,    86,    90,
       0,    46,     0,    51,     0,     0,   185,     0,   180,   182,
     192,     0,   195,   137,     0,   137,   142,     0,   259,   260,
       0,    59,     0,    57,     0,    62,     0,   123,   109,   137,
       0,   223,   103,   143,    91,     0,     0,    54,    53,     0,
       0,   184,     0,     0,   127,   137,   127,   200,     0,    61,
       0,     0,     0,     0,   127,    71,    82,    69,    70,     0,
      67,    68,    66,    72,    74,   111,     0,   256,     0,   183,
     186,     0,   193,   136,   127,   134,     0,    73,     0,     0,
     130,    81,    84,    83,   145,     0,   191,   135,   262,    92,
       0,    94,     0,   197,     0,    76,     0,     0,    75,     0,
      77,     0,    80,     0,    93,   118,    78,     0,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     3,     8,     9,    13,    14,    88,   186,
     238,    46,    47,   216,    98,    48,   203,    49,   321,   322,
     342,   252,   340,    50,    51,   426,   427,   468,   473,   428,
     429,   395,    52,   314,   315,    53,   430,   431,    92,    55,
     206,    56,    57,    58,    59,    60,    93,   255,   218,    62,
      63,    64,    65,   148,   207,   208,    66,   142,   247,   248,
      67,    68,    69,    70,   137,    71,   139,    72,    73,   226,
     266,    74,   325,   326,   375,    75,   240,   241,   381,   331,
      76,    77,   232,    94,    79,   228,    80,    81,    82,    83,
      84,    85,   338
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -373
static const yytype_int16 yypact[] =
{
     -42,   -23,    39,   -31,  -373,   116,  -373,   142,  1718,  -373,
      78,    86,  -373,   139,  -373,  -373,  -373,  2012,  -373,   169,
    2012,  -373,    15,    29,  -373,  -373,  -373,  -373,   125,   179,
     182,  2012,  -373,   170,  -373,   191,   164,  2012,  -373,   180,
     874,  2012,   231,   200,  -373,  1918,  -373,  -373,  -373,  -373,
    -373,   215,  -373,   180,     7,   210,   181,  -373,  -373,  -373,
      11,  1504,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  2012,   218,  -373,  -373,  -373,  -373,  -373,  1549,  1416,
     256,  -373,  -373,  -373,  -373,   133,  -373,  -373,   118,   104,
     246,   144,    27,  -373,  -373,   915,   172,   247,    58,  1416,
      32,  2012,  2042,   229,   177,   213,  2012,  2012,   213,   199,
     248,   287,   251,  1462,  1768,   219,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,   264,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,   266,  -373,  -373,  -373,  -373,  -373,   269,
    1416,   213,   180,  1416,   270,  -373,   288,  -373,  -373,  2072,
     510,   156,  -373,  -373,   257,  2012,   262,  1416,  1818,  2012,
    2012,  2012,  2012,  2012,  2012,  2012,  2012,  2012,  2012,     5,
    2012,  2012,  2012,  2012,  2012,  2012,  2012,  2012,  2012,  -373,
    -373,  2012,  2012,  2012,  2012,  2012,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,   296,  -373,   213,  2042,  -373,  2012,  -373,
     285,   294,  -373,   226,   -13,   210,     2,  -373,   289,   213,
    -373,  2012,  -373,  1416,  1416,   159,  -373,    25,  -373,  1416,
    -373,  -373,  -373,    30,  -373,     3,   290,  1012,  -373,  1054,
    -373,    16,   272,   216,  2012,   271,  1606,  -373,  1868,   292,
     167,  -373,   213,   295,   213,  -373,    16,  -373,   236,  -373,
    2102,   274,   283,    22,    35,    36,  -373,  1100,  2012,  2012,
    2042,   327,  1416,  -373,  -373,  -373,  -373,  1416,  1416,  1416,
     761,   761,  1583,  1993,  1993,  1993,  1993,   213,  -373,   153,
     153,   153,   577,   577,   827,   827,   100,   100,  1416,  1416,
     966,  1146,  1416,   -13,    38,   172,   213,   282,   291,   329,
     293,   165,   298,   306,  1416,    32,  -373,  2042,  -373,  1818,
     297,  1818,  2012,   189,  -373,   197,  -373,    23,   181,  1416,
     332,     6,  -373,  2012,   300,   138,  -373,  -373,   165,   180,
    -373,  -373,   309,   213,   310,   213,   163,  1192,    41,  -373,
       9,   165,   307,   336,  -373,  -373,  1416,  1416,    49,  2012,
     321,  -373,  2012,  2012,  -373,  -373,  -373,  -373,   165,    30,
     180,   298,  1416,  -373,  -373,  -373,  -373,  1234,  -373,  -373,
     303,   250,  2012,  -373,   271,    68,  1416,  1918,  -373,  -373,
      30,    61,  -373,   298,   325,   298,  -373,    32,  -373,  -373,
     314,  -373,   305,    30,   278,  -373,  2012,  -373,  1416,   298,
    1280,  1416,    30,  -373,  -373,  2012,   279,  1416,  -373,  1918,
    2012,  1918,   331,   165,   180,   298,   180,  1323,   365,  -373,
     328,   324,   330,   353,   180,  -373,  -373,  -373,  -373,   590,
    -373,  -373,   181,  -373,  -373,  1416,   180,  -373,  1374,  1918,
    1416,   180,    30,  -373,   180,  -373,  2012,  -373,   180,    14,
     213,  -373,  -373,  -373,  -373,  1818,  -373,  -373,  1416,  -373,
     165,  -373,   354,  -373,    93,   340,   355,  1668,  -373,   180,
    -373,   357,  1918,   343,  -373,  2042,  -373,    51,  -373
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -373,  -373,  -373,  -373,  -373,   379,  -373,    17,  -373,   209,
       0,   -39,  -372,  -373,   -26,   -79,  -373,  -373,  -373,    18,
    -373,  -373,  -373,   304,  -373,   -41,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,    75,  -373,  -214,  -373,  -373,    -8,   -92,
     286,  -224,  -373,  -373,  -373,  -146,    -7,  -100,    88,  -373,
    -373,  -373,  -342,  -212,    97,  -199,  -273,  -291,    62,  -373,
    -373,  -373,  -373,  -373,  -373,   472,  -373,  -373,  -373,  -373,
    -297,  -373,  -373,    71,  -373,  -373,  -373,   158,  -373,  -373,
    -373,  -373,  -373,    -1,   323,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -262
static const yytype_int16 yytable[] =
{
      54,    61,   217,   254,   205,   109,   145,    78,    45,   318,
     303,   360,   364,   224,   366,   308,   155,   202,   100,   316,
     101,   391,   425,     1,   297,   305,     4,   101,    87,   230,
     300,   298,   277,   104,   149,     7,   299,    54,    61,     6,
     105,   460,   102,   332,    78,   334,   114,    15,   373,   102,
     370,   150,   433,   306,   196,   114,   151,   425,    16,    17,
     298,    18,   245,   343,   344,   299,   354,   298,    90,   389,
     404,   150,   371,   114,   298,   152,    20,   397,   350,   478,
      21,    91,    23,    24,    25,    26,    27,   433,   204,   301,
     301,   318,   414,   374,   416,   152,   392,   223,   156,    34,
     231,   316,   103,   210,   152,   191,    54,    61,   436,   103,
     412,   152,   307,    78,   409,   152,   202,    42,   152,   265,
      10,   434,   156,   307,   444,   211,   192,    86,   390,    18,
     202,   179,   180,   246,   384,    12,   307,   298,   307,   181,
     182,   114,   466,    89,   183,   211,   190,   100,   413,   101,
      54,    61,   106,   193,   194,   410,   434,    78,   463,   258,
     348,   259,   305,   202,   101,   202,   387,    12,   101,    11,
     432,   102,   294,   173,   174,   175,   176,   177,   178,    16,
     378,   152,    18,   260,   179,   180,   102,   293,   184,   185,
     102,    12,   181,   182,   114,    32,    96,   183,   202,   145,
     199,   293,   443,   224,   445,   432,   107,    38,   200,   108,
     323,   324,   451,    21,   112,   201,   295,   355,    97,   110,
      21,   114,   201,    43,   254,   317,   221,   222,    54,    61,
      54,    61,   457,   313,   293,    78,   293,    78,    97,   368,
     111,   184,   185,   239,   329,    21,    15,   201,   115,   200,
     144,   462,   313,   258,   202,   259,   245,    16,    17,   153,
      18,    21,   147,   201,    21,   146,   201,    90,   154,   293,
     265,   188,   265,   195,   209,    20,   158,   141,   220,    21,
      91,    23,    24,    25,    26,    27,   211,   223,   293,   233,
     234,   242,   235,   359,   243,   239,   244,   250,    34,   251,
     -13,    54,    61,    54,    61,   105,   261,   317,    78,   212,
      78,   263,   295,   296,   313,   312,    42,   302,   309,   328,
     380,   320,   333,   335,   339,   293,    21,   246,   201,   341,
     349,   357,   258,   393,   361,   372,   256,   383,   385,   358,
      95,   396,   420,    99,   141,   365,   377,    35,   394,   399,
     402,   249,   406,   415,    99,   419,   421,   422,    40,   441,
     113,   423,   424,   418,   140,   143,   103,   264,   446,    54,
      61,   202,   145,   448,   447,   477,    78,   411,   278,   449,
     450,   467,   465,   469,   475,   476,   317,    44,   453,   189,
     369,   225,   408,   356,   157,   363,   379,   386,   330,     0,
     145,    54,    61,    54,    61,   442,     0,     0,    78,   439,
      78,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,   317,     0,   213,   214,   219,     0,     0,     0,   227,
     229,    54,    61,   145,     0,     0,     0,     0,    78,     0,
       0,     0,   293,     0,     0,     0,     0,    54,    61,     0,
       0,     0,   464,     0,    78,     0,     0,     0,     0,    54,
      61,     0,     0,     0,    54,    61,    78,   472,     0,     0,
       0,    78,   219,   257,     0,     0,     0,     0,   262,     0,
       0,     0,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   279,   280,   281,   282,   283,   284,   285,
     286,   287,     0,     0,   288,   289,   290,   291,   292,     0,
       0,     0,   138,     0,   212,     0,     0,     0,   264,   219,
     264,    99,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,    16,    17,   382,    18,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,   187,     0,     0,    20,   256,     0,   319,    21,    91,
      23,    24,    25,    26,    27,     0,     0,   187,     0,   403,
       0,   187,     0,   337,     0,     0,     0,    34,     0,     0,
       0,   346,   347,   219,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,   212,     0,     0,   175,
     176,   177,   178,    16,     0,     0,    18,     0,   179,   180,
       0,     0,   187,     0,     0,   187,   181,   182,   114,     0,
       0,   183,     0,   147,     0,   147,   313,     0,   362,   187,
     219,     0,   452,   147,     0,   367,     0,     0,    21,     0,
     201,     0,     0,     0,     0,   454,   376,     0,     0,     0,
     456,     0,     0,   147,   420,     0,     0,   459,   461,    35,
       0,     0,     0,     0,   264,   184,   185,     0,   421,   422,
      40,     0,   398,   423,   424,   400,   401,     0,   474,     0,
       0,     0,     0,     0,     0,   187,   187,     0,     0,     0,
       0,   187,     0,     0,     0,   407,     0,     0,     0,   187,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,   438,   187,
       0,     0,     0,   440,   187,     0,     0,     0,     0,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,     0,
       0,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,     0,     0,     0,     0,   458,
       0,   164,   165,   166,   167,   168,   187,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    16,     0,     0,
      18,   187,   179,   180,     0,     0,     0,     0,   219,     0,
     181,   182,   114,     0,     0,   183,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   184,
     185,   177,   178,    16,     0,     0,    18,     0,   179,   180,
       0,     0,     0,     0,     0,     0,   181,   182,   114,     0,
     187,   183,   187,   187,     0,     0,     0,     0,   116,   187,
       0,   117,   118,     0,     0,   119,   120,   121,   122,   187,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      16,   133,     0,    18,   134,     0,     0,   187,     0,     0,
     187,     0,   187,   135,     0,   184,   185,     0,   159,   160,
     161,     0,   162,   163,     0,   164,   165,   166,   167,   168,
     187,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    16,     0,   197,    18,     0,   179,   180,     0,     0,
       0,     0,     0,     0,   181,   182,   114,     0,     0,   183,
       0,     0,     0,   136,     0,     0,     0,     0,     0,   159,
     160,   161,     0,   162,   163,     0,   164,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    16,     0,     0,    18,     0,   179,   180,     0,
       0,     0,   198,   184,   185,   181,   182,   114,     0,     0,
     183,   351,   352,     0,     0,   159,   160,   161,   310,   162,
     163,     0,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    16,     0,
       0,    18,     0,   179,   180,     0,     0,     0,     0,     0,
       0,   181,   182,   114,   184,   185,   183,   159,   160,   161,
       0,   162,   163,     0,   164,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
      16,     0,   311,    18,     0,   179,   180,     0,     0,     0,
       0,     0,     0,   181,   182,   114,     0,     0,   183,     0,
     184,   185,     0,   159,   160,   161,     0,   162,   163,     0,
     164,   165,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,    16,     0,     0,    18,
       0,   179,   180,     0,     0,     0,     0,     0,     0,   181,
     182,   114,   184,   185,   183,   345,     0,     0,     0,   159,
     160,   161,     0,   162,   163,     0,   164,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    16,     0,     0,    18,     0,   179,   180,     0,
       0,     0,     0,     0,     0,   181,   182,   114,   184,   185,
     183,     0,   353,     0,     0,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    16,     0,
     388,    18,     0,   179,   180,     0,     0,     0,     0,     0,
       0,   181,   182,   114,   184,   185,   183,   159,   160,   161,
       0,   162,   163,     0,   164,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
      16,     0,     0,    18,     0,   179,   180,     0,     0,     0,
       0,     0,     0,   181,   182,   114,     0,   405,   183,     0,
     184,   185,     0,   159,   160,   161,     0,   162,   163,     0,
     164,   165,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,    16,     0,     0,    18,
       0,   179,   180,     0,     0,     0,     0,     0,     0,   181,
     182,   114,   184,   185,   183,   437,   159,   160,   161,     0,
     162,   163,     0,   164,   165,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    16,
       0,     0,    18,     0,   179,   180,     0,     0,     0,     0,
       0,     0,   181,   182,   114,     0,     0,   183,   184,   185,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,   162,   163,     0,   164,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
      16,     0,   455,    18,     0,   179,   180,     0,     0,     0,
    -261,   184,   185,   181,   182,   114,     0,     0,   183,   159,
     160,   161,     0,   162,   163,     0,   164,   165,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    16,     0,     0,    18,     0,   179,   180,     0,
       0,     0,     0,     0,     0,   181,   182,   114,     0,     0,
     183,     0,   184,   185,     0,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,    16,     0,
       0,    18,     0,   179,   180,     0,     0,     0,     0,     0,
       0,   181,   182,   236,   184,   185,   183,  -207,  -207,  -207,
       0,  -207,  -207,     0,  -207,  -207,  -207,  -207,  -207,     0,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
       0,     0,     0,     0,     0,  -207,  -207,     0,     0,     0,
       0,     0,     0,  -207,  -207,  -207,     0,     0,     0,     0,
     184,   185,  -216,  -216,  -216,     0,  -216,  -216,     0,  -216,
    -216,  -216,  -216,  -216,     0,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,     0,     0,     0,     0,     0,
    -216,  -216,     0,     0,     0,     0,     0,     0,  -216,  -216,
    -216,     0,  -207,  -207,   165,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    16,
       0,     0,    18,     0,   179,   180,     0,     0,     0,     0,
       0,    15,   181,   182,   114,     0,     0,   183,     0,     0,
       0,     0,    16,    17,     0,    18,     0,  -216,  -216,     0,
       0,     0,    19,     0,     0,     0,     0,     0,   237,     0,
      20,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,     0,     0,    28,     0,    29,    30,    31,    32,    33,
       0,   184,   185,    34,     0,    35,    36,    37,   323,   324,
      38,    39,     0,    15,     0,     0,    40,     0,    41,     0,
       0,    42,     0,     0,    16,    17,    43,    18,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
     470,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,    15,     0,    34,     0,    35,    36,    37,
       0,     0,    38,    39,    16,    17,     0,    18,    40,     0,
      41,   471,     0,    42,    19,     0,     0,     0,    43,     0,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,    15,     7,    34,     0,    35,    36,    37,
       0,     0,    38,    39,    16,    17,     0,    18,    40,     0,
      41,     0,     0,    42,    19,     0,     0,     0,    43,     0,
     237,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,    15,     0,    34,     0,    35,    36,    37,
       0,     0,    38,    39,    16,    17,     0,    18,    40,     0,
      41,     0,     0,    42,    19,     0,     0,     0,    43,   114,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,    15,     0,    34,     0,    35,    36,    37,
       0,     0,    38,    39,    16,    17,     0,    18,    40,     0,
      41,     0,     0,    42,    19,     0,     0,     0,    43,     0,
     327,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,    15,     0,    34,     0,    35,    36,    37,
       0,     0,    38,    39,    16,    17,     0,    18,    40,     0,
      41,     0,     0,    42,    19,     0,     0,     0,    43,     0,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,     0,     0,     0,    34,     0,    35,    36,    37,
       0,     0,    38,    39,     0,     0,     0,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,     0,    43,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    16,
       0,     0,    18,     0,   179,   180,     0,    15,     0,     0,
       0,     0,   181,   182,   114,     0,     0,   183,    16,    17,
       0,    18,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,    20,    15,     0,     0,
      21,    91,    23,    24,    25,    26,    27,     0,    16,    17,
       0,    18,     0,     0,     0,     0,     0,     0,    90,    34,
       0,   184,   185,     0,     0,     0,    20,    15,     0,     0,
      21,   215,    23,    24,    25,    26,    27,    42,    16,    17,
       0,    18,     0,     0,     0,     0,     0,     0,    90,    34,
       0,     0,     0,     0,     0,     0,    20,    15,     0,     0,
      21,   253,    23,    24,    25,    26,    27,    42,    16,    17,
       0,    18,     0,     0,     0,     0,     0,     0,    90,    34,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      21,   336,    23,    24,    25,    26,    27,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42
};

static const yytype_int16 yycheck[] =
{
       8,     8,   102,   149,    96,    31,    45,     8,     8,   233,
     209,   302,   309,   105,   311,    12,     5,    96,     3,   233,
       5,    12,   394,    65,    37,     3,    49,     5,    11,   108,
      28,    44,    27,     4,    27,    66,    49,    45,    45,     0,
      11,    27,    27,   242,    45,   244,    41,    15,    42,    27,
      27,    44,   394,    28,    27,    41,    49,   429,    26,    27,
      44,    29,   141,    28,    28,    49,    28,    44,    36,    28,
     361,    44,    49,    41,    44,    88,    44,    28,   277,    28,
      48,    49,    50,    51,    52,    53,    54,   429,    96,    87,
      87,   315,   383,    87,   385,    88,    87,   105,    87,    67,
     108,   315,    87,    45,    88,    88,   114,   114,   399,    87,
      49,    88,    87,   114,    46,    88,   195,    85,    88,   158,
       4,   394,    87,    87,   415,    87,    22,    49,    87,    29,
     209,    31,    32,   141,   333,    49,    87,    44,    87,    39,
      40,    41,    49,     4,    44,    87,    28,     3,    87,     5,
     158,   158,    27,    49,    50,    87,   429,   158,   455,     3,
     260,     5,     3,   242,     5,   244,     3,    49,     5,    27,
     394,    27,   198,    20,    21,    22,    23,    24,    25,    26,
      42,    88,    29,    27,    31,    32,    27,   195,    88,    89,
      27,    49,    39,    40,    41,    62,    27,    44,   277,   238,
      28,   209,   414,   295,   416,   429,    27,    74,    36,    27,
      72,    73,   424,    48,    50,    50,    27,   296,    49,    49,
      48,    41,    50,    90,   370,   233,    49,    50,   236,   236,
     238,   238,   444,    36,   242,   236,   244,   238,    49,    42,
      49,    88,    89,    76,    77,    48,    15,    50,    39,    36,
      50,   450,    36,     3,   333,     5,   335,    26,    27,    49,
      29,    48,    53,    50,    48,    50,    50,    36,    87,   277,
     309,    15,   311,    27,    27,    44,    58,    46,    49,    48,
      49,    50,    51,    52,    53,    54,    87,   295,   296,    41,
       3,    27,    41,   301,    28,    76,    27,    27,    67,    11,
       4,   309,   309,   311,   311,    11,    49,   315,   309,   100,
     311,    49,    27,    87,    36,    43,    85,    28,    28,    27,
     328,    50,    27,    87,    50,   333,    48,   335,    50,    46,
       3,    49,     3,   341,    28,     3,    45,    28,    28,    46,
      17,     5,    64,    20,    46,    48,    46,    69,    41,    28,
     358,   142,    49,    28,    31,    50,    78,    79,    80,    28,
      37,    83,    84,    49,    41,    42,    87,   158,     3,   377,
     377,   450,   411,    49,    46,   475,   377,   377,   169,    49,
      27,    41,    28,    28,    27,    42,   394,     8,   429,    85,
     315,   105,   374,   296,    71,   307,   325,   335,   240,    -1,
     439,   409,   409,   411,   411,   413,    -1,    -1,   409,   409,
     411,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,   429,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,   439,   439,   472,    -1,    -1,    -1,    -1,   439,    -1,
      -1,    -1,   450,    -1,    -1,    -1,    -1,   455,   455,    -1,
      -1,    -1,   460,    -1,   455,    -1,    -1,    -1,    -1,   467,
     467,    -1,    -1,    -1,   472,   472,   467,   467,    -1,    -1,
      -1,   472,   149,   150,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    -1,    -1,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    40,    -1,   305,    -1,    -1,    -1,   309,   196,
     311,   198,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,    26,    27,   329,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    44,    45,    -1,   234,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    95,    -1,   360,
      -1,    99,    -1,   250,    -1,    -1,    -1,    67,    -1,    -1,
      -1,   258,   259,   260,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,   387,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,   140,    -1,    -1,   143,    39,    40,    41,    -1,
      -1,    44,    -1,   414,    -1,   416,    36,    -1,   305,   157,
     307,    -1,    42,   424,    -1,   312,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,   436,   323,    -1,    -1,    -1,
     441,    -1,    -1,   444,    64,    -1,    -1,   448,   449,    69,
      -1,    -1,    -1,    -1,   455,    88,    89,    -1,    78,    79,
      80,    -1,   349,    83,    84,   352,   353,    -1,   469,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,   372,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,   257,
      -1,    -1,    -1,   410,   262,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,    -1,
      -1,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,    -1,    -1,    -1,    -1,   446,
      -1,    10,    11,    12,    13,    14,   304,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,   319,    31,    32,    -1,    -1,    -1,    -1,   475,    -1,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,    -1,   367,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    88,
      89,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
     398,    44,   400,   401,    -1,    -1,    -1,    -1,     4,   407,
      -1,     7,     8,    -1,    -1,    11,    12,    13,    14,   417,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    -1,   435,    -1,    -1,
     438,    -1,   440,    39,    -1,    88,    89,    -1,     3,     4,
       5,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
     458,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    87,    88,    89,    39,    40,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    88,    89,    44,     3,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,    -1,
      88,    89,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    88,    89,    44,    45,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    88,    89,
      44,    -1,    46,    -1,    -1,     3,     4,     5,    -1,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    88,    89,    44,     3,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,
      88,    89,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    88,    89,    44,    45,     3,     4,     5,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      87,    88,    89,    39,    40,    41,    -1,    -1,    44,     3,
       4,     5,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      44,    -1,    88,    89,    -1,     3,     4,     5,    -1,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    88,    89,    44,     3,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      88,    89,     3,     4,     5,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    88,    89,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    15,    39,    40,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    88,    89,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      -1,    88,    89,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    15,    -1,    -1,    80,    -1,    82,    -1,
      -1,    85,    -1,    -1,    26,    27,    90,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    15,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    26,    27,    -1,    29,    80,    -1,
      82,    83,    -1,    85,    36,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    15,    66,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    26,    27,    -1,    29,    80,    -1,
      82,    -1,    -1,    85,    36,    -1,    -1,    -1,    90,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    15,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    26,    27,    -1,    29,    80,    -1,
      82,    -1,    -1,    85,    36,    -1,    -1,    -1,    90,    41,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    15,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    26,    27,    -1,    29,    80,    -1,
      82,    -1,    -1,    85,    36,    -1,    -1,    -1,    90,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    15,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    26,    27,    -1,    29,    80,    -1,
      82,    -1,    -1,    85,    36,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    85,    -1,    -1,    -1,    -1,    90,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    29,    -1,    31,    32,    -1,    15,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    15,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,
      -1,    88,    89,    -1,    -1,    -1,    44,    15,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    85,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    15,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    85,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    92,    94,    49,    93,     0,    66,    95,    96,
       4,    27,    49,    97,    98,    15,    26,    27,    29,    36,
      44,    48,    49,    50,    51,    52,    53,    54,    57,    59,
      60,    61,    62,    63,    67,    69,    70,    71,    74,    75,
      80,    82,    85,    90,    96,   101,   102,   103,   106,   108,
     114,   115,   123,   126,   129,   130,   132,   133,   134,   135,
     136,   137,   140,   141,   142,   143,   147,   151,   152,   153,
     154,   156,   158,   159,   162,   166,   171,   172,   174,   175,
     177,   178,   179,   180,   181,   182,    49,    98,    99,     4,
      36,    49,   129,   137,   174,   175,    27,    49,   105,   175,
       3,     5,    27,    87,     4,    11,    27,    27,    27,   105,
      49,    49,    50,   175,    41,   100,     4,     7,     8,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    27,    30,    39,    89,   155,   156,   157,
     175,    46,   148,   175,    50,   102,    50,   100,   144,    27,
      44,    49,    88,    49,    87,     5,    87,   175,    58,     3,
       4,     5,     7,     8,    10,    11,    12,    13,    14,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    31,
      32,    39,    40,    44,    88,    89,   100,   156,    15,   114,
      28,    98,    22,    49,    50,    27,    27,    28,    87,    28,
      36,    50,   106,   107,   129,   130,   131,   145,   146,    27,
      45,    87,   100,   175,   175,    49,   104,   138,   139,   175,
      49,    49,    50,   129,   130,   131,   160,   175,   176,   175,
     106,   129,   173,    41,     3,    41,    41,    42,   101,    76,
     167,   168,    27,    28,    27,   106,   129,   149,   150,   100,
      27,    11,   112,    49,   136,   138,    45,   175,     3,     5,
      27,    49,   175,    49,   100,   102,   161,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,    27,   100,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   129,   105,    27,    87,    37,    44,    49,
      28,    87,    28,   146,   175,     3,    28,    87,    12,    28,
       6,    28,    43,    36,   124,   125,   126,   129,   132,   175,
      50,   109,   110,    72,    73,   163,   164,    42,    27,    77,
     168,   170,   146,    27,   146,    87,    49,   175,   183,    50,
     113,    46,   111,    28,    28,    45,   175,   175,   138,     3,
     146,    45,    46,    46,    28,   106,   145,    49,    46,   129,
     148,    28,   175,   139,   161,    48,   161,   175,    42,   124,
      27,    49,     3,    42,    87,   165,   175,    46,    42,   164,
     129,   169,   100,    28,   146,    28,   149,     3,    28,    28,
      87,    12,    87,   129,    41,   122,     5,    28,   175,    28,
     175,   175,   129,   100,   148,    43,    49,   175,   110,    46,
      87,   101,    49,    87,   148,    28,   148,   175,    49,    50,
      64,    78,    79,    83,    84,   103,   116,   117,   120,   121,
     127,   128,   132,   143,   147,   175,   148,    45,   175,   101,
     175,    28,   129,   144,   148,   144,     3,    46,    49,    49,
      27,   144,    42,   116,   100,    28,   100,   144,   175,   100,
      27,   100,   146,   161,   129,    28,    49,    41,   118,    28,
      42,    83,   101,   119,   100,    27,    42,   138,    28
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
#line 62 "hobby.yy"
    { setPackageLines((yyvsp[(3) - (3)].expr)); ;}
    break;

  case 3:
#line 66 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 4:
#line 67 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 5:
#line 71 "hobby.yy"
    { (yyval.expr)=packageName((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 6:
#line 72 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 10:
#line 89 "hobby.yy"
    { packageImport( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 11:
#line 90 "hobby.yy"
    { packageImport( (yyvsp[(3) - (4)].expr) ); ;}
    break;

  case 12:
#line 94 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str)); ;}
    break;

  case 13:
#line 95 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 14:
#line 99 "hobby.yy"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), "*"); ;}
    break;

  case 15:
#line 100 "hobby.yy"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 16:
#line 101 "hobby.yy"
    { (yyval.expr)=importName((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str), true); ;}
    break;

  case 18:
#line 106 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 19:
#line 110 "hobby.yy"
    { (yyval.expr)=makeEmpty(); ;}
    break;

  case 20:
#line 111 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 22:
#line 116 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 42:
#line 142 "hobby.yy"
    { (yyval.expr)=makeConst((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].expr)); ;}
    break;

  case 43:
#line 145 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 45:
#line 150 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 46:
#line 155 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 47:
#line 156 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (4)].tp), (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 48:
#line 157 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (2)].tp), (yyvsp[(2) - (2)].str)); ;}
    break;

  case 50:
#line 162 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:
#line 168 "hobby.yy"
    { (yyval.expr)=createEnum((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 53:
#line 173 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 54:
#line 177 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr));  ;}
    break;

  case 55:
#line 178 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (1)].str),nullptr); ;}
    break;

  case 56:
#line 185 "hobby.yy"
    { (yyval.tp)=nullptr; ;}
    break;

  case 57:
#line 186 "hobby.yy"
    { (yyval.tp)=(yyvsp[(2) - (2)].tp); ;}
    break;

  case 58:
#line 190 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 59:
#line 191 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 60:
#line 195 "hobby.yy"
    { (yyval.expr)=createNode((yyvsp[(1) - (1)].str)); ;}
    break;

  case 61:
#line 196 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), createNode((yyvsp[(3) - (3)].str))); ;}
    break;

  case 62:
#line 201 "hobby.yy"
    { (yyval.expr)=makeClass((yyvsp[(1) - (5)].type),(yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].expr), (yyvsp[(4) - (5)].tp), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 63:
#line 202 "hobby.yy"
    { (yyval.expr)=annotationdClass((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 64:
#line 206 "hobby.yy"
    { (yyval.type)=0; ;}
    break;

  case 65:
#line 207 "hobby.yy"
    { (yyval.type)=1; ;}
    break;

  case 73:
#line 218 "hobby.yy"
    { (yyval.expr)=setProtected(); ;}
    break;

  case 75:
#line 225 "hobby.yy"
    { (yyval.expr)=createFunction(2, "Init", (yyvsp[(3) - (5)].expr), nullptr, (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 76:
#line 229 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 77:
#line 230 "hobby.yy"
    { (yyval.expr)=makeEmpty(); ;}
    break;

  case 78:
#line 231 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 79:
#line 235 "hobby.yy"
    { (yyval.expr)=makeCall("Init", (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 81:
#line 241 "hobby.yy"
    { (yyval.expr)=createFunction(3, "Finalize", nullptr, nullptr, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 83:
#line 246 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 84:
#line 249 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 86:
#line 257 "hobby.yy"
    { (yyval.tp)=createInterface((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 90:
#line 267 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 91:
#line 272 "hobby.yy"
    { (yyval.expr)=createFunction(0, (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].expr), nullptr); ;}
    break;

  case 92:
#line 279 "hobby.yy"
    { (yyval.expr)=makeGet((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 93:
#line 283 "hobby.yy"
    { (yyval.expr)=makeSet((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].tp), (yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 94:
#line 284 "hobby.yy"
    { (yyval.expr)=makeSet((yyvsp[(2) - (3)].str), nullptr, nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 95:
#line 297 "hobby.yy"
    { (yyval.tp)=getClassType((yyvsp[(1) - (1)].str)); ;}
    break;

  case 96:
#line 298 "hobby.yy"
    { (yyval.tp)=getClassType((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].tp)); ;}
    break;

  case 97:
#line 299 "hobby.yy"
    { (yyval.tp)=getType((yyvsp[(1) - (1)].type)); ;}
    break;

  case 98:
#line 300 "hobby.yy"
    { (yyval.tp)=makeArray((yyvsp[(1) - (3)].tp)); ;}
    break;

  case 99:
#line 301 "hobby.yy"
    { (yyval.tp)=nullAble((yyvsp[(1) - (2)].tp)); ;}
    break;

  case 100:
#line 305 "hobby.yy"
    { (yyval.tp)=getFuncType(); ;}
    break;

  case 101:
#line 306 "hobby.yy"
    { (yyval.tp)=getFuncType(NULL); ;}
    break;

  case 102:
#line 307 "hobby.yy"
    { (yyval.tp)=getFuncType((yyvsp[(3) - (4)].tp), NULL); ;}
    break;

  case 103:
#line 308 "hobby.yy"
    { (yyval.tp)=getFuncType((yyvsp[(3) - (6)].tp), (yyvsp[(6) - (6)].tp)); ;}
    break;

  case 106:
#line 314 "hobby.yy"
    { (yyval.tp)=link((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].tp)); ;}
    break;

  case 107:
#line 318 "hobby.yy"
    { (yyval.expr)=createDef((yyvsp[(1) - (1)].expr)); ;}
    break;

  case 108:
#line 319 "hobby.yy"
    { (yyval.expr)=appendDef((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].str)); ;}
    break;

  case 109:
#line 320 "hobby.yy"
    { (yyval.expr)=appendDef((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 110:
#line 321 "hobby.yy"
    { (yyval.expr)=tupleResolve(let((yyvsp[(2) - (4)].str)), (yyvsp[(4) - (4)].expr), true); ;}
    break;

  case 111:
#line 322 "hobby.yy"
    { (yyval.expr)=tupleResolve((yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), true); ;}
    break;

  case 112:
#line 326 "hobby.yy"
    { (yyval.expr)=makeSequence( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 113:
#line 334 "hobby.yy"
    { (yyval.expr)=makeTuple((yyvsp[(4) - (5)].expr), (yyvsp[(2) - (5)].expr)); ;}
    break;

  case 114:
#line 338 "hobby.yy"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 115:
#line 342 "hobby.yy"
    { (yyval.expr)=link(let((yyvsp[(1) - (3)].str)), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 116:
#line 343 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), let((yyvsp[(3) - (3)].str))); ;}
    break;

  case 117:
#line 350 "hobby.yy"
    { (yyval.expr)=makeCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 118:
#line 354 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 120:
#line 356 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 123:
#line 371 "hobby.yy"
    { (yyval.expr)=createNew((yyvsp[(1) - (5)].tp), (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 124:
#line 375 "hobby.yy"
    { (yyval.expr)=makeDelete((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 125:
#line 381 "hobby.yy"
    { (yyval.expr)=createNewArray((yyvsp[(1) - (4)].tp), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 126:
#line 389 "hobby.yy"
    { (yyval.expr)=addFunctionBlock((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 127:
#line 393 "hobby.yy"
    { (yyval.expr)=NULL; ;}
    break;

  case 129:
#line 399 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].tp), (yyvsp[(3) - (3)].str), nullptr, 1); ;}
    break;

  case 130:
#line 404 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 132:
#line 406 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 134:
#line 416 "hobby.yy"
    { (yyval.expr)=createOperator((yyvsp[(2) - (7)].type), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 135:
#line 418 "hobby.yy"
    { (yyval.expr)=createOperator(BBRACKETS, (yyvsp[(5) - (8)].expr), (yyvsp[(7) - (8)].expr), (yyvsp[(8) - (8)].expr)); ;}
    break;

  case 136:
#line 420 "hobby.yy"
    { (yyval.expr)=createOperator(ARRAY, (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr)); ;}
    break;

  case 137:
#line 424 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 138:
#line 425 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 140:
#line 430 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 142:
#line 435 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 143:
#line 440 "hobby.yy"
    { (yyval.expr)=createFunction(6, "", (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 144:
#line 449 "hobby.yy"
    { (yyval.expr)=makeArrayCall((yyvsp[(1) - (3)].expr), createFunction(6, "", NULL, NULL, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 145:
#line 451 "hobby.yy"
    { (yyval.expr)=makeArrayCall((yyvsp[(1) - (7)].expr), createFunction(6, "", (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), (yyvsp[(7) - (7)].expr))); ;}
    break;

  case 146:
#line 456 "hobby.yy"
    { (yyval.expr)=createGo(createFunction(6, "", nullptr, (yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 147:
#line 457 "hobby.yy"
    { (yyval.expr)=createGo((yyvsp[(2) - (2)].expr)); ;}
    break;

  case 148:
#line 462 "hobby.yy"
    { (yyval.expr)=callReturn(); ;}
    break;

  case 149:
#line 463 "hobby.yy"
    { (yyval.expr)=callReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 150:
#line 468 "hobby.yy"
    { (yyval.type)='+'; ;}
    break;

  case 151:
#line 469 "hobby.yy"
    { (yyval.type)='-'; ;}
    break;

  case 152:
#line 470 "hobby.yy"
    { (yyval.type)='*'; ;}
    break;

  case 153:
#line 471 "hobby.yy"
    { (yyval.type)='/'; ;}
    break;

  case 154:
#line 472 "hobby.yy"
    { (yyval.type)='&'; ;}
    break;

  case 155:
#line 473 "hobby.yy"
    { (yyval.type)='|'; ;}
    break;

  case 156:
#line 474 "hobby.yy"
    { (yyval.type)='!'; ;}
    break;

  case 157:
#line 475 "hobby.yy"
    { (yyval.type)='<'; ;}
    break;

  case 158:
#line 476 "hobby.yy"
    { (yyval.type)='>'; ;}
    break;

  case 159:
#line 477 "hobby.yy"
    { (yyval.type)='%'; ;}
    break;

  case 160:
#line 478 "hobby.yy"
    { (yyval.type)='.'; ;}
    break;

  case 161:
#line 479 "hobby.yy"
    { (yyval.type)=LEFTMOVE; ;}
    break;

  case 162:
#line 480 "hobby.yy"
    { (yyval.type)=RIGHTMOVE; ;}
    break;

  case 163:
#line 481 "hobby.yy"
    { (yyval.type)=URIGHTMOVE; ;}
    break;

  case 164:
#line 482 "hobby.yy"
    { (yyval.type)=LEQ; ;}
    break;

  case 165:
#line 483 "hobby.yy"
    { (yyval.type)=REQ; ;}
    break;

  case 166:
#line 484 "hobby.yy"
    { (yyval.type)=RGO; ;}
    break;

  case 167:
#line 485 "hobby.yy"
    { (yyval.type)=OR; ;}
    break;

  case 168:
#line 486 "hobby.yy"
    { (yyval.type)=AND; ;}
    break;

  case 169:
#line 490 "hobby.yy"
    { (yyval.type)='^'; ;}
    break;

  case 170:
#line 491 "hobby.yy"
    { (yyval.type)='~'; ;}
    break;

  case 173:
#line 504 "hobby.yy"
    { (yyval.expr)=makeIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 174:
#line 508 "hobby.yy"
    { (yyval.expr)=setElse((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 180:
#line 525 "hobby.yy"
    { (yyval.expr)=createSwitch((yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 182:
#line 530 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 183:
#line 534 "hobby.yy"
    { (yyval.expr)=createCase((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 184:
#line 535 "hobby.yy"
    { (yyval.expr)=createCase(nullptr, (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 186:
#line 540 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 187:
#line 547 "hobby.yy"
    { (yyval.expr)=createTry( (yyvsp[(2) - (4)].expr), (yyvsp[(3) - (4)].expr), (yyvsp[(4) - (4)].expr) ); ;}
    break;

  case 188:
#line 551 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 190:
#line 553 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (2)].expr),(yyvsp[(2) - (2)].expr)); ;}
    break;

  case 191:
#line 557 "hobby.yy"
    { (yyval.expr)=makeCatch((yyvsp[(3) - (6)].expr), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].expr)); ;}
    break;

  case 192:
#line 561 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (1)].tp)); ;}
    break;

  case 193:
#line 562 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (3)].expr),let((yyvsp[(3) - (3)].tp))); ;}
    break;

  case 194:
#line 566 "hobby.yy"
    { (yyval.expr)=nullptr; ;}
    break;

  case 195:
#line 567 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (2)].expr); ;}
    break;

  case 196:
#line 575 "hobby.yy"
    { (yyval.expr)=makeWhile((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 197:
#line 579 "hobby.yy"
    { (yyval.expr)=makeFor( (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)); ;}
    break;

  case 200:
#line 589 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 201:
#line 590 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str), createFunction(6, "", nullptr, nullptr, (yyvsp[(3) - (3)].expr))); ;}
    break;

  case 202:
#line 591 "hobby.yy"
    { (yyval.expr)=tupleResolve((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 203:
#line 592 "hobby.yy"
    { (yyval.expr)=binary('=', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 211:
#line 606 "hobby.yy"
    { (yyval.expr)=makeNull(); ;}
    break;

  case 212:
#line 607 "hobby.yy"
    { (yyval.expr)=getVar((yyvsp[(1) - (1)].str)); ;}
    break;

  case 213:
#line 608 "hobby.yy"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); ;}
    break;

  case 214:
#line 609 "hobby.yy"
    { (yyval.expr)=unary((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 215:
#line 610 "hobby.yy"
    { (yyval.expr)=unaryAfter((yyvsp[(2) - (2)].type), (yyvsp[(1) - (2)].expr)); ;}
    break;

  case 220:
#line 615 "hobby.yy"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr)); ;}
    break;

  case 221:
#line 616 "hobby.yy"
    { (yyval.expr)=makeInc((yyvsp[(1) - (2)].expr), false); ;}
    break;

  case 222:
#line 617 "hobby.yy"
    { (yyval.expr)=makeIIF(makeIsNull((yyvsp[(1) - (3)].expr)), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 223:
#line 618 "hobby.yy"
    { (yyval.expr)=makeIIF((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));;}
    break;

  case 224:
#line 619 "hobby.yy"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 225:
#line 620 "hobby.yy"
    { (yyval.expr)=makeGetConstValue((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); ;}
    break;

  case 226:
#line 621 "hobby.yy"
    { (yyval.expr)=createNew((yyvsp[(1) - (4)].tp), NULL, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 227:
#line 622 "hobby.yy"
    { (yyval.expr)=binary('+', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 228:
#line 623 "hobby.yy"
    { (yyval.expr)=binary('-', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 229:
#line 624 "hobby.yy"
    { (yyval.expr)=binary('*', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 230:
#line 625 "hobby.yy"
    { (yyval.expr)=binary('/', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 231:
#line 626 "hobby.yy"
    { (yyval.expr)=binary('&', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 232:
#line 627 "hobby.yy"
    { (yyval.expr)=binary('|', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 233:
#line 628 "hobby.yy"
    { (yyval.expr)=binary('<', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 234:
#line 629 "hobby.yy"
    { (yyval.expr)=binary('>', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 235:
#line 630 "hobby.yy"
    { (yyval.expr)=binary('%', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 236:
#line 631 "hobby.yy"
    { (yyval.expr)=binary('.', (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 237:
#line 632 "hobby.yy"
    { (yyval.expr)=binary(LEFTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 238:
#line 633 "hobby.yy"
    { (yyval.expr)=binary(RIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 239:
#line 634 "hobby.yy"
    { (yyval.expr)=binary(URIGHTMOVE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 240:
#line 635 "hobby.yy"
    { (yyval.expr)=binary(LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 241:
#line 636 "hobby.yy"
    { (yyval.expr)=binary(REQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 242:
#line 637 "hobby.yy"
    { (yyval.expr)=binary(RGO, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 243:
#line 638 "hobby.yy"
    { (yyval.expr)=binary(EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 244:
#line 639 "hobby.yy"
    { (yyval.expr)=binary(AEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 245:
#line 640 "hobby.yy"
    { (yyval.expr)=binary(OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 246:
#line 641 "hobby.yy"
    { (yyval.expr)=binary(AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 247:
#line 642 "hobby.yy"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); ;}
    break;

  case 248:
#line 646 "hobby.yy"
    { (yyval.expr)=binaryIs((yyvsp[(1) - (3)].expr), getType((yyvsp[(3) - (3)].type)));  ;}
    break;

  case 250:
#line 651 "hobby.yy"
    {(yyval.expr)=stringCat((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr));;}
    break;

  case 255:
#line 659 "hobby.yy"
    { (yyval.expr)=(yyval.expr); ;}
    break;

  case 256:
#line 668 "hobby.yy"
    { (yyval.expr)=makeSplice((yyvsp[(1) - (6)].expr), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].expr)); ;}
    break;

  case 257:
#line 676 "hobby.yy"
    { (yyval.expr)=makeIndex((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 258:
#line 684 "hobby.yy"
    { (yyval.expr)=makeBased((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 259:
#line 690 "hobby.yy"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 260:
#line 691 "hobby.yy"
    { (yyval.expr)=makeAnnotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].expr)); ;}
    break;

  case 261:
#line 695 "hobby.yy"
    { (yyval.expr)=let((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].expr)); ;}
    break;

  case 262:
#line 696 "hobby.yy"
    { (yyval.expr)=link((yyvsp[(1) - (5)].expr), let((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].expr))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3175 "hobby.tab.cpp"
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


#line 699 "hobby.yy"

