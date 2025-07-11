#include <stdio.h>

int main() {
    int number;
    int first_two;
    int last_three;
    int result;

    scanf("%d", &number);

    last_three = number % 1000;
    first_two = number / 1000;
    result = (last_three * 100) + first_two;

    printf("%d\n", result);

    return 0;
}
