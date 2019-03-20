#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int p[2];
	pipe(p);
	int pid,pid1,pid2;
	pid=fork();
	if(pid==0)
	{
		int fd=open("text.txt",O_RDWR);
		char d[50];
		int n=read(fd,d,50);
		while(n > 0)
		{
			write(p[1],d,n);
			n=read(fd,d,50);
		}


		pid1=fork();
		if(pid1==0)
		{
			int fd=open("text1.txt",O_RDWR);
				char d1[50];
				int n1=read(fd,d1,50);
				while(n1 > 0)
				{
					write(p[1],d1,n1);
					n1=read(fd,d1,50);
				}

				pid2=fork();
				if(pid2==0)
				{
					int fd=open("text2.txt",O_RDWR);
					char d2[50];
					int n2=read(fd,d2,50);
					while(n2 > 0)
					{
						write(p[1],d2,n2);
						n2=read(fd,d2,50);
					}

				}

		}

	}
	else
	{
				close(p[1]);
				int fd=open("text3.txt",O_WRONLY|O_CREAT,S_IRWXU);
				char c[50];
				int n3=read(p[0],c,50);
				while(n3 > 0)
				{
					write(fd,c,n3);
					n3=read(p[0],c,50);
				}


	}

	return 0;
}
