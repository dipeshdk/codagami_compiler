int main(){
    char a = 'a',b = 'b',c = 'c';
    char ch1, ch2, ch3;
    int x,y,z;

    x = toascii(a);
    y = toascii(b);
    z = toascii(c);

    printf("ASCII value of %c = %d\n", a, x);
    printf("ASCII value of %c = %d\n", b, y);
    printf("ASCII value of %c = %d\n", c, z);

    a = 'y',b = 'h',c = 't';
    ch1 = toupper(a);
    ch2 = toupper(b);
    ch3 = toupper(c);

    printf("Uppercase of %c = %c\n", a, ch1);
    printf("Uppercase of %c = %c\n", b, ch2);
    printf("Uppercase of %c = %c\n", c, ch3);

    a = 'A', b = 'Z', c = 'V';
    ch1 = tolower(a);
    ch2 = tolower(b);
    ch3 = tolower(c);

    printf("Lowercase of %c = %c\n", a, ch1);
    printf("Lowercase of %c = %c\n", b, ch2);
    printf("Lowercase of %c = %c\n", c, ch3);
    
    return 0;
}