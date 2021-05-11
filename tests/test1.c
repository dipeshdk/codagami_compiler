/* void printf(char* str, double x);
void scanf(char* str, double* x);
double* malloc(int x);
char* format = "%lf\n";
int main() {
    double x = 90.89;
    double *g = malloc(8);
    printf(format, x);
    scanf(format, &x);
    printf(format, x);
    return 0;
} */

void printf(char* str, double x);
char* format = "%lf\n";
double* malloc(int x);

struct foo{
    int x;
    float y;
};

int main(){
    struct foo f, *p;
    struct foo arr[3];
    int x = 9;
    float y,z,w;
    p = malloc(sizeof(p));
    p->y = 78.90;
    f.x = x;
    f.y = 80.789;
    y = f.y + p->y;
    printf(format, y);
    y = f.y;
    arr[0] = f;
    y = arr[0].y;
    printf(format, y);
    /* y = arr[0].x;
    printf(format, y); */
    
    return 0;
}