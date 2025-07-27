#include <stdio.h>

int main() {
    char gender, license;
    double weight, cc_per_can, alcohol_percent, rest_hours;
    int amount;
    
    scanf(" %c", &gender);
    scanf("%lf", &weight);
    scanf(" %c", &license);
    scanf("%lf", &cc_per_can);
    scanf("%lf", &alcohol_percent);
    scanf("%d", &amount);
    scanf("%lf", &rest_hours);

    double max_alcohol;
    if (gender == 'M') {
        max_alcohol = weight * 0.68 * 10;
    } else {
        max_alcohol = weight * 0.55 * 10;
    }

    double total_cc = cc_per_can * amount;
    double alcohol_consumed = (total_cc * alcohol_percent) / 100.0;
    double peak_alcohol = (alcohol_consumed / max_alcohol) * 1000.0;
    double alcohol_eliminated = rest_hours * 15.0;
    double current__alcohol = peak_alcohol - alcohol_eliminated;
    
    if (current__alcohol < 0) {
       current__alcohol = 0;
    }

    if (license == 'N' || current__alcohol >= 50) {
        printf("Not Safe");
    } else {
        printf("Safe");
    }

    return 0;
}
