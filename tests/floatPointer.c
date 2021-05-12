char* str = "%f\n";

int main(){
    double a = 236789.137, b = 19672349.928, c = 58492.83821, d, e, f, g;
    double* i, *j, *k;
    i = &a;
    j = malloc(sizeof(double));
    *j = b;
    printf(str, *i);
    printf(str, *j);
    printf(str, c);
    d = (*i)+(*j);
    printf(str, d);
    e = c-(*j);
    printf(str, e);
    f = (*i)/c;
    printf(str, f);
    g = (*i)*c;
    printf(str, g);
    d = (*i)*(*j)/c+d-e;
    printf(str, d);
    return 0;
}