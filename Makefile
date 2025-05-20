CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = req_dep_graph

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	rm -f src/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET) example.md
