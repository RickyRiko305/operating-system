#include <bits/stdc++.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>

using namespace std;
int main() {
    
    int num,val;
    char buffer[1024];
    struct sockaddr_in server;
    struct sockaddr_in client;
    
    int sock = socket(AF_INET,SOCK_STREAM,0);
    
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);
    int p=bind(sock,(struct sockaddr*)&server,sizeof(server));
    if(p<0){
      cout<<"Bind Failed!"<<endl;
      close(sock);
      exit(1);
    };
    listen(sock,3);
    socklen_t size = sizeof(struct sockaddr_in);
      int new_socket = accept(sock,(struct sockaddr *)&client,&size);
      if(new_socket==-1){
        cout<<"connection failed!"<<endl;
      }
      

      char* message = "Connected to Server! Please enter the number : !\n";
      write(new_socket,message,strlen(message));
      while(1){
        recv(new_socket, &num, sizeof(num), 0);
        val=1;
        for(int i=num;i>1;--i){
          val *= i;
        }
        write(new_socket,&val,sizeof(val));
      }

      message = "Thanks for connecting!";
      write(new_socket,message,strlen(message));
      close(sock);

    return 0;
}
