CC = gcc
CFLAGS= -Wall -Werror -g -lrt
#CFLAGS = -g
default: all
all: Lucas HarmonicSeries HexagonalSeries Starter Reader

.c.o:
	$(CC) -o $(wildcard *.c)
	
tar:
	tar -cvzf IAN-DUNCAN-HW3.tar *.c README.txt makefile
	
clean:
	rm -f *.o *~ Lucas HarmonicSeries HexagonalSeries Starter Reader
	
