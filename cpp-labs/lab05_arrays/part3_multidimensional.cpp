#include <cstddef>
#include <iostream>

int main()
{
    constexpr std::size_t rows = 3;
    constexpr std::size_t columns = 4;

    int matrix[rows][columns] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (std::size_t row = 0; row < rows; ++row)
    {
        for (std::size_t column = 0;
             column < columns;
             ++column)
        {
            std::cout << matrix[row][column] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}