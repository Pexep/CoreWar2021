#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*ConvFile(char* path_fichier1_ASM, char* path_fichier2_ASM){*/
int main (void) {
	long int instruction_int;
	char path_fichier1_ASM[50], path_fichier2_ASM[50];
	char path_fichier1_int[50], path_fichier2_int[50];
	char instruction_char[20];
	FILE* fichier_ASM;
	FILE* fichier_int;

	strcpy(path_fichier1_ASM,"./Virus1.txt");
	strcpy(path_fichier2_ASM,"./Virus2.txt");
	strcpy(path_fichier1_int,path_fichier1_ASM);
	strcpy(path_fichier2_int,path_fichier2_ASM);
	strcat(path_fichier1_int,".int");
	strcat(path_fichier2_int,".int");

	/*conversion du premier fichier*/
	fichier_ASM=fopen(path_fichier1_ASM,"r");
	fichier_int=fopen(path_fichier1_int,"w");

	while (feof(fichier_ASM)==0) {
		fgets(instruction_char,20,fichier_ASM);
		if (feof(fichier_ASM)==0){
			printf("%s : ",instruction_char);

			/*appel à la conctione de convertion*/
			/*instruction_int=conversion(strlen(instruction_char),instruction_char);*/

			fwrite(&instruction_int, sizeof(long int), 1, fichier_int);
			printf("%d\n",instruction_int);
		}
	}

	fclose(fichier_ASM);
	fclose(fichier_int);
	printf("\n");

	/*conversion du deuxième fichier*/
	fichier_ASM=fopen(path_fichier2_ASM,"r");
	fichier_int=fopen(path_fichier2_int,"w");

	while (feof(fichier_ASM)==0) {
		fgets(instruction_char,20,fichier_ASM);
		if (feof(fichier_ASM)==0){
			printf("%s : ",instruction_char);

			/*appel à la conctione de convertion*/
			/*instruction_int=conversion(strlen(instruction_char),instruction_char);*/

			fwrite(&instruction_int, sizeof(long int), 1, fichier_int);
			printf("%d\n",instruction_int);
		}
	}

	fclose(fichier_ASM);
	fclose(fichier_int);


	return EXIT_SUCCESS;
}
