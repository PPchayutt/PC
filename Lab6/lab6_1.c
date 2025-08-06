#include <stdio.h>

int main() {
    int m[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int n[] = {1, 3, 9, 7, 11, 15, 19};
    int m_size = 8, n_size = 7;
    int input, found;
    
    do {
        scanf("%d", &input);
    } while (input < 1 || input > 20);
    
    for (int i = 0; i < m_size; i++) {
        if (m[i] == input) {
            printf("%d is in M at index [%d]", input, i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        for (int i = 0; i < n_size; i++) {
            if (n[i] == input) {
                printf("%d is in N at index [%d]", input, i);
                found = 1;
                break;
            }
        }
    }

    if (found == 0) {
        printf("%d is not in neither M nor N", input);
    }

    return 0;
}
