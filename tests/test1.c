void scanf(char c, int* d);
void printf(char *c, int d); 
char *p = "%ld\n\0";

struct foo{
    int x,y;
};

int main() {
    struct foo f1;
    struct foo f2;
    f1.x = 1;
    f1.y = 2;
    f2=f1;
    printf(p,f2.x);
    return 0;
}