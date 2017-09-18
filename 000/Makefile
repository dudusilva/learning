#
# makefile
#

run: main.o book.o
	gcc main.o book.o -o main

dbg: main.o book.o
	gcc -g main.o book.o -o main

tst: tst.o
	gcc tst.o -o tst

main.o: main.c
	gcc -c -g main.c

book.o: book.c
	gcc -c -g book.c

tst.o: tst.c
	gcc -c tst.c

cln:
	rm *.o

