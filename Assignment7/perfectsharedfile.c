#include "perfectsharedfile.h"

int perfect(int N);
{
   int rem = 0,sum = 0,ans = 1;

   for (int i = 1 ; i < N ; i++)
   {
        rem = N%i ;
        if(rem == 0)
        {
            sum =sum +i ;
        }
   }

   if(sum == N)
   {
    return 0;
   }
   else
   {
    return 1;
   }  
}

