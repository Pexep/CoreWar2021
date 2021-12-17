#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conversion.h"

void ConvFile(char* path_fichier1_ASM, char* path_fichier2_ASM, char* path_fichier1_int, char* path_fichier2_int){
	long long int instruction_int;
	char instruction_char[20];
	FILE* fichier_ASM;
	FILE* fichier_int;

	/*conversion du premier fichier*/
	fichier_ASM=fopen(path_fichier1_ASM,"r");
	fichier_int=fopen(path_fichier1_int,"w");

	while (feof(fichier_ASM)==0) {
		fgets(instruction_char,20,fichier_ASM);
		if (feof(fichier_ASM)==0){
			/*appel à la conctione de convertion*/
			instruction_int=conversion(instruction_char);
			fwrite(&instruction_int, sizeof(long long int), 1, fichier_int);

		}
	}

	fclose(fichier_ASM);
	fclose(fichier_int);


	/*conversion du deuxième fichier*/
	fichier_ASM=fopen(path_fichier2_ASM,"r");
	fichier_int=fopen(path_fichier2_int,"w");

	while (feof(fichier_ASM)==0) {
		fgets(instruction_char,20,fichier_ASM);
		if (feof(fichier_ASM)==0){


			/*appel à la conctione de convertion*/
			instruction_int=conversion(instruction_char);

			fwrite(&instruction_int, sizeof(long long int), 1, fichier_int);

		}
	}

	fclose(fichier_ASM);
	fclose(fichier_int);
}
