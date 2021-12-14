but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h
main.o : conversion_fichier.h

code.out : conversion.o conversion_fichier.o main.o 
	    gcc -o code.out conversion.o conversion_fichier.o main.o 
