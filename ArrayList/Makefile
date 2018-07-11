

CC = gcc
CFLAGS = -std=c11 -Wall -g -pedantic


program: makeprogram runprogram

	
makeprogram:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/DynamicString.c src/LinkedList.c src/utilities.c src/ArrayList.c test/main.c -o bin/prog1

runprogram:
		./bin/prog1


test: maketest runtest

maketest:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/DynamicString.c src/LinkedList.c src/utilities.c src/ArrayList.c test/testmain.c -o bin/test

runtest: maketest
		valgrind -v --leak-check=full ./bin/test


clean:
	rm -r bin
