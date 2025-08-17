#include <stdio.h>
#include <math.h>

double perimeter(double a, double b);
double area(double a, double b);

int main() {
    double a, b;
    
    scanf("%lf", &a);
    scanf("%lf", &b);

    double p_result = perimeter(a, b);
    double a_result = area(a, b);

    printf("Perimeter: %.2f\n", p_result);
    printf("Area: %.2f\n", a_result);

    return 0;
}

double perimeter(double a, double b) {
    double c = sqrt(pow(a, 2) + pow(b, 2));
    return a + b + c;
}

double area(double a, double b) {
    return 0.5 * a * b;
}
