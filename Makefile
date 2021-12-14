but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h
chargement_virus.o : chargement_virus.h
main.o : conversion_fichier.h chargement_virus.h

code.out : conversion.o conversion_fichier.o chargement_virus.o main.o
	    gcc -o code.out conversion.o conversion_fichier.o chargement_virus.o main.o
