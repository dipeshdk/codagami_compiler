#include "headers/allInclude.h"

int emitAssemblyForQuad(quadruple *quad, int &errCode, int &errStr) {
    switch(quad->opCode) {
    case OP_GOTO:
        asmOpGoto();
        break;
    case OP_ADDI: 
        asmOpAddI();
        break;
    case OP_MULI: 
        break;
    case OP_IFGOTO: 
        break;
    case OP_SUBI: 
        break;
    case OP_ASSIGNMENT: 
        // OP_ASSIN: arg1, result
        // symbolTableNode *arg1 = 
        // if(result is not constant) {
        //     if(arg1 is constant) {
        //         movl   $constant,-result.offset(%rbp)
        //         //movl   $0x5,-0xc(%rbp)
        //     }else {
        //         mov      -result.offset(%rbp), %eax
        //         mov      %eax, -arg1.offset(%rbp)
        //         //mov    -0xc(%rbp),%eax
        //         //mov    %eax,-0x8(%rbp)
        //     }
        // }else {
            //error, result cannot be a constant
        // }
        break;
    case OP_UNARY_MINUS: 
        break;
    case OP_DIVI: 
        break;
    case OP_LEFT_SHIFT: 
        break;
    case OP_RIGHT_SHIFT: 
        break;
    case OP_NOR: 
        break;
    case OP_OR: 
        break;
    case OP_AND: 
        break;
    case OP_LOGICAL_NOT: 
        break;
    case OP_XOR: 
        break;
    case OP_EQ: 
        break;
    case OP_NEQ: 
        break;
    case OP_LEQ: 
        break;
    case OP_GREATER: 
        break;
    case OP_LESS: 
        break;
    case OP_MOD: 
        break;
    case OP_ADDF: 
        break;
    case OP_MULF: 
        break;
    case OP_SUBF: 
        break;
    case OP_DIVF: 
        break;
    case OP_GEQ: 
        break;
    case OP_ANDAND: 
        break;
    case OP_OROR: 
        break;
    case OP_IFNEQGOTO: 
        break;
    case OP_BEGINFUNC: 
        break;
    case OP_ENDFUNC: 
        break;
    case OP_RETURN: 
        break;
    case OP_PUSHPARAM: 
        break;
    case OP_POPPARAM: 
        break;
    case OP_LCALL: 
        break;
    case OP_LABEL: 
        break;
    case OP_ADDR: 
        break;
    case OP_BITWISE_NOT: 
        break;
    default:
        break;
    }
}

void asmOpGoto(){
    
}