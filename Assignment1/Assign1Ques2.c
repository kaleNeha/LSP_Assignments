//WAP Which accept file name and Mode from user and Open that file in specific mode

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    char Fmode[20];
    int mode =0 ;

    printf("Enter your file name that you want to open : \n");
    scanf("%s",Fname);
    printf("Enter the mode which you like to open your file: \n");
    scanf("%s",Fmode);

    if( strcmp(Fmode,"read") == 0 )
    {
        mode = R_OK;   
    }
        else if( strcmp(Fmode,"write") == 0 )
    {
        mode = W_OK;  
    }
        else if( strcmp(Fmode,"execute") == 0 )
    {
        mode = X_OK;  
    }
   
    fd =  open(Fname, mode);

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