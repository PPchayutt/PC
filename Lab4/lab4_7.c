#include <stdio.h>

int main() {
    double price, discount_percent, final_price1, final_price2;
    int quantity, free_shirt, paid_shirt;

    scanf("%lf", &price);
    scanf("%lf", &discount_percent);
    scanf("%d", &quantity);

    final_price1 = (price * quantity) * (1 - discount_percent / 100.0);

    free_shirt = quantity / 3;
    paid_shirt = quantity - free_shirt;
    final_price2 = paid_shirt * price;

    if (final_price1 <= final_price2) {
        printf("Discount %.0f%%\n", discount_percent);
        printf("%.2f\n", final_price1);
    }
    else {
        printf("Buy 2 Get 1\n");
        printf("%.2f\n", final_price2);
    }

    return 0;
}
