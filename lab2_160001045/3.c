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
	int fdo=open("abc.txt",O_WRONLY|O_CREAT,S_IRWXU);
	while(read(fd,&c,1)==1)
	{
		write(fdo,&c,1);
	}
}
		
