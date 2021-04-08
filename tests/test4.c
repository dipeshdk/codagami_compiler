/*invalid struct use
*/ 

struct foo{
    int x,y;
    float b;
};

int main() {
    struct foo s;
    s.b="abcd";
    s.z=5;
    return 0;
}