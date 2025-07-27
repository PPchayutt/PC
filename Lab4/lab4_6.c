#include <stdio.h>
#include <ctype.h>

int main() {
    char txt;

    scanf(" %c", &txt);

    if (isdigit(txt)) {
        printf("number");
    }
    else if (islower(txt)) {
        printf("lowercase");
    }
    else if (isupper(txt)) {
        printf("uppercase");
    }
    else {
        printf("error");
    }

    return 0;
}
