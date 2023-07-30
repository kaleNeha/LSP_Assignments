//Write a program which is used to increase the priority by 5

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() 
{
    int oldpriority, newpriority;

    oldpriority = getpriority(PRIO_PROCESS, getpid());

    printf("Old priority: %d\n", oldpriority);

    newpriority = oldpriority - 5;

    if (setpriority(PRIO_PROCESS, getpid(), newpriority) == -1) 
    {
        perror("Error setting priority");
        return -1;
    }

    newpriority = getpriority(PRIO_PROCESS, getpid());

    printf("New priority: %d\n", newpriority);

    return 0;
}
