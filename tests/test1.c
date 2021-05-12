char *format = "%lf\n";

struct foo{
    int x;
    double y;
};

struct foo func(struct foo f){
    f.y += 90;
    f.x = 1000;
    return f;
}

struct foo* func2(struct foo f){
    struct foo *p;
    p = malloc(sizeof(struct foo));
    printf(format, f.x);
    printf(format, f.y);
    f.y += 90;
    f.x = 1000;
    printf(format, f.x);
    printf(format, f.y);
    *p = f;
    return p;
}


int main(){
    struct foo f, *p;
    struct foo arr[3];
    int x = 9;
    double y,z,w;
    p = malloc(sizeof(p));
    p->y = 78.90;
    f.x = x;
    f.y = 80.789;
    y = f.y + p->y;
    printf(format, y);
    y = f.y;
    arr[0] = f;
    y += arr[0].y;
    arr[0].y *= y;
    printf(format, y);
    printf(format, arr[0].y);
    y = arr[0].x;
    printf(format, y);
    arr[0].x = y;
    printf(format, arr[0].x);

    f = func(f);
    printf(format, f.x);
    printf(format, f.y);

    p = func2(f);
    printf(format, p->x);
    printf(format, p->y);
    
    return 0;
}