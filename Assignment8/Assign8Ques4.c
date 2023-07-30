//WAP which creates 2 processes as process2 and process3 and our parent process terminates till both the processes terminates

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main() 
{
    pid_t p2, p3;
    int status;

    p2 = fork();

   if (p2 == 0) 
   {       
        printf("Process 2 (PID: %d) is running.\n", getpid());
        
        sleep(2);
        printf("Process 2 is done.\n");
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        
        p3 = fork();

        if (p3 == 0) 
        {
            
            printf("Process 3 (PID: %d) is running.\n", getpid());
            
            sleep(3);
            printf("Process 3 is done.\n");
            exit(EXIT_SUCCESS);
        } 
        else
        {           
            waitpid(p2, &status, 0);
            waitpid(p3, &status, 0);

            printf("Parent process is done.\n");
        }
    }

    return 0;
}
