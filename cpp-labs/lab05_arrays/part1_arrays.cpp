#include <cstddef>
#include <iostream>

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};

    const std::size_t length =
        sizeof(numbers) / sizeof(numbers[0]);

    int sum = 0;
    int smallest = numbers[0];
    int largest = numbers[0];

    for (int value : numbers)
    {
        sum += value;

        if (value < smallest)
        {
            smallest = value;
        }

        if (value > largest)
        {
            largest = value;
        }
    }

    const double average =
        static_cast<double>(sum) / length;

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Smallest: " << smallest << '\n';
    std::cout << "Largest: " << largest << '\n';
    std::cout << "Average: " << average << '\n';

    std::cout << "Reverse order:\n";

    for (std::size_t index = length; index > 0; --index)
    {
        std::cout << numbers[index - 1] << '\n';
    }

    return 0;
}