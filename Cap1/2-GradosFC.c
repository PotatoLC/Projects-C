/*
    Programa de conversion de Fahrenheit a Celsius 
*/

#include <stdio.h>
// Grados de F a C, desde los 0°F hasta 300°F, de 20° en 20°
// Formula de F a C ----> C = (F-32) * 5/9

main() {
    float fahr;

    int lower = 0;
    int upper = 300;
    int step = 20;

    printf("\n\n");
    for (fahr = upper; fahr >= lower; fahr - step) {
        printf("%3.0f° Fahrenheit ----> %6.2f° Celsius \n", fahr, (fahr-32)*(5.0/9.0));
    }
    printf("\n\n");
}
