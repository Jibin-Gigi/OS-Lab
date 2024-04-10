#include<stdio.h>
void main(){
	int n,total_waitingTime,total_turnAroundTime;
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	int burstTime[n];
	int processName[n];
	printf("Enter the process names and burst time\n\n");
	printf("Process name\tBurst Time\n");
	for(int i=0;i<n;i++){
		scanf("%d",&processName[i]);
		scanf("%d",&burstTime[i]);
	}
	
	int waitingTime[n],turnAroundTime[n];
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
	
	float average_waitingTime=(float)total_waitingTime/n, average_turnAroundTime=total_turnAroundTime/n;
	
	printf("Process Name\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++){
		printf("          %d\t         %d\t             %d\n",processName[i],waitingTime[i],turnAroundTime[i]);
	}
	
	printf("Average waiting time=%f \nAverage turn around time=%f\n",average_waitingTime,average_turnAroundTime);
	
}
