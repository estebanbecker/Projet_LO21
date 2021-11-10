Projet_LO21: Projet_LO21.o bucket.o
	gcc -o Projet_LO21 Projet_LO21.o bucket.o
Projet_LO21.o: Projet_LO21.c
	gcc -c Projet_LO21.c -o Projet_LO21.o -W -Wall -pedantic
bucket.o: bucket.c bucket.h
	gcc -c bucket.c -o bucket.o -W -Wall -pedantic