char* str = "%f\n";

int main(){
    double a, b, c;
    a = 89/2.0;
    printf(str, a);
    a = 89.0/2;
    printf(str, a);
    a = 89/2;
    printf(str, a);
    return 0;
}