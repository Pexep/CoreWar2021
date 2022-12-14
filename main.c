#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <graph.h>
#include <unistd.h>
#include "execution.h"
#include "inttobin.h"
#include "variables.h"
#include "chargement_virus.h"
#include "conversion_fichier.h"
#include "check.h"

int main (int argc, char* argv[]){
	int flag, virus, pc, pc1, pc2, i, instructions_int[64];
	char path_fichier1_ASM[50], path_fichier2_ASM[50];
	char path_fichier1_int[50], path_fichier2_int[50];
	long long int memory[8000];
	couleur color_black=CouleurParComposante(0,0,0);

	if (argc!=3){
		printf("Problème d'arguments !!\n");
		return EXIT_FAILURE;
	}

	for (i=0;i<8000;i++){
		memory[i]=0;
	}
	/*Compilation*/
	strcpy(path_fichier1_ASM, argv[1]);
	strcpy(path_fichier2_ASM, argv[2]);
	strcpy(path_fichier1_int,path_fichier1_ASM);
	strcpy(path_fichier2_int,path_fichier2_ASM);
	strcat(path_fichier1_int,".int");
	strcat(path_fichier2_int,".int");
	ConvFile(path_fichier1_ASM,path_fichier2_ASM,path_fichier1_int,path_fichier2_int);

	/*Initialisation graphique, ouverture de la fenêtre et création de la grille*/
	InitialiserGraphique();
	CreerFenetre(0,0,L_FENETRE,H_FENETRE);
	ChoisirCouleurDessin(color_black);
	for (i=0;i<=CASE_X;i++){
		DessinerSegment(PLACEMENT_X-1+i*TAILLE_CASE+i,PLACEMENT_Y-1,PLACEMENT_X-1+i*TAILLE_CASE+i,PLACEMENT_Y-1+TAILLE_CASE*CASE_Y+CASE_Y);
	}
	for (i=0;i<=CASE_Y;i++){
		DessinerSegment(PLACEMENT_X-1,PLACEMENT_Y-1+i*TAILLE_CASE+i,PLACEMENT_X-1+TAILLE_CASE*CASE_X+CASE_X,PLACEMENT_Y-1+i*TAILLE_CASE+i);
	}
	for (i=0;i<=CASE_SUPP;i++){
		DessinerSegment(PLACEMENT_X-1+i*TAILLE_CASE+i,TAILLE_CASE*CASE_Y+PLACEMENT_Y+CASE_Y,PLACEMENT_X-1+i*TAILLE_CASE+i,TAILLE_CASE*CASE_Y+PLACEMENT_Y+TAILLE_CASE+CASE_Y);
	}
	DessinerSegment(PLACEMENT_X-1,TAILLE_CASE*(1+CASE_Y)+PLACEMENT_Y+CASE_Y,PLACEMENT_X+TAILLE_CASE*CASE_SUPP+CASE_SUPP-1,TAILLE_CASE*(1+CASE_Y)+PLACEMENT_Y+CASE_Y);
	EcrireTexte(1100,200,"Virus1",1);
	EcrireTexte(1100,400,"Virus2",1);
	ChoisirCouleurDessin(CouleurParComposante(0,0,255));
	RemplirRectangle(1050,180,20,20);
	ChoisirCouleurDessin(CouleurParComposante(0,255,255));
	RemplirRectangle(1050,380,20,20);
	ChoisirCouleurDessin(CouleurParComposante(255,0,0));
	RemplirRectangle(1050,210,20,20);
	ChoisirCouleurDessin(CouleurParComposante(0,255,0));
	RemplirRectangle(1050,410,20,20);

	/*Chargement en memoire*/
	srand(time(NULL));
	pc1=rand()%8000;
	pc2=rand()%8000;
	if (pc1<=pc2){
		if ((pc2-pc1)<1000){
			pc2=pc2+1000;
			if(pc2>=8000){
				pc2=pc2-8000;
			}
		}else{
			if (pc1+(8000-pc2)<1000){
				pc1=pc1+1000;
			}
		}
	}else{
		if ((pc1-pc2)<1000){
			pc1=pc1+1000;
			if(pc1>=8000){
				pc1=pc1-8000;
			}
		}else{
			if (pc2+(8000-pc1)<1000){
				pc2=pc2+1000;
			}
		}
	}
	VirusLoader (pc1,memory,path_fichier1_int,1);
	VirusLoader (pc2,memory,path_fichier2_int,2);

	/*----Entrée dans le jeu (jusqu'à ce qu'une instruction ne soit pas bonne)----*/
	virus=1, flag=0;
	while (flag==0){
		if (virus==1){
			pc=pc1;
		}else{
			pc=pc2;
		}

		/*Décomposition de l'instruction en plusieurs entiers*/
		convert (memory[pc], instructions_int);

		/*Vérification de la validité de l'instruction*/
		flag=check(instructions_int, memory, pc);

		/*Exécution de l'intruction (si elle est valide)*/
		if (flag==0){
			execute(instructions_int, &pc, virus, memory);
		}


		if (virus==1){
			virus=2;
			pc1=pc;
		}else{
			virus=1;
			pc2=pc;
		}
		sleep(1);
		/*----Sortie du jeu (une instruction n'est plus bonne)*/
	}

	/*Affichage du gagnant*/
	ChoisirCouleurDessin(CouleurParComposante(0,255,0));
	if (virus==1){
		EcrireTexte(1100,700,"Le gagnant est le Virus 1",2);
	}else{
		EcrireTexte(1100,700,"Le gagnant est le Virus 2",2);
	}

	/*Fermeture du graphique*/
	Touche();
	FermerGraphique();

	return EXIT_SUCCESS;
}
