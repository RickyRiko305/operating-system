#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  char *a = (char*)malloc(sizeof(char));
  int fd = open("text.txt",O_RDONLY);

   while(1){
      int n = read(fd,a,1);
      if(n==0){
        break;
      }
      write(1,a,1);
   }

  close(fd);

return 0;
}
