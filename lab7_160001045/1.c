#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h>
int data;
int addition(){
  //static int val=0;
  data = data + 10;
  printf("add : %d\n", data);
}
int subtraction(){
  //static int v;
  data = data - 5;
  printf("sub : %d\n", data);
}
int multiplication(){
  //static int v;
  data = data * 5;
  printf("mul : %d\n", data);
}
int division(){
  //static int v;
  data = data / 5;
  printf("div : %d\n", data);
}
int main(){
  //static int data
  pthread_t t1,t2,t3,t4;
  pthread_create(&t1, NULL, (void *)addition, NULL); 
  pthread_create(&t2, NULL, (void *)subtraction, NULL);  
  pthread_create(&t3, NULL, (void *)multiplication, NULL);
  pthread_create(&t4, NULL, (void *)division, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);	

  return 0;
}
