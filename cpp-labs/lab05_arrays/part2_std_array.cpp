#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << "Number of elements: "
              << numbers.size() << '\n';

    std::cout << "First element: "
              << numbers.front() << '\n';

    std::cout << "Last element: "
              << numbers.back() << '\n';

    for (int value : numbers)
    {
        std::cout << value << '\n';
    }

    return 0;
}