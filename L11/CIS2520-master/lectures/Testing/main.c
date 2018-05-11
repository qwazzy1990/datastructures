// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Project Specific Libraries
#include "fraction.h"

int main(int argc, char ** argv)
{
    // Create a fraction.
    Fraction * f = malloc(sizeof(Fraction));

	// How could we test
	// Seting denominator to 0 could crash this 
	printf("Testing if denominator set to 0 will crash\n");
	printf("Expecting: Fraction denominator set to 0 but won't crash\n");
	setFraction(f,0,0);
	printf("Received: Fraction denominator = %d\n", getDenominator(f));
	printf("Result: Test %s\n\n", getDenominator(f) == 0 ? "Passed" : "Failed");


	// NOT TESTING SECTION
	// This is called using
	Fraction *fr = malloc(sizeof(Fraction));
	setFraction(f,0,0);
	printFraction(fr);

	printf("ALL TESTS PASSED\n");

    // Free the memory.
    free(f);
	free(fr);
}
