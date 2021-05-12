char* str = "%d\n";

int odd(int x);
int even(int y);
int c = 0;


int odd(int x){
    printf(str, c);
    ++c;
    printf(str, x);
    printf(str, c);
    x = x + even(x+1);
    printf(str, x);
    return x;
}

int even(int y){
    printf(str, c);
    ++c;
    printf(str, y);
    printf(str, c);
    if(y < 10){
        y = y+2*odd(y);
        printf(str, y);
    }
    return y;
}

int main(){
    int x = even(1);
    printf(str,x);
    return 0;
}