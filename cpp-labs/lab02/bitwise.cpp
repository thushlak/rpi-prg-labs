#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint8_t power_bit{1U << 0};
    constexpr std::uint8_t ready_bit{1U << 1};
    constexpr std::uint8_t error_bit{1U << 2};

    std::uint8_t status_register{0};

    std::cout << "Initial:      "
              << std::bitset<8>(status_register) << '\n';

    // Set the power bit.
    status_register |= power_bit;

    std::cout << "Power set:    "
              << std::bitset<8>(status_register) << '\n';

    // Set the ready bit.
    status_register |= ready_bit;

    std::cout << "Ready set:    "
              << std::bitset<8>(status_register) << '\n';

    // Test whether the ready bit is set.
    bool is_ready{
        (status_register & ready_bit) != 0
    };

    std::cout << std::boolalpha;
    std::cout << "Device ready: " << is_ready << '\n';

    // Set the error bit.
    status_register |= error_bit;

    std::cout << "Error set:    "
              << std::bitset<8>(status_register) << '\n';

    // Clear the error bit.
    status_register &= static_cast<std::uint8_t>(~error_bit);

    std::cout << "Error cleared:"
              << std::bitset<8>(status_register) << '\n';

    // Toggle the power bit.
    status_register ^= power_bit;

    std::cout << "Power toggled:"
              << std::bitset<8>(status_register) << '\n';

    return 0;
}