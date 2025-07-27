#include <stdio.h>

int main() {
    char letter;

    scanf(" %c", &letter);

    if (letter >= 'a' && letter <= 'z') {
        char upper = letter - 32;
        printf("%c", upper);
    }
    else if (letter >= 'A' && letter <= 'Z') {
        char lower = letter + 32;
        printf("%c", lower);
    }
    else {
        printf("error");
    }

    return 0;
}
