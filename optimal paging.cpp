#include <stdio.h>

int nextUse(int pages[], int nPages, int currentIdx, int page) {
    int k;
    for(k = currentIdx + 1; k < nPages; k++) if(pages[k] == page) return k;
    return 1<<30; 
}

int main() {
    int frames[10], pages[50];
    int nFrames, nPages;
    int i,j,found,fault=0;

    printf("Enter number of frames (<=10): ");
    scanf("%d",&nFrames);
    printf("Enter number of pages (<=50): ");
    scanf("%d",&nPages);
    for(i=0;i<nFrames;i++) frames[i] = -1;
    for(i=0;i<nPages;i++) {
        printf("Page %d: ", i+1);
        scanf("%d",&pages[i]);
    }

    for(i=0;i<nPages;i++) {
        found = 0;
        for(j=0;j<nFrames;j++) if(frames[j] == pages[i]) { found = 1; break; }
        if(!found) {
            int idx = -1;
            // empty slot?
            for(j=0;j<nFrames;j++) if(frames[j] == -1) { idx = j; break; }
            if(idx == -1) {
                int farthest = -1, farPos = -1;
                for(j=0;j<nFrames;j++) {
                    int pos = nextUse(pages, nPages, i, frames[j]);
                    if(pos > farPos) { farPos = pos; farthest = j; }
                }
                idx = farthest;
            }
            frames[idx] = pages[i];
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
