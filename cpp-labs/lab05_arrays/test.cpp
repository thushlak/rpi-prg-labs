#include <array>
#include <exception>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    try
    {
        std::cout << numbers.at(2) << '\n';
    }
    catch (const std::out_of_range &error)
    {
        std::cerr << "Index error: "
                  << error.what() << '\n';
    }

    return 0;
}