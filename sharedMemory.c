#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#define SEGSIZE 100
int main(int argc, char *argv[ ])
{
	int shmid,cntr; key_t key;
	char *segptr;
	char buff[]="Hello";
	key=ftok(".",'s');
	if((shmid=shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666))== -1){
		if((shmid=shmget(key,SEGSIZE,0))==-1){
		perror("shmget");
		exit(1);
		}
	}
	else{
		printf("Creating a new shared memory seg \n");
		printf("SHMID:%d ",shmid);
	}
	system("ipcs –m");
	if((segptr=(char*)shmat(shmid,0,0))==(char*)-1){
		perror("shmat");
		exit(1);
	}
	printf("Writing data to shared memory…\n");
	strcpy(segptr,buff);
	printf("DONE\n");
	printf("Reading data from shared memory…\n");
	printf("DATA:-%s\n",segptr);
	printf("DONE\n");
	printf("Detaching\n");
	shmdt(segptr);
	printf("DONE\n");
	printf("Removing shared memory Segment…\n");
	if(shmctl(shmid,IPC_RMID,0)== -1)
		printf("Can‟t Remove Shared memory Segment…\n");
	else
		printf("Removed Successfully");
}








/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
void main(){
	key_t m =ftok(".","s");
	printf("Key= %d\n",m);
	int ShmId=shmget(m,1022,IPC_CREAT|0666);
	printf("ShmId= %d\n",ShmId);
	int *ShmAttachment=shmat(ShmId,0,0);
	printf("ShmAttachment= %d\n",ShmAttachment);
	if(ShmAttachment!=-1){
		printf("Attachment is succesfull\n");
		printf("Enter the data: ");
		char data[10];
		gets(data);
		strcpy(ShmAttachment,data);
		printf("Data given: %s\n",(char*)ShmAttachment);
	}
	else{
		printf("Attachment is not succesfull\n");
	}
	int ShmDettachment=shmdt(ShmAttachment);
	printf("ShmDettachment= %d\n",ShmDettachment);
	if(ShmDettachment!=-1){
		printf("Deattachment is succesfull\n");
	}
	else{
		printf("Deattachment is not succesfull\n");
	}
	int ShmControl=shmctl(ShmId,IPC_RMID, NULL);
	printf("ShmControl= %d\n",ShmControl);
	if(ShmControl!=-1){
		printf("Deattached Data is deleted\n");
	}
	else{
		printf("Deattached Data is not deleted\n");
	}
}

*/
