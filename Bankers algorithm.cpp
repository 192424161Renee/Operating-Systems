#include <stdio.h>
int main() {
    int alloc[3]={3,2,2};
    int max[3]={7,3,5};
    int avail=3;
    int need[3];
    for(int i=0;i<3;i++) need[i]=max[i]-alloc[i];
    int safe=1;
    for(int i=0;i<3;i++){
        if(need[i] <= avail)
            avail += alloc[i];
        else
            safe=0;
    }
    printf(safe ? "Safe State\n":"Unsafe State\n");
    return 0;
}