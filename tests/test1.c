void printf(char* p, int d);
char* p = "%ld\n";
<<<<<<< HEAD

 struct foo{
    int x,y,z;
};
 
 void func(struct foo f1) {
    return;
}

void kite(int a1, int a2, int a3,
    int a4, int a5, int a6, int a7,
    int a8, int a9) {
        return;
} 

int main(){
    struct foo f2;
    f2.x=5;
    func(f2);
    /* printf(p,y); */
   /*  int a,b,c,d;
    kite(1,2,3,4,5,a,b,c,d); */

   /*  int arr[1];
    arr[0]=5; */

    

=======

struct foo{
    int a;
    int b;
};

void func(int arr[10], int b, int c){
    arr[0] = b;
    arr[1] = b+c + arr[0];
    printf(p,arr[1]);
}


int main(){

    struct foo f[2];
    int array[10];
    struct foo f1, *f2;
    int c = 9;
    f2 = &f1;
    f1.a = 8;
    f1.b = 9;
    f[0].a = 78;
    f[0].b = 79;
    f[1] = f1;
    array[0] = 0;
    array[1] = 1;
    c = f[1].a + f[0].b + f2->a + f2->b;
    
    printf(p, f[0].a);
    printf(p, f[0].b);
    printf(p, f[1].a);
    printf(p, f[1].b);
    printf(p, f1.a);
    printf(p, f1.b);
    printf(p, c);  
    func(array, c, c);
>>>>>>> 16c46c38fbc78aaf7ab57e32e8b58179c62394b1
    return 0;
}
