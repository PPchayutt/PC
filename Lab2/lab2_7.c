#include <stdio.h>

int main() {
    char firstName[31];
    char lastName[31];
    char studentID[9];
    int day, month, year;
    float gpa;

    scanf("%s", firstName);
    scanf("%s", lastName);
    scanf("%s", studentID);
    scanf("%d/%d/%d", &day, &month, &year);
    scanf("%f", &gpa);

    printf("Fullname: %s %s\n", firstName, lastName);
    printf("ID: %s\n", studentID);
    printf("DOB: %02d-%02d-%d\n", day, month, year);
    printf("GPA: %.2f\n", gpa);

    return 0;
}
