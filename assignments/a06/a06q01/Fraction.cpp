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
