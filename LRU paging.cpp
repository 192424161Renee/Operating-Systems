#include <stdio.h>

int main() {
    int frames[10], timeStamp[10], pages[50];
    int nFrames, nPages;
    int i,j,found, fault=0, time=0;

    printf("Enter number of frames (<=10): ");
    scanf("%d",&nFrames);
    printf("Enter number of pages (<=50): ");
    scanf("%d",&nPages);

    for(i=0;i<nFrames;i++) frames[i] = -1, timeStamp[i] = 0;
    for(i=0;i<nPages;i++) {
        printf("Page %d: ", i+1);
        scanf("%d",&pages[i]);
    }

    for(i=0;i<nPages;i++) {
        time++;
        found = 0;
        
        for(j=0;j<nFrames;j++) if(frames[j] == pages[i]) {
            found = 1;
            timeStamp[j] = time;
            break;
        }
        if(!found) {
            
            int idx = -1, minTime = 1<<30;
            for(j=0;j<nFrames;j++) {
                if(frames[j] == -1) { idx = j; break; }
                if(timeStamp[j] < minTime) { minTime = timeStamp[j]; idx = j; }
            }
            frames[idx] = pages[i];
            timeStamp[idx] = time;
            fault++;
        }
        printf("After %d: ", pages[i]);
        for(j=0;j<nFrames;j++) {
            if(frames[j]==-1) printf("- ");
            else printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", fault);
    return 0;
}
