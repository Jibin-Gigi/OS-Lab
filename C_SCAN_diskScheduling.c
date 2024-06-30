#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMovement = 0, initial, size, seek_time = 0;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    
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

    
    printf("Head movement steps:\n");
    for (i = index; i < n; i++) {
        seek_time = abs(RQ[i] - initial);
        printf("Move from %d to %d (Seek Time: %d)\n", initial, RQ[i], seek_time);
        TotalHeadMovement += seek_time;
        initial = RQ[i];
    }

    
    seek_time = abs(size - 1 - initial);
    printf("Move from %d to %d (Seek Time: %d)\n", initial, size - 1, seek_time);
    TotalHeadMovement += seek_time;
    initial = size - 1;

    
    seek_time = size - 1;
    printf("Move from %d to %d (Seek Time: %d)\n", initial, 0, seek_time);
    TotalHeadMovement += seek_time;
    initial = 0;

    
    for (i = 0; i < index; i++) {
        seek_time = abs(RQ[i] - initial);
        printf("Move from %d to %d (Seek Time: %d)\n", initial, RQ[i], seek_time);
        TotalHeadMovement += seek_time;
        initial = RQ[i];
    }

    printf("Total head movement is %d\n", TotalHeadMovement);

    return 0;
}
