#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "case_graphique.h"
#include "execution.h"

/*Execution d'une instruction*/
void execute (int tab[], int* pc, int virus, long long int memory[]) {
	couleur color;
	int pcA,pcB;

	if (virus==1){
		color = CouleurParComposante(255,0,0);
	}else{
		color = CouleurParComposante(0,255,0);
	}

	/*Mode d'adressage 1 immediat (#)*/
	if (tab[1]==0){
		pcA=tab[3];
	}
	/*Mode d'adressage 1 direct ( )*/
	if (tab[1]==1){
		pcA=(*pc)+tab[3];
		if (pcA>=8000){
			pcA=pcA%8000;
		}
	}
	/*Mode d'adressage 1 indirect (@)*/
	if (tab[1]==2){
		pcA=tab[3]+(*pc);
		if (pcA>=8000){
			pcA=pcA%8000;
		}
		pcA=(*pc)+memory[pcA];
		if (pcA>=8000){
			pcA=pcA%8000;
		}
	}
	/*Mode d'adressage 2 immediat (#)*/
	if (tab[2]==0){
		pcB=tab[4];
	}
	/*Mode d'adressage 2 direct ( )*/
	if (tab[2]==1){
		pcB=(*pc)+tab[4];
		if (pcB>=8000){
			pcB=pcB%8000;
		}
	}
	/*Mode d'adressage 2 indirect (@)*/
	if (tab[2]==2){
		pcB=tab[4]+(*pc);
		if (pcB>=8000){
			pcB=pcB%8000;
		}
		pcB=(*pc)+memory[pcB];
		if (pcB>=8000){
			pcB=pcB%8000;
		}
	}
	/*L'instruction est un MOV*/
	if (tab[0]==1){
		memory[pcB]=memory[pcA];
		PrintCase(color,pcB);
		(*pc)++;
	}
	/*L'instruction est un ADD*/
	if (tab[0]==2){
		memory[pcB]=memory[pcA]+memory[pcB];
		PrintCase(color,pcB);
		(*pc)++;
	}

	/*L'instruction est un SUB*/
	if (tab[0]==3){
		memory[pcB]=memory[pcB]-memory[pcA];
		PrintCase(color,pcB);
		(*pc)++;
	}

	/*L'instruction est un JMP*/
	if (tab[0]==4){
		*pc=pcB;
	}

	/*L'instruction est un JMZ*/
	if (tab[0]==5){
		if (memory[pcB]==0){
			*pc=pcA;
		}
	}

	/*L'instruction est un JMG*/
	if (tab[0]==6){
		if (memory[pcB]>0){
			*pc=pcA;
		}
	}

	/*L'instruction est un DJZ*/
	if (tab[0]==7){
		if (memory[pcB]-1==0){
			memory[pcB]=memory[pcB]-1;
			PrintCase(color,pcB);
			*pc=pcA;
		}
	}

	/*L'instruction est un CMP*/
	if (tab[0]==8){
		if (memory[pcA]==memory[pcB]){
			(*pc)++;
		}else{
			*pc=(*pc)+2;
		}
	}
	if (*pc>=8000){
		*pc=(*pc)-8000;
	}
}
