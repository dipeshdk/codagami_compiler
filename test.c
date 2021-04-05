#include <stdio.h>

a();

int a(int b)
{
    printf("inside func a\n");
    return 1; 
}

int main() {
    int b;
    printf("ret value: %d\n", a(b));
    return 0;
}