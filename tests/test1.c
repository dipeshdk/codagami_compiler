
void printf(char *c, int d);
char *p = "%d\n";
struct foo{
    int a;
    int b;
    float c;
};


int main() {
    struct foo f;
    int c = 5;
    f.a = 5;
    printf(p,c);
    return 0;
}