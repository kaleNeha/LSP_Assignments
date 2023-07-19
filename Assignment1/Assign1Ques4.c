//WAP Which accept file name from user and
//print all information about that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    char Fname[20];

    printf("Enter your file name that you want to open : \n");
    scanf("%s",Fname);
   
    stat(Fname,&sobj);

    printf("File name : %s\n",Fname);
    printf("File size is : %d\n",(int)sobj.st_size);
    printf("Number of links : %d\n",(int)sobj.st_nlink);
    printf("Inode number : %d\n",(int)sobj.st_ino);
    printf("File system number : %d\n",(int)sobj.st_dev);
    printf("Number of blocks : %d\n",(int)sobj.st_blocks);

    return 0;    
}