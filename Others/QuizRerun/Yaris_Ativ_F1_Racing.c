#include <stdio.h>

int main() {
    int status, current_lap, sc_lap;
    float gap;
    
    scanf("%d", &status);
    scanf("%f", &gap);
    scanf("%d", &current_lap);
    scanf("%d", &sc_lap);

    int error_count = 0;

    if (status != 1) {
        error_count++;
    }
    if (gap >= 1.0) {
        error_count++;
    }
    if (current_lap <= 2) {
        error_count++;
    }
    if (current_lap - sc_lap < 2) {
        error_count++;
    }

    if (error_count == 0) {
        printf("DRS allowed");
    } else {
        printf("DRS not allowed %d", error_count);
    }

    return 0;
}
