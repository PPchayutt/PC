#include <stdio.h>
#include <math.h>

int main(){
    char t;
    int size1;
    int size2;
    scanf(" %c%d", &t, &size1);
    scanf(" %c%d", &t, &size2);
    printf("%d", (int)pow(2, size1 > size2 ? size1 - size2 : size2 - size1));
    return 0;
}