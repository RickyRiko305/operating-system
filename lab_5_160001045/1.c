#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <fcntl.h>

int main(){
 int p[2];
 pipe(p);
 pid_t pid;
 pid = fork();
 if(pid==0)
 {
		int fd=open("text.txt",O_RDWR|O_CREAT,S_IRWXU);
		char *d = (char*)malloc(sizeof(char));
		int n=read(fd,d,100);
                while(n>0){
                    write(p[1],d,n);
                    n=read(fd,d,100);
                }
                close(fd);

 } 
 else{
       close(p[1]);
       int fd=open("text3.txt",O_WRONLY|O_CREAT,S_IRWXU);
	char *c = (char*)malloc(sizeof(char));
	int n3=read(p[0],c,100);
	while(n3 > 0)
	{
	  write(fd,c,n3);
	  n3=read(p[0],c,100);
	}
        printf("tex is: %s",c);
       close(p[0])
       close(fd);
 }


 return 0;
}
