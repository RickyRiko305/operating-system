#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  char *a = (char*)malloc(sizeof(char));


   //int creat(char*creat,mode_t S_IRGRP);
   int fd = open("creat1.txt",O_WRONLY|O_CREAT,S_IRWXU);
   int fd1 = open("text.txt",O_RDONLY);

   while(1){
      int n = read(fd1,a,100);
      if(n==0){
        break;
      }
      write(fd,a,100);
   }
   close(fd);
   close(fd1);

return 0;
}
