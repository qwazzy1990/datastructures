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

    // Set and print the fraction
    for(int i = 0; i < 20; i++)
    {
        setFraction(f,i,10);
        printFraction(f);
        printf("\n");
    }

    // Free the memory.
    free(f);
}
