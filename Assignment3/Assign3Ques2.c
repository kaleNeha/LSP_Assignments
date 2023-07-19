//WAP Which accept directory name and file name from user 
//and check whether the file is present inthat directory or not

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
    char fname[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;

   printf("Enter name of directory :\n");
   scanf("%s",DirName);

   printf("Enter name of File :\n");
   scanf("%s",fname);

    dp= opendir(DirName);
    
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        if((strcmp(fname,entry->d_name)) == 0)
        {
            printf("File is present in directory");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
   
    closedir(dp);

    return 0;    
}
