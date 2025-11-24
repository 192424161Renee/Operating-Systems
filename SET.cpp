#include <stdio.h>
int main()
{
    int n, i, j;
    int burst[20], process[20];
    int waiting[20], turnaround[20];
    int temp;
    float total_wait = 0, total_turn = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &burst[i]);
        process[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[j] < burst[i]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = 0;
        for (j = 0; j < i; j++) {
            waiting[i] += burst[j];
        }
    }
    for (i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
        total_wait += waiting[i];
        total_turn += turnaround[i];
    }
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", process[i], burst[i], waiting[i], turnaround[i]);
    }
    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turn / n);
    return 0;
}