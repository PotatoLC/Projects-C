
int menu();
void filecopy(FILE *ifp, FILE *ofp);
int mostrarArchivos(int argc, char *argv[]);
void buscarElemento(char *palabra, char *tipo);
void agregarRecurso();

typedef struct {
    char nombre[100];
    char plataforma[100];
    char enlace[100];
    char instructor[100];
} UsuarioEn;
