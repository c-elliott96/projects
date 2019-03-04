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
        if (d == 1)
        {
            cout << '-' << n;
            return cout;
        }
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


bool operator==(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int n2 = n0 * d1;
    int d2 = d0 * n1;

    if (n2 == d2)
        return true;

    else
        return false;
}



bool operator!=(const Fraction & r0, const Fraction & r1)
{
    int n0 = r0.n;
    int d0 = r0.d;
    int n1 = r1.n;
    int d1 = r1.d;

    int n2 = n0 * d1;
    int d2 = d0 * n1;

    if ((n2 == d2))
        return false;
    else
        return true;    
}


void reduce(Fraction & f)
{
    int n = f.n;
    int d = f.d;

    bool print_neg = false;

    if ((n < 0 && d > 0) || (n > 0 && d < 0))
        print_neg = true;

    int smaller;
    if (n < d)
        smaller = n;
    else
        smaller = d;

    int gcd = 1;
    for (int i = 1; i <= smaller; ++i)
    {
        if ((n % i == 0) && (d % i == 0))
        {
            gcd = i;
        }
    }

    n /= gcd;
    d /= gcd;

    if (print_neg)
    {
        if (n < 0)
        {
            d = abs(d);
        }

        if (d < 0 && n != 0)
        {
            n *= -1;
            d = abs(d);
        }
    }

    if (n < 0 && d < 0)
    {
        n = abs(n);
        d = abs(d);
    }

    if (d == 0)
        n = 1;

    if (n == 0 && d != 0)
    {
        n = 0;
        d = 1;
    }

    f.n = n;
    f.d = d;

    return;
}


Fraction get_Fraction(int n, int d)
{
    Fraction ret;
    ret.n = n;
    ret.d = d;

    return ret;
}


int get_n(const Fraction & f)
{
    return f.n;
}


int get_d(const Fraction & f)
{
    return f.d;
}



void set_n(Fraction & r, int new_n)
{
    r.n = new_n;
}


void set_d(Fraction & r, int new_d)
{
    r.d = new_d;
}


void set(Fraction & r, int new_n, int new_d)
{
    r.n = new_n;
    r.d = new_d;
}


int get_int(const Fraction & f)
{
    int x = (int)f.n / f.d;
    return x;
}


double get_double(const Fraction & f)
{
    double x = (double)f.n / f.d;
    return x;
}


Fraction operator+=(Fraction & f, const Fraction & g)
{
    f.n = f.n * g.d + g.n * f.d;
    f.d = f.d * g.d;
    return f;
}


Fraction operator-=(Fraction & f, const Fraction & g)
{
    f.n = f.n * g.d - g.n * f.d;
    f.d = f.d * g.d;
    return f;
}
