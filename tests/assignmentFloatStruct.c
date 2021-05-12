char* format = "%lf\n";

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
    struct foo f, *p1, *p2;
    struct foo arr[3];
    int x = 9;
    double y,z,w;
    y = 90.789;
    z = 0.0;
    w = 45.789;
    p1 = malloc(sizeof(struct foo));
    p2 = malloc(sizeof(struct foo));
    p2 = &f;
    p1->x = 5;
    p1->y = 78.90;
    f.x = x;
    f.y = 80.789;
    y = f.y + p1->y;
    printf(format, y);
    y = f.y;
    arr[0] = f;
    arr[1] = *p1;
    y += arr[0].y;
    printf(format, y);
    arr[0].y *= y;
    printf(format, arr[0].y);
    y = arr[0].x;
    printf(format, y);
    arr[0].x = y;
    printf(format, arr[0].x);
    w = arr[0].x + arr[1].y + p2->y*p1->x;
    printf(format, w);

    f = func(f);
    printf(format, f.x);
    printf(format, f.y);

    p1 = func2(f);
    printf(format, p1->x);
    printf(format, p1->y);
    
    return 0;
}