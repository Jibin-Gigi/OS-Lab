#include<stdio.h>
#include<unistd.h>

void main(){
	int pd;
	pd=fork();
	if(pd==0){
		printf("\nThis is Child Process. \nProcess Id: %d",getpid());
		printf("\nParents Id: %d",getppid());
		int limit;
		printf("\nEnter the limit: ");
		scanf("%d",&limit);
		printf("First %d natural numbers are: \n",limit);
		for(int i=0;i<limit;i++){
			printf("%d\t",i+1);
		}
	}
	else if(pd>0){
		wait();
		printf("\nThis is Parent Process.\nProcess Id: %d",getppid());
		printf("\nEnter a number: ");
		int number;
		scanf("%d",&number);
		if(number%2==0){
			printf("The number is even\n");
		}
		else{
			printf("The number is odd\n");
		}
	}
	else{
		printf("\nFork failed");
	}
}
