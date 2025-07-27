#include <stdio.h>

int main() {
    int celsius;
    float fahrenheit;

    scanf("%d", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32;

    printf("%.1f\n", fahrenheit);
    
    return 0;
}
