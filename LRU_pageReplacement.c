#include <stdio.h>
#include <stdbool.h>

int main() {
    int no_frame, no_request, i, pgf = 0, j = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &no_request);

    printf("Enter the number of frames: ");
    scanf("%d", &no_frame);

    int frame[no_frame], req[no_request], used[no_frame];

    for (i = 0; i < no_frame; i++) {
        frame[i] = -1;
        used[i] = 0;
    }

    printf("Enter the requests:\n");
    for (i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }

    printf("Page replacement (LRU):\n");

    for (i = 0; i < no_request; i++) {
        int avail = 0;
        printf("%d: ", req[i]);

        for (int a = 0; a < no_frame; a++) {
            if (frame[a] == req[i]) {
                avail = 1;
                used[a] = i + 1;
                break;
            }
        }

        if (avail == 0) {
            int least_used = 0;
            for (int a = 1; a < no_frame; a++) {
                if (used[a] < used[least_used])
                    least_used = a;
            }

           
            frame[least_used] = req[i];
            used[least_used] = i + 1;
            pgf++;
        }

       
        for (int a = 0; a < no_frame; a++) {
            if (frame[a] != -1)
                printf("%d ", frame[a]);
            else
                printf("x ");
        }
        printf("\n");
    }
    printf("Total page faults = %d\n", pgf);

    return 0;
}

