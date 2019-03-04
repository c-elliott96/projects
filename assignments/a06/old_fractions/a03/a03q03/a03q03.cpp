// file: a03q01.cpp
// name: Christian Elliott

#include <iostream>
#include "Fraction.h"


void test_fraction_print()
{
    int xn = 0, xd = 0; // numerator and denominator of a fraction

    std::cin >> xn >> xd;
    fraction_print(xn, xd);
    std::cout << std::endl;
}


void test_fraction_add()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    fraction_add(xn, xd, yn, yd, zn, zd);
    fraction_print(xn, xd);
    std::cout << std::endl;
}


void test_fraction_subtract()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    fraction_subtract(xn, xd, yn, yd, zn, zd);
    fraction_print(xn, xd);
    std::cout << std::endl;
}


int main()
{
    int option;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_fraction_print();
            break;
        case 2:
            test_fraction_add();
            break;
        case 3:
            test_fraction_subtract();
            break;
    }


    return 0;
} 
    
