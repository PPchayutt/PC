#include <stdio.h>
#include <ctype.h>

int find_index(const char* wheel, char c) {
    for (int i = 0; i < 26; i++) {
        if (wheel[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    const char* wheel = "abxypqrmncedkljoshtufvzgwi";
    char text[201];

    scanf("%[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++) {
        char current_char = text[i];
        
        if (isalpha(current_char)) {
            int is_upper = isupper(current_char);
            int old_index = find_index(wheel, tolower(current_char));
            int new_index = (old_index - 5 + 26) % 26;
            char new_char = wheel[new_index];
            
            if (is_upper) {
                printf("%c", toupper(new_char));
            } else {
                printf("%c", new_char);
            }
        } else {
            printf("%c", current_char);
        }
    }

    return 0;
}
