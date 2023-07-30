#include "primesharedfile.h"

int prime(int N);
{
    int count = 1;

    for(int i = 2 ; i <= N/2 ; i++)
    {
        if(N % i == 0)
        {
            count = 1;
            break;
        }
    }

    return count;
}

