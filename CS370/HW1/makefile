CC = gcc

Start: Starter.o Executor.o
	$(CC) -g -o Start Starter.o Executor.o

Starter.o: Starter.c Executor.c Executor.h
	$(CC) -g -c Starter.c

Executor.o: Executor.c Executor.h
	$(CC) -g -c Executor.c

tar:
	tar -cvzf Ian_Duncan.tar *.c *.h *.txt Makefile

clean:
	rm -f Start.o
