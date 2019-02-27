// File: nextprime.cpp
// Name: Christian Elliott

#include <iostream>
#include <cmath>

void nextprime(int *p)
{
    int i = *p + 1;
    bool not_prime = false;
    while (1)
    {
        for (int j = i - 1; j >= sqrt(i); --j)
        {
            if (i % j == 0)
            {
                not_prime = true;
                break;
            }
        }

        if (not_prime)
        {
            ++i;
            not_prime = false;
        }
        else
        {
            *p = i;
            break;
        }
    }
}


int main()
{
    int x = 7;

    nextprime(&x); // x becomes 11
    std::cout << x << std::endl;

    nextprime(&x); // x becomes 13
    std::cout << x << std::endl;

    nextprime(&x); // x becomes 17
    std::cout << x << std::endl;

    return 0;
}
