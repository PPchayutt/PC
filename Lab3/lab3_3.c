#include <stdio.h>
#include <math.h>

int main() {
    double sideA, sideB, sideC;

    scanf("%lf",&sideA);
    scanf("%lf",&sideB);

    sideC = sqrt(pow(sideA, 2) + pow(sideB, 2));

    printf("%.2lf", sideC);

    return 0;
}
