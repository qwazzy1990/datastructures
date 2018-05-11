CFLAGS = -Wall -std=c99 -pedantic -g
bin = ./bin/
SOURCE = ./source/

all: prog1 prog2

prog1:
	gcc $(CFLAGS) $(SOURCE)main.c $(SOURCE)queue.c $(SOURCE)patient.c $(SOURCE)LinkedListAPI.c $(SOURCE)simulation.c -Iinclude -o $(bin)prog1

prog2:
	gcc $(CFLAGS) $(SOURCE)testMain.c $(SOURCE)queue.c $(SOURCE)patient.c $(SOURCE)LinkedListAPI.c $(SOURCE)simulation.c -Iinclude -o $(bin)prog2
clean:
	rm $(bin) prog2 $(bin)prog1
     
