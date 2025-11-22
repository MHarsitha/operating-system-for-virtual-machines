#include <stdio.h>
#include <string.h>

int main() {
    char fname[20], word[20], line[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", fname);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word))
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}

