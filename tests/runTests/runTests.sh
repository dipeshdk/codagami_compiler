#!/bin/bash

test () {

	# Remove old output files if any
	[ -f ../ActualOutput/output$1.txt ] && rm ../ActualOutput/output$1.txt
	
	# Execute the file and save the printed output.
	../../bin/lexer ../test$1.c > ../ActualOutput/output$1.txt
	
	
	# Compare the content of expected and generated output file.
	../../bin/compare "../ActualOutput/output$1.txt" "../Expected_outputs/test$1"
	
	# If both are equal the test is passed.
	if [[ $? -eq 0 ]]
	then
		echo "TEST $1 PASSED"
	else
		echo "TEST $1 FAILED"
	fi
	
}

# Cleanup old executable 
[ -f ../../bin/compare ] && rm ../../bin/compare

# Compile
g++ -o ../../bin/compare compare.cpp

test 1
test 2
test 3
test 4
test 5
