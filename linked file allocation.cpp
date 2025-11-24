#include <stdio.h>

int main() {
    int next[50], used[50]={0}, diskSize=20;
    int i, n, fileId=1;
    int head=-1, tail=-1, prev=-1;

    printf("Enter disk size (<=50): ");
    scanf("%d",&diskSize);
    printf("Enter number of blocks for file: ");
    scanf("%d",&n);

    for(i=0;i<diskSize;i++) next[i] = -1;

    int count=0;
    for(i=0;i<diskSize && count<n;i++) {
        if(!used[i]) {
            used[i]=1;
            if(head==-1) head = i;
            if(prev!=-1) next[prev] = i;
            prev = i;
            tail = i;
            count++;
        }
    }
    if(count < n){ printf("Not enough space\n"); return 0; }

    printf("File blocks chain starting at %d:\n", head);
    int cur = head;
    while(cur != -1) {
        printf("%d -> ", cur);
        cur = next[cur];
    }
    printf("NULL\n");
    return 0;
}
