char* str = "%d\n";

int fibonacci(int n){
    int prev = 0;
    int curr = 1;
    int fib = 0;
    int i = 0;
    printf(str, n);
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    for(i = 2; i <= n; ++i){
        fib = prev + curr;
        prev = curr;
        curr = fib;
        printf(str,fib);
        printf(str,curr);
        printf(str,prev);
    }
    return fib;
}

int main(){
    int n = 100;
    int fib = fibonacci(n);
    printf(str, fib);
    return 0;
}