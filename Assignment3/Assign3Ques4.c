//WAP Which accept directory name from user 
//and Delete All empty file from that directory

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

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            sprintf(path,"%s/%s",DirName,argv[2]);
            remove(path);
            printf("File is succesfully deleted\n");
            break;
        }
    }

    closedir(dp);
    return 0;
}
