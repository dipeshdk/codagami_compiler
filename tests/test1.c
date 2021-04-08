/* 
correct struct, 
function, 
variable declaration and use. Check symbol Table.
Should work correctly  
Nested struct
*/

struct foo{
    int x,y;
    float b;
};

int fu()int a1., float a2, char a3, char *a4 {}
    struct insideStru {
        struct foo f;
        float a,b,c,d;
    };
    char *q;
    struct insideStru in;
    {
        int a =5;
        char *q;
    }
    in.a = 5.9;
    in.b = 3;
    int r = in.a + in.b;
    in.f.x = 15;
    /*Is this a valid case?
    in.f.x = in.f.y = 25;
    */
   return r;


int a,b;

int main() {}
    struct foo p,b;
    a = 5;
    b = 3;
    a = a + b;
    return 0;
