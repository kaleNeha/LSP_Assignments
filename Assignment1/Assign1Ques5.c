//WAP Which accept file name and number of bytes from user and
//Read that number if bytes from file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    int Bytes = 0;
    char Buffer[20] = {'\0'};
    int Ret = 0;

    printf("Enter your file name that you want to open : \n");
    scanf("%s",Fname);
   
   printf("How many bytes you want to read: \n");
   scanf("%d",&Bytes);

    fd = open(Fname, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
   Ret = read(fd,Buffer,Bytes);

    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n",Buffer);

    return 0;    
}