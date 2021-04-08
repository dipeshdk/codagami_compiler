struct foo {
    int a,b;
    float *c;
};

int fun(int a, float b){
    a=5;
}

int main() {
    struct hoo{
        struct foo *f;
    };
    struct hoo h;
    float b;
    int a = 5;
    b=(float)a;
    return 0;
} 