#include <stdio.h>
#include <math.h>

int main() {
    char paper_type;
    int size1, size2, diff;

    scanf(" %c%d", &paper_type, &size1);
    scanf(" %c%d", &paper_type, &size2);

    if (size1 > size2) {
        diff = size1 - size2;
    } else {
        diff = size2 - size1;
    }

    int result = (int)pow(2, diff);

    printf("%d", result);

    return 0;
}
