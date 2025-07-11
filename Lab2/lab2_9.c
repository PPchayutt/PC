#include <stdio.h>

int main() {
    char c1, c2, c3, c4, c5;

    scanf(" %c", &c1);
    scanf(" %c", &c2);
    scanf(" %c", &c3);
    scanf(" %c", &c4);
    scanf(" %c", &c5);

    c1 = c1 + 1;
    c3 = c3 + 1;
    c5 = c5 + 1;

    printf("%c\n", c1);
    printf("%c\n", c2);
    printf("%c\n", c3);
    printf("%c\n", c4);
    printf("%c\n", c5);

    return 0;
}
