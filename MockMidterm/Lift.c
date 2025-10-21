#include <stdio.h>

int main() {
    int n, age;
    int has_child_under_12 = 0, has_adult = 0;
    double lift_maxWeight, personWeight, totalWeight = 0;

    scanf("%d", &n);
    scanf("%lf", &lift_maxWeight);

    for (int i = 0; i < n; i++) {
        scanf("%d", &age);
        scanf("%lf", &personWeight);
    
        totalWeight += personWeight;

        if (age < 12) {
            has_child_under_12 = 1;
        } else {
            has_adult = 1;
        }
    }

    if (totalWeight > lift_maxWeight) {
        printf("Not Safe");
        return 0;
    }

    if (has_child_under_12 == 1 && has_adult == 0) {
        printf("Not Safe");
        return 0;
    }
    
    printf("Safe");

    return 0;
}
