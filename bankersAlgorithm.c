#include <stdio.h>
#include <stdlib.h>

void main() {
    int num_processes, num_resources, i, j, k=0, completed=0, safe_flag=0, exec_count=0;

    printf("Enter no. of processes: ");
    scanf("%d", &num_processes);

    printf("Enter no. of resources: ");
    scanf("%d", &num_resources);

    int visited[num_processes];
    int safe_sequence[num_processes];

    int allocation[num_processes][num_resources];
    int max_need[num_processes][num_resources];
    int available[num_resources];
    int resource_need[num_processes][num_resources];

    printf("Enter the available instances: ");
    for(i = 0; i < num_resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the maximum need of each process:\n");
    for(i = 0; i < num_processes; i++) {
        printf("P%d : ", i);
        for(j = 0; j < num_resources; j++)
            scanf("%d", &max_need[i][j]);

        visited[i] = 0;
    }

    printf("\nEnter the allocation of resources to each process\n");
    for(i = 0; i < num_processes; i++) {
        printf("P%d : ", i);
        for(j = 0; j < num_resources; j++)
            scanf("%d", &allocation[i][j]);

        visited[i] = 0;
    }

    printf("\nAllocation\tMax\tNeed\n");
    for(i = 0; i < num_processes; i++) {
        for(j = 0; j < num_resources; j++)
            printf("%d ", allocation[i][j]);
        printf("\t\t");
        for(j = 0; j < num_resources; j++)
            printf("%d ", max_need[i][j]);
        printf("\t");
        for(j = 0; j < num_resources; j++) {
            resource_need[i][j] = max_need[i][j] - allocation[i][j];
            printf("%d ", resource_need[i][j]);
        }
        printf("\n");
    }

    while(completed < num_processes) {
        safe_flag = 0;
        for(i = 0; i < num_processes; i++) {
            exec_count = 0;
            for(j = 0; j < num_resources; j++) {
                if(resource_need[i][j] <= available[j])
                    exec_count++;
            }
            if(exec_count == num_resources && visited[i] == 0) {
                for(j = 0; j < num_resources; j++)
                    available[j] += allocation[i][j];
                safe_flag = 1;
                visited[i] = 1;
                completed++;
                safe_sequence[k++] = i;
            }
        }
        if(safe_flag == 0) {
            printf("No safe sequence exists!\n");
            exit(0);
        }
    }

    printf("\nSafe Sequence: ");
    printf("<");
    for(i = 0; i < num_processes; i++)
        printf("P%d ", safe_sequence[i]);
    printf(">\n");
}
