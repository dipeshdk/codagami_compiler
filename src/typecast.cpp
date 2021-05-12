#include "headers/allInclude.h"

int checkValidType(vector<int>& v) {
    if (v.size() != 1 || validTypes.find(v[0]) == validTypes.end())
        return CONFLICTING_TYPES;
    return 0;
}

bool checkTypeWrapperWithStruct(declSpec* ds1, declSpec* ds2) {
    bool c1 = (ds1->type[0] == TYPE_STRUCT && ds1->lexeme == ds2->lexeme);
    bool c2 = checkType(ds1, ds2->type[0], ds2->ptrLevel);
    return (c1 && c2);
}

bool checkType(declSpec* ds, int typeName, int ptrLevel) {
    if (checkValidType(ds->type) || ds->type[0] != typeName || ds->ptrLevel != ptrLevel)
        return false;
    return true;
}

int canTypecast(declSpec* to_ds, declSpec* from_ds) {
    if (!to_ds || !from_ds)
        return CONFLICTING_TYPES;

    int rank1 = getTypeRank(to_ds->type);
    int rank2 = getTypeRank(from_ds->type);
    //struct to any other not allowed
    /* 
      struct to int : not allowed
      struct to int* : not allowed
      struct* to int* : allowed
    */
    if ((rank1 == RANK_TYPE_STRUCT && rank2 != RANK_TYPE_STRUCT) || (rank1 != RANK_TYPE_STRUCT && rank2 == RANK_TYPE_STRUCT)) {
        if (to_ds->ptrLevel == 0 && from_ds->ptrLevel == 0) {
            setErrorParams(errCode, TYPE_ERROR, errStr, "cannot type cast");
            return TYPE_ERROR;
        }
        if (rank2 == RANK_TYPE_STRUCT && from_ds->ptrLevel == 0 && to_ds->ptrLevel > 0) {
            setErrorParams(errCode, TYPE_ERROR, errStr, "cannot type cast structs");
            return TYPE_ERROR;
        }
    }
    //struct-1 to struct-2 not allowed
    /* 
      struct1 to struct2 : not allowed
      struct1* to struct2 : not allowed
      struct1* to struct2* : allowed
    */
    if (rank1 == RANK_TYPE_STRUCT && rank2 == RANK_TYPE_STRUCT) {
        int ptr1 = to_ds->ptrLevel;
        int ptr2 = from_ds->ptrLevel;
        if (to_ds->lexeme != from_ds->lexeme) {
            if (ptr1 + ptr2 < 2) {
                setErrorParams(errCode, TYPE_ERROR, errStr, "cannot type cast structs");
                return TYPE_ERROR;
            }
        }
        if (ptr1 == 0 && ptr2 > 0 || ptr2 == 0 && ptr1 > 0) {
            setErrorParams(errCode, TYPE_ERROR, errStr, "different ptr levels of structs");
            return TYPE_ERROR;
        }
    }

    // float to char* not allowed, string literal can be typcasted only to char *
    if ((checkType(to_ds, TYPE_FLOAT, 0) && checkType(from_ds, TYPE_CHAR, 1)) || (checkType(from_ds, TYPE_FLOAT, 0) && checkType(to_ds, TYPE_CHAR, 1)) || (checkType(to_ds, TYPE_STRING_LITERAL, 0) && !checkType(from_ds, TYPE_CHAR, 1)) || (checkType(from_ds, TYPE_STRING_LITERAL, 0) && !checkType(to_ds, TYPE_CHAR, 1)))
        return CONFLICTING_TYPES;
    return 0;
}

bool areDifferentTypes(declSpec* to_ds, declSpec* from_ds, int& errCode, string& errStr) {
    int rank1 = getTypeRank(to_ds->type);
    int rank2 = getTypeRank(from_ds->type);
    if (rank1 < 0) {
        setErrorParams(errCode, rank1, errStr, "cannot type cast");
        return false;
    }
    if (rank2 < 0) {
        setErrorParams(errCode, rank2, errStr, "cannot type cast");
        return false;
    }
    return ((rank1 != rank2) || (from_ds->ptrLevel != to_ds->ptrLevel));
}

bool typeCastRequired(declSpec* to_ds, declSpec* from_ds, int& errCode, string& errStr) {
    int retval = canTypecast(to_ds, from_ds);
    if (retval) {
        setErrorParams(errCode, retval, errStr, "cannot type cast");
        return false;
    }
    return areDifferentTypes(to_ds, from_ds, errCode, errStr);
}

void checkTypeArrayWithTypecast(node* idNode, int& errCode, string& errStr) {
    errCode = 0;
    if (!idNode->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, "checkTypeArrayWithTypecast");
        return;
    }

    if (checkValidType(idNode->declSp->type)) {
        setErrorParams(errCode, TYPE_ERROR, errStr, "Array index should be integer or char");
        return;
    }

    if (checkType(idNode->declSp, TYPE_CHAR, 0)) {
        //typecast to int
        idNode->declSp->type = vector<int>({TYPE_INT});
        typeCastLexemeWithEmit(idNode, idNode->declSp);
        return;
    } else if (!checkType(idNode->declSp, TYPE_INT, 0)) {
        setErrorParams(errCode, TYPE_ERROR, errStr, "Array index should be integer or char");
        return;
    }
    return;
}

string getTypeName(int type) {
    switch (type) {
    case TYPE_CHAR:
        return "CHAR";
    case TYPE_INT:
        return "INT";
    case TYPE_FLOAT:
        return "FLOAT";
    case TYPE_VOID:
        return "VOID";
    case TYPE_STRUCT:
        return "STRUCT";
    case TYPE_STRING_LITERAL:
        return "STRING_LITERAL";
    }
    return "INVALID TYPE";
}

string getTypeString(vector<int> type) {
    string s;
    for (int& t : type) {
        s += getTypeName(t);
        s += "_";
    }
    return s;
}

int checkIntorCharorFloat(node* root) {
    if (!root->declSp) {
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkType(root->declSp, TYPE_INT, 0) || checkType(root->declSp, TYPE_CHAR, 0) || checkType(root->declSp, TYPE_FLOAT, 0))
        return 0;

    return TYPE_ERROR;
}


int checkIntOrCharOrPointer(node* root) {
    if (!root->declSp) {
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (!checkPointer(root) || checkType(root->declSp, TYPE_INT, 0) || checkType(root->declSp, TYPE_CHAR, 0))
        return 0;

    return TYPE_ERROR;
}

int checkIntOrChar(node* root) {
    if (!root->declSp) {
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkType(root->declSp, TYPE_INT, 0) || checkType(root->declSp, TYPE_CHAR, 0))
        return 0;

    return TYPE_ERROR;
}

int checkStringLiteralDecl(declSpec* root) {
    if (!root) {
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    vector<int> v1 = root->type;
    if (v1.size() == 1 && v1[0] == TYPE_STRING_LITERAL) {
        return 0;
    }
    return TYPE_ERROR;
}

int checkPointer(node* root) {
    if (!root)
        return INVALID_ARGS;
    if (!root->declSp)
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    if (root->declSp->ptrLevel != 1)
        return TYPE_ERROR;
    return 0;
}

int getTypeRank(vector<int>& type) {
    if (type.size() != 1)
        -TYPE_ERROR;
    switch (type[0]) {
    case TYPE_STRUCT:
        return RANK_TYPE_STRUCT;
    case TYPE_FLOAT:
        return RANK_TYPE_FLOAT;
    case TYPE_INT:
        return RANK_TYPE_INT;
    case TYPE_CHAR:
        return RANK_TYPE_CHAR;
    case TYPE_VOID:
        return RANK_TYPE_VOID;
    }
    return -TYPE_ERROR;
}

int giveTypeCastRank(node* n1, node* n2) {
    //if -ve then error, 0 if equal rank, 1 if rank1 > rank2, 2 if rank2 > rank1
    if (!n1 || !n2)
        return -INVALID_ARGS;
    if (!n1->declSp || !n2->declSp)
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;

    vector<int> v1 = n1->declSp->type;
    vector<int> v2 = n2->declSp->type;
    /*  
        4       3     2       1 
        Float > Int > Char > Void
    */
    int rank1 = getTypeRank(v1);
    int rank2 = getTypeRank(v2);

    if (n1->declSp->ptrLevel > 0)
        rank1 = RANK_TYPE_POINTER;
    if (n2->declSp->ptrLevel > 0)
        rank2 = RANK_TYPE_POINTER;
    if (rank1 < 0)
        return rank1;
    if (rank2 < 0)
        return rank2;
    if (rank1 > rank2) {
        return 1;
    } else if (rank1 < rank2) {
        return 2;
    }
    return 0;
}

void typeCastLexemeWithEmit(node* temp, declSpec* dp) {
    string newTmp = emitTypeCast(temp, dp, errCode, errStr);
    temp->addr = newTmp;
    typeCastLexeme(temp, dp);
}

void typeCastLexeme(node* temp, declSpec* dp) {
    vector<int> newType = dp->type;
    string strType = "(TO_";
    strType = strType + getTypeString(newType);
    strType.pop_back();
    if (dp->ptrLevel) {
        strType += "*";
    }
    strType += ")";
    temp->declSp->type = newType;
    string s = strType + string(temp->lexeme);
    strcpy(temp->lexeme, s.c_str());
}

int giveTypeCastRankUnary(node* n1, node* n2) {
    if (!n1)
        return INVALID_ARGS;
    if (!n1->declSp)
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;

    if (!n2)
        return INVALID_ARGS;
    if (!n2->declSp)
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;

    if (requiresTypeCasting(n1->declSp, n2->declSp)) {
        int retval = canTypecast(n2->declSp, n1->declSp);
        if (retval)
            return retval;
        typeCastLexemeWithEmit(n2, n1->declSp);
    }
    return 0;
}

int typeCastByRank(node* n1, node* n2, int rank) {
    if (rank < 0 || rank > 2)
        return TYPE_ERROR;
    if (rank == 0)
        return 0;
    node *to, *from;
    if (rank == 1) {
        from = n2;
        to = n1;
    } else if (rank == 2) {
        from = n1;
        to = n2;
    }
    int retval = canTypecast(to->declSp, from->declSp);
    if (retval) {
        return retval;
    }
    typeCastLexemeWithEmit(from, to->declSp);
    return 0;
}

int bitwiseTypecastingSingleNode(node* n, int& errCode, string& errStr) {
    int retval = checkIntOrChar(n);
    if (retval) {
        setErrorParams(errCode, TYPE_ERROR, errStr, "type bitwise expression");
        return -TYPE_ERROR;
    }
    if (!n->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, n->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (n->declSp->type[0] == TYPE_CHAR) {
        declSpec* ds = new declSpec();
        ds->type.push_back(TYPE_INT);
        typeCastLexemeWithEmit(n, ds);
    }
    return 0;
}

int bitwiseImplicitTypecasting(node* n1, node* n2, int& errCode, string& errStr) {
    // if type is char convert it to int
    int ret1 = bitwiseTypecastingSingleNode(n1, errCode, errStr);
    if (ret1)
        return ret1;
    int ret2 = bitwiseTypecastingSingleNode(n2, errCode, errStr);
    if (ret2)
        return ret2;
    return 0;
}

int implicitTypecastingNotPointerNotStringLiteral(node* n1, node* n2, string& var) {
    int retval1 = checkPointer(n1);
    int retval2 = checkPointer(n2);
    if (!retval1) {
        if (n1->lexeme)
            var = n1->lexeme;
        return -POINTER_ERROR;
    }
    if (!retval2) {
        if (n2->lexeme)
            var = n2->lexeme;
        return -POINTER_ERROR;
    }
    int rank = giveTypeCastRank(n1, n2);
    if (rank < 0) {
        var = "typecasting error rank";
        return rank;
    }
    int retval = typeCastByRank(n1, n2, rank);
    if (retval) {
        return -retval;
    }
    return rank;
}

//TODO: check use in grammarOld.y
int implicitTypecastingNotStringLiteral(node* n1, node* n2, string& var) {
    int rank = giveTypeCastRank(n1, n2);
    if (rank < 0) {
        var = "typecasting error rank";
        return rank;
    }
    int retval = typeCastByRank(n1, n2, rank);
    if (retval) {
        return retval;
    }
    return rank;
}

bool requiresTypeCasting(declSpec* n1, declSpec* n2) {
    vector<int> v1 = n1->type;
    vector<int> v2 = n2->type;
    if (v1 != v2 || (v1 == v2 && v1[0] == TYPE_STRUCT && n1->lexeme != n2->lexeme) || (v1 == v2 && n1->ptrLevel != n2->ptrLevel))
        return true;
    return false;
}

node* makeNodeForExpressionByRank(node* n1, node* n2, string name, string lexeme, int rank, int& errCode, string& errStr) {
    if (rank < 0) {
        setErrorParams(errCode, rank, errStr, errStr);
        return nullptr;
    }
    node* temp = makeNode((char*)name.c_str(), (char*)lexeme.c_str(), 0, n1, n2, (node*)NULL, (node*)NULL);
    temp->declSp = new declSpec();
    switch (rank) {
    case 1:
        temp->declSp = n1->declSp;
        break;
    case 2:
        temp->declSp = n2->declSp;
        break;
    default:
        temp->declSp = n1->declSp;
        break;
    }
    string type = getTypeName(temp->declSp->type[0]);
    // if(temp->declSp->ptrLevel>0) type += "*"; // not sure as of yet type for operator.
    string new_lexeme = lexeme + "(" + type + ")";
    temp->lexeme = strcpy(new char[new_lexeme.length() + 1], new_lexeme.c_str());
    return temp;
}

//  4       3     2       1
//         Float > Int > Char > Void

node* makeNodeForExpressionNotPointerNotString(node* n1, node* n2, string name, int& errCode, string& errStr) {
    int rank = implicitTypecastingNotPointerNotStringLiteral(n1, n2, errStr);
    return makeNodeForExpressionByRank(n1, n2, name, name, rank, errCode, errStr);
}

node* makeNodeForExpressionNotStringForAddition(node* n1, node* n2, string name, int& errCode, string& errStr) {
    int retval1 = checkPointer(n1);
    int retval2 = checkPointer(n2);
    int rank1 = getTypeRank(n1->declSp->type);
    int rank2 = getTypeRank(n2->declSp->type);
    if (!retval1) {
        if (!retval2) {
            errStr = "invalid operands to binary +";
            setErrorParams(errCode, POINTER_ERROR, errStr, errStr);
            return nullptr;
        }
        if (rank2 != RANK_TYPE_INT && rank2 != RANK_TYPE_CHAR) {
            errStr = "invalid operands to binary +";
            setErrorParams(errCode, POINTER_ERROR, errStr, errStr);
            return nullptr;
        }
    } else if (!retval2) {
        if (!retval1) {
            errStr = "invalid operands to binary +";
            setErrorParams(errCode, POINTER_ERROR, errStr, errStr);
            return nullptr;
        }
        if (rank1 != RANK_TYPE_INT && rank1 != RANK_TYPE_CHAR) {
            errStr = "invalid operands to binary +";
            setErrorParams(errCode, POINTER_ERROR, errStr, errStr);
            return nullptr;
        }
    }
    int rank = implicitTypecastingNotStringLiteral(n1, n2, errStr);
    if (rank < 0) {
        errStr = "invalid operands to binary +";
        setErrorParams(errCode, TYPE_ERROR, errStr, errStr);
        return nullptr;
    }
    return makeNodeForExpressionByRank(n1, n2, name, name, rank, errCode, errStr);
}