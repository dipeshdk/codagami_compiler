void printf(char* str, double x);
char* format = "%lf\n";
double* malloc(int x);

struct foo{
    int x;
    float y;
};

int main(){
    struct foo f, *p1, *p2;
    struct foo arr[3];
    int x = 9;
    float y,z,w;
    y = 90.789;
    z = 0.0;
    w = 45.789;
    p1 = malloc(sizeof(p1));
    p2 = malloc(sizeof(p2));
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
    
    return 0;
}