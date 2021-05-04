void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d \n";

struct foo{
    int a;
    int b;
    int c;
};

int main() {
    struct foo f[2];
    f[0].a = 4;
    printf(p, f[0].a);
    return 0;
}