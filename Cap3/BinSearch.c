#include <stdio.h>

int binsearch(int x, int v[], int n); 

// Imprime la linea de entrada mas larga
int main() {
    int listaOrdenada[] = {1, 6, 90, 120, 220, 469, 875, 675};
    int num = 469;
    int posEncontrado;

    posEncontrado = -1;

    // Busqueda binaria

    posEncontrado = binsearch(num, listaOrdenada, 8);
    if (posEncontrado> -1) {
        printf("La posicion del numero %d es %d \n", num, posEncontrado);  
    } else printf("Numero no encontrado");
}

// BinSearch: Encuentra x en v[]
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low <= high) {
        mid = (low + high) / 2;
        if(x < v[mid]) {
            high = mid-1;
        }
        else if (x > v[mid]) {
            low = mid+1;
        }
        else return mid;
    }
    return -1; 
}