#include <stdio.h>

int main() {
    double km;

    scanf("%lf", &km);

    if (km < 0 || km > 58.855) {
        printf("InValid");
    }
    else if (km <= 5.032) {
        printf("Bangkok");
    }
    else if (km <= 35.477) {
        printf("Samut Prakarn");
    }
    else if (km <= 52.900) {
        printf("Chachoengsao");
    }
    else { 
        printf("Chon Buri");
    }

    return 0;
}
