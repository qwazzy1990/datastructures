#include "fraction.h"
#include <stdio.h>

int getNumerator(Fraction* fraction)
{
    return fraction->numerator;
}

int getDenominator(Fraction * fraction)
{
    return fraction->denominator;
}


void setFraction( Fraction * fraction, int numerator, int denominator )
{
    setFractionNumerator(fraction, numerator);
    setFractionDenominator(fraction, denominator);
}

void setFractionNumerator( Fraction * fraction, int numerator )
{
    fraction->numerator = numerator;
}


void setFractionDenominator( Fraction * fraction, int denominator )
{
    fraction->denominator = denominator;
}

void printFraction( Fraction * fraction )
{
    if( fraction )
    {
        printf("%d / %d\n", fraction->numerator, fraction->denominator);
    }
    else
    {
        printf("Fraction is not initialized.");
    }
}
