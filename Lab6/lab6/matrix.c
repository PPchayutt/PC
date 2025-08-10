#include <stdio.h>
 
int main(){
    double matA[3][3];
    double matB[3][3];
    for(int i = 0; i < 3; i++){
        scanf("%lf %lf %lf", &matA[i][0], &matA[i][1], &matA[i][2]);
    }
    for(int i = 0; i < 3; i++){
        scanf("%lf %lf %lf", &matB[i][0], &matB[i][1], &matB[i][2]);
    }
    printf("A x B\n");
    for(int i = 0; i < 3; i++){
        printf("%.2lf %.2lf %.2lf\n", 
            matA[i][0] * matB[0][0] + matA[i][1] * matB[1][0] + matA[i][2] * matB[2][0],
            matA[i][0] * matB[0][1] + matA[i][1] * matB[1][1] + matA[i][2] * matB[2][1],
            matA[i][0] * matB[0][2] + matA[i][1] * matB[1][2] + matA[i][2] * matB[2][2]
        );
    }
    return 0;
}