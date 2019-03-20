#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
int main(){
	mkfifo("/tmp/fifo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	int fd=open("/tmp/fifo", O_WRONLY);
	char x;
	while(read(0,&x,1))
	{
		if(x<'0' || x>'9')break;
		write(fd,&x,1);
	}

}
