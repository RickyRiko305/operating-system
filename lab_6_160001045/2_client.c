#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

int main(){
  struct sockaddr_in address; 
    int sock = 0; 
    struct sockaddr_in serv_addr; 
   // char *hello = "Hello from client"; 
    char server_reply[2000] = {0}; 
    int c=0;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
    { 
        printf("\n failed to creation Socket.  \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT); 
       
    
    //inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);  
    
    c =  connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (c < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    recv(sock, server_reply , 2000 , 0);
    //send(sock , hello , strlen(hello) , 0 ); 
    //printf("Hello message sent\n"); 
    //int val = read( sock , client_reply, 2000); 
    printf("%s\n",server_reply );
    close(c);



 return 0;
}
