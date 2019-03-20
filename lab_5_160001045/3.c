#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <fcntl.h>

int main(){
 int p[2];
 pipe(p);
 int pid1,pid2;
 pid1 = fork();
 if(pid1==0)
 {              
     char *d = (char*)malloc(sizeof(char)*50); 		
                dup2(1,p[0]);
                read(1,d,11);		
                printf("%s",d);               
 } 
 else{
      pid2 = fork();
      if(pid2==0){
      
      }
      else{
	char *c = (char*)malloc(sizeof(char)*50);
	printf("enter the text: ");
        scanf("%s",c);
        dup2(0,p[1]);
	write(0,c,11);
      }
                
       
 }
    


 return 0;
}
