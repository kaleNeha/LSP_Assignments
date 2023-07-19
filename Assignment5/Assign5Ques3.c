//WAP which accept directory name from user 
//and write information of all regular file in and 
//then read the content from that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)


int main(int argc, char *argv[])
{
    struct stat sobj;
    char Fname[20];
    int fd = 0;
    DIR *dp = NULL;
    char Buffer[1024] = {'\0'};

    printf("Enter name of directory :\n");
   scanf("%s",DirName);

    dp= opendir(DirName);
    
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return -1;
    }

     while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            read(name,sizeof(Buffer));
        }
    }
     
    close(fd);

    return 0 ;
}