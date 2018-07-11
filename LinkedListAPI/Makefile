CC = gcc
CFLAGS = -std=c11 -Wall -g -pedantic


program: makeprogram runprogram

	
makeprogram:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/DynamicString.c src/utilities.c src/LinkedList.c test/testmain.c -o bin/prog1

runprogram: makeprogram
		./bin/prog1


test: maketest mem-leak mem-err

mem-leak: maketest
		valgrind --leak-check=full ./bin/test

mem-err: maketest
		valgrind -v ./bin/test

maketest:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/DynamicString.c src/utilities.c src/LinkedList.c test/testmain.c -o bin/test

clean:
	rm -r bin
