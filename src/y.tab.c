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
	struct node* currDecl;
	int funcDecl = 0;


extern "C"
{
	int yylex(void);  
	int yywrap();
	void yyset_in  ( FILE * _in_str  );
}

void yyerror(const char *s);
extern char yytext[];

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
		case ARRAY_INDEX_SHOULD_BE_INT:
			str = "Array index should be a integer ";
			break;
		case INVALID_ARGS_IN_FUNC_CALL:
			str = "Invalid aruments in function call ";
			break;
		case INVALID_STORAGE_CLASS:
			str = "Conflicting type of storage class ";
			break;
		case SYMBOL_NOT_FOUND:
			str = "Symbol used before declaration ";
			break;
		case STRUCT_NOT_DECLARED:
			str = "Undeclared struct ";
			break;
		case INVALID_SYNTAX:
			str = "Invalid Syntax ";
			break;
		case VARIABLE_NOT_A_STRUCT:
			str = "Not a struct ";
			break;
		case INVALID_REFERENCE:
			str = "Invalid reference ";
			break;
		case INVALID_STRUCT_PARAM:
			str = "Invalid struct param ";
			break;
		case INTERNAL_ERROR_DECL_SP_NOT_DEFINED:
			str = "INTERNAL_ERROR_DECL_SP_NOT_DEFINED";
			break;
		case POINTER_ERROR:
			str = "Invalid Operand Of Type Pointer";
			break;
		case STRING_LITERAL_ERROR:
			str = "Invalid Operand Of Type String";
			break;
		case SHOULD_NOT_BE_FLOAT:
			str = "Invalid Operand Of Type Float";
			break;
		case VOID_ERROR:
			str = "void data type is not compatible";
		default:
			break;
	}
	str+=var;
	cout << "\nERROR: " << str << " on line number: " << line+1 << endl;
	exit(error_code);
}



#line 371 "y.tab.c"


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
       0,   141,   141,   160,   161,   169,   173,   183,   195,   196,
     208,   217,   246,   313,   387,   396,   408,   409,   413,   414,
     421,   428,   448,   449,   455,   456,   459,   462,   463,   464,
     468,   469,   485,   486,   494,   501,   515,   516,   523,   533,
     534,   549,   567,   568,   575,   582,   589,   599,   600,   645,
     693,   694,   704,   705,   715,   716,   726,   727,   733,   734,
     740,   741,   747,   748,   764,   765,   766,   767,   768,   769,
     770,   771,   772,   773,   774,   778,   779,   783,   787,   788,
     834,   835,   843,   844,   852,   853,   865,   866,   872,   873,
     889,   890,   891,   892,   893,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   912,   920,   941,
     942,   965,   970,   977,   978,   986,  1012,  1020,  1021,  1026,
    1030,  1031,  1041,  1049,  1050,  1066,  1067,  1068,  1072,  1073,
    1077,  1078,  1082,  1088,  1097,  1105,  1110,  1115,  1116,  1127,
    1128,  1138,  1142,  1146,  1151,  1157,  1163,  1173,  1174,  1184,
    1189,  1199,  1200,  1211,  1230,  1251,  1269,  1271,  1276,  1277,
    1292,  1293,  1294,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1318,  1319,  1320,  1324,  1325,  1329,  1330,  1331,
    1332,  1333,  1334,  1338,  1339,  1340,  1344,  1345,  1346,  1347,
    1352,  1357,  1358,  1378,  1379,  1383,  1384,  1388,  1389,  1390,
    1394,  1395,  1396,  1397,  1401,  1402,  1403,  1404,  1405,  1409,
    1410,  1414,  1415,  1419,  1433,  1472,  1483,  1525
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
#line 141 "grammarOld.y"
                     { 
		symbolTableNode* stNode = lookUp(gSymTable, yylval.id);
		if(!stNode) { 
			error(yylval.id, UNDECLARED_SYMBOL);
		}
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		temp->declSp = new declSpec();
		for(int &i : stNode->declSp->type)
			temp->declSp->type.push_back(i);
		for(int &i : stNode->declSp->storageClassSpecifier)
			temp->declSp->storageClassSpecifier.push_back(i);

		temp->declSp->ptrLevel = stNode->declSp->ptrLevel;
		temp->declSp->lexeme = stNode->declSp->lexeme;
		temp->declSp->isConst = stNode->declSp->isConst;
		temp->declSp->isVolatile = stNode->declSp->isVolatile;
		(yyval.nodes)=temp;

	}
#line 2010 "y.tab.c"
    break;

  case 3:
#line 160 "grammarOld.y"
                        {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2016 "y.tab.c"
    break;

  case 4:
#line 161 "grammarOld.y"
                         {
		node* temp = makeNode(strdup("STRING_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_STRING_LITERAL);
		(yyval.nodes) = temp;
	}
#line 2029 "y.tab.c"
    break;

  case 5:
#line 169 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2035 "y.tab.c"
    break;

  case 6:
#line 173 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_INT);
		addIVal(temp, yylval.id);
		(yyval.nodes) = temp;
	}
#line 2050 "y.tab.c"
    break;

  case 7:
#line 183 "grammarOld.y"
                     {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_FLOAT);
		addFVal(temp, yylval.id);
		(yyval.nodes) = temp;}
#line 2064 "y.tab.c"
    break;

  case 8:
#line 195 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2070 "y.tab.c"
    break;

  case 9:
#line 196 "grammarOld.y"
                                                {
		if((yyvsp[-1].nodes)->declSp) {
			int err = check_type_array((yyvsp[-1].nodes)->declSp->type);
			error((yyvsp[-1].nodes)->lexeme, err);
		}
		else {
			error((yyvsp[-1].nodes)->lexeme, ARRAY_INDEX_SHOULD_BE_INT);
		}
		addChild((yyvsp[-3].nodes),(yyvsp[-1].nodes));
		(yyvsp[-3].nodes)->infoType = INFO_TYPE_ARRAY;
		(yyval.nodes) = (yyvsp[-3].nodes);
		}
#line 2087 "y.tab.c"
    break;

  case 10:
#line 208 "grammarOld.y"
                                     { // Check with function paramlist111NoParamName111
		node* postfix_expression  = (yyvsp[-2].nodes);
		string func_name(postfix_expression->lexeme);
		if(postfix_expression -> paramList.size() > 0){
			error(func_name, INVALID_ARGS_IN_FUNC_CALL);
		}
		postfix_expression->infoType = INFO_TYPE_FUNC;
		(yyval.nodes) = postfix_expression;	
	}
#line 2101 "y.tab.c"
    break;

  case 11:
#line 217 "grammarOld.y"
                                                              {
		// TODO: Error check for argument validity and function name
		node* postfix_expression  = (yyvsp[-3].nodes);
		string func_name(postfix_expression->lexeme);
		vector<struct param*> paramList = postfix_expression -> paramList; 
		int idx = 0;
		node* curr = (yyvsp[-1].nodes);
		while(curr){
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			if(!temp) continue;
			if(!temp->declSp || !paramList[idx]->declSp){
				error(temp->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
				break;
			}
			int retval = compareTypes(temp->declSp, paramList[idx]->declSp);
			if(retval){
				error(temp->lexeme, INVALID_ARGS_IN_FUNC_CALL);
			}
			idx++;
			curr = curr -> next;
		}
		postfix_expression->infoType = INFO_TYPE_FUNC;
		addChild(postfix_expression,(yyvsp[-1].nodes));
		(yyval.nodes) = postfix_expression;
	}
#line 2135 "y.tab.c"
    break;

  case 12:
#line 246 "grammarOld.y"
                                            { 
		// TODO: Check if IDENTIFIER is valid field in struct
		// x.y.z
		node* curr = (yyvsp[-2].nodes);
		while(curr != NULL){
			string s(curr->name);
			if(s == "IDENTIFIER"){
				break;
			}
			else{
				curr = curr->childList;
				if(curr){
 					curr = curr->next;
				}
			}
		}

		if(curr == NULL){
			// Error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		
		string rightMostStructName;	
		structTableNode* structure = nullptr;
		if(curr->infoType == INFO_NESTED_STRUCT){
			// declSp allocated so look in structure table
			if(curr->declSp) {
				rightMostStructName = curr->declSp->lexeme;
				structure = structLookUp(gSymTable, rightMostStructName);
			}
		}
		else{
			// look in symbol table
			symbolTableNode* n = lookUp(gSymTable, curr->lexeme);
			int isStruct = 0;
			if(n->declSp) {
				for(int t : n->declSp->type) {
					if(t == TYPE_STRUCT) {
						isStruct=1;
						break;
					}
				}
				if(isStruct) {
					rightMostStructName = n->declSp->lexeme;
					structure = structLookUp(gSymTable, rightMostStructName);
				}
			}
			
		}
		if(structure == nullptr) {
			//error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		// rightMostStructName = curr->lexeme;
		string identifierName(yylval.id);
		// structure = structLookUp(gSymTable, rightMostStructName);
		int err = 0;
		structParam* param = structureParamLookup(structure, identifierName, err);
		if(err) error("structHasParam", err);
		if(!param) error(identifierName, INVALID_STRUCT_PARAM);
		
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, NULL, NULL, NULL, NULL);
		temp->declSp = param->declSp;
		temp->infoType = INFO_NESTED_STRUCT;
		
		(yyval.nodes) = makeNode(strdup("."), strdup("."), 0, (yyvsp[-2].nodes), temp , NULL, NULL);
		}
#line 2207 "y.tab.c"
    break;

  case 13:
#line 313 "grammarOld.y"
                                               {
		// TODO: Struct field check
		node* curr = (yyvsp[-2].nodes);
		while(curr != NULL){
			string s(curr->name);
			if(s == "IDENTIFIER"){
				break;
			}
			else{
				curr = curr->childList;
				if(curr){
 					curr = curr->next;
				}
			}
		}

		if(curr == NULL){
			// Error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		
		string rightMostStructName;	
		structTableNode* structure = nullptr;
		if(curr->infoType == INFO_NESTED_STRUCT){
			// declSp allocated so look in structure table
			if(curr->declSp)
				if(curr->declSp->ptrLevel != 1){
					// Error
					printf("ptrlev 1= %d\n", curr->declSp->ptrLevel);
					error(curr->lexeme, INVALID_REFERENCE);
				}
				rightMostStructName = curr->declSp->lexeme;
				structure = structLookUp(gSymTable, rightMostStructName);
			
		}
		else{
			// look in symbol table
			symbolTableNode* n = lookUp(gSymTable, curr->lexeme);
			int isStruct = 0;
			if(n->declSp) {
				for(int t : n->declSp->type) {
					if(t == TYPE_STRUCT) {
						isStruct=1;
						break;
					}
				}
				if(isStruct) {
					if(n->declSp->ptrLevel != 1){
						// Error
						printf("ptrlev 2= %d\n", curr->declSp->ptrLevel);
						error(n->name, INVALID_REFERENCE);
					}
					rightMostStructName = n->declSp->lexeme;
					structure = structLookUp(gSymTable, rightMostStructName);
				}
			}
			
		}
		if(structure == nullptr) {
			//error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		string identifierName(yylval.id);
		int err = 0;
		structParam* param = structureParamLookup(structure, identifierName, err);
		if(err) error("structHasParam", err);
		if(!param) error(identifierName, INVALID_STRUCT_PARAM);
		
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, NULL, NULL, NULL, NULL);
		temp->declSp = param->declSp;
		temp->infoType = INFO_NESTED_STRUCT;
		
		(yyval.nodes) = makeNode(strdup("PTR_OP"), strdup("->"), 0, (yyvsp[-2].nodes), temp , NULL, NULL);
	}
#line 2286 "y.tab.c"
    break;

  case 14:
#line 387 "grammarOld.y"
                                    {
		// TODO: Should be integer
		int retval  = checkIntLongShort((yyvsp[-1].nodes));
		if(retval){
			error((yyvsp[-1].nodes)->lexeme, retval);
		}
		addChild((yyvsp[-1].nodes), makeNode(strdup("INC_OP"), strdup("++"), 1, NULL, NULL, NULL, NULL));
		(yyval.nodes) = (yyvsp[-1].nodes);
		}
#line 2300 "y.tab.c"
    break;

  case 15:
#line 396 "grammarOld.y"
                                    {
		// TODO: postfix_expression should be integer
		int retval  = checkIntLongShort((yyvsp[-1].nodes));
		if(retval){
			error((yyvsp[-1].nodes)->lexeme, retval);
		}
		addChild((yyvsp[-1].nodes), makeNode(strdup("DEC_OP"), strdup("--"), 1, NULL, NULL, NULL, NULL));
		(yyval.nodes) = (yyvsp[-1].nodes);
		}
#line 2314 "y.tab.c"
    break;

  case 16:
#line 408 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2320 "y.tab.c"
    break;

  case 17:
#line 409 "grammarOld.y"
                                                             {if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2326 "y.tab.c"
    break;

  case 18:
#line 413 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2332 "y.tab.c"
    break;

  case 19:
#line 414 "grammarOld.y"
                                  {
		// TODO: Integer check
		int retval  = checkIntLongShort((yyvsp[0].nodes));
		if(retval){
			error((yyvsp[0].nodes)->lexeme, retval);
		}
		(yyval.nodes) = makeNode(strdup("INC_OP"), strdup("++"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2344 "y.tab.c"
    break;

  case 20:
#line 421 "grammarOld.y"
                                  {
		// TODO: Integer check
		int retval  = checkIntLongShort((yyvsp[0].nodes));
		if(retval){
			error((yyvsp[0].nodes)->lexeme, retval);
		}
		(yyval.nodes) = makeNode(strdup("DEC_OP"), strdup("--"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2356 "y.tab.c"
    break;

  case 21:
#line 428 "grammarOld.y"
                                         { 
		// TODO: Type checking and typecasting based on the unary_operatory
		node* unary_operator = (yyvsp[-1].nodes);
		node* cast_expression = (yyvsp[0].nodes);
		string name(unary_operator->name);
		
		int retval = checkStringLiteral(cast_expression);
		if(!retval){
			error(cast_expression->name, TYPE_ERROR);
		}

		if(name == "*"){
			if(!(cast_expression -> infoType == INFO_TYPE_ARRAY ||(cast_expression -> declSp && cast_expression -> declSp->ptrLevel > 0)) ){
				return TYPE_ERROR;	
			}
		}
		unary_operator->declSp = cast_expression->declSp;
		addChild(unary_operator, cast_expression);
		(yyval.nodes) = unary_operator;
	}
#line 2381 "y.tab.c"
    break;

  case 22:
#line 448 "grammarOld.y"
                                  {(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2387 "y.tab.c"
    break;

  case 23:
#line 449 "grammarOld.y"
                                  {
		// TODO: Check validity of type_name 
		(yyval.nodes) = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2395 "y.tab.c"
    break;

  case 24:
#line 455 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("&"), strdup("&"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2401 "y.tab.c"
    break;

  case 25:
#line 456 "grammarOld.y"
              {
		// TODO: Check ptrLevel>0 or array..
		(yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2409 "y.tab.c"
    break;

  case 26:
#line 459 "grammarOld.y"
              {
		// TODO: String Literal check
		(yyval.nodes) = makeNode(strdup("+"), strdup("+"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2417 "y.tab.c"
    break;

  case 27:
#line 462 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("-"), strdup("-"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2423 "y.tab.c"
    break;

  case 28:
#line 463 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("~"), strdup("~"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2429 "y.tab.c"
    break;

  case 29:
#line 464 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("!"), strdup("!"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2435 "y.tab.c"
    break;

  case 30:
#line 468 "grammarOld.y"
                           {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2441 "y.tab.c"
    break;

  case 31:
#line 469 "grammarOld.y"
                                            { 
		// Append typename to front of lexeme
		string strType = "(TO_";
		node* type_name = (yyvsp[-2].nodes);
		node* cast_expression = (yyvsp[0].nodes);
		int err = checkValidTypeCast(cast_expression->declSp, type_name->declSp);;
		if(err) error("", err);
		strType = strType + getTypeString(type_name->declSp->type) + ")";
		cast_expression->declSp->type = type_name->declSp->type;
		string s = strType + string(cast_expression->lexeme); 
		strcpy(cast_expression->lexeme, s.c_str());
		(yyval.nodes) = cast_expression;
	}
#line 2459 "y.tab.c"
    break;

  case 32:
#line 485 "grammarOld.y"
                          {(yyval.nodes) = (yyvsp[0].nodes); }
#line 2465 "y.tab.c"
    break;

  case 33:
#line 486 "grammarOld.y"
                                                        { 
		//  no pointer & no string literal
		string var;
		int retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2478 "y.tab.c"
    break;

  case 34:
#line 494 "grammarOld.y"
                                                        { 
		string var;
		int retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}		
		(yyval.nodes) = makeNode(strdup("/"), strdup("/"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2490 "y.tab.c"
    break;

  case 35:
#line 501 "grammarOld.y"
                                                        { 
		int retval = checkFloat((yyvsp[0].nodes));
		if(retval){
			error((yyvsp[0].nodes)->lexeme, SHOULD_NOT_BE_FLOAT);
		}
		string var;
		retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("%"), strdup("%"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2506 "y.tab.c"
    break;

  case 36:
#line 515 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2512 "y.tab.c"
    break;

  case 37:
#line 516 "grammarOld.y"
                                                            { 
		string var;
		int retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("+"), strdup("+"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2524 "y.tab.c"
    break;

  case 38:
#line 523 "grammarOld.y"
                                                            { 
		string var;
		int retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("-"), strdup("-"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2536 "y.tab.c"
    break;

  case 39:
#line 533 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2542 "y.tab.c"
    break;

  case 40:
#line 534 "grammarOld.y"
                                                       { 
		int retval = checkIntLongShort((yyvsp[0].nodes));
		if(retval){
			error((yyvsp[0].nodes)->lexeme, TYPE_ERROR);
		}
		retval = checkIntLongShort((yyvsp[-2].nodes));
		if(retval){
			error((yyvsp[-2].nodes)->lexeme, TYPE_ERROR);
		}
		string var;
		retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("LEFT_OP"), strdup("<<"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2562 "y.tab.c"
    break;

  case 41:
#line 549 "grammarOld.y"
                                                        { 
		int retval = checkIntLongShort((yyvsp[0].nodes));
		if(retval){
			error((yyvsp[0].nodes)->lexeme, TYPE_ERROR);
		}
		retval = checkIntLongShort((yyvsp[-2].nodes));
		if(retval){
			error((yyvsp[-2].nodes)->lexeme, TYPE_ERROR);
		}
		string var;
		retval = implicitTypecastingNotPointerNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
		if(retval){
			error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("RIGHT_OP"), strdup(">>"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2582 "y.tab.c"
    break;

  case 42:
#line 567 "grammarOld.y"
                           { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2588 "y.tab.c"
    break;

  case 43:
#line 568 "grammarOld.y"
                                                     { 
			string var;
			int retval = implicitTypecastingNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
			if(retval){
				error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("<"), strdup("<"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2600 "y.tab.c"
    break;

  case 44:
#line 575 "grammarOld.y"
                                                     { 
			string var;
			int retval = implicitTypecastingNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
			if(retval){
				error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup(">"), strdup(">"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2612 "y.tab.c"
    break;

  case 45:
#line 582 "grammarOld.y"
                                                       {
			string var;
			int retval = implicitTypecastingNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
			if(retval){
				error(var,retval);
		}
	(yyval.nodes) = makeNode(strdup("LE_OP"), strdup("<="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2624 "y.tab.c"
    break;

  case 46:
#line 589 "grammarOld.y"
                                                       { 
			string var;
			int retval = implicitTypecastingNotStringLiteral((yyvsp[-2].nodes), (yyvsp[0].nodes), var);
			if(retval){
				error(var,retval);
		}
		(yyval.nodes) = makeNode(strdup("GE_OP"), strdup(">="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2636 "y.tab.c"
    break;

  case 47:
#line 599 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2642 "y.tab.c"
    break;

  case 48:
#line 600 "grammarOld.y"
                                                          { 
		int retval1 = checkPointer((yyvsp[-2].nodes));
		int retval2 = checkPointer((yyvsp[0].nodes));
		int x = (retval1 == 0) + (retval2 == 0); 
		string var;
		if(x == 2){
			
		}else{
			if(x == 1){
				if(!retval1){
					var = (yyvsp[-2].nodes)->lexeme;
					error(var, POINTER_ERROR);
				}
				if(!retval2){
					var = (yyvsp[0].nodes)->lexeme;
					error(var, POINTER_ERROR);
				}	
			}else{
				retval1 = checkStringLiteral((yyvsp[-2].nodes));
				retval2 = checkStringLiteral((yyvsp[0].nodes));
				x = (retval1 == 0) + (retval2 == 0); 
				if(x == 2){

				}else{
					if(x == 1){
						if(!retval1){
							var = (yyvsp[-2].nodes)->lexeme;
							error(var,STRING_LITERAL_ERROR);
						}
						if(!retval2){
							var = (yyvsp[0].nodes)->lexeme;
							error(var,STRING_LITERAL_ERROR);
						}
					}
				
				}
				
			}
		}
		int rank = giveTypeCastRank((yyvsp[-2].nodes), (yyvsp[0].nodes));
		if(rank){
			var = "typecasting error rank";
			error(var, rank);
		}	
		(yyval.nodes) = makeNode(strdup("EQ_OP"), strdup("=="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2692 "y.tab.c"
    break;

  case 49:
#line 645 "grammarOld.y"
                                                          { 
		int retval1 = checkPointer((yyvsp[-2].nodes));
		int retval2 = checkPointer((yyvsp[0].nodes));
		int x = (retval1 == 0) + (retval2 == 0); 
		string var;
		if(x == 2){
			
		}else{
			if(x == 1){
				if(!retval1){
					var = (yyvsp[-2].nodes)->lexeme;
					error(var, POINTER_ERROR);
				}
				if(!retval2){
					var = (yyvsp[0].nodes)->lexeme;
					error(var, POINTER_ERROR);
				}	
			}else{
				retval1 = checkStringLiteral((yyvsp[-2].nodes));
				retval2 = checkStringLiteral((yyvsp[0].nodes));
				x = (retval1 == 0) + (retval2 == 0); 
				if(x == 2){

				}else{
					if(x == 1){
						if(!retval1){
							var = (yyvsp[-2].nodes)->lexeme;
							error(var,STRING_LITERAL_ERROR);
						}
						if(!retval2){
							var = (yyvsp[0].nodes)->lexeme;
							error(var,STRING_LITERAL_ERROR);
						}
					}
				
				}
				
			}
		}
		int rank = giveTypeCastRank((yyvsp[-2].nodes), (yyvsp[0].nodes));
		if(rank){
			var = "typecasting error rank";
			error(var, rank);
		}
		(yyval.nodes) = makeNode(strdup("NE_OP"), strdup("!="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2742 "y.tab.c"
    break;

  case 50:
#line 693 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2748 "y.tab.c"
    break;

  case 51:
#line 694 "grammarOld.y"
                                                 { 
		int retval = checkIntLongShort((yyvsp[-2].nodes));
		int retval2 = checkIntLongShort((yyvsp[0].nodes));
		if(retval || retval2){
			error("expression", TYPE_ERROR);
		}
		(yyval.nodes) = makeNode(strdup("&"), strdup("&"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2760 "y.tab.c"
    break;

  case 52:
#line 704 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2766 "y.tab.c"
    break;

  case 53:
#line 705 "grammarOld.y"
                                                     { 
		int retval = checkIntLongShort((yyvsp[-2].nodes));
		int retval2 = checkIntLongShort((yyvsp[0].nodes));
		if(retval || retval2){
			error("expression", TYPE_ERROR);
		}
		(yyval.nodes) = makeNode(strdup("^"), strdup("^"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2778 "y.tab.c"
    break;

  case 54:
#line 715 "grammarOld.y"
                                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2784 "y.tab.c"
    break;

  case 55:
#line 716 "grammarOld.y"
                                                              { 
		int retval = checkIntLongShort((yyvsp[-2].nodes));
		int retval2 = checkIntLongShort((yyvsp[0].nodes));
		if(retval || retval2){
			error("expression", TYPE_ERROR);
		}
		(yyval.nodes) = makeNode(strdup("|"), strdup("|"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2796 "y.tab.c"
    break;

  case 56:
#line 726 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 2802 "y.tab.c"
    break;

  case 57:
#line 727 "grammarOld.y"
                                                                { 
		//Strings Literals allowed
		(yyval.nodes) = makeNode(strdup("AND_OP"), strdup("&&"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2810 "y.tab.c"
    break;

  case 58:
#line 733 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2816 "y.tab.c"
    break;

  case 59:
#line 734 "grammarOld.y"
                                                             { 
		//Strings Literals allowed
		(yyval.nodes) = makeNode(strdup("OR_OP"), strdup("||"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 2824 "y.tab.c"
    break;

  case 60:
#line 740 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2830 "y.tab.c"
    break;

  case 61:
#line 741 "grammarOld.y"
                                                                          { 
		
		(yyval.nodes) = makeNode(strdup("?:"), strdup("?:"), 0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL); }
#line 2838 "y.tab.c"
    break;

  case 62:
#line 747 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2844 "y.tab.c"
    break;

  case 63:
#line 748 "grammarOld.y"
                                                                     { 
		node* unary_expression = (yyvsp[-2].nodes);
		node* assignment_expression = (yyvsp[0].nodes);
		if(!unary_expression->declSp){
			declSpec* ds = new declSpec();
			if(!assignment_expression->declSp){
				error(assignment_expression->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
			}
			ds->type = assignment_expression->declSp->type;
			unary_expression->declSp = ds;
		}
		addChild((yyvsp[-1].nodes), (yyvsp[-2].nodes)); addChild((yyvsp[-1].nodes), assignment_expression); (yyval.nodes) = (yyvsp[-1].nodes);
		}
#line 2862 "y.tab.c"
    break;

  case 64:
#line 764 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 2868 "y.tab.c"
    break;

  case 65:
#line 765 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2874 "y.tab.c"
    break;

  case 66:
#line 766 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2880 "y.tab.c"
    break;

  case 67:
#line 767 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2886 "y.tab.c"
    break;

  case 68:
#line 768 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2892 "y.tab.c"
    break;

  case 69:
#line 769 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2898 "y.tab.c"
    break;

  case 70:
#line 770 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("LEFT_ASSIGN"), strdup("<<="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2904 "y.tab.c"
    break;

  case 71:
#line 771 "grammarOld.y"
                       { (yyval.nodes) = makeNode(strdup("RIGHT_ASSIGN"), strdup(">>="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2910 "y.tab.c"
    break;

  case 72:
#line 772 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2916 "y.tab.c"
    break;

  case 73:
#line 773 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2922 "y.tab.c"
    break;

  case 74:
#line 774 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
#line 2928 "y.tab.c"
    break;

  case 75:
#line 778 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2934 "y.tab.c"
    break;

  case 76:
#line 779 "grammarOld.y"
                                               { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 2940 "y.tab.c"
    break;

  case 77:
#line 783 "grammarOld.y"
                                 { (yyval.nodes) = (yyvsp[0].nodes); }
#line 2946 "y.tab.c"
    break;

  case 78:
#line 787 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 2952 "y.tab.c"
    break;

  case 79:
#line 788 "grammarOld.y"
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
				sym_node->declSp = declSpCopy((yyvsp[-2].nodes)->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			} 
			
			curr = curr->next;
		}
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[-1].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[-1].nodes);   
	}
#line 3000 "y.tab.c"
    break;

  case 80:
#line 834 "grammarOld.y"
                                  {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3006 "y.tab.c"
    break;

  case 81:
#line 835 "grammarOld.y"
                                                         {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));} 
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->storageClassSpecifier;
		int err = addStorageClassToDeclSpec(temp, v);
		if(err) error("addStorageClassToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 3019 "y.tab.c"
    break;

  case 82:
#line 843 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3025 "y.tab.c"
    break;

  case 83:
#line 844 "grammarOld.y"
                                                {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));} 
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
	}
#line 3038 "y.tab.c"
    break;

  case 84:
#line 852 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3044 "y.tab.c"
    break;

  case 85:
#line 853 "grammarOld.y"
                                                {
		node *temp = (yyvsp[0].nodes);
		//TODO: Verify correctness, code to merge types commented out
		// vector<int> v = $1->declSp->type;
		// int err = addTypeToDeclSpec(temp, v);
		// if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
	}
#line 3058 "y.tab.c"
    break;

  case 86:
#line 865 "grammarOld.y"
                          {  (yyval.nodes) = (yyvsp[0].nodes);  }
#line 3064 "y.tab.c"
    break;

  case 87:
#line 866 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);
	}
#line 3072 "y.tab.c"
    break;

  case 88:
#line 872 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3078 "y.tab.c"
    break;

  case 89:
#line 873 "grammarOld.y"
                                     { 
		node* declarator = (yyvsp[-2].nodes);
		node* initializer = (yyvsp[0].nodes);
		if(!declarator->declSp){
			declSpec* ds = new declSpec();
			if(!initializer->declSp){
				error(initializer->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
			}
			ds->type = initializer->declSp->type;
			declarator->declSp = ds;
		}
		(yyval.nodes) = makeNode(strdup("="), strdup("="), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
	}
#line 3096 "y.tab.c"
    break;

  case 90:
#line 889 "grammarOld.y"
                  {(yyval.nodes) = makeStorageClassNode(TYPE_TYPEDEF, strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3102 "y.tab.c"
    break;

  case 91:
#line 890 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_EXTERN, strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3108 "y.tab.c"
    break;

  case 92:
#line 891 "grammarOld.y"
                 {(yyval.nodes) = makeStorageClassNode(TYPE_STATIC, strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3114 "y.tab.c"
    break;

  case 93:
#line 892 "grammarOld.y"
               {(yyval.nodes) = makeStorageClassNode(TYPE_AUTO, strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3120 "y.tab.c"
    break;

  case 94:
#line 893 "grammarOld.y"
                   {(yyval.nodes) = makeStorageClassNode(TYPE_REGISTER, strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3126 "y.tab.c"
    break;

  case 95:
#line 897 "grammarOld.y"
               { (yyval.nodes) = makeTypeNode(TYPE_VOID);	}
#line 3132 "y.tab.c"
    break;

  case 96:
#line 898 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_CHAR);}
#line 3138 "y.tab.c"
    break;

  case 97:
#line 899 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_SHORT);}
#line 3144 "y.tab.c"
    break;

  case 98:
#line 900 "grammarOld.y"
              {(yyval.nodes) = makeTypeNode(TYPE_INT);}
#line 3150 "y.tab.c"
    break;

  case 99:
#line 901 "grammarOld.y"
               {(yyval.nodes) = makeTypeNode(TYPE_LONG);}
#line 3156 "y.tab.c"
    break;

  case 100:
#line 902 "grammarOld.y"
                {(yyval.nodes) = makeTypeNode(TYPE_FLOAT);}
#line 3162 "y.tab.c"
    break;

  case 101:
#line 903 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_DOUBLE);}
#line 3168 "y.tab.c"
    break;

  case 102:
#line 904 "grammarOld.y"
                 {(yyval.nodes) = makeTypeNode(TYPE_SIGNED);}
#line 3174 "y.tab.c"
    break;

  case 103:
#line 905 "grammarOld.y"
                   {(yyval.nodes) = makeTypeNode( TYPE_UNSIGNED);}
#line 3180 "y.tab.c"
    break;

  case 104:
#line 906 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3186 "y.tab.c"
    break;

  case 105:
#line 907 "grammarOld.y"
                         {(yyval.nodes) = (yyvsp[0].nodes);}
#line 3192 "y.tab.c"
    break;

  case 106:
#line 908 "grammarOld.y"
                    { (yyval.nodes) = NULL;}
#line 3198 "y.tab.c"
    break;

  case 107:
#line 912 "grammarOld.y"
          {
		node* temp = makeDeadNode();
		temp->lexeme = yylval.id;
		(yyval.nodes) =temp;		
	}
#line 3208 "y.tab.c"
    break;

  case 108:
#line 920 "grammarOld.y"
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
#line 3234 "y.tab.c"
    break;

  case 109:
#line 941 "grammarOld.y"
                                                          {cout << "488 feature not included"<< endl; (yyval.nodes) = NULL;}
#line 3240 "y.tab.c"
    break;

  case 110:
#line 942 "grammarOld.y"
                                      {
		string name(previ); //TODO: wrong name, uses previ
		
		if(!structLookUp(gSymTable, name)) { // Recursive lookup
			if(!structLookUp(gSymTable, string(yylval.id))){
				error(name, STRUCT_NOT_DECLARED);
			}
			else{
				name = yylval.id;
			}
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
#line 3265 "y.tab.c"
    break;

  case 111:
#line 965 "grammarOld.y"
                 {
		node* temp = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_STRUCT;
		// printf("struct here\n"); 
		(yyval.nodes) = temp;}
#line 3275 "y.tab.c"
    break;

  case 112:
#line 970 "grammarOld.y"
                {
		node* temp = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_UNION;
		(yyval.nodes) = temp;}
#line 3284 "y.tab.c"
    break;

  case 113:
#line 977 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3290 "y.tab.c"
    break;

  case 114:
#line 978 "grammarOld.y"
                                                     {  
		for(auto &u : (yyvsp[0].nodes)->structParamList)
			(yyvsp[-1].nodes)->structParamList.push_back(u);
		(yyval.nodes) = (yyvsp[-1].nodes);
	}
#line 3300 "y.tab.c"
    break;

  case 115:
#line 986 "grammarOld.y"
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
				int ptrLevel = 0;
				if(u->declSp)
					ptrLevel = u->declSp->ptrLevel;
				u->declSp = specifier_qualifier_list->declSp;
				u->declSp->ptrLevel = ptrLevel;				
				specifier_qualifier_list->structParamList.push_back(u);
			}
			curr = curr -> next;
		}
		(yyval.nodes) = specifier_qualifier_list;
	}
#line 3328 "y.tab.c"
    break;

  case 116:
#line 1012 "grammarOld.y"
                                                  {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));}
		node *temp = (yyvsp[0].nodes);
		vector<int> v = (yyvsp[-1].nodes)->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		(yyval.nodes) = temp;
		}
#line 3341 "y.tab.c"
    break;

  case 117:
#line 1020 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3347 "y.tab.c"
    break;

  case 118:
#line 1021 "grammarOld.y"
                                                  {
		node *temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
	}
#line 3357 "y.tab.c"
    break;

  case 119:
#line 1026 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3363 "y.tab.c"
    break;

  case 120:
#line 1030 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3369 "y.tab.c"
    break;

  case 121:
#line 1031 "grammarOld.y"
                                                       {
		node* struct_declarator = (yyvsp[0].nodes); 
		node* struct_declarator_list = (yyvsp[-2].nodes); 
		for(auto &u : struct_declarator->structParamList)
			struct_declarator_list->structParamList.push_back(u);
		(yyval.nodes) = struct_declarator_list;
	}
#line 3381 "y.tab.c"
    break;

  case 122:
#line 1041 "grammarOld.y"
                     { 
		node* declarator = (yyvsp[0].nodes); 
		structParam* param = new structParam();
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		declarator->structParamList.push_back(param);
		(yyval.nodes) = declarator;
	}
#line 3394 "y.tab.c"
    break;

  case 123:
#line 1049 "grammarOld.y"
                                  {(yyval.nodes) = NULL;}
#line 3400 "y.tab.c"
    break;

  case 124:
#line 1050 "grammarOld.y"
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
#line 3417 "y.tab.c"
    break;

  case 125:
#line 1066 "grammarOld.y"
                                       {(yyval.nodes) = makeNode(strdup("ENUM"), strdup("enum"), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3423 "y.tab.c"
    break;

  case 126:
#line 1067 "grammarOld.y"
                                                  { (yyval.nodes) = makeNode(strdup("ENUM"), strdup("enum"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3429 "y.tab.c"
    break;

  case 127:
#line 1068 "grammarOld.y"
                          { (yyval.nodes) = (node*)NULL;}
#line 3435 "y.tab.c"
    break;

  case 128:
#line 1072 "grammarOld.y"
                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3441 "y.tab.c"
    break;

  case 129:
#line 1073 "grammarOld.y"
                                         { if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 3447 "y.tab.c"
    break;

  case 130:
#line 1077 "grammarOld.y"
                     {(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3453 "y.tab.c"
    break;

  case 131:
#line 1078 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("="),strdup("="), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3459 "y.tab.c"
    break;

  case 132:
#line 1082 "grammarOld.y"
                {
		node* temp = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isConst = true;
		(yyval.nodes) = temp;
	}
#line 3470 "y.tab.c"
    break;

  case 133:
#line 1088 "grammarOld.y"
                   {
		node* temp = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isVolatile = true;
		(yyval.nodes) = temp;
	}
#line 3481 "y.tab.c"
    break;

  case 134:
#line 1097 "grammarOld.y"
                                     { 
		node *temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));

		(yyval.nodes) = temp;
		currDecl = (yyval.nodes);
	}
#line 3494 "y.tab.c"
    break;

  case 135:
#line 1105 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); currDecl = (yyval.nodes); }
#line 3500 "y.tab.c"
    break;

  case 136:
#line 1110 "grammarOld.y"
                     { 
		(yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		(yyval.nodes)-> infoType = INFO_TYPE_NORMAL;
		(yyval.nodes)->lineNo = line+1;
	}
#line 3510 "y.tab.c"
    break;

  case 137:
#line 1115 "grammarOld.y"
                             { (yyval.nodes) = (yyvsp[-1].nodes);}
#line 3516 "y.tab.c"
    break;

  case 138:
#line 1116 "grammarOld.y"
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
#line 3532 "y.tab.c"
    break;

  case 139:
#line 1127 "grammarOld.y"
                                    {(yyval.nodes) = (yyvsp[-2].nodes); }
#line 3538 "y.tab.c"
    break;

  case 140:
#line 1128 "grammarOld.y"
                                                        { 
		node* direct_declarator = (yyvsp[-3].nodes);	
		node* parameter_type_list = (yyvsp[-1].nodes);	
		// Done: Add parameters to symbol table with appropriate types, also add to function arguments

		direct_declarator->paramList = parameter_type_list->paramList;
		direct_declarator->paramSize = parameter_type_list->paramSize;
		direct_declarator->infoType = INFO_TYPE_FUNC;
		(yyval.nodes)=direct_declarator;
	}
#line 3553 "y.tab.c"
    break;

  case 141:
#line 1138 "grammarOld.y"
                                                    { 
		// Not handled: Add to symbol table with appropriate type??, also add to function arguments
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 3562 "y.tab.c"
    break;

  case 142:
#line 1142 "grammarOld.y"
                                    { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3568 "y.tab.c"
    break;

  case 143:
#line 1146 "grammarOld.y"
              { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		incrementPointerLevel(temp, NULL);
		(yyval.nodes) = temp;
	}
#line 3578 "y.tab.c"
    break;

  case 144:
#line 1151 "grammarOld.y"
                                  { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) =  temp;
		}
#line 3589 "y.tab.c"
    break;

  case 145:
#line 1157 "grammarOld.y"
                      { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[0].nodes), (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 3600 "y.tab.c"
    break;

  case 146:
#line 1163 "grammarOld.y"
                                          { 
		node* temp  = makeNode(strdup("*"), strdup("*"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL,(node*)NULL );
		int retval = incrementPointerLevel(temp, (yyvsp[0].nodes));
		mergeConstVolatile((yyvsp[0].nodes),(yyvsp[-1].nodes));
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
		}
#line 3612 "y.tab.c"
    break;

  case 147:
#line 1173 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3618 "y.tab.c"
    break;

  case 148:
#line 1174 "grammarOld.y"
                                             { 
		// if($1){ makeSibling($2,$1);$$ = $1;} else $$ = $2;
		node* temp = (yyvsp[-1].nodes);
		mergeConstVolatile(temp, (yyvsp[0].nodes));
		(yyval.nodes) = temp;
	}
#line 3629 "y.tab.c"
    break;

  case 149:
#line 1184 "grammarOld.y"
                         { 
		node* parameter_list = (yyvsp[0].nodes);
		parameter_list->paramSize = parameter_list->paramList.size();
		(yyval.nodes) = parameter_list;
	 }
#line 3639 "y.tab.c"
    break;

  case 150:
#line 1189 "grammarOld.y"
                                      { 
		makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes));
		node* parameter_list = (yyvsp[-2].nodes);
		parameter_list->paramSize = INF_PARAM_LIST;
		(yyval.nodes) = parameter_list;
	}
#line 3650 "y.tab.c"
    break;

  case 151:
#line 1199 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3656 "y.tab.c"
    break;

  case 152:
#line 1200 "grammarOld.y"
                                                   { 
		if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));}
		node* parameter_list = (yyvsp[-2].nodes);
		node* parameter_declaration = (yyvsp[0].nodes);
		for(auto& u: parameter_declaration->paramList)
			parameter_list->paramList.push_back(u);
		(yyval.nodes) = parameter_list;
	}
#line 3669 "y.tab.c"
    break;

  case 153:
#line 1211 "grammarOld.y"
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
#line 3693 "y.tab.c"
    break;

  case 154:
#line 1230 "grammarOld.y"
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
#line 3719 "y.tab.c"
    break;

  case 155:
#line 1251 "grammarOld.y"
                                 { 
		node* declaration_specifiers = (yyvsp[0].nodes);

		param *parameter = new param();
		if(!parameter->declSp) {
			parameter->declSp = new declSpec();
		}
		if(declaration_specifiers->declSp) {
			parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		}
		parameter->paramName = "111NoParamName111";
		declaration_specifiers->paramList.push_back(parameter);

		(yyval.nodes) = declaration_specifiers; 
	}
#line 3739 "y.tab.c"
    break;

  case 156:
#line 1269 "grammarOld.y"
                     { 
		 (yyval.nodes) = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 3746 "y.tab.c"
    break;

  case 157:
#line 1271 "grammarOld.y"
                                         { 
		makeSibling(makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-2].nodes)); (yyval.nodes) = (yyvsp[-2].nodes);}
#line 3753 "y.tab.c"
    break;

  case 158:
#line 1276 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3759 "y.tab.c"
    break;

  case 159:
#line 1277 "grammarOld.y"
                                                       {
		if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));}
		node *temp = (yyvsp[-1].nodes);
		if((yyvsp[0].nodes)->declSp) {
			int err = addTypeToDeclSpec(temp, (yyvsp[0].nodes)->declSp->type);
			if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
			err = addStorageClassToDeclSpec(temp, (yyvsp[0].nodes)->declSp->storageClassSpecifier);
			mergeConstVolatile(temp, (yyvsp[0].nodes));
			copyPtrLevel(temp, (yyvsp[0].nodes));
		}
		(yyval.nodes) = temp;
	}
#line 3776 "y.tab.c"
    break;

  case 160:
#line 1292 "grammarOld.y"
                  { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3782 "y.tab.c"
    break;

  case 161:
#line 1293 "grammarOld.y"
                                     { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3788 "y.tab.c"
    break;

  case 162:
#line 1294 "grammarOld.y"
                                             {
		//assuming ptr level of direct_abstract_declarator is zero
		node* temp = (yyvsp[0].nodes);
		mergeConstVolatile(temp, (yyvsp[-1].nodes));
		copyPtrLevel(temp, (yyvsp[-1].nodes));
		(yyval.nodes) = temp;
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;
	}
#line 3801 "y.tab.c"
    break;

  case 163:
#line 1306 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3807 "y.tab.c"
    break;

  case 164:
#line 1307 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3813 "y.tab.c"
    break;

  case 165:
#line 1308 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3819 "y.tab.c"
    break;

  case 166:
#line 1309 "grammarOld.y"
                                             {(yyval.nodes) = (yyvsp[-2].nodes);}
#line 3825 "y.tab.c"
    break;

  case 167:
#line 1310 "grammarOld.y"
                                                                 {(yyval.nodes) = (yyvsp[-3].nodes);}
#line 3831 "y.tab.c"
    break;

  case 168:
#line 1311 "grammarOld.y"
                  {(yyval.nodes) = (node*)NULL;}
#line 3837 "y.tab.c"
    break;

  case 169:
#line 1312 "grammarOld.y"
                                      {(yyval.nodes) = (yyvsp[-1].nodes);}
#line 3843 "y.tab.c"
    break;

  case 170:
#line 1313 "grammarOld.y"
                                             { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3849 "y.tab.c"
    break;

  case 171:
#line 1314 "grammarOld.y"
                                                                 { (yyval.nodes) = (yyvsp[-3].nodes); }
#line 3855 "y.tab.c"
    break;

  case 172:
#line 1318 "grammarOld.y"
                                { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3861 "y.tab.c"
    break;

  case 173:
#line 1319 "grammarOld.y"
                                   { (yyval.nodes) = (yyvsp[-1].nodes); }
#line 3867 "y.tab.c"
    break;

  case 174:
#line 1320 "grammarOld.y"
                                       { (yyval.nodes) = (yyvsp[-2].nodes); }
#line 3873 "y.tab.c"
    break;

  case 175:
#line 1324 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3879 "y.tab.c"
    break;

  case 176:
#line 1325 "grammarOld.y"
                                           {if((yyvsp[-2].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-2].nodes));(yyval.nodes) = (yyvsp[-2].nodes);} else (yyval.nodes) = (yyvsp[0].nodes);}
#line 3885 "y.tab.c"
    break;

  case 177:
#line 1329 "grammarOld.y"
                            { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3891 "y.tab.c"
    break;

  case 178:
#line 1330 "grammarOld.y"
                             {(yyval.nodes) = (yyvsp[0].nodes); }
#line 3897 "y.tab.c"
    break;

  case 179:
#line 1331 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3903 "y.tab.c"
    break;

  case 180:
#line 1332 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3909 "y.tab.c"
    break;

  case 181:
#line 1333 "grammarOld.y"
                              { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3915 "y.tab.c"
    break;

  case 182:
#line 1334 "grammarOld.y"
                         { (yyval.nodes) = (yyvsp[0].nodes); }
#line 3921 "y.tab.c"
    break;

  case 183:
#line 1338 "grammarOld.y"
                                   {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3927 "y.tab.c"
    break;

  case 184:
#line 1339 "grammarOld.y"
                                                 { (yyval.nodes) = makeNode(strdup("CASE"), strdup("case"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL); }
#line 3933 "y.tab.c"
    break;

  case 185:
#line 1340 "grammarOld.y"
                                {(yyval.nodes) = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 3939 "y.tab.c"
    break;

  case 186:
#line 1344 "grammarOld.y"
                               { (yyval.nodes) = (node*)NULL; gSymTable = gSymTable->parent;}
#line 3945 "y.tab.c"
    break;

  case 187:
#line 1345 "grammarOld.y"
                                              { (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3951 "y.tab.c"
    break;

  case 188:
#line 1346 "grammarOld.y"
                                                {  (yyval.nodes) = (yyvsp[-1].nodes); gSymTable = gSymTable->parent;}
#line 3957 "y.tab.c"
    break;

  case 189:
#line 1347 "grammarOld.y"
                                                               { if((yyvsp[-2].nodes)){(yyval.nodes) = makeNode(strdup("BODY"), strdup("body"), 0, (yyvsp[-2].nodes), (yyvsp[-1].nodes), (node*)NULL, (node*)NULL);} else{
		(yyval.nodes) = (yyvsp[-1].nodes);} gSymTable = gSymTable->parent;}
#line 3964 "y.tab.c"
    break;

  case 190:
#line 1352 "grammarOld.y"
      { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}
#line 3972 "y.tab.c"
    break;

  case 191:
#line 1357 "grammarOld.y"
                      { (yyval.nodes) = (yyvsp[0].nodes);}
#line 3978 "y.tab.c"
    break;

  case 192:
#line 1358 "grammarOld.y"
                                       {
		node* temp = NULL;
		string s((yyvsp[-1].nodes)->name);
		bool c1  = (s == "DECL_LIST");
		if( c1 ){ 
			temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, (yyvsp[-1].nodes)->childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
		} else {
			temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);
		}
		for(auto &u : (yyvsp[0].nodes)->paramList){
			temp->paramList.push_back(u);
		}
		for(auto &u : (yyvsp[-1].nodes)->paramList){
			temp->paramList.push_back(u);
		}
		(yyval.nodes) = temp;
	}
#line 4000 "y.tab.c"
    break;

  case 193:
#line 1378 "grammarOld.y"
                    { (yyval.nodes) = (yyvsp[0].nodes); }
#line 4006 "y.tab.c"
    break;

  case 194:
#line 1379 "grammarOld.y"
                                   { if(!strcmp(((yyvsp[-1].nodes) -> name), "STMT_LIST")){(yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup("statement list"), 0, (yyvsp[-1].nodes) -> childList, (yyvsp[0].nodes), (node*)NULL, (node*)NULL);} else (yyval.nodes) = makeNode(strdup("STMT_LIST"), strdup("statement list"), 0, (yyvsp[-1].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 4012 "y.tab.c"
    break;

  case 195:
#line 1383 "grammarOld.y"
              {(yyval.nodes) = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4018 "y.tab.c"
    break;

  case 196:
#line 1384 "grammarOld.y"
                         {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (yyvsp[-1].nodes)); (yyval.nodes) = (yyvsp[-1].nodes);}
#line 4024 "y.tab.c"
    break;

  case 197:
#line 1388 "grammarOld.y"
                                          {(yyval.nodes) = makeNode(strdup("IF"), strdup("if"),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 4030 "y.tab.c"
    break;

  case 198:
#line 1389 "grammarOld.y"
                                                         {(yyval.nodes) = makeNode(strdup("IF_ELSE"), strdup("else"),0, (yyvsp[-4].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 4036 "y.tab.c"
    break;

  case 199:
#line 1390 "grammarOld.y"
                                              {(yyval.nodes) = makeNode(strdup("SWITCH"), strdup("switch"),0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 4042 "y.tab.c"
    break;

  case 200:
#line 1394 "grammarOld.y"
                                             {(yyval.nodes) = makeNode(strdup("WHILE"), strdup("while"), 0, (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL, (node*)NULL);}
#line 4048 "y.tab.c"
    break;

  case 201:
#line 1395 "grammarOld.y"
                                                    {(yyval.nodes) = makeNode(strdup("DO WHILE"), strdup("do while"), 0, (yyvsp[-5].nodes), (yyvsp[-2].nodes), (node*)NULL, (node*)NULL);}
#line 4054 "y.tab.c"
    break;

  case 202:
#line 1396 "grammarOld.y"
                                                                          {(yyval.nodes) = makeNode(strdup("FOR"), strdup("for"),0, (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes), (node*)NULL);}
#line 4060 "y.tab.c"
    break;

  case 203:
#line 1397 "grammarOld.y"
                                                                                     {(yyval.nodes) = makeNode(strdup("FOR"), strdup("for"),0, (yyvsp[-4].nodes), (yyvsp[-3].nodes), (yyvsp[-2].nodes), (yyvsp[0].nodes));}
#line 4066 "y.tab.c"
    break;

  case 204:
#line 1401 "grammarOld.y"
                              {(yyval.nodes) = makeNode(strdup("GOTO"), strdup("goto"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4072 "y.tab.c"
    break;

  case 205:
#line 1402 "grammarOld.y"
                      { (yyval.nodes) = makeNode(strdup("CONTINUE"), strdup("continue"),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4078 "y.tab.c"
    break;

  case 206:
#line 1403 "grammarOld.y"
                    { (yyval.nodes) = makeNode(strdup("BREAK"), strdup("break"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4084 "y.tab.c"
    break;

  case 207:
#line 1404 "grammarOld.y"
                     { (yyval.nodes) = makeNode(strdup("RETURN"), strdup("return"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4090 "y.tab.c"
    break;

  case 208:
#line 1405 "grammarOld.y"
                                { (yyval.nodes) = makeNode(strdup("RETURN"), strdup("return"), 0, (yyvsp[-1].nodes), (node*)NULL, (node*)NULL, (node*)NULL);}
#line 4096 "y.tab.c"
    break;

  case 209:
#line 1409 "grammarOld.y"
                               { (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes); }
#line 4102 "y.tab.c"
    break;

  case 210:
#line 1410 "grammarOld.y"
                                                {if((yyvsp[-1].nodes)){makeSibling((yyvsp[0].nodes),(yyvsp[-1].nodes));(yyval.nodes) = (yyvsp[-1].nodes);} else (yyval.nodes) = (yyvsp[0].nodes); root = (yyval.nodes);}
#line 4108 "y.tab.c"
    break;

  case 211:
#line 1414 "grammarOld.y"
                              {(yyval.nodes) = (yyvsp[0].nodes);}
#line 4114 "y.tab.c"
    break;

  case 212:
#line 1415 "grammarOld.y"
                      {(yyval.nodes) = (yyvsp[0].nodes);}
#line 4120 "y.tab.c"
    break;

  case 213:
#line 1419 "grammarOld.y"
                                                                                            { 
		addChild((yyvsp[-3].nodes), (yyvsp[-1].nodes)); 
		addChild((yyvsp[-3].nodes), (yyvsp[0].nodes)); 
	 	
		node* declaration_specifiers = (yyvsp[-4].nodes); // type
		node* declarator = (yyvsp[-3].nodes); // func , param list
		
		
		for(auto &u: (yyvsp[-1].nodes)->paramList){
			(yyvsp[-3].nodes)->paramList.push_back(u);
		}
		addFunctionSymbol( declaration_specifiers, declarator);
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 4139 "y.tab.c"
    break;

  case 214:
#line 1433 "grammarOld.y"
                                                                           { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declaration_specifiers = (yyvsp[-3].nodes); // type
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(declaration_specifiers, declarator); 
		// // Adding params to symtab
		// symbolTable* curr;
		// for(auto s: gSymTable->childList){
		// 	curr = s;
		// }

		// for(auto &p: declarator->paramList){
		// 	int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
		// 	if(retVal) {
		// 		error(p->paramName, retVal);
		// 	}
		// 	string lex = p->paramName;
			
		// 	struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
		// 	if(!sym_node){
		// 		error(lex, ALLOCATION_ERROR);
		// 	}
			
		// 	// if(temp->infoType == INFO_TYPE_ARRAY){
		// 	// 	sym_node->infoType = INFO_TYPE_ARRAY;
				
		// 	// 	sym_node->declSp = declSpCopy(p->declSp);
		// 	// 	if(p->declSp)
		// 	// 		sym_node->declSp->ptrLevel = p->declSp->ptrLevel;
		// 	// }
		// 	// else {
		// 	sym_node->declSp = declSpCopy(p->declSp);
		// 	// if(temp->declSp)
		// 	// 		sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
		// 	// } 
		// }

		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 4183 "y.tab.c"
    break;

  case 215:
#line 1472 "grammarOld.y"
                                                                     { 
		addChild((yyvsp[-3].nodes), (yyvsp[-1].nodes)); 
		addChild((yyvsp[-3].nodes), (yyvsp[0].nodes));
		node* declarator = (yyvsp[-3].nodes); // func , param list
		
		for(auto &u: (yyvsp[-1].nodes)->paramList){
			(yyvsp[-3].nodes)->paramList.push_back(u);
		}
		addFunctionSymbol(NULL, declarator);
		(yyval.nodes) = (yyvsp[-3].nodes);
	}
#line 4199 "y.tab.c"
    break;

  case 216:
#line 1483 "grammarOld.y"
                                                    { 
		addChild((yyvsp[-2].nodes), (yyvsp[0].nodes));
		node* declarator = (yyvsp[-2].nodes); // func , param list
		addFunctionSymbol(NULL, declarator);

		// // Adding params to symtab
		// symbolTable* curr;
		// for(auto s: gSymTable->childList){
		// 	curr = s;
		// }

		// for(auto &p: declarator->paramList){
		// 	int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
		// 	if(retVal) {
		// 		error(p->paramName, retVal);
		// 	}
		// 	string lex = p->paramName;
			
		// 	struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
		// 	if(!sym_node){
		// 		error(lex, ALLOCATION_ERROR);
		// 	}
			
		// 	// if(temp->infoType == INFO_TYPE_ARRAY){
		// 	// 	sym_node->infoType = INFO_TYPE_ARRAY;
				
		// 	// 	sym_node->declSp = declSpCopy(p->declSp);
		// 	// 	if(p->declSp)
		// 	// 		sym_node->declSp->ptrLevel = p->declSp->ptrLevel;
		// 	// }
		// 	// else {
		// 	sym_node->declSp = declSpCopy(p->declSp);
		// 	// if(temp->declSp)
		// 	// 		sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
		// 	// } 
		// }
		
		(yyval.nodes) = (yyvsp[-2].nodes);
	}
#line 4243 "y.tab.c"
    break;

  case 217:
#line 1525 "grammarOld.y"
          {
		// TODO: Send type from declaration specifier to function name
		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		// Adding params to symtab
		struct node* declarator = currDecl;
		symbolTable* curr = gSymTable;

		for(auto &p: declarator->paramList){
			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
			if(retVal) {
				error(p->paramName, retVal);
			}
			string lex = p->paramName;
			
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			
			// if(temp->infoType == INFO_TYPE_ARRAY){
			// 	sym_node->infoType = INFO_TYPE_ARRAY;
				
			// 	sym_node->declSp = declSpCopy(p->declSp);
			// 	if(p->declSp)
			// 		sym_node->declSp->ptrLevel = p->declSp->ptrLevel;
			// }
			// else {
			sym_node->declSp = declSpCopy(p->declSp);
			// if(temp->declSp)
			// 		sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			// } 
		}
	}
#line 4282 "y.tab.c"
    break;


#line 4286 "y.tab.c"

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
#line 1559 "grammarOld.y"

#include <stdio.h>
int id = 0;



void printDeclarations(node* root, FILE *fp) {
    if(!root || root->isLeaf == DEAD_NODE ) return;
	string s1(root->name), s2(root->lexeme);
	string s = "n: " + s1 + " , l: " + s2 + "\0";
	if(root->isLeaf){
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, s.c_str());
	} else {
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, s.c_str());
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


using namespace std;

int main(int ac, char **av) {
	cout << "I am in main" << endl;
	insert_into_sets();
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror(" Error: ");
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
