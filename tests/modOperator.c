int main(){
    int a = 10, b= 12323,c = 29831924;
    float f = 2413.123, g = 6756.342;
    
    b = c % b;
    a = c % b;
    printf("%d, %d\n", a, b);

    f = c % a;
    g = ((b % c) % a) % 121;
    printf("%lf, %lf\n", f, g);
    return 0;
}