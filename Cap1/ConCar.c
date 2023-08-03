/*
El programa cuenta el número de líneas en la entrada de texto y muestra el resultado al final. 
Utiliza un bucle while para leer cada carácter de la entrada hasta que se alcance el final del archivo (EOF), 
incrementando el contador de líneas cada vez que encuentra un carácter de nueva línea '\n'
*/
#include <stdio.h>

main(){
    int c, nl;
    nl = 0;

    while ( c=getchar() != EOF) {
        if ( c == '\n') ++ nl ;
    }

    printf("Total de lineas: %d", nl);
}
