#include <stdio.h>
#include <stdlib.h>
#include "inttobin.h"

int convert(long long int integer, int* tab){
    /* Convertion d'un entier en bianire stocké sur 64 bits */
    int binary[64],j,puis;
    long long int rest=integer;
    int i=0, temp;
    for(i=0; i<64; i++){ /* Initialisation du tableau */
        binary[i]=0;
    }
    for(i=0; i<=63; i++){
      binary[63-i]=rest%2;
      rest=rest/2;
    }

    tab[0]=binary[0]*8+binary[1]*4+binary[2]*2+binary[3];
    tab[1]=binary[4]*2+binary[5];
    tab[2]=binary[6]*2+binary[7];
    tab[3]=0;
    tab[4]=0;
    for (i=0;i<28;i++){
		    puis=1;
		    for (j=0;j<27-i;j++){
		          puis=puis*2;
		   }
		   tab[3]=tab[3]+puis*binary[8+i];
	  }
    for (i=0;i<28;i++){
		    puis=1;
		    for (j=0;j<27-i;j++){
		          puis=puis*2;
		   }
		   tab[4]=tab[4]+puis*binary[36+i];

	  }
    return EXIT_SUCCESS;
}
