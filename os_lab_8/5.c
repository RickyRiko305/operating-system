#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
#include <semaphore.h>
#define for(i,b) for(int i=0; i<b; i++)
#define N 10
#define p(v) p  
sem_t Customers,Barbers;

sem_t Seats ; 
int FreeSeats = N; 
  
void Barber() { 
      while(1) { 
            
            printf("waits for a customer (sleeps).\n");
        sleep(1);
            sem_wait(&Customers); 
  
            
            sem_wait(&Seats); 
  
            
            printf("a chair gets free.\n");sleep(1);
            FreeSeats++; 
             
            
             printf("bring new customer for haircut.\n");sleep(1);
            sem_post(&Barbers); 
             
            
            sem_post(&Seats); 
            
            printf("barber is cutting hair.\n");sleep(1);
      } 
} 
  
void Customer() { 
      while(1) { 
            
            sem_wait(&Seats); 
            if(FreeSeats > 0) { 
                   
                  
                  printf("sitting sem_post.\n");sleep(1);
                  FreeSeats--; 
                   
                  
                  sem_post(&Customers); 
                   
                  
                  sem_post(&Seats); 
                   
                  
                  sem_wait(&Barbers); 
                  
                  printf(" customer is having hair cut\n"); sleep(1);
            } else { 
                  
                  sem_post(&Seats); 
                  
                  printf("customer leaves\n"); sleep(1);
            } 
      } 
} 


int main(){
  sem_init (&Barbers,0,0);
  sem_init (&Customers,0,0);
  sem_init (&Seats,0,1);
  pthread_t t1,t2,t3;
    
    pthread_create(&t1, NULL, (void *)Barber, NULL);
    
    pthread_create(&t2, NULL, (void *)Customer, NULL);
    
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    

 return 0;
}
