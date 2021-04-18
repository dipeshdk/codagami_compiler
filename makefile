CC=gcc
SRC=src
BIN=bin
OBJ=obj
LEX=lex
YACC=yacc 
GPP=g++
HEADER=$(SRC)/headers

all: $(BIN)/3AC

$(OBJ)/lex.yy.c : $(SRC)/grammar.l $(OBJ)/y.tab.h $(OBJ)/y.tab.c
	$(LEX) -o $(OBJ)/lex.yy.c $(SRC)/grammar.l

$(OBJ)/y.tab.c: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.c -vt $(SRC)/grammar.y
	
$(OBJ)/y.tab.h: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.h -dt $(SRC)/grammar.y

$(OBJ)/generateDot.o: $(SRC)/generateDot.cpp 
	$(GPP) -c generateDot.cpp  -o $(OBJ)/generateDot.o 

#cpp files ------------------------------------------------------------------------------------------------

$(OBJ)/grammarFunctions.o: $(SRC)/grammarFunctions.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c grammarFunctions.cpp -o grammarFunctions.o

$(OBJ)/printSymbolTable.o: $(SRC)/printSymbolTable.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c printSymbolTable.cpp -o printSymbolTable.o

$(OBJ)/symbolTable.o: $(SRC)/symbolTable.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c symbolTable.cpp -o symbolTable.o

$(OBJ)/TAC.o: $(SRC)/TAC.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c TAC.cpp -o TAC.o

$(OBJ)/typecast.o: $(SRC)/typecast.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c typecast.cpp -o typecast.o
	
$(OBJ)/utility.o: $(SRC)/utility.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c utility.cpp -o utility.o

$(OBJ)/AST.o: $(SRC)/AST.cpp $(HEADER)/constants.h $(HEADER)structures.h $(HEADER)/allInclude.h
	$(GPP) -c AST.cpp -o AST.o

#-----------------------------------------------------------------------------------------------

$(OBJ)/lex.yy.o: $(OBJ)/lex.yy.c
	$(CC) -o $(OBJ)/lex.yy.o -c $(OBJ)/lex.yy.c

$(BIN)/3AC: $(OBJ)/lex.yy.o $(OBJ)/y.tab.c $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o
	$(GPP) -o $(BIN)/3AC $(OBJ)/lex.yy.o $(OBJ)/y.tab.c $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o


clean: 
	$(RM) $(OBJ)/* $(BIN)/* ./*.dot ./*.ps 
