#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char fname[20], data[100];
    int choice;

    printf("Enter file name: ");
    scanf("%s", fname);

    while (1) {
        printf("\n1.Create\n2.Write\n3.Read\n4.Append\n5.Delete\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            fp = fopen(fname, "w");
            fclose(fp);
            printf("File created.\n");
            break;

        case 2:
            fp = fopen(fname, "w");
            printf("Enter data: ");
            scanf(" %[^\n]", data);
            fprintf(fp, "%s", data);
            fclose(fp);
            break;

        case 3:
            fp = fopen(fname, "r");
            printf("\n--- File Content ---\n");
            while (fgets(data, sizeof(data), fp))
                printf("%s", data);
            fclose(fp);
            break;

        case 4:
            fp = fopen(fname, "a");
            printf("Enter data to append: ");
            scanf(" %[^\n]", data);
            fprintf(fp, "%s", data);
            fclose(fp);
            break;

        case 5:
            remove(fname);
            printf("File deleted.\n");
            break;

        case 6:
            exit(0);
        }
    }
}

