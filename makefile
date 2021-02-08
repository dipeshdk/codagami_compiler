CC=gcc
SRC=src
BIN=bin
OBJ=obj
LEX=flex
YACC=yacc 


all: $(BIN)/lexer

$(BIN)/lexer: $(OBJ)/lex.yy.c $(OBJ)/y.tab.c
	$(CC) -o $(BIN)/lexer $< -lfl

$(OBJ)/y.tab.c: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.c -vt $(SRC)/grammar.y

$(OBJ)/y.tab.h: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.h -dt $(SRC)/grammar.y

$(OBJ)/lex.yy.c : $(SRC)/grammar.l $(OBJ)/y.tab.h $(OBJ)/y.tab.c
	$(LEX) -o $(OBJ)/lex.yy.c $(SRC)/grammar.l

clean: 
	$(RM) $(OBJ)/* $(BIN)/*


