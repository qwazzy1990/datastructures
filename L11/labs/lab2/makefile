CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

SRC_FILES = $(wildcard ./src/*.c)

show:
	@echo $(SRC_FILES)

program:
	$(CC) $(CFLAGS) $(SRC_FILES) -Iinclude -o $(BIN)program

cls:
	clear

clean:
	rm ./bin/*

