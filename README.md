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

## Abstract Syntax Tree

The project parses input C file and outputs an abstract syntax tree as a DOT script. This DOT script can be processed to view the AST in graphical form.

## Usage

### Build everything 
```console
$  cd src
$  cd ./runOnCodagami [test_file]
```

### Build everything and diff the output with gcc
```console
$  cd src
$  cd ./runTest [test_file]
```

### Build and Run all testcases
```console
$  make test
```

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
