#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include<pthread.h>
#include<string.h>
#include<sys/wait.h>
int a[100000];
int fib(int *val)
{
	int p=*val;
	a[0]=0;
	a[1]=1;
	for(int i=2;i<p;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}
int main(int argc, char const argv[])
{
	int val;
	scanf("%d",&val);
	pthread_t t1;
        int p = pthread_create(&t1,NULL,(void *)fib,&val);
        pthread_join(t1,NULL);
	for(int i=0;i<val;i++){
           printf("%d ",a[i]);
        }


}
