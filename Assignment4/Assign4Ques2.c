//WAP Which accept directory name and create new directory of thst name

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    int Ret = 0;

    printf("Enter name of directory :\n");
    scanf("%s",DirName);

    Ret = mkdir(DirName,0777);
    if(Ret == 0)
    {        
         printf("File is craeted succesfully \n");
    } 
    else
    {       
         printf("Unable to open the directory\n");
    }

    return 0;
}
