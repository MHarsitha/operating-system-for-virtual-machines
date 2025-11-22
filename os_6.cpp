#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], pr[n], rt[n], wt[n], tat[n];
    int completed = 0, time = 0, i, minP, curr;

    for (i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i]; 
    }

    while (completed < n) {
        minP = 9999;
        curr = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < minP) {
                minP = pr[i];
                curr = i;
            }
        }

        if (curr != -1) {
            rt[curr]--;  

            if (rt[curr] == 0) {
                completed++;
                tat[curr] = time + 1 - at[curr];
                wt[curr] = tat[curr] - bt[curr];
            }
        }

        time++;
    }

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}

