// file: Fraction.cpp
// name: Christian Elliott


#include <iostream>
#include <cmath>
#include <cstdlib>


void fraction_print(int n, int d)
{
    // fraction print goes here

    int abs_n = abs(n);
    int abs_d = abs(d);
    if (d == 0)
    {
        std::cout << "undefined";
        //return 0;
    }
    else if (n == 0)
    {
        std::cout << 0;
    }
    
    else
    {
        int smaller;
        if (abs_n > abs_d)
        {
            smaller = abs_d;
        }
        else
           smaller = abs_n;

        int new_d;
        for (int i = smaller; i > 0; --i)
        {
            if (n % i == 0 && d % i == 0)
            {
                new_d = i;
                break;
            }
        }

        if (((n < 0 && d > 0) && n != 0) || ((n > 0 && d < 0) && n != 0))
        {
            std::cout << '-';
        }

        int ans_n = n / new_d;
        int ans_d = d / new_d;
        // if fraction = whole num
        if (ans_n % ans_d == 0)
        {
            std::cout << ans_n / ans_d;
        }
        
        else
        {
            std::cout << abs(n / new_d) << '/' << abs(d / new_d);
        }
    }
}


void fraction_add(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd)
{
    xn = (yn * zd) + (yd * zn);
    xd = yd * zd;
}


void fraction_subtract(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd)
{
    xn = (yn * zd) - (yd * zn);
    xd = yd * zd;
}


void fraction_multiply(int & xn, int & xd,
                       int yn, int yd,
                       int zn, int zd)
{
    xn = yn * zn;
    xd = yd * zd;
}


void fraction_divide(int & xn, int & xd,
                     int yn, int yd,
                     int zn, int zd)
{
    xn = yn * zd;
    xd = yd * zn;
}


bool fraction_eq(int yn, int yd,
                 int zn, int zd)
{
    bool y_negative = false;
    bool z_negative = false;
    
    // if yn/yd is negative
    if ((yn < 0 && yd >= 0) || (yn >= 0 && yd < 0))
    {
        y_negative = true;
    }
    
    // if zn/zd is negative
    if ((zn < 0 && zd >= 0) || (zn >= 0 && zd < 0))
    {
        z_negative = true;
    }

    // if function gets here and y_neg or z_neg hasn't been changed, they're +

    // if they're opposite signs, not equal
    if (z_negative == false && y_negative == true)
    {
        return false;
    }

    // if they're opposite signs, not equal
    if (y_negative == false && z_negative == true)
    {
        return false;
    }

    int larger_denominator = 0;
    int smaller_denominator = 0;
    
    if (abs(yd) >= abs(zd))
    {
        larger_denominator = yd;
        smaller_denominator = zd;
    }
    else
    {
        larger_denominator = zd;
        smaller_denominator = yd;
    }

    // if you cannot divide larger by smaller, there's no way they're equal
    if (abs(larger_denominator % smaller_denominator) != 0)
    {
        return false;
    }

    int multiplier = 0;


    // creates multiplier for comparing numerators after making
    // same  denominator
    if (larger_denominator == yd)
    {
        multiplier = yd / zd;
    }

    else
    {
        multiplier = zd / yd;
    }

    if (larger_denominator == yd)
    {
        if (zn * multiplier != yn)
        {
            return false;
        }

        else
        {
            return true;
        }
    }

    if (larger_denominator == zd)
    {
        if (yn * multiplier != zn)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}


bool fraction_neq(int yn, int yd,
                 int zn, int zd)
{
    if (fraction_eq(yn, yd, zn, zd) == 1)
    {
        return false;
    }
    else
        return true;
}
