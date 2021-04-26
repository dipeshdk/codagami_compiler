#include<stdio.h>

int foo(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
     a++;
     b++;
     c++;
     d++;
     e++;
     f++;
     i++;
     j++;
     return 60;
}

int main(){
    int a=1,b=2;
    int c =foo(1,2,3,4,5,6,7,8,9,10);
    printf("%d\n",c);
}