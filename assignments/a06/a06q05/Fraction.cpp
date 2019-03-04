// Christian Elliott
// Date:
// Fraction.cpp

#include <iostream>
#include <cmath>
#include "Fraction.h"



std::ostream & operator<<(std::ostream & cout, const Fraction & r)
{
    int n = r.n;
    int d = r.d;

    bool print_neg = false;

    if (n == d)
    {
        cout << 1;
        return cout;
    }

    if (d == 0)
    {
        cout << "undefined";
        return cout;
    }

    if (n == 0)
    {
        cout << 0;
        return cout;
    }

    // if one and only one is negative, set print_neg to true
    if ((n < 0 && d > 0) || (n > 0 && d < 0))
        print_neg = true;

    n = abs(n);
    d = abs(d);

    int smaller_num;
    if (n < d)
        smaller_num = n;

    else
        smaller_num = d;

    int gcd;

    for (int i = 1; i <= smaller_num; ++i)
    {
        if (n % i == 0 && d % i ==0)
            gcd = i;
    }

    n = n / gcd;
    d = d / gcd;

    if (print_neg)
    {
        cout << '-' << n << '/' << d;
        return cout;
    }

    else
    {
        cout << n << '/' << d;
        return cout;
    }

    
    cout << n << '/' << d;
    return cout;
}



//Fraction operator+(const Fraction &, const Fraction &);
Fraction operator+(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int smaller_num;
    if (d0 < d1)
        smaller_num = d0;

    else
        smaller_num = d1;

    int gcd;

    for (int i = 1; i <= smaller_num; ++i)
    {
        if (d0 % i == 0 && d1 % i == 0)
            gcd = i;
    }

    int d2 = gcd;
    d2 = (d0 * d1) / d2;

    int n2 = (n0) * (d2 / d0) + (n1) * (d2 / d1);

    d2 = d2 / gcd;
    n2 = n2 / gcd;

    Fraction ret = {n2, d2};

    return ret;
}



Fraction operator-(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int smaller_num;
    if (d0 < d1)
        smaller_num = d0;

    else
        smaller_num = d1;

    /*
    int gcd;

    for (int i = 1; i <= smaller_num; ++i)
    {
        if (d0 % i == 0 && d1 % i == 0)
            gcd = i;
    }

    std::cout << gcd << '\n';

    int d2 = gcd;
    */
    
    int d2 = (d0 * d1); //d2;

    int n2 = (n0 * d1) - (d0 * n1);

    //d2 = d2 / gcd;
    //n2 = n2 / gcd;

    Fraction ret = {n2, d2};

    return ret;
}


Fraction operator*(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int n2 = n0 * n1;
    int d2 = d0 * d1;

    Fraction ret = {n2, d2};

    return ret;
}


Fraction operator/(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int n2 = n0 * d1;
    int d2 = d0 * n1;

    Fraction ret = {n2, d2};

    return ret;
}
