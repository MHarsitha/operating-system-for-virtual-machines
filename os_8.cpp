#include <stdio.h>

int main() {
    int n, tq, i, time = 0, done;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
        wt[i] = 0;
        tat[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    done = 0;
    while (done < n) {
        done = 0;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] > tq) {
                    rt[i] -= tq;
                    time += tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            } else {
                done++;
            }
        }
    }

    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}

