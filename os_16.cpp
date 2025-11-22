#include <stdio.h>

struct Emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Emp e;
    int n, pos, choice;

    fp = fopen("emp.dat", "rb+");
    if (fp == NULL)
        fp = fopen("emp.dat", "wb+");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter ID, Name and Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("\nEnter record number to access (0 to %d): ", n - 1);
    scanf("%d", &pos);

    fseek(fp, pos * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details:\n");
    printf("ID: %d\nName: %s\nSalary: %.2f\n", e.id, e.name, e.salary);

    fclose(fp);
    return 0;
}

