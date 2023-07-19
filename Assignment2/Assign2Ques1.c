//WAP Which accept file name from user and read whole file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    char *Buffer=NULL;
    int Ret = 0;
    int Size=0;

    printf("Enter your file name that you want to open : \n");
    scanf("%s",Fname);
   
    fd = open(Fname, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }


    //Size = atoi(argv[2]);

    Buffer = (char *)malloc(atoi(argv[2]));

    Ret = read(fd,Buffer,sizeof(Fname));

    if(Ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n",Buffer);

    return 0;    
}