#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include <semaphore.h>
#define for(i,b) for(int i=0; i<b; i++)
int a=0,b=0;
sem_t sem1,sem2;
void A(){
    //sem_init (&sem,0,1);
    for(i,10){
      sem_wait(&sem1);    
      a=1;
      printf("A");
      sem_post(&sem2);
    }

}

void B(){
  //sem_init (&sem,0,1);
   
    for(i,10){
     sem_wait(&sem2);
     printf("B");
     sem_post(&sem1);
    }

  
}


int main(){
  sem_init (&sem1,0,1);
  sem_init (&sem2,0,0);
  pthread_t t1,t2;
    
    pthread_create(&t1, NULL, (void *)A, NULL);
    //sleep(1);
    pthread_create(&t2, NULL, (void *)B, NULL);
    //sleep(1);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    

 return 0;
}
