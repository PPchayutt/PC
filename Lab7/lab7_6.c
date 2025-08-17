#include <stdio.h>
#include <math.h>

int main() {
    long long x, y;
    double c;

    scanf("%lld %lld", &x, &y);

    c = sqrt(pow(x, 2) + pow(y, 2));

    printf("sqrt(%lld^2+%lld^2)=%.2lf", x, y, c);

    return 0;
}
