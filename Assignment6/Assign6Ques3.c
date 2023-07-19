//WAP which accept directory name and file name from user and create file in that directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char DirName[20];
    char fname[20];
    char path[20];
    int fd = 0;

    printf("Enter the directory name: ");
    scanf("%s", DirName);

    printf("Enter the file name: ");
    scanf("%s", fname);
    strcpy(path, DirName);
    strcat(path, "/");
    strcat(path, fname);

    fd = fopen(path, "w");
    if (fd == NULL) {
        printf("Unable to create the file in the specified directory.\n");
        return 1;
    }

    fclose(fd);

    printf("File created successfully in the specified directory.\n");

    return 0;
}
