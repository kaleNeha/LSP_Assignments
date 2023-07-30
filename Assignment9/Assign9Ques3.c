//Write a program which is used to print proproty of process
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() 
{
   
    int priority = getpriority(PRIO_PROCESS, getpid());

    if (priority == -1) 
    {
        printf("Error getting priority");
        return  -1;
    }

    printf("Process priority: %d\n", priority);

    return 0;
}
