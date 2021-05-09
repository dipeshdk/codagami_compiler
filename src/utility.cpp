#include "headers/allInclude.h"

int mergeConstVolatile(node* temp, node* from) {
    if (!temp->declSp) {
        temp->declSp = new declSpec();
    }
    if (from->declSp) {
        temp->declSp->isConst = temp->declSp->isConst || from->declSp->isConst;
        temp->declSp->isVolatile = temp->declSp->isVolatile || from->declSp->isVolatile;
    }
    return 0;
}

int incrementPointerLevel(node* temp, node* from) {
    if (!temp->declSp)
        temp->declSp = new declSpec();
    if (from && from->declSp && from->declSp->ptrLevel)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    temp->declSp->ptrLevel++;
    return 0;
}

int copyPtrLevel(node* temp, node* from) {
    if (!temp->declSp)
        temp->declSp = new declSpec();
    if (from->declSp)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    return 0;
}

int getValueFromConstantExpression(node* constant_expression, int& err) {
    int val = 0;
    if (!constant_expression) {
        err = INVALID_ARGS;
        return val;
    }
    switch (constant_expression->valType) {
    case TYPE_INT:
        // val = constant_expression->ival;
        val = stoi(constant_expression->addr);
        break;
    case TYPE_CHAR:
        val = stoi(constant_expression->addr);
        break;
    default:
        err = TYPE_ERROR;
        return val;
        break;
    }
    return val;
}

void setErrorParams(int& errCode, int code, string& errString, string str) {
    errCode = code;
    errString = str;
    return;
}

void typeCastWarning(string from, string to){
   cout << "\nWARNING: implicit typecast from " << from << " to " << to << " on line number: " << line + 1 << endl;
}


void error(string var, int error_code) {
    string str;
    switch (error_code) {
    case SYMBOL_ALREADY_EXISTS:
        str = "redeclaration of";
        break;
    case ALLOCATION_ERROR:
        str = "ALLOCATION_ERROR";
        break;
    case INVALID_ARGS:
        str = "Invalid arguments passed to the function ";
        break;
    case CONFLICTING_TYPES:
        str = "Conflicting types for";
        break;
    case UNDECLARED_SYMBOL:
        str = "Undeclared symbol ";
        break;
    case TYPE_ERROR:
        str = "incompatible types.";
        break;
    case ARRAY_SIZE_NOT_CONSTANT:
        str = "Array size should be a constant ";
        break;
    case ARRAY_SIZE_SHOULD_BE_INT:
        str = "size of array has non-integer type.";
        break;
    case ARRAY_INDEX_SHOULD_BE_INT:
        str = "index of array has non-integer type.";
        break;
    case INVALID_ARGS_IN_FUNC_CALL:
        str = "Invalid aruments in function call ";
        break;
    case INVALID_STORAGE_CLASS:
        str = "Conflicting type of storage class ";
        break;
    case SYMBOL_NOT_FOUND:
        str = "undeclared symbol";
        break;
    case STRUCT_NOT_DECLARED:
        str = "Undeclared struct. storage size isn’t known for";
        break;
    case INVALID_SYNTAX:
        str = "Invalid Syntax ";
        break;
    case VARIABLE_NOT_A_STRUCT:
        str = "Not a struct ";
        break;
    case INVALID_REFERENCE:
        str = "Invalid reference ";
        break;
    case INVALID_STRUCT_PARAM:
        str = "Invalid struct param ";
        break;
    case INTERNAL_ERROR_DECL_SP_NOT_DEFINED:
        str = "INTERNAL_ERROR: Declaraton Specifier not defined";
        break;
    case POINTER_ERROR:
        str = "Invalid Operand Of Type Pointer";
        break;
    case STRING_LITERAL_ERROR:
        str = "Invalid Operand Of Type String";
        break;
    case SHOULD_NOT_BE_FLOAT:
        str = "Invalid Operand Of Type Float";
        break;
    case VOID_ERROR:
        str = "void data type is not compatible";
        break;
    case UNSUPPORTED_FUNCTIONALITY:
        str = "This functionality is not supported by this compiler.";
        break;
    case NOT_A_CHAR:
        str = "should be a char";
        break;
    case DEFAULT_ERROR:
        str = "";
        break;
    case NON_POINTER_DEFERENCE:
        str = "invalid type argument of unary *";
        break;
    case UNDEFINED_FUNCTION:
        str = "Function is not defined";
        break;
    case MISMATCH_DEFINITION_DECLARATION:
        str = "Function declaration and definition do not match.";
        break;
    case ASSIGNMENT_TO_CONSTANT_ERROR:
        str = "Assignment to a constant not allowed";
        break;
    case ARRAY_SIZE_SHOULD_BE_POSITIVE:
        str = "Array size should be positive integer constant";
        break;
    case ARRAY_INDEX_SHOULD_BE_POSITIVE:
        str = "Array size should be positive integer constant";
        break;
    case NON_GLOBAL_STRING_LITERAL:
        str = "Non global string literal. String literals can be used only in global scope";
        break;
    case INVALID_STRING_LITERAL_ASSIGNMENT:
        str = "Invalid string literal assignment";
        break;
    case INVALID_POINTER_ADDR:
        str = "Internal error: Invalid pointer name in 3AC code";
        break;
    case INVALID_GLOBAL_INITIALIZER:
        str = "Invalid global initialization. RHS must be constant.";
        break;
    default:
        break;
    }
    str += " ";
    str += var;
    cout << "\nERROR: " << str << " on line number: " << line + 1 << endl;
    exit(error_code);
}

void copyList(node* n1, node* n2) {
    n1->continuelist = n2->continuelist;
    n1->nextlist = n2->nextlist;
    n1->truelist = n2->truelist;
    n1->falselist = n2->falselist;
}

bool isConstant(string s) {
    if(s == CONSTANT){
        return true;
    }
    int n = s.length();
    int i = 0;
    if (n > 0 && s[0] == '-')
        i++;
    for (; i < n; i++) {
        char c = s[i];
        if (!(c >= '0' && c <= '9'))
            return false;
    }
    return true;
}

string hexString(string decStr) {
    return decStr;
}

int getNumberFromConstAddr(string s) {
    int a;
    stringstream ss;
    ss << s;
    ss >> a;
    return a;
}

string removeExtension(string str) {
    char c = '.';
    size_t found = str.find(c);
    if (found != string::npos)
        return str.substr(0, found);
    return str;
}

string extractFileName(string str) {
    char ch = '/';
    size_t found;
    found = str.find_last_of(ch);
    if (found == string::npos) {
        return removeExtension(str);
    } else {
        return removeExtension(str.substr(found + 1, str.length() - found - 1));
    }
}