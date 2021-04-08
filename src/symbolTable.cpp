#include<bits/stdc++.h>
#include "symbolTable.h"

using namespace std;
int gScope=0;
struct symbolTable* gSymTable;

set< vector<int> > char_type_check;
set< vector<int> > short_type_check;
set< vector<int> > int_type_check;
set< vector<int> > long_type_check;
set< vector<int> > float_type_check;
set< vector<int> > double_type_check;
set< vector<int> > void_type_check;

vector<int> c1 {TYPE_CHAR};
vector<int> c2 {TYPE_SIGNED,TYPE_CHAR};
vector<int> c3 {TYPE_UNSIGNED,TYPE_CHAR};

vector<int> v1 {TYPE_SHORT}; 
vector<int> v2 {TYPE_SHORT,TYPE_INT};
vector<int> v3 {TYPE_SIGNED,TYPE_SHORT,TYPE_INT};
vector<int> v4 {TYPE_SIGNED,TYPE_SHORT};
vector<int> v5 {TYPE_UNSIGNED,TYPE_SHORT,TYPE_INT};
vector<int> v6 {TYPE_UNSIGNED,TYPE_SHORT};

vector<int> i1 {TYPE_INT};
vector<int> i2 {TYPE_SIGNED};
vector<int> i3 {TYPE_SIGNED,TYPE_INT};
vector<int> i4 {TYPE_UNSIGNED};
vector<int> i5 {TYPE_UNSIGNED, TYPE_INT};

vector<int> f1 {TYPE_FLOAT};

vector<int> d1 {TYPE_DOUBLE};
vector<int> d2 {TYPE_LONG, TYPE_DOUBLE};

vector<int> ll1 {TYPE_LONG};
vector<int> ll2 {TYPE_LONG, TYPE_INT};
vector<int> ll3 {TYPE_SIGNED,TYPE_LONG};
vector<int> ll4 {TYPE_SIGNED, TYPE_LONG, TYPE_INT};
vector<int> ll5 {TYPE_UNSIGNED, TYPE_LONG};
vector<int> ll6 {TYPE_UNSIGNED, TYPE_LONG, TYPE_INT};

vector<int> l1 {TYPE_LONG, TYPE_LONG};
vector<int> l2 {TYPE_LONG, TYPE_LONG, TYPE_INT};
vector<int> l3 {TYPE_SIGNED, TYPE_LONG, TYPE_LONG};
vector<int> l4 {TYPE_SIGNED, TYPE_LONG, TYPE_LONG, TYPE_INT};
vector<int> l5 {TYPE_UNSIGNED, TYPE_LONG, TYPE_LONG};
vector<int> l6 {TYPE_UNSIGNED, TYPE_LONG, TYPE_LONG, TYPE_INT};

vector<int> vv1 {TYPE_VOID};


void insert_into_sets(){
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    reverse(v3.begin(), v3.end());
    reverse(v4.begin(), v4.end());
    reverse(v5.begin(), v5.end());
    reverse(c1.begin(), c1.end());
    reverse(c2.begin(), c2.end());
    reverse(c3.begin(), c3.end());
    reverse(d1.begin(), d1.end());
    reverse(d2.begin(), d2.end());
    reverse(f1.begin(), f1.end());
    reverse(i1.begin(), i1.end());
    reverse(i2.begin(), i2.end());
    reverse(i3.begin(), i3.end());
    reverse(i4.begin(), i4.end());
    reverse(i5.begin(), i5.end());
    reverse(ll1.begin(), ll1.end());
    reverse(ll2.begin(), ll2.end());
    reverse(ll3.begin(), ll3.end());
    reverse(ll4.begin(), ll4.end());
    reverse(ll5.begin(), ll5.end());
    reverse(ll6.begin(), ll6.end());
    reverse(l1.begin(), l1.end());
    reverse(l2.begin(), l2.end());
    reverse(l3.begin(), l3.end());
    reverse(l4.begin(), l4.end());
    reverse(l5.begin(), l5.end());
    reverse(l6.begin(), l6.end());

    short_type_check.insert(v1);
    short_type_check.insert(v2);
    short_type_check.insert(v3);
    short_type_check.insert(v4);
    short_type_check.insert(v5);
    short_type_check.insert(v6);

    char_type_check.insert(c1);
    char_type_check.insert(c2);
    char_type_check.insert(c3);

    float_type_check.insert(f1);

    int_type_check.insert(i1);
    int_type_check.insert(i2);
    int_type_check.insert(i3);
    int_type_check.insert(i4);
    int_type_check.insert(i5);

    long_type_check.insert(l1);
    long_type_check.insert(l2);
    long_type_check.insert(l3);
    long_type_check.insert(l4);
    long_type_check.insert(l5);
    long_type_check.insert(l6);

    long_type_check.insert(ll1);
    long_type_check.insert(ll2);
    long_type_check.insert(ll3);
    long_type_check.insert(ll4);
    long_type_check.insert(ll5);
    long_type_check.insert(ll6);

    double_type_check.insert(d1);
    double_type_check.insert(d2);    

    void_type_check.insert(vv1);
}

// grammar.y check if nullptr then it is error.
struct symbolTableNode* lookUp(symbolTable* st, string name) {
    // goes to parent if does not find in st
    //returns node otherwise null
    symbolTable* node = st;
    while(node != nullptr){
        if(node->symbolTableMap.find(name) != node->symbolTableMap.end()){
            return node->symbolTableMap[name];
        }
        node = node->parent;
    }
    return nullptr;
}

int insertSymbol(symbolTable* st, int lineNo, string name){
    if(st->symbolTableMap.find(name) != st->symbolTableMap.end()) {
        cout << "\nsymbol name: " << name << "\n";
        return SYMBOL_ALREADY_EXISTS;
    }
    symbolTableNode* node = new symbolTableNode();
    if(!node) {
        return ALLOCATION_ERROR;
    }
    st->symbolOrder.push_back(name);
    node->name = name;
    node->lineNo = lineNo;
    st->symbolTableMap[name] = node;
    return 0;
}


int addIVal(node* temp, string s) {
    // size_t n = s.length();
    size_t p;
    // int i = stoi(s,&p);
    // if(p == n) {
    //     temp->ival = (int)stod(s, &p);
    //     return TYPE_INT;
    // }
    // long l = stol(s, &p);
    // if(p == n || (p == n-1 && (s[p] == 'l' || s[p] == 'L'))) {
    //     return TYPE_LONG;
    // }
    //TODO: Handle int and long separately
    temp->valType = TYPE_LONG;
    temp->lval = (long)stod(s, &p);
    return TYPE_INT;
}

int addFVal(node* temp, string s) {
    // size_t n = s.length();
    size_t p;
    // int i = stoi(s,&p);
    // if(p == n) {
    //     temp->ival = (int)stod(s, &p);
    //     return TYPE_INT;
    // }
    // long l = stol(s, &p);
    // if(p == n || (p == n-1 && (s[p] == 'l' || s[p] == 'L'))) {
    //     return TYPE_LONG;
    // }
    //TODO: Handle int and long separately
    temp->valType = TYPE_DOUBLE;
    temp->dval = (double)stod(s, &p);
    return TYPE_FLOAT;
    // return TYPE_ERROR;
}


struct symbolTable* addChildSymbolTable(struct symbolTable *parent){
    symbolTable* node = new symbolTable();
    if(!node)
        return nullptr;
    node->scope = gScope++;
    node->parent = parent;
    parent->childList.push_back(node);
    return node;
}

int checkValidType(declSpec* declSp) {
    vector<int> &v = declSp->type;
    bool c1 = short_type_check.find(v) != short_type_check.end();
    bool c2 = long_type_check.find(v) != long_type_check.end();
    bool c3 = int_type_check.find(v) != int_type_check.end();
    bool c4 = float_type_check.find(v) != float_type_check.end(); 
    bool c5 = double_type_check.find(v) != double_type_check.end();
    bool c6 = char_type_check.find(v) != char_type_check.end();
    bool c7 = void_type_check.find(v) != void_type_check.end();
    bool x = c1 | c2 | c3 | c4 | c5 | c6| c7;
    if(x){
        return 0;
    }else{
        return CONFLICTING_TYPES;
    }
}

int compareTypes(declSpec* ds1,  declSpec* ds2){
    if(!ds1 | !ds2)
        return CONFLICTING_TYPES;
    vector<int> v1 = ds1->type;
    vector<int> v2 = ds2->type;
    int pt1 = ds1->ptrLevel;
    int pt2 = ds2->ptrLevel;

    bool c4 = float_type_check.find(v1) != float_type_check.end(); 
    bool c5 = double_type_check.find(v1) != double_type_check.end();
    bool c6 = char_type_check.find(v1) != char_type_check.end();
    bool x1 = c4|c5;

    bool g6 = char_type_check.find(v2) != char_type_check.end();
    bool g4 = float_type_check.find(v2) != float_type_check.end(); 
    bool g5 = double_type_check.find(v2) != double_type_check.end();
    bool x2 = g4|g5;

    // float char* not allowed
    if((x1 && g6 && pt2>0) || (x2 && c6 && pt1>0)){
        return CONFLICTING_TYPES;
    }
    // ds1 string
    if(v1[0] == TYPE_STRING_LITERAL){
        if(pt2 == 0 ) return CONFLICTING_TYPES;
    }
    return 0;
    // string (int, char, float)* allowed
    // string (int,char) not allowed 
}

int check_type_array(vector<int> &v){
    bool c1 = short_type_check.find(v) != short_type_check.end();
    bool c2 = long_type_check.find(v) != long_type_check.end();
    bool c3 = int_type_check.find(v) != int_type_check.end();
    bool c4 = float_type_check.find(v) != float_type_check.end(); 
    bool c5 = double_type_check.find(v) != double_type_check.end();
    bool x = c1 | c2 | c3 ;
    if(x){
        return 0;
    }else if(c4|c5){
        return ARRAY_SIZE_SHOULD_BE_INT;
    }
    else{
        return ARRAY_SIZE_NOT_CONSTANT;
    }
	return 0;
}

int addTypeToDeclSpec(node *temp, vector<int>&v){
    if(!temp || !temp->declSp) {
        return INVALID_ARGS;
    }
    for(int i = 0; i < v.size() ; i++) {
        temp->declSp->type.push_back(v[i]);
    }
    return checkValidType(temp->declSp);
}

int checkValidStorageClass(node *temp) {
    if(temp->declSp->storageClassSpecifier.size() > 1
        || (temp->infoType == INFO_TYPE_FUNC && temp->declSp->storageClassSpecifier.size() > 0 
        && temp->declSp->storageClassSpecifier[0] != TYPE_EXTERN))
        return INVALID_STORAGE_CLASS;
    return 0;
}

int addStorageClassToDeclSpec(node *temp, vector<int>&v){
    if(!temp || !temp->declSp) {
        return INVALID_ARGS;
    }
    for(int i = v.size()-1; i >=0; i--) {
        temp->declSp->storageClassSpecifier.push_back(v[i]);
    }
    return checkValidStorageClass(temp);
}

string getTypeName(int type) {
    switch(type) {
        case TYPE_CHAR: return "CHAR";
        case TYPE_SHORT: return "SHORT";
        case TYPE_INT: return "INT";
        case TYPE_LONG: return "LONG";
        case TYPE_FLOAT: return "FLOAT";
        case TYPE_DOUBLE: return "DOUBLE";
        case TYPE_SIGNED: return "SIGNED";
        case TYPE_UNSIGNED: return "UNSIGNED";
        case TYPE_VOID: return "VOID";
        case TYPE_STRUCT: return "STRUCT";
        case TYPE_UNION: return "UNION";
        case TYPE_ENUM: return "ENUM";
        case TYPE_TYPEDEF: return "TYPEDEF";
        case TYPE_EXTERN: return "EXTERN";
        case TYPE_STATIC: return "STATIC";
        case TYPE_AUTO: return "AUTO";
        case TYPE_REGISTER: return "REGISTER";
    }
    return "INVALID TYPE";
}

string getTypeString(vector<int> type) {
    string s;
    for(int &t : type) {
        s += getTypeName(t);
        s += "_";
    }
    return s;
}

void printDeclSp(declSpec* ds) {
    cout << "   Printing Decl Sp\n";
    if(!ds) {
        cout << "   Decl Sp: NULL\n";
        return;
    }
    cout << "   ptrLevel: " << ds->ptrLevel << " \n"
        << "    lexeme: " <<ds->lexeme << "  \n"
        << "    isConst: " <<ds->isConst << "  \n"
        << "    isVolatile: " <<ds->isVolatile << "  \n";
    cout << "\n     type: \n    ";
    for(int t : ds->type) 
        cout << getTypeName(t) << " ";
    cout << "\n     storageClassSpecifier: \n   ";
    for(int t : ds->storageClassSpecifier) 
       cout << getTypeName(t) << " ";
    cout << "\n";
}

void printToCsvFile(symbolTable *st){
    string fileName = "symbolTableOfScope";
    fileName = fileName.append(to_string(st->scope));
    fileName = fileName.append(".csv");
    fstream file;
    file.open(fileName, ios::app);
    file << "Name, infoType, arraySize, paramSize, isDefined";
    int maxParamListSize = 0;
    for(auto elem: st->symbolTableMap){
        maxParamListSize = elem.second->paramList.size() > maxParamListSize ? elem.second->paramList.size() : maxParamListSize;
    }
    for(int i = 0; i < maxParamListSize;i++){
        file << ", Parameter" << i + 1;
    }
    file << "\n";
    for(auto elem : st->symbolTableMap){
        file << elem.second->name << ", "
            << elem.second->infoType << ", "
            << elem.second->arraySize << ", "
            << elem.second->paramSize << ", "
            << elem.second->isDefined;
        for(param* t : elem.second->paramList) {
            file << ", " << t->paramName;
        }
        file << "\n";
    }
}

void printSymbolTable(symbolTable *st) {
    printToCsvFile(st);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\n\n=============Printing symbol table (scope: " << st->scope << ")====================\n\n";

    for(auto elem : st->symbolTableMap) {
        cout << "\n---------------------------------------\n";
        cout << elem.first << " \n" 
            << "name: " << elem.second->name << " \n"
            << "infoType: " << elem.second->infoType << " \n"
            << "arraySize: " << elem.second->arraySize << " \n"
            << "paramSize: " << elem.second->paramSize << " \n"
            << "isDefined: " << elem.second->isDefined << " \n";

        cout << "declSp: \n";
        printDeclSp(elem.second->declSp);
        cout << "paramList: \n   ";
        for(param* t : elem.second->paramList) {
            cout << "name: " << t->paramName << "\n";
            printDeclSp(t->declSp);
        }

        cout << "\n---------------------------------------\n";
    }
    for(auto &s: st->symbolOrder){
        cout << s << " ";
    }
    cout << endl;
    cout << "\n=================================================\n";
    printStructTable(st->structMap, st->scope);
    for(symbolTable *child : st->childList) {
        printSymbolTable(child);
    }   
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

}

// int getSize(struct symbolTableNode* elem){
//     int size = 0;
//     if(elem->infoType == INFO_TYPE_ARRAY){
//             size += getTypeSize(elem->declSp->type)*(elem->arraySize);
//         }
//         else if(elem->infoType == INFO_TYPE_FUNC){
//             size += 8;
//         }
//         else if(elem->infoType == INFO_TYPE_STRUCT){
//             structTableNode* n = st->structMap[s->declSp->lexeme];
//             for(auto i: n->paramList){
//                 size+= getTypeSize(i->declSp->type);
//             }
//         }
//         else if(elem->declSp && elem->declSp->ptrLevel){
//             size += 8;
//         }
//     else{
//         size += getTypeSize(elem->declSp->type);
//     }
// }


void printElem(symbolTableNode* elem, string str) {
    
    printf("%s", str.c_str());
    printf("\"name\" : \"%s\",\n", elem->name.c_str());
    printf("%s", str.c_str());
    printf("\"infoType\" : %d,\n", elem->infoType);
    printf("%s", str.c_str());
    printf("\"arraySize\" : %d,\n", elem->arraySize);
    printf("%s", str.c_str());
    printf("\"paramSize\" : %d,\n", elem->paramSize);
    printf("%s", str.c_str());
    printf("\"isDefined\" : %d,\n", elem->isDefined);

    declSpec *ds = elem->declSp;
    if(ds) {
        printf("%s", str.c_str());
        printf("\"ptrLevel\" : %d,\n", ds->ptrLevel);
        printf("%s", str.c_str());
        printf("\"lexeme\" : \"%s\",\n", ds->lexeme.c_str());
        printf("%s", str.c_str());
        printf("\"isConst\" : %d,\n", elem->arraySize);
        printf("%s", str.c_str());
        printf("\"isVolatile\" : %d,\n", elem->paramSize);
        printf("%s", str.c_str());
        printf("\"declSpIsDefined\" : %d,\n", elem->isDefined);
        printf("%s", str.c_str());
        printf("\"type\" : \"");
        for(int t : ds->type) 
            printf("%s ",getTypeName(t).c_str());
        printf("\",\n");
        printf("%s", str.c_str());
        printf("\"storageClassSpecifier\" : \"");
        for(int t : ds->storageClassSpecifier) 
            printf("%s ",getTypeName(t).c_str());
        printf("\",\n");
    }
    printf("%s", str.c_str());
    printf("\"paramList\" : \n");
    printf("%s", str.c_str());
    str += "\t";
    printf("[\n");
    int paramListSize = elem->paramList.size();
    int i = 0;
    for(param* t : elem->paramList) {
        printf("%s", str.c_str());
        printf("{\n");
        printf("%s", str.c_str());
        printf("\"name\" : \"%s\"\n", t->paramName.c_str());
        ds = t->declSp;
        if(ds) {
            printf(",\n");
            printf("%s", str.c_str());
            printf("\"ptrLevel\" : %d,\n", ds->ptrLevel);
            printf("%s", str.c_str());
            printf("\"struct lexeme\" : \"%s\",\n", ds->lexeme.c_str() );
            printf("%s", str.c_str());
            printf("\"isConst\" : %d,\n", elem->arraySize);
            printf("%s", str.c_str());
            printf("\"isVolatile\" : %d,\n", elem->paramSize);
            printf("%s", str.c_str());
            printf("\"isDefined\" : %d,\n", elem->isDefined );
            printf("%s", str.c_str());
            printf("\"type\" : \"");
            for(int t : ds->type) 
                printf("%s ",getTypeName(t).c_str());
            printf("\",\n");
            printf("%s", str.c_str());
            printf("\"storageClassSpecifier\" : \"");
            for(int t : ds->storageClassSpecifier) 
                printf("%s ",getTypeName(t).c_str());
            printf("\"\n");
            printf("%s", str.c_str());
            printf("}");
            if(i < (paramListSize-1)) {
                printf(",");
            }
            printf("\n");
            i++;
        }
    }
    printf("%s", str.c_str());
    printf("]\n");
    str.pop_back();
    printf("%s", str.c_str());
}

void printSymbolTableJSON(symbolTable *st, int numTab) {
    stringstream ss;  
    ss << "symbolTable" << st->scope << ".json";
    string fileName;
    ss >> fileName;
    freopen(fileName.c_str(), "w", stdout);
    string str;
    for(int i = 0; i < numTab; i++) {
        str += '\t';
    }
    printf("%s", str.c_str());
    str += "\t";
    printf("{\n");
    printf("%s", str.c_str());
    printf("\"scope\" : %d,\n", st->scope);
    int mapSize = st->symbolTableMap.size();
    int j = 0;
    printf("\"symbolOrder\" : [");
    int offset = 0;
    for(int i = 0; i < st->symbolOrder.size(); i++) {
    // for(auto &s: st->symbolOrder){
        // printf("\"%s\", ",s.c_str());
        symbolTableNode *elem = st->symbolTableMap[st->symbolOrder[i]];
        int size = 0;
        if(elem->infoType == INFO_TYPE_ARRAY){
            size += getTypeSize(elem->declSp->type)*(elem->arraySize);
        }
        else if(elem->infoType == INFO_TYPE_FUNC){
            size += 8;
        }
        else if(elem->infoType == INFO_TYPE_STRUCT){
            if(!elem->declSp){
                structTableNode* n = st->structMap[elem->declSp->lexeme];
                for(auto i: n->paramList){
                    if(!i->declSp)
                        size+= getTypeSize(i->declSp->type);
                }
            }
            
        }
        else if(elem->declSp && elem->declSp->ptrLevel){
            size += 8;
        }
        else{
            size += getTypeSize(elem->declSp->type);
        }
        
        printf("%s", str.c_str());
        printf("{\n");
        printf("%s", str.c_str());
        printf("\"size\" : %d,\n", size);
        printf("%s", str.c_str());
        printf("\"offset\" : %d,\n", offset);
        printElem(elem, str);
        printf("}");
        if(i < (st->symbolOrder.size()-1)) {
            printf(",");
        }
        printf("\n");
        offset += size;

    }
    printf("]\n");
    printf("%s", str.c_str());
    printf("}\n");
    // str.pop_back();
    // printStructTable(st->structMap, st->scope);
    for(symbolTable *child : st->childList) {
        printSymbolTableJSON(child, numTab);
    }   
    // printf("}\n");
}

// int getTypeSize(vector<int> &type) {
//     int size = 0;

//     for(int &t : type) {
//         switch(t) {
//             case TYPE_CHAR: return SIZE_CHAR; break; 
//             case TYPE_SHORT: return SIZE_SHORT; break; 
//             case TYPE_INT: return SIZE_INT; break; 
//             case TYPE_LONG: return SIZE_LONG; break; 
//             case TYPE_FLOAT: return SIZE_FLOAT; break; 
//             case TYPE_DOUBLE: return SIZE_DOUBLE; break;
//             default: break; 
//         }
//     }
//     return size;
// }

int getTypeSize(vector<int> &type) {
    vector<int> &v = type;
    bool c1 = (short_type_check.find(v) != short_type_check.end());
    bool c2 = (long_type_check.find(v) != long_type_check.end());
    bool c3 = (int_type_check.find(v) != int_type_check.end());
    bool c4 = (float_type_check.find(v) != float_type_check.end()); 
    bool c5 = (double_type_check.find(v) != double_type_check.end());
    bool c6 = (char_type_check.find(v) != char_type_check.end());
    bool c7 = (void_type_check.find(v) != void_type_check.end());
    if(c1){
        return SIZE_SHORT;
    }else if(c2){
        return SIZE_LONG;
    }else if(c3){
        return SIZE_INT;
    }else if(c4){
        return SIZE_FLOAT;
    }else if(c5){
        return SIZE_DOUBLE;
    }else if(c6){
        return SIZE_CHAR;
    }else if(c7){
        return SIZE_VOID;
    }
    return 0;
}

// void symbolTableCsvDump(symbolTable *st) {
//     cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
//     cout << "\n\n=============Printing symbol table (scope: " << st->scope << ")====================\n\n";

//     for(auto elem : st->symbolTableMap) {
//         cout << "\n---------------------------------------\n";
//         cout << elem.first << " \n" 
//             << "name: " << elem.second->name << " \n"
//             << "infoType: " << elem.second->infoType << " \n"
//             << "arraySize: " << elem.second->arraySize << " \n"
//             << "paramSize: " << elem.second->paramSize << " \n"
//             << "isDefined: " << elem.second->isDefined << " \n";

//         cout << "declSp: \n";
//         printDeclSp(elem.second->declSp);
//         cout << "paramList: \n   ";
//         for(param* t : elem.second->paramList) {
//             cout << "name: " << t->paramName << "\n";
//             printDeclSp(t->declSp);
//         }

//         cout << "\n---------------------------------------\n";
//     }
//     for(auto &s: st->symbolOrder){
//         cout << s << " ";
//     }
//     cout << endl;
//     cout << "\n=================================================\n";
//     printStructTable(st->structMap, st->scope);
//     for(symbolTable *child : st->childList) {
//         printSymbolTable(child);
//     }   
//     cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

// }

void printStructTable(map<string, struct structTableNode*> &structMap, int scope) {
    cout << "\n\n=============Printing struct table (scope: " << scope << ")====================\n\n";

    for(auto elem : structMap) {
        cout << "\n---------------------------------------\n";
        cout << elem.first << " \n" 
            << "infoType: " << elem.second->infoType << " \n"
            << "lineNo: " << elem.second->lineNo << " \n"
            << "name: " << elem.second->name << " \n";

        cout << "paramList: \n   ";
        for(structParam* t : elem.second->paramList) {
            cout << "name: " << t->name << "\n";
            cout << "bit: " << t->bit << "\n";
            printDeclSp(t->declSp);
        }
        cout << "\n---------------------------------------\n";
    }
    cout << "\n=================================================\n"; 
}

int mergeConstVolatile(node* temp, node* from) {
    if(!temp->declSp) {
        temp->declSp = new declSpec();
    }
    if(from->declSp) {
        temp->declSp->isConst = temp->declSp->isConst || from->declSp->isConst;
        temp->declSp->isVolatile = temp->declSp->isVolatile || from->declSp->isVolatile;
    }
    return 0;
}

int incrementPointerLevel(node* temp, node* from) {
    if (!temp->declSp){
        temp->declSp = new declSpec();
    } 
    if(from && from->declSp && from->declSp->ptrLevel){
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    }
    // else{
    //     temp->declSp->ptrLevel = 0;
    // }
    temp->declSp->ptrLevel++;
    return 0;
}

int copyPtrLevel(node* temp, node* from) {
    if(!temp->declSp) 
        temp->declSp = new declSpec();
    if(from->declSp)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    return 0;
}

int addFunctionSymbol(node* declaration_specifiers, node* declarator) {
    string name = declarator->lexeme;
    // cout << "addFunctionSymbol: name: " << name << " scope " << gSymTable->scope << "\n";
    int retVal = insertSymbol(gSymTable, declarator->lineNo, name);
    if(retVal == SYMBOL_ALREADY_EXISTS) {
        //TODO: Later
    }
    
    if(retVal) {
        //error checks
    }

    symbolTableNode* sym_node = gSymTable->symbolTableMap[name];

    if(!sym_node){
        return ALLOCATION_ERROR;
    }

    sym_node->infoType = INFO_TYPE_FUNC;
    if(declaration_specifiers)
        sym_node->declSp = declaration_specifiers->declSp;
    else{
        declSpec* ds = new declSpec();
        ds->type.push_back(TYPE_INT);
        sym_node->declSp = ds;
    }
    sym_node->paramList = declarator->paramList;
    return 0;
}

declSpec* declSpCopy(declSpec* ds) {
    declSpec* newds = new declSpec();
    for(auto &a : ds->type) {
        newds->type.push_back(a);
    }
    newds->ptrLevel = ds->ptrLevel;
    newds->lexeme = ds->lexeme;
    for(auto &a : ds->storageClassSpecifier) {
        newds->storageClassSpecifier.push_back(a);
    }
    newds->isConst = ds->isConst;
    newds->isVolatile = ds->isVolatile;
    return newds;
}

int removeSymbol(symbolTable* st, string name) {
    if(!st) {
        return INVALID_ARGS;
    }
    auto it = st->symbolTableMap.find(name);
    if(it == st->symbolTableMap.end()) {
        return SYMBOL_NOT_FOUND;
    }
    st->symbolTableMap.erase(it);
    return 0;
}

int getValueFromConstantExpression(node* constant_expression, int &err) {
    err=0;
    int val = 0;
    if(!constant_expression) {
        err = INVALID_ARGS;
        return val;
    }
    switch(constant_expression->valType){
        case TYPE_INT: 
            val = constant_expression->ival;
            break;
        case TYPE_LONG: 
            val = constant_expression->lval;
            break;
        case TYPE_FLOAT:
        case TYPE_DOUBLE:
            err = TYPE_ERROR;
            break;
        default:
            break; 
    }
    return val;
}

structTableNode* structLookUp(symbolTable* st, string name) {
    symbolTable* curr = st;
    while(curr) {
        if(curr->structMap.find(name) != curr->structMap.end()) {
            return curr->structMap[name];
        }
        curr = curr->parent;
    }
    return nullptr;
}

structParam* structureParamLookup(structTableNode* node, string paramName, int& err){
    //returns 0 if struct node has a param named paramName
    err = 0;
    if(!node || !paramName.size()) {
        err = INVALID_ARGS;
        return nullptr;
    }
    
    for(structParam* p : node->paramList) {
        if(p->name == paramName) 
            return p;
    }
    
    return nullptr;
}

int checkVoid(node* root){
    if(!root -> declSp){
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    vector<int>v = (root-> declSp->type);
    bool v1 = void_type_check.find(v) != void_type_check.end(); 
    if(!v1){
        return TYPE_ERROR;
    }
    return 0; 
}

int checkIntLongShort(node* root){
    if(!root -> declSp){
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    int retval = check_type_array(root-> declSp->type);
    if(retval){
        return TYPE_ERROR;
    }
    return 0;
}

int checkFloat(node* root){
    if(!root -> declSp){
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    vector<int>v = (root-> declSp->type);
    bool c1 = float_type_check.find(v) != float_type_check.end(); 
    bool c2 = double_type_check.find(v) != double_type_check.end(); 
    bool x = c1 | c2;
    if(!x){
        return TYPE_ERROR;
    }
    return 0;
}

int checkStringLiteral(node* root){
    if(!root -> declSp){
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    vector<int> v1 = root -> declSp->type;
    if(v1.size()> 0 && v1[0] == TYPE_STRING_LITERAL ){
        return 0;
    }

    return TYPE_ERROR;
}

int checkValidTypeCast(declSpec* from, declSpec* to){
    //return 0 if typecast is valid
    if(!to || !from) {
        return INVALID_ARGS;
    }
    bool toIsFloat = false;
    bool toIsCharStar = false;
    for(int &t : to->type) {
        if(t == TYPE_FLOAT) {
            toIsFloat=1;
        }
        if(t == TYPE_CHAR && to->ptrLevel == 1) {
            toIsCharStar = true;
        }
    }

    bool fromIsFloat = false;
    bool fromIsCharStar = false;

    if(from) {
        for(int &t : from->type) {
            if(t == TYPE_FLOAT) {
                fromIsFloat=1;
            }
            if(t == TYPE_CHAR && from->ptrLevel == 1) {
                fromIsCharStar = true;
            }
        }
    }

    if((fromIsFloat && toIsCharStar) || (fromIsCharStar && toIsFloat)) {
        return 1;
    }

    return 0;
}


int checkPointer(node* root){
    if(!root) return INVALID_ARGS;
    if(!root -> declSp) return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    if(root -> declSp->ptrLevel <= 0) return TYPE_ERROR;
    return 0;
}

int giveTypeCastRank(node* n1, node* n2){
    if(!n1) return INVALID_ARGS;
    if(!n1 -> declSp) return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;

    if(!n2) return INVALID_ARGS;
    if(!n2 -> declSp) return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;


    vector<int> v1 = n1 -> declSp ->type;
    vector<int> v2 = n2 -> declSp ->type;

    // cout << v1[0] << endl;
    
    int f1 =  (float_type_check.find(v1) != float_type_check.end()); 
    int d1 = (double_type_check.find(v1) != double_type_check.end());
    int i1 = (checkIntLongShort(n1) == 0);
    int c1 = (char_type_check.find(v1) != char_type_check.end());
    // cout << f1 << d1 << i1 << c1 << endl;
    int rank1 = ((f1|d1)<<2) + (i1<<1) + (c1);
    int f2 =  (float_type_check.find(v2) != float_type_check.end()); 
    int d2 = (double_type_check.find(v2) != double_type_check.end());
    int i2 = (checkIntLongShort(n2) == 0);
    int c2 = (char_type_check.find(v2) != char_type_check.end());
    int rank2 = ((f2|d2)<<2) + (i2<<1) + (c2);
    string strType = "(TO_";
    // printf("rank1 = %d, rank2 = %d\n", rank1, rank2);
    if(rank1 > rank2){
        strType = strType + getTypeString(n1->declSp->type) + ")";
        n2->declSp->type = n1->declSp->type;
        string s = strType + string(n2->lexeme); 
        strcpy(n2->lexeme, s.c_str());
    }else if(rank1 < rank2){
        strType = strType + getTypeString(n2->declSp->type) + ")";
        n1->declSp->type = n2->declSp->type;
        string s = strType + string(n1->lexeme); 
        strcpy(n1->lexeme, s.c_str());
    }
    return 0;
}
int giveTypeCastRankUnary(node* n1, node* n2){
    if(!n1) return INVALID_ARGS;
    if(!n1 -> declSp) return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;

    if(!n2) return INVALID_ARGS;
    if(!n2 -> declSp) return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;


    vector<int> v1 = n1 -> declSp ->type;
    vector<int> v2 = n2 -> declSp ->type;
    int f1 =  (float_type_check.find(v1) != float_type_check.end()); 
    int d1 = (double_type_check.find(v1) != double_type_check.end());
    int i1 = (checkIntLongShort(n1) == 0);
    int c1 = (char_type_check.find(v1) != char_type_check.end());
    // cout << f1 << d1 << i1 << c1 << endl;
    int rank1 = ((f1|d1)<<2) + (i1<<1) + (c1);
    int f2 =  (float_type_check.find(v2) != float_type_check.end()); 
    int d2 = (double_type_check.find(v2) != double_type_check.end());
    int i2 = (checkIntLongShort(n2) == 0);
    int c2 = (char_type_check.find(v2) != char_type_check.end());
    int rank2 = ((f2|d2)<<2) + (i2<<1) + (c2);
    if(rank1 != rank2){
        string strType = "(TO_";
        strType = strType + getTypeString(n1->declSp->type) + ")";
        // n2->declSp->type = n1->declSp->type;
        string s = strType + string(n2->lexeme); 
        strcpy(n2->lexeme, s.c_str());
    }
    return 0;
}

int implicitTypecastingNotPointerNotStringLiteral(node*n1, node*n2, string& var){
    int retval1 = checkPointer(n1);
    int retval2 = checkPointer(n2);
    if(!retval1){
        var = n1->lexeme;
        return POINTER_ERROR;
    }
    if(!retval2){
        var = n2->lexeme;
        return POINTER_ERROR;
    }
    retval1 = checkStringLiteral(n1);
    retval2 = checkStringLiteral(n2);
    if(!retval1){
        var = n1->lexeme;
        return STRING_LITERAL_ERROR;
    }
    if(!retval2){
        var = n2->lexeme;
        return STRING_LITERAL_ERROR;
    }
    int rank = giveTypeCastRank(n1, n2);
    if(rank){
        var = "typecasting error rank";
        return rank;
    }
    return 0;
}

int implicitTypecastingNotStringLiteral(node*n1, node*n2, string& var){
    int retval1 = checkStringLiteral(n1);
    int retval2 = checkStringLiteral(n2);
    if(!retval1){
        var = n1->lexeme;
        return STRING_LITERAL_ERROR;
    }
    if(!retval2){
        var = n2->lexeme;
        return STRING_LITERAL_ERROR;
    }
    int rank = giveTypeCastRank(n1, n2);
    if(rank){
        var = "typecasting error rank";
        return rank;
    }
    return 0;
}
