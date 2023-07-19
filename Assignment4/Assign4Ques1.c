//WAP Which is used to demonstrate concept I/O redirection

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char path[50] = {'\0'};

    printf("Enter name of directory :\n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    } 
    else
    {
        printf("UFile is created succesfully\n");
    }

    closedir(dp);
    return 0;
}
