#include <iostream>
#include "Fraction.h"


void test_print()
{
    int n = 0, d = 0;
    std::cin >> n >> d;

    Fraction f = {n, d};
    std::cout << f << std::endl;
}


void test_add()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = {n0, d0};
    Fraction r1 = {n1, d1};
    std::cout << (r0 + r1) << std::endl;    
}


void test_subtract()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = {n0, d0};
    Fraction r1 = {n1, d1};

    std::cout << (r0 - r1) << std::endl;
}


void test_multiply()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = {n0, d0};
    Fraction r1 = {n1, d1};

    std::cout << (r0 * r1) << std::endl;
}


void test_divide()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = {n0, d0};
    Fraction r1 = {n1, d1};

    std::cout << (r0 / r1) << std::endl;
}


void test_eq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction f = {n0, d0};
    Fraction g = {n1, d1};
    std::cout << (f == g) << std::endl;
    return;
}


void test_not_eq()
{
    int n0, d0;
    int n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction f = {n0, d0};
    Fraction g = {n1, d1};
    std::cout << (f != g) << std::endl;
    return;
}


int main()
{
    int option;
    std::cin >> option;

    switch (option)
    {
        case 1:
            test_print();
            break;
        case 2:
            test_add();
            break;
        case 3:
            test_subtract();
            break;
        case 4:
            test_multiply();
            break;
        case 5:
            test_divide();
            break;
        case 6:
            test_eq();
            break;
        case 7:
            test_not_eq();
            break;
    }

    return 0;
}
