#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void String(struct Student* students, int size, const char* input) {
    int count = 0;
    const char* delimiter = " ";
    char* token = strtok((char*)input, delimiter);
    while (token != NULL && count < size) {
        students[count].rollno = atoi(token);
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strncpy(students[count].name, token, sizeof(students[count].name) - 1);
            token = strtok(NULL, delimiter);
        }
        if (token != NULL) {
            students[count].marks = atof(token);
            token = strtok(NULL, delimiter);
        }
        count++;
    }
}
void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}
int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    fflush(stdin); 
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    char input[100];
    printf("Enter student details in the format 'RollNo Name Marks':\n");
    for (int i = 0; i < size; i++) {
        fgets(input, sizeof(input), stdin);
        String(&students[i], size, input);
    }
    displayStudents(students, size);
    free(students);
    return 0;
}