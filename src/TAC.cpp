#include "TAC.h"
#include "symbolTable.h"
using namespace std;

int temp_num = 0;
vector<quadruple*> gCode;
struct symbolTable* gTempSymbolMap;

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
    if(retval){
        errCode = retval; 
    }
    return name;
}
