//WAP which is used to create shared library n that library should be loaded at runtime by the other program
//that library should contains function to perform the arithmatic operations like
//Addition,Substraction,Division,Multiplication

#include <stdio.h>
#include "ques1sharedfile.h"

int main() 
{
    int a= 10,b = 11 ;
    int AddResult = 0 ,SubResult = 0,DivResult = 0,MultiResult =0;

    AddResult = Addition(a,b);
    SubResult = Substraction(a,b);
    DivResult = Division(a,b);
    MultiResult = Multiplication(a,b);

    printf("Addition is : %d\n",AddResult);
    printf("Substraction is : %d\n",SubResult);
    printf("DivResult is : %d\n",DivResult);
    printf("Multiplication is : %d\n",MultiResult);
    
    return 0;
}
