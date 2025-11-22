#include <stdio.h>

int main() {
    int n, start;
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int next[n];
    printf("Enter next block pointer for each block (-1 for end):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &next[i]);

    printf("Enter start block: ");
    scanf("%d", &start);

    printf("File Blocks: ");
    while (start != -1) {
        printf("%d ", start);
        start = next[start];
    }
    return 0;
}

