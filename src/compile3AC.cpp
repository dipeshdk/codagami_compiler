#include "headers/allInclude.h"
#define NOT_CONSTANT_EXCEPTION 601
#define NUM_REGISTER 10
#define CONSTANT "__constant__"
#define EAX_REGISTER_INDEX 3
#define EDX_REGISTER_INDEX 4
#define GLOBAL "global"
#define GLOBAL_SIZE 0

using namespace std;

vector<reg*> regVec;
vector< pair<string, vector<string>> > gAsm;
vector<string> gArgRegs({"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"});
vector<string> regNames({"%r10", "%r11", "%rcx", "%rax" , "%rdx" , "%rbx" , "%rsp" , "%rbp" , "%rsi" , "%rdi"});
stack<string> funcNameStack;
stack<int> funcSizeStack;
vector<pair<string, string>> globalDataPair;
int gQuadNo; // holding the current quadNo
stack<int> ptrAssignedRegs;


string stripTypeCastUtil(string name) {
  size_t pos = name.find(")");
  if (pos == string::npos)
    return name;
  return name.substr(pos+2);
}

void stripTypeCastFromQuads() {
  for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
    quadruple *quad = gCode[quadNo];
    stripTypeCastUtil(quad->result);
    stripTypeCastUtil(quad->arg1);
    stripTypeCastUtil(quad->arg2);
  }
}

void emitAssemblyFrom3AC(string asmOutputFile) {
  funcNameStack.push(GLOBAL);
  initializeRegs();
  // stripTypeCastFromQuads();
  vector<int> gotoLabels;
  for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
    int op = gCode[quadNo]->opCode;
    if((op == OP_GOTO) || (op == OP_IFGOTO) || (op == OP_IFNEQGOTO)){
        string num = gCode[quadNo]->result;
        if(!isConstant(num)){
            errorAsm(num, GOTO_ADDR_NOT_CONST);
        }
        gotoLabels.push_back(stoi(num));
    }
  }
  
  sort(gotoLabels.begin(), gotoLabels.end());
  int curr = 0;
  for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
      gQuadNo=quadNo;
      if((curr < gotoLabels.size()) && (gotoLabels[curr] == quadNo)){
         asmLabel(quadNo);
         while(gotoLabels[curr] == quadNo){
             curr++;
         }
      }
      emitAssemblyForQuad(quadNo);
      while(!ptrAssignedRegs.empty()) {
          freeReg(ptrAssignedRegs.top());
          ptrAssignedRegs.pop();
      }
  }
  setUpGlobalData();
  printAsm(asmOutputFile);
}

void setUpGlobalData() {
  //TODO: setup globalDataPair<dataName, dataVal>
  return;
}

void printAsm(string asmOutputFile) {
  freopen(asmOutputFile.c_str(), "w", stdout);
  printASMData();
  printASMText();
}

void printASMData() {
    cout << "\n.data" << endl;
    cout << "   format:  .asciz \"%ld\\n\"" << endl;
    // int lineNo = 0;
    for(pair<string, string> p : globalDataPair) {
        cout << p.first << ":   " << p.second << "\n";  
    }
    cout <<  endl;
}

void emitAssemblyForQuad(int quadNo) {
    quadruple *quad = gCode[quadNo];
    switch(quad->opCode) {
    case OP_GOTO:
        asmOpGoto(quadNo);
        break;
    case OP_ADDI: 
        asmOpAddI(quadNo);
        break;
    case OP_MULI: 
        asmOpMulI(quadNo);
        break;
    case OP_IFGOTO: 
        asmOpIfGoto(quadNo);
        break;
    case OP_SUBI: 
        asmOpSubI(quadNo);
        break;
    case OP_ASSIGNMENT: 
        asmOpAssignment(quadNo);
        break;
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
        asmOpEq(quadNo);
        break;
    case OP_NEQ: 
        asmOpNeq(quadNo);
        break;
    case OP_LEQ: 
        asmOpLeq(quadNo);
        break;
    case OP_GREATER: 
        asmOpGreater(quadNo);
        break;
    case OP_LESS: 
        asmOpLess(quadNo);
        break;
    case OP_MOD: 
        asmOpMod(quadNo);
        break;
    /* case OP_ADDF: 
        break;
    case OP_MULF: 
        break;
    case OP_SUBF: 
        break;
    case OP_DIVF: 
        break; */
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
        asmOpBeginFunc(quadNo);
        break;
    case OP_ENDFUNC: 
        asmOpEndFunc(quadNo);
        break;
    case OP_RETURN:
      asmOpReturn(quadNo);
      break;
    case OP_PUSHPARAM:
      asmOpPushparam(quadNo);
      break;
    case OP_POPPARAM:
      asmOpPopparam(quadNo);
      break;
    case OP_LCALL:
        amsOpLCall(quadNo); 
        break;
    case OP_LABEL: 
        asmOpLabel(quadNo);
        break;
    case OP_ADDR: 
        amsOpAddr(quadNo);
        break;
    /* case OP_BITWISE_NOT:
        break; */
    case OP_MOV:
      asmOPMoveFuncParam(quadNo);
      break;
    default:
      break;
  }
}

void amsOpAddr(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];

    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

    if(isConstant(quad->arg1))
        errorAsm(quad->arg1, ASSIGNMENT_TO_CONSTANT_ERROR);
    
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string resultAddr = getVariableAddr(quad->result, st);
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("leaq", {argAddr, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
}

void asmOpLabel(int quadNo) {
  string label = "\n";
  label        = label + gCode[quadNo]->result + ":";
  emitAsm(label, {});
  string funcName = gCode[quadNo]->result;
  funcNameStack.push(funcName);
}

void asmLabel(int labelno){
    string label = "\nlabel$"+to_string(labelno)+":";
    emitAsm(label, {});
}
void asmOpReturn(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    int eaxInd = EAX_REGISTER_INDEX;
    string eaxName = regVec[EAX_REGISTER_INDEX]->regName;
    
    if(quad->result != EMPTY_STR){
        freeRegAndMoveToStack(eaxInd);
        regVec[eaxInd]->isFree = false;
        if(!isConstant(quad->result)){
            string argAddr = getVariableAddr(quad->result, st);
            emitAsm("movq", {argAddr, eaxName});
        }else{
            emitAsm("movq", {"$"+hexString(quad->result), eaxName});
        }
    }
}

void asmOpEndFunc(int quadNo){
    emitAsm("addq", {"$"+hexString(to_string(funcSizeStack.top())), "%rsp"});
    emitAsm("popq", {"%rbp"});
    emitAsm("retq", {});
    funcNameStack.pop();
    funcSizeStack.pop();
}

void amsOpLCall(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    //mov    %eax,-0x4(%rbp)
    if(isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    if(quad->arg1 == "printf"){
        emitAsm("lea", {"format(%rip)", "%rdi"});
        emitAsm("xor", {"%rax", "%rax"});
    }
    emitAsm("callq", {quad->arg1});
    if(quad->result != EMPTY_STR){
        string resultAddr = getVariableAddr(quad->result, st);
        emitAsm("movq", {"%rax", resultAddr});
    }
}

void emitFuncStart() {
    emitAsm("endbr64", {});
    emitAsm("pushq", {"%rbp"});
    emitAsm("movq", {"%rsp", "%rbp"});
}

void asmOPMoveFuncParam(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    
    string regName = quad->arg1;
    string valToMove = quad->result;
    if(find(gArgRegs.begin(), gArgRegs.end(), regName) == gArgRegs.end()){
        errorAsm("", REGISTER_ASSIGNMENT_ERROR);
    }
    
    if(isConstant(valToMove)) {
        emitAsm("movq", {"$"+hexString(valToMove), regName});
    }else {
        string argAddr = getVariableAddr(valToMove, st);
        emitAsm("movq", {argAddr, regName});
    }
}

void asmJump(int quadNo, string op){
    quadruple *quad = gCode[quadNo];
    string result = quad->result;
    string label = "label$"+result;
    emitAsm(op, {label});
}



void asmOpPopparam(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    string resultAddr = quad->result;
    
    if(!isConstant(resultAddr)){
        errorAsm("", POPPARAM_ARG_NOT_CONSTANT);
    }
    emitAsm("addq", {"$"+hexString(quad->result), "%rsp"});
}

void asmOpBeginFunc(int quadNo) {
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

  if(!isConstant(quad->result))
      errorAsm(quad->result, BEGIN_FUNC_ARG_NOT_CONSTANT_ERROR);
  if(funcNameStack.empty() || funcNameStack.top() == GLOBAL)
      errorAsm("",CALL_TO_GLOBAL_ERROR);

  int funcSize = getNumberFromConstAddr(quad->result);
  funcSizeStack.push(funcSize);
  //TODO: funcNameStack is the the stack containing active function names, starting with global
  symbolTableNode* funcNode = lookUp(st, funcNameStack.top());
  if(!funcNode){
      error(funcNameStack.top(), SYMBOL_NOT_FOUND);
  }
  if(funcNode->infoType != INFO_TYPE_FUNC)
      error(funcNameStack.top(), TYPE_ERROR);

  //emit start
  emitFuncStart();
  
  //sub stack pointer
  emitAsm("subq", {"$"+hexString(quad->result), "%rsp"});

  //move first 6 arguments from register to stack
  vector<struct param*> paramList = funcNode->paramList;
  int numParams = paramList.size();
  for(int i = 0; i < min(6, numParams); i++) {
      string argAddr = getVariableAddr(paramList[i]->paramName, st);
      emitAsm("movq", {gArgRegs[i], argAddr});
  }
  return;
}

void asmOpPushparam(int quadNo) {
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

      string resultAddr = quad->result;

    if(isConstant(resultAddr)){
        emitAsm("pushq", {"$"+hexString(resultAddr)});
    }
    else{
        string argAddr = getVariableAddr(resultAddr,st);
        emitAsm("movq", {argAddr, "%rax"});
        emitAsm("pushq", {"%rax"});
  }
}

/*  Currently our compiler doesn't support negative numbers,
	it takes negative numbers as UNARY_MINUS abs(number).
	This is in contrast with what GCC do.
	Thus, our unary minus implementation will depend on this.
	Currently, I am implementing it in a way such that the final
	result of the asm code is same as that of GCC. */

void asmOpUnaryOperator(string op, int quadNo) {
  // emit(OP_UNARY_MINUS, cast_expression->addr, EMPTY_STR, newTmp);
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

  if (isConstant(quad->result))
    errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

  string resultAddr = getVariableAddr(quad->result, st);
  int regInd = -1;
  string regName = CONSTANT;

  if(isConstant(quad->arg1)) {
      regInd = getReg(quadNo, CONSTANT);
      regName = regVec[regInd]->regName;
      emitAsm("movq", {"$"+quad->arg1, regName});
  }else{
      string argAddr = getVariableAddr(quad->arg1, st);
      regInd = getReg(quadNo, quad->arg1);
      regName = regVec[regInd]->regName;
      emitAsm("movq", {argAddr, regName});
  }
  // neg register
  if(regName == CONSTANT){
      errorAsm("Register not assigned properly.", REGISTER_ASSIGNMENT_ERROR);
      return;
  }
  emitAsm(op, {regName});
  // move the value of this register at resultAddr        
  emitAsm("movq", {regName, resultAddr});
  freeReg(regInd);
}

void asmOpUnaryMinus(int quadNo) {
  asmOpUnaryOperator("neg", quadNo);
}

void asmOpUnaryLogicalNot(int quadNo){
    quadruple *quad = gCode[quadNo];
    symbolTable *st = codeSTVec[quadNo];
    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    string argString = quad->arg1;
    if(isConstant(argString)){
        string result = evaluate("logicalNot", argString, "");  //incomp
        emitAsm("movq", {resultAddr});
    }else{
        string argAddr = getVariableAddr(argString, st);
        emitAsm("cmpl", {"$0x0", argAddr});
        emitAsm("sete", {"%al"});
        emitAsm("movzbl", {"%al", regNames[EAX_REGISTER_INDEX]});
        emitAsm("movq", {regNames[EAX_REGISTER_INDEX], resultAddr});
    }
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
    emitAsm("movq", {"$0x0", regVec[EDX_REGISTER_INDEX]->regName});

    // free rax and use it
    freeRegAndMoveToStack(EAX_REGISTER_INDEX); 
    regVec[EAX_REGISTER_INDEX]->isFree = false;
    // mov arg1 to eax
    string arg1Addr;
    string reg1Name = regVec[EAX_REGISTER_INDEX]->regName;
    
    if(isConst1){
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movq", {arg1Addr, reg1Name});
    }else{
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
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
        emitAsm("movq", {arg2Addr, reg2Name});
        emitAsm("idivq", {reg2Name});
    }else{
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("idivq", {arg2Addr});
    }
    
    // mov eax to result
    emitAsm("movq", {reg1Name,resultAddr});
    freeReg(EAX_REGISTER_INDEX);
    freeReg(EDX_REGISTER_INDEX);
    if(isConst2 && reg2Ind != -1){
        freeReg(reg2Ind);
    }
}

void asmOpLeftShift(int quadNo) {
  swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
  emitAsmForBinaryOperator("sal", quadNo);
}

void asmOpRightShift(int quadNo) {
  swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
  emitAsmForBinaryOperator("sar", quadNo);
}

void emitAsm(string optr, vector<string> operands) {
  gAsm.push_back({optr, operands});
}

void errorAsm(string str, int errCode) {
  string errStr;
  switch (errCode) {
    case ASSIGNMENT_TO_CONSTANT_ERROR:
      errStr = "Cannot assign value to a constant.";
      break;
    case UNDEFINED_SCOPE_STNODE_ERROR:
      errStr = "Internal Error. UNDEFINED_SCOPE_STNODE_ERROR";
      break;
    case REGISTER_ASSIGNMENT_ERROR:
      errStr = "Internal Error. REGISTER_ASSIGNMENT_ERROR";
      break;
    case POPPARAM_ARG_NOT_CONSTANT:
      errStr = "Popparam arg should be constant";
      break;
    case BEGIN_FUNC_ARG_NOT_CONSTANT_ERROR:
      errStr = "Beginfunc arg should be constant";
      break;
    case CALL_TO_GLOBAL_ERROR:
      errStr = "Internal Error. Calling global";
      break;
    case GOTO_ADDR_NOT_CONST:
      errStr = "Internal Error: Goto address should be integer";
      break;
    case DEREFERENCING_CONSTANT_ERROR:
      errStr = "Derefrencing a constant not allowed.";
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
    if(isPointer(varName)) 
        varName = stripPointer(varName);
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    int offset = sym_node->offset;
    offset += getOffsettedSize(sym_node->size);
    return -1*offset;
}


bool isGlobal(string varName, symbolTable* st) {
    if(isPointer(varName)) 
        varName = stripPointer(varName);
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    if(sym_node->scope == -1)
        errorAsm("scope of variable not defined", UNDEFINED_SCOPE_STNODE_ERROR);
    return sym_node->scope == GLOBAL_SCOPE_NUM;
}

int getGlobalAddress(string varName, symbolTable* st){
    if(isPointer(varName)) 
        varName = stripPointer(varName);
    symbolTableNode* sym_node = lookUp(st, varName);
    if(sym_node == nullptr){
        error(varName, SYMBOL_NOT_FOUND);
    }
    // TODO: global offset(starting address of the program) need to be added here to get the absolute address of the variable
    return sym_node->offset;
}

bool isPointer(string name) {
    int n = name.size();
    if(n <= 3) return false;
    if(name[0]=='*' && name[1] == '(' && name[n-1]==')') return true;
    
    return false;
}

string getOffsetStr(int offset){
     string offsetStr="";
    if(offset < 0) 
        offsetStr = "-";
    
    offset = abs(offset);
    offsetStr = offsetStr + hexString(to_string(offset));
    return offsetStr + "(%rbp)";
}

string stripPointer(string name) {
    int n = name.length();
    string varName = name.substr(2, n-3);
    return varName;
}

string getVariableAddr(string varName, symbolTable* st) {
    int offset;
    string offsetStr;
    if(isGlobal(varName, st)) {
        //UNSUPPORTED FUNCTION
        error("globals are unsupported", UNSUPPORTED_FUNCTIONALITY);
        //TODO: return absolute addr
        offset = getGlobalAddress(varName, st);
        return to_string(offset);
    }
    if(isPointer(varName)) {
        string name = stripPointer(varName);
        if(isConstant(name))
            errorAsm(name,DEREFERENCING_CONSTANT_ERROR);
        offset = getOffset(name, st);
        offsetStr=getOffsetStr(offset);
        int regInd = getReg(gQuadNo, name); //TODO: Free this reg
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {offsetStr, regName});
        ptrAssignedRegs.push(regInd);
        return "(" + regName + ")";
    }   
    offset = getOffset(varName, st);
    offsetStr=getOffsetStr(offset);
    return offsetStr;
}

void initializeRegs() {
  regVec = vector<reg *>(NUM_REGISTER);
  for (int i = 0; i < NUM_REGISTER; i++) {
    regVec[i]          = new reg();
    regVec[i]->isFree  = true;
    regVec[i]->regName = regNames[i];
  }
}

int getReg(int quadNo, string varValue) {
  for (int i = 0; i < NUM_REGISTER; i++) {
    if (regVec[i]->isFree) {
      useReg(i, quadNo, varValue);
      return i;
    }
  }
  int ind = getRegToFree();
  freeRegAndMoveToStack(ind);
  useReg(ind, quadNo, varValue);
  return ind;
}

int getRegToFree() {
  // TODO: returns index of reg to free if all regs are used
  return 0;
}

void freeReg(int regInd) {
  regVec[regInd]->isFree = true;
}

void useReg(int regInd, int quadNo, string varValue) {
  regVec[regInd]->isFree   = false;
  regVec[regInd]->quadNo   = quadNo;
  regVec[regInd]->varValue = varValue;
}

void freeRegAndMoveToStack(int regInd) {
  //TODO: free a reg by moving its data to a location and then
  if (isConstant(regVec[regInd]->varValue)) return;

    string resultAddr = getVariableAddr(regVec[regInd]->varValue, codeSTVec[regVec[regInd]->quadNo]);
    emitAsm("movq", {regVec[regInd]->regName, resultAddr});
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
        emitAsm("movq", {"$"+hexString(quad->arg1), resultAddr});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {argAddr, regName});
        emitAsm("movq", {regName, resultAddr});
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
        emitAsm("movq", {"$"+quad->arg1, "%rax"});
    }else {
        string argAddr = getVariableAddr(quad->arg1, st);
        // int regInd = getReg(quadNo, quad->arg1);
        // string regName = regVec[regInd]->regName;
        emitAsm("movq", {argAddr, "%rax"});
        // emitAsm("mov", {regName, resultAddr});
        // freeReg(regInd);
    }
    emitAsm("cltd", {});
    if(isConstant(quad->arg2)) {
        emitAsm("idivq", {"$"+quad->arg2});
    }else {
        string argAddr = getVariableAddr(quad->arg2, st);
        // int regInd = getReg(quadNo, quad->arg1);
        // string regName = regVec[regInd]->regName;
        emitAsm("idivq", {argAddr});
        // emitAsm("mov", {regName, resultAddr});
        // freeReg(regInd);
    }
    emitAsm("movq", {"%rdx", resultAddr});
    return;
}



string evaluate(string op, string arg1, string arg2) {
    if(op == "addq") {
        int result = getNumberFromConstAddr(arg1) + getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "imulq") {
        int result = getNumberFromConstAddr(arg1) * getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if(op == "subq"){
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


void asmOpComp(int quadNo, string asm_comp) {
  //    8:	8b 45 f4             	mov    -0xc(%rbp),%eax
  //    b:	3b 45 f8             	cmp    -0x8(%rbp),%eax
  //    e:	0f 9d c0             	setge  %al
  //   11:	0f b6 c0             	movzbl %al,%eax
  //   14:	89 45 fc             	mov    %eax,-0x4(%rbp)
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

  if (isConstant(quad->result))
    errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);  //does not print line number

  string resultAddr = getVariableAddr(quad->result, st);
  if (isConstant(quad->arg1)) {
    emitAsm("movq", {"$" + hexString(quad->arg1), "%rax"});
  } else {
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("movq", {argAddr, "%rax"});
  }
  if (isConstant(quad->arg2)) {
    emitAsm("cmp", {"$" + hexString(quad->arg2), "%rax"});
  } else {
    string argAddr = getVariableAddr(quad->arg2, st);
    emitAsm("cmp", {argAddr, "%rax"});
  }
  int regInd     = getReg(quadNo, quad->arg1);
  string regName = regVec[regInd]->regName;
  emitAsm(asm_comp, {regName});
  emitAsm("movzbl", {regName, "%rax"});
  emitAsm("movq", {"%rax", resultAddr});
  freeReg(regInd);
  return;
}

void asmOpGeq(int quad) {
  asmOpComp(quad, "setge");
}

void asmOpLeq(int quad) {
  asmOpComp(quad, "setle");
}

void asmOpGreater(int quad) {
  asmOpComp(quad, "setg");
}

void asmOpLess(int quad) {
  asmOpComp(quad, "setl");
}

void asmOpEq(int quad) {
  asmOpComp(quad, "sete");
}

void asmOpNeq(int quad) {
  asmOpComp(quad, "setne");
}

void asmOpAndAnd(int quadNo) {
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

  if (isConstant(quad->result))
    errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);  //does not print line number

  string resultAddr = getVariableAddr(quad->result, st);
  if (isConstant(quad->arg1)) {
    emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg1)});
  } else {
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("cmp", {"$0x0", argAddr});
  }
  emitAsm("je", {"1f"});  // Jump to mov 0x0
  if (isConstant(quad->arg2)) {
    emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg2)});
  } else {
    string argAddr = getVariableAddr(quad->arg2, st);
    emitAsm("cmp", {"$0x0", argAddr});
  }
  emitAsm("je", {"1f"});  // Jump to mov 0x0
  emitAsm("movq", {"$0x1", "%rax"});
  emitAsm("jmp", {"2f"});
  emitAsm("\n1:", {});
  emitAsm("movq", {"$0x0", "%rax"});
  emitAsm("\n2:", {});
  emitAsm("movq", {"%rax", resultAddr});
  return;
}

void asmOpOrOr(int quadNo) {
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

  if (isConstant(quad->result))
    errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);  //does not print line number

  string resultAddr = getVariableAddr(quad->result, st);
  if (isConstant(quad->arg1)) {
    emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg1)});
  } else {
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("cmp", {"$0x0", argAddr});
  }
  emitAsm("jne", {"1f"});  // Jump to mov 0x0
  if (isConstant(quad->arg2)) {
    emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg2)});
  } else {
    string argAddr = getVariableAddr(quad->arg2, st);
    emitAsm("cmp", {"$0x0", argAddr});
  }
  emitAsm("je", {"2f"});  // Jump to mov 0x0
  emitAsm("\n1:", {});
  emitAsm("movq", {"$0x1", "%rax"});
  emitAsm("jmp", {"3f"});
  emitAsm("\n2:", {});
  emitAsm("movq", {"$0x0", "%rax"});
  emitAsm("\n3:", {});
  emitAsm("movq", {"%rax", resultAddr});
  return;
}

void asmOpGoto(int quadNo) {
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

  if (!isConstant(quad->result)) {
    errorAsm(quad->result, GOTO_ADDR_NOT_CONST);
  }
  asmJump(quadNo, "jmp");
}

void asmOpIfGoto(int quadNo) {
  quadruple *quad = gCode[quadNo];
  symbolTable *st = codeSTVec[quadNo];

  if (isConstant(quad->arg1)) {
    emitAsm("cmpl", {"$0x0", "$" + hexString(quad->arg1)});
  } else {
    string argAddr1 = getVariableAddr(quad->arg1, st);
    int regInd      = getReg(quadNo, quad->arg1);
    string regName  = regVec[regInd]->regName;
    emitAsm("mov", {argAddr1, regName});
    emitAsm("cmp", {"$0x0", regName});
    freeReg(regInd);
  }
  asmJump(quadNo, "jne");
    // Address to be added
}

void asmOpIfNeqGoto(int quadNo) {
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

  if (isConstant(quad->arg1)) {
    if (isConstant(quad->arg2)) {
      emitAsm("cmp", {"$" + hexString(quad->arg1), "$" + hexString(quad->arg2)});
    } else {
      string argAddr = getVariableAddr(quad->arg2, st);
      emitAsm("cmp", {"$" + hexString(quad->arg1), argAddr});
    }
  } else if (isConstant(quad->arg2)) {
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("cmp", {"$" + hexString(quad->arg2), argAddr});
  } else {
    string argAddr1 = getVariableAddr(quad->arg1, st);
    string argAddr2 = getVariableAddr(quad->arg2, st);
    int regInd      = getReg(quadNo, quad->arg1);
    string regName  = regVec[regInd]->regName;
    emitAsm("movq", {argAddr1, regName});
    emitAsm("cmp", {regName, argAddr2});
    freeReg(regInd);
  }
  asmJump(quadNo, "jne"); // Address to be added

  return;
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
            emitAsm("movq", {"$"+eval, resultAddr});
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
        emitAsm("movq", {arg1Addr, reg1Name});
    }else{
        reg1Ind = getReg(quadNo, quad->arg1);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
    }
    
    if(isConst2){
        reg2Ind = getReg(quadNo, CONSTANT);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movq", {arg2Addr, reg2Name});
    }else{
        reg2Ind = getReg(quadNo, quad->arg2);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("movq", {arg2Addr, reg2Name});
    }
    emitAsm(op, {reg1Name, reg2Name});
    //Assuming result in reg2
    emitAsm("movq", {reg2Name,resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
    return;
}

void asmOpLogicalOr(int quadNo) {
  emitAsmForBinaryOperator("or", quadNo);
}

void asmOpLogicalAnd(int quadNo) {
  emitAsmForBinaryOperator("and", quadNo);
}

void asmOpLogicalXor(int quadNo) {
  emitAsmForBinaryOperator("xor", quadNo);
}

void asmOpAddI(int quadNo) {
    emitAsmForBinaryOperator("addq", quadNo);
}

void asmOpMulI(int quadNo) {
    emitAsmForBinaryOperator("imulq", quadNo);
}

void asmOpSubI(int quadNo) {
  swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
  emitAsmForBinaryOperator("subq", quadNo);
}

void asmOpCompareEqual(int quadNo) {
  emitAsmForBinaryOperator("cmp", quadNo);
}
