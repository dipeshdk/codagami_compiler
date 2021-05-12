char *str = "%d\n";

struct foo{
    int x,y,z;
};

struct hoo{
    int x,y,z,w,a,b;
};

void func6(struct foo f, int a, int b, int c, int d, int e, int i, struct hoo h1, int g, struct hoo h2) {
    printf(str,f.x);
    printf(str,f.y);
    printf(str,f.z);
    
    printf(str, h1.x);
    printf(str, h1.y);
    printf(str, h1.z);
    printf(str, h1.w);
    printf(str, h1.a);
    printf(str, h1.b);
    
    printf(str, h2.x);
    printf(str, h2.y);
    printf(str, h2.z);
    printf(str, h2.w);
    printf(str, h2.a);
    printf(str, h2.b);

    printf(str, a);
    printf(str, b);
    printf(str, c);
    printf(str, d);
    printf(str, e);
    printf(str, i);
    printf(str, g); 
    return;
} 

void func(struct foo f) {
    printf(str,f.x);
    printf(str,f.y);
    printf(str,f.z);
    return;
}

void gun(struct foo f, struct hoo h1, struct hoo h2) {
    printf(str,f.x);
    printf(str,f.y);
    printf(str,f.z);
    
    printf(str, h1.x);
    printf(str, h1.y);
    printf(str, h1.z);
    printf(str, h1.w);
    printf(str, h1.a);
    printf(str, h1.b);
    
    printf(str, h2.x);
    printf(str, h2.y);
    printf(str, h2.z);
    printf(str, h2.w);
    printf(str, h2.a);
    printf(str, h2.b);
    return;
}

int main(void)
{
    struct foo f;
    struct hoo h1, h2;
    f.x=1;
    f.y=2;
    f.z=3;

    h1.x=11;
    h1.y=12;
    h1.z=13;
    h1.w=14;
    h1.a=15;
    h1.b=16;

    h2.x=21;
    h2.y=22;
    h2.z=23;
    h2.w=24;
    h2.a=25;
    h2.b=26;
    func(f);
    gun(f,h1,h2);
    func6(f,100,101,102,103,104,105,h1,107,h2);
    return 0;
}