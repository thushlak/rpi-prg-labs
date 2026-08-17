#include <cstdint>
#include <iostream>
#include <limits>

int main()
{   
    std::int8_t signed_byte{-20};
    std::uint8_t unsigned_byte{250};

    std::int16_t temperature{-120};
    std::uint16_t sensor_value{65000};

    std::int32_t error_code{-50000};
    std::uint32_t register_value{0xDEADBEEF};

    std::int64_t timestamp{9876543210LL};

    // Unary + forces 8-bit integers to print numerically.
    std::cout << "Signed byte: "
              << +signed_byte << '\n';

    std::cout << "Unsigned byte: "
              << +unsigned_byte << '\n';

    std::cout << "Temperature: "
              << temperature << '\n';

    std::cout << "Sensor value: "
              << sensor_value << '\n';

    std::cout << "Error code: "
              << error_code << '\n';

    std::cout << "Register value: 0x"
              << std::hex << register_value << std::dec << '\n';

    std::cout << "Timestamp: "
              << timestamp << '\n';

    std::cout << "\n--- Sizes ---\n";
    std::cout << "int8_t:   " << sizeof(std::int8_t) << " byte\n";
    std::cout << "uint16_t: " << sizeof(std::uint16_t) << " bytes\n";
    std::cout << "uint32_t: " << sizeof(std::uint32_t) << " bytes\n";
    std::cout << "int64_t:  " << sizeof(std::int64_t) << " bytes\n";

    std::cout << "\nMaximum uint8_t: "
              << +std::numeric_limits<std::uint8_t>::max() << '\n';

    return 0;
}