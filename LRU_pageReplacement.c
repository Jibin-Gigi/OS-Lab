#include<stdio.h>

void main()
{
    int no_frames, no_requests, page_faults=0;
    printf("Enter the no. of frames :");
    scanf("%d", &no_frames);

    printf("Enter no.of requests :");
    scanf("%d", &no_requests);

    int frames[no_frames],requests[no_requests],recently_used_index[no_frames];

    for (int i =0;i<no_frames;i++){
        frames[i]=-1;
        recently_used_index[i]= -1;
    }

    printf("Enter the requests: ");
    for (int i=0; i<no_requests; i++){
        scanf("%d", &requests[i]);
    }

    for (int i =0;i<no_requests;i++){
        printf("%d: ", requests[i]);
        int available = 0;
        for (int j =0;j<no_frames;j++){
            if (frames[j]==requests[i]){
                available = 1;
                recently_used_index[j] = i;
                break;
            }
        }

        if (available == 0){
            int least_used_index = 0;
            for (int j = 1;j<no_frames;j++){
                if (recently_used_index[j] < recently_used_index[least_used_index])
                    least_used_index = j;
            }

            frames[least_used_index] = requests[i];
            page_faults++;
            recently_used_index[least_used_index] = i;

        }

         for (int j = 0; j < no_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("x ");
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);
}    
