#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n;
    char name1[50], name2[50], name3[50];
    scanf("%d", &n);
    scanf("%s %s %s", name1, name2, name3);

    double n1, n2, n3;
    double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf", &n1, &n2, &n3);
        sum1 += n1;
        sum2 += n2;
        sum3 += n3;
    }

    double capacity1 = (strcmp(name1, "Nano") == 0) ? 6.6 : 5.5;
    double capacity2 = (strcmp(name2, "Nano") == 0) ? 6.6 : 5.5;
    double capacity3 = (strcmp(name3, "Nano") == 0) ? 6.6 : 5.5;

    int d1 = (int)ceil(sum1 / capacity1);
    int d2 = (int)ceil(sum2 / capacity2);
    int d3 = (int)ceil(sum3 / capacity3);

    printf("%s: %d refills\n", name1, d1);
    printf("%s: %d refills\n", name2, d2);
    printf("%s: %d refills\n", name3, d3);

    return 0;
}
