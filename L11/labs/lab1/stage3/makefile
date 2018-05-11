CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

program:
	$(CC) $(CFLAGS) $(SRC)person.c $(SRC)main.c -Iinclude -o $(BIN)program

test:
	$(CC) $(CFLAGS) $(SRC)person.c $(SRC)testMain.c -Iinclude -o $(BIN)testing

cls:
	clear

sayHi:
	@echo 'Hi, It's nice to meet you!'
	@echo 'This is a test program'
