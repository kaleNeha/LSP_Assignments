//WAP which is used to create 2 shared library n that library should be loaded at runtime by the other program
//First library should contains function to check wheher the input member is prime or not
//Second library should contains function to check whether the input member is perfect or not

#include <stdio.h>
#include "primesharedfile.h"
#include "perfectsharedfile.h"

int main() 
{
    int iValue1 = 0 ,iValue2 = 0 , result =0 , ret=0;

    printf("Enter First Value : \n");
    scanf("%d",iValue1);

    printf("Enter Second Value : \n");
    scanf("%d",iValue2);

    result = prime(iValue1);
    ret = perfect(iValue2);

    if(result == 0)
    {
        printf("The number is a prime Number\n");
    }
    else
    {
        printf("The number is a  not prime Number\n");
    }

    if(ret == 0)
    {
        printf("The number is a Perfect Number\n");
    }
    else
    {
        printf("The number is a not Perfect Number\n");
    }
    
    return 0;
}
