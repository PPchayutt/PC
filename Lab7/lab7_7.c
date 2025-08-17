#include <stdio.h>
#include <string.h>
#include <ctype.h>

void correctName(char name[]);
void sortName(char names[][61], int n);

int main() {
    int n;
    scanf("%d", &n);
    char names[n][61];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", names[i]);
    }

    for (int i = 0; i < n; i++) {
        correctName(names[i]);
    }

    sortName(names, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

void correctName(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            name[i + 1] = toupper(name[i + 1]);
        }
    }
}

void sortName(char names[][61], int n) {
    char temp[61];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}
