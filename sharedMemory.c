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
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {
    key_t key = ftok(".", 's');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    printf("Key= %d\n", key);

    int shmId = shmget(key, 1022, IPC_CREAT | 0666);
    if (shmId == -1) {
        perror("shmget");
        exit(1);
    }
    printf("ShmId= %d\n", shmId);

    char *shmAttachment = shmat(shmId, 0, 0);
    if (shmAttachment == (char *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("ShmAttachment= %p\n", (void *)shmAttachment);

    printf("Attachment is successful\n");
    printf("Enter the data: ");
    char data[100];
    if (fgets(data, sizeof(data), stdin) != NULL) {
        data[strcspn(data, "\n")] = '\0';  // Remove newline character
        strcpy(shmAttachment, data);
        printf("Data given: %s\n", shmAttachment);
    } else {
        perror("fgets");
        exit(1);
    }

    if (shmdt(shmAttachment) == -1) {
        perror("shmdt");
        exit(1);
    }
    printf("Detachment is successful\n");

    if (shmctl(shmId, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Removed shared memory segment successfully\n");

    return 0;
}

*/
