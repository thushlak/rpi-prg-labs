#include <iostream>
#include <string>

int  main ()
{
    std::string device_name;
    int temperature;
    double voltage;
    char status;
    bool driver_loaded;

    std::cout << "Enter device name: ";
    std::cin >> device_name;

    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    std::cout << "Enter voltage: ";
    std::cin >> voltage;

    std::cout << "Enter status character: ";
    std::cin >> status;

    std::cout << "Is the driver loaded? Enter 1 for yes or 0 for no: ";
    std::cin >> driver_loaded;

    std::cout << "\n--- Device Report ---\n";
    std::cout << "Device: " << device_name << '\n';
    std::cout << "Temperature: " << temperature << " C\n";
    std::cout << "Voltage: " << voltage << " V\n";
    std::cout << "Status: " << status << '\n';
    std::cout << std::boolalpha;
    std::cout << "Driver loaded: " << driver_loaded << '\n';

    return 0;
}
