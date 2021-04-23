struct foo{
    int a;
    float b;
    char c;
};

int main(){
    int a;
    int b, c, d;
    struct foo e, f;

    a = sizeof(int);
    b = sizeof(struct foo);
    c = sizeof(char);
    d = sizeof(c);
    return 0;
}