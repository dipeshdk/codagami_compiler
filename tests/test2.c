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
    struct foo arr[2];
    f.x=5;
    func(f);
    return 0;
}