#include <stdio.h>

int main() {
    float price, circum, height;
    float radius, volume, price_per_ml;

    scanf("%f", &price);
    scanf("%f", &circum);
    scanf("%f", &height);
    
    radius = circum / 2;
    volume = height * 3.14159265359 * (radius * radius);
    price_per_ml = price / volume;

    printf("Volume : %.2fml\n", volume);
    printf("Baht/ml : %.4f\n", price_per_ml);

    return 0;
}
