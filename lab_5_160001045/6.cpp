#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#define buff_size 10
typedef int bool;
//void chkerror()
//{
//	if(errno)
//	{
//		printf("Error %d\n",errno);
//		exit(0);
//	}
//}
typedef struct{
	char q[buff_size];
	int st,en;
} DATA;
void push(DATA *link_list, char c)
{
	if(link_list->st == -1)
	{
		link_list->st = 0;
		link_list->en = 0;
	}
	link_list->q[link_list->en] = c;
	link_list->en = (link_list->en+1)%buff_size;
}
bool full(DATA *link_list)
{
	return (link_list->st!=-1) && link_list->st == link_list->en;
}
int main()
{
	key_t key = ftok("text.c",53);//task1.c
	//chkerror();
	int shmid = shmget(key,sizeof(DATA),0777|IPC_CREAT);
	//chkerror();
	DATA *link_list = (DATA*) shmat(shmid,NULL,SHM_RND);
	//chkerror();
	link_list->st = -1, link_list->en = -1;
	for(int i=0;i<1000;i++)
	{
		char p = 'a'+rand()%26;
		while(full(link_list));//WAIT
		printf("%c",p);
		fflush(stdout);
		push(link_list,p);
	}
	printf("\n");
	shmdt(link_list);
	return 0;
}
