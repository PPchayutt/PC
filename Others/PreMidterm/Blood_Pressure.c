#include <stdio.h>

int main() {
    double SBP, DBP;

    scanf("%lf", &SBP);
    scanf("%lf", &DBP);

    if (SBP > 140 || DBP > 90){
        printf("Hypertension");
    } else {
        printf("Normal");
    }

    return 0;
}
