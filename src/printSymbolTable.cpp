#include "headers/allInclude.h"

extern int offset;

bool isTempVar(string varName) {
    return isdigit(varName[0]);
}
void printDeclSp(declSpec* ds) {
    cout << "   Printing Decl Sp\n";
    if (!ds) {
        cout << "   Decl Sp: NULL\n";
        return;
    }
    cout << "   ptrLevel: " << ds->ptrLevel << " \n"
         << "    lexeme: " << ds->lexeme << "  \n"
         << "    isConst: " << ds->isConst << "  \n"
         << "    isVolatile: " << ds->isVolatile << "  \n";
    cout << "\n     type: \n    ";
    for (int t : ds->type)
        cout << getTypeName(t) << " ";
    cout << "\n     storageClassSpecifier: \n   ";
    for (int t : ds->storageClassSpecifier)
        cout << getTypeName(t) << " ";
    cout << "\n";
}

void printSymbolTable(symbolTable* st) {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "\n\n=============Printing symbol table (scope: " << st->scope << ")====================\n\n";

    for (auto elem : st->symbolTableMap) {
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
        for (param* t : elem.second->paramList) {
            cout << "name: " << t->paramName << "\n";
            printDeclSp(t->declSp);
        }

        cout << "\n---------------------------------------\n";
    }
    for (auto& s : st->symbolOrder) {
        cout << s << " ";
    };
    cout << "\n=================================================\n";
    printStructTable(st->structMap, st->scope);
    for (symbolTable* child : st->childList) {
        printSymbolTable(child);
    }
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

void printElem(symbolTableNode* elem, string str, int printTemps) {
    // printf("%s", str.c_str());
    if (printTemps == 0) {
        if (isTempVar(elem->name)) {
            return;
        }
    }
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

    declSpec* ds = elem->declSp;
    if (ds) {
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
        for (int t : ds->type)
            printf("%s ", getTypeName(t).c_str());
        printf("\",\n");
        printf("%s", str.c_str());
        printf("\"storageClassSpecifier\" : \"");
        for (int t : ds->storageClassSpecifier)
            printf("%s ", getTypeName(t).c_str());
        printf("\",\n");
    }
    printf("%s", str.c_str());
    printf("\"paramList\" : [\n");
    // printf("%s", str.c_str());
    str += "\t";
    // printf("[\n");
    int paramListSize = elem->paramList.size();
    int i = 0;
    for (param* t : elem->paramList) {
        printf("%s", str.c_str());
        printf("{\n");
        printf("%s", str.c_str());
        printf("\"name\" : \"%s\",\n", t->paramName.c_str());
        printf("%s", str.c_str());
        printf("\"infoType\" : \"%d\"", t->infoType);
        ds = t->declSp;
        if (ds) {
            // printf("%s", str.c_str());
            printf(",\n");
            printf("%s", str.c_str());
            printf("\"ptrLevel\" : %d,\n", ds->ptrLevel);
            printf("%s", str.c_str());
            printf("\"struct lexeme\" : \"%s\",\n", ds->lexeme.c_str());
            printf("%s", str.c_str());
            printf("\"isConst\" : %d,\n", elem->arraySize);
            printf("%s", str.c_str());
            printf("\"isVolatile\" : %d,\n", elem->paramSize);
            printf("%s", str.c_str());
            printf("\"isDefined\" : %d,\n", elem->isDefined);
            printf("%s", str.c_str());
            printf("\"type\" : \"");
            for (int t : ds->type)
                printf("%s ", getTypeName(t).c_str());
            printf("\",\n");
            printf("%s", str.c_str());
            printf("\"storageClassSpecifier\" : \"");
            for (int t : ds->storageClassSpecifier)
                printf("%s ", getTypeName(t).c_str());
            printf("\"\n");
            printf("%s", str.c_str());
            printf("}");
            if (i < (paramListSize - 1)) {
                printf(",");
            }
            printf("\n");
            i++;
        } else {
            printf("\n");
        }
    }
    printf("%s", str.c_str() + 1);
    printf("]\n");
    str.pop_back();
    printf("%s", str.c_str());
}

void printSymbolTableJSON(string filePrefix, symbolTable* st, int numTab, int printTemps) {
    stringstream ss;
    ss << filePrefix << st->scope << ".json";
    string fileName;
    ss >> fileName;
    FILE* jsonFile = freopen(fileName.c_str(), "w", stdout);
    string str;
    for (int i = 0; i < numTab; i++) {
        str += '\t';
    }
    printf("%s", str.c_str());
    str += "\t";
    printf("{\n");
    printf("%s", str.c_str());
    printf("\"scope\" : %d,\n", st->scope);
    int mapSize = st->symbolTableMap.size();
    int j = 0;
    printf("%s", str.c_str());
    printf("\"symbolOrder\" : [");
    // int offset = 0;
    for (int i = 0; i < st->symbolOrder.size(); i++) {
        symbolTableNode* elem = st->symbolTableMap[st->symbolOrder[i]];
        printf("%s", str.c_str());
        printf("{\n");
        printf("%s", str.c_str());
        printElem(elem, str, printTemps);
        printf("}");
        if (i < (st->symbolOrder.size() - 1)) {
            printf(",");
        }
        printf("\n");
    }
    printf("%s", str.c_str());
    printf("]\n");
    printf("%s", str.c_str() + 1);
    printf("}\n");
    fclose(jsonFile);
    for (symbolTable* child : st->childList) {
        printSymbolTableJSON(filePrefix, child, numTab, printTemps);
    }
}

int getNodeSize(symbolTableNode* elem, symbolTable* st) {
    int size = 0;
    if (elem->declSp->ptrLevel >= 1)
        size = 8;
    else if (elem->infoType == INFO_TYPE_ARRAY) {
        size += 8;
    } else if (elem->infoType == INFO_TYPE_STRUCT || (elem->declSp && elem->declSp->type.size() > 0 && elem->declSp->type[0] == TYPE_STRUCT)) {
        if (elem->declSp) {
            structTableNode* n = structLookUp(st, elem->declSp->lexeme);
            for (auto i : n->paramList) {
                if (i->declSp)
                    if (i->declSp->ptrLevel > 0) {
                        size += 8;
                    } else
                        size += getTypeSize(i->declSp->type);
            }
        }
        size = getOffsettedSize(size);
    } else if (elem->infoType == INFO_TYPE_FUNC) {
        size += 8;
    } else if (elem->declSp && elem->declSp->ptrLevel) {
        size += 8;
    } else {
        size += getTypeSize(elem->declSp->type);
    }
    return size;
}

int getArraySize(symbolTableNode* sym_node, symbolTable* st) {
    if (sym_node->infoType == INFO_TYPE_ARRAY) {
        if (sym_node->declSp->ptrLevel > 1) {
            return 8 * (sym_node->arraySize);
        } else if (sym_node->declSp->type[0] == TYPE_STRUCT) {
            string structName = sym_node->declSp->lexeme;
            structTableNode* structNode = structLookUp(st, structName);
            if (structNode == nullptr) {
                error(structName, STRUCT_NOT_DECLARED);
                return -STRUCT_NOT_DECLARED;
            }
            int size = getStructSize(structNode);
            if (size < 0) {
                error(structName + " size error", DEFAULT_ERROR);
            }
            return size * (sym_node->arraySize);
        } else
            return getTypeSize(sym_node->declSp->type) * (sym_node->arraySize);
    }
    return 0;
}

int getOffsettedSize(int size) {
    if (size % 8 == 0) {
        return size;
    }
    return ((size / 8) + 1) * 8;
}

int getTypeSize(vector<int>& type) {
    if (type.size() != 1)
        return -CONFLICTING_TYPES;
    switch (type[0]) {
    // case TYPE_CHAR: return SIZE_CHAR;
    // case TYPE_VOID: return SIZE_VOID;
    // case TYPE_INT: return SIZE_INT;
    // case TYPE_FLOAT: return SIZE_FLOAT;
    default:
        return 8;
    }
    return -CONFLICTING_TYPES;
}

void addTempDetails(string name, symbolTable* symtab, node* node) {
    symbolTableNode* sym_node = lookUp(symtab, name);
    int size = 8;
    if (node->declSp->ptrLevel == 0) {
        symbolTableNode* new_node = new symbolTableNode();
        new_node->declSp = declSpCopy(node->declSp);
        new_node->infoType = node->infoType;
        size = getNodeSize(new_node, symtab);
    }
    sym_node->declSp = declSpCopy(node->declSp);
    sym_node->size = size;
    sym_node->offset = offset;
    offset += size;
    return;
}

void printStructTable(map<string, struct structTableNode*>& structMap, int scope) {
    cout << "\n\n=============Printing struct table (scope: " << scope << ")====================\n\n";

    for (auto elem : structMap) {
        cout << "\n---------------------------------------\n";
        cout << elem.first << " \n"
             << "infoType: " << elem.second->infoType << " \n"
             << "lineNo: " << elem.second->lineNo << " \n"
             << "name: " << elem.second->name << " \n";

        cout << "paramList: \n   ";
        for (structParam* t : elem.second->paramList) {
            cout << "name: " << t->name << "\n";
            cout << "bit: " << t->bit << "\n";
            printDeclSp(t->declSp);
        }
        cout << "\n---------------------------------------\n";
    }
    cout << "\n=================================================\n";
}

string getOpName(int opCode) {
    switch (opCode) {
    case OP_GOTO:
        return "GOTO";
    case OP_ADDI:
        return "ADDI";
    case OP_MULI:
        return "MULI";
    case OP_IFGOTO:
        return "IFGOTO";
    case OP_SUBI:
        return "SUBI";
    case OP_ASSIGNMENT:
        return "ASSIGNMENT";
    case OP_ASSIGNMENTF:
        return "ASSIGNMENTF";
    case OP_UNARY_MINUS:
        return "UNARY_MINUS";
    case OP_UNARY_MINUSF:
        return "UNARY_MINUSF";
    case OP_DIVI:
        return "DIVI";
    case OP_CALL:
        return "CALL";
    case OP_LEFT_SHIFT:
        return "LEFT_SHIFT";
    case OP_RIGHT_SHIFT:
        return "RIGHT_SHIFT";
    case OP_OR:
        return "OR";
    case OP_AND:
        return "AND";
    case OP_XOR:
        return "XOR";
    case OP_EQ:
        return "EQ";
    case OP_NEQ:
        return "NEQ";
    case OP_LEQ:
        return "LEQ";
    case OP_GREATER:
        return "GREATER";
    case OP_LESS:
        return "LESS";
    case OP_EQF:
        return "EQF";
    case OP_NEQF:
        return "NEQF";
    case OP_LEQF:
        return "LEQF";
    case OP_GREATERF:
        return "GREATERF";
    case OP_LESSF:
        return "LESSF";
    case OP_MOD:
        return "MOD";
    case OP_ADDF:
        return "ADDF";
    case OP_MULF:
        return "MULF";
    case OP_SUBF:
        return "SUBF";
    case OP_DIVF:
        return "DIVF";
    case OP_GEQ:
        return "GEQ";
    case OP_GEQF:
        return "GEQF";
    case OP_ANDAND:
        return "ANDAND";
    case OP_OROR:
        return "OROR";
    case OP_IFNEQGOTO:
        return "IFNEQGOTO";
    case OP_BEGINFUNC:
        return "BEGINFUNC";
    case OP_ENDFUNC:
        return "ENDFUNC";
    case OP_RETURN:
        return "RETURN";
    case OP_RETURNF:
        return "RETURNF";
    case OP_PUSHPARAM:
        return "PUSHPARAM";
    case OP_POPPARAM:
        return "POPPARAM";
    case OP_LCALL:
        return "LCALL";
    case OP_LABEL:
        return "LABEL";
    case OP_BITWISE_NOT:
        return "BITWISE_NOT";
    case OP_LOGICAL_NOT:
        return "LOGICAL_NOT";
    case OP_ADDR:
        return "ADDR";
    case OP_MOV:
        return "MOV";
    case OP_DUMMYPUSH:
        return "DUMMYPUSH";
    }
    return "INVALID OPCODE";
}

void printQuad(quadruple* quad, int line) {
    printf("%d.   ", line);
    switch (quad->opCode) {
    case OP_IFGOTO:
        printf("    IF %s THEN GOTO %s\n", quad->arg1.c_str(), quad->result.c_str());
        break;
    case OP_GOTO:
    case OP_BEGINFUNC:
    case OP_PUSHPARAM:
    case OP_POPPARAM:
        printf("    %s %s\n", getOpName(quad->opCode).c_str(), quad->result.c_str());
        break;
    case OP_ENDFUNC:
        printf("    END_FUNCTION\n\n");
        break;
    case OP_RETURNF:
        if (quad->result == EMPTY_STR) {
            printf("    ReturnF \n");
        } else {
            printf("    ReturnF %s\n", quad->result.c_str());
        }
        break;
    case OP_RETURN:
        if (quad->result == EMPTY_STR) {
            printf("    Return \n");
        } else {
            printf("    Return %s\n", quad->result.c_str());
        }
        break;
    case OP_LCALL:
        if (quad->result == EMPTY_STR) {
            printf("    LCALL %s\n", quad->arg1.c_str());
        } else {
            printf("    %s = LCALL %s\n", quad->result.c_str(), quad->arg1.c_str());
        }
        break;
    case OP_LABEL:
        printf("%s:\n", quad->result.c_str());
        break;
    case OP_ASSIGNMENT:
        printf("    %s = %s\n", quad->result.c_str(), quad->arg1.c_str());
        break;
    case OP_ASSIGNMENTF:
        printf("    %s = %s\n", quad->result.c_str(), quad->arg1.c_str());
        break;
    case OP_IFNEQGOTO:
        printf("    IF %s <> %s GOTO %s\n", quad->arg1.c_str(), quad->arg2.c_str(), quad->result.c_str());
        break;
    case OP_UNARY_MINUS:
    case OP_UNARY_MINUSF:
    case OP_BITWISE_NOT:
    case OP_LOGICAL_NOT:
    case OP_ADDR:
        printf("    %s = %s %s\n", quad->result.c_str(), getOpName(quad->opCode).c_str(), quad->arg1.c_str());
        break;
    case OP_MOV:
        printf("    MOV %s -> %s\n", quad->result.c_str(), quad->arg1.c_str());
        break;
    case OP_MOVF:
        printf("    MOVF %s -> %s\n", quad->result.c_str(), quad->arg1.c_str());
        break;
    case OP_SUBI:
        printf("    %s = %s %s %s\n", quad->result.c_str(), quad->arg2.c_str(), getOpName(quad->opCode).c_str(), quad->arg1.c_str());
        break;
    case OP_DUMMYPUSH:
        printf("    DUMMY_PUSH\n");
        break;
    default:
        printf("    %s = %s %s %s\n", quad->result.c_str(), quad->arg1.c_str(), getOpName(quad->opCode).c_str(), quad->arg2.c_str());
    }
}

void printCode(char* filename) {
    freopen(filename, "w", stdout);
    int n = gCode.size();
    for (int i = 0; i < n; i++) {
        printQuad(gCode[i], i);
    }
}

void printASMText() {
    cout << "\n.text\n  .global main\n"
         << endl;
    // int lineNo = 0;
    for (pair<string, vector<string>> p : gAsm) {
        string res = p.first;
        res += "    ";
        int n = p.second.size();
        for (int i = 0; i < n; i++) {
            res += p.second[i];
            if (i < (n - 1))
                res += ", ";
        }
        cout << "  " << res << "\n";
    }
    cout << endl;
}
