#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n];
    for(i=0; i<n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
    int wt = 0;
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt, wt+bt[i]);
        wt += bt[i];
    }
}