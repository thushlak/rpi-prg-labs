#include <iostream>
#include <iomanip>

int main()
{
    int total_readings{7};
    int total_temperature{181};

    // Both operands are integers
    int integer_average{
        total_temperature / total_readings
    };

    // Explicitly convert one operand to double
    double precise_average{
        static_cast<double>(total_temperature) / total_readings
    };

    double measured_voltage{3.78};

    // Explicit conversion from double to int
    int whole_voltage{
        static_cast<int>(measured_voltage)
    };

    int seconds{3675};

    int hours{seconds / 3600};
    int remaining_seconds{seconds % 3600};
    int minutes{remaining_seconds / 60};
    int final_seconds{remaining_seconds % 60};

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "--- Type Conversion ---\n";
    std::cout << "Integer average: "
              << integer_average << '\n';

    std::cout << "Precise average: "
              << precise_average << '\n';

    std::cout << "Measured voltage: "
              << measured_voltage << '\n';

    std::cout << "Converted to int: "
              << whole_voltage << '\n';

    std::cout << "\n--- Division and Remainder ---\n";
    std::cout << seconds << " seconds = "
              << hours << " hour(s), "
              << minutes << " minute(s), "
              << final_seconds << " second(s)\n";
    
    int error_count{0};

        error_count++;
        error_count++;
        error_count += 3;
        error_count -= 1;

    std::cout << "\nFinal error count: "
          << error_count << '\n';

    return 0;
}