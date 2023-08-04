//Write a program which creates multiple threads & sets its thread attributes accrodingly

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
   printf("Thread %ld is running\n", (int)ptr);
}


int main()
{
    pthread_t TID;
    int result;
    int ret1;
    int i = 0;
    int numthread = 5;

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
    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}