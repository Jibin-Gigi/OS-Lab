#include<stdio.h>

struct memoryBlock{
	int size;
	int allocated;
	int memoryIndex;
}m[10];

struct process{
	int processSize;
	int flag;
}p[10];

void main(){
	int memory,pno; 
	printf("Enter the no. of memory blocks: ");
	scanf("%d",&memory);
	printf("Enter size of memory blocks: \n");
	for(int i=0;i<memory;i++){
		printf("%d\t",i);
		m[i].memoryIndex=i;
		scanf("%d",&m[i].size);
		m[i].allocated=0;
	}
	
	printf("\nEnter no. of processes: ");
	scanf("%d",&pno);
	printf("Enter size required for each processes\n");
	for(int i=0;i<pno;i++){
		printf("%d\t",i);
		scanf("%d",&p[i].processSize);
		p[i].flag=0;
		
	}
	
	for(int i=0;i<memory;i++){
		for(int j=i+1;j<memory;j++){
			if(m[i].size>m[j].size){
				int temp=m[i].size;
				m[i].size=m[j].size;
				m[j].size=temp;
				
				temp=m[i].memoryIndex;
				m[i].memoryIndex=m[j].memoryIndex;
				m[j].memoryIndex=temp;
			}
		}
	}
	
	
	for(int i=0;i<pno;i++){
		for(int j=0;j<memory;j++){
			if(m[j].allocated==1){
					continue;
			}		
			else{
				if(p[i].processSize<=m[j].size){
					m[j].allocated=1;
					p[i].flag=1;
					printf("Process %d is alloced to memory block %d\n",i,m[j].memoryIndex);
					break;
				}
			}
		   }	
		
	}
	
	for(int i=0;i<pno;i++){
		if(p[i].flag==0){
			printf("The process %d is not allocated\n",i);
		}
	}	
	
	
	
}
