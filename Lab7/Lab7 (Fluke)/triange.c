#include <stdio.h>
#include <math.h>
 
double perimeter();
double area();
 
int main(){
    double a;
    double b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("Perimeter: %.2lf\n", perimeter(a, b));
    printf("Area: %.2lf", area(a, b));
    return 0;
}
 
double perimeter(double a, double b){
    return a + b + (sqrt(a*a + b*b));
}
double area(double a, double b){
    return 0.5 * a * b;
}