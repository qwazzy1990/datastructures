CC = gcc
CFLAGS = -std=c11 -Wall -g -pedantic


program: makeprogram runprogram

	
makeprogram:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/Numbers.c src/DynamicString.c src/utilities.c src/LinkedListAPI.c test/testmain.c -o bin/prog1

runprogram: makeprogram
		./bin/prog1


test: maketest mem-leak mem-err

mem-leak: maketest
		valgrind --leak-check=full ./bin/test

mem-err: maketest
		valgrind -v ./bin/test

maketest:
		mkdir bin
		$(CC) $(CFLAGS) -Iinclude src/Numbers.c src/DynamicString.c src/utilities.c src/LinkedListAPI.c test/testmain.c -o bin/test

dennis: makedennis rundennis

makedennis:
	mkdir bin
	$(CC) $(CFLAGS) -Iinclude src/LinkedListAPI.c src/StructListDemo.c -o bin/dennis

rundennis: makedennis
	valgrind -v --leak-check=full ./bin/dennis

clean:
	rm -r bin