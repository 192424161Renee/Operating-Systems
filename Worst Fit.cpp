#include <stdio.h>

int main() {
    int blocks[10], processes[10], nBlocks, nProc;
    int allocation[10];
    int i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &nBlocks);

    for(i = 0; i < nBlocks; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &nProc);

    for(i = 0; i < nProc; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processes[i]);
        allocation[i] = -1;
    }

    for(i = 0; i < nProc; i++) {
        int worstIndex = -1;

        for(j = 0; j < nBlocks; j++) {
            if(blocks[j] >= processes[i]) {
                if(worstIndex == -1 || blocks[j] > blocks[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        if(worstIndex != -1) {
            allocation[i] = worstIndex;
            blocks[worstIndex] -= processes[i];
        }
    }

  
    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < nProc; i++) {
        if(allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }

    return 0;
}
