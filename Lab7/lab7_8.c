#include <stdio.h>
#include <ctype.h>

void swap_letter(char one_text[]);
int check_same(char text1[], char text2[]);

int main() {
    char text1[101], text2[101];
    char swapped_text1[101], swapped_text2[101];
    int i;

    scanf("%[^\n]", text1);
    getchar(); 
    scanf("%[^\n]", text2);

    for (i = 0; text1[i] != '\0'; i++) {
        swapped_text1[i] = text1[i];
    }
    swapped_text1[i] = '\0';

    for (i = 0; text2[i] != '\0'; i++) {
        swapped_text2[i] = text2[i];
    }
    swapped_text2[i] = '\0';

    swap_letter(swapped_text1);
    swap_letter(swapped_text2);

    printf("*** Results ***\n");
    printf("%s\n", swapped_text1);
    printf("%s\n", swapped_text2);
    printf("***************\n");

    if (check_same(text1, text2) == 0) {
        printf("Both strings are the same.");
    } else {
        printf("Both strings are not the same.");
    }

    return 0;
}

void swap_letter(char one_text[]) {
    for (int i = 0; one_text[i] != '\0'; i++) {
        if (islower(one_text[i])) {
            one_text[i] = toupper(one_text[i]);
        } else if (isupper(one_text[i])) {
            one_text[i] = tolower(one_text[i]);
        }
    }
}

int check_same(char text1[], char text2[]) {
    int i = 0;
    while (text1[i] != '\0' && text2[i] != '\0') {
        if (tolower(text1[i]) != tolower(text2[i])) {
            return 1;
        }
        i++;
    }
    if (text1[i] != text2[i]) {
        return 1;
    }
    return 0;
}
