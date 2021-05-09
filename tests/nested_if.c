void printf(char* s, int x);
char* str = "%d\n";

int main() {
    int a = 3,b = 2,c = 0;
    char p,q,r;
    
    if(a == b){
      if(c == 0){
          printf(str, 890);
        p = 'a';
      }
      else if(c == 1){
          printf(str, 891);
        q = 'a';
      }
      else{
          printf(str, 892);
        r = 'b';
      }
    }

    if(!c){
      if(a){
        if(a == p*c + b){
            printf(str, 893);
          return 0;
        }
        else{
            printf(str, 894);
          a == p*c + b + 1;
        }
      }
    }
    return 0;
}