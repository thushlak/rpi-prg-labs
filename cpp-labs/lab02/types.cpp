#include <iostream>
#include <limits>

int main()
{
    char status = 'A';
    bool driver_loaded = true;
    short sensor_id = 280;
    int temperature = 26;
    long error_count = 1000;
    long long uptime_seconds = 9876543210LL;
    float voltage = 3.3F;
    double precise_voltage = 3.300001;

    std::cout << "--- Values and Memory Sizes ---\n";

    std::cout << "char:      " << status
              << " | size: " << sizeof(status) << " byte\n";

    std::cout << "bool:      " << std::boolalpha << driver_loaded
              << " | size: " << sizeof(driver_loaded) << " byte\n";

    std::cout << "short:     " << sensor_id
              << " | size: " << sizeof(sensor_id) << " bytes\n";

    std::cout << "int:       " << temperature
              << " | size: " << sizeof(temperature) << " bytes\n";

    std::cout << "long:      " << error_count
              << " | size: " << sizeof(error_count) << " bytes\n";

    std::cout << "long long: " << uptime_seconds
              << " | size: " << sizeof(uptime_seconds) << " bytes\n";

    std::cout << "float:     " << voltage
              << " | size: " << sizeof(voltage) << " bytes\n";

    std::cout << "double:    " << precise_voltage
              << " | size: " << sizeof(precise_voltage) << " bytes\n";

    std::cout << "\n--- Integer Limits ---\n";
    std::cout << "Minimum int: " << std::numeric_limits<int>::min() << '\n';
    std::cout << "Maximum int: " << std::numeric_limits<int>::max() << '\n';

    return 0;
}