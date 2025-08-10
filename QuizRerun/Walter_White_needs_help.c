#include <stdio.h>

int main() {
    int start, end;
    int sum = 0;

    scanf("%d", &start);
    scanf("%d", &end);

    printf("pass :");

    if (start <= end) {
        for (int i = start; i <= end; i++) {
            if (i % 2 == 0) {
                printf(" %d", i);
                sum += i;
            }
        }
    } else {
        for (int i = start; i >= end; i--) {
            if (i % 2 == 0) {
                printf(" %d", i);
                sum += i;
            }
        }
    }

    printf("\n");
    printf("Sum : %d\n", sum);

    return 0;
}
