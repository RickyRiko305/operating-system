#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	char c;
	int fd=open("a.txt",O_RDONLY);
	while(read(fd,&c,1)==1)
	{
		write(1,&c,1);
	}
}
		
