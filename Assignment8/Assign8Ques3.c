//WAP which creates three different processes internally as process2,process3,process4

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main() 
{
    int p2, p3, p4;

    p2 = fork();

    if (p2 == 0) {
        
        p3 = fork();

        if (p3 == 0) {
            
            p4 = fork();

            if (p4 == 0) 
            {
               
                printf("Process 4 (PID: %d) is running.\n", getpid());
                
                printf("Process 4 is done.\n");
                exit(EXIT_SUCCESS);
            } 
            else 
            {
                
                printf("Process 3 (PID: %d) is running.\n", getpid());
                
                wait(NULL);
                printf("Process 3 is done.\n");
                exit(EXIT_SUCCESS);
            }
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
        
        printf("Process 1 (Parent) (PID: %d) is running.\n", getpid());
        
        wait(NULL);
        printf("Process 1 (Parent) is done.\n");
    }

    return 0;
}

