struct coord{
    int x;
    int y;
};

struct coord2{
    int x;
    int y;
};

struct coord foo1 (){
  struct coord x;
  return x;
}

/* (currently throwing error(fixed by GCC) --- to be checked by GCC */
struct coord* foo2 (){
  struct coord* x;
  return x;
}

/* different ptrLevel in structs : not allowed --- to be checked by GCC */
/* struct coord* foo3 (){
    struct coord a;
    return a; 
}
 */
/*  struct1 - struct2 : not allowed 
struct coord foo4 (){
    struct coord2 a;
    return a; 
}
*/

/*struct1 - any other data type : not allowed 
struct coord foo2 (){
    return 2; 
}
*/
/*
struct coord* foo2 (){
  struct coord2 x;
  return (&x)->a;
}
*/

int main() {
    float  f2;
    char p,q,r;
    int j1;
    int i;
    struct coord *f1,*f3;
    *f1 = foo1();
    /* f3 = foo1(); */
}