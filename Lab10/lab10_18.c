#include <stdio.h>
#include <string.h>

struct Record
{
    char id[10];
    char name[100];
    long salary;
    long sales;
};

int main()
{
    int num_employees;
    scanf("%d", &num_employees);
    struct Record employee[num_employees];

    for (int i = 0; i < num_employees; i++)
    {
        scanf("%s %s %ld %ld",
              employee[i].id,
              employee[i].name,
              &employee[i].salary,
              &employee[i].sales);
    }

    char search_id[10];
    scanf(" %s", search_id);
    int found = 0;

    for (int i = 0; i < num_employees; i++)
    {
        if (strcmp(employee[i].id, search_id) == 0)
        {
            found = 1;
            double commission = (double)employee[i].sales * 0.02;
            double total_income = (double)employee[i].salary + commission;
            printf("%s\n", employee[i].id);
            printf("%s\n", employee[i].name);
            printf("%ld\n", employee[i].sales);
            printf("%.2f\n", commission);
            printf("%ld\n", employee[i].salary);
            printf("%.2f\n", total_income);
            break;
        }
    }

    if (found == 0)
    {
        printf("ID not found !!!\n");
    }

    return 0;
}
