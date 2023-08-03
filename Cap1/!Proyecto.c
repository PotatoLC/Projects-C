/*
Este es un pequeño juego en lenguaje C donde el usuario y una IA tratan de adivinar una letra secreta entre 'a' y 'z'. 
El programa proporciona pistas sobre si la letra elegida es mayor o menor que la letra secreta. 
¡Diviértete adivinando y compitiendo con la IA! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_IA() {
    static int seed_initialized = 0;
    if (!seed_initialized) {
        srand(time(NULL));
        seed_initialized = 1;
    }
    int random_num = rand() % 26 + 97;  // Genera numero aleatorio entre 97 a 122, es decir, de la 'a' a 'z' en minuscula en ASCII
    return random_num;
}

int main(){

    srand(time(NULL));
    int num_ale = rand() % 26; // Ponemos el 26 porque hay 25 letras en el abecedario
    char letra_secreta = 'a' + num_ale; // Letra 'a' en ASCII equivale a 97
    
    //printf("\nLa letra secreta es ---> %c\n", letra_secreta);  //Comentario para ver la letra secreta si no quieres jugar pero si quieres ver la mecanica del juego :D
    printf("\tSolo ingresa letras en minuscula\n");
    printf("\tPresiona ENTER para comenzar  ");
    int resp_user = getchar();
    int resp_ia = random_IA();
    
  

    while (resp_user != letra_secreta || resp_ia != letra_secreta) {
        printf("\n\nTurno del usuario, elige una letra ----> ");
        int resp_user = getchar();

        // Mecanica del usuario
        if (resp_user != letra_secreta) {
            printf("Esa no es la letra secreta\n");
            char letraUser = (char)resp_user;
            if (resp_user < letra_secreta) {
                printf("Tu letra %c, es menor (<) que la letra secreta", letraUser);
            } else printf ("Tu letra %c, es mayor (>) que la letra secreta\n", letraUser);
        } else {
            printf ("\n\n\t¡ESA ES LA LETRA SECRETA!!!\n\n");
            return 0;
        }
        
        //Mecanica de la IA
        printf("\n\nTurno de la IA");
        int resp_ia = random_IA();
        char letraIA = (char)resp_ia;
        if (resp_ia != letra_secreta) {
            printf("\nLa IA ha elegido una letra, pero se ha equivocado\n");
            if (resp_ia > letra_secreta) {
                printf("La letra que ha elegido %c, es mayor (>) a la letra secreta\n", letraIA);
            } else printf("La letra que ha elegido %c, es menor (<) a la letra secreta\n", letraIA);
            //printf("\nPresiona ENTER para continuar");
            int enter = getchar();
        } else {
            printf ("\n\n\tJAJAJJAJA, la IA ha adivinado la letra secreta\n\n"); 
            return 0;
        }
        
    }
}
