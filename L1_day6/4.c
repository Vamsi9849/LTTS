#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int rollno;
    char name[20];
    float marks;
};

void parseString(struct Student* students, int size, const char* input) {
    int i = 0;
    const char* delimiter = " ";
    char* token = strtok((char*)input, delimiter);

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiter);
        strncpy(students[i].name, token, sizeof(students[i].name));
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);
        token = strtok(NULL, delimiter);
        i++;
    }
}

void initialize(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        memset(students[i].name, 0, sizeof(students[i].name));
        students[i].marks = 0.0;
    }
}

void display(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int compareDesc(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;

    if (studentA->marks > studentB->marks) {
        return -1;
    } else if (studentA->marks < studentB->marks) {
        return 1;
    } else {
        return 0;
    }
}

void sortDescending(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compareDesc);
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    fflush(stdin); // Clear input buffer

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the student details in the format 'rollno name marks':\n");

    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        parseString(&students[i], 1, input);
    }

    printf("\n--- Student Details ---\n");
    display(students, size);

    printf("\n--- Student Details (Sorted in Descending Order of Marks) ---\n");
    sortDescending(students, size);
    display(students, size);

    free(students);

    return 0;
}