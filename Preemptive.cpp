#include <stdio.h>
int main() {
    int n, i, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], at[n], pr[n], rt[n], wt[n], tat[n];
    for(i=0; i<n; i++) {
        printf("P%d AT BT Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    while(completed < n) {
        int idx = -1, best_pr = 9999;
        for(i=0; i<n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < best_pr) {
                best_pr = pr[i];
                idx = i;
            }
        }
        if(idx == -1) { time++; continue; }
        rt[idx]--;
        time++;
        if(rt[idx] == 0) {
            completed++;
            tat[idx] = time - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }
    printf("\nProcess\tWT\tTAT\n");
    for(i=0; i<n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
}