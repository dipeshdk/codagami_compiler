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
#define NOT_CONSTANT 507

#define RANK_TYPE_STRUCT 6
#define RANK_TYPE_FLOAT 5
#define RANK_TYPE_INT 4
#define RANK_TYPE_POINTER 3
#define RANK_TYPE_CHAR 2
#define RANK_TYPE_VOID 1

#define SIZE_CHAR 1
#define SIZE_SHORT 2
#define SIZE_INT 4
#define SIZE_LONG 8
#define SIZE_FLOAT 4
#define SIZE_DOUBLE 8
#define SIZE_VOID 0

#define DEAD_NODE 600
#define UNNAMED_PARAM "UNNAMED PARAM"

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
#define NON_POINTER_DEFERENCE 127
#define UNDEFINED_FUNCTION 128
#define MISMATCH_DEFINITION_DECLARATION 129
#define ASSIGNMENT_TO_CONSTANT_ERROR 130
#define UNDEFINED_SCOPE_STNODE_ERROR 131
#define REGISTER_ASSIGNMENT_ERROR 132
#define BEGIN_FUNC_ARG_NOT_CONSTANT_ERROR 133
#define CALL_TO_GLOBAL_ERROR 134
#define POPPARAM_ARG_NOT_CONSTANT 135
#define DEREFERENCING_CONSTANT_ERROR 136
#define ARRAY_SIZE_SHOULD_BE_POSITIVE 137
#define ARRAY_INDEX_SHOULD_BE_POSITIVE 138
#define GOTO_ADDR_NOT_CONST 139
#define NON_GLOBAL_STRING_LITERAL 140
#define INVALID_STRING_LITERAL_ASSIGNMENT 141
#define INVALID_POINTER_ADDR 142
#define INVALID_GLOBAL_INITIALIZER 143
#define CASE_SHOULD_BE_INT 144

#define NOT_CONSTANT_EXCEPTION 601

#define INFO_TYPE_NORMAL 201
#define INFO_TYPE_FUNC 202
#define INFO_TYPE_ARRAY 203
#define INFO_TYPE_STRUCT 204
#define INFO_TYPE_UNION 205
#define INFO_NESTED_STRUCT 206

#define NOT_GOTO_IN_BACKPATCH 301

#define OP_GOTO 701 //{OP_GOTO, "", "", gotoAddr}
#define OP_ADDI 702
#define OP_MULI 703
#define OP_IFGOTO 704 //{OP_IFGOTO, relop->addr, "", gotoAddr}
#define OP_SUBI 705
#define OP_ASSIGNMENT 706
#define OP_UNARY_MINUS 707
#define OP_DIVI 708
#define OP_CALL 709
#define OP_LEFT_SHIFT 710
#define OP_RIGHT_SHIFT 711
#define OP_OR 713
#define OP_AND 714
#define OP_LOGICAL_NOT 715
#define OP_XOR 716
#define OP_EQ 717
#define OP_NEQ 718
#define OP_LEQ 719
#define OP_GREATER 720
#define OP_LESS 721
#define OP_EQF 7170
#define OP_NEQF 7180
#define OP_LEQF 7190
#define OP_GREATERF 7200
#define OP_LESSF 7210
#define OP_ADDF 723
#define OP_MULF 724
#define OP_SUBF 725
#define OP_DIVF 726
#define OP_MOD 722
#define OP_GEQ 727
#define OP_GEQF 7270
#define OP_ANDAND 728
#define OP_OROR 729
#define OP_IFNEQGOTO 730 // {OP_IFNEQGOTO, operand1, operand2, gotoAddr if not equal}
#define OP_BEGINFUNC 731
#define OP_ENDFUNC 732
#define OP_RETURN 733
#define OP_PUSHPARAM 734
#define OP_POPPARAM 735
#define OP_LCALL 736
#define OP_LABEL 737
#define OP_ADDR 738
#define OP_BITWISE_NOT 739
#define OP_MOV 740

#define BLANK_STR "BLANK"
#define EMPTY_STR "______"

#define GLOBAL_SCOPE_NUM 0

#define DEFAULT_INITIALIZATION_VALUE 0
#define DEFAULT_INITIALIZATION_VALUE_TYPE TYPE_INT

#define CALLQ_PADDING 16

#define NOT_CONSTANT_EXCEPTION 601
#define NUM_REGISTER 8
#define NUM_REGISTER_FLOAT 16
#define CONSTANT "__constant__"
#define NO_VAR_VALUE_ASSIGNED "__not_assigned__"
#define EAX_REGISTER_INDEX 3
#define EDX_REGISTER_INDEX 4
#define ECX_REGISTER_INDEX 4
#define CL_REGISTER "%cl" // ECX 8 bit version

#define REGISTER_RDI "%rdi"
#define REGISTER_R10 "%r10"
#define REGISTER_R11 "%r11"
#define REGISTER_RCX "%rcx"
#define REGISTER_RAX "%rax"
#define REGISTER_RDX "%rdx"
#define REGISTER_RBX "%rbx"
#define REGISTER_RSP "%rsp"
#define REGISTER_RBP "%rbp"
#define REGISTER_RSI "%rsi"
#define REGISTER_RDI "%rdi"
#define REGISTER_R8 "%r8"
#define REGISTER_R9 "%r9"

#define REGISTER_XMM0 "%xmm0"
#define REGISTER_XMM1 "%xmm1"
#define REGISTER_XMM2 "%xmm2"
#define REGISTER_XMM3 "%xmm3"
#define REGISTER_XMM4 "%xmm4"
#define REGISTER_XMM5 "%xmm5"
#define REGISTER_XMM6 "%xmm6"
#define REGISTER_XMM7 "%xmm7"
#define REGISTER_XMM8 "%xmm8"
#define REGISTER_XMM9 "%xmm9"
#define REGISTER_XMM10 "%xmm10"
#define REGISTER_XMM11 "%xmm11"
#define REGISTER_XMM12 "%xmm12"
#define REGISTER_XMM13 "%xmm13"
#define REGISTER_XMM14 "%xmm14"
#define REGISTER_XMM15 "%xmm15"

#define GLOBAL "global"
#define GLOBAL_SIZE 0
#endif