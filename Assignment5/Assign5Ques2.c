//WAP which accept file name from user which contains information of employee 
//we have to read all contents of that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct Employee
{
    int Rollno;
    char Ename[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee eobj;
    char Fname[20];
    int fd = 0;

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&eobj,sizeof(eobj));

    printf("Roll number : %d : \n",eobj.Rollno);
    printf("Name : %s : \n",eobj.Ename);
    printf("Marks : %f : \n",eobj.Marks);
    printf("Age : %d : \n",eobj.Age);

    close(fd);
}