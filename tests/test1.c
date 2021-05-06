void printf(char* p, int d);
char* p = "%ld\n";

struct foo{
    int a;
    int b;
};

int main(){

    struct foo f[2];
    struct foo f1;

    f1.a = 4;
    f1.b = 5;
    f[0] = f1; 
  
    printf(p, f[1].b);
    return 0;
}
