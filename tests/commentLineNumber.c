void printf(char* str, int x);
char* str = "%d\n";

int main(){
    int a, x;
    a = 10;
    printf(str, a);
    /*hfhd
    dhfihdif
    dhfhadfdhf
    error will be generated in this test case
    */
    a = 1 ? 3 : 5 == 6 ? 7 : 8;
    printf(str, a);
    return 0;
}