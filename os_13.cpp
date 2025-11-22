#include <stdio.h>

int main() {
    int blocks[5] = {100, 500, 200, 300, 600};
    int processes[4] = {212, 417, 112, 426};
    int allocation[4] = {-1,-1,-1,-1};

    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            if(blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }

    printf("Process\tBlock\n");
    for(int i=0;i<4;i++)
        printf("P%d\t%d\n",i+1,allocation[i]);
    return 0;
}

