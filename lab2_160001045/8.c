#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	char c[]="Hello";
	char d[5];
	long fd=open("a.txt",O_RDWR | O_CREAT ,S_IRWXU);
	long fdo=open("ab.txt",O_RDWR | O_CREAT ,S_IRWXU);
	dup2(fd,0);
	dup2(fdo,1);
	write(0,c,5);
	lseek(0,0,SEEK_SET);
	read(0,d,5);
	write(1,d,5);
	

}
		
