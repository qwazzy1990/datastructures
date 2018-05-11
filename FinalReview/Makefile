CFLAGS = gcc -Wall -std=c99 -g -pedantic
SOURCE = ./source/
BIN = ./bin/

prog1:
	$(CFLAGS) $(SOURCE)QuickSort.c $(SOURCE)Heap.c $(SOURCE)main.c $(SOURCE)Merge.c -Iinclude -o $(BIN)prog1

clean:
	rm $(BIN)prog1
