#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include  <math.h>
#define PORT 8080
int prime(int num){
   int t=1;


   int i=0;
   for(i=2; i<num; i++)
{
      if((num%i)==0){
        return 0;
      }
   }


  return 1;
}

void process(int *num){
   int val=0;
   int a= *num;
   read(a,&val,sizeof(int));
   val = prime(val);
   send(a,&val,sizeof(int),0);
}

int main(){
   int socket_desc, new_socket, val;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );


    char server_reply[2000] = {0};
    char *message = "Hello from server";


    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc<0){
      printf("failed t create socket \n");
      return -1;
    }
    int i=0;

    int b = bind(socket_desc, (struct sockaddr *)&server_address,sizeof(server_address));
    listen(socket_desc, 1);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );


    while(1){

    int c = sizeof(address);
    new_socket = accept(socket_desc, (struct sockaddr *)&address,(socklen_t*)&c);


     pthread_t t1;
     int h = pthread_create(&t1, NULL, (void *)process, &new_socket);
     pthread_join(t1,NULL);




    }
    close(new_socket);
  return 0;
}
