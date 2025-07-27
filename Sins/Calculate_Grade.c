#include <stdio.h>

int main() {
    char info[41];
    int g1, g2, g3, g4, g5, g6;

    scanf(" %[^\n]", info);
    scanf("%d %d %d %d %d %d", &g1, &g2, &g3, &g4, &g5, &g6);

    int total_credits = 18;
    int grade_sum = g1 + g2 + g3 + g4 + g5 + g6;
    double total_grades = grade_sum * 3.0;
    double gpa = total_grades / total_credits;

    printf("Grade announcement 1/2568: %s\n", info);
    printf("GPS/GPA: %.2f\n", gpa);

    return 0;
}
