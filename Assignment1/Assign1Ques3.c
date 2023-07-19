//WAP Which accept file name and Mode that program 
//check whether our process can access taht file in accepted mode or not 

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    char Fmode[20];
    int mode =0 ;
    struct stat sobj;
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
    
    if(access(Fname,mode)<0)
    {
        printf("unable to access %s file in %d mode \n ",Fname,mode);
    
    }
    else
    {
        printf("you can access %s file in %dd mode \n ",Fname,mode);
    
    }
    return 0;
}