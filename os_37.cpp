#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter requests: ");
    for(int i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total = 0;
    for(int i=0;i<n;i++){
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Head Movement: %d\n", total);
    return 0;
}

