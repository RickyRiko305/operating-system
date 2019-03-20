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
   int fd = open("dup1.txt",O_WRONLY|O_CREAT,S_IRWXU);
   
   int d = dup(fd);
    while(1){
      int n = read(fd1,a,1);
      if(n==0){
        break;
      }
      write(d,a,1);
   }

   close(fd1);
   close(fd);

return 0;
}
