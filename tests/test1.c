/* void printf(char* str, double x);
void scanf(char* str, double* x);
double* malloc(int x);
char* format = "%lf\n";
int main() {
    double d = 5.5;
    int a=d;
    double dd = a;
    printf(str,dd);
    return 0;
} */

void printf(char* str, double x);
char* format = "%lf\n";
double* malloc(int x);

struct foo{
    int x;
    double y;
};

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
    
    return 0;
}