void printf(char *c, int a);
int* malloc(int x);
char *str = "%d\n";

/* struct foo{
    int x,y,z;
};

struct foo1{
    int a,b;
};

void func(struct foo sarr[2], int c){
    struct foo1 f1;
    f1.a = 10;
    f1.b = 11;
    sarr[0].x = sarr[1].x + sarr[1].y + 2*c;
    sarr[0].y = f1.a;
    printf(str, sarr[0].x);
    printf(str, sarr[0].y);
    printf(str, sarr[0].z);
    printf(str, sarr[1].x);
    printf(str, sarr[1].y);
    printf(str, sarr[1].z);
    printf(str, f1.a);
    printf(str, f1.b);
}
 */
int main(){
    /* struct foo f1,*f2;
    struct foo arr[2];
    int x,y;
    f2 = malloc(24);
    f2 = &f1;
    f1.x = 90;
    f1.z = 92;
    f1.y = 91;
    printf(str, f1.x);
    printf(str, f1.y);
    printf(str, f1.z);
    f2->x = 80;
    f2->y = 81;
    f2->z =  82;
    printf(str, f2->x);
    printf(str, f2->y);
    printf(str, (*f2).z);
 */
    /* arr[0].x = 70;
    arr[0].y = 71;
    arr[0].z = 72;
    arr[1] = *f2;

    x = f1.x + f2->y + arr[0].x;

    printf(str, arr[0].x);
    printf(str, arr[0].y);
    printf(str, arr[0].z);
    printf(str, arr[1].x);
    printf(str, arr[1].y);
    printf(str, arr[1].z);

    func(arr, x + (*(f2)).z); */

    return 0;
}
