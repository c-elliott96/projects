// File: array_concat.cpp
// Name: Christian Elliott

#include <iostream>


void array_concat(int x[1024], int x_len,
                  int y[1024], int y_len)
{
    for (int i = x_len; i < y_len + x_len; ++i)
    {
        x[i] = y[i - x_len];
    }
}


int main()
{
    int x[1024] = {2, 3, 5, 7, 11, 13, 17, 19};
    int x_len = 4;
    int y[1024] = {2, 4, 8, 16, 32, 64, 128, 256};
    int y_len = 3;

    array_concat(x, x_len, y, y_len);
    // concatenate y[0], ..., y[y_len - 1] to x[x_len], ...

    // after the above function call, x has values
    // {2, 3, 5, 7, 2, 4, 8, ... }
    // and x_len is 7.

    x_len += y_len;

    for (int i = 0; i < x_len; ++i)
    {
        std::cout << x[i] << ' ';
    }

    std::cout << '\n';
    
    return 0;
}
