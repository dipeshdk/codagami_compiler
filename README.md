# codagami_compiler (Group 17)

This project is aimed to make a compiler of our own as a group project of the couse CS335A:Compiler Design. This Project is being handled by team Codagami

## Members

-   [Chimaya Singal (180207)](https://github.com/https://github.com/chinmaya-s)
-   [Dipesh Khandelwal (180249)](https://github.com/dipeshdk)
-   [Rythm Agarwal (180636)](https://github.com/Rythmag)
-   [Sakshi (180653)](https://github.com/Sakshisak)
-   [Sarthak Dubey (180674)](https://github.com/srthkdb)

## Implementation details

-   Implementation language: C++
-   Target language: x86 64-bit
-   Source language: C (fixed)

## Usage

### Build everything 
To build codagami binary and compile a C file, and output assembly, 3AC and symbol table, you can use the bash script runOnCodagami as:
```console
$  bash runOnCodagami.sh [input_file.c]
```
runOnCodagami stores the outputs in ./outputs/[input_file] directory \
Or you can manually run the commands:
```console
$  make
$  bin/codagami -i [input_file] -all
$  gcc -no-pie outputs/[input_file]/[input_file].s -o codagamiBinary.out -lm
$ bash codagamiBinary.out
```
For detailed use of codagami binary, refer to Documentation section of README.md.
### 

### Build everything and diff the output with gcc
To compare the output given by codagami and GCC, you can use the run script as follows:
```console
$  bash runTest.sh [input_file.c]
```
This will show you the diff of the output given by GCC and output given by codagami under the section "printing diff".

### Build and Run all testcases
We have made some test cases which are contained in the directory tests/ and these all testcases can be run through testScript.sh script as follows:
```console
$  make test
```
or
```console
$  bash testScript.sh
```
This will show you on the console which test cases are passing and which are failing. For the test cases which fail you can refer to failed_logs for finding the error information thrown by codagami.

## Documentation
### MakeFile
```console
make    :       Build codagami binariy
make clean   :  Removes temporaries
make realclean   :  Removes temporaries and outputs
make test   :  Build and test on all testcases
```
### Codagami binary
```console
Brief Usage: bin/codagami -i [input_file](compulsory) -o [output_file.s](default=input_file.s)
Details:
        -all [output_dir]       :   outputs everything except ast in output dir
        -ast [dot_file.dot]     :   outputs ast a .dot file 
        -tac [tac_file.tac]     :   outputs 3AC 
        -st [symbol_table_dir]  :   outputs symbol tables for each scope as a .json file 
        -E                      :   Applies gcc preprocessor on input file before processing 
        -h                      :   help 
```
