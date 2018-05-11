# Name: Foo Bar
# Student Number: 0123456


##########################
# Description:
##########################

This is a boiler plate for anyone who wants to start with a running skeleton c program. 
The program contains 3 files each having a single function called by a main function in 
a separate file. The goal of this program is to demonstrate the detail required in a 
program abiding by the specs of CIS*2520.


##########################
# Run and Compile:
##########################

To compile/build the program move to the root directory of this program and type:

	make

The program is compiled into a single executable in the bin (binary) directory named 
runMe. So, to run the program type:

	./bin/runMe


##########################
# Optional Features:
##########################

This program does not implement any optional or additional features. 


##########################   
# Assumptions/Limitations:
##########################

There are no limitations or preassumptions for running the code. The only assumption of
this boiler plate is that all assignment submissions in this course will follow the 
submission guidelines.

WARNING: This is not a limitation of the program, but of GNU make. The slightly more 
"complicated" makefile requires that after each time each time the code is updated the
current .o files must be cleaned. Meaning, the user must use "make clean" before
building with with "make" or "make build".
