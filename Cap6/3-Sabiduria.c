#include <stdio.h>
#include <string.h>
#include "3-Sabiduria.h"

int menu() {
    char resp = 0;
    printf("\n\nPresiona ENTER para continuar");
    getchar();

    while (resp < '0' || resp > '3') {
        printf("\n---------------------------------------- \n");
        printf("[0] ----> Insertar nueva referencia\n");
        printf("[1] ----> Buscar referencia\n");
        printf("[2] ----> Mostrar cursos\n");
        printf("[3] ----> Salir\n");
        printf("-----------------------------------------");
        printf("\n\n  Tu respuesta ---->  ");
        scanf(" %c", &resp);
        getchar();
    }
    return resp -'0';
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }

}

int mostrarArchivos(int argc, char *argv[]) {
 FILE *fp;
    char *prog = argv[0];

    freopen("error.log", "w", stderr);

    if (argc == 1) {
        fp = fopen("3-Recursos.txt", "r"); // Abrir el archivo
        if (fp == NULL) {
            fprintf(stderr, "\n\n %s: No puede abrir el fichero %s\n\n", prog, "3-Recursos.txt");
            return 1;
        }
        filecopy(fp, stdout); 
        fclose(fp);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "\n\n %s: No puede abrir el fichero %s\n\n", prog, *argv);
                fclose(stderr);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}

void buscarElemento(char *palabra, char *tipo) {
    FILE *fp = fopen("3-Recursos.txt", "r");
    if (fp == NULL) {
        printf("No pude abrir el archivo brother :(\n");
        return;
    }

    UsuarioEn user[100];
    int lineasEn = 0;

    char linea[100];
    char busqueda[100];
    sprintf(busqueda, "%s: %s", tipo, palabra);

    while (fgets(linea, sizeof(linea), fp) != NULL) {
        if (strstr(linea, busqueda) != NULL) {
            fgets(user[lineasEn].nombre, sizeof(user[lineasEn].nombre), fp);
            fgets(user[lineasEn].plataforma, sizeof(user[lineasEn].plataforma), fp);
            fgets(user[lineasEn].enlace, sizeof(user[lineasEn].enlace), fp);
            fgets(user[lineasEn].instructor, sizeof(user[lineasEn].instructor), fp);

            user[lineasEn].nombre[strcspn(user[lineasEn].nombre, "\n")] = '\0';
            user[lineasEn].plataforma[strcspn(user[lineasEn].plataforma, "\n")] = '\0';
            user[lineasEn].enlace[strcspn(user[lineasEn].enlace, "\n")] = '\0';
            user[lineasEn].instructor[strcspn(user[lineasEn].instructor, "\n")] = '\0';

            lineasEn++;
        }
    }
    fclose(fp);
    printf("\n");

    for (int i = 0; i < lineasEn; i++) {
        printf("%s\n", user[i].nombre);
        printf("%s\n", user[i].plataforma);
        printf("%s\n", user[i].enlace);
        printf("%s\n", user[i].instructor);
    }
}

void agregarRecurso() {
    FILE *fp = fopen("3-Recursos.txt", "a");
    if (fp == NULL) {
        printf("No pude abrir el archivo brother");
        return;
    }

    printf("\nInstructor: ");
    char instructor[100];
    fgets(instructor, sizeof(instructor), stdin);
    instructor[strcspn(instructor, "\n")] == '\0';

    printf("Nombre: ");
    char nombre[100];
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] == '\0';

    printf("Plataforma: ");
    char plataforma[100];
    fgets(plataforma, sizeof(plataforma), stdin);
    plataforma[strcspn(plataforma, "\n")] == '\0';

    printf("Enlace: ");
    char enlace[100];
    fgets(enlace, sizeof(enlace), stdin);
    enlace[strcspn(enlace, "\n")] == '\0';

    fprintf(fp, "\nInstructor: %s", instructor);
    fprintf(fp, "Nombre: %s", nombre);
    fprintf(fp, "Plataforma: %s", plataforma);
    fprintf(fp, "Enlace: %s", enlace);

    fclose(fp);
    printf("\n\nSe agregó el curso de forma correcta\n\n");
}
