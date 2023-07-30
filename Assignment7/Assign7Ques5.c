//Write a program which create static library which contains file name from user 
//and which display the information of that file
#include <stdio.h>
#include "infosharedfile.h"

int main() 
{
    char filename[20];
    
    printf("Enter your file name: ");
    scanf("%s", filename);
 
    displayinfo(filename);

    return 0;
    
}
