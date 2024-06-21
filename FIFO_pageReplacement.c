#include <stdio.h>

int main() {
    int numFrames, numRequests, i, pageFaults = 0, currentIndex = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &numRequests);

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int frames[numFrames], requests[numRequests];

    for (i = 0; i < numFrames; i++)
        frames[i] = -1;

    printf("Enter the requests:\n");
    for (i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Page replacement:\n");

    for (i = 0; i < numRequests; i++) {
        int available = 0;
        printf("%d : ", requests[i]);

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == requests[i]) {
                available = 1;
                break;
            }
        }

        if (available == 0) {
            frames[currentIndex] = requests[i];
            currentIndex = (currentIndex + 1) % numFrames;
            pageFaults++;

            for (int j = 0; j < numFrames; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("x ");
            }
        } else {
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("x ");
            }
        }

        printf("\n");
    }
    printf("Total page faults = %d\n", pageFaults);

    return 0;
}
