//WAP Which accept directory name from user and read 20b bytes from that position

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
     int fd = 0,ret = 0;
    char Arr[20];
    char Fname[20];
    char Fname1[20];
    printf("Enter your file name \n");
    scanf("%s",Fname);
    printf("Enter your second file name \n");
    scanf("%s",Fmode1);

    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    ret = read(fd,Arr,20);

    printf("Data from file is \n");
    write(1,Arr,ret);

    close(fd);
    return 0;
}
