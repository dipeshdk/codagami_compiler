# codagami_compiler (Group 17)

This project is aimed to make a compiler of our own as a group project of the couse CS335A:Compiler Design. This Project is being handled by team Codagami

## Members

-   [Chinmaya Singal (180207)](https://github.com/chinmaya-s)
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

## Usage example
The steps to compile and run an ANSI code are as follows:
```console
$ make
$ bin/codagami <filename>
$ gcc -no-pie outputs/<fileName>/<fileName>.s -o codagamiBinary.out -lm
$ bash codagamiBinary.out
```
To compare the output given by codagami and GCC, you can use the run script as follows:
```console
$ make
$ bash run <filename.c>
```
This will show you the diff of the output given by GCC and output given by codagami under the section "printing diff".

We have made some test cases which are contained in the directory tests/ and these all testcases can be run through testScript.sh script as follows:
```console
$ bash testScript.sh
```
This will show you on the console which test cases are passing and which are failing. For the test cases which fail you can refer to failed_logs for finding the error information thrown by codagami.
