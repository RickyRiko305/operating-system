#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>

using namespace std;


int main() {
 	int client_Socket;
	char buffer[1024];
	struct sockaddr_in server_Address;
	socklen_t address_size;
	client_Socket = socket(AF_INET, SOCK_STREAM, 0);

	server_Address.sin_family = AF_INET;
	server_Address.sin_port = htons(8080);
  	server_Address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address_size = sizeof(server_Address);
	int p=connect(client_Socket, (struct sockaddr *) &server_Address, address_size);
	if(p==-1){
	    cout<<"Error! Can't connect"<<endl;
		exit(1);
	}

  	while(1){
	    strcpy(buffer, "");
	    recv(client_Socket, buffer, 1024, 0);
	    cout<<buffer<<endl;
	    strcpy(buffer, "");
	    cin>>buffer;
	    send(client_Socket,buffer,strlen(buffer),0);
	}

  close(client_Socket);

    return 0;
}
