#include "headers/allInclude.h" 

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
    if (!temp->declSp)
        temp->declSp = new declSpec();
    if(from && from->declSp && from->declSp->ptrLevel)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
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


int getValueFromConstantExpression(node* constant_expression, int &err) {
    int val = 0;
    if(!constant_expression) {
        err = INVALID_ARGS;
        return val;
    }
	switch(constant_expression->valType){
        case TYPE_INT: 
            val = constant_expression->ival;
            break;
        case TYPE_FLOAT:
        default:
		    err = TYPE_ERROR;
			return val;
            break; 
    }
    return val;
}


void setErrorParams(int &errCode, int code, string &errString, string str) {
    errCode=code;
    errString=str;
    return;
}

void error(string var, int error_code) {
	string str;
	switch(error_code) {
		case SYMBOL_ALREADY_EXISTS:
			str = "SYMBOL_ALREADY_EXISTS";
			break;
		case ALLOCATION_ERROR:
			str = "ALLOCATION_ERROR";
			break;
		case INVALID_ARGS:
			str = "Invalid arguments passed to the function ";
			break;
		case CONFLICTING_TYPES:
			str = "Conflicting type of declaration ";
			break;
		case UNDECLARED_SYMBOL:
			str = "Undeclared symbol ";
			break;		
		case TYPE_ERROR:
			str = "TYPE_ERROR";
			break;
		case ARRAY_SIZE_NOT_CONSTANT:
			str = "Array size should be a constant ";
			break;
		case ARRAY_SIZE_SHOULD_BE_INT:
			str = "Array size should be a integer ";
			break;
		case ARRAY_INDEX_SHOULD_BE_INT:
			str = "Array index should be a integer ";
			break;
		case INVALID_ARGS_IN_FUNC_CALL:
			str = "Invalid aruments in function call ";
			break;
		case INVALID_STORAGE_CLASS:
			str = "Conflicting type of storage class ";
			break;
		case SYMBOL_NOT_FOUND:
			str = "Symbol used before declaration ";
			break;
		case STRUCT_NOT_DECLARED:
			str = "Undeclared struct ";
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
			str = "INTERNAL_ERROR_DECL_SP_NOT_DEFINED";
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
			str = "functionality is not supported by this compiler.";
			break;
		case NOT_A_CHAR:
			str = "should be a char";
			break;
		case DEFAULT_ERROR:
			str = "";
			break;
		case NON_POINTER_DEFERENCE:
			str = "Dereferencing a non-pointer";
			break;
		case UNDEFINED_FUNCTION:
			str = "Function is not defined";
			break;
		case MISMATCH_DEFINITION_DECLARATION:
			str = "Function declaration and definition do not match.";
			break;
		default:
			break;
	}
	str += " ";
	str+=var;
	cout << "\nERROR: " << str << " on line number: " << line+1 << endl;
	exit(error_code);
}