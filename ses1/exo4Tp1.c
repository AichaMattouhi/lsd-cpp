

#include <stdio.h>
#include <stdlib.h>




void print_nth_byte (int n , int m)

{

  
      for(int i =n*8 ;i>=(n-1)*8 ;i--)
    {
       if((m >>i)&1==1)
        printf("1");
       else
        printf("0");
 
    }
    printf("\n");
}

int main ()
{
   print_nth_byte (2, 17161);
   return 0;
   
 }
 
  
  
