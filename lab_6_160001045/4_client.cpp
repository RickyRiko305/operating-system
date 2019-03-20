#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
using namespace std;
int main() {
  int client_socket;
  int num,val;
	char buffer[1024];
	struct sockaddr_in server_Address;
	socklen_t addr_size;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	server_Address.sin_family = AF_INET;
	server_Address.sin_port = htons(8080);
  server_Address.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr_size = sizeof(server_Address);
  int p=connect(client_socket, (struct sockaddr *) &server_Address, addr_size);
	if(p==-1){
      cout<<"Error! Can't connect"<<endl;
      exit(1);
  }
    strcpy(buffer, "");
    recv(client_socket, buffer, 1024, 0);
    cout<<buffer<<endl;
    cin>>num;
    send(client_socket,&num,sizeof(num),0);
    recv(client_socket, &val, sizeof(val), 0);
    cout<<"Factorial : "<< val<<endl;
    close(client_socket);
    return 0;
}
