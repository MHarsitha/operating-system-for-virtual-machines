#include <stdio.h>

int main() {
    int n;
    printf("Enter number of blocks: ");
    scanf("%d",&n);

    int index[n];
    printf("Enter block numbers:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&index[i]);

    printf("Allocated Blocks:\n");
    for(int i=0;i<n;i++)
        printf("%d ", index[i]);

    return 0;
}

