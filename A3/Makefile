CFLAGS = -Wall -std=c99 -pedantic -g
BIN = ./bin/
SRC = ./source/

all: prog1 prog2

prog1:
	gcc $(CFLAGS) $(SRC)main.c $(SRC)HashTableAPI.c $(SRC)SinglyLinkedListAPI.c $(SRC)WordAPI.c $(SRC)SimulationAPI.c $(SRC)FileInputAPI.c -Iinclude -o $(BIN)prog1

prog2: 
	gcc $(CFLAGS) $(SRC)testMain.c $(SRC)HashTableAPI.c $(SRC)SinglyLinkedListAPI.c $(SRC)WordAPI.c $(SRC)SimulationAPI.c $(SRC)FileInputAPI.c -Iinclude -o $(BIN)prog2

clean:
	rm $(BIN)prog1 $(BIN)prog2
