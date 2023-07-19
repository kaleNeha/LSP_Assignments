//WAP which accept file name
//which contains data of all file. we have to print all file name whose size is greater that 10 bytes

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    char fname[20];
    char currentFileName[20];
    int fileSize = 0;
    int fd = 0;

    printf("Enter the name of the file: ");
    scanf("%s", fname);

    fd = fopen(fname, "r");
    if (fd == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

     
    while (fscanf(fd, "%s %d", currentFileName, &fileSize) == 2) {
        if (fileSize > 10) {
            printf("%s\n", currentFileName);
        }
    }

    fclose(fd);

    return 0;
}
