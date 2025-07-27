#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("Triangle is valid.");
    } 
    else {
        printf("Triangle is not valid.");
    }

    return 0;
}
