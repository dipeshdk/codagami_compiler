int main() {
    int sigraise = 10;
    int rand1 = rand();
    int rand2 = rand_r();
    int sigRetVal;
    printf("rand() val = %d\n", rand1);
    printf("rand_r() val = %d\n", rand1);
    /* sigRetVal = raise(sigraise);
    printf("signal raise return value = %d\n", sigRetVal); */
    return 0;
}