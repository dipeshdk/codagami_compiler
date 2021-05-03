void scanf(char c, int d);
void printf(char *c, int d); 
char *p = "%ld\n\0";

int gVar = 5+40;
gVar=50;
int main() {
    int x = -9+4-4/18*'a';
    
    scanf(p,&gVar);
    printf(p,gVar);
    printf(p,gVar);

    return 0;
}