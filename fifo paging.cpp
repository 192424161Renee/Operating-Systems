#include <stdio.h>

int main() {
    int frames[10], pages[50], inFrame, i, j;
    int nFrames, nPages, fault = 0;
    int front = 0, rear = 0; 

    printf("Enter number of frames (<=10): ");
    scanf("%d", &nFrames);
    printf("Enter number of pages (<=50): ");
    scanf("%d", &nPages);

    for(i=0;i<nFrames;i++) frames[i] = -1;
    for(i=0;i<nPages;i++) {
        printf("Page %d: ", i+1);
        scanf("%d", &pages[i]);
    }

    for(i=0;i<nPages;i++) {
        inFrame = 0;
        for(j=0;j<nFrames;j++) if(frames[j] == pages[i]) inFrame = 1;
        if(!inFrame) {
            
            frames[rear] = pages[i];
            rear = (rear + 1) % nFrames;
            fault++;
        }
        
        printf("After request %d: ", pages[i]);
        for(j=0;j<nFrames;j++) {
            if(frames[j] == -1) printf("- ");
            else printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", fault);
    return 0;
}
