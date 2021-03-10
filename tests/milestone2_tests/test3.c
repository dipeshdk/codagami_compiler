struct foo {
    int x;
    double y;    
};

int main() {
    struct foo* z = (struct foo*)malloc(sizeof(foo));
    foo->x;
}