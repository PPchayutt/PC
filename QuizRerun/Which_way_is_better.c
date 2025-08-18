#include <stdio.h>

int main() {
    double fuel_price;
    int chosen_routes[4];
    double efficiencies[4];

    scanf("%lf", &fuel_price);

    for (int i = 0; i < 4; i++) {
        scanf("%d", &chosen_routes[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &efficiencies[i]);
    }

    double total_cost_expressway = 0;
    double total_cost_romklao = 0;
    int days_on_expressway = 0;
    int days_on_romklao = 0;

    for (int i = 0; i < 4; i++) {
        double daily_liters, daily_cost;

        if (chosen_routes[i] == 1) {
            daily_liters = 29.0 / efficiencies[i];
            daily_cost = (daily_liters * fuel_price) + 60.0;
            total_cost_expressway += daily_cost;
            days_on_expressway++;
            
            printf("Day %d: fuel %.2f L, cost %.2f Baht\n", i + 1, daily_liters, daily_cost);

        } else {
            daily_liters = 25.0 / efficiencies[i];
            daily_cost = daily_liters * fuel_price;
            total_cost_romklao += daily_cost;
            days_on_romklao++;

            printf("Day %d: fuel %.2f L, cost %.2f Baht\n", i + 1, daily_liters, daily_cost);
        }
    }

    double avg_expressway = 0;
    if (days_on_expressway > 0) {
        avg_expressway = total_cost_expressway / days_on_expressway;
    }

    double avg_romklao = 0;
    if (days_on_romklao > 0) {
        avg_romklao = total_cost_romklao / days_on_romklao;
    }
    
    printf("Expressway: %.2f Baht\n", avg_expressway);
    printf("Romklao: %.2f Baht", avg_romklao);

    return 0;
}
