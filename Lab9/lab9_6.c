#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    int amount_lower = 0, amount_upper = 0, amount_digit = 0;

    str = (char *)malloc(101 * sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    scanf("%[^\n]", str);

    for (int i = 0; *(str + i) != '\0'; i++) {
        if (*(str + i) >= 'a' && *(str + i) <= 'z') {
            amount_lower++;
        } else if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
            amount_upper++;
        } else if (*(str + i) >= '0' && *(str + i) <= '9') {
            amount_digit++;
        }
    }

    printf("Lowercase letters: %d\n", amount_lower);
    printf("Uppercase letters: %d\n", amount_upper);
    printf("Digits: %d\n", amount_digit);

    free(str);

    return 0;
}
