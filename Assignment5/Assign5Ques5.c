//WAP which accept file name from user 
//which contains data of all file. we have to craete all file again

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
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;
    struct FileInfo fobj;
    int fd = 0;

    pprintf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",Fname,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            creat(fd,&fobj,sizeof(fobj));
            printf("%s\n",entry->d_name);
        }
    }

    closedir(dp);
    
    return 0;
}