#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* Je veux pas me faire chier à faire des commandes artisanal de comparaison de chaine de carractère alors qu'il y a déjà un truc tout fait */
#include "conversion.h"

/*
    conversion :
    Cette fonction a besoin de 2 paramètres : la taile de la chaine de caractère en entré et la suite d'instruction à analyser
*/
void argument(char *men, long long *mem, long long *val);

long long int conversion(char instruction[]){
    	long long int le_code = 0;

	long long i = 0;
	long long mema = 0;
	long long memb = 0;
	long long vala = 0;
	long long valb = 0;

	char *mnemo;
	char *arg1;
	char *arg2;

	char delim[] = " ";

	mnemo = strtok(instruction, delim);
	arg1 = strtok(NULL, delim);
	arg2 = strtok(NULL, delim);

	if (strcmp(mnemo,"DAT") == 0) {
		arg2 = arg1;
		arg1 = NULL;
	}

	if (strcmp(mnemo,"MOV") == 0) { i = 1; }

	if (strcmp(mnemo,"ADD") == 0) { i = 2; }

	if (strcmp(mnemo,"SUB") == 0) { i = 3; }

	if (strcmp(mnemo,"JMP") == 0) { i = 4; }

	if (strcmp(mnemo,"JMZ") == 0) { i = 5; }

	if (strcmp(mnemo,"JMG") == 0) { i = 6; }

	if (strcmp(mnemo,"DJZ") == 0) { i = 7; }

	if (strcmp(mnemo,"CMP") == 0) { i = 8; }

	if (strcmp(mnemo,"DAT") == 0) { i = 0; }

	argument(arg1, &mema, &vala);
	argument(arg2, &memb, &valb);

	i = i << 60;

	mema = mema << 58;
	if (i == 0) // DAT
		memb = 0;
	memb = memb << 56;
	vala = vala << 28;
	valb = valb;

	le_code = i | le_code;
	le_code = le_code | mema;
	le_code = le_code | memb;
	le_code = le_code | vala;
	le_code = le_code | valb;


	return le_code;
}

void argument(char *arg, long long *mem, long long *val) {
	int sign = 0;
	if (arg != NULL) {
		switch(arg[0]) {
			case '#' :
				*mem = 	0L;
				arg = arg+1;
				break;
			case '@' :
				*mem = 2L;
				arg = arg+1;
				break;
			default :
				*mem = 1;
		}

		if (arg[0] == '-') {
			sign = 1;
			arg = arg+1;
		}

		*val = strtoll(arg, NULL, 0);

		if (sign == 1) { *val = 8000-(*val); }
	}
}
