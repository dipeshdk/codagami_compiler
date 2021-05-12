char *str = "%lf\n";

struct foo{
    int x, y;
};

void func(struct foo f) {
    printf(str, 5.6);
    return;
}

int main() {
    struct foo f;
    func(f);
    return 0;
}
