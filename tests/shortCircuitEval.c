int foo(int x){
    return x;
}
float bar(float x){
    return x;
}
int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    if(a == 1){
        d = 5;
    }
    if(b == foo(2) + c && c != b + d){
        d = 6;
    }
    a = 10;
    if(b + d <= c - a|| bar(12) >= d /a){
        b = 34;
    }

    a = b && c;
    a = b + d + c  || a - b;
}