#include <stdio.h>

int main() {
    char input_char;

    scanf(" %c", &input_char);

    if (input_char >= 'a' && input_char <= 'z') {
        char upper_char = input_char - 32;
        printf("%c", upper_char);
    }
    else if (input_char >= 'A' && input_char <= 'Z') {
        char lower_char = input_char + 32;
        printf("%c", lower_char);
    }
    else {
        printf("error");
    }

    return 0;
}
