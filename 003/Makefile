#
# makefile
#

SRC=sortl

run: main.o $(SRC).o
	gcc main.o $(SRC).o -o main

dbg: main.o $(SRC).o
	gcc -g main.o $(SRC).o -o main

tst: tst.o
	gcc tst.o -o tst

main.o: main.c
	gcc -c -g main.c

$(SRC).o: $(SRC).c
	gcc -c -g $(SRC).c

tst.o: tst.c
	gcc -c tst.c

cln:
	rm *.o

