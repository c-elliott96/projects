#include <iostream>


bool is_palindrome (char string[30])
{
    int i = 0;
    int str_len = 0;
    while (string[i] != '\0')
    {
        ++str_len;
        ++i;
    }

    for (int j = 0; j < str_len; ++j)
        {
            if (string[j] != string[str_len - j - 1])
                {
                    return false;
                }
            else
                return true;
        }
}


int main()
{
    char string[30];

    std::cin >> string;

    std::cout << is_palindrome(string) << '\n';
    
    return 0;
}
