lex grammar.l
yacc --verbose --debug -d grammarOld.y
gcc -c lex.yy.c

g++ -c AST.cpp -o AST.o
g++ -c generateDot.cpp -o generateDot.o
g++ -c grammarFunctions.cpp -o grammarFunctions.o
g++ -c printSymbolTable.cpp -o printSymbolTable.o
g++ -c symbolTable.cpp -o symbolTable.o
g++ -c TAC.cpp -o TAC.o
g++ -c typecast.cpp -o typecast.o
g++ -c utility.cpp -o utility.o

g++ lex.yy.o y.tab.c AST.o  generateDot.o  grammarFunctions.o  printSymbolTable.o  symbolTable.o TAC.o typecast.o utility.o

./a.out ../tests/test$1.c
./genDot.sh