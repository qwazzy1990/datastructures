
CFLAGS = -std=c99 -Wall -pedantic -g
BIN = ./bin/
SOURCE = ./source/

all: prog1 prog2

prog1:
	gcc $(CFLAGS) $(SOURCE)main.c $(SOURCE)simulation.c $(SOURCE)BinSearchTree.c $(SOURCE)ReadFile.c $(SOURCE)Rule.c -Iinclude -o $(BIN)prog1

prog2:
	gcc $(CFLAGS) $(SOURCE)testMain.c $(SOURCE)simulation.c $(SOURCE)BinSearchTree.c $(SOURCE)ReadFile.c $(SOURCE)Rule.c -Iinclude -o $(BIN)prog2

clean:
	rm $(BIN)prog1 $(BIN)prog2
