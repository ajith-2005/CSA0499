#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void writeEmployee(FILE *file, struct Employee emp, int index) {
    fseek(file, index * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);
}

void readEmployee(FILE *file, struct Employee *emp, int index) {
    fseek(file, index * sizeof(struct Employee), SEEK_SET);
    fread(emp, sizeof(struct Employee), 1, file);
}

int main() {
    FILE *file = fopen("employees.dat", "wb+");
    if (!file) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    struct Employee emp1 = {1, "John Doe", 50000.0};
    writeEmployee(file, emp1, 0);

    struct Employee emp2;
    readEmployee(file, &emp2, 0);
    printf("ID: %d, Name: %s, Salary: %.2f\n", emp2.id, emp2.name, emp2.salary);

    fclose(file);
    return EXIT_SUCCESS;
}
