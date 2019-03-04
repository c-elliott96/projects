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
Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);
bool operator==(const Fraction &, const Fraction &);
bool operator!=(const Fraction &, const Fraction &);
void reduce(Fraction &);

Fraction get_Fraction(int n, int d); // Used to create a Fraction with
// the given n and d
int get_n(const Fraction & f); // return copy of the numerator
int get_d(const Fraction & f); // return copy of the denominator
void set_n(Fraction & r, int new_n); // set r.n to new_n
void set_d(Fraction & r, int new_d); // set r.d to new_d
void set(Fraction & r, int new_n, int new_d); // sets both n and d of r
// with the new values

int get_int(const Fraction & f);
double get_double(const Fraction & f);

Fraction operator+=(Fraction &, const Fraction &);
Fraction operator-=(Fraction &, const Fraction &);
Fraction operator*=(Fraction &, const Fraction &);


#endif

