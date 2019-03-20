#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
int main() 
{ 
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
    
    bind(socket_desc, (struct sockaddr *)&server_address,sizeof(server_address)); 

    while(i<3){     
    struct sockaddr_in address; 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT );    
    
    listen(socket_desc, 3);
    int c = sizeof(address); 
    new_socket = accept(socket_desc, (struct sockaddr *)&address,(socklen_t*)&c);
    
    //val = read( new_socket , server_reply, 2000); 
    //printf("%s\n",server_reply ); 
    //send(new_socket , message , strlen(message) , 0 ); 
    write(new_socket , message , strlen(message));
    printf("Hello message sent\n"); 
    i++;

    }
    return 0; 
} 
