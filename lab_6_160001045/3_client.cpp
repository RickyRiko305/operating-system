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
	    cout<<"Error! connection failed"<<endl;
		exit(1);
	}
	    strcpy(buffer, "");
	    recv(client_socket, buffer, 1024, 0);
	    cout<<buffer<<endl;
	    strcpy(buffer, "");
	    cout<<"Please enter date like (DD:MM:Year)=";
	    cin>>buffer;
	    send(client_socket,buffer,strlen(buffer),0);
	

  close(client_socket);

    return 0;
}
