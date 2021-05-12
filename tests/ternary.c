char* str = "%d\n";

int foo(int a, int x, int y, int z) {
   int b = 5;
   a = 1 ? 2 : 3;
   printf(str, a);
   a = 0 ? 2 : 3;
   printf(str, a);
   a = 1==9 ? 2 : 3;
   printf(str, a);
   a = 1<=9 ? 2 : 3;
   printf(str, a);
   a = 1>=9 ? 2 : 3;
   printf(str, a);
   a = 1!=9 ? 2 : 3;
   printf(str, a);
   a = 1!=1 ? 2 : 3;
   printf(str, a);

   a = 1 ? x : 3;
   printf(str, a);
   a = 0 ? x : 3;
   printf(str, a);
   a = 1==9 ? x : 3;
   printf(str, a);
   
   a = 1<=9 ? x : 3;
   printf(str, a);
   a = 1>=9 ? x : 3;
   printf(str, a);
   a = 1!=9 ? x : 3;
   printf(str, a);
   a = 1!=1 ? x : 3;
   printf(str, a);
  
   a = 1 ? x : y;
   printf(str, a); 

   a = 0 ? x : y;
   printf(str, a);
   a = 1==9 ? x : y;
   printf(str, a);
   a = 1<=9 ? x : y;
   printf(str, a);
   a = 1>=9 ? x : y;
   printf(str, a);
   a = 1!=9 ? x : y;
   printf(str, a);
   a = 1!=1 ? x : y;
   printf(str, a);
    
   a = b ? x : y;
   printf(str, a);
   a = b ? x : y;
   printf(str, a);
   a = b==9 ? x : y;
   printf(str, a);
   a = b<=9 ? x : y;
   printf(str, a);
   a = b>=9 ? x : y;
   printf(str, a);
   a = b!=9 ? x : y;
   printf(str, a);
   a = b!=1 ? x : y;
   printf(str, a);

   a = b ? x : y;
   printf(str, a);
   a = b ? x : y;
   printf(str, a);
   a = b==z ? x : y;
   printf(str, a);
   a = b<=z ? x : y;
   printf(str, a);
   a = b>=z ? x : y;
   printf(str, a);
   a = b!=z ? x : y;
   printf(str, a);
   a = b!=b ? x : y;
   printf(str, a);
    if(!a) a=4;
    else a = 5;
    printf(str, a);
    a = x*y == ( 2*x >= 3*y+z? 3*z : (1 ? 3*z : x*y)) ? 3+x*y+z : 4*7+x + y + z;
    return a;
}

int main(){
    int a, x = 9, y = 0, z =90;
    a = x*y == ( 2*x >= 3*y+z? 3*z : x*y) ? 3+x*y+z : 4*7+x + y + z;
    printf(str,a);
    printf(str, foo(2,x,y,z));
    return 0;
}