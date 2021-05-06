void printf(char* str, int x);
char* str = "%d\n";

int odd(int x);
int even(int y);
int c = 0;


int odd(int x){
    ++c;
    printf(str, x);
    x = x + even(x+1);
    return x;
}

int even(int y){
    ++c;
    printf(str, y);
    if(y < 10){
        y = y+2*odd(y);
    }
    return y;
}

int main(){
    int x = even(1);
    printf(str,x);
    return 0;
}