int main(){
    int a = 10, b = 343;
    float f = 10.43783,  g = 23.23;
    printf("f = %lf\n", f);
    switch(a){
        case 10:{
            printf("10: val = %d\n", a);
            break;
        }
        case 12:{
            printf("12: val = %d\n", a);
            break;
        }
        case 13:{
            printf("13: val = %d\n", b);
            break;
        }
        default:
            printf("default case: val = %d\n", a);
    }
    return 0;
}