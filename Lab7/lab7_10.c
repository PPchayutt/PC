#include <stdio.h>

long long findWays(int n);

int main() {
    int n;
    scanf("%d", &n);
    long long result = findWays(n);

    printf("method = %lld", result);

    return 0;
}

long long findWays(int n) {
    if (n <= 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    long long prev2 = 1;
    long long prev1 = 2;
    long long current_ways;

    for (int i = 3; i <= n; i++) {
        current_ways = prev1 + prev2;
        prev2 = prev1;
        prev1 = current_ways;
    }

    return current_ways;
}
