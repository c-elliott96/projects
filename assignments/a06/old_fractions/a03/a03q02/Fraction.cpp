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
    xn = (zn * yd) + (yn * zd);
    xd = yd * zd;
}
