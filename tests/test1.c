void printf(char *c, int a);
char *str = "%d\n";

struct foo{
    int x,y,z;
};

void func(struct foo f) {
    printf(str,f.x);
    return;
}

int main(void)
{
    struct foo f;
    f.x=1;
    f.y=2;
    f.z=3;
    func(f);
    return 0;
}