//WAP Which accept 2vdirectory name from user 
//and move all files from source directory to destination directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char SourceDirName[20];
    char DestinationDirName[20];
    struct dirent *entry = NULL;
    DIR *dp = NULL;

   printf("Enter name of Source directory :\n");
   scanf("%s",SourceDirName);

   printf("Enter name of Destination directory :\n");
   scanf("%s",DestinationDirName);

    dp = opendir(SourceDirName);
    if(dp == NULL)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        printf(SourceDirName,"%s/%s",argv[1],entry->d_name);
        printf(DestinationDirName,"%s/%s",argv[2],entry->d_name);

        rename(SourceDirName,DestinationDirName);
    }

    return 0;    
}
