void printf(char* str, int x);
char* str = "%d\n";

/* int g = 6; */
float f1 = 8.906453;
float f2 = 9088.77;
int main() {
    float pp = 66.6;
    float pq = 90.0;
    int a;

    a =  pp < pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  pp < f1;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  f1 < pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a = f1 < f2;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  pp <= pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  pp <= f1;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  f1 <= pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a = f1 <= f2;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  pp > pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  pp > f1;
    if(a) printf(str, 901);
    else printf(str, 900);

    a =  f1 > pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    a = f1 > f2;
    if(a) printf(str, 901);
    else printf(str, 900);
 
    /* a = 6.0 < pp;
    if(a) printf(str, 901);
    else printf(str, 900);
 
    a = pp < 6.0;
    if(a) printf(str, 901);
    else printf(str, 900); */
 

    /* a = pp < 6.0; */
    /* a = 6.0 < pp;
    /* a = 6.0 < 7.0; */
    /* if(a) printf(str, 901);
    else printf(str, 900); */
    return 0;
}