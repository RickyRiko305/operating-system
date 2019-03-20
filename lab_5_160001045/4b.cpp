	#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int id = open("/tmp/fifo",O_RDONLY);
	
	int d=0,val=1,i;
	
	char x;
	while(read(id,&x,1)>0)
	{
		d=d*10+x-'a';
	}
	for(i=1;i<=d;i++)
			val*=i;
	printf("%d",val);

}
