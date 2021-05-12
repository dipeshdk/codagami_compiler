char* str = "%d\n";

int foo(int a, char b){
    int x = 90,y = 67;
    printf(str,a);
    printf(str,b);
    {char g = 'c';
    x = a * b + g;
    printf(str,x);
    printf(str,g);
    }
    y = a * b ;
    printf(str,y);
    return y;
}

int main(){
    int x = 34, y = 25;
    int g = 56;
    char k = 'a';
    y = 0;
    y = foo(g,k);
    printf(str,y);
    x = 0;
    printf(str,x);
    return 0;
}