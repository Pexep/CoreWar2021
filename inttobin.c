#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "inttobin.h"

int convert(long long int integer, int* binary){
    /* Convertion d'un entier en bianire stocké sur 64 bits */
    long long int rest=integer;
    int i=0, temp;
    for(i=0; i<64; i++){ /* Initialisation du tableau */
        binary[i]=0;
    }
    for(i=63; i>=0; i--){
        if(rest-pow(2,i)>=0){
            binary[i]=1;
            printf("%ld - %ld - %d\n", rest, pow(2,i), i);
            rest=rest-pow(2,i);
        }
    }
    return EXIT_SUCCESS;
}