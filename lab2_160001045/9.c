#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int ar[2];
	pipe(ar);
	int pid1,pid2,pid=fork();
	if(pid==0)
	{
		int fd=open("ab.txt",O_RDWR);
		char dr[50];
		int a=read(fd,dr,50);
		while(a > 0)
		{
			write(ar[1],dr,a);
			a=read(fd,dr,50);
		}

	}
	else
	{
		pid1=fork();
		if(pid1==0)
		{
			int fd=open("ab1.txt",O_RDWR);
				char dr[50];
				int a=read(fd,dr,50);
				while(a > 0)
				{
					write(ar[1],dr,a);
					a=read(fd,dr,50);
				}
		}
		else
		{
			pid2=fork();
			if(pid2==0)
			{
				int fd=open("ab2.txt",O_RDWR);
				char dr[50];
				int a=read(fd,dr,50);
				while(a > 0)
				{
					write(ar[1],dr,a);
					a=read(fd,dr,50);
				}

			}
			else
			{
				close(ar[1]);
				int fd=open("abc.txt",O_WRONLY|O_CREAT,S_IRWXU);
				char c[50];
				int a=read(ar[0],c,50);
				while(a > 0)
				{
					write(fd,c,a);
					a=read(ar[0],c,50);
				}
			}
		}
	}
}