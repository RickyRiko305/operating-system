#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include <semaphore.h>
int data =10;
 

sem_t sem;
int addit(){
    
   sem_init (&sem,0,1);
   sem_wait(&sem);
  
   data += 10;
   sem_post(&sem);
   printf("after add val = %d\n",data);
}
int subtr(){
   
   sem_init (&sem,0,1);
   sem_wait(&sem);
  
   data -= 5;
   sem_post(&sem);
   printf("after sub val = %d\n",data);
}

int main(){
    
    pthread_t t1,t2;
    printf("inti val = %d\n",data);
    pthread_create(&t1, NULL, (void *)addit, NULL);

    sleep(1);
    pthread_create(&t2, NULL, (void *)subtr, NULL);

    sleep(1);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

return 0;
}
