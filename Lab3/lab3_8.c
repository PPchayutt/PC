#include <stdio.h>

int main() {
    long long total_seconds;
    long long days, hours, minutes, seconds, remainder;

    scanf("%lld", &total_seconds);

    days = total_seconds / 86400;
    remainder = total_seconds % 86400;
    hours = remainder / 3600;
    remainder = remainder % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60;

    printf("%lld s = %lld d %lld h %lld m %lld s\n", total_seconds, days, hours, minutes, seconds);

    return 0;
}
