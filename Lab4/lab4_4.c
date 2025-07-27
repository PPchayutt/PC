#include <stdio.h>

int main() {
    double score;

    scanf("%lf", &score);

    if (score <= 100 && score >= 80) {
        printf("A");
    }
    else if (score < 80 && score >= 70) {
        printf("B");
    }
    else if (score < 70 && score >= 60) {
        printf("C");
    }
    else if (score < 60 && score >= 50) {
        printf("D");
    }
    else if (score < 50 && score >= 0) {
        printf("F");
    }
    else{
        printf("Out of Range");
    }

    return 0;
}
