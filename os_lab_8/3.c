#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include <semaphore.h>

int a=0,b=0;
sem_t sem;
void drink_coffee(){
    sem_init (&sem,0,2);
  
    sem_wait(&sem);    
    a=1;
    printf("drink coffe\n");
    sem_post(&sem);
    
  
  
}

void study_os(){
  sem_init (&sem,0,2);
  
    
    sem_wait(&sem);
    printf("study os\n");    
    b=1;
    sem_post(&sem);
    

  
}

void take_exam(){
  sem_init (&sem,0,2);
  sem_wait(&sem);
  //if(a==1 && b==1){
    printf("take exam\n");
   //}
   sem_post(&sem);
  
}



int main(){
  
  pthread_t t1,t2,t3;
    
    pthread_create(&t1, NULL, (void *)drink_coffee, NULL);
    pthread_create(&t2, NULL, (void *)study_os, NULL);
    pthread_create(&t3, NULL, (void *)take_exam, NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

 return 0;
}
