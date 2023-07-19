//WAP which create hole of size 1kb at the end of file.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{

    int fd = 0;

    fd = fopen("example.txt", "a");

    if (fd == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    fseek(fd, 1024, SEEK_CUR);

    fputc('\0', fd);

    fclose(fd);

    printf("Hole created successfully!\n");

    return 0;
}
