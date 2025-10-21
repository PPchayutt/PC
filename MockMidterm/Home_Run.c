#include <stdio.h>

int main() {
    int n, count;
    double distance, fieldSize;

    scanf("%d", &n);
    scanf("%lf", &distance);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &fieldSize);
        if (distance > fieldSize) {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}
