but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h
chargement_virus.o : case_graphique.h
case_graphique.o : case_graphique.h variables.h
main.o : conversion_fichier.h chargement_virus.h case_graphique.h variables.h

code.out : conversion.o conversion_fichier.o chargement_virus.o case_graphique.o main.o
	    gcc -o code.out conversion.o conversion_fichier.o chargement_virus.o case_graphique.o main.o -lgraph
