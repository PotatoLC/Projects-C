/*
El programa cuenta el número de caracteres, palabras y líneas en la entrada de texto y muestra los resultados al final.
*/


#include <stdio.h>

#define IN 1 
#define OUT 0 

main(){
    
    int c,nl,nw,nc,state;

    state = OUT;
    nl = nw = nc = 0;

    while((c=getchar())!=EOF){
        ++nc;
        if (c=='\n')
            ++nl;
        if(c==' '||c=='\n'||c=='\t')
            state=OUT;
        else if(state==OUT){
            ++nw;
            state=IN;
        }
        
    }

    printf("\nNumero de caracteres ----> %d \n"
            "Numero de lineas -----> %d \n"
            "Numero de palabras -----> %d \n", nc, nl, nw);
}
