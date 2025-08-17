#include <stdio.h>

int main() {
    char tyre_code;

    scanf(" %c", &tyre_code);

    switch (tyre_code) {
        case 'S':
        case 's':
            printf("Soft");
            break;
        case 'M':
        case 'm':
            printf("Medium");
            break;
        case 'H':
        case 'h':
            printf("Hard");
            break;
        case 'I':
        case 'i':
            printf("Intermediate");
            break;
        case 'W':
        case 'w':
            printf("Wet");
            break;
    }

    return 0;
}
