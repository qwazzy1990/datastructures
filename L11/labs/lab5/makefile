CC = gcc
CFLAGS = -Wall -g -std=c99
LIBS = -lLinkedList

BIN = ./bin/
SRC = ./src/

SRC_FILES = $(wildcard ./src/*.c)
TEST_FILES = $(wildcard ./tests/*.c)



all: program 

program:
	$(CC) $(CFLAGS) $(SRC_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)program

#testing:
#	$(CC) $(CFLAGS) $(TEST_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)testProgram

show:
	@echo $(SRC_FILES)

cls:
	clear

clean:
	rm ./bin/*

