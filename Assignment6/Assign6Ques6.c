//WAP which accept directory name from user and create hole in file 
//if size is less then 1 kb & it is greater 
//then 1 kb then truncate the remaining data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int fd1 = 0;
    char fname[20];
    char path[20];
    struct dirent* entry;
    struct stat fileStat;

    printf("Enter the directory name: ");
    scanf("%s", fname);

    fd = opendir(fname);
    if (fd == NULL) {
        printf("Unable to open the directory.\n");
        return;
    }
   
    while ((entry = readdir(fd)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; 
        }

        snprintf(path, sizeof(path), "%s/%s", fname, entry->d_name);

        if (stat(path, &fileStat) == -1) {
            printf("Unable to get file information for %s\n", entry->d_name);
            continue;
        }
    
        if (fileStat.st_size < 1024) {
            fd1 = fopen(path, "r+");
            if (fd1 == NULL) {
                printf("Unable to open the file: %s\n", entry->d_name);
                continue;
            }

            fseek(fd1, 0, SEEK_END);

            long holeSize = 1024 - fileStat.st_size;

            for (long i = 0; i < holeSize; i++) {
                fputc('\0', fd1);
            }

            fclose(fd1);

            printf("Hole created in file: %s\n", entry->d_name);
        } else {
            if (truncate(path, 1024) == -1) {
                printf("Unable to truncate the file: %s\n", entry->d_name);
                continue;
            }

            printf("File truncated: %s\n", entry->d_name);
        }
    }

    closedir(fd);

    return 0;
}