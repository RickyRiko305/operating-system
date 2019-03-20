#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#define buff_size 10
typedef int bool;
typedef struct{
	char q[buff_size];
	int st,en;
} DATA;


void push(DATA *list, char x)
{
	list->q[list->en] = x;
	list->en = (list->en+1)%buff_size;
}


bool full(DATA *list)
{
	return (list->en+1)%buff_size == list->st;
}


int main()
{
	int  key_val = ftok("1.c",53);
	chkerror();
	int shmid = shmget(key_val,sizeof(DATA),0777|IPC_CREAT);
	chkerror();
	DATA *list = (DATA*) shmat(shmid,NULL,SHM_RND);
	chkerror();
	list->st = 0, list->en = 0;
	
	for(int i=0;i<1000;i++)
	{
		char p = 'a'+rand()%26;
		while(full(list));//WAIT
		printf("%c",p);
		fflush(stdout);
		push(list,p);
	}
	printf("\n");
	shmdt(list);
	return 0;
}
