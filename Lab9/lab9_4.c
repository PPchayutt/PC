#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    int capacity = 10;
    int size = 0;
    char ch;

    str = (char *)malloc(capacity * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        scanf(" %c", &ch);

        if (ch == '-') break;

        if (size >= capacity) {
            capacity *= 2;
            char *temp = (char *)realloc(str, capacity * sizeof(char));
            if (temp == NULL) {
                free(str);
                printf("Memory reallocation failed\n");
                return 1;
            }
            str = temp;
        }

        *(str + size) = ch;
        size++;
    }

    *(str + size) = '\0';


    printf("%s\n", str);

    char *ptr = str + size - 1;
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");

    free(str);
    return 0;
}
