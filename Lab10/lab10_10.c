#include <stdio.h>
#include <string.h>

struct student_info
{
    char name[61];
    char surname[61];
    char sex[10];
    int age;
    char id[13];
    double gpa;
};

int main()
{
    struct student_info student;

    scanf("%s %s %s %d %s %lf",
          student.name,
          student.surname,
          student.sex,
          &student.age,
          student.id,
          &student.gpa);

    if (strcmp(student.sex, "Male") == 0)
    {
        printf("Mr %c %s (%d) ID: %s GPA %.2lf\n",
               student.name[0],
               student.surname,
               student.age,
               student.id,
               student.gpa);
    }
    else
    {
        printf("Miss %c %s (%d) ID: %s GPA %.2lf\n",
               student.name[0],
               student.surname,
               student.age,
               student.id,
               student.gpa);
    }

    return 0;
}
