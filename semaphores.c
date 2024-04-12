#include<stdio.h>
#include<stdlib.h>
int mutex=1 , full=0, empty=3;

int wait(int s){
	s--;
	return s;
}

int signal(int s){
	s++;
	return s;
}

void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	mutex=signal(mutex);
}

void main(){
	int role,choice=1;
	do{
		printf("Enter role : 1)Producer 2)Consumer \tEnter 0 to exit\n");
		scanf("%d",&role);
		switch(role){
			case 1: {
				if(mutex==1 && empty!=0){
					producer();
					printf("1 item is produced\n\n");
				}
				else{
					printf("Buffer Full\n\n");
				}
				break;
			}
			
			case 2: {
				if(mutex==1 && full!=0){
					consumer();
					printf("1 item is consumed\n\n");
				}
				else{
					printf("Empty Buffer\n\n");
				}
				break;
			}
			
			case 0 : {
				exit(0);
			}
		}
		
	}while(choice);
}
