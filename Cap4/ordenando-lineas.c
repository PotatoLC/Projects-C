/*
El programa lee líneas de entrada y las ordena alfabéticamente utilizando el algoritmo de ordenación QuickSort. 
Luego, imprime las líneas ordenadas. Si la entrada supera el límite máximo de líneas a ordenar (MAXLINES), muestra un mensaje de error.
*/


#include <stdio.h>
#include <string.h>
#include "librerialineas.h"
#include "gestorbuffer.h"

#define MAXLINES 5000 /*max numero de lineas a ordenar*/

char *lineptr[MAXLINES];

/*ordena las líneas*/
int main(){
    int nlines;
    if((nlines=readlines(lineptr,MAXLINES))>=0){
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("error: entrada demasiado grande para ser ordenado\n");
        return 1;
    }
}
