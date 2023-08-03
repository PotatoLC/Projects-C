// El programa lee líneas de entrada y muestra la línea más larga encontrada.

#include <stdio.h>

#define MAX_LINE 1000

int getLine(char s[], int maxline);
void copy(char to[], char from[]);

main() {
    int len, max; 

    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;
    while (( len = getLine(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    } if (max > 0) {
        printf("La linea mas larga es: \n %s", longest);
    } return 0;
}

// Lee la linea y regresa su longitud
int getLine(char s[], int maxline) {
    int c, i;

    for( i = 0; (i < maxline - 1) && ((c = getchar()) != EOF) && (c != '\n'); i ++) {
        s[i] = c;
    } if (c == '\n'){
        s[i] = c;
        i ++;
    } 
    s[i]='\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i=0;
    while ((to[i] = from[i]) != '\0') {
        i ++;
    }
}
