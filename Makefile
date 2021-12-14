but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h

code.out : conversion.o conversion_fichier.o
    gcc -ansi -WALL -o code.out conversion.o conversion_fichier.o