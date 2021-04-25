#include "headers/allInclude.h"
#define NOT_CONSTANT_EXCEPTION 601
#define NUM_REGISTER 8
#define CONSTANT "__constant__"
using namespace std;

vector<reg*> regVec;
vector< pair<string, vector<string>> > gAsm;
vector<string> regNames({"%rax" , "%rcx" , "%rdx" , "%rbx" , "%rsp" , "%rbp" , "%rsi" , "%rdi"});

void emitAssemblyFrom3AC() {
    initializeRegs();
    for(int quadNo = 0; quadNo < gCode.size(); quadNo++) {
        emitAssemblyForQuad(quadNo);
    }
    printASM();
}


void emitAssemblyForQuad(int quadNo) {
    quadruple *quad = gCode[quadNo];
    switch(quad->opCode) {
    case OP_GOTO:
        // asmOpGoto();
        break;
    case OP_ADDI: 
        // asmOpAddI();
        break;
    case OP_MULI: 
        // asmOpMulI();
        break;
    case OP_IFGOTO: 
        // asmOpIfGoto();
        break;
    case OP_SUBI: 
        // asmOpSubI();
        break;
    case OP_ASSIGNMENT: 
        asmOpAssignment(quadNo);
        break;
    
    // amigo
    case OP_UNARY_MINUS:
        // asmOpUnaryMinus(quadNo);  
        break;
    case OP_DIVI:
        // asmOpDivI(quadNo);  
        break;
    case OP_LEFT_SHIFT: 
        // asmOpLeftShift(quadNo);  
        break;
    case OP_RIGHT_SHIFT: 
        // asmOpRightShift(quadNo);  
        break;
    // amigo's Work end here
    
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

/*  Currently our compiler doesn't support negative numbers,
    it takes negative numbers as UNARY_MINUS abs(number). 
    This is in contrast with what GCC do.
    Thus, our unary minus implementation will depend on this.
    Currently, I am implementing it in a way such that the final
    result of the asm code is same as that of GCC. */

void asmOpUnaryMinus(int quadNo){
    // emit(OP_UNARY_MINUS, cast_expression->addr, EMPTY_STR, newTmp);
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];

    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    
    string resultAddr = getVariableAddr(quad->result, st);
    int regInd = -1;
    string regName = CONSTANT;

    if(isConstant(quad->arg1)) {
        regInd = getReg(quadNo, CONSTANT);
        regName = regVec[regInd]->regName;
        emitAsm("movl", {"$"+quad->arg1, regName});
    }else{
        string argAddr = getVariableAddr(quad->arg1, st);
        regInd = getReg(quadNo, quad->arg1);
        regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr, regName});
    }
    // neg register
    if(regName == CONSTANT){
        errorAsm("Register not assigned properly.", REGISTER_ASSIGNMENT_ERROR);
        return;
    }
    emitAsm("neg", {regName});
    // move the value of this register at resultAddr        
    emitAsm("mov", {regName, resultAddr});
}

void asmOpDivI(int quadNo){

}

void asmOpLeftShift(int quadNo){

}

void asmOpRightShift(int quadNo){

}


void emitAsm(string optr, vector<string> operands){
    gAsm.push_back({optr, operands});
}


void errorAsm(string str, int errCode){
    string errStr;
    switch(errCode){
        case ASSIGNMENT_TO_CONSTANT_ERROR:
            errStr = "Cannot assign value to a constant.";
            break;
        case UNDEFINED_SCOPE_STNODE_ERROR:
            errStr = "Internal Error.";
            break;
        case REGISTER_ASSIGNMENT_ERROR:
            errStr = "Internal Error.";
        default:
            break;
    }
    errStr += " ";
    errStr += str;
    cout << "ERROR: " << errStr << endl;
    exit(errCode);
}


int getOffset(string varName, symbolTable* st){
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    int offset = sym_node->offset;
    offset += sym_node->size;
    return -1*offset;
}


bool isGlobal(string varName, symbolTable* st) {
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    if(sym_node->scope == -1)
        errorAsm("scope of variable not defined", UNDEFINED_SCOPE_STNODE_ERROR);
    return sym_node->scope == GLOBAL_SCOPE_NUM;
}

int getGlobalAddress(string varName, symbolTable* st){
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    // TODO: global offset(starting address of the program) need to be added here to get the absolute address of the variable
    return sym_node->offset;
}


string getVariableAddr(string varName, symbolTable* st) {
    int offset;
    if(isGlobal(varName, st)) {
        //UNSUPPORTED FUNCTION
        error("globals are unsupported", UNSUPPORTED_FUNCTIONALITY);
        //TODO: return absolute addr
        offset = getGlobalAddress(varName, st);
        return to_string(offset);
    }
    offset = getOffset(varName, st);
    return to_string(offset) + "(%rbp)";
}

// void asmOpGoto(){
    
// }

// void asmOpAddI(){

// }

void initializeRegs() {
    regVec = vector<reg*>(NUM_REGISTER);
    for(int i = 0; i < NUM_REGISTER; i++) {
        regVec[i] = new reg();
        regVec[i]->isFree = true;
        regVec[i]->regName = regNames[i];
    }
}

int getReg(int quadNo, string varValue) {
    for(int i = 0; i < NUM_REGISTER; i++) {
        if(regVec[i]->isFree) {
            useReg(i, quadNo, varValue);
            return i;
        }
    }
    int ind = getRegToFree();
    freeRegAndMoveToStack(ind);
    useReg(ind, quadNo, varValue);
    return ind;
}

int getRegToFree(){
    // TODO: returns index of reg to free if all regs are used
    return 0;
}

void freeReg(int regInd) {
    regVec[regInd]->isFree = true;
}

void useReg(int regInd, int quadNo, string varValue) {
    regVec[regInd]->isFree = false;
    regVec[regInd]->quadNo = quadNo;
    regVec[regInd]->varValue = varValue;
}

void freeRegAndMoveToStack(int regInd) {
    //TODO: free a reg by moving its data to a location and then
    if(isConstant(regVec[regInd]->varValue)) return;

    string resultAddr = getVariableAddr(regVec[regInd]->varValue, codeSTVec[regVec[regInd]->quadNo]);
    emitAsm("mov", {regVec[regInd]->regName, resultAddr});
}


void asmOpAssignment(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    //result is not constant
    // -result.offset(%rbp)
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("movl", {"$"+quad->arg1, resultAddr});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr, regName});
        emitAsm("mov", {regName, resultAddr});
        freeReg(regInd);
    }
}