#include "headers/allInclude.h"
#define NOT_CONSTANT_EXCEPTION 601

int emitAssemblyForQuad(int quadNo, int &errCode, int &errStr) {
    quadruple *quad = gCode[quadNo];
    switch(quad->opCode) {
    case OP_GOTO:
        asmOpGoto();
        break;
    case OP_ADDI: 
        asmOpAddI();
        break;
    case OP_MULI: 
        asmOpMulI();
        break;
    case OP_IFGOTO: 
        asmOpIfGoto();
        break;
    case OP_SUBI: 
        asmOpSubI();
        break;
    case OP_ASSIGNMENT: 
        asmOpAssignment(quad);
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


void printASM() {
    for(pair<string, vector<string>> p : gAsm) {
        string res = p.first;
        res += "    ";
        int n = p.second.size();
        for(int i = 0; i < n; i++) {
            res += p.second[i];
            if(i < (n-1)) res += ", ";
        }
        cout << res << "\n";
    }
}

void emitAsm(string operator, vector<string> operands){
    gASM.push_back({operator, operands});
}

void errorAsm(string str, int errCode){
    string errStr;
    switch(errCode){
        case ASSIGNMENT_TO_CONSTANT_ERROR:
            errStr = "Cannot assign value to a constant.";
    }
    errStr += " ";
    errStr += str;
    cout << "ERROR: " << errStr << endl;
    exit(errCode);
}

string getVariableAddr() {
    
}

void asmOpGoto(){
    
}

void asmOpAddI(){

}

bool isConstant(string s){
    try{
        int x = stoi(s);
        throw NOT_CONSTANT_EXCEPTION;
    }
    catch(int exp){
        if(exp == NOT_CONSTANT_EXCEPTION)   return false;
        else    return true; 
    }
}

void asmOpAssignment(int quadNo){
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
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(!isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    //result is not constant
    // -result.offset(%rbp)
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("movl", {"$"+quad->arg1, resultAddr});
    }else {
        string reg = getReg();
        emitAsm("mov", {getVariableAddr(quad->arg1, st), reg});
        emitAsm("mov", {reg, resultAddr});
    }
}