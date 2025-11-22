#include <stdio.h>

struct Process {
    int id, bt, wt, tat;
};

void findWaitingTime(struct Process p[], int n) {
    p[0].wt = 0;
    for(int i=1; i<n; i++)
        p[i].wt = p[i-1].bt + p[i-1].wt;
}

void findTurnAroundTime(struct Process p[], int n) {
    for(int i=0; i<n; i++)
        p[i].tat = p[i].bt + p[i].wt;
}

void findAverageTime(struct Process p[], int n) {
    int total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(int i=0; i<n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);
    }
    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);
}

void fcfs(struct Process p[], int n) {
    printf("\n--- First Come First Serve (FCFS) Scheduling ---\n");
    findWaitingTime(p, n);
    findTurnAroundTime(p, n);
    findAverageTime(p, n);
}

void sjf(struct Process p[], int n) {
    struct Process temp;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\n--- Shortest Job First (SJF) Scheduling ---\n");
    findWaitingTime(p, n);
    findTurnAroundTime(p, n);
    findAverageTime(p, n);
}

int main() {
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++) {
        p[i].id = i+1;
        printf("Enter burst time for Process %d: ", i+1);
        scanf("%d", &p[i].bt);
    }

    printf("\nSelect Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SJF\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        fcfs(p, n);
    else if(choice == 2)
        sjf(p, n);
    else
        printf("Invalid choice!\n");

    return 0;
}

