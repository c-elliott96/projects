// File: bubblesort.cpp
// Name: Christian Elliott

#include <iostream>


// this bubblesort does not use recursion. instead, two for loops

void bubblesort(int x[10], int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        for (int j = start; j < end - i; ++j)
        {
            if (x[j] > x[j + 1])
            {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}


int main()
{
    int start = 0;
    int end = 9;

    int x[10] = {5, 2, 1, 8, 56, 32, 9, 10, 3, 12};

    bubblesort(x, start, end);

    for (int i = 0; i <= end; ++i)
    {
        std::cout << x[i] << ' ';
    }

    std::cout << '\n';
    
    return 0;
}
