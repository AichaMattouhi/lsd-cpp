
#include <stdio.h>
#include <stdlib.h>

void  check_msb (int num)

{
 
 
    if ((num >>8*sizeof(int)-1& 1)==1)
       printf("1\n");
    else 
       printf("0\n");
   

  
}


