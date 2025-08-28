#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main(){
    int floorsrc;
    int floordest;
    scanf("%d %d", &floorsrc, &floordest);
    double height;
    if(floorsrc != 1 && floordest != 1){
        height = 4 * abs(floorsrc - floordest);
    }
    else{
        height = 4 * abs(floorsrc - floordest) + 2;
    }
    double ans = (1.5 / 0.5) + ((height - 2 * pow(1.5,2) / (2 * 0.5)) / 1.5) + (1.5 / 0.5);
    printf("%.2lf", ans);
    return 0;
}
