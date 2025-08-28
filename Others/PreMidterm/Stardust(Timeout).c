#include <stdio.h>
#include <math.h>
 
double findavg(double num[], int n){
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        ans += num[i];
    }
    return ans / n;
}
 
double findmedian(double num[], int n){
    double sortednum[n];
    for(int i = 0; i < n; i++){
        sortednum[i] = num[i];
    }
    int isswap = 1;
    while (isswap == 1){
        isswap = 0;
        for(int i = 1; i < n; i++){
            if(sortednum[i - 1] > sortednum[i]){
                double temp = sortednum[i];
                sortednum[i] = sortednum[i - 1];
                sortednum[i - 1] = temp;
                isswap = 1;
            }
        }
    }
    if(n % 2 == 0){
        double te[] = {sortednum[n / 2], sortednum[n / 2 + 1]};
        return findavg(te , 2);
    }
    return sortednum[n / 2];
    
}
 
double findstd(double num[], int n){
    double avg = findavg(num, n);
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += pow(num[i] - avg, 2);
    }
    return sqrt(ans / n);
}
 
int main(){
    int n;
    scanf("%d", &n);
    double num[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
    }
    printf("%.2lf\n", findavg(num, n));
    printf("%.2lf\n", findmedian(num, n));
    printf("%.2lf", findstd(num, n));
    return 0;
}
