# Makefile
CFLAGS = -Wall -std=c11
CC = gcc

SRC = src
INCLUDE = include

all: main

main: main.o DepGraph.o ParseFile.o Report.o
	$(CC) $(CFLAGS) main.o DepGraph.o ParseFile.o Report.o -o main

main.o: $(SRC)/main.c $(INCLUDE)/ParseFile.h $(INCLUDE)/DepGraph.h $(INCLUDE)/Report.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/main.c -o main.o

ParseFile.o: $(SRC)/ParseFile.c $(INCLUDE)/ParseFile.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/ParseFile.c -o ParseFile.o

DepGraph.o: $(SRC)/DepGraph.c $(INCLUDE)/DepGraph.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/DepGraph.c -o DepGraph.o

Report.o: $(SRC)/Report.c $(INCLUDE)/Report.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/Report.c -o Report.o

clean:
    del /Q main.exe main *.o 2>nul || exit 0
# rm -f main *.o
