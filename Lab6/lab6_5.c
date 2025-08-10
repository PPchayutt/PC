#include <stdio.h>
#include <ctype.h>

int main() {
    char text[301];
    char find;
    
    scanf("%[^\n]", text);
    scanf(" %c", &find);

    int count = 0;
    int positions[301];
    int len = 0;

    while (text[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (tolower(text[i]) == tolower(find)) {
            positions[count] = i + 1;
            count++;
        }
    }

    if (count > 0) {
        printf("There is/are %d \"%c\" in the above sentences.\n", count, tolower(find));
        printf("Position: ");
        for (int i = 0; i < count; i++) {
            printf("%d", positions[i]);
            if (i < count - 1) {
                printf(", ");
            }
        }
    } else {
        printf("Not found.");
    }

    return 0;
}
