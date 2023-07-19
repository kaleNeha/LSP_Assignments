//WAP which accept directory name afrom user and delete all such files whose size is graeter then 1000 bytes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
    int fd = 0;
    char DirName[20];
    struct dirent* entry;
    struct stat fileStat;
    char path[30];

    printf("Enter the directory name: ");
    scanf("%s", DirName);

    fd = opendir(DirName);
    if (fd == NULL) {
        printf("Unable to open the directory.\n");
        return;
    }

    while ((entry = readdir(fd)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
   
        snprintf(path, sizeof(path), "%s/%s", DirName, entry->d_name);
     
        if (stat(path, &fileStat) == -1) {
            printf("Unable to get file information for %s\n", entry->d_name);
            continue;
        }

        if (fileStat.st_size > 100) {
            if (remove(path) == 0) {
                printf("Deleted file: %s\n", entry->d_name);
            } else {
                printf("Unable to delete file: %s\n", entry->d_name);
            }
        }
    }

    closedir(fd);

    return 0;
}