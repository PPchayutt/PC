#include <stdio.h>

int main() {
    float height, weight;
    float bmi;

    scanf("%f", &height);
    scanf("%f", &weight);

    bmi = weight / ((height / 100) * (height / 100));

    printf("%f", bmi);

    return 0;
}
