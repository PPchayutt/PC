#include <stdio.h>

int main() {
    char num[6];

    scanf("%s", num);

    printf("%.1s", num);
    printf("%79s", "");
    printf("%3.2s", num);
    printf("%78s", "");
    printf("%4.3s", num);
    printf("%77s", "");
    printf("%5.4s", num);
    printf("%76s", "");
    printf("%6.5s", num);

    return 0;
}
