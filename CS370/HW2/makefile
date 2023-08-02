CC = gcc
CFLAGS= -Wall -Werror -g
#CFLAGS = -g
default: all
all: Lucas HarmonicSeries HexagonalSeries Generator

.c.o:
	$(CC) -o $(wildcard *.c)
	
tar:
	tar -cvzf IAN-DUNCAN-HW2.tar *.c README.txt makefile
	
clean:
	rm -f *.o *~ Lucas HarmonicSeries HexagonalSeries Generator
	
