# Makefile
CFLAGS = -Wall -std=c11
CC = gcc

SRC = src
INCLUDE = include

EXE = rdgg-01234567.exe

all: $(EXE)

$(EXE): main.o DepGraph.o ParseFile.o Report.o
	$(CC) $(CFLAGS) main.o DepGraph.o ParseFile.o Report.o -o $(EXE)

main.o: $(SRC)/main.c $(INCLUDE)/ParseFile.h $(INCLUDE)/DepGraph.h $(INCLUDE)/Report.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/main.c -o main.o

ParseFile.o: $(SRC)/ParseFile.c $(INCLUDE)/ParseFile.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/ParseFile.c -o ParseFile.o

DepGraph.o: $(SRC)/DepGraph.c $(INCLUDE)/DepGraph.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/DepGraph.c -o DepGraph.o

Report.o: $(SRC)/Report.c $(INCLUDE)/Report.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/Report.c -o Report.o

clean:
	del /Q $(EXE) *.o 2>nul || exit 0
	
#ran using powershell
