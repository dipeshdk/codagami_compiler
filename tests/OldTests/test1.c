int gl = 10;

int foo() {
    return 5;
}

int bar() {
    gl++;
    return gl + 5;
}

int main(){
    int a;
    int d[11];
    for(a = 5; a < 10; a++) {
        if(a < 6) d[a] = foo();
        else d[a] = bar();
    }

    return 0;
}