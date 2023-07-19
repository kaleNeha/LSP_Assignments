//WAP Which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as demo.txt

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
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;

    char Buffer[1024] = {'\0'};

    char Fname[20];
    char Fname1[20];
    printf("Enter your file name \n");
    scanf("%s",Fname);
    printf("Enter your second file name \n");
    scanf("%s",Fmode1);

    fdSource = open(Fname,O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fdDest = write(Fmode1,0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);;

    close(fd);
    return 0;
}
