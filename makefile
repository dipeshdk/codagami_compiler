CC=gcc
SRC=src
BIN=bin
OBJ=obj
LEX=lex
YACC=yacc 
GPP=g++
HEADER=$(SRC)/headers

all: $(BIN)/codagami

$(OBJ)/lex.yy.c : $(SRC)/grammar.l $(OBJ)/y.tab.h $(OBJ)/y.tab.c
	$(LEX) -o $(OBJ)/lex.yy.c $(SRC)/grammar.l

$(OBJ)/y.tab.c: $(SRC)/grammarOld.y
	$(YACC) --verbose --debug -o $(OBJ)/y.tab.c -vt $(SRC)/grammarOld.y
	
$(OBJ)/y.tab.h: $(SRC)/grammarOld.y
	$(YACC) --verbose --debug -o $(OBJ)/y.tab.h -dt $(SRC)/grammarOld.y

$(OBJ)/generateDot.o: $(SRC)/generateDot.cpp 
	$(GPP) -c $(SRC)/generateDot.cpp  -o $(OBJ)/generateDot.o 

#cpp files ------------------------------------------------------------------------------------------------


$(OBJ)/grammarFunctions.o: $(SRC)/grammarFunctions.cpp $(HEADER)/grammarFunctions.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/grammarFunctions.cpp -o $(OBJ)/grammarFunctions.o

$(OBJ)/printSymbolTable.o: $(SRC)/printSymbolTable.cpp $(HEADER)/printSymbolTable.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/printSymbolTable.cpp -o $(OBJ)/printSymbolTable.o

$(OBJ)/symbolTable.o: $(SRC)/symbolTable.cpp $(HEADER)/symbolTable.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/symbolTable.cpp -o $(OBJ)/symbolTable.o

$(OBJ)/TAC.o: $(SRC)/TAC.cpp $(HEADER)/TAC.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/TAC.cpp -o $(OBJ)/TAC.o

$(OBJ)/typecast.o: $(SRC)/typecast.cpp $(HEADER)/typecast.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/typecast.cpp -o $(OBJ)/typecast.o
	
$(OBJ)/utility.o: $(SRC)/utility.cpp $(HEADER)/utility.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/utility.cpp -o $(OBJ)/utility.o

$(OBJ)/AST.o: $(SRC)/AST.cpp $(HEADER)/AST.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/AST.cpp -o $(OBJ)/AST.o

$(OBJ)/compile3AC.o: $(SRC)/compile3AC.cpp $(HEADER)/compile3AC.h $(HEADER)/compile3AC.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/compile3AC.cpp -o $(OBJ)/compile3AC.o

$(OBJ)/compile3ACfloat.o: $(SRC)/compile3ACfloat.cpp $(HEADER)/compile3ACfloat.h $(HEADER)/constants.h $(HEADER)/structures.h $(HEADER)/allInclude.h
	$(GPP) -c $(SRC)/compile3ACfloat.cpp -o $(OBJ)/compile3ACfloat.o

#-----------------------------------------------------------------------------------------------

$(OBJ)/lex.yy.o: $(OBJ)/lex.yy.c
	$(CC) -o $(OBJ)/lex.yy.o -c $(OBJ)/lex.yy.c

$(BIN)/codagami: $(OBJ)/lex.yy.o $(OBJ)/y.tab.c $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o $(OBJ)/compile3AC.o  $(OBJ)/compile3ACfloat.o
	$(GPP) -o $(BIN)/codagami $(OBJ)/lex.yy.o $(OBJ)/y.tab.c  $(OBJ)/AST.o  $(OBJ)/generateDot.o  $(OBJ)/grammarFunctions.o  $(OBJ)/printSymbolTable.o  $(OBJ)/symbolTable.o $(OBJ)/TAC.o $(OBJ)/typecast.o $(OBJ)/utility.o $(OBJ)/compile3AC.o $(OBJ)/compile3ACfloat.o



clean:
	$(RM) ./*.dot ./*.ps ./*.json ./code.txt symbolTableJson/*
realclean: 
	$(RM) -rf $(OBJ)/* $(BIN)/* ./*.dot ./*.ps ./*.json ./code.txt symbolTableJson/* ./gccOutput ./myOutput ./gccBinary.out ./codagamiBinary.out ./outputs/* ./a.out
test:
	bash testScript.sh
