#include <stdio.h>
#include <stdlib.h> 

int head, a[20], i, distance, n, seektime;

int main() {
    printf("\nEnter Head position:");
    scanf("%d", &head);

    printf("Enter number of disk requests:");
    scanf("%d", &n);

    printf("Enter the disk requests:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("*****FCFS DISK SCHEDULING*****\n");
    seektime = 0; 

    for (i = 0; i < n; i++) {
        distance = abs(head - a[i]); 
        printf("Head movement from %d to %d: %d\n", head, a[i], distance);
        seektime += distance; 
        head = a[i]; 
    }

    printf("Total seek time is: %d\n", seektime);

    return 0;
}
