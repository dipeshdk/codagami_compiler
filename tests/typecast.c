
struct foo{
    int x,y;
};

int func(int c, int b){
    c = b;
    return 'a';
}

struct foo func1(int f){
    struct foo f1;
    return f1;
}



int main(){
    int a,b,*c;
    char x,y,*z;
    struct foo sf;

    a = 'a' + 1;
    b = 'b' + 2;
    x = a;
    a = a + c;
    b = z;

    a = func(a, x);

    x = (func1(b)).x;

    return 0;
}