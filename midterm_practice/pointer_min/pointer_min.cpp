// File: pointer_min.cpp
// Name: Christian Elliott

#include <iostream>

int main()
{
    int x[5] = {2, 5, 3, 1, 9};

    int *p = &x[0];
    int *q = &x[5];

    int min = *p;

    for (; p <= q - 1; ++(p))
    {
        if (min > *p)
        {
            min = *p;
        }
    }

    std::cout << min << std::endl;
    
    return 0;
}
