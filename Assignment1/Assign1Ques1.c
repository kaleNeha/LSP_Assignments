//WAP Which accept file name from user and Open that file

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;

    printf("Enter your file name that you want to open : \n");
    scanf("%s",Fname);

    fd =  open(Fname, O_RDONLY);

    if(fd ==-1)
    {
        printf("Unble to open your file \n");
        return -1;
    }
    else{
        printf("Your file open succesfully %d \n",fd);
    }

    return 0;
}