#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	char c[100];
	int fd=open("a.txt",O_RDONLY);
	int a=read(fd,c,100);
	while(a)
	{
		write(1,c,a);
		a=read(fd,c,100);
	}
}
		