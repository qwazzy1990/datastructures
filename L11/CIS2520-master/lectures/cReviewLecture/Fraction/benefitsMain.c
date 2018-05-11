// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    /* 
      This is perfectly fine and allowed 
    */
    Fraction  *f = malloc(sizeof(Fraction));

    f->numerator = 3;
    f->denominator= 5;

    int a = f->numerator;

    /*****************************************/

    Fraction  *f = malloc(sizeof(Fraction));
    
    // Mutators or setter
    setDenominator(f, 5);
    setNumerator(f,3);

    // Accessors
    int c = getNumerator(f);
    int d = getDenominator(f);

    return 0;
}