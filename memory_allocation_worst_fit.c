#include <stdio.h>

struct memoryBlock {
    int size;
    int allocated;
    int memoryIndex;
};

struct process {
    int processSize;
    int flag;
};

void main() {
    int numBlocks, numProcesses;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    struct memoryBlock m[numBlocks];

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d\t", i);
        m[i].memoryIndex = i;
        scanf("%d", &m[i].size);
        m[i].allocated = 0;
    }

    for (int i = 0; i < numBlocks; i++) {
        for (int j = i + 1; j < numBlocks; j++) {
            if (m[i].size < m[j].size) {
                int temp = m[i].size;
                m[i] = m[j];
                m[j].size = temp;
            }
        }
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);

    struct process p[numProcesses];

    printf("Enter the size required for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t", i);
        scanf("%d", &p[i].processSize);
        p[i].flag = 0;
    }

    printf("\n");

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (!m[j].allocated && p[i].processSize <= m[j].size) {
                m[j].allocated = 1;
                p[i].flag = 1;
                printf("Process %d (size: %d) is allocated to memory block %d (size: %d)\n", i, p[i].processSize, m[j].memoryIndex, m[j].size);
                break;
            }
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        if (!p[i].flag) {
            printf("Process %d (size: %d) is not allocated\n", i, p[i].processSize);
        }
    }
}
