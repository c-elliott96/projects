// file: a03q01.cpp
// name: Christian Elliott

#include <iostream>
#include "Fraction.h"


void test_fraction_print()
{
    int n = 0, d = 0; // numerator and denominator of a fraction

    std::cin >> n >> d;
    fraction_print(n, d);
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
    }


    return 0;
} 
    
