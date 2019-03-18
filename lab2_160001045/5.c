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
	int i=-1;
	int s=lseek(fd,0,SEEK_END);
		lseek(fd,-1,SEEK_END);
	s=s*-1;
	while(s-1<i)
	{
		read(fd,&c,1);
		write(1,&c,1);
		i--;
		lseek(fd,i,SEEK_END);
	}
}
		
