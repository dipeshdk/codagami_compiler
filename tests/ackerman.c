char* str = "%d\n";

int ack(int m, int n)
{
    if (m == 0){
        m = n+1;
        printf(str, m);
    }
    else if((m > 0) && (n == 0)){
        printf(str, 900087);
        return ack(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        printf(str, 900088);
        return ack(m-1, ack(m, n-1));
    }
}

void fov(int x) {
    printf(str,x);
    x = 5;
    return;
} 

int goo() {
    int f = 90;
    printf(str,6709867);
    return f;
}
  
int main(){
    int A;
    A = ack(2, 3);
    printf(str, A);
    fov(68);
    A=goo();
    printf(str,A);
    fov(A);
    printf(str, goo());
    return 0;
}