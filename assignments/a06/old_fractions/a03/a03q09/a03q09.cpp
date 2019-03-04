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


void test_fraction_multiply()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    fraction_multiply(xn, xd, yn, yd, zn, zd);
    fraction_print(xn, xd);
    std::cout << std::endl;
}


void test_fraction_divide()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    fraction_divide(xn, xd, yn, yd, zn, zd);
    fraction_print(xn, xd);
    std::cout << std::endl;
}


void test_fraction_eq()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    //fraction_eq(yn, yd, zn, zd);
    std::cout << fraction_eq(yn, yd, zn, zd);
    //fraction_print(xn, xd);
    std::cout << std::endl;
}


void test_fraction_neq()
{
    int xn = 0, xd = 0; // fraction xn/xd
    int yn = 0, yd = 0; // fraction yn/yd
    int zn = 0, zd = 0; // fraction zn/zd

    std::cin >> yn >> yd >> zn >> zd;
    std::cout << fraction_neq(yn, yd, zn, zd);
    std::cout << std::endl;
}


void test_fraction_lt()
{
    int yn = 0, yd = 0;
    int zn = 0, zd = 0;

    std::cin >> yn >> yd >> zn >> zd;
    std::cout << fraction_lt(yn, yd, zn, zd);
    std::cout << std::endl;
}

void test_fraction_factorization()
{
    int an = 0, ad = 0;
    int bn = 0, bd = 0;
    int cn = 0, cd = 0;

    std::cin >> an >> ad >> bn >> bd >> cn >> cd;
    fraction_factorization();
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
        case 4:
            test_fraction_multiply();
            break;
        case 5:
            test_fraction_divide();
            break;
        case 6:
            test_fraction_eq();
            break;
        case 7:
            test_fraction_neq();
            break;
        case 8:
            test_fraction_lt();
            break;
        case 9:
            test_fraction_factorization();
            break;
    }


    return 0;
} 
    
