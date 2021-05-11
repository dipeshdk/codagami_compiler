void printf(char* str, int x);
char* str = "%d\n";

/* int g = 6; */
float q = 91.5;
float p = 91.0;
int main() {
    float pp = 90.0;
    float pq = 91.0;
    int a;

    

    a = 6.0 < pp;
    if(a) printf(str, 901);
    else printf(str, 900);
 
    a = pp < 6.0;
    if(a) printf(str, 901);
    else printf(str, 900);
 

    /* a = pp < 6.0; */
    /* a = 6.0 < pp;
    /* a = 6.0 < 7.0; */
    /* if(a) printf(str, 901);
    else printf(str, 900); */
    return 0;
}