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
    int number;
    printf("enter the number: ");
    scanf("%d",&number);
    //write(sock, &number, sizeof(number));
    send(sock,&number, sizeof(number),0);
    int flag;
    read(sock,&flag,sizeof(int));

    if(flag==1){
       printf("prime number");
    }
    else{
       printf("not prime number");
    }

    close(c);



 return 0;
}
