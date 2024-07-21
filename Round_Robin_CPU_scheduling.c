#include<stdio.h>
void main(){
	int n,total_waitingTime=0,total_turnAroundTime=0,total=0;
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	int flag=0;
	int burstTime[n];
	int processName[n];
	int remainingTime[n];
	int timeQuantum;
	printf("Enter time quantum: ");
	scanf("%d",&timeQuantum);
	printf("Enter the process names,burst time\n\n");
	printf("Process name\tBurst Time\n");
	for(int i=0;i<n;i++){
		scanf("%d",&processName[i]);
		scanf("%d",&burstTime[i]);
		remainingTime[i]=burstTime[i];
	}
	
	int waitingTime[n],turnAroundTime[n];
	
	while(flag!=n){
		for(int i=0;i<n;i++){
			if(remainingTime[i]>timeQuantum){
				remainingTime[i]=remainingTime[i]-timeQuantum;
				total=total+timeQuantum;
			}
			else if(remainingTime[i]==0){
				
				continue;
			}
			else{
				total=total+remainingTime[i];
				remainingTime[i]=0;
				
				turnAroundTime[i]=total;
				total_turnAroundTime=total_turnAroundTime+turnAroundTime[i];
				
				waitingTime[i]=total-burstTime[i];
				total_waitingTime=total_waitingTime+waitingTime[i];
				
				flag++;
			}
		}
	}
	
	float average_waitingTime=(float)total_waitingTime/n, average_turnAroundTime=(float)total_turnAroundTime/n;
	
	printf("Process Name\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++){
		printf("          %d\t         %d\t             %d\n",processName[i],waitingTime[i],turnAroundTime[i]);
	}
	
	printf("Average waiting time=%f \nAverage turn around time=%f\n",average_waitingTime,average_turnAroundTime);
	
}
	
	
