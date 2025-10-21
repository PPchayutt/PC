#include <stdio.h>
#include <string.h>

struct Weather
{
    char outlook[9];
    int temperature;
    int humidity;
    char wind;
};

void playing_decision(struct Weather *day_weather)
{
    if (strcmp(day_weather->outlook, "overcast") == 0)
    {
        printf("yes\n");
    }
    else if (strcmp(day_weather->outlook, "rain") == 0)
    {
        if (day_weather->wind == 'F')
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    else if (strcmp(day_weather->outlook, "sunny") == 0)
    {
        if (day_weather->humidity > 77)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
}

int main()
{
    int num_days;
    scanf("%d", &num_days);
    struct Weather daily_records[num_days];

    for (int i = 0; i < num_days; i++)
    {
        scanf(" %s %d %d %c",
              daily_records[i].outlook,
              &daily_records[i].temperature,
              &daily_records[i].humidity,
              &daily_records[i].wind);
    }

    for (int i = 0; i < num_days; i++)
    {
        playing_decision(&daily_records[i]);
    }

    return 0;
}
