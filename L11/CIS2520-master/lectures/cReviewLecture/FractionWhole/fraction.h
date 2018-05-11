// Protected your structure and code from accidently being included twice.
#ifndef FRACTION_H
#define FRACTION_H

// A standard method of declaring a structure.
// The benefit being you don't have to prefix fraction with struct everywhere.

/**
 * This structure holds a denominator and numerator as integers.
 */
typedef struct fraction {

    int wholeNumber;
    int numerator;
    int denominator;

} Fraction; // NOTE: Without this typedef you have to type "struct fraction" everytime you want to declare a fraction.

/**
 * Accessor for the numerator
 * @param  fraction
 * @return          numerator
 */
int getNumerator( Fraction* fraction );

/**
 * Accessor for the denominator
 * @param  fraction
 * @return the denominator of fraction
 */
int getDenominator( Fraction * fraction );


/**
 * Sets the numerator and denominator for a fraction
 * @param fraction    Properly created fraction
 * @param numerator   integer
 * @param denominator integer not 0
 */
void setFraction( Fraction * fraction, int numerator, int denominator );


/**
 * Set only the numerator of a fraction
 * @param fraction  Properly created fraction
 * @param numerator integer
 */
void setFractionNumerator( Fraction * fraction, int numerator );


/**
 * Set only the denominator of a fraction
 * @param fraction  Properly created fraction
 * @param denominator integer, 0 will be ignore
 */
void setFractionDenominator( Fraction * fraction, int denominator );

/**
 * Prints the division of the numerator and denominator follow by both values.
 * @param fraction 
 */
void printFraction( Fraction * fraction );


#endif
