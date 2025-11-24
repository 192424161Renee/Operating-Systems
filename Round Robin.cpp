#include <stdio.h>
int main() {
    int n, tq, i, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], rt[n], wt[n], tat[n];
    for(i=0; i<n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    int done;
    do {
        done = 1;
        for(i=0; i<n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);
    printf("\nProcess\tWT\tTAT\n");
    for(i=0; i<n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
}