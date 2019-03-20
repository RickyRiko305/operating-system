#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include <semaphore.h>
#define MAX 10
int a[MAX];

sem_t sem;
void producer(){
  //sem_init (&sem,0,1);
  for(int i=0; i<10; i++){
    sem_wait(&sem);    
    a[i] = i;
    printf("val prodeuced is %d\n",a[i]);
    sem_post(&sem);
    
  }
  
}

void consumer(){
  //sem_init (&sem,0,1);
  for(int i=0; i<10; i++){
    
    sem_wait(&sem);
    printf("val consumer is %d\n",a[i]);    
    a[i] = -1;
    sem_post(&sem);
    
  }
  
}



int main(){
  sem_init (&sem,0,1);
  pthread_t t1,t2;
    
    pthread_create(&t1, NULL, (void *)producer, NULL);

    //sleep(1);
    pthread_create(&t2, NULL, (void *)consumer, NULL);

    //sleep(1);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);


 return 0;
}
