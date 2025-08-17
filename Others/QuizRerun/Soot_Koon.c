#include <stdio.h>

int main() {
    int m, n;

    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d x %d = %d\n", m, i, m * i);
    }

    return 0;
}
