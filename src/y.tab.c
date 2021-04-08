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
	extern char* previ;
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




#line 347 "y.tab.c"


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
#define YYLAST   1231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

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
       0,   117,   117,   118,   119,   120,   124,   130,   138,   139,
     142,   144,   149,   153,   156,   159,   165,   166,   170,   171,
     174,   177,   180,   181,   187,   188,   191,   192,   193,   194,
     198,   199,   216,   217,   220,   223,   229,   230,   233,   239,
     240,   243,   249,   250,   253,   256,   258,   264,   265,   268,
     274,   275,   280,   281,   285,   286,   290,   291,   297,   298,
     304,   305,   311,   312,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   330,   331,   335,   339,   340,
     388,   389,   397,   398,   407,   408,   421,   422,   428,   429,
     435,   436,   437,   438,   439,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   458,   467,   488,
     489,   508,   512,   519,   520,   528,   550,   558,   559,   564,
     568,   569,   579,   587,   588,   603,   604,   605,   609,   610,
     614,   615,   619,   625,   634,   641,   646,   653,   654,   665,
     666,   676,   680,   684,   689,   695,   701,   711,   712,   722,
     727,   737,   738,   749,   768,   789,   818,   821,   828,   829,
     833,   834,   835,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   859,   860,   861,   865,   866,   870,   871,   872,
     873,   874,   875,   879,   880,   881,   885,   886,   887,   888,
     893,   898,   899,   920,   921,   925,   926,   930,   931,   932,
     936,   937,   938,   939,   943,   944,   945,   946,   947,   951,
     952,   956,   957,   961,   977,   985,   998,  1007
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
  "storage_class_specifier", "type_specifier", "inden_marker",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
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

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     974,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,    13,    38,    10,  -272,    88,  1183,  1183,  -272,    14,
    -272,  1183,  -272,    84,    46,   882,  -272,  -272,   -56,    31,
      11,  -272,  -272,    10,  -272,    21,  -272,   126,  -272,  -272,
     -33,  1060,  -272,  1183,   406,   666,    84,  -272,  -272,    31,
      23,   -23,  -272,  -272,  -272,  -272,    38,  -272,   523,  1183,
     -21,  1060,  1009,  -272,   107,  1060,  -272,    88,  -272,   -14,
    1183,  -272,  -272,   110,    49,    71,  -272,    78,  -272,  -272,
    -272,  -272,   787,   808,   808,   645,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,   172,  -272,   833,  -272,   148,
     -15,   144,     1,   241,    81,   112,   119,   197,     0,  -272,
     120,   -20,   833,    31,  -272,  -272,   157,   523,   271,  -272,
    -272,  -272,  -272,  1183,  1060,  -272,  -272,  -272,   833,   106,
    -272,   149,  -272,   274,  -272,  -272,   928,   691,  -272,   113,
    -272,   135,  -272,  1162,  -272,   244,   645,  -272,   833,  -272,
    -272,  -272,   158,   138,   181,   249,  -272,  -272,   716,   833,
     260,  -272,   833,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     833,  -272,  -272,  -272,  -272,  -272,   -19,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   833,  -272,
    1029,  -272,   107,  -272,   833,   190,   833,   195,   205,   220,
     223,   558,   224,   284,   206,   217,   574,  -272,  -272,   128,
    -272,  -272,  -272,   345,   416,  -272,  -272,  -272,  -272,  -272,
     225,   238,  -272,   258,   135,  1127,   737,  -272,  -272,  -272,
     264,  -272,   833,  1086,   151,  -272,   833,  -272,  -272,   161,
    -272,   201,  -272,  -272,  -272,  -272,   148,   148,   -15,   -15,
     144,   144,   144,   144,     1,     1,   241,    81,   112,   119,
     197,   -24,   487,  -272,  -272,  -272,  -272,  -272,   558,   256,
     558,   833,   833,   833,   283,   594,   257,  -272,  -272,  -272,
     129,  -272,  -272,   452,  -272,  -272,  -272,  -272,  -272,  -272,
     276,  -272,   291,  -272,  -272,  -272,  -272,   833,  -272,   833,
    -272,  -272,  -272,   558,  -272,   168,   170,   178,   279,   594,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   558,   558,
     558,   833,   762,   305,  -272,  -272,   179,   558,   186,   558,
     277,  -272,   558,  -272,  -272,  -272
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,   106,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   100,   101,   132,   133,    95,   111,
     112,     0,     0,   143,   212,     0,    80,    82,   104,     0,
     105,    84,   217,   135,     0,     0,   209,   211,   127,     0,
       0,   147,   145,   144,    78,     0,    86,   217,    81,    83,
     110,     0,    85,   190,     0,     0,   134,     1,   210,     0,
     130,     0,   128,   137,   148,   146,     0,    79,     0,   190,
       0,   117,     0,   113,     0,   119,   191,     0,   216,     0,
     190,   156,   142,   155,     0,   149,   151,     0,     2,     6,
       7,     4,     0,     0,     0,     0,   139,    24,    25,    26,
      27,    28,    29,     8,     3,    18,    30,     0,    32,    36,
      39,    42,    47,    50,    52,    54,    56,    58,    60,    77,
       0,     0,     0,     0,   125,    87,    88,     0,    30,    62,
     172,    89,   214,   190,     0,   116,   109,   114,     0,     0,
     120,   122,   118,   190,   192,   215,     0,     0,   153,   160,
     154,   161,   140,     0,   141,     0,     0,    22,     0,    19,
      20,    75,     0,   158,     0,     0,    14,    15,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   126,   131,   129,   175,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    64,     0,   213,
       0,   123,     0,   115,     0,     2,     0,     0,     0,     0,
       0,   190,     0,     0,     0,     0,     0,   195,   186,     0,
     193,   177,   178,   190,   190,   179,   180,   181,   182,   168,
       0,     0,   164,     0,   162,     0,     0,   150,   152,   157,
       0,     5,     0,     0,   160,   159,     0,    13,    10,     0,
      16,     0,    12,    33,    34,    35,    37,    38,    40,    41,
      45,    46,    43,    44,    48,    49,    51,    53,    55,    57,
      59,     0,     0,   173,    63,   108,   121,   124,   190,     0,
     190,     0,     0,     0,     0,     0,     0,   205,   206,   207,
       0,   196,   188,   190,   187,   194,   169,   163,   165,   170,
       0,   166,     0,    23,    76,    31,    11,     0,     9,     0,
     174,   176,   183,   190,   185,     0,     0,     0,     0,     0,
     204,   208,   189,   171,   167,    17,    61,   184,   190,   190,
     190,     0,     0,   197,   199,   200,     0,   190,     0,   190,
       0,   202,   190,   198,   201,   203
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,  -272,  -272,  -272,   -55,  -272,   -78,    94,    95,
      80,    91,   176,   177,   175,   180,   182,  -272,   -54,   -66,
    -272,   -87,   -62,     7,     5,  -272,   298,  -272,   -45,  -272,
    -272,  -272,   231,   -63,   -50,  -272,   154,  -272,   308,   246,
      92,    -2,   -12,   -10,  -272,   -51,  -272,   219,  -272,   214,
     -73,  -145,  -116,  -272,  -120,  -272,   -34,  -272,   -57,   140,
    -271,  -272,  -272,  -272,  -272,   359,  -272,   351
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   105,   259,   128,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   129,   161,
     208,   229,   120,    76,    77,    45,    46,    26,    27,    70,
      28,    29,    72,    73,    74,   139,   140,    30,    61,    62,
      31,    32,    33,    34,    43,   240,    85,    86,    87,   164,
     241,   151,   131,   196,   230,   231,   232,    79,    80,   234,
     235,   236,   237,   238,    35,    36,    37,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   119,   130,    84,   244,    25,    71,    24,   162,   137,
     150,   195,   133,    42,   179,   180,    38,    50,   189,    78,
      40,   135,    56,    47,   329,   142,    71,    71,    59,   171,
      71,    48,    49,    65,    60,   132,    52,   157,   159,   160,
      25,     1,    24,   252,   123,   163,   145,   123,   282,     1,
      71,  -107,   106,    16,    17,   175,   176,   319,   342,    83,
     193,   130,   124,   134,   126,   192,   283,   106,   119,   162,
     143,   162,   141,   149,    63,   126,   211,   181,   182,    23,
     190,   148,   261,   106,   119,   243,   233,   144,    66,    71,
     255,     1,   106,   119,   263,   264,   265,    39,    51,   209,
      22,   294,   260,   281,    67,   122,   163,    23,    22,   244,
       1,    71,   152,     1,   305,    41,     1,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,    64,   149,    56,   153,   300,
     144,   154,   284,    75,    40,   155,    54,   137,    55,   185,
      22,    83,   287,   254,   289,   177,   178,    23,    83,   106,
     119,   106,   119,    75,    75,    71,   321,    75,   322,    22,
     324,    44,   146,   212,   147,   146,    23,   147,   315,    23,
     165,   166,   167,   305,   312,   191,   314,    75,   138,   213,
     186,   106,   119,   -88,   310,   252,   252,   245,   187,   246,
     253,   106,   147,   337,   325,   326,   327,    23,    68,   -88,
     141,   301,   331,   253,   188,   147,   130,   172,   343,   344,
     345,   251,   173,   174,   316,   252,    75,   351,   317,   353,
     214,   338,   355,   339,   168,   252,   169,   252,   170,    68,
     144,   340,   350,   254,   256,   252,   252,   249,    75,   352,
      83,   335,   257,   252,   346,   348,   183,   184,    83,   270,
     271,   272,   273,   262,   106,   336,   318,   291,   252,   266,
     267,   288,   268,   269,   274,   275,   290,   215,    89,    90,
      91,    92,   292,    93,    94,   293,   295,   296,   306,   297,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     298,   307,    75,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   308,   216,   217,   218,   313,   219,   220,
     221,   222,   223,   224,   225,   226,    95,   323,   328,   333,
     330,   341,    97,    98,    99,   100,   101,   102,   215,    89,
      90,    91,    92,   207,    93,    94,   334,   227,   349,   228,
     354,   276,   278,   277,   125,   210,   286,   121,   279,   194,
     250,   280,   248,   303,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    58,   216,   217,   218,    69,   219,
     220,   221,   222,   223,   224,   225,   226,    95,     0,    81,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   215,
      89,    90,    91,    92,     0,    93,    94,     0,   227,     0,
     302,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   215,    89,    90,    91,    92,
       0,    93,    94,     0,     0,     0,   216,   217,   218,    82,
     219,   220,   221,   222,   223,   224,   225,   226,    95,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
      88,    89,    90,    91,    92,     0,    93,    94,     0,   227,
       0,   304,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,    95,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,    88,    89,    90,    91,
      92,     0,    93,    94,     0,   227,     0,   332,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   215,    89,    90,    91,    92,     0,    93,    94,     0,
       0,   127,   320,     0,     0,     0,     0,    88,    89,    90,
      91,    92,     0,    93,    94,    95,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,    88,    89,    90,
      91,    92,     0,    93,    94,     0,     0,   127,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,   226,
      95,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,    95,     0,     0,     0,
       0,   227,    97,    98,    99,   100,   101,   102,    88,    89,
      90,    91,    92,     0,    93,    94,    95,   299,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     0,    88,
      89,    90,    91,    92,     2,    93,    94,   227,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    88,    89,    90,    91,    92,     0,
      93,    94,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,    88,
      89,    90,    91,    92,     0,    93,    94,     0,    95,     0,
       0,    96,     0,     0,    97,    98,    99,   100,   101,   102,
      88,    89,    90,    91,    92,     0,    93,    94,     0,     0,
       0,     0,     0,    95,     0,     0,   242,     0,     0,    97,
      98,    99,   100,   101,   102,    88,    89,    90,    91,    92,
       0,    93,    94,     0,     0,     0,     0,     0,    95,   258,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
      88,    89,    90,    91,    92,     0,    93,    94,     0,    95,
       0,     0,   311,     0,     0,    97,    98,    99,   100,   101,
     102,    88,    89,    90,    91,    92,     0,    93,    94,     0,
       0,     0,     0,     0,    95,   347,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,    88,    89,    90,    91,
      92,     0,    93,    94,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,    57,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   239,   147,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     2,     0,
       0,     0,     0,    23,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     2,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,   136,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,   285,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   239,
     147,     0,     0,     0,     0,    23,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   247,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
      55,    55,    68,    54,   149,     0,    51,     0,    95,    72,
      83,   127,    69,    23,    13,    14,     3,     3,    18,    53,
      22,    71,    34,    25,   295,    75,    71,    72,    84,   107,
      75,    26,    27,    43,     3,    69,    31,    92,    93,    94,
      35,     3,    35,    67,    67,    95,    80,    67,    67,     3,
      95,    84,   107,    43,    44,    70,    71,    81,   329,    54,
     122,   127,    85,    84,    66,    85,    85,   122,   122,   156,
      84,   158,    74,    83,    63,    77,   138,    76,    77,    69,
      80,    83,   169,   138,   138,   147,   143,    80,    67,   134,
     163,     3,   147,   147,   172,   173,   174,    84,    84,   133,
      62,   221,   168,   190,    83,    82,   156,    69,    62,   254,
       3,   156,    63,     3,   234,    23,     3,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    43,   146,   149,    67,   226,
     133,    63,   208,    51,   146,    67,    62,   210,    64,    68,
      62,   146,   214,   163,   216,    11,    12,    69,   153,   214,
     214,   216,   216,    71,    72,   210,   282,    75,   288,    62,
     290,    83,    62,    67,    64,    62,    69,    64,   256,    69,
       8,     9,    10,   303,   246,    65,   252,    95,    81,    83,
      78,   246,   246,    67,   245,    67,    67,    62,    79,    64,
      62,   256,    64,   323,   291,   292,   293,    69,    82,    83,
     212,    83,    83,    62,    17,    64,   282,    69,   338,   339,
     340,    63,    74,    75,    63,    67,   134,   347,    67,   349,
      81,    63,   352,    63,    62,    67,    64,    67,    66,    82,
     233,    63,    63,   253,    63,    67,    67,     3,   156,    63,
     245,   317,     3,    67,   341,   342,    15,    16,   253,   179,
     180,   181,   182,     3,   319,   319,    65,    62,    67,   175,
     176,    81,   177,   178,   183,   184,    81,     3,     4,     5,
       6,     7,    62,     9,    10,    62,    62,     3,    63,    83,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      83,    63,   210,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    65,    50,    51,    52,    63,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    81,    55,    63,
      83,    62,    68,    69,    70,    71,    72,    73,     3,     4,
       5,     6,     7,    82,     9,    10,    65,    83,    53,    85,
      83,   185,   187,   186,    66,   134,   212,    59,   188,   123,
     156,   189,   153,   233,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    35,    50,    51,    52,    47,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,     3,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    83,    -1,
      85,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    50,    51,    52,    63,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    83,
      -1,    85,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    84,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    83,    68,    69,    70,    71,    72,    73,     3,     4,
       5,     6,     7,    -1,     9,    10,    62,    83,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,     3,
       4,     5,     6,     7,    29,     9,    10,    83,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    62,    -1,
      -1,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     0,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    29,    -1,
      -1,    -1,    -1,    69,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    85,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    85,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    69,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    62,    69,   109,   110,   113,   114,   116,   117,
     123,   126,   127,   128,   129,   150,   151,   152,     3,    84,
     127,   126,   129,   130,    83,   111,   112,   127,   110,   110,
       3,    84,   110,   153,    62,    64,   128,     0,   151,    84,
       3,   124,   125,    63,   126,   129,    67,    83,    82,   153,
     115,   114,   118,   119,   120,   126,   109,   110,   142,   143,
     144,     3,    63,   110,   131,   132,   133,   134,     3,     4,
       5,     6,     7,     9,    10,    62,    65,    68,    69,    70,
      71,    72,    73,    87,    88,    89,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     108,   124,    82,    67,    85,   112,   127,    84,    91,   104,
     105,   138,   142,   144,    84,   120,    85,   119,    81,   121,
     122,   127,   120,    84,   109,   142,    62,    64,   127,   129,
     136,   137,    63,    67,    63,    67,    62,    91,    62,    91,
      91,   105,   107,   120,   135,     8,     9,    10,    62,    64,
      66,    93,    69,    74,    75,    70,    71,    11,    12,    13,
      14,    76,    77,    15,    16,    68,    78,    79,    17,    18,
      80,    65,    85,   108,   125,   138,   139,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    82,   106,   142,
     118,   108,    67,    83,    81,     3,    50,    51,    52,    54,
      55,    56,    57,    58,    59,    60,    61,    83,    85,   107,
     140,   141,   142,   144,   145,   146,   147,   148,   149,    63,
     131,   136,    65,   108,   137,    62,    64,    49,   133,     3,
     135,    63,    67,    62,   129,   136,    63,     3,    63,    90,
     105,   107,     3,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    97,    97,    98,    99,   100,   101,
     102,   107,    67,    85,   105,    85,   122,   108,    81,   108,
      81,    62,    62,    62,   140,    62,     3,    83,    83,    83,
     107,    83,    85,   145,    85,   140,    63,    63,    65,    63,
     131,    65,   108,    63,   105,    93,    63,    67,    65,    81,
      85,   138,   140,    81,   140,   107,   107,   107,    55,   146,
      83,    83,    85,    63,    65,   105,   104,   140,    63,    63,
      63,    62,   146,   140,   140,   140,   107,    63,   107,    53,
      63,   140,    63,   140,    83,   140
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
     114,   114,   114,   114,   114,   114,   114,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   140,   141,   141,   141,   142,   142,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     148,   148,   148,   148,   149,   149,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   152,   152,   153
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
       1,     1,     1,     1,     1,     1,     1,     0,     6,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     3,     4,     4,     5,
       0,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     5,     4,     4,     3,     0
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
#line 117 "grammarOld.y"
                     { cout << "117 identifier : " << yylval.id << endl;if(!lookUp(gSymTable, yylval.id)) { error(yylval.id, UNDECLARED_SYMBOL);	}; (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 1968 "y.tab.c"
    break;

  case 3:
#line 118 "grammarOld.y"
                        {(yyval.nodes) = (yyvsp[0].nodes);}
#line 1974 "y.tab.c"
    break;

  case 4:
#line 119 "grammarOld.y"
                         {(yyval.nodes) = makeNode(strdup("STRING_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 1980 "y.tab.c"
    break;

  case 5:
#line 120 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 1986 "y.tab.c"
    break;

  case 6:
#line 124 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		addIVal(temp, yylval.id);
		(yyval.nodes) = temp;
	}
#line 1997 "y.tab.c"
    break;

  case 7:
#line 130 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		addFVal(temp, yylval.id);
		(yyval.nodes) = temp;}
#line 2007 "y.tab.c"
    break;

  case 8:
#line 138 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2013 "y.tab.c"
    break;

  case 9:
#line 139 "grammarOld.y"
                                                {
		// TODO: expression should be int
		addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);}
#line 2021 "y.tab.c"
    break;

  case 10:
#line 142 "grammarOld.y"
                                     {(yyval.nodes) = (yyvsp[-2].nodes); // Check with function paramlist
	}
#line 2028 "y.tab.c"
    break;

  case 11:
#line 144 "grammarOld.y"
                                                              {
		// TODO: Error check for argument validity and function name
		
		addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 2038 "y.tab.c"
    break;

  case 12:
#line 149 "grammarOld.y"
                                            { 
		// TODO: Check if IDENTIFIER is valid field in struct
		
		(yyval.nodes) = makeNode(strdup("."), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 2047 "y.tab.c"
    break;

  case 13:
#line 153 "grammarOld.y"
                                               {
		// TODO: Struct field check
		(yyval.nodes) = makeNode(strdup("PTR_OP"), strdup(""), 0, (yyvsp[-2].nodes), makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
#line 2055 "y.tab.c"
    break;

  case 14:
#line 156 "grammarOld.y"
                                    {
		// TODO: Should be integer
		addChild((yyvsp[-1].nodes), makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));(yyval.nodes) = (yyvsp[-1].nodes);}
#line 2063 "y.tab.c"
    break;

  case 15:
#line 159 "grammarOld.y"
                                    {
		// TODO: postfix_expression should be integer
		addChild((yyvsp[-1].nodes), makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 2071 "y.tab.c"
    break;

  case 16:
#line 165 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2077 "y.tab.c"
    break;

  case 17:
#line 166 "grammarOld.y"
                                                             { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 2083 "y.tab.c"
    break;

  case 18:
#line 170 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2089 "y.tab.c"
    break;

  case 19:
#line 171 "grammarOld.y"
                                  {
		// TODO: Integer check
		(yyval.nodes) = makeNode(strdup("INC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2097 "y.tab.c"
    break;

  case 20:
#line 174 "grammarOld.y"
                                  {
		// TODO: Integer check
		(yyval.nodes) = makeNode(strdup("DEC_OP"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2105 "y.tab.c"
    break;

  case 21:
#line 177 "grammarOld.y"
                                         { 
		// TODO: Type checking and typecasting based on the unary_operatory
		addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2113 "y.tab.c"
    break;

  case 22:
#line 180 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2119 "y.tab.c"
    break;

  case 23:
#line 181 "grammarOld.y"
                                  {
		// TODO: Check validity of type_name 
		(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2127 "y.tab.c"
    break;

  case 24:
#line 187 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2133 "y.tab.c"
    break;

  case 25:
#line 188 "grammarOld.y"
              {
		//TODO: Check ptrLevel>0 or array..
		(yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2141 "y.tab.c"
    break;

  case 26:
#line 191 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2147 "y.tab.c"
    break;

  case 27:
#line 192 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2153 "y.tab.c"
    break;

  case 28:
#line 193 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("~"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2159 "y.tab.c"
    break;

  case 29:
#line 194 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("!"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2165 "y.tab.c"
    break;

  case 30:
#line 198 "grammarOld.y"
                           {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2171 "y.tab.c"
    break;

  case 31:
#line 199 "grammarOld.y"
                                            { 
		// Append typename to front of lexeme
		// TODO: Typename check, check if it can be typecasted (string cant be typecasted)
		string type = "(to ";
		node* temp = (yyvsp[-2].nodes);
		while(temp != NULL){
			type = type + temp->lexeme; // TODO: check lexeme for type_name
			temp = temp->next;
		}
		type = type+")";
		string s = type + string((yyvsp[0].nodes)->lexeme); // TODO: check expression lexeme
		strcpy((yyvsp[0].nodes)->lexeme, s.c_str());
		(yyval.nodes) = (yyvsp[0].nodes);
	}
#line 2190 "y.tab.c"
    break;

  case 32:
#line 216 "grammarOld.y"
                          {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2196 "y.tab.c"
    break;

  case 33:
#line 217 "grammarOld.y"
                                                        { 
		// TODO: Type check
		(yyval.nodes) = makeNode(strdup("*"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2204 "y.tab.c"
    break;

  case 34:
#line 220 "grammarOld.y"
                                                        { 

		(yyval.nodes) = makeNode(strdup("/"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2212 "y.tab.c"
    break;

  case 35:
#line 223 "grammarOld.y"
                                                        { 
		// TODO: Type check : integers
		(yyval.nodes) = makeNode(strdup("%"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2220 "y.tab.c"
    break;

  case 36:
#line 229 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2226 "y.tab.c"
    break;

  case 37:
#line 230 "grammarOld.y"
                                                            { 
		// TODO: Check implicit typecasting
		(yyval.nodes) = makeNode(strdup("+"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2234 "y.tab.c"
    break;

  case 38:
#line 233 "grammarOld.y"
                                                            { 
		// TODO: Check implicit typecasting
		(yyval.nodes) = makeNode(strdup("-"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2242 "y.tab.c"
    break;

  case 39:
#line 239 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2248 "y.tab.c"
    break;

  case 40:
#line 240 "grammarOld.y"
                                                       { 
		// TODO: Both should be integers
		(yyval.nodes) = makeNode(strdup("LEFT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2256 "y.tab.c"
    break;

  case 41:
#line 243 "grammarOld.y"
                                                        { 
		// TODO: Both should be integers
		(yyval.nodes) = makeNode(strdup("RIGHT_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2264 "y.tab.c"
    break;

  case 42:
#line 249 "grammarOld.y"
                           { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2270 "y.tab.c"
    break;

  case 43:
#line 250 "grammarOld.y"
                                                     { 
		// TODO: String Literal check,  implicit typecasting
		(yyval.nodes) = makeNode(strdup("<"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2278 "y.tab.c"
    break;

  case 44:
#line 253 "grammarOld.y"
                                                     { 
		// TODO: String Literal check, implicit typecasting
		(yyval.nodes) = makeNode(strdup(">"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2286 "y.tab.c"
    break;

  case 45:
#line 256 "grammarOld.y"
                                                       { // TODO: String Literal check
	(yyval.nodes) = makeNode(strdup("LE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2293 "y.tab.c"
    break;

  case 46:
#line 258 "grammarOld.y"
                                                       { 
		// TODO: String Literal check, implicit typecasting
		(yyval.nodes) = makeNode(strdup("GE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2301 "y.tab.c"
    break;

  case 47:
#line 264 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2307 "y.tab.c"
    break;

  case 48:
#line 265 "grammarOld.y"
                                                          { 
		// TODO: String Literal check, implicit typecasting
		(yyval.nodes) = makeNode(strdup("EQ_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2315 "y.tab.c"
    break;

  case 49:
#line 268 "grammarOld.y"
                                                          { 
		// TODO: String Literal check, implicit typecasting
		(yyval.nodes) = makeNode(strdup("NE_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2323 "y.tab.c"
    break;

  case 50:
#line 274 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2329 "y.tab.c"
    break;

  case 51:
#line 275 "grammarOld.y"
                                                 { 
		(yyval.nodes) = makeNode(strdup("&"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2336 "y.tab.c"
    break;

  case 52:
#line 280 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2342 "y.tab.c"
    break;

  case 53:
#line 281 "grammarOld.y"
                                                     { (yyval.nodes) = makeNode(strdup("^"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2348 "y.tab.c"
    break;

  case 54:
#line 285 "grammarOld.y"
                                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2354 "y.tab.c"
    break;

  case 55:
#line 286 "grammarOld.y"
                                                              { (yyval.nodes) = makeNode(strdup("|"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2360 "y.tab.c"
    break;

  case 56:
#line 290 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2366 "y.tab.c"
    break;

  case 57:
#line 291 "grammarOld.y"
                                                                { 
		//TODO: Strings Literals allowed
		(yyval.nodes) = makeNode(strdup("AND_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2374 "y.tab.c"
    break;

  case 58:
#line 297 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2380 "y.tab.c"
    break;

  case 59:
#line 298 "grammarOld.y"
                                                             { 
		//TODO: Strings Literals allowed
		(yyval.nodes) = makeNode(strdup("OR_OP"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2388 "y.tab.c"
    break;

  case 60:
#line 304 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2394 "y.tab.c"
    break;

  case 61:
#line 305 "grammarOld.y"
                                                                          { 
		
		(yyval.nodes) = makeNode(strdup("?:"), strdup(""), 0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL); }
#line 2402 "y.tab.c"
    break;

  case 62:
#line 311 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2408 "y.tab.c"
    break;

  case 63:
#line 312 "grammarOld.y"
                                                                     { addChild((yyvsp[-1].nodes), (yyvsp[-2].nodes)); addChild((yyvsp[-1].nodes), (yyvsp[0].nodes)); (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2414 "y.tab.c"
    break;

  case 64:
#line 316 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2420 "y.tab.c"
    break;

  case 65:
#line 317 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2426 "y.tab.c"
    break;

  case 66:
#line 318 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2432 "y.tab.c"
    break;

  case 67:
#line 319 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2438 "y.tab.c"
    break;

  case 68:
#line 320 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2444 "y.tab.c"
    break;

  case 69:
#line 321 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2450 "y.tab.c"
    break;

  case 70:
#line 322 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("LEFT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2456 "y.tab.c"
    break;

  case 71:
#line 323 "grammarOld.y"
                       { (yyval.nodes) = makeNode(strdup("RIGHT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2462 "y.tab.c"
    break;

  case 72:
#line 324 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2468 "y.tab.c"
    break;

  case 73:
#line 325 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2474 "y.tab.c"
    break;

  case 74:
#line 326 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2480 "y.tab.c"
    break;

  case 75:
#line 330 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2486 "y.tab.c"
    break;

  case 76:
#line 331 "grammarOld.y"
                                               { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2492 "y.tab.c"
    break;

  case 77:
#line 335 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2498 "y.tab.c"
    break;

  case 78:
#line 339 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2504 "y.tab.c"
    break;

  case 79:
#line 340 "grammarOld.y"
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
#line 2554 "y.tab.c"
    break;

  case 80:
#line 388 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2560 "y.tab.c"
    break;

  case 81:
#line 389 "grammarOld.y"
                                                         {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));} 
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->storageClassSpecifier;
		int err = addStorageClassToDeclSpec(temp, v);
		if(err) error("addStorageClassToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 2573 "y.tab.c"
    break;

  case 82:
#line 397 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2579 "y.tab.c"
    break;

  case 83:
#line 398 "grammarOld.y"
                                                {
		cout << 399 << endl;
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));} 
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 2593 "y.tab.c"
    break;

  case 84:
#line 407 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2599 "y.tab.c"
    break;

  case 85:
#line 408 "grammarOld.y"
                                                {
		cout << 409 << endl;
		node *temp = (yyvsp[0].nodes);
		//TODO: Verify correctness, code to merge types commented out
		// vector<int> v = $1->declSp->type;
		// int err = addTypeToDeclSpec(temp, v);
		// if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
	}
#line 2614 "y.tab.c"
    break;

  case 86:
#line 421 "grammarOld.y"
                          {  (yyval.nodes) = (yyvsp[0].nodes);  }
#line 2620 "y.tab.c"
    break;

  case 87:
#line 422 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);
	}
#line 2628 "y.tab.c"
    break;

  case 88:
#line 428 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2634 "y.tab.c"
    break;

  case 89:
#line 429 "grammarOld.y"
                                     { 
		(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
	}
#line 2642 "y.tab.c"
    break;

  case 90:
#line 435 "grammarOld.y"
                  {(yyval.nodes) = makeStorageClassNode(TYPE_TYPEDEF, strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2648 "y.tab.c"
    break;

  case 91:
#line 436 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_EXTERN, strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2654 "y.tab.c"
    break;

  case 92:
#line 437 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_STATIC, strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2660 "y.tab.c"
    break;

  case 93:
#line 438 "grammarOld.y"
               {(yyval.nodes) = makeStorageClassNode(TYPE_AUTO, strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2666 "y.tab.c"
    break;

  case 94:
#line 439 "grammarOld.y"
                   {(yyval.nodes) = makeStorageClassNode(TYPE_REGISTER, strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2672 "y.tab.c"
    break;

  case 95:
#line 443 "grammarOld.y"
               { (yyval.nodes) = makeTypeNode(TYPE_VOID);	}
#line 2678 "y.tab.c"
    break;

  case 96:
#line 444 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_CHAR);}
#line 2684 "y.tab.c"
    break;

  case 97:
#line 445 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_SHORT);}
#line 2690 "y.tab.c"
    break;

  case 98:
#line 446 "grammarOld.y"
              {(yyval.nodes) = makeTypeNode(TYPE_INT);}
#line 2696 "y.tab.c"
    break;

  case 99:
#line 447 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_LONG);}
#line 2702 "y.tab.c"
    break;

  case 100:
#line 448 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_FLOAT);}
#line 2708 "y.tab.c"
    break;

  case 101:
#line 449 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_DOUBLE);}
#line 2714 "y.tab.c"
    break;

  case 102:
#line 450 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_SIGNED);}
#line 2720 "y.tab.c"
    break;

  case 103:
#line 451 "grammarOld.y"
                   {(yyval.nodes) = makeTypeNode( TYPE_UNSIGNED);}
#line 2726 "y.tab.c"
    break;

  case 104:
#line 452 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2732 "y.tab.c"
    break;

  case 105:
#line 453 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2738 "y.tab.c"
    break;

  case 106:
#line 454 "grammarOld.y"
                    { (yyval.nodes) = NULL;}
#line 2744 "y.tab.c"
    break;

  case 107:
#line 458 "grammarOld.y"
          {
		node* temp = makeDeadNode();
		temp->lexeme = yylval.id;
		cout << "inden_marker " << yylval.id << endl;
		(yyval.nodes) =temp;		
	}
#line 2755 "y.tab.c"
    break;

  case 108:
#line 467 "grammarOld.y"
                                                                                  {
		structTableNode* structNode = new structTableNode();
		string name = (yyvsp[-3].nodes)->lexeme;
		structNode->infoType = (yyvsp[-5].nodes)->infoType;
		structNode->lineNo = line+1;
		structNode->name = name;
		for(auto &u : (yyvsp[-1].nodes)->structParamList){
			structNode->paramList.push_back(u);
		} 
		
		int type = ((yyvsp[-5].nodes)->infoType == INFO_TYPE_STRUCT) ? TYPE_STRUCT : TYPE_UNION;
		node * temp = makeTypeNode(type);
		if(!temp->declSp)
			temp->declSp = new declSpec();
		temp->declSp->lexeme = name;
		temp->infoType = (yyvsp[-5].nodes)->infoType;
		temp->lineNo = line +1;

		gSymTable->structMap[(yyvsp[-3].nodes)->lexeme] = structNode;
		(yyval.nodes) = temp;
	}
#line 2781 "y.tab.c"
    break;

  case 109:
#line 488 "grammarOld.y"
                                                          {cout << "488 feature not included"<< endl; (yyval.nodes) = NULL;}
#line 2787 "y.tab.c"
    break;

  case 110:
#line 489 "grammarOld.y"
                                      {
		string name(previ); //TODO: wrong name
		if(gSymTable->structMap.find(name) == gSymTable->structMap.end()){
			cout << "error here " << name <<" "<<yylval.id <<endl;
			cout << "previous = " << previ << endl;
			error(name, STRUCT_NOT_DECLARED);
		}
		int type = ((yyvsp[-1].nodes)->infoType == INFO_TYPE_STRUCT) ? TYPE_STRUCT : TYPE_UNION;
		node * temp = makeTypeNode(type);
		if(!temp->declSp)
			temp->declSp = new declSpec();
		temp->declSp->lexeme = name;
		temp->infoType = (yyvsp[-1].nodes)->infoType;
		temp->lineNo = line +1;
		(yyval.nodes) = temp;
	}
#line 2808 "y.tab.c"
    break;

  case 111:
#line 508 "grammarOld.y"
                 {
		node* temp = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_STRUCT;
		(yyval.nodes) = temp;}
#line 2817 "y.tab.c"
    break;

  case 112:
#line 512 "grammarOld.y"
                {
		node* temp = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_UNION;
		(yyval.nodes) = temp;}
#line 2826 "y.tab.c"
    break;

  case 113:
#line 519 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2832 "y.tab.c"
    break;

  case 114:
#line 520 "grammarOld.y"
                                                     {  
		for(auto &u : (yyvsp[0].nodes)->structParamList)
			(yyvsp[-1].nodes)->structParamList.push_back(u);
		(yyval.nodes) = (yyvsp[-1].nodes);
	}
#line 2842 "y.tab.c"
    break;

  case 115:
#line 528 "grammarOld.y"
                                                              {
		node* specifier_qualifier_list = (yyvsp[-2].nodes);
		node* struct_declarator_list = (yyvsp[-1].nodes);
		node* curr = struct_declarator_list;
		while(curr) {
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			if(!temp) continue;
			for(auto &u : temp->structParamList) {
				u->declSp = specifier_qualifier_list->declSp;
				specifier_qualifier_list->structParamList.push_back(u);
			}
			curr = curr -> next;
		}
		(yyval.nodes) = specifier_qualifier_list;
	}
#line 2866 "y.tab.c"
    break;

  case 116:
#line 550 "grammarOld.y"
                                                  {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));}
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
		}
#line 2879 "y.tab.c"
    break;

  case 117:
#line 558 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2885 "y.tab.c"
    break;

  case 118:
#line 559 "grammarOld.y"
                                                  {
		node *temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
	}
#line 2895 "y.tab.c"
    break;

  case 119:
#line 564 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2901 "y.tab.c"
    break;

  case 120:
#line 568 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2907 "y.tab.c"
    break;

  case 121:
#line 569 "grammarOld.y"
                                                       {
		node* struct_declarator = (yyvsp[0].nodes); 
		node* struct_declarator_list = (yyvsp[-2].nodes); 
		for(auto &u : struct_declarator->structParamList)
			struct_declarator_list->structParamList.push_back(u);
		(yyval.nodes) = struct_declarator_list;
	}
#line 2919 "y.tab.c"
    break;

  case 122:
#line 579 "grammarOld.y"
                     { 
		node* declarator = (yyvsp[0].nodes); 
		structParam* param = new structParam();
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		declarator->structParamList.push_back(param);
		(yyval.nodes) = declarator;
	}
#line 2932 "y.tab.c"
    break;

  case 123:
#line 587 "grammarOld.y"
                                  {(yyval.nodes) = NULL;}
#line 2938 "y.tab.c"
    break;

  case 124:
#line 588 "grammarOld.y"
                                             {
		node* declarator = (yyvsp[-2].nodes); 
		structParam* param = new structParam();
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		int err = 0;
		int ret = getValueFromConstantExpression((yyvsp[0].nodes), err);
		if(err) error("getValueFromConstantExpression", err);
		param->bit = ret;
		declarator->structParamList.push_back(param);
		(yyval.nodes) = declarator;
	}
#line 2955 "y.tab.c"
    break;

  case 125:
#line 603 "grammarOld.y"
                                       {(yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2961 "y.tab.c"
    break;

  case 126:
#line 604 "grammarOld.y"
                                                  { (yyval.nodes) = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2967 "y.tab.c"
    break;

  case 127:
#line 605 "grammarOld.y"
                          { (yyval.nodes) = (node*)NULL;}
#line 2973 "y.tab.c"
    break;

  case 128:
#line 609 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2979 "y.tab.c"
    break;

  case 129:
#line 610 "grammarOld.y"
                                         { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2985 "y.tab.c"
    break;

  case 130:
#line 614 "grammarOld.y"
                     {(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2991 "y.tab.c"
    break;

  case 131:
#line 615 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 2997 "y.tab.c"
    break;

  case 132:
#line 619 "grammarOld.y"
                {
		node* temp = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isConst = true;
		(yyval.nodes) = temp;
	}
#line 3008 "y.tab.c"
    break;

  case 133:
#line 625 "grammarOld.y"
                   {
		node* temp = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isVolatile = true;
		(yyval.nodes) = temp;
	}
#line 3019 "y.tab.c"
    break;

  case 134:
#line 634 "grammarOld.y"
                                     { 
		node *temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));

		(yyval.nodes) = temp;
	}
#line 3031 "y.tab.c"
    break;

  case 135:
#line 641 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3037 "y.tab.c"
    break;

  case 136:
#line 646 "grammarOld.y"
                     { 
		cout << "601 iden name = " << yylval.id <<endl;
		// cout << "601 marker name = " << $1->lexeme <<endl;
		(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		(yyval.nodes)-> infoType = INFO_TYPE_NORMAL;
		(yyval.nodes)->lineNo = line+1;
	}
#line 3049 "y.tab.c"
    break;

  case 137:
#line 653 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes);}
#line 3055 "y.tab.c"
    break;

  case 138:
#line 654 "grammarOld.y"
                                                        {
		node* temp = (yyvsp[-3].nodes);
		int err;
		int asize = getValueFromConstantExpression(temp, err);
		if(err){
			error(temp->lexeme, err);
		}
		temp->infoType = INFO_TYPE_ARRAY;
		temp->arraySize = asize;
		(yyval.nodes) = temp;
	}
#line 3071 "y.tab.c"
    break;

  case 139:
#line 665 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[-2].nodes); }
#line 3077 "y.tab.c"
    break;

  case 140:
#line 666 "grammarOld.y"
                                                        { 
		node* direct_declarator = (yyvsp[-3].nodes);	
		node* parameter_type_list = (yyvsp[-1].nodes);	
		// TODO: Add parameters to symbol table with appropriate types, also add to function arguments

		direct_declarator->paramList = parameter_type_list->paramList;
		direct_declarator->paramSize = parameter_type_list->paramSize;
		direct_declarator->infoType = INFO_TYPE_FUNC;
		(yyval.nodes)=direct_declarator;
	}
#line 3092 "y.tab.c"
    break;

  case 141:
#line 676 "grammarOld.y"
                                                    { 
		// TODO: Add to symbol table with appropriate type??, also add to function arguments
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 3101 "y.tab.c"
    break;

  case 142:
#line 680 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3107 "y.tab.c"
    break;

  case 143:
#line 684 "grammarOld.y"
              { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		incrementPointerLevel(temp, NULL);
		(yyval.nodes) = temp;
	}
#line 3117 "y.tab.c"
    break;

  case 144:
#line 689 "grammarOld.y"
                                  { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) =  temp;
		}
#line 3128 "y.tab.c"
    break;

  case 145:
#line 695 "grammarOld.y"
                      { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 3139 "y.tab.c"
    break;

  case 146:
#line 701 "grammarOld.y"
                                          { 
		node* temp  = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL,(node*)NULL );
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile((yyvsp[0].nodes),(yyvsp[-1].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
		}
#line 3151 "y.tab.c"
    break;

  case 147:
#line 711 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3157 "y.tab.c"
    break;

  case 148:
#line 712 "grammarOld.y"
                                             { 
		// if($1){ makeSibling($2,$1);$$ = $1;} else $$ = $2;
		node* temp = (yyvsp[-1].nodes);
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 3168 "y.tab.c"
    break;

  case 149:
#line 722 "grammarOld.y"
                         { 
		node* parameter_list = (yyvsp[0].nodes);
		parameter_list->paramSize = parameter_list->paramList.size();
		(yyval.nodes) = parameter_list;
	 }
#line 3178 "y.tab.c"
    break;

  case 150:
#line 727 "grammarOld.y"
                                      { 
		makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes));
		node* parameter_list = (yyvsp[-2].nodes);
		parameter_list->paramSize = INF_PARAM_LIST;
		(yyval.nodes) = parameter_list;
	}
#line 3189 "y.tab.c"
    break;

  case 151:
#line 737 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3195 "y.tab.c"
    break;

  case 152:
#line 738 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));}
		node* parameter_list = (yyvsp[-2].nodes);
		node* parameter_declaration = (yyvsp[0].nodes);
		for(auto& u: parameter_declaration->paramList)
			parameter_list->paramList.push_back(u);
		(yyval.nodes) = parameter_list;
	}
#line 3208 "y.tab.c"
    break;

  case 153:
#line 749 "grammarOld.y"
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
#line 3232 "y.tab.c"
    break;

  case 154:
#line 768 "grammarOld.y"
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
#line 3258 "y.tab.c"
    break;

  case 155:
#line 789 "grammarOld.y"
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
#line 3289 "y.tab.c"
    break;

  case 156:
#line 818 "grammarOld.y"
                     { // insertSymbol(gSymTable, line+1, yylval.id);
	 	cout << "773 : " << yylval.id << endl;
		 (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3297 "y.tab.c"
    break;

  case 157:
#line 821 "grammarOld.y"
                                         { 
		// insertSymbol(gSymTable, line+1, yylval.id);
		cout << "773 : " << yylval.id << endl;
		makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);}
#line 3306 "y.tab.c"
    break;

  case 158:
#line 828 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3312 "y.tab.c"
    break;

  case 159:
#line 829 "grammarOld.y"
                                                       {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); }
#line 3318 "y.tab.c"
    break;

  case 160:
#line 833 "grammarOld.y"
                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3324 "y.tab.c"
    break;

  case 161:
#line 834 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3330 "y.tab.c"
    break;

  case 162:
#line 835 "grammarOld.y"
                                             {
		//assuming ptr level of direct_abstract_declarator is zero
		node* temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;

	}
#line 3344 "y.tab.c"
    break;

  case 163:
#line 847 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3350 "y.tab.c"
    break;

  case 164:
#line 848 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3356 "y.tab.c"
    break;

  case 165:
#line 849 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3362 "y.tab.c"
    break;

  case 166:
#line 850 "grammarOld.y"
                                             {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 3368 "y.tab.c"
    break;

  case 167:
#line 851 "grammarOld.y"
                                                                 {(yyval.nodes) = (yyvsp[-3].nodes);}
#line 3374 "y.tab.c"
    break;

  case 168:
#line 852 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3380 "y.tab.c"
    break;

  case 169:
#line 853 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3386 "y.tab.c"
    break;

  case 170:
#line 854 "grammarOld.y"
                                             { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3392 "y.tab.c"
    break;

  case 171:
#line 855 "grammarOld.y"
                                                                 { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 3398 "y.tab.c"
    break;

  case 172:
#line 859 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3404 "y.tab.c"
    break;

  case 173:
#line 860 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3410 "y.tab.c"
    break;

  case 174:
#line 861 "grammarOld.y"
                                       { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3416 "y.tab.c"
    break;

  case 175:
#line 865 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3422 "y.tab.c"
    break;

  case 176:
#line 866 "grammarOld.y"
                                           {if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 3428 "y.tab.c"
    break;

  case 177:
#line 870 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3434 "y.tab.c"
    break;

  case 178:
#line 871 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 3440 "y.tab.c"
    break;

  case 179:
#line 872 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3446 "y.tab.c"
    break;

  case 180:
#line 873 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3452 "y.tab.c"
    break;

  case 181:
#line 874 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3458 "y.tab.c"
    break;

  case 182:
#line 875 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3464 "y.tab.c"
    break;

  case 183:
#line 879 "grammarOld.y"
                                   {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3470 "y.tab.c"
    break;

  case 184:
#line 880 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("CASE"), strdup("case"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 3476 "y.tab.c"
    break;

  case 185:
#line 881 "grammarOld.y"
                                {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3482 "y.tab.c"
    break;

  case 186:
#line 885 "grammarOld.y"
                               { (yyval.nodes) = (node*)NULL; gSymTable = gSymTable->parent;}
#line 3488 "y.tab.c"
    break;

  case 187:
#line 886 "grammarOld.y"
                                              { cout << 874 << endl; (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3494 "y.tab.c"
    break;

  case 188:
#line 887 "grammarOld.y"
                                                { cout << 875<< endl; (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3500 "y.tab.c"
    break;

  case 189:
#line 888 "grammarOld.y"
                                                               { cout << 876 << endl; if((yyvsp[-2].nodes)){(yyval.nodes) = makeNode(strdup("BODY"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[-1].nodes), (node*)NULL, (node*)NULL);} else{
		(yyval.nodes) = (yyvsp[-1].nodes);} gSymTable = gSymTable->parent;}
#line 3507 "y.tab.c"
    break;

  case 190:
#line 893 "grammarOld.y"
      { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}
#line 3515 "y.tab.c"
    break;

  case 191:
#line 898 "grammarOld.y"
                      { cout << 887 << endl; (yyval.nodes) = (yyvsp[0].nodes);}
#line 3521 "y.tab.c"
    break;

  case 192:
#line 899 "grammarOld.y"
                                       {
		node* temp = NULL;
		string s((yyvsp[-1].nodes)->name);
		bool c1  = (s == "DECL_LIST");
		if( c1 ){ 
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes)->childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
		} else {
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
		}
		for(auto &u : (yyvsp[0].nodes)->paramList){
			temp->paramList.push_back(u);
		}
		for(auto &u : (yyvsp[-1].nodes)->paramList){
			temp->paramList.push_back(u);
		}
		(yyval.nodes) = temp;
	}
#line 3543 "y.tab.c"
    break;

  case 193:
#line 920 "grammarOld.y"
                    { cout << 907 << endl; (yyval.nodes) = (yyvsp[0].nodes); }
#line 3549 "y.tab.c"
    break;

  case 194:
#line 921 "grammarOld.y"
                                   { cout << 908 << endl; if(!strcmp(((yyvsp[-1].nodes) -> name), "STMT_LIST")){(yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);} else (yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup(""), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3555 "y.tab.c"
    break;

  case 195:
#line 925 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3561 "y.tab.c"
    break;

  case 196:
#line 926 "grammarOld.y"
                         {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-1].nodes)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 3567 "y.tab.c"
    break;

  case 197:
#line 930 "grammarOld.y"
                                          {(yyval.nodes) = makeNode(strdup("IF"), strdup("if"),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3573 "y.tab.c"
    break;

  case 198:
#line 931 "grammarOld.y"
                                                         {(yyval.nodes) = makeNode(strdup("IF_ELSE"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3579 "y.tab.c"
    break;

  case 199:
#line 932 "grammarOld.y"
                                              {(yyval.nodes) = makeNode(strdup("SWITCH"), strdup(""),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3585 "y.tab.c"
    break;

  case 200:
#line 936 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("WHILE"), strdup(""), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3591 "y.tab.c"
    break;

  case 201:
#line 937 "grammarOld.y"
                                                    {(yyval.nodes) = makeNode(strdup("DO WHILE"), strdup(""), 0, (yyvsp[-5].nodes), (yyvsp[-2].nodes), (node*)NULL, (node*)NULL);}
#line 3597 "y.tab.c"
    break;

  case 202:
#line 938 "grammarOld.y"
                                                                          {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 3603 "y.tab.c"
    break;

  case 203:
#line 939 "grammarOld.y"
                                                                                     {(yyval.nodes) = makeNode(strdup("FOR"), strdup(""),0, (yyvsp[-4].nodes), (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes));}
#line 3609 "y.tab.c"
    break;

  case 204:
#line 943 "grammarOld.y"
                              {(yyval.nodes) = makeNode(strdup("GOTO"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3615 "y.tab.c"
    break;

  case 205:
#line 944 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("CONTINUE"), strdup(""),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3621 "y.tab.c"
    break;

  case 206:
#line 945 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("BREAK"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3627 "y.tab.c"
    break;

  case 207:
#line 946 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3633 "y.tab.c"
    break;

  case 208:
#line 947 "grammarOld.y"
                                { (yyval.nodes) = makeNode(strdup("RETURN"), strdup(""), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3639 "y.tab.c"
    break;

  case 209:
#line 951 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes); }
#line 3645 "y.tab.c"
    break;

  case 210:
#line 952 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes);}
#line 3651 "y.tab.c"
    break;

  case 211:
#line 956 "grammarOld.y"
                              {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3657 "y.tab.c"
    break;

  case 212:
#line 957 "grammarOld.y"
                      {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3663 "y.tab.c"
    break;

  case 213:
#line 961 "grammarOld.y"
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
#line 3684 "y.tab.c"
    break;

  case 214:
#line 977 "grammarOld.y"
                                                                           { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declaration_specifiers = (yyvsp[-3].nodes); // type
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(declaration_specifiers, declarator); 

		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 3697 "y.tab.c"
    break;

  case 215:
#line 985 "grammarOld.y"
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
#line 3715 "y.tab.c"
    break;

  case 216:
#line 998 "grammarOld.y"
                                                    { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(NULL, declarator);
		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 3726 "y.tab.c"
    break;

  case 217:
#line 1007 "grammarOld.y"
          {
		// TODO: Send type from declaration specifier to function name
		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
	}
#line 3736 "y.tab.c"
    break;


#line 3740 "y.tab.c"

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
#line 1012 "grammarOld.y"

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
	cout << "I am in main" << endl;
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
	newNode->name = strdup("Storage Node");
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
