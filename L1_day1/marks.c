#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float pm, mm, cm;
    float tm, per;
    scanf("%d", &rollNo);
    scanf("%s", name);
    scanf("%f", &pm);
    scanf("%f", &mm);
    scanf("%f", &cm);

    
    tm = pm + mm + cm;
    per = (tm / 300) * 100;
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", pm);
    printf("Math Marks: %.2f\n", mm);
    printf("Chemistry Marks: %.2f\n", cm);
    printf("Total Marks: %.2f\n", tm);
    printf("Percentage: %.2f%%\n", per);

    return 0;
}

