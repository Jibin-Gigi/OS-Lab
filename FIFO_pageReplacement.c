#include <stdio.h>

int main() {
    int no_frame, no_request, i, pgf = 0, j = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &no_request);

    printf("Enter the number of frames: ");
    scanf("%d", &no_frame);

    int frame[no_frame], req[no_request];

    for (i = 0; i < no_frame; i++)
        frame[i] = -1;

    printf("Enter the requests:\n");
    for (i = 0; i < no_request; i++) {
        scanf("%d", &req[i]);
    }

    printf("Page replacement:\n");

    for (i = 0; i < no_request; i++) {
        int avail = 0;
        printf("%d: ", req[i]);

        for (int a = 0; a < no_frame; a++) {
            if (frame[a] == req[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
           
            frame[j] = req[i];
            j = (j + 1) % no_frame;
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

















/*
#include<stdio.h>
void main(){
  int no_frame,no_request,i,pgf=0,j=0;
  printf("Enter the number of request\n");
  scanf("%d",&no_request);
  printf("Enter the number of frames\n");
  scanf("%d",&no_frame);
   int frame[no_frame],req[no_request];
  for(i=0;i<no_frame;i++)
      frame[i]=-1;
  printf("Enter the requests:\n");
  for(i=0;i<no_request;i++){
    scanf("%d",&req[i]);
  }
  printf("page replacement :\n");
  for(i=0;i<no_request;i++){
    int avail=0;
    printf("%d :",req[i]);
    for(int a=0;a<no_frame;a++){
     
       if(frame[a]==req[i]){
         avail=1;
         break;
       }
    }
    if(avail==0){
       frame[j]=req[i];
       j=(j+1)%no_frame;
       pgf++;
    }
    for(int a=0;a<no_frame;a++){
      printf("%d\t",frame[a]);
    }
    printf("\n");
  }
  printf("No of page fault=%d\n",pgf);
}






















#include<stdio.h>
void main(){
	int pageFault=0,j=0;
	int req;
	printf("Enter the no.of requests: ");
	scanf("%d",&req);
	int frames;
	printf("Enter the no.of frames: ");
	scanf("%d",&frames);
	int requests[req];
	printf("Enter the requets: ");
	for(int i=0;i<req;i++){
		scanf("%d",&requests[i]);
		printf("  ");
	}
	for(int i=0;i<req;i++){
		printf
	}
}


*/
