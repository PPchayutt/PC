#include <stdio.h>

int main() {
    float num1, num2, num3, num4, sum, avg;

    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);
    scanf("%f", &num4);

    sum = num1 + num2 + num3 + num4;
    avg = sum / 4;

    printf("Summation is %.2f\n", sum);
    printf("Average is %.3f\n", avg);

    return 0;
}
