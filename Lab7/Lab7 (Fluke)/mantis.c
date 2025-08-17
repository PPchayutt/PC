#include <stdio.h>

int getmethod(int step);

int main(){
    int step = 0;
    scanf("%d", &step);
    printf("method = %d", getmethod(step));
    return 0;
}

int getmethod(int step){
    int previous = 0;
    int current = 1;
    for(int i = 0; i < step; i++){
        int temp = current;
        current += previous;
        previous = temp;
    }
    return current;
}