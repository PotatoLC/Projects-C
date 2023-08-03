/*
El programa convierte líneas de entrada en números de punto flotante utilizando la función atof, una versión propia de atof 
para convertir cadenas en números de punto flotante. Luego, imprime los resultados con un formato específico.
*/


#include <stdio.h>
#include <ctype.h>
#include "libreria.h"

double atof(char s[]);

int main() {
    char line[MAXLINE];
    int found = 0;

    while(myGetLine(line, MAXLINE) > 0) {
        printf("\t %6.3 \n ", atof(line));
    }
    return 0;
}

// MyGetLine --> Trae una linea y la pone en s, regresa so longitud

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? - 1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0; 
    }
    
    return sign * val / power;

}
