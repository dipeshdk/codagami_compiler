#define NUMB 5

#ifdef NUMB
#define SOME_VALUE 12
#else
#define SOME_VALUE 14
#endif

int main() {
    printf("%d\n", NUMB);
    printf("%d\n", SOME_VALUE);
    return 0;
}