//WAP Which writes structure in file, structure should contains information of student

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;

    sobj.Rollno = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 25;
    strcpy(sobj.Sname,"Marvellous");

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&sobj,sizeof(sobj));

    return 0;
}