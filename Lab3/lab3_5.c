#include <stdio.h>

int main() {
    double width, length, perimeter;

    scanf("%lf", &width);
    scanf("%lf", &length);

    perimeter = (width * 2) + (length * 2);

    printf("Perimeter of rectangle = %.4lf units", perimeter);

    return 0;
}
