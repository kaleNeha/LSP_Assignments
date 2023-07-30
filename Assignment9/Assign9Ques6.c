//Write a program which is used to Display environment of our running process.
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() 
{
    printf("Environment of the running process:\n");

    for (int i = 0; environ[i] != NULL; i++) 
    {
        printf("%s\n", environ[i]);
    }

    return 0;
}

