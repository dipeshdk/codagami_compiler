#include <stdio.h>


int a(b, c) {
    char d = 'a'+ b;
    printf("d: %d\n",d);
    return d;
}


/*
if function, add to symbol table
if already in st, verify param list, ret type
if param list has no types, give warning

if param list is empty, modify the st entry of function later
to change param list

create a new st only in function defintion, and add params to symbol table;

a global var to store ret type if we are inside a function
verify and typecast return type when return statement is encountered


int a(int b, int c)
function_definition:  declaration_specifiers makeSTMarker declarator function_scope declaration_list compound_statement 


*/


int main() {
    char b = (1.5);
    double f = b+1.5;
    int i = 100;
    char* g=100;
    float h = g;
    if(g == b) {
        printf("eq");
    }else {
        printf("neq");
    }
    return 0;
} 