//WAP which is used to create shared library n that library should be loaded at runtime by the other program
//that library should contains function which accepts 2 file names from user and it will compare that contents of that file

#include <stdio.h>
#include "ques2sharedfile.h"

int main() 
{
    char Fname[20];
    char Sname[20];
    //ret = 0;
    char result[20]

    printf("Enter First file name : \n");
    scanf("%s",Fname);

    printf("Enter Second file name : \n");
    scanf("%s",Sname);

    result = filecompare(Fname,Sname);

    if(result == "Same")
    {
        printf("Both files are same\n");
    }
    else
    {
        printf("Both files are diffrent\n");
    }
    
    return 0;
}
