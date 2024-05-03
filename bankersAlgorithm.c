#include<stdio.h>

void main(){
	int totalProcess,totalResources;
	printf("Enter the no. of processes: ");
	scanf("%d",&totalProcess);
	printf("Enter the no. of resources required :  ");
	scanf("%d",&totalResources);
	int allocation[totalProcess][totalResources],max[totalProcess][totalResources],need[totalProcess][totalResources];
	int safeSequence[totalProcess],flag[totalProcess];
	int available[totalResources],sum[totalResources];
	int count=0,s=0;
	int total[totalResources];
	
	printf("Enter total resources");
	for(int i=0;i<totalResources;i++){
		scanf("%d",&total[i]);
	}
	
	printf("Enter the resources already allocated for each processes: \n");
	for(int i=0;i<totalProcess;i++){
		printf("P%d\t",i);
		for(int j=0;j<totalResources;j++){
			scanf("%d",&allocation[i][j]);
		}
		flag[i]=0;
		sum[i]=0;
	}
	
	printf("Enter the maximum resources required for each processes: ");
	for(int i=0;i<totalProcess;i++){
		printf("P%d\t",i);
		for(int j=0;j<totalResources;j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("The resources needed for each processes is: \n");
	for(int i=0;i<totalProcess;i++){
		printf("P%d\t",i);
		for(int j=0;j<totalResources;j++){
			need[i][j]=max[i][j]-allocation[i][j];
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	
	//Calculation
	for(int i=0;i<totalProcess;i++){
		for(int j=0;j<totalResources;j++){
			sum[j]=sum[j]+allocation[i][j];
		}
		
		if(sum[i]>total[i]){
			printf("Total memory blocks is less than sum of allocations...!! Error !!");
			exit(0);
		}
	}
	
	for(int j=0;j<totalResources;j++){
		available[j]=total[j] - sum[j];
	}
	
	//Banker's Algorithm 
	for(int i=0;i<totalProcess;i++){
		if(flag[i]==1)
			continue;
		for(int j=0;j<totalResources;j++){
			if(need[i][j]<available[j]){
				count++;
			}
			
		}
		
		if(count==totalResources){
			for(int k=0;k<totalResources;k++){
				available[k]=allocation[i][k];
					
			}
			
			flag[i]=1;
			safeSequence[i]=s+1;
			count=0;
		}
		
		
	}	
	
	printf("Safe sequence: ");
	for(int i=0;i<totalResources;i++){
		printf("P%d -> ",safeSequence[i]);
	}
}
