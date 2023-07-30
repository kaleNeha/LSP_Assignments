//WAP in which parent process waits till its childs process treminates
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
    int Ret = 0;
    int status,exit_status;
    Ret = fork();

     if(Ret == 0)    //Child
    {
        printf("Child process is done.\n");
    }
    else
    {           
        wait(&status);

        if (WIFEXITED(status)) 
        {
           
            exit_status = WEXITSTATUS(status);
            printf("Child process terminated with exit status: %d\n", exit_status);
        } 
        else 
        {
           
            printf("Child process terminated abnormally.\n");
        }

        printf("Parent process is done.\n");

    }
    
    return 0;
}
