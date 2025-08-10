#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char names[20][61];
    int num_names = 20;

    for (int i = 0; i < num_names; i++) {
        scanf(" %[^\n]", names[i]);
    }

    for (int i = 0; i < num_names; i++) {
        for (int j = 0; names[i][j] != '\0'; j++) {
            names[i][j] = tolower(names[i][j]);
        }

        names[i][0] = toupper(names[i][0]);

        for (int j = 0; names[i][j] != '\0'; j++) {
            if (names[i][j] == ' ') {
                names[i][j + 1] = toupper(names[i][j + 1]);
                break;
            }
        }
    }

    char temp[61];
    for (int i = 0; i < num_names - 1; i++) {
        for (int j = 0; j < num_names - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < num_names; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
