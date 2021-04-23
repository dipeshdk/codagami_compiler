#include "headers/allInclude.h" 

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
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\n\n=============Printing symbol table (scope: " << st->scope << ")====================\n\n";

    for(auto elem : st->symbolTableMap) {
        cout << "\n---------------------------------------\n";
        cout << elem.first << " \n" 
            << "name: " << elem.second->name << " \n"
            << "infoType: " << elem.second->infoType << " \n"
            << "arraySize: " << elem.second->arraySize << " \n"
            << "paramSize: " << elem.second->paramSize << " \n"
            << "isDefined: " << elem.second->isDefined << " \n"
            << "size: " << elem.second->size << " \n"
            << "offset: " << elem.second->offset << " \n";

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
    printf("%s", str.c_str());
    printf("\"size\" : %d,\n", elem->size);
    printf("%s", str.c_str());
    printf("\"offset\" : %d,\n", elem->offset);

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
    // int offset = 0;
    for(int i = 0; i < st->symbolOrder.size(); i++) {
    // for(auto &s: st->symbolOrder){
        // printf("\"%s\", ",s.c_str());
        symbolTableNode *elem = st->symbolTableMap[st->symbolOrder[i]];
        // int size = getNodeSize(elem, st);
        // if(elem->infoType == INFO_TYPE_ARRAY){
        //     size += getTypeSize(elem->declSp->type)*(elem->arraySize);
        // }
        // else if(elem->infoType == INFO_TYPE_FUNC){
        //     size += 8;
        // }
        // else if(elem->infoType == INFO_TYPE_STRUCT){
        //     if(!elem->declSp){
        //         structTableNode* n = st->structMap[elem->declSp->lexeme];
        //         for(auto i: n->paramList){
        //             if(!i->declSp)
        //                 size+= getTypeSize(i->declSp->type);
        //         }
        //     }
            
        // }
        // else if(elem->declSp && elem->declSp->ptrLevel){
        //     size += 8;
        // }
        // else{
        //     size += getTypeSize(elem->declSp->type);
        // }
        
        printf("%s", str.c_str());
        printf("{\n");
        printf("%s", str.c_str());
        printf("\"size\" : %d,\n", elem->size);
        printf("%s", str.c_str());
        printf("\"offset\" : %d,\n", elem->offset);
        printElem(elem, str);
        printf("}");
        if(i < (st->symbolOrder.size()-1)) {
            printf(",");
        }
        printf("\n");
        // offset += size;

    }
    printf("]\n");
    printf("%s", str.c_str());
    printf("}\n");
    // str.pop_back();
    // printStructTable(st->structMap, st->scope);
    for(symbolTable *child : st->childList) {
        printSymbolTableJSON(child, numTab);
    }   

    freopen(fileName.c_str(), "w", stdout);
}

int getNodeSize(symbolTableNode* elem, symbolTable* st){
    int size = 0;
    if(elem->infoType == INFO_TYPE_ARRAY){
        if(elem->declSp->ptrLevel > 0){
            size += 8*(elem->arraySize);
        }
        else size += getTypeSize(elem->declSp->type)*(elem->arraySize);
    }
    else if(elem->infoType == INFO_TYPE_FUNC){
        size += 8;
    }
    else if(elem->infoType == INFO_TYPE_STRUCT){
        if(elem->declSp){
            structTableNode* n = structLookUp(st, elem->declSp->lexeme);
            for(auto i: n->paramList){
                if(i->declSp)
                    if(i->declSp->ptrLevel > 0){
                        size += 8;
                    }
                    else size+= getTypeSize(i->declSp->type);
            }
        }
        
    }
    else if(elem->declSp && elem->declSp->ptrLevel){
        size += 8;
    }
    else{
        size += getTypeSize(elem->declSp->type);
    }
    return size;
}

int getOffsettedSize(int size){
    if(size%4 == 0){
        return size;
    }
    return ((size/4) +1)*4;
}

int getTypeSize(vector<int> &type) {
    if(type.size() != 1) return -CONFLICTING_TYPES;
    switch(type[0]) {
        case TYPE_CHAR: return SIZE_CHAR; 
        case TYPE_VOID: return SIZE_VOID;
        case TYPE_INT: return SIZE_INT;  
        case TYPE_FLOAT: return SIZE_FLOAT;  
    }
    return -CONFLICTING_TYPES;
}


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
        case OP_GEQ: return "OP_GEQ"; 
        case OP_ANDAND : return "OP_ANDAND" ;  
        case OP_OROR : return "OP_OROR" ;     
        case OP_IFNEQGOTO : return "OP_IFNEQGOTO" ; 
        case OP_BEGINFUNC : return "OP_BEGINFUNC" ;
        case OP_ENDFUNC : return "OP_ENDFUNC" ;
        case OP_RETURN : return "OP_RETURN" ;
        case OP_PUSHPARAM : return "OP_PUSHPARAM" ;
        case OP_POPPARAM : return "OP_POPPARAM" ;
        case OP_LCALL : return "OP_LCALL"; 
        case OP_LABEL : return "OP_LABEL"; 


    }
    return "INVALID OPCODE";
}

void printQuad(quadruple* quad, int line) {
    printf("%d.   ", line);
    switch(quad->opCode) {
        case OP_IFGOTO:
            printf("IF %s THEN GOTO %s\n",quad->arg1.c_str(), quad->result.c_str()); break;
        case OP_GOTO:
        case OP_BEGINFUNC:
        case OP_PUSHPARAM:
        case OP_POPPARAM:
            printf("%s %s\n",getOpName(quad->opCode).c_str(), quad->result.c_str()); break;
        case OP_ENDFUNC:
            printf("END_FUNCTION\n"); break;
        case OP_RETURN:
            if(quad->result == BLANK_STR) {
                printf("Return \n");
            }else {
                printf("Return %s\n", quad->result.c_str());
            }
            break;
        case OP_LCALL:
            if(quad->result == BLANK_STR) {
                printf("LCALL _%s\n", quad->arg1.c_str());
            }else {
                printf("%s = LCALL _%s\n", quad->result.c_str(), quad->arg1.c_str());
            }
            break;
        case OP_LABEL: printf("%s:\n", quad->result.c_str()); break;
        case OP_ASSIGNMENT:
            printf("%s = %s\n", quad->result.c_str(), quad->arg1.c_str()); break;
        case OP_IFNEQGOTO:
            printf("IF %s <> %s GOTO %s\n", quad->arg1.c_str(), quad->arg2.c_str(), quad->result.c_str()); break;
        default:
            printf("%s = %s %s %s\n", quad->result.c_str(),  quad->arg1.c_str(), getOpName(quad->opCode).c_str(), quad->arg2.c_str());
    }
}

void printCode() {
    freopen("code.txt", "w", stdout);
    cout << "\n==================== Printing 3AC Code ==================\n";
    int n = gCode.size();
    for(int i = 0; i < n; i++) {
        printQuad(gCode[i], i);
    }
    cout << "\n====================================================\n";
}