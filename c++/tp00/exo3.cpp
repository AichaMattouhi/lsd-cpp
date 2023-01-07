#include <iostream.h>
#include <algorithm>
using namespace std;

struct  node {

    int data ;
    struct node* next;
    
    
              };
              
typedef struct node node ;
typedef struct node* stack ;


stack push (int x , stack* L)
{
 
    stack p = new node; 
    p->data = x;
    p->next =*L;
    *L=p;
    return L;
    
 }
 
 
void remove_duplicates(stack *p)

{   node ptr1,ptr2;
   ptr1=*p;
   while(ptr1!=NULL  && ptr1->next!=NULL)
   { ptr2=ptr1;
     while(ptr2->next!=NULL)
     {
       if (ptr2->next->data=ptr1->data)
         { dup=ptr2->next;
          ptr2->next=ptr2->next->next;
          free(dup);
         }
      else 
         ptr2=ptr2->next;
         
     }
     
     ptr1=ptr1->next;
   }
}
 
 
void PRINT(stack P)
{
    stack temp=P;
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    if(temp!=NULL)
        printf("%d\n",temp->data);
}
