#include <stdio.h>
#include <stdlib.h>
#include "check.h"

int check(long long int *entry){
    /* Vérification des instructions fournies - 1 : Problème, 0 : aucun soucis */
    if(entry[0]==0){
        return 1;
    }
    if(entry[3] >=8000 || entry[4] >=8000){
        return 1;
    }
    return 0;
}