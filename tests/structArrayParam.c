void printf(char *c, int a);
int* malloc(int x);
char *str = "%d\n";

struct foo{
    int x,y,z;
};

struct foo1{
    int a,b;
};


void func(struct foo sarr[2] , int c, struct foo1 f){
    struct foo1 f1;
    f1.a = f.a;
    f1.b = f.b;
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
    return;
}

int main(){
    struct foo arr[2];
    struct foo f1, *f2;
    struct foo1 f3;
    f2 = malloc(sizeof(f2));
    f1.x = 35;
    f1.y = 45;
    f1.z = 55;
    (*f2).x = 65;
    (*f2).y = 75;
    (*f2).z = 85;
    arr[0] = f1;
    arr[1] = *f2;
    f3.a = 10;
    f3.b = 20;
    func(arr , 100, f3);
    return 0;

}