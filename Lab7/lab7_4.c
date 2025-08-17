#include <stdio.h>

double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
void printFahrenheit(double fahrenheit);
void printCelcius(double celcius);

int main() {
    double temp;
    char unit;

    scanf("%lf %c", &temp, &unit);

    if (unit == 'c' || unit == 'C') {
        double result_f = celsiusToFahrenheit(temp);
        printFahrenheit(result_f);
    } 
    else if (unit == 'f' || unit == 'F') {
        double result_c = fahrenheitToCelsius(temp);
        printCelcius(result_c);
    }

    return 0;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

void printFahrenheit(double fahrenheit) {
    printf("%.2f f", fahrenheit);
}

void printCelcius(double celcius) {
    printf("%.2f c", celcius);
}
