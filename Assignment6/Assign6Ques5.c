//WAP which accept directory name afrom user and offset , remove all the data from that offset

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int fd = 0;
    char fname[20];
    int offset;

    printf("Enter the file name: ");
    scanf("%s", fname);

    printf("Enter the offset: ");
    scanf("%d", &offset);

    fd = fopen(fname, "r+");
    if (fd == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    fseek(fd, offset, SEEK_SET);

    if (ftruncate(fileno(fd), ftell(fd)) == -1) {
        printf("Unable to truncate the file.\n");
        fclose(fd);
        return 1;
    }

    fclose(fd);

    printf("Data removed successfully from the specified offset.\n");

    return 0;
}