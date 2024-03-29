#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

testPath=$1
fileName=$(basename ${testPath%.c})


rm -f gccOutput myOutput
echo -e "${BLUE}----------------------file name $fileName------------------------------------${NC}"


echo -e "${BLUE}----------------------building assembly bin/3AC --------------------------${NC}"
rm -f outputs/${fileName}
mkdir outputs/${fileName}
bin/codagami -i ${testPath} -all outputs/${fileName}/ -E
if [ $? -ne 0 ]; then
    echo -e "${RED}Error building codagami assembly${NC}";
    exit 1
fi


echo -e "${BLUE}----------------------assembler gcc -no-pie ------------------------------${NC}"
gcc -no-pie outputs/${fileName}/${fileName}.s -o codagamiBinary.out -lm
if [ $? -ne 0 ]; then
    echo -e "${RED}Error running codagami assembly${NC}";
    exit 1
fi


echo -e "${BLUE}----------------------running my a.out ---------------------------------${NC}"
./codagamiBinary.out > myOutput
if [ $? -ne 0 ]; then
    echo -e "${RED}Error running codagami assembly${NC}";
    exit 1
fi


echo -e "${BLUE}----------------------building using gcc...-------------------------------${NC}"
gcc -ansi -pedantic ${testPath} -o gccBinary.out -lm
if [ $? -ne 0 ]; then
    echo -e "${RED}Error building gcc assembly${NC}";
    exit 1
fi


echo -e "${BLUE}----------------------running gcc a.out...--------------------------------${NC}"
./gccBinary.out > gccOutput
if [ $? -ne 0 ]; then
    echo -e "${RED}Error running gcc output${NC}";
    exit 1
fi


echo -e "${BLUE}----------------------printing diff---------------------------------------${NC}"
diff -c gccOutput myOutput
if [ $? -ne 0 ]; then
    echo -e "${RED}**gcc and codagami output didn't match**${NC}";
    exit 1
fi

exit 0