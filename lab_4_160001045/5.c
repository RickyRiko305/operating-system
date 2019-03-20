#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  char *a = (char*)malloc(sizeof(char));
   

   //int creat(char*creat,mode_t S_IRGRP);
   //int fd = open("creat.txt",O_WRONLY|O_CREAT,S_IRWXU);
   int fd1 = open("text.txt",O_RDONLY);
   int h = lseek(fd1,0,SEEK_END);
   while(h>0){
      int n = read(fd1,a,1);
      
      write(1,a,1);
      //h--;
      h = lseek(fd1,-2,SEEK_CUR);
   }
   int n = read(fd1,a,1);
      
      write(1,a,1);

   close(fd1);

return 0;
}
