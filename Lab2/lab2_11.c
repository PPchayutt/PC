#include <stdio.h>

int main() {
    int p1;
    int p2;
    int final_num;

    scanf("%2d%3d", &p1, &p2);

    final_num = (p2 * 100) + p1;

    printf("%d\n", final_num);

    return 0;
}
