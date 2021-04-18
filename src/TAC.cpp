#include "TAC.h"
using namespace std;

int temp_num = 0;

vector<quadruple*> gCode;
map<string, struct symbol*> gTempSymbolMap;

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
        if(index > sizeOfList || ((gCode[index]->opCode != GOTO) && gCode[index]->opCode != IFGOTO)){
            return -1;
        }
        gCode[index]->arg1 = to_string(i);
    }
    return 0;
}
void emit(int opCode, string arg1, string arg2, string result){
    quadruple* quad = new quadruple();
    quad->opCode = opCode;
    quad->arg1 = arg1;
    quad->arg2 = arg1;
    quad->result = result;
    gCode.push_back(quad);
}

int nextQuad(){
    return gCode.size();
}

string generateTemp(){
    temp_num++;
    return to_string(temp_num)+"temp";
}

int main(){

    return 0;
}