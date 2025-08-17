#include <stdio.h>
#include <math.h>

int main(){
    long long x=0, y=0;
    scanf("%lld %lld",&x, &y);
    printf("sqrt(%lld^2+%lld^2)=%.2lf", x, y, sqrt((double)x*(double)x+(double)y*(double)y));
    return 0;
}