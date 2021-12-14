#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "chargement_virus.h"
#include "conversion_fichier.h"

/*int main (int argc, char* argv[]){*/
int main (void) {
	int flag, virus, pc1, pc2;
	char path_fichier1_ASM[50], path_fichier2_ASM[50];
	char path_fichier1_int[50], path_fichier2_int[50];
	long long int memory[8000];

	/*Compilation*/
	/*strcpy(path_fichier1_ASM, argv[1]);
	strcpy(path_fichier2_ASM, argv[2]);*/
	strcpy(path_fichier1_ASM,"./Virus1.txt");
	strcpy(path_fichier2_ASM,"./Virus2.txt");
	strcpy(path_fichier1_int,path_fichier1_ASM);
	strcpy(path_fichier2_int,path_fichier2_ASM);
	strcat(path_fichier1_int,".int");
	strcat(path_fichier2_int,".int");
	ConvFile(path_fichier1_ASM,path_fichier1_ASM,path_fichier2_int,path_fichier2_int);

	/*Initialisation graphique, ouverture de la fenêtre et création de la grille*/

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
		}
	}else{
		if ((pc1-pc2)<1000){
			pc1=pc1+1000;
			if(pc1>=8000){
				pc1=pc1-8000;
			}
		}
	}
	VirusLoader (pc1,memory,path_fichier1_int,1);
	VirusLoader (pc2,memory,path_fichier2_int,2);

	/*----Entrée dans le jeu (jusqu'à ce qu'une instruction ne soit pas bonne)----*/
	/*Chargement de l'instruction et decortiquement en plusieurs entiers*/

	/*Vérification de la validité de l'instruction*/

	/*Exécution de l'intruction (si elle est valide)*/

	/*----Sortie du jeu (une instruction n'est plus bonne)*/

	/*Fermeture du graphique*/

	return EXIT_SUCCESS;
}
