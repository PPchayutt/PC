#include <stdio.h>

int main() {
    int game_round;
    scanf("%d", &game_round);

    double start_blood = 2800.0;
    double current_blood = start_blood;
    double total_hours = game_round * 0.5;

    for (int h = 1; h <= total_hours; h++) {
        current_blood = current_blood * 0.98;
    }

    double blood_loss = start_blood - current_blood;

    printf("%.2f\n", blood_loss);

    if (blood_loss > 840) {
        printf("Danger");
    } else {
        printf("Safe");
    }

    return 0;
}
