#include "innerfactsharedfile.h"

int innerfactorial(int inum)
{
     int fact = 1;
     for(i=1;i<=inum;i++)
     {    
          fact=fact*i; 
     }    
     
     return fact;
}

