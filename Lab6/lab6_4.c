#include <stdio.h>

int main() {
    int size = 0;
    char text[101];

    scanf("%[^\n]", text);

    for (int i=0; i<101; i++) {
        if (text[i] == '\0') {
            break;
        }
        size += 1;
    }

    while (size != 0) {
        printf("%c", text[--size]);
    }
    
    return 0;
}
