void printf(char *c, int a);
char *str = "%d\n";

struct foo{
    int x,y,z;
};

void func(int a,int b,int c,int d, int e, int f, int g) {
    printf(str,g);
    return;
}

int main(void)
{
    struct foo f;
    func(1,2,3,4,5,6,7);
    return 0;
}