but : code.out

conversion.o : conversion.h
conversion_fichier.o : conversion.h

code.out : conversion.h conversion_fichier.h
    gcc -ansi -WALL conversion.o conversion_fichier.o