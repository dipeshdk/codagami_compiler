struct foo{
    int a;
    float b;
    char c;
};

int main(){
    int a;
    int b, c, d;
    struct foo e, f;
    char ff;
    float xx;


    a = sizeof(int);
    b = sizeof(struct foo);
    c = sizeof(char);
    d = sizeof(c);
    d = sizeof(e);
    d = sizeof(ff);
    d = sizeof(xx);
    return 0;
}