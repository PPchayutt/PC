#include <stdio.h>

int main() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    float result = (float)a / b;
    
    printf("%.2f", result);

    return 0;
}
