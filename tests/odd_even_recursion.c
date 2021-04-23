int odd(int x);
int even(int y);

int odd(int x){
    x = x+even(x);
    return x;
}

int even(int y){
    if(y < 10000) y = y+2*odd(y);
    return y;
}

int main(){
    even(1);
    return 0;
}