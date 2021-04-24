int ack(int m, int n)
{
    if (m == 0){
        m = n+1;
    }
    else if((m > 0) && (n == 0)){
        return ack(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ack(m-1, ack(m, n-1));
    }
}

void fov(int x) {
    x = 5;
    return;
} 

int goo() {
    int f;
    return f;
}
  
int main(){
    int A;
    A = ack(1, 2);
    fov(68);
    A=goo();
    fov(A);
    goo();
    return 0;
}