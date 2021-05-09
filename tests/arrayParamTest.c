
void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d\n";

void func(int arrfunc[4], int c, int b){
    int x[3];
    int z[2];
    x[0] = 10;
    x[1] = 11;
    x[2] = 12;
    z[0] = 91;
    z[1] = 92;

    c = x[1] + x[2] + x[0] + arrfunc[0];
    b = z[1] + z[0] + arrfunc[1];

    printf(p,x[0]);
    printf(p,x[1]);
    printf(p,x[2]);
    printf(p,z[0]); 
    printf(p,z[1]);
    printf(p,c);
    printf(p,b);
}


int main() {
    int arr[4];
    int arr2[4];
    int c;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr2[0] = arr[1];
    arr2[1] = arr[2];
    c = 100;
    arr2[2] = arr[3];

    printf(p,arr[0]);
    printf(p,arr[1]);
    printf(p,arr[2]);
    printf(p,arr[3]);
    printf(p,arr2[0]);
    printf(p,arr2[1]);
    printf(p,arr2[2]);
    printf(p,c);

    func(arr, c, c+5);
    return 0;
}
