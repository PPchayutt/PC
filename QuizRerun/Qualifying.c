#include <stdio.h>

int main() {
    double time1, time2, time3;
    char name1[100], name2[100], name3[100];

    scanf("%lf %[^\n]", &time1, name1);
    scanf("%lf %[^\n]", &time2, name2);
    scanf("%lf %[^\n]", &time3, name3);

    double fastest_time = time1;
    int fastest_driver = 1;

    if (time2 < fastest_time) {
        fastest_time = time2;
        fastest_driver = 2;
    }
    if (time3 < fastest_time) {
        fastest_time = time3;
        fastest_driver = 3;
    }

    if (fastest_driver == 1) {
        printf("%s is Fastest : %.3f", name1, fastest_time);
    } else if (fastest_driver == 2) {
        printf("%s is Fastest : %.3f", name2, fastest_time);
    } else {
        printf("%s is Fastest : %.3f", name3, fastest_time);
    }

    return 0;
}
