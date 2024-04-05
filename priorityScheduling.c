#include<stdio.h>
void main(){
	int n,total_waitingTime=0,total_turnAroundTime=0;
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	int burstTime[n];
	int processName[n];
	int priorityQueue[n];
	printf("Enter the process names,burst time and priorities\n\n");
	printf("Process name\tBurst Time\t  Priority\n");
	for(int i=0;i<n;i++){
		scanf("%d",&processName[i]);
		scanf("%d",&burstTime[i]);
		scanf("%d",&priorityQueue[i]);
	}
	
	int waitingTime[n],turnAroundTime[n];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(priorityQueue[i]>priorityQueue[j]){
				int temp=priorityQueue[i];
				priorityQueue[i]=priorityQueue[j];
				priorityQueue[j]=temp;
				
				temp=burstTime[i];
				burstTime[i]=burstTime[j];
				burstTime[j]=temp;
				
				temp=processName[i];
				processName[i]=processName[j];
				processName[j]=temp;
			}
		}
	}
	
	waitingTime[0]=0;
	turnAroundTime[0]=burstTime[0];
	total_waitingTime=waitingTime[0];
	total_turnAroundTime=turnAroundTime[0];
	
	
	for(int i=1;i<n;i++){
		waitingTime[i]=waitingTime[i-1]+burstTime[i-1];
		total_waitingTime=total_waitingTime+waitingTime[i];
		
		turnAroundTime[i]=turnAroundTime[i-1]+burstTime[i];
		total_turnAroundTime=total_turnAroundTime+turnAroundTime[i];
		
	}
	
	float average_waitingTime=(float)total_waitingTime/n, average_turnAroundTime=(float)total_turnAroundTime/n;
	
	printf("Process Name\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++){
		printf("          %d\t         %d\t             %d\n",processName[i],waitingTime[i],turnAroundTime[i]);
	}
	
	printf("Average waiting time=%f \nAverage turn around time=%f\n",average_waitingTime,average_turnAroundTime);
	

	
}
