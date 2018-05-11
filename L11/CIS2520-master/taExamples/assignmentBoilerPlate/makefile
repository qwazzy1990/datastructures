# These lines are makefile comments, this makefile is designed to be easy to read.
# -std=c99 = ISO C99 standard (1999), https://gcc.gnu.org/c99status.html
# -Wall = Enables warnings for questionable and easily avoidable constructions.
# -pedantic = Issues all the warnings demanded by strict ISO C and ISO C++.
# -g = Produce debugging information for use with GDB.
# -I = tells the compiler where to look for header files.
# -c = Stops the linking process.
# -o = Names the target executable.

CFLAGS = -std=c99 -Wall -pedantic -g -Iinclude -c


# C Compiler (CC) = gcc
CC = gcc




# Builds the entire program

build: fileOne.o fileTwo.o fileThree.o main.o
	$(CC) objLib/fileOne.o objLib/fileTwo.o objLib/fileThree.o objLib/main.o -o bin/runMe




# Builds each of the individual c files into .o files

fileOne.o:
	gcc $(CFLAGS) src/fileOne.c -o objLib/fileOne.o

fileTwo.o:
	gcc $(CFLAGS) src/fileTwo.c -o objLib/fileTwo.o

fileThree.o:
	gcc $(CFLAGS) src/fileThree.c -o objLib/fileThree.o

main.o:
	gcc $(CFLAGS) src/main.c -o objLib/main.o




# cleans the objLib and bin

clean:
	rm objLib/*.o
	rm bin/runMe



