#include <iostream>


double f(double x[], int x_len)
{
    if (x_len == 0)
    {
        return 0.0;
    }

    else
    {
        return (x[x_len - 1] * x[x_len - 1] + f(x, x_len - 1));
    }
}


int main()
{
    int x_len = 5;
    
    
    double x[x_len] = {0.0, 3.0, 1.0, 2.0, 4.0};

    std::cout << f(x, 0) << std::endl;
    std::cout << f(x, 1) << std::endl;
    std::cout << f(x, 2) << std::endl;
    std::cout << f(x, 3) << std::endl;
    std::cout << f(x, 4) << std::endl;
    
    return 0;
}
