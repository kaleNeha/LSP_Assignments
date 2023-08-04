//Write a program which creates simple thread 
//it accept one value from user and it return some value to the caller thread 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
  printf("Value received from main thread is : %d\n",(int)ptr);
   pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int No 0;

    printf("Enter your number \n");
    scanf("%d",&No);

    ret = pthread_create(&TID,            
                          NULL,           
                          ThreadProc,     
                          (int *)No);     

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID);
  
    return 0;
}