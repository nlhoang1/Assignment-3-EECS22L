# Makefile
CFLAGS = -Wall -std=c11
CC = gcc

all: main

main: main.o DepGraph.o ParseFile.o Report.o
	$(CC) $(CFLAGS) main.o DepGraph.o ParseFile.o Report.o -o main

main.o: main.c ParseFile.h DepGraph.h Report.h
	$(CC) $(CFLAGS) -c main.c

ParseFile.o: ParseFile.c ParseFile.h
	$(CC) $(CFLAGS) -c ParseFile.c

DepGraph.o: DepGraph.c DepGraph.h
	$(CC) $(CFLAGS) -c DepGraph.c

Report.o: Report.c Report.h
	$(CC) $(CFLAGS) -c Report.c

clean:
	rm -f main *.o
