#include <stdio.h>

int main() {
    int start, length;
    printf("Enter start block: ");
    scanf("%d",&start);

    printf("Enter file length: ");
    scanf("%d",&length);

    printf("Allocated Blocks:\n");
    for(int i=start;i<start+length;i++)
        printf("%d ", i);

    return 0;
}

