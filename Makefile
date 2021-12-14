but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h

code.out : conversion.o conversion_fichier.out
    gcc -o code.out conversion.o conversion_fichier.o