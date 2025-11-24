#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i;
    int total = 0;

    printf("Enter initial head position: ");
    scanf("%d",&head);
    printf("Enter number of requests: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) { printf("Request %d: ", i+1); scanf("%d",&req[i]); }

    printf("Service order: ");
    for(i=0;i<n;i++) {
        printf("%d ", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }
    printf("\nTotal head movement: %d\n", total);
    return 0;
}
