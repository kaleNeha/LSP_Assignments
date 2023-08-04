//Write a program which creates two thread , 
//and by using appropriate synchronization technique avoid the scheduling problem

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

#define numthread 2
#define Increments 100
int counter = 0;

void * ThreadProc(void *ptr)
{
   for (int i = 0; i < Increments; i++) {
        counter++;
    }
    return NULL;  
}

int main()
{
    pthread_t TID;
    int ret1 = 0, ret2 = 0;

    for (i = 0; i < numthread; i++) 
    {
      ret1 = pthread_create(&TID[i],       
                            NULL,       
                            ThreadProc, 
                            NULL);  
    } 
    
    for (i = 0; i < numthread; i++) 
    {
          int result = pthread_join(TID[i], NULL);
          if (result != 0) {
              printf("Error joining thread %ld\n", i);
              exit(EXIT_FAILURE);
          }
    }
   
     printf("Expected counter value: %d\n", numthread * Increments);
    printf("Actual counter value: %d\n", counter);
    
    
    pthread_exit(NULL);
    return 0;
}