//WAP Which accept 2 file name and copy the contents of an existing into newly craeted file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};
int main(int argc, char *argv[])
{
    char Fname[20];
    char Fname1[20];
    int fd = 0;
    int fd1 = 0;
    char name[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL; 
    struct FileInfo fobj;
    struct stat sobj;

    printf("Enter your file name : \n");
    scanf("%s",Fname);
 
     
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    fd1 = creat("FileCombine.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        printf(name,"%s/%s",Fname,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            printf("%s\n",entry->d_name);
        }
    }

    return 0;
}
