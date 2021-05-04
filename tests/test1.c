void scanf(char c, int* d);
void printf(char *c, int d); 
char *p = "%ld\n\0";

void func(int a1[10]){
    return;
}

void func2(int a2[10]){
    return;
}

struct foo{
    int x,y;
};

int main() {
    int f[2];
    int c;
    f[0] = 5;
    c = f[0];
    printf(p,c);
    return 0;
}