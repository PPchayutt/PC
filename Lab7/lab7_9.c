#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
#define G 9.81

int main() {
    int theta_degree, u;

    scanf("%d", &theta_degree);
    scanf("%d", &u);

    double theta_radian = theta_degree * PI / 180.0;
    double numerator = pow(u, 2) * pow(sin(theta_radian), 2);
    double denominator = 2 * G;
    double h = numerator / denominator;

    printf("theta (degree) : %d\n", theta_degree);
    printf("u (m/s) : %d\n", u);
    printf("h (m) : %.4f\n", h);

    return 0;
}
