#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMovement = 0, initial, size, move;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);

    // Sort the request array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    // If movement is towards high value
    if (move == 1) {
        printf("Head movement steps:\n");

        for (i = index; i < n; i++) {
            printf("Move from %d to %d\n", initial, RQ[i]);
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }

        
        printf("Move from %d to %d\n", RQ[n - 1], 0);
        TotalHeadMovement += RQ[n - 1]; 

        initial = 0;
        for (i = 0; i < index; i++) {
            printf("Move from %d to %d\n", initial, RQ[i]);
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else { // If movement is towards low value
        printf("Head movement steps:\n");

        for (i = index - 1; i >= 0; i--) {
            printf("Move from %d to %d\n", initial, RQ[i]);
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }

        
        printf("Move from %d to %d\n", RQ[0], size - 1);
        TotalHeadMovement += (size - 1 - RQ[0] + 1);

        initial = size - 1;
        for (i = n - 1; i >= index; i--) {
            printf("Move from %d to %d\n", initial, RQ[i]);
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is %d\n", TotalHeadMovement);

    return 0;
}
