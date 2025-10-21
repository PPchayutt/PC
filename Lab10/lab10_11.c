#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student_info
{
    char name[61];
    char surname[61];
    char sex[10];
    int age;
    char id[13];
    float gpa;
};

void print_student(struct student_info student)
{
    if (strcmp(student.sex, "Male") == 0)
    {
        printf("Mr %c %s (%d) ID: %s GPA %.2f\n",
               student.name[0], student.surname, student.age, student.id, student.gpa);
    }
    else
    {
        printf("Miss %c %s (%d) ID: %s GPA %.2f\n",
               student.name[0], student.surname, student.age, student.id, student.gpa);
    }
}

void sort_students(struct student_info students[], int count, char option[])
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {

            int should_swap = 0;

            if (strcmp(option, "name") == 0)
            {
                if (strcmp(students[j].name, students[j + 1].name) > 0)
                {
                    should_swap = 1;
                }
            }
            else if (strcmp(option, "surname") == 0)
            {
                if (strcmp(students[j].surname, students[j + 1].surname) > 0)
                {
                    should_swap = 1;
                }
            }
            else if (strcmp(option, "id") == 0)
            {
                if (strcmp(students[j].id, students[j + 1].id) > 0)
                {
                    should_swap = 1;
                }
            }

            if (should_swap == 1)
            {
                struct student_info temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{

    struct student_info all_students[20];
    char sort_option[20];

    for (int i = 0; i < 20; i++)
    {
        scanf("%s %s %s %d %s %f",
              all_students[i].name,
              all_students[i].surname,
              all_students[i].sex,
              &all_students[i].age,
              all_students[i].id,
              &all_students[i].gpa);
    }

    scanf("%s", sort_option);

    for (int i = 0; i < strlen(sort_option); i++)
    {
        sort_option[i] = tolower(sort_option[i]);
    }

    sort_students(all_students, 20, sort_option);

    for (int i = 0; i < 20; i++)
    {
        print_student(all_students[i]);
    }

    return 0;
}
