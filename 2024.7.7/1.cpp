#include <cstdint>
#include <iostream>

int main()
{
    int64_t num;
    std::cin >> num;
    for (int64_t i = 3; i <= num; i++)
    {
        if (num % i == 0)
        {
            std::cout << i;
            return 0;
        }
    }
    return 0;
}
