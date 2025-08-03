#include <stdio.h>

int main() {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    float total_age = 0, total_height = 0, total_weight = 0;
    
    for (int i = 0; i < 50; i++) {
        int age, height, weight;
        scanf("%d %d %d", &age, &height, &weight);

        total_age += age;
        total_height += height;
        total_weight += weight;

        if (age >= 20 && height >= 160) {
            count1++;
        }
        if (age < 20 && (height <= 180 || weight >= 60)) {
            count2++;
        }
        if (age >= 30 && (weight >= 40 && weight <= 80)) {
            count3++;
        }
        if (age < 40 && (weight < 85 || height <= 200)) {
            count4++;
        }
    }

    float avg_height = total_height / 50.0;
    float avg_weight = total_weight / 50.0;

    printf("Age >= 20 and Height >= 160: %d\n", count1);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", count2);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", count3);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", count4);
    printf("Average Age: %d\n", (int)(total_age / 50));
    printf("Average Height: %.2f\n", avg_height);
    printf("Average Weight: %.2f\n", avg_weight);

    return 0;
}
