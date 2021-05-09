void printf(char* p, int d);
char* str = "%d\n";

int foo(int x){
    return x;
}
int bar(int x){
    return x;
}

int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    if(a == 1){
        d = 5;
        printf(str, d);
    }
    printf(str, a);
    if(b == foo(2) + c && c != b + d){
        d = 6;
        printf(str, d);
    }
    printf(str, d);
    a = 10;
    if(b + d <= c - a|| bar(12) >= d /a){
        b = 34;
        printf(str, b);
    }
    printf(str, b);
    a = b && c;
    printf(str, a);
    a = b + d + c  || a - b;
    printf(str, a);
    return 0;
}