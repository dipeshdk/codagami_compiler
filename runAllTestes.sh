fileNames=("ackerman.c" "arrayInitialization.c" "arrayTest.c" "binarySearchRecursive.c" "bubble_sort.c" "commentLineNumber.c" "fibonacci.c" "funcTest.c" "functionDeclaration.c" "mutualRecursion.c" "nested_if.c" "newton_raphson.c" "odd_even_recursion.c" "operatorTypecasting.c" "quicksort.c" "shortCircuitEval.c" "sizeof.c" "struct_in_function.c" "structUnionAsFuncParamAndReturn.c" "ternary.c" "test1.c" "test2.c" "test3.c" "test_issue13.c" "unaryOperators.c" "unaryVsBinaryMinus.c" "unionType.c")

make
mkdir outputs
mkdir symbolTableJson
for f in "${fileNames[@]}"
do
out="${f%.c}".output
echo "filename: ${f}"
    bin/3AC tests/$f outputs/$out
done