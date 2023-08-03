#include <stdio.h>

#define MAX_LINE 1000

void mystrcpy(char *s, char *t);
int strcmp(char *s, char *t);


int main () {
    char origen[] ="Paco tiene un coche amarillooooooojj";
    char copia[MAX_LINE];
    
    mystrcpy(copia, origen);

    printf("%s\n", copia);
    printf("%d", strcmp(copia, origen));

    return 0;
}

void mystrcpy(char *s, char *t) {
    while ((*s=*t) != '\0') {
        s++;
        t++;    
    }
    
}

// Regresa < 0 si s<t, 0  si s == t, >0 si s>t
int strcmp(char *s, char *t) {

    for(; *s==*t; s++, t++) {
        if (*s == '\0') return 0;
    }

    return *s-*t;
}