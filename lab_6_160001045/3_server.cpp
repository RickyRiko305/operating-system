#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <unistd.h>
#include <time.h>
using namespace std;

#define ll long long
#define print(x) cout<<x
#define br cout<<endl
#define print2(x,y) cout<<x<<" "<<y
#define array(x) (ll*)malloc(sizeof(ll)*x)
#define vec(x) vector<x>
#define pb push_back
#define npos std::string::npos

int main() {
    
    char buffer[1024];
    struct sockaddr_in server;
    struct sockaddr_in client;
    
    
    int sock = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);
    int p=bind(sock,(struct sockaddr*)&server,sizeof(server));
    if(p<0){
      cout<<"Binding failed!"<<endl;
      close(sock);
      exit(1);
    }
    listen(sock,4);
    socklen_t size = sizeof(struct sockaddr_in);

    while(1){
      int new_socket = accept(sock,(struct sockaddr *)&client,&size);
      if(new_socket==-1){
        cout<<"connection failed!"<<endl;
        break;
      }
      

      char* message = "hello !\n";
      write(new_socket,message,strlen(message));
        strcpy(buffer, "");
        recv(new_socket, buffer, 1024, 0);
        if(strcmp(buffer,"Bye")==0)
          break;
        cout<<buffer<<endl;
        strcpy(buffer, "");
        cin>>buffer;
        send(new_socket,buffer,strlen(buffer),0);



      message = "Please disconnect after use!";
      write(new_socket,message,strlen(message));
    }
    close(sock);

    return 0;
}
