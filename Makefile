but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h
chargement_virus.o : case_graphique.h
case_graphique.o : case_graphique.h variables.h
inttobin.o : inttobin.h
execution.o : case_graphique.h
main.o : conversion_fichier.h chargement_virus.h case_graphique.h inttobin.h execution.h variables.h

code.out : conversion.o conversion_fichier.o chargement_virus.o case_graphique.o inttobin.o execution.o main.o
	    gcc -o code.out conversion.o conversion_fichier.o chargement_virus.o case_graphique.o inttobin.o execution.o main.o -lgraph -lm
