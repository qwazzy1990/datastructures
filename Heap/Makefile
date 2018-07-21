CC = gcc
CFLAGS = -std=c11 -Wall -g -pedantic


program: makeprogram runprogram

	
makeprogram:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude -lm src/DynamicString.c src/utilities.c src/Heap.c test/testmain.c -o bin/prog1

runprogram: makeprogram
		./bin/prog1


test: maketest mem-leak mem-err

mem-leak: maketest
		valgrind --leak-check=full ./bin/test

mem-err: maketest
		valgrind -v ./bin/test

maketest:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude -lm src/DynamicString.c src/utilities.c src/Heap.c test/testmain.c -o bin/test

test1: maketest1 runtest1
		
maketest1:
	mkdir bin
	$(CC) $(CFLAGS) -Iinclude -D DEBUG1=false -lm src/DynamicString.c src/utilities.c src/Heap.c test/testmain.c -o bin/test1

runtest1:
	./bin/test1

clean:
	rm -r bin
