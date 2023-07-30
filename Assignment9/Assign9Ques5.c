//Write a program which is used to yield our processor bu using appropriate system call
#include <stdio.h>
#include <sched.h>

int main() 
{
    int Result = 0;
    printf("Starting the yield program.\n");

    Result = sched_yield();

    if (Result == 0) {
        printf("Processor yielded successfully.\n");
    } 
    else 
    {
        perror("Error in yielding processor");
        return 1;
    }

    printf("Program completed.\n");

    return 0;
}

