#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <graph.h>
#include "chargement_virus.h"
#include "case_graphique.h"

/*Chargement des instruction sous la forme d'entiers, dans la memoire*/
void VirusLoader (int pc, long long int memory [], char* path_fichier, int virus) {
	int i;
	FILE* fichier;
	long long int instruction;
	couleur color;

	if (virus==1){
		color=CouleurParComposante(0,0,255);
	}else{
		color=CouleurParComposante(0,255,255);
	}

	fichier=fopen(path_fichier,"r");
	for (i=0;feof(fichier)==0; i++) {
		fread(&instruction,sizeof(long long int),1,fichier);
		if (feof(fichier)==0){
			if (pc+i <8000){
				memory[pc+i]=instruction;
				/*affichage graphique de la case à l'indice pc+i, de couleur selon le numéro du virus*/
				PrintCase(color,pc+i);
			}else{
				memory[pc+i-8000]=instruction;
				/*affichage graphique de la case à l'indice pc+i-8000, de couleur selon le numéro du virus*/
				PrintCase(color,pc+i-8000);
			}
		}
	}
}
