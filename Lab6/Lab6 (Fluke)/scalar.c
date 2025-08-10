#include <stdio.h>
 
int main(){
    double mat[3][3];
    for(int i = 0; i < 3; i++){
        scanf("%lf %lf %lf", &mat[i][0], &mat[i][1], &mat[i][2]);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                if(mat[i][j] != mat[0][0]){
                    printf("This is not a scalar matrix");
                    return 0;
                }
            }
            else{
                if(mat[i][j] != 0.0){
                    printf("This is not a scalar matrix");
                    return 0;
                }
            }
        }
    }
    printf("This is a scalar matrix");
    return 0;
}