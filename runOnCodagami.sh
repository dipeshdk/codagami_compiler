#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

testPath=$1
fileName=$(basename ${testPath%.c})

echo -e "${BLUE}------------make--------------------${NC}"
make
if [ $? -ne 0 ]; then
    echo -e "${RED}Error in make${NC}";
    exit 1
fi

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
./codagamiBinary.out > codagamiOutput
if [ $? -ne 0 ]; then
    echo -e "${RED}Error running codagami assembly${NC}";
    exit 1
else echo -e "${GREEN}Open file codagamiOutput for the output${NC}"
fi
