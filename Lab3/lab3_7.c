#include <stdio.h>

int main() {
    float price, discountP, count;
    float discountRate, totalprice, discountPrice, finalTotalPrice;

    scanf("%f", &price);
    scanf("%f", &discountP);
    scanf("%f", &count);

    totalprice = count * price;
    discountRate = discountP / 100;
    discountPrice = discountRate * totalprice;
    finalTotalPrice = totalprice - discountPrice;
    
    printf("%.2f\n", finalTotalPrice);

    return 0;
}
