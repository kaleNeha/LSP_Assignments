#include <stdio.h>
#include <sys/stat.h>
#include "infosharedfile.h"

void displayinfo(char *filename)

{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    stat(filename,&sobj);

    printf("File name : %s\n",filename);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);

    return 0;
     
}

