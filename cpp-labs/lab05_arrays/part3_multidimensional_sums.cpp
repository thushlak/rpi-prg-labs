#include <array>
#include <iostream>

int main()
{
    std::array<std::array<int, 4>, 3> led_grid = {{
        {{1, 0, 0, 1}},
        {{0, 1, 1, 0}},
        {{1, 1, 1, 1}}
    }};

    for (const auto &row : led_grid)
    {
        for (int led : row)
        {
            std::cout << (led == 1 ? "ON " : "OFF ");
        }

        std::cout << '\n';
    }

    return 0;
}