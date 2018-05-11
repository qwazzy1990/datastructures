#include "fraction.h"
#include <stdio.h>

int getNumerator(Fraction* fraction)
{
    if(fraction)
        return (fraction->wholeNumber * fraction->numerator);
    return 0;
}

int getDenominator(Fraction * fraction)
{
    if(fraction)
        return fraction->denominator;
    return 1;
}


void setFraction( Fraction * fraction, int numerator, int denominator )
{
    setFractionDenominator(fraction, denominator);
    setFractionNumerator(fraction, numerator);
}

void setFractionNumerator( Fraction * fraction, int numerator )
{
    if(fraction)
    {
        if( fraction->denominator != 0)
        {
            fraction->wholeNumber = numerator/fraction->denominator;
            fraction->numerator = numerator%fraction->denominator;
        }
    }
}


void setFractionDenominator( Fraction * fraction, int denominator )
{
    if(fraction && denominator != 0)
    {
        fraction->denominator = denominator;
    }
}

void printFraction( Fraction * fraction )
{
    if( fraction )
    {
        printf("%d %d / %d\n", fraction->wholeNumber, fraction->numerator, fraction->denominator);
    }
    else
    {
        printf("Fraction is not initialized.");
    }
}
