#include <stdio.h>

int main() {
    int quacks;

    scanf("%d", &quacks);

    if (quacks < 0) {
        printf("Error");
    }
    else if (quacks == 0) {
        printf("Duck Type: Silent Duck");
    }
    else if (quacks <= 10) {
        printf("Duck Type: Chill Duck");
    }
    else if (quacks <= 50) {
        printf("Duck Type: Happy Duck");
    }
    else {
        printf("Duck Type: Talkative Duck");
    }

    return 0;
}
