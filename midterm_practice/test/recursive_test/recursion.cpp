#include <iostream>


int f(int * x)
{
    return (x != NULL ? 42 : *x);
}


int main()
{
    int a = 2;
    std::cout << f(&a); //<< ' ' << f(NULL) << std::endl;
    return 0;
}
