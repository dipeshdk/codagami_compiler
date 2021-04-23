void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            ++i;
         while(number[j]>number[pivot])
            --j;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int  count, number[25];

   count = 5;
   number[0]=88;
   number[1]=-9;
   number[2]=90;
   number[3]=5;
   number[4]=20;

   quicksort(number,0,count-1);

   return 0;
}