#include <stdio.h>

int main() {
    int disk[50] = {0}, diskSize=20;
    int indexBlock[20];
    int i, nBlocks, fileId=1;
    int req;

    printf("Enter disk size (<=50): ");
    scanf("%d",&diskSize);

    printf("Enter number of blocks needed for file: ");
    scanf("%d",&nBlocks);
    if(nBlocks <=0 || nBlocks > diskSize-1) { printf("Invalid\n"); return 0; }

   
    int idx = -1, d=0;
    for(i=0;i<diskSize;i++) if(disk[i]==0) { idx = i; disk[i]=fileId; break; }
    if(idx == -1) { printf("No space\n"); return 0; }

    
    int count = 0;
    for(i=0;i<diskSize && count<nBlocks;i++) {
        if(disk[i]==0) { disk[i]=fileId; indexBlock[count]=i; count++; }
    }
    if(count < nBlocks) { printf("Not enough space\n"); return 0; }

    printf("Index block at %d contains:\n", idx);
    for(i=0;i<nBlocks;i++) printf("%d ", indexBlock[i]);
    printf("\n");

    printf("Enter logical block number to access (1..%d): ", nBlocks);
    scanf("%d",&req);
    if(req>=1 && req<=nBlocks) printf("Physical block is %d\n", indexBlock[req-1]);
    else printf("Invalid\n");
    return 0;
}
