#include <stdio.h>
#include <string.h>

int main() {
    char text[101];

    scanf("%[^\n]", text);

    int len = strlen(text);
    int is_palindrome = 1;

    for (int i = 0; i < len / 2; i++) {
        if (text[i] != text[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome == 1) {
        printf("It is Palindrome.");
    } else {
        printf("It is not Palindrome.");
    }
    
    return 0;
}
