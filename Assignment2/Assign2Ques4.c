//WAP Which accept directory name from user and print all file names and its type from that directory

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
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;

   printf("Enter name of directory :\n");
   scanf("%s",DirName);

    dp= opendir(DirName);
    
    if(dp == NULL)
    {
        printf("Unable to open directory");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        printf("%s\n",entry->d_name);
        scanf(name,"%s/%s",DirName,entry->d_name);
        printf("%s\n",name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            printf("File name : %s\n",name);
            printf("Regular File");          
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("File name : %s\n",name);
            printf("Its a directory\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("File name : %s\n",name);
            printf("Its a symbolic link\n");
        }
    }

    return 0;    
}
