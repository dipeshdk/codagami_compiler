void printf(char* str, int x);
char* str = "%d\n";
struct foo{
    int a,b,c,d,e,f,g,h,i,j,k,l;
};

struct foo func(int a) {
    struct foo f;
    f.a=1;
    f.b=2;
    f.c=3;
    f.d=4;
    f.e=5;
    f.f=6;
    f.g=7;
    f.h=8;
    f.i=9;
    f.j=10;
    f.k=11;
    f.l=12;
    return f;
}

int main(){
    int a = 69;
    struct foo f;
    int x;
    f.a=3;
    x=5;
    x=6;
    f = func(a);
    printf(str, f.f);
    return 0;
}