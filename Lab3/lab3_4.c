#include <stdio.h>

int main() {
    double num1, num2;
    double sum, difference, product, quotient;

    scanf("%lf, %lf", &num1, &num2);

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;

    printf("The sum of the given numbers : %lf\n", sum);
    printf("The difference of the given numbers : %lf\n", difference);
    printf("The product of the given numbers : %lf\n", product);
    printf("The quotient of the given numbers : %lf\n", quotient);

    return 0;
}
