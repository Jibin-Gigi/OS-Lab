#include <stdio.h>

struct memoryBlock {
    int size;
    int allocated;
};

struct process {
    int processSize;
    int flag;
};

int main() {
    int numBlocks, numProcesses;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);
    if (numBlocks <= 0) {
        printf("Number of memory blocks must be greater than zero.\n");
        return 1;
    }

    struct memoryBlock m[numBlocks];

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d\t", i);
        scanf("%d", &m[i].size);
        if (m[i].size <= 0) {
            printf("Size of memory blocks must be greater than zero.\n");
            return 1;
        }
        m[i].allocated = 0;
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);
    if (numProcesses <= 0) {
        printf("Number of processes must be greater than zero.\n");
        return 1;
    }

    struct process p[numProcesses];

    printf("Enter the size required for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t", i);
        scanf("%d", &p[i].processSize);
        if (p[i].processSize <= 0) {
            printf("Process size must be greater than zero.\n");
            return 1;
        }
        p[i].flag = 0;
    }

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (!m[j].allocated && p[i].processSize <= m[j].size) {
                m[j].allocated = 1;
                p[i].flag = 1;
                printf("Process %d (size: %d) is allocated to memory block %d (size: %d)\n", i, p[i].processSize, j, m[j].size);
                break;
            }
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        if (!p[i].flag) {
            printf("Process %d (size: %d) is not allocated\n", i, p[i].processSize);
        }
    }

    return 0;
}
