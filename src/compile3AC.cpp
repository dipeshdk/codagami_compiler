#include "headers/allInclude.h"
#define NOT_CONSTANT_EXCEPTION 601
#define NUM_REGISTER 8
#define CONSTANT "__constant__"
#define EAX_REGISTER_INDEX 0
#define EDX_REGISTER_INDEX 2

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
        asmOpAddI(quadNo);
        break;
    case OP_MULI: 
        asmOpMulI(quadNo);
        break;
    case OP_IFGOTO: 
        // asmOpIfGoto();
        break;
    case OP_SUBI: 
        asmOpSubI(quadNo);
        break;
    case OP_ASSIGNMENT: 
        asmOpAssignment(quadNo);
        break;
    
    // amigo
    case OP_UNARY_MINUS:
        asmOpUnaryMinus(quadNo);  
        break;
    case OP_DIVI:
        asmOpDivI(quadNo);  
        break;
    case OP_LEFT_SHIFT: 
        asmOpLeftShift(quadNo);  
        break;
    case OP_RIGHT_SHIFT: 
        asmOpRightShift(quadNo);  
        break;
    // amigo's Work end here

    case OP_OR: 
        asmOpLogicalOr(quadNo);
        break;
    case OP_AND: 
        asmOpLogicalAnd(quadNo);
        break;
    case OP_LOGICAL_NOT: 
        asmOpUnaryLogicalNot(quadNo);
        break;
    case OP_XOR: 
        asmOpLogicalXor(quadNo);
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

void asmOpUnaryOperator(string op, int quadNo){
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
    emitAsm(op, {regName});
    // move the value of this register at resultAddr        
    emitAsm("mov", {regName, resultAddr});
    freeReg(regInd);
}

void asmOpUnaryMinus(int quadNo){
    asmOpUnaryOperator("neg", quadNo);
}

void asmOpUnaryLogicalNot(int quadNo){
    asmOpUnaryOperator("not", quadNo);
}

void asmOpDivI(int quadNo){   
    /*  Refer http://www.godevtool.com/TestbugHelp/UseofIDIV.htm#:~:text=The%20IDIV%20instruction%20takes%20only,the%20dividend%20and%20the%20divisor. 
        The above website tell us all the different version of this command of which I(amigo) have used only 1 standard form. */ 
    
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); 
    
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);
    
    // free rdx and use it and set it to zero
    freeRegAndMoveToStack(EDX_REGISTER_INDEX); 
    regVec[EDX_REGISTER_INDEX]->isFree = false;
    emitAsm("movl", {"$0x0", regVec[EDX_REGISTER_INDEX]->regName});

    // free rax and use it
    freeRegAndMoveToStack(EAX_REGISTER_INDEX); 
    regVec[EAX_REGISTER_INDEX]->isFree = false;
    // mov arg1 to eax
    string arg1Addr;
    string reg1Name = regVec[EAX_REGISTER_INDEX]->regName;
    
    if(isConst1){
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movl", {arg1Addr, reg1Name});
    }else{
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("mov", {arg1Addr, reg1Name});
    }
    
    // cltd
    emitAsm("cltd", {});
    
    // idivl arg2
    string arg2Addr;
    int reg2Ind = -1;
    if(isConst2){
        reg2Ind = getReg(quadNo, CONSTANT);
        string reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movl", {arg2Addr, reg2Name});
        emitAsm("idiv", {reg2Name});
    }else{
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("idiv", {arg2Addr});
    }
    
    // mov eax to result
    emitAsm("mov", {reg1Name,resultAddr});
    freeReg(EAX_REGISTER_INDEX);
    freeReg(EDX_REGISTER_INDEX);
    if(isConst2 && reg2Ind != -1){
        freeReg(reg2Ind);
    }
}

void asmOpLeftShift(int quadNo){
    swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
    emitAsmForBinaryOperator("sal", quadNo);
}

void asmOpRightShift(int quadNo){
    swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
    emitAsmForBinaryOperator("sar", quadNo);
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
    string offsetStr="";
    if(offset < 0) 
        offsetStr = "-";
    
    offset = abs(offset);
    offsetStr = offsetStr + hexString(to_string(offset));
    return offsetStr + "(%rbp)";
}

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
        emitAsm("movl", {"$"+hexString(quad->arg1), resultAddr});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr, regName});
        emitAsm("mov", {regName, resultAddr});
        freeReg(regInd);
    }
}


string evaluate(string op, string arg1, string arg2) {
    if(op == "add") {
        int result = getNumberFromConstAddr(arg1) + getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "imul") {
        int result = getNumberFromConstAddr(arg1) * getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "sub"){
        int result = getNumberFromConstAddr(arg1) - getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "xor"){
        int result = getNumberFromConstAddr(arg1) ^ getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "or"){
        int result = getNumberFromConstAddr(arg1) | getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "and"){
        int result = getNumberFromConstAddr(arg1) & getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "sal"){
        int result = getNumberFromConstAddr(arg2) << getNumberFromConstAddr(arg1);
        return hexString(to_string(result));
    }
    if(op == "sar"){
        int result = getNumberFromConstAddr(arg2) >> getNumberFromConstAddr(arg1);
        return hexString(to_string(result));
    }
    return EMPTY_STR;
}


void emitAsmForBinaryOperator(string op, int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); 
    
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);

    if(isConst1 && isConst2) {
        //evaluate and movl
        string eval = evaluate(op, quad->arg1, quad->arg2);
        if(eval != EMPTY_STR){
            emitAsm("movl", {"$"+eval, resultAddr});
            return;
        }
    }

    string arg1Addr;
    string arg2Addr;
    int reg1Ind = -1;
    int reg2Ind = -1;
    string reg1Name, reg2Name;
    if(isConst1){
        reg1Ind = getReg(quadNo, CONSTANT);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movl", {arg1Addr, reg1Name});
    }else{
        reg1Ind = getReg(quadNo, quad->arg1);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("mov", {arg1Addr, reg1Name});
    }
    
    if(isConst2){
        reg2Ind = getReg(quadNo, CONSTANT);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movl", {arg2Addr, reg2Name});
    }else{
        reg2Ind = getReg(quadNo, quad->arg2);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("mov", {arg2Addr, reg2Name});
    }
    emitAsm(op, {reg1Name, reg2Name});
    //Assuming result in reg2
    emitAsm("mov", {reg2Name,resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
}


void asmOpLogicalOr(int quadNo){
    emitAsmForBinaryOperator("or", quadNo);
}


void asmOpLogicalAnd(int quadNo){
    emitAsmForBinaryOperator("and", quadNo);
}


void asmOpLogicalXor(int quadNo){
    emitAsmForBinaryOperator("xor", quadNo);
}


void asmOpAddI(int quadNo) {
    emitAsmForBinaryOperator("add", quadNo);
}


void asmOpMulI(int quadNo) {
    emitAsmForBinaryOperator("imul", quadNo);
}

void asmOpSubI(int quadNo) {
    emitAsmForBinaryOperator("sub", quadNo);
}

void asmOpCompareEqual(int quadNo){
    emitAsmForBinaryOperator("cmp", quadNo);
}

