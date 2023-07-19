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

    printf("string you want to add in file: \n");
    scanf("%s",Buffer);
   
    fd = open(Fname, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);
    }
    

    printf("Data from file is : %s\n",Buffer);

    return 0;    
}
