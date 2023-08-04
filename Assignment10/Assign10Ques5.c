//Write a program which is used to get thread id inside its thread function

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
  printf("Inside Thread function Id = %d",pthread_self());
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