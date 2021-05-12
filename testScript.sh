RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'
rm failed_logs
touch failed_logs
format=./tests/*.c
echo -e "${BLUE}------------make realclean--------------------${NC}"
make realclean
echo -e "${BLUE}------------make--------------------${NC}"
make
if [ $? -ne 0 ]; then
    echo -e "${RED}Error in make${NC}";
    exit 1
fi

for file in $format;
do
 if [[ "$file" == "$format" ]]
 then
    echo -e "${RED}No Files in tests directory${NC}"
    exit 1
 else
    fileName=$(basename "${file%.*}")
    echo -e "${BLUE}Running $fileName ${NC}"
    ./run $file &> testcase_temp
    retVal=$?
    if [[ "$fileName" =~ fail_* ]]; then
        if [ $retVal -ne 0 ]; then
            echo -e "TESTCASE ${GREEN}PASSED${NC}"
            cat testcase_temp >> failed_logs
        else
            echo -e "TESTCASE ${RED}FAILED${NC}"
        fi
    else
        if [ $retVal -ne 0 ]; then
            echo -e "TESTCASE ${RED}FAILED${NC}"
            cat testcase_temp >> failed_logs
        else
            echo -e "TESTCASE ${GREEN}PASSED${NC}"
        fi
    fi
    
    rm testcase_temp
 fi
done