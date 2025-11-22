#include <stdio.h>

int main() {
    int b, p;
    printf("Enter number of blocks: ");
    scanf("%d",&b);

    int block[b];
    printf("Enter block sizes:\n");
    for(int i=0;i<b;i++) scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&p);

    int process[p], allocation[p];
    printf("Enter process sizes:\n");
    for(int i=0;i<p;i++) scanf("%d",&process[i]);

    for(int i=0;i<p;i++){
        int best = -1;
        for(int j=0;j<b;j++){
            if(block[j] >= process[i]){
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        allocation[i] = best;
        if(best != -1)
            block[best] -= process[i];
    }

    printf("\nProcess\tSize\tBlock\n");
    for(int i=0;i<p;i++){
        if(allocation[i] == -1)
            printf("P%d\t%d\tNot Allocated\n",i+1,process[i]);
        else
            printf("P%d\t%d\tB%d\n",i+1,process[i],allocation[i]+1);
    }
}

