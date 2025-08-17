#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

double findH(double theta, double velocity){
    return (pow(velocity, 2)*pow(sin(theta * PI / 180),2) / (2 * 9.81));
}

int main(){
    int theta = 0;
    int velocity = 0;
    scanf("%d", &theta);
    scanf("%d", &velocity);

    printf("theta (degree) : %d\n", theta);
    printf("u (m/s) : %d\n", velocity);
    printf("h (m) : %.4lf", findH(theta, velocity));
    return 0;
}