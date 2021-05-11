void printf(char* str, double x);
char* str = "%d\n";

struct foo{
    int x;
};

void func(struct foo f) {
    printf(str, f.x);
    return;
}

int main(){
    struct foo f;
    f.x=5;
    func(f);
    return 0;
}