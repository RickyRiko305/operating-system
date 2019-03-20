#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  char *a = (char*)malloc(sizeof(char));
   

   close(0);
   close(1);
   int fd1 = open("text.txt",O_RDONLY);
   int fd = open("dup.txt",O_WRONLY|O_CREAT,S_IRWXU);
   
   while(1){
      int n = read(fd1,a,1);
      if(n==0){
        break;
      }
      write(fd,a,1);
   }

   close(fd1);

return 0;
}
