CC=gcc
CFLAGS= -g -Wall -std=c11 -o 

.PHONY:all 
all: unitaire homogene random

unitaire:test_unitaire.c projet2019.c 
	$(CC)  $(CFLAGS)  unitaire.o test_unitaire.c projet2019.c -lm

homogene:test_homogene.c projet2019.c
	$(CC)  $(CFLAGS)  homogene.o test_homogene.c projet2019.c -lm

random:test_random.c projet2019.c
	$(CC)  $(CFLAGS)  random.o test_random.c projet2019.c -lm


.PHONY:clean
clean:
	@rm -rf *.o
