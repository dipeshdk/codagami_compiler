#ifndef constantsHeader
#define constantsHeader

#define NO_BIT_ASSIGNED -1
#define TEMP_LINE_NO -301

#define INF_PARAM_LIST INT_MAX

#define TYPE_CHAR 501
#define TYPE_INT 502
#define TYPE_FLOAT 503
#define TYPE_VOID 504
#define TYPE_STRUCT 505
#define TYPE_STRING_LITERAL 506

#define SIZE_CHAR 1
#define SIZE_SHORT 2
#define SIZE_INT 4 
#define SIZE_LONG 8
#define SIZE_FLOAT 4
#define SIZE_DOUBLE 8
#define SIZE_VOID 0

#define DEAD_NODE 600

#define DEFAULT_ERROR 101
#define SYMBOL_ALREADY_EXISTS 102
#define ALLOCATION_ERROR 103
#define INVALID_ARGS 104
#define CONFLICTING_TYPES 105
#define UNDECLARED_SYMBOL 106
#define TYPE_ERROR 107
#define ARRAY_SIZE_NOT_CONSTANT 108
#define ARRAY_SIZE_SHOULD_BE_INT 109
#define INVALID_STORAGE_CLASS 110
#define SYMBOL_NOT_FOUND 111
#define STRUCT_NOT_DECLARED 112
#define INVALID_SYNTAX 113
#define VARIABLE_NOT_A_STRUCT 114
#define INVALID_REFERENCE 115
#define ARRAY_INDEX_SHOULD_BE_INT 116
#define INVALID_ARGS_IN_FUNC_CALL 117
#define INVALID_STRUCT_PARAM 118
#define INTERNAL_ERROR_DECL_SP_NOT_DEFINED 119
#define POINTER_ERROR 120
#define STRING_LITERAL_ERROR 121
#define SHOULD_NOT_BE_FLOAT 122
#define VOID_ERROR 123
#define UNSUPPORTED_FUNCTIONALITY 125
#define NOT_A_CHAR 126


#define INFO_TYPE_NORMAL 201
#define INFO_TYPE_FUNC 202
#define INFO_TYPE_ARRAY 203
#define INFO_TYPE_STRUCT 204
#define INFO_TYPE_UNION 205
#define INFO_NESTED_STRUCT 206


#define NOT_GOTO_IN_BACKPATCH 301

#define OP_GOTO 701
#define OP_ADDI 702
#define OP_MULI 703 
#define OP_IFGOTO 704
#define OP_SUBI 705
#define OP_ASSIGNMENT 706
#define OP_UNARY_MINUS 707
#define OP_DIVI 708
#define OP_CALL 709
#define OP_LEFT_SHIFT 7010
#define OP_RIGHT_SHIFT 7011
#define OP_NOR 7012
#define OP_OR 7013
#define OP_AND 7014
#define OP_NOT 7015
#define OP_XOR 7016
#define OP_EQ 7017
#define OP_NEQ 7018
#define OP_LEQ 7019
#define OP_GREATER 7020
#define OP_LESS 7021
#define OP_MOD 7022
#define OP_ADDF 7023
#define OP_MULF 7024
#define OP_SUBF 7025
#define OP_DIVF 7026


#endif