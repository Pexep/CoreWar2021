#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chargement_virus.h"
/*#include "affichage_memoire.h"*/

void VirusLoader (int pc, long long int memory [], char* path_fichier, int virus) {
	int i;
	FILE* fichier;
	long long int instruction;

	fichier=fopen(path_fichier,"r");
	for (i=0;feof(fichier)==0; i++) {
		fread(&instruction,sizeof(long long int),1,fichier);
		if (feof(fichier)==0){
			if (pc+i <8000){
				memory[pc+i]=instruction;
				/*affichage graphique de la case à l'indice pc+i, de couleur selon le numéro du virus*/
			}else{
				memory[pc+i-8000]=instruction;
				/*affichage graphique de la case à l'indice pc+i-8000, de couleur selon le numéro du virus*/
			}
		}
	}

}
