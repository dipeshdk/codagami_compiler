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
    if(b == foo(2) && c == b){
        d = 6;
    }
    if(b == c || bar(12) == d){
        b = 34.90;
    }
}