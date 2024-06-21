#include <stdio.h>

int main() {
    int numFrames, numRequests, i, pageFaults = 0, currentIndex = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &numRequests);

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int frames[numFrames], requests[numRequests], used[numFrames];

    for (i = 0; i < numFrames; i++) {
        frames[i] = -1;
        used[i] = 0;
    }

    printf("Enter the requests:\n");
    for (i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Page replacement (LRU):\n");

    for (i = 0; i < numRequests; i++) {
        int available = 0;
        printf("%d: ", requests[i]);

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == requests[i]) {
                available = 1;
                used[j] = i + 1;
                break;
            }
        }

        if (available == 0) {
            int leastUsedIndex = 0;
            for (int j = 1; j < numFrames; j++) {
                if (used[j] < used[leastUsedIndex])
                    leastUsedIndex = j;
            }

            frames[leastUsedIndex] = requests[i];
            used[leastUsedIndex] = i + 1;
            pageFaults++;
        }



        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("x ");
        }
        printf("\n");
    }
    printf("Total page faults = %d\n", pageFaults);
    printf("Total page hits = %d\n", numRequests - pageFaults); 


    return 0;
}
