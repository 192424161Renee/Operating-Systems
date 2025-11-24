#include <stdio.h>
int main()
{
    int n, i, j;
    int burst[20], priority[20], process[20];
    int waiting[20], turnaround[20];
    int temp;
    float total_wait = 0, total_turn = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        process[i] = i + 1; 
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &burst[i]);
        printf("Enter Priority for Process P%d (Lower = Higher Priority): ", i+1);
        scanf("%d", &priority[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
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
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_wait += waiting[i];
        total_turn += turnaround[i];
    }
    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", process[i], burst[i], priority[i], waiting[i], turnaround[i]);
    }
    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf(" \nAverage Turnaround Time = %.2f\n", total_turn / n);
    return 0;
}