#include <stdio.h>

void filecopy(FILE *, FILE *);

int main( int argc, char *argv[]) {

    FILE *fp;
    char *prog = argv[0];

    freopen("error.log", "w", stderr);

    if (argc == 1) {
        filecopy(stdin, stdout);
    }
    else {
        while ( --argc>0) {
            if (( fp = fopen(*++argv, "r")) == NULL ) {
                fprintf(stderr, "\n\n %s: No puede abrir el fichero %s\n\n", prog, *argv);
                fclose(stderr);
                return 1;
            }
            else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}


// Filecopy ---> Copia de un puntero a otro
void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }

}
