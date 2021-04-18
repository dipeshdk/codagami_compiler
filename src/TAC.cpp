#include "headers/allInclude.h" 

vector<int> makelist(int i){
    return vector<int>{i};
}

vector<int> makelist(){
    return vector<int>(0);
}

vector<int> mergelist(vector<int> &list1,vector<int> &list2){
    list1.insert(list1.begin(), list2.begin(), list2.end());
    return list1;
}

int backpatch(vector<int> &list, int i){
    int sizeOfList = gCode.size();
    for(int index : list){
        if(index > sizeOfList || 
            ((gCode[index]->opCode != OP_GOTO) && 
            gCode[index]->opCode != OP_IFGOTO))
            return NOT_GOTO_IN_BACKPATCH;
        gCode[index]->arg1 = to_string(i);
    }
    return 0;
}

void emit(int opCode, string arg1, string arg2, string result){
    quadruple* quad = new quadruple();
    quad->opCode = opCode;
    quad->arg1 = arg1;
    quad->arg2 = arg2;
    quad->result = result;
    gCode.push_back(quad);
}

int nextQuad(){
    return gCode.size();
}

string generateTemp(int &errCode){
    errCode = 0;
    temp_num++;
    string name = to_string(temp_num)+"temp";
    int retval = insertSymbol(gTempSymbolMap, TEMP_LINE_NO, name);
    if(retval)
        errCode = retval; 
    return name;
}

void setAddr(node* n, string addr) {
	n->addr = addr;
}

string getOpName(int opCode) {
    switch(opCode){
        case OP_GOTO: return "OP_GOTO";
        case OP_ADDI: return "OP_ADDI";
        case OP_MULI: return "OP_MULI";
        case OP_IFGOTO: return "OP_IFGOTO";
        case OP_SUBI: return "OP_SUBI";
        case OP_ASSIGNMENT: return "OP_ASSIGNMENT";
        case OP_UNARY_MINUS: return "OP_UNARY_MINUS";
        case OP_DIVI: return "OP_DIVI";
        case OP_CALL: return "OP_CALL";
        case OP_LEFT_SHIFT: return "OP_LEFT_SHIFT";
        case OP_RIGHT_SHIFT: return "OP_RIGHT_SHIFT";
        case OP_NOR: return "OP_NOR";
        case OP_OR: return "OP_OR";
        case OP_AND: return "OP_AND";
        case OP_NOT: return "OP_NOT";
        case OP_XOR: return "OP_XOR";
        case OP_EQ: return "OP_EQ";
        case OP_NEQ: return "OP_NEQ";
        case OP_LEQ: return "OP_LEQ";
        case OP_GREATER: return "OP_GREATER";
        case OP_LESS: return "OP_LESS";
        case OP_MOD: return "OP_MOD";
        case OP_ADDF: return "OP_ADDF";
        case OP_MULF: return "OP_MULF";
        case OP_SUBF: return "OP_SUBF";
        case OP_DIVF: return "OP_DIVF"; 
    }
    return "INVALID OPCODE";
}

void printCode() {
    cout << "\n==================== Printing Code ==================\n";
    for(auto &quad : gCode) {
        cout <<"result =  "<< quad->result
        <<", arg1 = " << quad->arg1 
        << ", opCode  = " 
        << getOpName(quad->opCode)
        <<", arg2 = " << quad->arg2
        << "\n"; 
    }
    cout << "\n====================================================\n";
}