#include <stdio.h>
int main() {
    int blocks[3]={100,500,200};
    int process[3]={120,90,300};
    int alloc[3]={-1,-1,-1};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(blocks[j]>=process[i]){
                alloc[i]=j;
                blocks[j]-=process[i];
                break;
            }
        }
    }
    for(int i=0;i<3;i++)
        printf("Process %d -> Block %d\n", i, alloc[i]);
    return 0;
}