#include <stdio.h>

int calculateSum(int times[]) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += times[i];
    }
    return sum;
}

int calculateAvg(int sum) {
    return sum / 7;
}

int main() {
    char name1[51], name2[51];
    int times1[7], times2[7];

    scanf(" %[^\n]", name1);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &times1[i]);
    }
    scanf(" %[^\n]", name2);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &times2[i]);
    }

    int sum1 = calculateSum(times1);
    int avg1 = calculateAvg(sum1);
    printf("%s: %d minutes, average %d minutes/day\n", name1, sum1, avg1);

    int sum2 = calculateSum(times2);
    int avg2 = calculateAvg(sum2);
    printf("%s: %d minutes, average %d minutes/day\n", name2, sum2, avg2);

    int p1_faster = 0, p2_faster = 0, equal = 0;
    for (int i = 0; i < 7; i++) {
        if (times1[i] < times2[i]) {
            p1_faster++;
        } else if (times2[i] < times1[i]) {
            p2_faster++;
        } else {
            equal++;
        }
    }
    printf("Faster days - %s: %d, %s: %d, Equal: %d", name1, p1_faster, name2, p2_faster, equal);

    return 0;
}
