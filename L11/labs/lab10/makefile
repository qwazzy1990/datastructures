CC = gcc
CFLAGS = -Wall -g -std=c99
LIBS = -lLinkedList

BIN = ./bin/
SRC = ./src/

SRC_FILES = $(wildcard ./src/*.c)
TEST_FILES = $(wildcard ./tests/*.c)



program:
	$(CC) $(CFLAGS) $(SRC_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)program

# No required for Lab 10
# testing:
#	$(CC) $(CFLAGS) $(TEST_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)testProgram

show:
	@echo $(SRC_FILES)

cls:
	clear

clean:
	rm ./bin/*

