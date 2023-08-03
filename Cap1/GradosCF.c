/*
    Programa de conversion de Celsius a Fahrenheit 
*/

#include <stdio.h>
// Grados de C a F, desde los .10°C hasta los 50°C, de 10° en 10°
// Formula de C a F ----> F = (C * 5/9) + 32

main() {
    float celsius;

    int lower = -10;
    int upper = 50;
    int step = 10;

    printf("\n\n");
    for(celsius = lower; celsius <= upper; celsius + step) {
        printf("%3.0f° Celsius ----> %6.2f Fahrenheit \n", celsius, (celsius*(5.0/9.0) + 32));
    }
}