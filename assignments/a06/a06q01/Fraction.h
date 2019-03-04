// Christian Elliott
// Date: way too late
// Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction
{
    int n; // numerator
    int d; // denominator
};


std::ostream & operator<<(std::ostream &, const Fraction &);

#endif

