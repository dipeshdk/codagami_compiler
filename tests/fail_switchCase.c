int main(){
    int a = 10, b = 343;
    float f = 10.43783,  g = 23.23;
    printf("f = %lf\n", f);
    switch(a){
        case 10:{
            printf("val = %d\n", a);
        }
        case 12:{
            printf("val = %d\n", a);
        }
        case b:{
            printf("B case: %d\n", b);
        }
        default:
            printf("default case: val = %d\n", a);
    }
    return 0;
}