#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    int n = 0, m = 1;
    
    scanf(" %d", &n);
    scanf(" %d%*c", &m);

    str = (char *)malloc((n + 1) * sizeof(char));
    if (str == NULL) {
        return 1;
    }

    char temp_char;
    int actual_len = 0;

    while (actual_len < n && scanf("%c", &temp_char) == 1 && temp_char != '\n') {
        *(str + actual_len) = temp_char;
        actual_len++;
    }
    *(str + actual_len) = '\0';

    for (int i = 0; i < actual_len; i += m) {
        printf("%c", *(str + i));
    }

    printf("\n");
    free(str);
    return 0;
}
