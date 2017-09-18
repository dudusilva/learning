#
# makefile
#

SRC=egyptian

dbg: main.o $(SRC).o
	gcc -g main.o $(SRC).o -lm -o main

main.o: main.c
	gcc -c -g -lm main.c

$(SRC).o: $(SRC).c
	gcc -c -g -lm $(SRC).c

cln:
	rm *.o

