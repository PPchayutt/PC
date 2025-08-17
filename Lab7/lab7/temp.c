#include <stdio.h>

double ctf(double c);
 
double ftc(double f);
 
void printfh(double f);
 
void printc(double c);
 
int main(){
    double temp;
    char unit;
    scanf(" %lf %c", &temp, &unit);
    if(unit == 'c' || unit == 'C'){
        printfar(ctf(temp));
    }
    else if(unit == 'f' || unit == 'F'){
        printcel(ftc(temp));
    }
    return 0;
}

double ctf(double c){
    return (9.0 / 5.0) * c + 32;
}
 
double ftc(double f){
    return (5.0 / 9.0) * (f - 32);
}
 
void printfh(double f){
    printf("%.2lf f", f);
}
 
void printc(double c){
    printf("%.2lf c", c);
}