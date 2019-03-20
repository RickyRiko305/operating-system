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
sem_t sem;
void A(){
    //sem_init (&sem,0,1);
    //for(i,10){
      //sem_wait(&sem);    
    //a=1;
    printf("A");
    //sem_post(&sem);
    //}

}

void B(){
  //sem_init (&sem,0,1);
   
    //for(i,10){
     //sem_wait(&sem);
     printf("B");
     //sem_post(&sem);
    //}

  
}


int main(){
  //sem_init (&sem,0,2);
  pthread_t t1,t2;
    for(i,10){
    pthread_create(&t1, NULL, (void *)A, NULL);
    sleep(1);
    pthread_create(&t2, NULL, (void *)B, NULL);
    sleep(1);
    }
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    

 return 0;
}
