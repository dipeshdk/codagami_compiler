/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELLIPSIS 303
#define CASE 304
#define DEFAULT 305
#define IF 306
#define ELSE 307
#define SWITCH 308
#define WHILE 309
#define DO 310
#define FOR 311
#define GOTO 312
#define CONTINUE 313
#define BREAK 314
#define RETURN 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "grammarOld.y"
struct node* nodes; char* id;

#line 243 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 27 "grammarOld.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symbolTable.h"
    extern int gScope;
    extern symbolTable* gSymTable;
    extern int line;


extern "C"
{
	// int yyparse (void);
	int yylex(void);  
	int yywrap();
	void yyset_in  ( FILE * _in_str  );
}

void yyerror(const char *s);
// int yylex();
extern char yytext[];
// typedef struct node{
// 	// int type;
// 	int id;
// 	char* name;
// 	char* lexeme;
// 	int isLeaf;
// 	struct node* next;
// 	struct node* childList;
// }node;

node* root;
  node* makeNode(char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);
	void makeSibling(node* root, node* childList);
	void addChild(node* parent, node* child);

#line 296 "y.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    74,    75,    76,    77,
      78,    79,    80,    81,    85,    86,    90,    91,    92,    93,
      94,    95,    99,   100,   101,   102,   103,   104,   108,   109,
     113,   114,   115,   116,   120,   121,   122,   126,   127,   128,
     132,   133,   134,   135,   136,   140,   141,   142,   146,   147,
     151,   152,   156,   157,   161,   162,   166,   167,   171,   172,
     176,   177,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   195,   196,   200,   204,   205,   209,   210,
     211,   212,   213,   214,   218,   219,   223,   224,   228,   229,
     230,   231,   232,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   251,   252,   253,   257,   258,
     262,   263,   267,   271,   272,   273,   274,   278,   279,   283,
     284,   285,   289,   290,   291,   295,   296,   300,   301,   305,
     306,   310,   311,   315,   316,   317,   318,   319,   320,   321,
     325,   326,   327,   328,   332,   333,   338,   339,   343,   344,
     348,   349,   350,   354,   355,   359,   360,   364,   365,   366,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   382,
     383,   384,   388,   389,   393,   394,   395,   396,   397,   398,
     402,   403,   404,   408,   409,   410,   411,   416,   419,   420,
     424,   425,   429,   430,   434,   435,   436,   440,   441,   442,
     443,   447,   448,   449,   450,   451,   455,   456,   460,   461,
     465,   466,   467,   468
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "scope_marker", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-188)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     982,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,    15,    56,   -19,  -235,    33,  1214,  1214,  -235,    16,
    -235,  1214,  1214,    62,    19,   892,  -235,  -235,   -49,    34,
      -8,  -235,  -235,   -19,  -235,   -25,  -235,  1094,  -235,  -235,
     -40,   243,  -235,  -235,    33,  -235,   -17,  1214,   421,   679,
      62,  -235,  -235,    34,    45,   -34,  -235,  -235,  -235,  -235,
      56,  -235,   537,  -235,  1214,   243,   243,  1017,  -235,     4,
     243,    92,   291,  -235,  -235,  -235,  -235,    22,    31,    30,
    -235,    98,  -235,  -235,  -235,   798,   819,   819,   658,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,   122,  -235,   843,
    -235,   135,     6,   156,    43,   187,   109,   107,   113,   195,
      13,  -235,   153,   -33,   843,    34,  -235,  -235,   537,   220,
    -235,  -235,  -235,  -235,  1037,  -235,  -235,  -235,   843,   -18,
    -235,   142,  -235,   147,   843,   154,   213,   215,   232,   572,
     241,   248,   223,   224,   588,  -235,  -235,  -235,    -3,  -235,
    -235,  -235,   361,   431,  -235,  -235,  -235,  -235,   937,   703,
    -235,    39,  -235,    72,  -235,  1193,  -235,   304,   658,  -235,
     843,  -235,  -235,   126,    59,   246,   306,  -235,  -235,   728,
     843,   307,  -235,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,  -235,  -235,  -235,  -235,  -235,   -22,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   843,
    -235,  -235,     4,  -235,   843,   572,   231,   572,   843,   843,
     843,   258,   607,   233,  -235,  -235,  -235,    50,   843,  -235,
    -235,   467,  -235,  -235,  -235,   251,   252,  -235,   254,    72,
    1158,   749,  -235,  -235,  -235,   277,  -235,  1117,   149,  -235,
     843,  -235,  -235,   127,  -235,   169,  -235,  -235,  -235,  -235,
     135,   135,     6,     6,   156,   156,   156,   156,    43,    43,
     187,   109,   107,   113,   195,   106,   501,  -235,  -235,  -235,
    -235,  -235,   572,  -235,   132,   158,   163,   255,   607,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,   281,  -235,   289,
    -235,  -235,  -235,   843,  -235,   843,  -235,  -235,  -235,   572,
     572,   572,   843,   773,  -235,  -235,  -235,  -235,   302,  -235,
    -235,   170,   572,   190,   572,   273,  -235,   572,  -235,  -235,
    -235
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   129,   130,    93,   108,
     109,     0,     0,   140,   209,     0,    78,    80,   102,     0,
     103,    82,   187,   132,     0,     0,   206,   208,   124,     0,
       0,   144,   142,   141,    76,     0,    84,    86,    79,    81,
     107,     0,    83,   188,     0,   213,     0,   187,     0,     0,
     131,     1,   207,     0,   127,     0,   125,   134,   145,   143,
       0,    77,     0,   211,   187,     0,   114,     0,   110,     0,
     116,    86,   187,   189,   212,   153,   139,   152,     0,   146,
     148,     0,     2,     3,     4,     0,     0,     0,     0,   136,
      22,    23,    24,    25,    26,    27,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    75,     0,     0,     0,     0,   122,    85,     0,    28,
      60,   169,    87,   210,     0,   113,   106,   111,     0,     0,
     117,   119,   115,     2,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,   192,   183,    73,     0,   190,
     174,   175,   187,   187,   176,   177,   178,   179,     0,     0,
     150,   157,   151,   158,   137,     0,   138,     0,     0,    20,
       0,    17,    18,     0,   155,     0,     0,    12,    13,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   123,   128,   126,   172,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    62,     0,
     105,   120,     0,   112,     0,   187,     0,   187,     0,     0,
       0,     0,     0,     0,   202,   203,   204,     0,     0,   193,
     185,   187,   184,   191,   165,     0,     0,   161,     0,   159,
       0,     0,   147,   149,   154,     0,     5,     0,   157,   156,
       0,    11,     8,     0,    14,     0,    10,    31,    32,    33,
      35,    36,    38,    39,    43,    44,    41,    42,    46,    47,
      49,    51,    53,    55,    57,     0,     0,   170,    61,   118,
     121,   180,   187,   182,     0,     0,     0,     0,     0,   201,
     205,    74,   186,   166,   160,   162,   167,     0,   163,     0,
      21,    29,     9,     0,     7,     0,   171,   173,   181,   187,
     187,   187,     0,     0,   168,   164,    15,    59,   194,   196,
     197,     0,   187,     0,   187,     0,   199,   187,   195,   198,
     200
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,  -235,   -57,  -235,   -89,    69,    93,    61,
      99,   150,   161,   164,   148,   166,  -235,   -56,   -68,  -235,
     -83,   -35,    12,     0,  -235,   301,  -235,   120,  -235,  -235,
     299,   -24,   -70,  -235,   145,  -235,   315,   256,   139,    -9,
     -13,   -14,  -235,   -53,  -235,   204,  -235,   202,   -73,  -154,
    -127,  -235,   -72,  -235,   174,  -235,   -36,   221,  -234,  -235,
    -235,  -235,  -235,   347,  -235
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   273,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   130,   157,   229,
     158,   122,    53,    54,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   139,   140,    30,    65,    66,    31,    32,
      33,    34,    43,   255,    89,    90,    91,   185,   256,   173,
     132,   217,   159,   160,   161,    56,    57,   163,   164,   165,
     166,   167,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   216,   108,   121,   131,    88,   135,     1,   308,    42,
     142,    74,    24,    40,   172,   183,    47,   259,    38,    50,
     192,    60,     1,    16,    17,     1,    48,    49,   184,    69,
     210,    52,   125,   125,    63,    25,     1,    64,   179,   181,
     182,    70,     1,    75,   296,    81,   162,    24,   232,    23,
     126,   213,   108,   137,    67,   200,   201,    71,    87,     1,
     131,    81,   297,   248,   233,    22,    82,   108,   121,    83,
     141,   247,    23,   171,   333,   196,   197,   241,   170,   249,
      22,   108,   121,   168,   138,   169,    83,   108,   121,   214,
      23,   253,   211,   174,    22,   183,   175,   183,    39,    51,
     168,    23,   169,   231,   277,   278,   279,   275,   184,   236,
     137,   269,   108,   121,   259,    44,   248,    22,   202,   203,
     267,   274,   169,    58,    23,    59,   124,    23,   295,   186,
     187,   188,   310,   260,   258,   261,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   171,   304,   305,   306,    60,    40,
     176,   298,    41,   301,   177,   303,   198,   199,    87,   327,
     268,    76,   248,    72,    83,    87,   206,   108,   121,   253,
     311,   321,    68,   189,   207,   190,   325,   191,   266,   322,
      80,   208,   248,   323,   329,    76,    76,    76,   248,   300,
      76,   204,   205,   193,   108,   121,    55,   317,   194,   195,
     267,   209,   169,   108,    80,    80,    80,   212,    76,    80,
     330,    73,   234,   141,   248,   331,   319,   235,   131,   248,
     328,    84,   345,   324,   237,   248,   248,    80,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   133,   341,
     343,   243,   347,   268,    76,   336,   248,   338,   339,   340,
      87,   284,   285,   286,   287,   280,   281,    87,   108,   337,
     346,     2,   348,    80,   238,   350,   239,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   282,   283,   240,   143,    93,    94,    95,    76,    96,
      97,   228,   242,   288,   289,   244,   245,   264,   270,   271,
     276,   302,   307,   313,   314,   309,   332,    80,   315,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   320,
     144,   145,   146,   334,   147,   148,   149,   150,   151,   152,
     153,   154,    98,   335,   344,   349,   290,   293,   100,   101,
     102,   103,   104,   105,   143,    93,    94,    95,   291,    96,
      97,   127,   292,   155,   134,   156,   294,   299,   123,   263,
     265,   215,    62,   251,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,    98,     0,    85,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   143,    93,    94,    95,     0,    96,
      97,     0,     0,   155,     0,   250,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
     143,    93,    94,    95,     0,    96,    97,     0,     0,     0,
     144,   145,   146,    86,   147,   148,   149,   150,   151,   152,
     153,   154,    98,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,    92,    93,    94,    95,     0,    96,
      97,     0,     0,   155,     0,   252,   144,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,    98,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      92,    93,    94,    95,     0,    96,    97,     0,     0,   155,
       0,   312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,     0,   143,    93,    94,    95,     0,
      96,    97,     0,     0,   128,   326,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,    97,    98,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      92,    93,    94,    95,     0,    96,    97,     0,     0,     0,
     128,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,    98,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,    98,
       0,     0,     0,     0,   155,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,    98,     0,
     246,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,    92,    93,    94,    95,     2,    96,    97,   155,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,     0,     0,
      98,     0,     0,    99,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,     0,    98,     0,     0,   257,     0,     0,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,    98,
     272,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,     0,     0,
      98,     0,     0,   318,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,     0,    98,   342,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,   178,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    61,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   254,
     169,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     2,     0,     0,     0,     0,
      23,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,  -187,   267,   254,
     169,     0,     0,     0,     0,    23,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   262,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,   128,    59,    59,    72,    58,    76,     3,   242,    23,
      80,    47,     0,    22,    87,    98,    25,   171,     3,     3,
     109,    34,     3,    42,    43,     3,    26,    27,    98,    43,
      17,    31,    66,    66,    83,    35,     3,     3,    95,    96,
      97,    66,     3,    83,    66,    54,    82,    35,    66,    68,
      84,    84,   109,    77,    62,    12,    13,    82,    58,     3,
     128,    70,    84,    66,    82,    61,    83,   124,   124,    57,
      79,   154,    68,    87,   308,    69,    70,   149,    87,    82,
      61,   138,   138,    61,    80,    63,    74,   144,   144,   124,
      68,   163,    79,    62,    61,   178,    66,   180,    83,    83,
      61,    68,    63,   138,   193,   194,   195,   190,   178,   144,
     134,   184,   169,   169,   268,    82,    66,    61,    75,    76,
      61,   189,    63,    61,    68,    63,    81,    68,   211,     7,
       8,     9,    82,    61,   169,    63,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   168,   238,   239,   240,   171,   168,
      62,   229,    23,   235,    66,   237,    10,    11,   168,   296,
     184,    51,    66,    81,   162,   175,    67,   234,   234,   251,
     248,   270,    43,    61,    77,    63,    80,    65,    62,    62,
      51,    78,    66,    66,    62,    75,    76,    77,    66,   234,
      80,    14,    15,    68,   261,   261,    32,   260,    73,    74,
      61,    16,    63,   270,    75,    76,    77,    64,    98,    80,
      62,    47,    80,   232,    66,    62,   261,    80,   296,    66,
     302,    57,    62,    64,    80,    66,    66,    98,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    74,   332,
     333,     3,    62,   267,   134,   323,    66,   329,   330,   331,
     260,   200,   201,   202,   203,   196,   197,   267,   325,   325,
     342,    28,   344,   134,    61,   347,    61,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   198,   199,    61,     3,     4,     5,     6,   178,     8,
       9,    81,    61,   204,   205,    82,    82,     3,    62,     3,
       3,    80,    54,    62,    62,    82,    61,   178,    64,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    62,
      49,    50,    51,    62,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    64,    52,    82,   206,   209,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,   207,     8,
       9,    70,   208,    82,    75,    84,   210,   232,    63,   175,
     178,   125,    35,   162,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,     3,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      49,    50,    51,    62,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    -1,    84,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      83,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    82,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    61,    -1,
      82,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,     3,     4,     5,     6,    28,     8,     9,    82,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     0,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    28,    -1,    -1,    -1,    -1,
      68,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,   107,   108,   111,   112,   113,   114,
     120,   123,   124,   125,   126,   147,   148,   149,     3,    83,
     124,   123,   126,   127,    82,   109,   110,   124,   108,   108,
       3,    83,   108,   107,   108,   139,   140,   141,    61,    63,
     125,     0,   148,    83,     3,   121,   122,    62,   123,   126,
      66,    82,    81,   139,   141,    83,   112,   115,   116,   117,
     123,   124,    83,   107,   139,     3,    62,   108,   128,   129,
     130,   131,     3,     4,     5,     6,     8,     9,    61,    64,
      67,    68,    69,    70,    71,    72,    86,    87,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   106,   121,    81,    66,    84,   110,    83,    89,
     102,   103,   135,   139,   115,   117,    84,   116,    80,   118,
     119,   124,   117,     3,    49,    50,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    82,    84,   103,   105,   137,
     138,   139,   141,   142,   143,   144,   145,   146,    61,    63,
     124,   126,   133,   134,    62,    66,    62,    66,    61,    89,
      61,    89,    89,   105,   117,   132,     7,     8,     9,    61,
      63,    65,    91,    68,    73,    74,    69,    70,    10,    11,
      12,    13,    75,    76,    14,    15,    67,    77,    78,    16,
      17,    79,    64,    84,   106,   122,   135,   136,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    81,   104,
      84,   106,    66,    82,    80,    80,   106,    80,    61,    61,
      61,   137,    61,     3,    82,    82,    82,   105,    66,    82,
      84,   142,    84,   137,    62,   128,   133,    64,   106,   134,
      61,    63,    48,   130,     3,   132,    62,    61,   126,   133,
      62,     3,    62,    88,   103,   105,     3,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    97,    98,    99,   100,   105,    66,    84,   103,   119,
     106,   137,    80,   137,   105,   105,   105,    54,   143,    82,
      82,   103,    84,    62,    62,    64,    62,   128,    64,   106,
      62,    91,    62,    66,    64,    80,    84,   135,   137,    62,
      62,    62,    61,   143,    62,    64,   103,   102,   137,   137,
     137,   105,    62,   105,    52,    62,   137,    62,   137,    82,
     137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   149
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     4,     4,     5,     0,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 67 "grammarOld.y"
                     {(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); printf("%s",yylval.id);}
#line 1922 "y.tab.c"
    break;

  case 3:
#line 68 "grammarOld.y"
                        {printf("I am constant here\n"); (yyval.nodes) = makeNode(strdup("CONSTANT"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);printf("%s",yylval.id);}
#line 1928 "y.tab.c"
    break;

  case 4:
#line 69 "grammarOld.y"
                         {(yyval.nodes) = makeNode(strdup("STRING_LITERAL"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 1934 "y.tab.c"
    break;

  case 5:
#line 70 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 1940 "y.tab.c"
    break;

  case 6:
#line 74 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 1946 "y.tab.c"
    break;

  case 7:
#line 75 "grammarOld.y"
                                                {addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);}
#line 1952 "y.tab.c"
    break;

  case 8:
#line 76 "grammarOld.y"
                                     {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 1958 "y.tab.c"
    break;

  case 9:
#line 77 "grammarOld.y"
                                                              {addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);}
#line 1964 "y.tab.c"
    break;

  case 10:
#line 78 "grammarOld.y"
                                            { (yyval.nodes) = makeNode(strdup("."), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 1970 "y.tab.c"
    break;

  case 11:
#line 79 "grammarOld.y"
                                               {(yyval.nodes) = makeNode(strdup("PTR_OP"), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 1976 "y.tab.c"
    break;

  case 12:
#line 80 "grammarOld.y"
                                    {addChild((yyvsp[-1].nodes), makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));(yyval.nodes) = (yyvsp[-1].nodes);}
#line 1982 "y.tab.c"
    break;

  case 13:
#line 81 "grammarOld.y"
                                    {addChild((yyvsp[-1].nodes), makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 1988 "y.tab.c"
    break;

  case 14:
#line 85 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 1994 "y.tab.c"
    break;

  case 15:
#line 86 "grammarOld.y"
                                                             { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2000 "y.tab.c"
    break;

  case 16:
#line 90 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2006 "y.tab.c"
    break;

  case 17:
#line 91 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("INC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2012 "y.tab.c"
    break;

  case 18:
#line 92 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("DEC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2018 "y.tab.c"
    break;

  case 19:
#line 93 "grammarOld.y"
                                         { addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2024 "y.tab.c"
    break;

  case 20:
#line 94 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2030 "y.tab.c"
    break;

  case 21:
#line 95 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2036 "y.tab.c"
    break;

  case 22:
#line 99 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2042 "y.tab.c"
    break;

  case 23:
#line 100 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2048 "y.tab.c"
    break;

  case 24:
#line 101 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2054 "y.tab.c"
    break;

  case 25:
#line 102 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2060 "y.tab.c"
    break;

  case 26:
#line 103 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("~"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2066 "y.tab.c"
    break;

  case 27:
#line 104 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("!"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2072 "y.tab.c"
    break;

  case 28:
#line 108 "grammarOld.y"
                           {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2078 "y.tab.c"
    break;

  case 29:
#line 109 "grammarOld.y"
                                            { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else {(yyval.nodes) = (yyvsp[0].nodes);} }
#line 2084 "y.tab.c"
    break;

  case 30:
#line 113 "grammarOld.y"
                          {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2090 "y.tab.c"
    break;

  case 31:
#line 114 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2096 "y.tab.c"
    break;

  case 32:
#line 115 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("/"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2102 "y.tab.c"
    break;

  case 33:
#line 116 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("%"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2108 "y.tab.c"
    break;

  case 34:
#line 120 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2114 "y.tab.c"
    break;

  case 35:
#line 121 "grammarOld.y"
                                                            { (yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2120 "y.tab.c"
    break;

  case 36:
#line 122 "grammarOld.y"
                                                            { (yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2126 "y.tab.c"
    break;

  case 37:
#line 126 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2132 "y.tab.c"
    break;

  case 38:
#line 127 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("LEFT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2138 "y.tab.c"
    break;

  case 39:
#line 128 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("RIGHT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2144 "y.tab.c"
    break;

  case 40:
#line 132 "grammarOld.y"
                           { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2150 "y.tab.c"
    break;

  case 41:
#line 133 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup("<"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2156 "y.tab.c"
    break;

  case 42:
#line 134 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup(">"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2162 "y.tab.c"
    break;

  case 43:
#line 135 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("LE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2168 "y.tab.c"
    break;

  case 44:
#line 136 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("GE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2174 "y.tab.c"
    break;

  case 45:
#line 140 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2180 "y.tab.c"
    break;

  case 46:
#line 141 "grammarOld.y"
                                                          { (yyval.nodes) = makeNode(strdup("EQ_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2186 "y.tab.c"
    break;

  case 47:
#line 142 "grammarOld.y"
                                                          { (yyval.nodes) = makeNode(strdup("NE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2192 "y.tab.c"
    break;

  case 48:
#line 146 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2198 "y.tab.c"
    break;

  case 49:
#line 147 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2204 "y.tab.c"
    break;

  case 50:
#line 151 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2210 "y.tab.c"
    break;

  case 51:
#line 152 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup("^"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2216 "y.tab.c"
    break;

  case 52:
#line 156 "grammarOld.y"
                                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2222 "y.tab.c"
    break;

  case 53:
#line 157 "grammarOld.y"
                                                              { (yyval.nodes) = makeNode(strdup("|"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2228 "y.tab.c"
    break;

  case 54:
#line 161 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2234 "y.tab.c"
    break;

  case 55:
#line 162 "grammarOld.y"
                                                                { (yyval.nodes) = makeNode(strdup("AND_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2240 "y.tab.c"
    break;

  case 56:
#line 166 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2246 "y.tab.c"
    break;

  case 57:
#line 167 "grammarOld.y"
                                                             { (yyval.nodes) = makeNode(strdup("OR_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2252 "y.tab.c"
    break;

  case 58:
#line 171 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2258 "y.tab.c"
    break;

  case 59:
#line 172 "grammarOld.y"
                                                                          { (yyval.nodes) = makeNode(strdup("?:"), strdup(""), 0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL); }
#line 2264 "y.tab.c"
    break;

  case 60:
#line 176 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2270 "y.tab.c"
    break;

  case 61:
#line 177 "grammarOld.y"
                                                                     { addChild((yyvsp[-1].nodes), (yyvsp[-2].nodes)); addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2276 "y.tab.c"
    break;

  case 62:
#line 181 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2282 "y.tab.c"
    break;

  case 63:
#line 182 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2288 "y.tab.c"
    break;

  case 64:
#line 183 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2294 "y.tab.c"
    break;

  case 65:
#line 184 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2300 "y.tab.c"
    break;

  case 66:
#line 185 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2306 "y.tab.c"
    break;

  case 67:
#line 186 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2312 "y.tab.c"
    break;

  case 68:
#line 187 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("LEFT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2318 "y.tab.c"
    break;

  case 69:
#line 188 "grammarOld.y"
                       { (yyval.nodes) = makeNode(strdup("RIGHT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2324 "y.tab.c"
    break;

  case 70:
#line 189 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2330 "y.tab.c"
    break;

  case 71:
#line 190 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2336 "y.tab.c"
    break;

  case 72:
#line 191 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2342 "y.tab.c"
    break;

  case 73:
#line 195 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2348 "y.tab.c"
    break;

  case 74:
#line 196 "grammarOld.y"
                                               { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2354 "y.tab.c"
    break;

  case 75:
#line 200 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2360 "y.tab.c"
    break;

  case 76:
#line 204 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2366 "y.tab.c"
    break;

  case 77:
#line 205 "grammarOld.y"
                                                          { if((yyvsp[-2].nodes)){makeSibling((yyvsp[-1].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2372 "y.tab.c"
    break;

  case 78:
#line 209 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2378 "y.tab.c"
    break;

  case 79:
#line 210 "grammarOld.y"
                                                         {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2384 "y.tab.c"
    break;

  case 80:
#line 211 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2390 "y.tab.c"
    break;

  case 81:
#line 212 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2396 "y.tab.c"
    break;

  case 82:
#line 213 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2402 "y.tab.c"
    break;

  case 83:
#line 214 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2408 "y.tab.c"
    break;

  case 84:
#line 218 "grammarOld.y"
                          { (yyval.nodes) = (yyvsp[0].nodes);  }
#line 2414 "y.tab.c"
    break;

  case 85:
#line 219 "grammarOld.y"
                                                   { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2420 "y.tab.c"
    break;

  case 86:
#line 223 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2426 "y.tab.c"
    break;

  case 87:
#line 224 "grammarOld.y"
                                     { (yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 2432 "y.tab.c"
    break;

  case 88:
#line 228 "grammarOld.y"
                  {(yyval.nodes) = makeNode(strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2438 "y.tab.c"
    break;

  case 89:
#line 229 "grammarOld.y"
                 {(yyval.nodes) = makeNode(strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2444 "y.tab.c"
    break;

  case 90:
#line 230 "grammarOld.y"
                 {(yyval.nodes) = makeNode(strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2450 "y.tab.c"
    break;

  case 91:
#line 231 "grammarOld.y"
               {(yyval.nodes) = makeNode(strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2456 "y.tab.c"
    break;

  case 92:
#line 232 "grammarOld.y"
                   {(yyval.nodes) = makeNode(strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2462 "y.tab.c"
    break;

  case 93:
#line 236 "grammarOld.y"
               {(yyval.nodes) = NULL;}
#line 2468 "y.tab.c"
    break;

  case 94:
#line 237 "grammarOld.y"
               {(yyval.nodes) = NULL;}
#line 2474 "y.tab.c"
    break;

  case 95:
#line 238 "grammarOld.y"
                {(yyval.nodes) = NULL;}
#line 2480 "y.tab.c"
    break;

  case 96:
#line 239 "grammarOld.y"
              {(yyval.nodes) = NULL;}
#line 2486 "y.tab.c"
    break;

  case 97:
#line 240 "grammarOld.y"
               {(yyval.nodes) = NULL;}
#line 2492 "y.tab.c"
    break;

  case 98:
#line 241 "grammarOld.y"
                {(yyval.nodes) = NULL;}
#line 2498 "y.tab.c"
    break;

  case 99:
#line 242 "grammarOld.y"
                 {(yyval.nodes) = NULL;}
#line 2504 "y.tab.c"
    break;

  case 100:
#line 243 "grammarOld.y"
                 {(yyval.nodes) = NULL;}
#line 2510 "y.tab.c"
    break;

  case 101:
#line 244 "grammarOld.y"
                   {(yyval.nodes) = NULL;}
#line 2516 "y.tab.c"
    break;

  case 102:
#line 245 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2522 "y.tab.c"
    break;

  case 103:
#line 246 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2528 "y.tab.c"
    break;

  case 104:
#line 247 "grammarOld.y"
                    {(yyval.nodes) = NULL;}
#line 2534 "y.tab.c"
    break;

  case 105:
#line 251 "grammarOld.y"
                                                                     {(yyval.nodes) = NULL;}
#line 2540 "y.tab.c"
    break;

  case 106:
#line 252 "grammarOld.y"
                                                          {(yyval.nodes) = NULL;}
#line 2546 "y.tab.c"
    break;

  case 107:
#line 253 "grammarOld.y"
                                     {(yyval.nodes) = NULL;}
#line 2552 "y.tab.c"
    break;

  case 108:
#line 257 "grammarOld.y"
                 {(yyval.nodes) = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2558 "y.tab.c"
    break;

  case 109:
#line 258 "grammarOld.y"
                {(yyval.nodes) = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2564 "y.tab.c"
    break;

  case 110:
#line 262 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2570 "y.tab.c"
    break;

  case 111:
#line 263 "grammarOld.y"
                                                     { if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2576 "y.tab.c"
    break;

  case 112:
#line 267 "grammarOld.y"
                                                              {(yyval.nodes) = NULL;}
#line 2582 "y.tab.c"
    break;

  case 113:
#line 271 "grammarOld.y"
                                                  {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2588 "y.tab.c"
    break;

  case 114:
#line 272 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2594 "y.tab.c"
    break;

  case 115:
#line 273 "grammarOld.y"
                                                  {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2600 "y.tab.c"
    break;

  case 116:
#line 274 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2606 "y.tab.c"
    break;

  case 117:
#line 278 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2612 "y.tab.c"
    break;

  case 118:
#line 279 "grammarOld.y"
                                                       {(yyval.nodes) = NULL;}
#line 2618 "y.tab.c"
    break;

  case 119:
#line 283 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2624 "y.tab.c"
    break;

  case 120:
#line 284 "grammarOld.y"
                                  {(yyval.nodes) = NULL;}
#line 2630 "y.tab.c"
    break;

  case 121:
#line 285 "grammarOld.y"
                                             {(yyval.nodes) = NULL;}
#line 2636 "y.tab.c"
    break;

  case 122:
#line 289 "grammarOld.y"
                                       {(yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2642 "y.tab.c"
    break;

  case 123:
#line 290 "grammarOld.y"
                                                  { (yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2648 "y.tab.c"
    break;

  case 124:
#line 291 "grammarOld.y"
                          { (yyval.nodes) = (node*)NULL;}
#line 2654 "y.tab.c"
    break;

  case 125:
#line 295 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2660 "y.tab.c"
    break;

  case 126:
#line 296 "grammarOld.y"
                                         { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2666 "y.tab.c"
    break;

  case 127:
#line 300 "grammarOld.y"
                     {(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2672 "y.tab.c"
    break;

  case 128:
#line 301 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 2678 "y.tab.c"
    break;

  case 129:
#line 305 "grammarOld.y"
                {(yyval.nodes) = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2684 "y.tab.c"
    break;

  case 130:
#line 306 "grammarOld.y"
                   {(yyval.nodes) = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2690 "y.tab.c"
    break;

  case 131:
#line 310 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2696 "y.tab.c"
    break;

  case 132:
#line 311 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2702 "y.tab.c"
    break;

  case 133:
#line 315 "grammarOld.y"
                     { insertSymbol(gSymTable, line+1, yylval.id);printf("I am here  %d, scope = %d\n", line+1, gSymTable->scope);printf("%s\n", yylval.id); (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2708 "y.tab.c"
    break;

  case 134:
#line 316 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes);}
#line 2714 "y.tab.c"
    break;

  case 135:
#line 317 "grammarOld.y"
                                                        { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 2720 "y.tab.c"
    break;

  case 136:
#line 318 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[-2].nodes); }
#line 2726 "y.tab.c"
    break;

  case 137:
#line 319 "grammarOld.y"
                                                        { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 2732 "y.tab.c"
    break;

  case 138:
#line 320 "grammarOld.y"
                                                    { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 2738 "y.tab.c"
    break;

  case 139:
#line 321 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 2744 "y.tab.c"
    break;

  case 140:
#line 325 "grammarOld.y"
              { (yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2750 "y.tab.c"
    break;

  case 141:
#line 326 "grammarOld.y"
                                  { (yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2756 "y.tab.c"
    break;

  case 142:
#line 327 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2762 "y.tab.c"
    break;

  case 143:
#line 328 "grammarOld.y"
                                          { (yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL,(node*)NULL );}
#line 2768 "y.tab.c"
    break;

  case 144:
#line 332 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2774 "y.tab.c"
    break;

  case 145:
#line 333 "grammarOld.y"
                                             { if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2780 "y.tab.c"
    break;

  case 146:
#line 338 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2786 "y.tab.c"
    break;

  case 147:
#line 339 "grammarOld.y"
                                      { makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);}
#line 2792 "y.tab.c"
    break;

  case 148:
#line 343 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2798 "y.tab.c"
    break;

  case 149:
#line 344 "grammarOld.y"
                                                   { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2804 "y.tab.c"
    break;

  case 150:
#line 348 "grammarOld.y"
                                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2810 "y.tab.c"
    break;

  case 151:
#line 349 "grammarOld.y"
                                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2816 "y.tab.c"
    break;

  case 152:
#line 350 "grammarOld.y"
                                 { (yyval.nodes) = (node*)NULL; }
#line 2822 "y.tab.c"
    break;

  case 153:
#line 354 "grammarOld.y"
                     {insertSymbol(gSymTable, line+1, yylval.id);printf("I am here  %d\n", line+1); (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2828 "y.tab.c"
    break;

  case 154:
#line 355 "grammarOld.y"
                                         { insertSymbol(gSymTable, line+1, yylval.id);printf("I am here  %d\n", line+1); makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);}
#line 2834 "y.tab.c"
    break;

  case 155:
#line 359 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2840 "y.tab.c"
    break;

  case 156:
#line 360 "grammarOld.y"
                                                       {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2846 "y.tab.c"
    break;

  case 157:
#line 364 "grammarOld.y"
                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2852 "y.tab.c"
    break;

  case 158:
#line 365 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2858 "y.tab.c"
    break;

  case 159:
#line 366 "grammarOld.y"
                                             {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2864 "y.tab.c"
    break;

  case 160:
#line 370 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 2870 "y.tab.c"
    break;

  case 161:
#line 371 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 2876 "y.tab.c"
    break;

  case 162:
#line 372 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 2882 "y.tab.c"
    break;

  case 163:
#line 373 "grammarOld.y"
                                             {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 2888 "y.tab.c"
    break;

  case 164:
#line 374 "grammarOld.y"
                                                                 {(yyval.nodes) = (yyvsp[-3].nodes);}
#line 2894 "y.tab.c"
    break;

  case 165:
#line 375 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 2900 "y.tab.c"
    break;

  case 166:
#line 376 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 2906 "y.tab.c"
    break;

  case 167:
#line 377 "grammarOld.y"
                                             { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 2912 "y.tab.c"
    break;

  case 168:
#line 378 "grammarOld.y"
                                                                 { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 2918 "y.tab.c"
    break;

  case 169:
#line 382 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2924 "y.tab.c"
    break;

  case 170:
#line 383 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2930 "y.tab.c"
    break;

  case 171:
#line 384 "grammarOld.y"
                                       { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 2936 "y.tab.c"
    break;

  case 172:
#line 388 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2942 "y.tab.c"
    break;

  case 173:
#line 389 "grammarOld.y"
                                           {if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2948 "y.tab.c"
    break;

  case 174:
#line 393 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2954 "y.tab.c"
    break;

  case 175:
#line 394 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2960 "y.tab.c"
    break;

  case 176:
#line 395 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2966 "y.tab.c"
    break;

  case 177:
#line 396 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2972 "y.tab.c"
    break;

  case 178:
#line 397 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2978 "y.tab.c"
    break;

  case 179:
#line 398 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2984 "y.tab.c"
    break;

  case 180:
#line 402 "grammarOld.y"
                                   {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 2990 "y.tab.c"
    break;

  case 181:
#line 403 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("CASE"), strdup("case"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2996 "y.tab.c"
    break;

  case 182:
#line 404 "grammarOld.y"
                                {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3002 "y.tab.c"
    break;

  case 183:
#line 408 "grammarOld.y"
                               { (yyval.nodes) = (node*)NULL; }
#line 3008 "y.tab.c"
    break;

  case 184:
#line 409 "grammarOld.y"
                                              { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3014 "y.tab.c"
    break;

  case 185:
#line 410 "grammarOld.y"
                                                { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3020 "y.tab.c"
    break;

  case 186:
#line 411 "grammarOld.y"
                                                               { if((yyvsp[-2].nodes)){(yyval.nodes) = makeNode(strdup("BODY"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[-1].nodes), (node*)NULL, (node*)NULL);} else{
		(yyval.nodes) = (yyvsp[-1].nodes);	} }
#line 3027 "y.tab.c"
    break;

  case 187:
#line 416 "grammarOld.y"
      { gSymTable = addChildSymbolTable(gSymTable);}
#line 3033 "y.tab.c"
    break;

  case 188:
#line 419 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3039 "y.tab.c"
    break;

  case 189:
#line 420 "grammarOld.y"
                                       { if(!strcmp(((yyvsp[-1].nodes) -> name), "DECL_LIST")){(yyval.nodes) = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);} else (yyval.nodes) = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3045 "y.tab.c"
    break;

  case 190:
#line 424 "grammarOld.y"
                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3051 "y.tab.c"
    break;

  case 191:
#line 425 "grammarOld.y"
                                   { if(!strcmp(((yyvsp[-1].nodes) -> name), "STMT_LIST")){(yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);} else (yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3057 "y.tab.c"
    break;

  case 192:
#line 429 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3063 "y.tab.c"
    break;

  case 193:
#line 430 "grammarOld.y"
                         {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-1].nodes)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 3069 "y.tab.c"
    break;

  case 194:
#line 434 "grammarOld.y"
                                          {(yyval.nodes) = makeNode(strdup("IF"), strdup("if"),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3075 "y.tab.c"
    break;

  case 195:
#line 435 "grammarOld.y"
                                                         {(yyval.nodes) = makeNode(strdup("IF_ELSE"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3081 "y.tab.c"
    break;

  case 196:
#line 436 "grammarOld.y"
                                              {(yyval.nodes) = makeNode(strdup("SWITCH"), strdup(""),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3087 "y.tab.c"
    break;

  case 197:
#line 440 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("WHILE"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3093 "y.tab.c"
    break;

  case 198:
#line 441 "grammarOld.y"
                                                    {(yyval.nodes) = makeNode(strdup("DO WHILE"), strdup(""), 0, (yyvsp[-5].nodes), (yyvsp[-2].nodes), (node*)NULL, (node*)NULL);}
#line 3099 "y.tab.c"
    break;

  case 199:
#line 442 "grammarOld.y"
                                                                          {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3105 "y.tab.c"
    break;

  case 200:
#line 443 "grammarOld.y"
                                                                                     {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes));}
#line 3111 "y.tab.c"
    break;

  case 201:
#line 447 "grammarOld.y"
                              {(yyval.nodes) = makeNode(strdup("GOTO"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3117 "y.tab.c"
    break;

  case 202:
#line 448 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("CONTINUE"), strdup(""),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3123 "y.tab.c"
    break;

  case 203:
#line 449 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("BREAK"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3129 "y.tab.c"
    break;

  case 204:
#line 450 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3135 "y.tab.c"
    break;

  case 205:
#line 451 "grammarOld.y"
                                { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3141 "y.tab.c"
    break;

  case 206:
#line 455 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes); printf("start\n"); }
#line 3147 "y.tab.c"
    break;

  case 207:
#line 456 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes); printf("start1\n");}
#line 3153 "y.tab.c"
    break;

  case 208:
#line 460 "grammarOld.y"
                              {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3159 "y.tab.c"
    break;

  case 209:
#line 461 "grammarOld.y"
                      {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3165 "y.tab.c"
    break;

  case 210:
#line 465 "grammarOld.y"
                                                                                { addChild((yyvsp[-2].nodes), (yyvsp[-1].nodes)); addChild((yyvsp[-2].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3171 "y.tab.c"
    break;

  case 211:
#line 466 "grammarOld.y"
                                                               { addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3177 "y.tab.c"
    break;

  case 212:
#line 467 "grammarOld.y"
                                                         { addChild((yyvsp[-2].nodes), (yyvsp[-1].nodes)); addChild((yyvsp[-2].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3183 "y.tab.c"
    break;

  case 213:
#line 468 "grammarOld.y"
                                        { addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3189 "y.tab.c"
    break;


#line 3193 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 472 "grammarOld.y"

#include <stdio.h>
int id = 0;


void printDeclarations(node* root, FILE *fp) {
    if(!root) return;
	if(root->isLeaf){
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, root->name);
	} else {
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, root->name);

	}
    node* childList = root->childList;
    while(childList) {
        printDeclarations(childList, fp);
        childList = childList->next;
    }
}        

void printEdges(node* root, FILE *fp) {
    node* child = root->childList;
    while(child) {
        fprintf(fp, "%d -> %d\n", root->id, child->id);
        printEdges(child, fp);
        child = child->next;
    }
}

void generateDot(node* root, char* fileName) {
    FILE *fp;
    fp = fopen(fileName, "w");
    fprintf(fp,"strict digraph AST {\n");
    printDeclarations(root, fp);
    printEdges(root, fp);
    fprintf(fp,"}\n");
    fclose(fp);
}

// int main(int ac, char **av) {
// 	int val;
//     FILE    *fd;
//     if (ac >= 2)
//     {
//         if (!(fd = fopen(av[1], "r")))
//         {
//             perror("Error: ");
//             return (-1);
//         }
//         yyset_in(fd);
        
// 		yyparse();
// 		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
// 		char * fileName = strdup("graph.dot");
// 		if(ac == 3) fileName = av[2];

// 		generateDot(root,fileName);

//         fclose(fd);
//     }
//     else
//         printf("Usage: a.out input_filename [optional]ouput.dot \n");
	
// 	return 0; 
// }

using namespace std;
// extern int gScope;
// extern symbolTable* gSymTable;
// extern int line;

int main(int ac, char **av) {
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        
        // Make the first symbol table with global scope
		gSymTable = new symbolTable();
		if(!gSymTable) {
			printf("ERROR: Cannot allocate global symbol table\n");
			return 1;
		}
		gSymTable->scope = gScope++;
		gSymTable->parent = nullptr;
		
        yyparse();
		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
		char * fileName = strdup("graph.dot");
		if(ac == 3) fileName = av[2];

		generateDot(root,fileName);

        fclose(fd);
    }
    else
        printf("Usage: a.out input_filename [optional]ouput.dot \n");

	return 0; 
}

node* makeNode(char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->id = id++;
	newNode->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
	newNode->lexeme = (char*)malloc(sizeof(char)*(strlen(lexeme)+1));
	strcpy(newNode->name, name);
	strcpy(newNode->lexeme, lexeme);
	newNode->isLeaf = isLeaf;
	newNode->childList = c1;
	makeSibling(c2,newNode->childList);
	makeSibling(c3,newNode->childList);
	makeSibling(c4,newNode->childList);
	return newNode;
}

void makeSibling(node* root, node* childList){
	if(!root) return;
	if(!childList) return;
	node* curr  = childList;
	node* prev  = (node*)NULL;
	while(curr){
		prev = curr;
		curr = curr->next;
	}
	prev->next = root;
}

void addChild(node* parent, node* child){
	if(parent->childList == (node*)NULL){
		parent->childList = child;
	}
	else{
		makeSibling(child, parent->childList);
	}
}


extern int column;
void yyerror(const char* s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
