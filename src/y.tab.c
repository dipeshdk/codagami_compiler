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
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    SIZEOF = 262,
    PTR_OP = 263,
    INC_OP = 264,
    DEC_OP = 265,
    LEFT_OP = 266,
    RIGHT_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    LEFT_ASSIGN = 279,
    RIGHT_ASSIGN = 280,
    AND_ASSIGN = 281,
    XOR_ASSIGN = 282,
    OR_ASSIGN = 283,
    TYPE_NAME = 284,
    TYPEDEF = 285,
    EXTERN = 286,
    STATIC = 287,
    AUTO = 288,
    REGISTER = 289,
    CHAR = 290,
    SHORT = 291,
    INT = 292,
    LONG = 293,
    SIGNED = 294,
    UNSIGNED = 295,
    FLOAT = 296,
    DOUBLE = 297,
    CONST = 298,
    VOLATILE = 299,
    VOID = 300,
    STRUCT = 301,
    UNION = 302,
    ENUM = 303,
    ELLIPSIS = 304,
    CASE = 305,
    DEFAULT = 306,
    IF = 307,
    ELSE = 308,
    SWITCH = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    GOTO = 313,
    CONTINUE = 314,
    BREAK = 315,
    RETURN = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define SIZEOF 262
#define PTR_OP 263
#define INC_OP 264
#define DEC_OP 265
#define LEFT_OP 266
#define RIGHT_OP 267
#define LE_OP 268
#define GE_OP 269
#define EQ_OP 270
#define NE_OP 271
#define AND_OP 272
#define OR_OP 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define LEFT_ASSIGN 279
#define RIGHT_ASSIGN 280
#define AND_ASSIGN 281
#define XOR_ASSIGN 282
#define OR_ASSIGN 283
#define TYPE_NAME 284
#define TYPEDEF 285
#define EXTERN 286
#define STATIC 287
#define AUTO 288
#define REGISTER 289
#define CHAR 290
#define SHORT 291
#define INT 292
#define LONG 293
#define SIGNED 294
#define UNSIGNED 295
#define FLOAT 296
#define DOUBLE 297
#define CONST 298
#define VOLATILE 299
#define VOID 300
#define STRUCT 301
#define UNION 302
#define ENUM 303
#define ELLIPSIS 304
#define CASE 305
#define DEFAULT 306
#define IF 307
#define ELSE 308
#define SWITCH 309
#define WHILE 310
#define DO 311
#define FOR 312
#define GOTO 313
#define CONTINUE 314
#define BREAK 315
#define RETURN 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "grammarOld.y"
struct node* nodes; char* id;

#line 245 "y.tab.c"

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
	int funcDecl = 0;


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
node* makeTypeNode(int type);
node* makeDeadNode();
node* makeStorageClassNode(int storageClass, char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);

void error(string var, int error_code) {
	string str;
	switch(error_code) {
		case SYMBOL_ALREADY_EXISTS:
			str = "SYMBOL_ALREADY_EXISTS";
			break;
		case ALLOCATION_ERROR:
			str = "ALLOCATION_ERROR";
			break;
		case INVALID_ARGS:
			str = "Invalid arguments passed to the function ";
			break;
		case CONFLICTING_TYPES:
			str = "Conflicting type of declaration ";
			break;
		case UNDECLARED_SYMBOL:
			str = "Undeclared symbol ";
			break;		
		case TYPE_ERROR:
			str = "TYPE_ERROR";
			break;
		case ARRAY_SIZE_NOT_CONSTANT:
			str = "Array size should be a constant ";
			break;
		case ARRAY_SIZE_SHOULD_BE_INT:
			str = "Array size should be a integer ";
			break;
		case INVALID_STORAGE_CLASS:
			str = "Conflicting type of storage class ";
			break;
		case SYMBOL_NOT_FOUND:
			str = "Symbol used before declaration ";
		default:
			break;
	}
	str+=var;
	cout << "\nERROR: " << str << " on line number: " << line+1 << endl;
	exit(error_code);
}




#line 346 "y.tab.c"


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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   117,   118,   119,   123,   129,   137,   138,
     139,   140,   141,   142,   143,   144,   148,   149,   153,   154,
     155,   156,   157,   158,   162,   163,   164,   165,   166,   167,
     171,   172,   176,   177,   178,   179,   183,   184,   185,   189,
     190,   191,   195,   196,   197,   198,   199,   203,   204,   205,
     209,   210,   214,   215,   219,   220,   224,   225,   229,   230,
     234,   235,   239,   240,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   258,   259,   263,   267,   268,
     316,   317,   325,   326,   333,   334,   346,   347,   353,   354,
     360,   361,   362,   363,   364,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   383,   396,   397,
     401,   407,   415,   416,   420,   424,   427,   428,   433,   437,
     438,   442,   443,   444,   448,   449,   450,   454,   455,   459,
     460,   464,   470,   479,   486,   491,   496,   497,   518,   519,
     529,   533,   537,   542,   548,   554,   564,   565,   575,   580,
     590,   591,   602,   621,   642,   671,   673,   679,   680,   684,
     685,   686,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   710,   711,   712,   716,   717,   721,   722,   723,   724,
     725,   726,   730,   731,   732,   736,   737,   738,   739,   744,
     749,   750,   770,   771,   775,   776,   780,   781,   782,   786,
     787,   788,   789,   793,   794,   795,   796,   797,   801,   802,
     806,   807,   811,   827,   835,   848,   857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
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
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
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
  "external_declaration", "function_definition", "func_marker", YY_NULLPTR
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
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-268)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     949,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,     7,    32,    33,  -268,    27,  1158,  1158,  -268,    13,
    -268,  1158,  -268,    -9,    53,   857,  -268,  -268,   -75,    54,
       0,  -268,  -268,    33,  -268,   -23,  -268,   -18,  -268,  -268,
      16,  1035,  -268,  1158,   402,   662,    -9,  -268,  -268,    54,
      29,   -38,  -268,  -268,  -268,  -268,    32,  -268,   519,  1158,
    1035,  1035,   984,  -268,     9,  1035,  -268,    27,  -268,    68,
    1158,  -268,  -268,    85,   134,    49,  -268,    77,  -268,  -268,
    -268,  -268,   758,   783,   783,   641,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,   468,  -268,   804,  -268,   125,
     171,   233,    37,   167,   103,    97,   156,   196,    24,  -268,
     123,    88,   804,    54,  -268,  -268,   172,   519,   338,  -268,
    -268,  -268,  -268,  1158,  1004,  -268,  -268,  -268,   804,    83,
    -268,   174,  -268,   270,  -268,  -268,   903,   687,  -268,   105,
    -268,   141,  -268,  1137,  -268,   258,   641,  -268,   804,  -268,
    -268,  -268,    78,   108,   199,   262,  -268,  -268,   219,   804,
     263,  -268,   804,   804,   804,   804,   804,   804,   804,   804,
     804,   804,   804,   804,   804,   804,   804,   804,   804,   804,
     804,  -268,  -268,  -268,  -268,  -268,    89,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,   804,  -268,
    -268,  -268,     9,  -268,   804,   186,   804,   187,   209,   210,
     216,   554,   221,   291,   213,   214,   570,  -268,  -268,   112,
    -268,  -268,  -268,   341,   412,  -268,  -268,  -268,  -268,  -268,
     256,   260,  -268,   268,   141,  1102,   712,  -268,  -268,  -268,
     271,  -268,   804,  1061,   168,  -268,   804,  -268,  -268,   135,
    -268,   173,  -268,  -268,  -268,  -268,   125,   125,   171,   171,
     233,   233,   233,   233,    37,    37,   167,   103,    97,   156,
     196,   109,   483,  -268,  -268,  -268,  -268,   554,   254,   554,
     804,   804,   804,   281,   590,   266,  -268,  -268,  -268,   113,
    -268,  -268,   448,  -268,  -268,  -268,  -268,  -268,  -268,   274,
    -268,   287,  -268,  -268,  -268,  -268,   804,  -268,   804,  -268,
    -268,  -268,   554,  -268,   147,   148,   149,   292,   590,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,   554,   554,   554,
     804,   733,   303,  -268,  -268,   164,   554,   170,   554,   284,
    -268,   554,  -268,  -268,  -268
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   135,   106,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   100,   101,   131,   132,    95,   110,
     111,     0,     0,   142,   211,     0,    80,    82,   104,     0,
     105,    84,   216,   134,     0,     0,   208,   210,   126,     0,
       0,   146,   144,   143,    78,     0,    86,   216,    81,    83,
     109,     0,    85,   189,     0,     0,   133,     1,   209,     0,
     129,     0,   127,   136,   147,   145,     0,    79,     0,   189,
       0,   116,     0,   112,     0,   118,   190,     0,   215,     0,
     189,   155,   141,   154,     0,   148,   150,     0,     2,     6,
       7,     4,     0,     0,     0,     0,   138,    24,    25,    26,
      27,    28,    29,     8,     3,    18,    30,     0,    32,    36,
      39,    42,    47,    50,    52,    54,    56,    58,    60,    77,
       0,     0,     0,     0,   124,    87,    88,     0,    30,    62,
     171,    89,   213,   189,     0,   115,   108,   113,     0,     0,
     119,   121,   117,   189,   191,   214,     0,     0,   152,   159,
     153,   160,   139,     0,   140,     0,     0,    22,     0,    19,
      20,    75,     0,   157,     0,     0,    14,    15,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   125,   130,   128,   174,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    64,     0,   212,
     107,   122,     0,   114,     0,     2,     0,     0,     0,     0,
       0,   189,     0,     0,     0,     0,     0,   194,   185,     0,
     192,   176,   177,   189,   189,   178,   179,   180,   181,   167,
       0,     0,   163,     0,   161,     0,     0,   149,   151,   156,
       0,     5,     0,     0,   159,   158,     0,    13,    10,     0,
      16,     0,    12,    33,    34,    35,    37,    38,    40,    41,
      45,    46,    43,    44,    48,    49,    51,    53,    55,    57,
      59,     0,     0,   172,    63,   120,   123,   189,     0,   189,
       0,     0,     0,     0,     0,     0,   204,   205,   206,     0,
     195,   187,   189,   186,   193,   168,   162,   164,   169,     0,
     165,     0,    23,    76,    31,    11,     0,     9,     0,   173,
     175,   182,   189,   184,     0,     0,     0,     0,     0,   203,
     207,   188,   170,   166,    17,    61,   183,   189,   189,   189,
       0,     0,   196,   198,   199,     0,   189,     0,   189,     0,
     201,   189,   197,   200,   202
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -268,  -268,  -268,  -268,  -268,   -55,  -268,   -92,    71,    75,
      39,    76,   183,   204,   182,   206,   215,  -268,   -54,   -65,
    -268,   -84,   -68,     6,     5,  -268,   340,  -268,   -47,  -268,
    -268,   337,   -29,   -49,  -268,   211,  -268,   349,   302,   114,
      -8,   -14,   -10,  -268,   -52,  -268,   275,  -268,   273,   -64,
    -142,  -119,  -268,   -53,  -268,   -35,  -268,   -48,   194,  -267,
    -268,  -268,  -268,  -268,   395,  -268,   409
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   105,   259,   128,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   129,   161,
     208,   229,   120,    76,    77,    45,    46,    26,    27,    28,
      29,    72,    73,    74,   139,   140,    30,    61,    62,    31,
      32,    33,    34,    43,   240,    85,    86,    87,   164,   241,
     151,   131,   196,   230,   231,   232,    79,    80,   234,   235,
     236,   237,   238,    35,    36,    37,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   119,    84,   130,    71,    25,    24,   244,   195,    59,
      38,   162,     1,    42,    40,   171,    50,    47,    78,   150,
      56,   133,   135,    71,    71,    71,   142,   328,    71,   123,
       1,    48,    49,    65,   132,     1,    52,   157,   159,   160,
      25,    24,   189,   137,    66,   145,   163,   124,    71,   -88,
     179,   180,   106,    54,   193,    55,     1,    60,   126,    83,
      67,   341,   130,    63,    68,   -88,   141,   106,   119,   126,
     211,    22,   162,   149,   162,   148,    16,    17,    23,   243,
     263,   264,   265,   106,   119,   261,   144,    71,     1,    22,
     138,    39,   106,   119,    22,   233,    23,    51,   209,   255,
      70,    23,    23,   260,   190,   137,   281,   163,     1,    71,
      44,   122,   244,   181,   182,    22,   153,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,    56,   149,    41,    40,   144,
     154,   251,   299,   284,   155,   252,   286,   146,   288,   147,
     212,    83,   143,   254,    23,   123,   282,    64,    83,   106,
     119,   106,   119,   320,   314,    75,   213,   146,   293,   147,
     253,   185,   147,   192,   283,   186,   252,    23,   311,   252,
     252,   304,   183,   184,    75,    75,    75,   313,   191,    75,
     318,   106,   119,   309,   172,   300,   330,   152,   315,   173,
     174,   106,   316,   245,   141,   246,   324,   325,   326,    75,
     337,   338,   339,   188,   252,   252,   252,   130,   270,   271,
     272,   273,    88,    89,    90,    91,    92,   349,    93,    94,
     253,   252,   147,   351,   321,   187,   323,   252,   317,   144,
     252,   175,   176,   254,   177,   178,   266,   267,    75,   304,
      83,   334,   268,   269,    68,   214,   345,   347,    83,   274,
     275,   249,   256,   106,   335,   257,   262,   287,   289,   336,
      75,   290,   291,   215,    89,    90,    91,    92,   292,    93,
      94,    95,   258,   294,   342,   343,   344,    97,    98,    99,
     100,   101,   102,   350,   295,   352,   296,   297,   354,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   305,
     216,   217,   218,   306,   219,   220,   221,   222,   223,   224,
     225,   226,    95,   307,   312,   322,   327,   332,    97,    98,
      99,   100,   101,   102,   215,    89,    90,    91,    92,   329,
      93,    94,   333,   227,   340,   228,   348,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   353,   276,   278,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     277,   216,   217,   218,   279,   219,   220,   221,   222,   223,
     224,   225,   226,    95,   280,    81,   125,   134,   121,    97,
      98,    99,   100,   101,   102,   215,    89,    90,    91,    92,
     207,    93,    94,   285,   227,   194,   301,   302,   248,   250,
      58,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   215,    89,    90,    91,    92,    69,    93,    94,     0,
       0,     0,   216,   217,   218,    82,   219,   220,   221,   222,
     223,   224,   225,   226,    95,     0,   165,   166,   167,     0,
      97,    98,    99,   100,   101,   102,    88,    89,    90,    91,
      92,     0,    93,    94,     0,   227,     0,   303,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,   226,
      95,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,    88,    89,    90,    91,    92,     0,    93,    94,
     168,   227,   169,   331,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   215,    89,    90,
      91,    92,     0,    93,    94,     0,     0,   127,   319,     0,
       0,     0,     0,    88,    89,    90,    91,    92,     0,    93,
      94,    95,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,    88,    89,    90,    91,    92,     0,    93,
      94,     0,     0,   127,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,   226,    95,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,    95,     0,     0,     0,     0,   227,    97,    98,
      99,   100,   101,   102,    88,    89,    90,    91,    92,     0,
      93,    94,    95,   298,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,     0,    88,    89,    90,    91,    92,
       2,    93,    94,   227,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      88,    89,    90,    91,    92,     0,    93,    94,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,    88,    89,    90,    91,    92,
       0,    93,    94,     0,    95,     0,     0,    96,     0,     0,
      97,    98,    99,   100,   101,   102,    88,    89,    90,    91,
      92,     0,    93,    94,     0,     0,     0,     0,     0,    95,
       0,     0,   242,     0,     0,    97,    98,    99,   100,   101,
     102,    88,    89,    90,    91,    92,     0,    93,    94,     0,
       0,     0,     0,     0,    95,     0,     0,   310,     0,     0,
      97,    98,    99,   100,   101,   102,    88,    89,    90,    91,
      92,     0,    93,    94,     0,    95,   346,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,    88,    89,    90,
      91,    92,     0,    93,    94,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,    57,     0,     0,
       1,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   239,   147,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     2,     0,     0,     0,     0,    23,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     2,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   136,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,   210,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   239,   147,     0,     0,     0,     0,
      23,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   247,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      55,    55,    54,    68,    51,     0,     0,   149,   127,    84,
       3,    95,     3,    23,    22,   107,     3,    25,    53,    83,
      34,    69,    71,    70,    71,    72,    75,   294,    75,    67,
       3,    26,    27,    43,    69,     3,    31,    92,    93,    94,
      35,    35,    18,    72,    67,    80,    95,    85,    95,    67,
      13,    14,   107,    62,   122,    64,     3,     3,    66,    54,
      83,   328,   127,    63,    82,    83,    74,   122,   122,    77,
     138,    62,   156,    83,   158,    83,    43,    44,    69,   147,
     172,   173,   174,   138,   138,   169,    80,   134,     3,    62,
      81,    84,   147,   147,    62,   143,    69,    84,   133,   163,
      84,    69,    69,   168,    80,   134,   190,   156,     3,   156,
      83,    82,   254,    76,    77,    62,    67,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   149,   146,    23,   146,   133,
      63,    63,   226,   208,    67,    67,   214,    62,   216,    64,
      67,   146,    84,   163,    69,    67,    67,    43,   153,   214,
     214,   216,   216,   282,   256,    51,    83,    62,   221,    64,
      62,    68,    64,    85,    85,    78,    67,    69,   246,    67,
      67,   234,    15,    16,    70,    71,    72,   252,    65,    75,
      81,   246,   246,   245,    69,    83,    83,    63,    63,    74,
      75,   256,    67,    62,   212,    64,   290,   291,   292,    95,
      63,    63,    63,    17,    67,    67,    67,   282,   179,   180,
     181,   182,     3,     4,     5,     6,     7,    63,     9,    10,
      62,    67,    64,    63,   287,    79,   289,    67,    65,   233,
      67,    70,    71,   253,    11,    12,   175,   176,   134,   302,
     245,   316,   177,   178,    82,    81,   340,   341,   253,   183,
     184,     3,    63,   318,   318,     3,     3,    81,    81,   322,
     156,    62,    62,     3,     4,     5,     6,     7,    62,     9,
      10,    62,    63,    62,   337,   338,   339,    68,    69,    70,
      71,    72,    73,   346,     3,   348,    83,    83,   351,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    63,
      50,    51,    52,    63,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    65,    63,    81,    55,    63,    68,    69,
      70,    71,    72,    73,     3,     4,     5,     6,     7,    83,
       9,    10,    65,    83,    62,    85,    53,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    83,   185,   187,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     186,    50,    51,    52,   188,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   189,     3,    66,    70,    59,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,     7,
      82,     9,    10,   212,    83,   123,    85,   233,   153,   156,
      35,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,     4,     5,     6,     7,    47,     9,    10,    -1,
      -1,    -1,    50,    51,    52,    63,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,     8,     9,    10,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    83,    -1,    85,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,     7,    -1,     9,    10,
      62,    83,    64,    85,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    84,    85,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    84,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    83,    68,    69,
      70,    71,    72,    73,     3,     4,     5,     6,     7,    -1,
       9,    10,    62,    83,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    -1,     3,     4,     5,     6,     7,
      29,     9,    10,    83,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    62,    -1,    -1,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    62,    63,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     0,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    29,    -1,    -1,    -1,    -1,    69,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    29,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    85,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    85,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    62,    69,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   149,   150,   151,     3,    84,
     126,   125,   128,   129,    83,   111,   112,   126,   110,   110,
       3,    84,   110,   152,    62,    64,   127,     0,   150,    84,
       3,   123,   124,    63,   125,   128,    67,    83,    82,   152,
      84,   114,   117,   118,   119,   125,   109,   110,   141,   142,
     143,     3,    63,   110,   130,   131,   132,   133,     3,     4,
       5,     6,     7,     9,    10,    62,    65,    68,    69,    70,
      71,    72,    73,    87,    88,    89,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     108,   123,    82,    67,    85,   112,   126,    84,    91,   104,
     105,   137,   141,   143,   117,   119,    85,   118,    81,   120,
     121,   126,   119,    84,   109,   141,    62,    64,   126,   128,
     135,   136,    63,    67,    63,    67,    62,    91,    62,    91,
      91,   105,   107,   119,   134,     8,     9,    10,    62,    64,
      66,    93,    69,    74,    75,    70,    71,    11,    12,    13,
      14,    76,    77,    15,    16,    68,    78,    79,    17,    18,
      80,    65,    85,   108,   124,   137,   138,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    82,   106,   141,
      85,   108,    67,    83,    81,     3,    50,    51,    52,    54,
      55,    56,    57,    58,    59,    60,    61,    83,    85,   107,
     139,   140,   141,   143,   144,   145,   146,   147,   148,    63,
     130,   135,    65,   108,   136,    62,    64,    49,   132,     3,
     134,    63,    67,    62,   128,   135,    63,     3,    63,    90,
     105,   107,     3,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    97,    97,    98,    99,   100,   101,
     102,   107,    67,    85,   105,   121,   108,    81,   108,    81,
      62,    62,    62,   139,    62,     3,    83,    83,    83,   107,
      83,    85,   144,    85,   139,    63,    63,    65,    63,   130,
      65,   108,    63,   105,    93,    63,    67,    65,    81,    85,
     137,   139,    81,   139,   107,   107,   107,    55,   145,    83,
      83,    85,    63,    65,   105,   104,   139,    63,    63,    63,
      62,   145,   139,   139,   139,   107,    63,   107,    53,    63,
     139,    63,   139,    83,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   115,
     116,   116,   117,   117,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   140,   140,   140,   141,   141,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   147,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   151,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     3,     4,     4,     5,     0,
       1,     2,     1,     2,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     5,     4,     4,     3,     0
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
#line 116 "grammarOld.y"
                     { if(!lookUp(gSymTable, yylval.id)) { error(yylval.id, UNDECLARED_SYMBOL);	}; (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 1960 "y.tab.c"
    break;

  case 3:
#line 117 "grammarOld.y"
                        {(yyval.nodes) = (yyvsp[0].nodes);}
#line 1966 "y.tab.c"
    break;

  case 4:
#line 118 "grammarOld.y"
                         {(yyval.nodes) = makeNode(strdup("STRING_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 1972 "y.tab.c"
    break;

  case 5:
#line 119 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 1978 "y.tab.c"
    break;

  case 6:
#line 123 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		addIVal(temp, yylval.id);
		(yyval.nodes) = temp;
	}
#line 1989 "y.tab.c"
    break;

  case 7:
#line 129 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		addFVal(temp, yylval.id);
		(yyval.nodes) = temp;}
#line 1999 "y.tab.c"
    break;

  case 8:
#line 137 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2005 "y.tab.c"
    break;

  case 9:
#line 138 "grammarOld.y"
                                                {addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);}
#line 2011 "y.tab.c"
    break;

  case 10:
#line 139 "grammarOld.y"
                                     {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 2017 "y.tab.c"
    break;

  case 11:
#line 140 "grammarOld.y"
                                                              {addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);}
#line 2023 "y.tab.c"
    break;

  case 12:
#line 141 "grammarOld.y"
                                            { (yyval.nodes) = makeNode(strdup("."), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 2029 "y.tab.c"
    break;

  case 13:
#line 142 "grammarOld.y"
                                               {(yyval.nodes) = makeNode(strdup("PTR_OP"), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 2035 "y.tab.c"
    break;

  case 14:
#line 143 "grammarOld.y"
                                    {addChild((yyvsp[-1].nodes), makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));(yyval.nodes) = (yyvsp[-1].nodes);}
#line 2041 "y.tab.c"
    break;

  case 15:
#line 144 "grammarOld.y"
                                    {addChild((yyvsp[-1].nodes), makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 2047 "y.tab.c"
    break;

  case 16:
#line 148 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2053 "y.tab.c"
    break;

  case 17:
#line 149 "grammarOld.y"
                                                             { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2059 "y.tab.c"
    break;

  case 18:
#line 153 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2065 "y.tab.c"
    break;

  case 19:
#line 154 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("INC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2071 "y.tab.c"
    break;

  case 20:
#line 155 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("DEC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2077 "y.tab.c"
    break;

  case 21:
#line 156 "grammarOld.y"
                                         { addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2083 "y.tab.c"
    break;

  case 22:
#line 157 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2089 "y.tab.c"
    break;

  case 23:
#line 158 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2095 "y.tab.c"
    break;

  case 24:
#line 162 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2101 "y.tab.c"
    break;

  case 25:
#line 163 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2107 "y.tab.c"
    break;

  case 26:
#line 164 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2113 "y.tab.c"
    break;

  case 27:
#line 165 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2119 "y.tab.c"
    break;

  case 28:
#line 166 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("~"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2125 "y.tab.c"
    break;

  case 29:
#line 167 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("!"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2131 "y.tab.c"
    break;

  case 30:
#line 171 "grammarOld.y"
                           {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2137 "y.tab.c"
    break;

  case 31:
#line 172 "grammarOld.y"
                                            { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else {(yyval.nodes) = (yyvsp[0].nodes);} }
#line 2143 "y.tab.c"
    break;

  case 32:
#line 176 "grammarOld.y"
                          {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2149 "y.tab.c"
    break;

  case 33:
#line 177 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2155 "y.tab.c"
    break;

  case 34:
#line 178 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("/"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2161 "y.tab.c"
    break;

  case 35:
#line 179 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("%"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2167 "y.tab.c"
    break;

  case 36:
#line 183 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2173 "y.tab.c"
    break;

  case 37:
#line 184 "grammarOld.y"
                                                            { (yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2179 "y.tab.c"
    break;

  case 38:
#line 185 "grammarOld.y"
                                                            { (yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2185 "y.tab.c"
    break;

  case 39:
#line 189 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2191 "y.tab.c"
    break;

  case 40:
#line 190 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("LEFT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2197 "y.tab.c"
    break;

  case 41:
#line 191 "grammarOld.y"
                                                        { (yyval.nodes) = makeNode(strdup("RIGHT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2203 "y.tab.c"
    break;

  case 42:
#line 195 "grammarOld.y"
                           { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2209 "y.tab.c"
    break;

  case 43:
#line 196 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup("<"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2215 "y.tab.c"
    break;

  case 44:
#line 197 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup(">"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2221 "y.tab.c"
    break;

  case 45:
#line 198 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("LE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2227 "y.tab.c"
    break;

  case 46:
#line 199 "grammarOld.y"
                                                       { (yyval.nodes) = makeNode(strdup("GE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2233 "y.tab.c"
    break;

  case 47:
#line 203 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2239 "y.tab.c"
    break;

  case 48:
#line 204 "grammarOld.y"
                                                          { (yyval.nodes) = makeNode(strdup("EQ_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2245 "y.tab.c"
    break;

  case 49:
#line 205 "grammarOld.y"
                                                          { (yyval.nodes) = makeNode(strdup("NE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2251 "y.tab.c"
    break;

  case 50:
#line 209 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2257 "y.tab.c"
    break;

  case 51:
#line 210 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2263 "y.tab.c"
    break;

  case 52:
#line 214 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2269 "y.tab.c"
    break;

  case 53:
#line 215 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup("^"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2275 "y.tab.c"
    break;

  case 54:
#line 219 "grammarOld.y"
                                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2281 "y.tab.c"
    break;

  case 55:
#line 220 "grammarOld.y"
                                                              { (yyval.nodes) = makeNode(strdup("|"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2287 "y.tab.c"
    break;

  case 56:
#line 224 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2293 "y.tab.c"
    break;

  case 57:
#line 225 "grammarOld.y"
                                                                { (yyval.nodes) = makeNode(strdup("AND_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2299 "y.tab.c"
    break;

  case 58:
#line 229 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2305 "y.tab.c"
    break;

  case 59:
#line 230 "grammarOld.y"
                                                             { (yyval.nodes) = makeNode(strdup("OR_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2311 "y.tab.c"
    break;

  case 60:
#line 234 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2317 "y.tab.c"
    break;

  case 61:
#line 235 "grammarOld.y"
                                                                          { (yyval.nodes) = makeNode(strdup("?:"), strdup(""), 0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL); }
#line 2323 "y.tab.c"
    break;

  case 62:
#line 239 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2329 "y.tab.c"
    break;

  case 63:
#line 240 "grammarOld.y"
                                                                     { addChild((yyvsp[-1].nodes), (yyvsp[-2].nodes)); addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2335 "y.tab.c"
    break;

  case 64:
#line 244 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2341 "y.tab.c"
    break;

  case 65:
#line 245 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2347 "y.tab.c"
    break;

  case 66:
#line 246 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2353 "y.tab.c"
    break;

  case 67:
#line 247 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2359 "y.tab.c"
    break;

  case 68:
#line 248 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2365 "y.tab.c"
    break;

  case 69:
#line 249 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2371 "y.tab.c"
    break;

  case 70:
#line 250 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("LEFT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2377 "y.tab.c"
    break;

  case 71:
#line 251 "grammarOld.y"
                       { (yyval.nodes) = makeNode(strdup("RIGHT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2383 "y.tab.c"
    break;

  case 72:
#line 252 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2389 "y.tab.c"
    break;

  case 73:
#line 253 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2395 "y.tab.c"
    break;

  case 74:
#line 254 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2401 "y.tab.c"
    break;

  case 75:
#line 258 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2407 "y.tab.c"
    break;

  case 76:
#line 259 "grammarOld.y"
                                               { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2413 "y.tab.c"
    break;

  case 77:
#line 263 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2419 "y.tab.c"
    break;

  case 78:
#line 267 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2425 "y.tab.c"
    break;

  case 79:
#line 268 "grammarOld.y"
                                                          {
		node* curr = (yyvsp[-1].nodes);
		while(curr){
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			
			if(!temp) continue;
			string lex = temp->lexeme;
			cout << "inserting symbol " << lex << " in scope " << gSymTable->scope << endl;
			int retVal = insertSymbol(gSymTable, temp->lineNo, lex);
			if(retVal) {
				error(temp->lexeme, retVal);
			}
			
			struct symbolTableNode* sym_node = gSymTable->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			if(funcDecl){
				param* paramter = new param();
				paramter-> declSp = declSpCopy((yyvsp[-2].nodes)->declSp);
				paramter->paramName = lex;
				(yyvsp[-2].nodes)->paramList.push_back(paramter);
			}
			if(temp->infoType == INFO_TYPE_ARRAY){
				sym_node->infoType = INFO_TYPE_ARRAY;
				sym_node->arraySize = temp->arraySize;
				sym_node->declSp = declSpCopy((yyvsp[-2].nodes)->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			}
			else {
				// sym_node->infoType = INFO_TYPE_NORMAL;
				sym_node->declSp = declSpCopy((yyvsp[-2].nodes)->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			} 
			
			curr = curr->next;
		}
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[-1].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[-1].nodes);   
	}
#line 2475 "y.tab.c"
    break;

  case 80:
#line 316 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2481 "y.tab.c"
    break;

  case 81:
#line 317 "grammarOld.y"
                                                         {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} 
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->storageClassSpecifier;
		int err = addStorageClassToDeclSpec(temp, v);
		if(err) error("addStorageClassToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 2494 "y.tab.c"
    break;

  case 82:
#line 325 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2500 "y.tab.c"
    break;

  case 83:
#line 326 "grammarOld.y"
                                                {
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 2512 "y.tab.c"
    break;

  case 84:
#line 333 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2518 "y.tab.c"
    break;

  case 85:
#line 334 "grammarOld.y"
                                                {
		node *temp = (yyvsp[0].nodes);
		//TODO: Verify correctness, code to merge types commented out
		// vector<int> v = $1->declSp->type;
		// int err = addTypeToDeclSpec(temp, v);
		// if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
	}
#line 2532 "y.tab.c"
    break;

  case 86:
#line 346 "grammarOld.y"
                          { (yyval.nodes) = (yyvsp[0].nodes);  }
#line 2538 "y.tab.c"
    break;

  case 87:
#line 347 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);
	}
#line 2546 "y.tab.c"
    break;

  case 88:
#line 353 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2552 "y.tab.c"
    break;

  case 89:
#line 354 "grammarOld.y"
                                     { 
		(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
	}
#line 2560 "y.tab.c"
    break;

  case 90:
#line 360 "grammarOld.y"
                  {(yyval.nodes) = makeStorageClassNode(TYPE_TYPEDEF, strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2566 "y.tab.c"
    break;

  case 91:
#line 361 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_EXTERN, strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2572 "y.tab.c"
    break;

  case 92:
#line 362 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_STATIC, strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2578 "y.tab.c"
    break;

  case 93:
#line 363 "grammarOld.y"
               {(yyval.nodes) = makeStorageClassNode(TYPE_AUTO, strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2584 "y.tab.c"
    break;

  case 94:
#line 364 "grammarOld.y"
                   {(yyval.nodes) = makeStorageClassNode(TYPE_REGISTER, strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2590 "y.tab.c"
    break;

  case 95:
#line 368 "grammarOld.y"
               { (yyval.nodes) = makeTypeNode(TYPE_VOID);	}
#line 2596 "y.tab.c"
    break;

  case 96:
#line 369 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_CHAR);}
#line 2602 "y.tab.c"
    break;

  case 97:
#line 370 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_SHORT);}
#line 2608 "y.tab.c"
    break;

  case 98:
#line 371 "grammarOld.y"
              {(yyval.nodes) = makeTypeNode(TYPE_INT);}
#line 2614 "y.tab.c"
    break;

  case 99:
#line 372 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_LONG);}
#line 2620 "y.tab.c"
    break;

  case 100:
#line 373 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_FLOAT);}
#line 2626 "y.tab.c"
    break;

  case 101:
#line 374 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_DOUBLE);}
#line 2632 "y.tab.c"
    break;

  case 102:
#line 375 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_SIGNED);}
#line 2638 "y.tab.c"
    break;

  case 103:
#line 376 "grammarOld.y"
                   {(yyval.nodes) = makeTypeNode( TYPE_UNSIGNED);}
#line 2644 "y.tab.c"
    break;

  case 104:
#line 377 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2650 "y.tab.c"
    break;

  case 105:
#line 378 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2656 "y.tab.c"
    break;

  case 106:
#line 379 "grammarOld.y"
                    {(yyval.nodes) = NULL;}
#line 2662 "y.tab.c"
    break;

  case 107:
#line 383 "grammarOld.y"
                                                                     {
		// TODO: decide to keep or no
		// int retVal = insertSymbol(gSymTable, line+1, yylval.id);
		// if(retVal) {
		// 	error("", retVal);
		// }
		symbolTableNode* stNode = lookUp(gSymTable, yylval.id);
		if(!stNode) {
			error(yylval.id, UNDECLARED_SYMBOL);	
		}
		stNode->infoType = INFO_TYPE_STRUCT;
		(yyval.nodes) = NULL;
		}
#line 2680 "y.tab.c"
    break;

  case 108:
#line 396 "grammarOld.y"
                                                          {(yyval.nodes) = NULL;}
#line 2686 "y.tab.c"
    break;

  case 109:
#line 397 "grammarOld.y"
                                     {(yyval.nodes) = NULL;}
#line 2692 "y.tab.c"
    break;

  case 110:
#line 401 "grammarOld.y"
                 {
		node* temp = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_STRUCT);
	 	(yyval.nodes) = temp;}
#line 2702 "y.tab.c"
    break;

  case 111:
#line 407 "grammarOld.y"
                {
		node* temp = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_UNION);
		(yyval.nodes)=temp;}
#line 2712 "y.tab.c"
    break;

  case 112:
#line 415 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2718 "y.tab.c"
    break;

  case 113:
#line 416 "grammarOld.y"
                                                     { if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2724 "y.tab.c"
    break;

  case 114:
#line 420 "grammarOld.y"
                                                              {(yyval.nodes) = NULL;}
#line 2730 "y.tab.c"
    break;

  case 115:
#line 424 "grammarOld.y"
                                                  {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));}
		}
#line 2738 "y.tab.c"
    break;

  case 116:
#line 427 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2744 "y.tab.c"
    break;

  case 117:
#line 428 "grammarOld.y"
                                                  {
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;
		mergeConstVolatile((yyvsp[0].nodes), (yyvsp[-1].nodes));
		(yyval.nodes) = (yyvsp[0].nodes);
	}
#line 2754 "y.tab.c"
    break;

  case 118:
#line 433 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2760 "y.tab.c"
    break;

  case 119:
#line 437 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2766 "y.tab.c"
    break;

  case 120:
#line 438 "grammarOld.y"
                                                       {(yyval.nodes) = NULL;}
#line 2772 "y.tab.c"
    break;

  case 121:
#line 442 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2778 "y.tab.c"
    break;

  case 122:
#line 443 "grammarOld.y"
                                  {(yyval.nodes) = NULL;}
#line 2784 "y.tab.c"
    break;

  case 123:
#line 444 "grammarOld.y"
                                             {(yyval.nodes) = NULL;}
#line 2790 "y.tab.c"
    break;

  case 124:
#line 448 "grammarOld.y"
                                       {(yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2796 "y.tab.c"
    break;

  case 125:
#line 449 "grammarOld.y"
                                                  { (yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2802 "y.tab.c"
    break;

  case 126:
#line 450 "grammarOld.y"
                          { (yyval.nodes) = (node*)NULL;}
#line 2808 "y.tab.c"
    break;

  case 127:
#line 454 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2814 "y.tab.c"
    break;

  case 128:
#line 455 "grammarOld.y"
                                         { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2820 "y.tab.c"
    break;

  case 129:
#line 459 "grammarOld.y"
                     {(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2826 "y.tab.c"
    break;

  case 130:
#line 460 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 2832 "y.tab.c"
    break;

  case 131:
#line 464 "grammarOld.y"
                {
		node* temp = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isConst = true;
		(yyval.nodes) = temp;
	}
#line 2843 "y.tab.c"
    break;

  case 132:
#line 470 "grammarOld.y"
                   {
		node* temp = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isVolatile = true;
		(yyval.nodes) = temp;
	}
#line 2854 "y.tab.c"
    break;

  case 133:
#line 479 "grammarOld.y"
                                     { 
		node *temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));

		(yyval.nodes) = temp;
	}
#line 2866 "y.tab.c"
    break;

  case 134:
#line 486 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2872 "y.tab.c"
    break;

  case 135:
#line 491 "grammarOld.y"
                     { 
		(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		(yyval.nodes)-> infoType = INFO_TYPE_NORMAL;
		(yyval.nodes)->lineNo = line+1;
	}
#line 2882 "y.tab.c"
    break;

  case 136:
#line 496 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes);}
#line 2888 "y.tab.c"
    break;

  case 137:
#line 497 "grammarOld.y"
                                                        {
		node* temp = (yyvsp[-3].nodes);
		int asize = 0;
		switch((yyvsp[-1].nodes)->valType){
			case TYPE_INT: 
				asize = (yyvsp[-1].nodes)->ival;
				break;
			case TYPE_LONG: 
				asize = (yyvsp[-1].nodes)->lval;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				error((yyvsp[-1].nodes)->name, TYPE_ERROR);
				break;
			default:
				break; 
		}
		temp->infoType = INFO_TYPE_ARRAY;
		temp->arraySize = asize;
		(yyval.nodes) = temp;
	}
#line 2914 "y.tab.c"
    break;

  case 138:
#line 518 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[-2].nodes); }
#line 2920 "y.tab.c"
    break;

  case 139:
#line 519 "grammarOld.y"
                                                        { 
		node* direct_declarator = (yyvsp[-3].nodes);	
		node* parameter_type_list = (yyvsp[-1].nodes);	
		// TODO: Add parameters to symbol table with appropriate types, also add to function arguments

		direct_declarator->paramList = parameter_type_list->paramList;
		direct_declarator->paramSize = parameter_type_list->paramSize;
		direct_declarator->infoType = INFO_TYPE_FUNC;
		(yyval.nodes)=direct_declarator;
	}
#line 2935 "y.tab.c"
    break;

  case 140:
#line 529 "grammarOld.y"
                                                    { 
		// TODO: Add to symbol table with appropriate type??, also add to function arguments
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 2944 "y.tab.c"
    break;

  case 141:
#line 533 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 2950 "y.tab.c"
    break;

  case 142:
#line 537 "grammarOld.y"
              { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		incrementPointerLevel(temp, NULL);
		(yyval.nodes) = temp;
	}
#line 2960 "y.tab.c"
    break;

  case 143:
#line 542 "grammarOld.y"
                                  { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) =  temp;
		}
#line 2971 "y.tab.c"
    break;

  case 144:
#line 548 "grammarOld.y"
                      { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 2982 "y.tab.c"
    break;

  case 145:
#line 554 "grammarOld.y"
                                          { 
		node* temp  = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL,(node*)NULL );
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile((yyvsp[0].nodes),(yyvsp[-1].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
		}
#line 2994 "y.tab.c"
    break;

  case 146:
#line 564 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3000 "y.tab.c"
    break;

  case 147:
#line 565 "grammarOld.y"
                                             { 
		// if($1){ makeSibling($2,$1);$$ = $1;} else $$ = $2;
		node* temp = (yyvsp[-1].nodes);
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 3011 "y.tab.c"
    break;

  case 148:
#line 575 "grammarOld.y"
                         { 
		node* parameter_list = (yyvsp[0].nodes);
		parameter_list->paramSize = parameter_list->paramList.size();
		(yyval.nodes) = parameter_list;
	 }
#line 3021 "y.tab.c"
    break;

  case 149:
#line 580 "grammarOld.y"
                                      { 
		makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes));
		node* parameter_list = (yyvsp[-2].nodes);
		parameter_list->paramSize = INF_PARAM_LIST;
		(yyval.nodes) = parameter_list;
	}
#line 3032 "y.tab.c"
    break;

  case 150:
#line 590 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3038 "y.tab.c"
    break;

  case 151:
#line 591 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));}
		node* parameter_list = (yyvsp[-2].nodes);
		node* parameter_declaration = (yyvsp[0].nodes);
		for(auto& u: parameter_declaration->paramList)
			parameter_list->paramList.push_back(u);
		(yyval.nodes) = parameter_list;
	}
#line 3051 "y.tab.c"
    break;

  case 152:
#line 602 "grammarOld.y"
                                            { 
		node* declaration_specifiers = (yyvsp[-1].nodes);
		node* declarator = (yyvsp[0].nodes);

		param *parameter = new param();
		if(!parameter->declSp) {
			parameter->declSp = new declSpec();
		}
		if(declaration_specifiers->declSp) {
			parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		}
		if(declarator->declSp) {
			parameter->declSp->ptrLevel = declarator->declSp->ptrLevel;
		}
		parameter->paramName = declarator->lexeme;
		declarator->paramList.push_back(parameter);

		(yyval.nodes) = declarator; 
	}
#line 3075 "y.tab.c"
    break;

  case 153:
#line 621 "grammarOld.y"
                                                     { 
		//TODO: difference in abstract_declarator and declarator
		node* declaration_specifiers = (yyvsp[-1].nodes);
		node* declarator = (yyvsp[0].nodes);

		param *parameter = new param();
		if(!parameter->declSp) {
			parameter->declSp = new declSpec();
		}
		if(declaration_specifiers->declSp) {
			parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		}
		if(declarator->declSp) {
			parameter->declSp->ptrLevel = declarator->declSp->ptrLevel;
		}
		parameter->paramName = declarator->lexeme;

		declarator->paramList.push_back(parameter);

		(yyval.nodes) = declarator; 
	 }
#line 3101 "y.tab.c"
    break;

  case 154:
#line 642 "grammarOld.y"
                                 { 
		// if(funcDecl){
		// 	// TODO: Error
			
		// }


		// $$ = $1;
		node* declaration_specifiers = (yyvsp[0].nodes);
		// node* declarator = new node();

		param *parameter = new param();
		if(!parameter->declSp) {
			parameter->declSp = new declSpec();
		}
		if(declaration_specifiers->declSp) {
			parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		}
		// if(declarator->declSp) {
		// 	parameter->declSp->ptrLevel = declarator->declSp->ptrLevel;
		// }
		parameter->paramName = "111NoParamName111";
		declaration_specifiers->paramList.push_back(parameter);

		(yyval.nodes) = declaration_specifiers; 
	}
#line 3132 "y.tab.c"
    break;

  case 155:
#line 671 "grammarOld.y"
                     { // insertSymbol(gSymTable, line+1, yylval.id);
	 	(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3139 "y.tab.c"
    break;

  case 156:
#line 673 "grammarOld.y"
                                         { 
		// insertSymbol(gSymTable, line+1, yylval.id);
		makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);}
#line 3147 "y.tab.c"
    break;

  case 157:
#line 679 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3153 "y.tab.c"
    break;

  case 158:
#line 680 "grammarOld.y"
                                                       {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 3159 "y.tab.c"
    break;

  case 159:
#line 684 "grammarOld.y"
                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3165 "y.tab.c"
    break;

  case 160:
#line 685 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3171 "y.tab.c"
    break;

  case 161:
#line 686 "grammarOld.y"
                                             {
		//assuming ptr level of direct_abstract_declarator is zero
		node* temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;

	}
#line 3185 "y.tab.c"
    break;

  case 162:
#line 698 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3191 "y.tab.c"
    break;

  case 163:
#line 699 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3197 "y.tab.c"
    break;

  case 164:
#line 700 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3203 "y.tab.c"
    break;

  case 165:
#line 701 "grammarOld.y"
                                             {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 3209 "y.tab.c"
    break;

  case 166:
#line 702 "grammarOld.y"
                                                                 {(yyval.nodes) = (yyvsp[-3].nodes);}
#line 3215 "y.tab.c"
    break;

  case 167:
#line 703 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3221 "y.tab.c"
    break;

  case 168:
#line 704 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3227 "y.tab.c"
    break;

  case 169:
#line 705 "grammarOld.y"
                                             { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3233 "y.tab.c"
    break;

  case 170:
#line 706 "grammarOld.y"
                                                                 { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 3239 "y.tab.c"
    break;

  case 171:
#line 710 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3245 "y.tab.c"
    break;

  case 172:
#line 711 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3251 "y.tab.c"
    break;

  case 173:
#line 712 "grammarOld.y"
                                       { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3257 "y.tab.c"
    break;

  case 174:
#line 716 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3263 "y.tab.c"
    break;

  case 175:
#line 717 "grammarOld.y"
                                           {if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 3269 "y.tab.c"
    break;

  case 176:
#line 721 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3275 "y.tab.c"
    break;

  case 177:
#line 722 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 3281 "y.tab.c"
    break;

  case 178:
#line 723 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3287 "y.tab.c"
    break;

  case 179:
#line 724 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3293 "y.tab.c"
    break;

  case 180:
#line 725 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3299 "y.tab.c"
    break;

  case 181:
#line 726 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3305 "y.tab.c"
    break;

  case 182:
#line 730 "grammarOld.y"
                                   {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3311 "y.tab.c"
    break;

  case 183:
#line 731 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("CASE"), strdup("case"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 3317 "y.tab.c"
    break;

  case 184:
#line 732 "grammarOld.y"
                                {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3323 "y.tab.c"
    break;

  case 185:
#line 736 "grammarOld.y"
                               { (yyval.nodes) = (node*)NULL; gSymTable = gSymTable->parent;}
#line 3329 "y.tab.c"
    break;

  case 186:
#line 737 "grammarOld.y"
                                              { (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3335 "y.tab.c"
    break;

  case 187:
#line 738 "grammarOld.y"
                                                { (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3341 "y.tab.c"
    break;

  case 188:
#line 739 "grammarOld.y"
                                                               { if((yyvsp[-2].nodes)){(yyval.nodes) = makeNode(strdup("BODY"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[-1].nodes), (node*)NULL, (node*)NULL);} else{
		(yyval.nodes) = (yyvsp[-1].nodes);} gSymTable = gSymTable->parent;}
#line 3348 "y.tab.c"
    break;

  case 189:
#line 744 "grammarOld.y"
      { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}
#line 3356 "y.tab.c"
    break;

  case 190:
#line 749 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes);}
#line 3362 "y.tab.c"
    break;

  case 191:
#line 750 "grammarOld.y"
                                       { 
		node* temp;
		if(!strcmp(((yyvsp[-1].nodes) -> name), "DECL_LIST")){
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
		} else 
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);

		for(auto &u : (yyvsp[0].nodes)->paramList){
			temp->paramList.push_back(u);
		}

		for(auto &u : (yyvsp[-1].nodes)->paramList){
			temp->paramList.push_back(u);
		}
		(yyval.nodes) = temp;
	}
#line 3383 "y.tab.c"
    break;

  case 192:
#line 770 "grammarOld.y"
                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3389 "y.tab.c"
    break;

  case 193:
#line 771 "grammarOld.y"
                                   { if(!strcmp(((yyvsp[-1].nodes) -> name), "STMT_LIST")){(yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);} else (yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3395 "y.tab.c"
    break;

  case 194:
#line 775 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3401 "y.tab.c"
    break;

  case 195:
#line 776 "grammarOld.y"
                         {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-1].nodes)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 3407 "y.tab.c"
    break;

  case 196:
#line 780 "grammarOld.y"
                                          {(yyval.nodes) = makeNode(strdup("IF"), strdup("if"),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3413 "y.tab.c"
    break;

  case 197:
#line 781 "grammarOld.y"
                                                         {(yyval.nodes) = makeNode(strdup("IF_ELSE"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3419 "y.tab.c"
    break;

  case 198:
#line 782 "grammarOld.y"
                                              {(yyval.nodes) = makeNode(strdup("SWITCH"), strdup(""),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3425 "y.tab.c"
    break;

  case 199:
#line 786 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("WHILE"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3431 "y.tab.c"
    break;

  case 200:
#line 787 "grammarOld.y"
                                                    {(yyval.nodes) = makeNode(strdup("DO WHILE"), strdup(""), 0, (yyvsp[-5].nodes), (yyvsp[-2].nodes), (node*)NULL, (node*)NULL);}
#line 3437 "y.tab.c"
    break;

  case 201:
#line 788 "grammarOld.y"
                                                                          {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3443 "y.tab.c"
    break;

  case 202:
#line 789 "grammarOld.y"
                                                                                     {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes));}
#line 3449 "y.tab.c"
    break;

  case 203:
#line 793 "grammarOld.y"
                              {(yyval.nodes) = makeNode(strdup("GOTO"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3455 "y.tab.c"
    break;

  case 204:
#line 794 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("CONTINUE"), strdup(""),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3461 "y.tab.c"
    break;

  case 205:
#line 795 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("BREAK"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3467 "y.tab.c"
    break;

  case 206:
#line 796 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3473 "y.tab.c"
    break;

  case 207:
#line 797 "grammarOld.y"
                                { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3479 "y.tab.c"
    break;

  case 208:
#line 801 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes); }
#line 3485 "y.tab.c"
    break;

  case 209:
#line 802 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes);}
#line 3491 "y.tab.c"
    break;

  case 210:
#line 806 "grammarOld.y"
                              {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3497 "y.tab.c"
    break;

  case 211:
#line 807 "grammarOld.y"
                      {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3503 "y.tab.c"
    break;

  case 212:
#line 811 "grammarOld.y"
                                                                                            { 
		addChild((yyvsp[-3].nodes), (yyvsp[-1].nodes)); 
		addChild((yyvsp[-3].nodes), (yyvsp[0].nodes)); 
	 	
		node* declaration_specifiers = (yyvsp[-4].nodes); // type
		node* declarator = (yyvsp[-3].nodes); // func , param list
		
		
		for(auto &u: (yyvsp[-1].nodes)->paramList){
			(yyvsp[-3].nodes)->paramList.push_back(u);
			// int err = removeSymbol(gSymTable, u->paramName);
			// if(err) error("removeSymbol", err);
		}
		addFunctionSymbol( declaration_specifiers, declarator);
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 3524 "y.tab.c"
    break;

  case 213:
#line 827 "grammarOld.y"
                                                                           { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declaration_specifiers = (yyvsp[-3].nodes); // type
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(declaration_specifiers, declarator); 

		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 3537 "y.tab.c"
    break;

  case 214:
#line 835 "grammarOld.y"
                                                                     { 
		addChild((yyvsp[-3].nodes), (yyvsp[-1].nodes)); 
		addChild((yyvsp[-3].nodes), (yyvsp[0].nodes));
		node* declarator = (yyvsp[-3].nodes); // func , param list
		
		for(auto &u: (yyvsp[-1].nodes)->paramList){
			(yyvsp[-3].nodes)->paramList.push_back(u);
			// int err = removeSymbol(gSymTable, u->paramName);
			// if(err) error("removeSymbol", err);
		}
		addFunctionSymbol(NULL, declarator);
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 3555 "y.tab.c"
    break;

  case 215:
#line 848 "grammarOld.y"
                                                    { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(NULL, declarator);
		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 3566 "y.tab.c"
    break;

  case 216:
#line 857 "grammarOld.y"
          {
		// TODO: Send type from declaration specifier to function name
		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
	}
#line 3576 "y.tab.c"
    break;


#line 3580 "y.tab.c"

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
#line 862 "grammarOld.y"

#include <stdio.h>
int id = 0;



void printDeclarations(node* root, FILE *fp) {
    if(!root || root->isLeaf == DEAD_NODE ) return;
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
	if(root->isLeaf == DEAD_NODE) return;
    node* child = root->childList;
    while(child) {
		if(child->isLeaf == DEAD_NODE) {
			child = child->next;
			continue;
		}
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
	insert_into_sets();
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

		printSymbolTable(gSymTable);

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

node* makeDeadNode(){
	node* newNode = new node();
	newNode->isLeaf=DEAD_NODE;
	newNode->declSp = new declSpec();
    newNode->childList = NULL;
    newNode->next = NULL;
	newNode->name = strdup("Dead Node");
	return newNode;
}

node* makeTypeNode(int tp){
	node* newNode = makeDeadNode();
	newNode->declSp->type.push_back(tp); //TODO: check validity of type
	return newNode;
}

node* makeStorageClassNode(int storageClass, char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = makeNode(name, lexeme, isLeaf, 
			c1,c2, c3, c4);
	newNode->declSp = new declSpec();
	newNode->declSp->storageClassSpecifier.push_back(storageClass); //TODO: check validity of storage class
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
