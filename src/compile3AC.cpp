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
    case OP_UNARY_MINUS:
        // dipesh 
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
        asmOpMod(quadNo);
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
        asmOpGeq(quadNo);
        break;
    case OP_ANDAND: 
        asmOpAndAnd(quadNo);
        break;
    case OP_OROR: 
        asmOpOrOr(quadNo);
        break;
    case OP_IFNEQGOTO: 
        asmOpIfNeqGoto(quadNo);
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
    
    if(isConstant(quad->result)){
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    }
    
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

void asmOpMod(int quadNo){
//    8:	8b 45 f8             	mov    -0x8(%rbp),%eax (Move arg1)
//    b:	99                   	cltd   
//    c:	f7 7d fc             	idivl  -0x4(%rbp) (arg2)
//    f:	89 55 f8             	mov    %edx,-0x8(%rbp) (result)
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("mov", {"$"+quad->arg1, "%eax"});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        // int regInd = getReg(quadNo, quad->arg1);
        // string regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr, "%eax"});
        // emitAsm("mov", {regName, resultAddr});
        // freeReg(regInd);
    }
    emitAsm("cltd", {});
    if(isConstant(quad->arg2)) {
        emitAsm("idiv", {"$"+quad->arg2});
    }else {
        string argAddr = getVariableAddr(quad->arg2, st);
        // int regInd = getReg(quadNo, quad->arg1);
        // string regName = regVec[regInd]->regName;
        emitAsm("idiv", {argAddr});
        // emitAsm("mov", {regName, resultAddr});
        // freeReg(regInd);
    }
    emitAsm("mov", {"%edx", resultAddr});
    return;
}
void asmOpGeq(int quadNo){
//    8:	8b 45 f4             	mov    -0xc(%rbp),%eax
//    b:	3b 45 f8             	cmp    -0x8(%rbp),%eax
//    e:	0f 9d c0             	setge  %al
//   11:	0f b6 c0             	movzbl %al,%eax
//   14:	89 45 fc             	mov    %eax,-0x4(%rbp)
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("mov", {"$"+quad->arg1, "%eax"});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("mov", {argAddr, "%eax"});
    }
    if(isConstant(quad->arg2)) {
        emitAsm("cmp", {"$"+quad->arg2, "%eax"});
    }else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {argAddr, "%eax"});
    }
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    emitAsm("setge", {regName});
    emitAsm("movz", {regName, "%eax"});
    emitAsm("mov", {"%eax", resultAddr});
    freeReg(regInd);
    return;
}
void asmOpAndAnd(int quadNo){
// Possible optimization
//    8:	83 7d f4 00          	cmpl   $0x0,-0xc(%rbp)
//    c:	74 0d                	je     1b <main+0x1b>
//    e:	83 7d f8 00          	cmpl   $0x0,-0x8(%rbp)
//   12:	74 07                	je     1b <main+0x1b>
//   14:	b8 01 00 00 00       	mov    $0x1,%eax
//   19:	eb 05                	jmp    20 <main+0x20>
//   1b:	b8 00 00 00 00       	mov    $0x0,%eax
//   20:	89 45 fc             	mov    %eax,-0x4(%rbp)
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("cmp", {"$0", "$"+quad->arg1});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("je", {to_string(gAsm.size()+5)}); // Jump to mov 0x0
    if(isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0", "$"+quad->arg2});
    }else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("je", {to_string(gAsm.size()+3)}); // Jump to mov 0x0
    emitAsm("mov", {"$1", "%eax"});
    emitAsm("jmp", {to_string(gAsm.size()+2)});
    emitAsm("$0", {"%eax"});
    emitAsm("mov", {"%eax", resultAddr});
    return;
}
void asmOpOrOr(int quadNo){
//    8:	83 7d f4 00          	cmpl   $0x0,-0xc(%rbp)
//    c:	75 06                	jne    14 <main+0x14>
//    e:	83 7d f8 00          	cmpl   $0x0,-0x8(%rbp)
//   12:	74 07                	je     1b <main+0x1b>
//   14:	b8 01 00 00 00       	mov    $0x1,%eax
//   19:	eb 05                	jmp    20 <main+0x20>
//   1b:	b8 00 00 00 00       	mov    $0x0,%eax
//   20:	89 45 fc             	mov    %eax,-0x4(%rbp)
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number
    
    string resultAddr = getVariableAddr(quad->result, st);
    if(isConstant(quad->arg1)) {
        emitAsm("cmp", {"$0", "$"+quad->arg1});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("jne", {to_string(gAsm.size()+3)}); // Jump to mov 0x0
    if(isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0", "$"+quad->arg2});
    }else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("je", {to_string(gAsm.size()+3)}); // Jump to mov 0x0
    emitAsm("mov", {"$1", "%eax"});
    emitAsm("jmp", {to_string(gAsm.size()+2)});
    emitAsm("$0", {"%eax"});
    emitAsm("mov", {"%eax", resultAddr});
    return;
}
void asmOpIfNeqGoto(int quadNo){
//         switch(a){
//    8:	83 7d f8 01          	cmpl   $0x1,-0x8(%rbp)
//    c:	74 08                	je     16 <main+0x16>
//    e:	83 7d f8 02          	cmpl   $0x2,-0x8(%rbp)
//   12:	74 0b                	je     1f <main+0x1f>
//   14:	eb 11                	jmp    27 <main+0x27>
//         case 1: {
//             b = 1;
//   16:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
//             break;
//   1d:	eb 08                	jmp    27 <main+0x27>
//         }
//         case 2: {
//             b = 2;
//   1f:	c7 45 fc 02 00 00 00 	movl   $0x2,-0x4(%rbp)
//             break;
//   26:	90                   	nop
//         }
//     }
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    if(isConstant(quad->arg1)) {
        if(isConstant(quad->arg2)){
            emitAsm("cmp", {"$"+quad->arg1, "$"+quad->arg2});    
        }
        else{
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("cmp", {"$"+quad->arg1, argAddr});
        }
    }
    else if(isConstant(quad->arg2)){
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$"+quad->arg2, argAddr});
    }
    else {
        string argAddr1 = getVariableAddr(quad->arg1, st);
        string argAddr2 = getVariableAddr(quad->arg2, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr1, regName});
        emitAsm("cmp", {regName, argAddr2});
        freeReg(regInd);
    }
    emitAsm("jne", {"GOTO_ADDR"}); // Address to be added

    return;
}