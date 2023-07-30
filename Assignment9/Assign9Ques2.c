//Write a program which creates two processes 
//process 1 count number of capital charachters from demo.txt file.
// process 2 count number of capital charachters from hello.txt file.
//both the processes writes its count in Count.txt file
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main()
{
    int p1, p2;
    int fd = 0, fd1 = 0;
    int count =0 , count1 = 0;
    int ch;

    
    p1 = fork();

    if (p1 == 0) 
    {
       
        fd = open("demo.txt", "r");
        
        while ((ch = getc(fd)) != EOF) 
        {
            if (isupper(ch)) {
                count++;
            }
        }
    
        fd1 = open("count.txt", "w");
       
        printf(fd1, "Count from process 1: %d\n", count);
        close(fd1);

        exit(EXIT_SUCCESS);
    }

  
    p2 = fork();

   if (p2 == 0) 
   {
       
        fd1 = open("demo.txt", "r");
        
        while ((ch = getc(fd1)) != EOF) 
        {
            if (isupper(ch)) {
                count1++;
            }
        }
    
        fd1 = open("count.txt", "w");
       
        printf(fd1, "Count from process 2: %d\n", count1);
        close(fd1);

        exit(EXIT_SUCCESS);
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    return 0;
}
