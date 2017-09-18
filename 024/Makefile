#
# makefile
#

SRC=commonden

dbg: main.o $(SRC).o
	gcc -g main.o $(SRC).o -lm -o main

tst: tst.o
	gcc tst.o -o tst

main.o: main.c
	gcc -c -g -lm main.c

$(SRC).o: $(SRC).c
	gcc -c -g -lm $(SRC).c

tst.o: tst.c
	gcc -c tst.c

cln:
	rm *.o

