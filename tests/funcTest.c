int foo(int a, char b){
    int x,y;
    {char g;
    x = a * b + g;
    }
    y = a * b ;
    return y;
}

int main(){
    int x, y;
    float g;
    char k;
    y = 0;
    foo(g,k);
    x = 0;
    return 0;
}