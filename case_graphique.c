#include <stdlib.h>
#include <stdio.h>
#include "variables.h"
#include "case_graphique.h"

/*Affichage de la case memoire modifiee*/
void PrintCase (couleur color, int pc) {
	ChoisirCouleurDessin(color);
	if (pc < CASE_X*CASE_Y){
		RemplirRectangle(PLACEMENT_X+TAILLE_CASE*(pc%CASE_X)+pc%CASE_X,PLACEMENT_Y+(pc/CASE_X)*TAILLE_CASE+pc/CASE_X,TAILLE_CASE,TAILLE_CASE);
	}else{
		pc=pc-CASE_X*CASE_Y;
		RemplirRectangle(PLACEMENT_X+TAILLE_CASE*pc+pc,PLACEMENT_Y+TAILLE_CASE*CASE_Y+CASE_Y,TAILLE_CASE,TAILLE_CASE);
	}

}
