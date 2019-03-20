#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <fcntl.h>

int main(){
 int p[2];
 pipe(p);
 int pid;
 pid = fork();
 if(pid==0)
 {              
		char *d = (char*)malloc(sizeof(char)*50); 		
                dup2(1,p[0]);
                read(1,d,11);		
                printf("%s",d);                
 } 
 else{   
      
        char *c = (char*)malloc(sizeof(char)*50);
	printf("enter the text: ");
        scanf("%s",c);
        dup2(0,p[1]);
	write(0,c,11);
	      
 }
    close(p[1]);
    close(p[0]);
    close(1);
     close(0);


 return 0;
}
