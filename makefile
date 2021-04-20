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

$(OBJ)/y.tab.c: $(SRC)/grammarOld.y
	$(YACC) --verbose --debug -o $(OBJ)/y.tab.c -vt $(SRC)/grammarOld.y
	
$(OBJ)/y.tab.h: $(SRC)/grammarOld.y
	$(YACC) --verbose --debug -o $(OBJ)/y.tab.h -dt $(SRC)/grammarOld.y

$(OBJ)/generateDot.o: $(SRC)/generateDot.cpp 
	$(GPP) -c $(SRC)/generateDot.cpp  -o $(OBJ)/generateDot.o 

#cpp files ------------------------------------------------------------------------------------------------

$(OBJ)/grammarFunctions.o: $(SRC)/grammarFunctions.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/grammarFunctions.cpp -o $(OBJ)/grammarFunctions.o

$(OBJ)/printSymbolTable.o: $(SRC)/printSymbolTable.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/printSymbolTable.cpp -o $(OBJ)/printSymbolTable.o

$(OBJ)/symbolTable.o: $(SRC)/symbolTable.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/symbolTable.cpp -o $(OBJ)/symbolTable.o

$(OBJ)/TAC.o: $(SRC)/TAC.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/TAC.cpp -o $(OBJ)/TAC.o

$(OBJ)/typecast.o: $(SRC)/typecast.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/typecast.cpp -o $(OBJ)/typecast.o
	
$(OBJ)/utility.o: $(SRC)/utility.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/utility.cpp -o $(OBJ)/utility.o

$(OBJ)/AST.o: $(SRC)/AST.cpp $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/AST.cpp -o $(OBJ)/AST.o

#-----------------------------------------------------------------------------------------------

$(OBJ)/lex.yy.o: $(OBJ)/lex.yy.c
	$(CC) -o $(OBJ)/lex.yy.o -c $(OBJ)/lex.yy.c

$(BIN)/3AC: $(OBJ)/lex.yy.o $(OBJ)/y.tab.c $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o
	$(GPP) -o $(BIN)/3AC $(OBJ)/lex.yy.o $(OBJ)/y.tab.c  $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o


clean: 
	$(RM) $(OBJ)/* $(BIN)/* ./*.dot ./*.ps ./*.json ./code.txt
