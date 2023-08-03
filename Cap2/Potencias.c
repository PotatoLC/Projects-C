// Programa para sacar potencias a un numero

#include <stdio.h>

int power(int base, int power);

int main () {
    int i;
    power(2, 5);
    for (i = 0; i < 10; i ++) {
        printf("%d %d %d \n", i, power(2,i), power(-3,i));
    } return 0;
}

int power(int base, int power) {
    int i, p;
    
    p=1;

    for (i = 0; i < power;  i++) {
        p *= base;
    } return p;
}
