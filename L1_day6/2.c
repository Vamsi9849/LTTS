#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void StringToStructArray(const char* input, struct Student* students, int size) {
    const char* delimiter = " ";
    char* token = strtok((char*)input, delimiter);

    for (int i = 0; i < size; i++) {
        if (token == NULL)
            break;

        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        if (token == NULL)
            break;

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, delimiter);
        if (token == NULL)
            break;

        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
    }
}

void initialize(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        memset(students[i].name, 0, sizeof(students[i].name));
        students[i].marks = 0.0;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    getchar();

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the student details (rollno name marks):\n");

    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        StringToStructArray(input, &students[i], 1);
    }

    initialize(students, size);

  
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

  
    free(students);

    return 0;
}