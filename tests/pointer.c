char* str = "%d\n";

int main(){
    int a, *b, *c;
    a = 45;
    printf(str, a);
    b = malloc(sizeof(int));
    *b = 90;
    printf(str, *b);
    *b = a;
    printf(str, *b);
    a = *b;
    printf(str, a);
    return 0;
}