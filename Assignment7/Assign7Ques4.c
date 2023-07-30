//Write a program which create shared function library which internally loads shared library.
//the innner shared library provides the function to calculate the factoroal of number
//Aslo write a program which will load that shared library and call the function
#include <stdio.h>
#include "factsharedfile.h"

int main() 
{
    int num = 5 , result =0;
    result = factorial(num);
    printf("Factorial of %d is: %llu\n", num, result);
    return 0;
    
}
