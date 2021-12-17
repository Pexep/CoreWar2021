#include <stdio.h>
#include <stdlib.h>
#include "check.h"

int check(int *entry, long long int memory[], int pc){
    /* Vérification des instructions fournies - 1 : Problème, 0 : aucun soucis */
    int pcA, pcB;
    /*Mode d'adressage 1 immediat (#)*/
	if (entry[1]==0){
		pcA=entry[3];
	}
	/*Mode d'adressage 1 direct ( )*/
	if (entry[1]==1){
		pcA=(pc)+entry[3];
		if (pcA>=8000){
			pcA=pcA%8000;
		}
	}
	/*Mode d'adressage 1 indirect (@)*/
	if (entry[1]==2){
    pcA=entry[3]+(pc);
    if (pcA>=8000){
			pcA=pcA%8000;
		}
		pcA=(pc)+memory[pcB];
		if (pcA>=8000){
			pcA=pcA%8000;
		}
	}
	/*Mode d'adressage 2 immediat (#)*/
	if (entry[2]==0){
		pcB=entry[4];
	}
	/*Mode d'adressage 2 direct ( )*/
	if (entry[2]==1){
		pcB=(pc)+entry[4];
		if (pcB>=8000){
			pcB=pcB%8000;
		}
	}
	/*Mode d'adressage 2 indirect (@)*/
	if (entry[2]==2){
    pcB=entry[4]+(pc);
    if (pcB>=8000){
			pcB=pcB%8000;
		}
		pcB=(pc)+memory[pcB];
    if (pcB>=8000){
			pcB=pcB%8000;
		}
	}

    if(entry[0]==0){
        return 1;
    }
    if(entry[3] >=8000 || entry[4] >=8000){
        return 1;
    }
    if (entry[0]==2 && memory[pcA]+memory[pcB]>=8446744199999999999){
		 return 1;
	  }
    if (entry[0]==3 && memory[pcB]-memory[pcA]<0){
  		return 1;
	  }

    return 0;
}
