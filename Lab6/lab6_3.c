#include <stdio.h>

int main() {
    double matrix[3][3];
    double scalar_value;
    int is_scalar = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    scalar_value = matrix[0][0];

    if (scalar_value == 0) {
        is_scalar = 0;
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    if (matrix[i][j] != scalar_value) {
                        is_scalar = 0;
                    }
                } else {
                    if (matrix[i][j] != 0) {
                        is_scalar = 0;
                    }
                }
            }
        }
    }

    if (is_scalar == 1) {
        printf("This is a scalar matrix");
    } else {
        printf("This is not a scalar matrix");
    }

    return 0;
}
