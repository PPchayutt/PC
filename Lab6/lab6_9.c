#include <stdio.h>
#include <ctype.h>

int main() {
    int n;
    char seen_chars[27] = {0};
    int counts[26] = {0};
    int seen_count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char current_char;
        scanf(" %c", &current_char);

        if (isalpha(current_char)) {
            current_char = tolower(current_char);

            int found = 0;
            for (int j = 0; j < seen_count; j++) {
                if (seen_chars[j] == current_char) {
                    counts[j]++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                seen_chars[seen_count] = current_char;
                counts[seen_count] = 1;
                seen_count++;
            }
        }
    }

    for (int i = 0; i < seen_count; i++) {
        printf("%c: %d\n", seen_chars[i], counts[i]);
    }

    return 0;
}
