#include <stdio.h>
 
double getValue(){
    double value;
    scanf("%lf", &value);
    return value;
}
double findMin(double array[], int size){
    int ind = 0;
    for(int i = 1; i < size; i++){
        if(array[i] < array[ind]){
            ind = i;
        }
    }
    return array[ind];
}
double findMax(double array[], int size){
    int ind = 0;
    for(int i = 1; i < size; i++){
        if(array[i] > array[ind]){
            ind = i;
        }
    }
    return array[ind];
}
double findAvg(double array[], int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum / size;
}
 
int main(){
    int size = 1;
    scanf("%d", &size);
    double array[size];
    for(int i = 0; i < size; i++){
        array[i] = getValue();
    }
    printf("%d Values\n", size);
    printf("Min: %.3lf\n", findMin(array, size));
    printf("Max: %.3lf\n", findMax(array, size));
    printf("Avg: %.3lf\n", findAvg(array, size));
    return 0;
}