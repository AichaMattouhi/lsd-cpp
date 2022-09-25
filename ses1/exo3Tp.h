




#include <stdio.h>
#include <stdlib.h>




//fonction that checks if the  msb is set or not
void  check_msb (int num);

//fonction that takes a byte , and prints it in binary
void printBits ( unsigned char byte);



void  check_msb (int num)

{
 
 
    if ((num >>8*sizeof(int)-1 & 1)==1)
       printf("1\n");
    else 
       printf("0\n");
   

  
}


void printBits ( unsigned char byte)
{
      for(int i =sizeof(unsigned char)*8-1 ;i>=0;i--)
    {
       if((byte >>i)&1==1)
        printf("1");
       else
        printf("0");
 
    }
    printf("\n");
}


