// El programa intercambia los valores de dos variables utilizando la función swap. Imprime los valores antes y después del intercambio.

#include <stdio.h>

void swap(int *px, int *py);

int main() {
    int num1, num2;

    num1 = 20;
    num2 = 35;

    printf("Numeros antes del swap num1: %d, num2: %d \n\n", num1, num2);
    swap(&num1, &num2);
    printf("Numeros despues del swap num1: %d, num2: %d \n\n", num1, num2);

}

void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
