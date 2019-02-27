// File: prime_pointers.cpp
// Name: Christian Elliott

#include <iostream>
#include <cmath>

int main()
{
    int * p;
    int * q;
    int * r;
    int * s;

    p = new int;
    q = new int;
    r = new int;
    s = new int;


    std::cin >> *p >> *q;

    for (; *p <= *q; ++(*p))
    {
        *s = 0;
        for (*r = 2; *r <= sqrt(*p); ++(*r))
        {
            if (*p % *r == 0)
            {
                *s = 1;
                break;
            }
        }
        if (*s == 0)
        {
            std::cout << *p << ' ' << std::endl;
        }
    }

    delete p;
    delete q;
    delete r;
    delete s;
    
    return 0;
}
