CC=gcc
SRC=src
BIN=bin
OBJ=obj
LEX=flex
YACC=yacc 
objfiles = lex.yy.c y.output y.tab.c y.tab.h

all: $(BIN)/lexer

$(BIN)/lexer: $(OBJ)/lex.yy.c $(OBJ)/y.tab.c
	$(CC) -o $(BIN)/lexer $< -lfl

$(OBJ)/lex.yy.c : $(SRC)/grammar.l $(OBJ)/y.tab.h
	$(LEX) -o $(OBJ)/lex.yy.c $(SRC)/grammar.l

$(OBJ)/y.tab.c: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.c -dvt $(SRC)/grammar.y

$(OBJ)/y.tab.h: $(SRC)/grammar.y
	$(YACC) -o $(OBJ)/y.tab.h -dvt $(SRC)/grammar.y

clean: 
	$(RM) $(OBJ)/$(objfiles) $(BIN)/*


