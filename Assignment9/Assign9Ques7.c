//Write a program which is used to print home directory ang login user name
#include <stdio.h>
#include <stdlib.h>

int main() 
{

    char *homeDir = getenv("HOME");
    if (homeDir != NULL) {
        printf("Home Directory: %s\n", homeDir);
    } 
    else 
    {
        printf("Home Directory not found.\n");
    }

    char *userName = getenv("USER");
    if (userName != NULL) 
    {
        printf("Login User Name: %s\n", userName);
    } 
    else 
    {
        printf("Login User Name not found.\n");
    }

    return 0;
}

