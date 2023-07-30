//WAP in create three level process hierarchy where process 1,
//creates process 2 and it internally creates process 3

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main() 
{
    int p1, p2;
    
    p1 = fork();

    if (p1 == 0) 
    {      
        p2 = fork();

       if (p2 == 0) 
       {
            
            printf("Process 3 (PID: %d) is running.\n", getpid());
            
            printf("Process 3 is done.\n");
            exit(EXIT_SUCCESS);
        } 
        else 
        {
            
            printf("Process 2 (PID: %d) is running.\n", getpid());
            
            wait(NULL);
            printf("Process 2 is done.\n");
            exit(EXIT_SUCCESS);
        }
    } 
    else 
    {
       
        printf("Process 1 (PID: %d) is running.\n", getpid());
        
        wait(NULL);
        printf("Process 1 is done.\n");
    }

    return 0;
}
