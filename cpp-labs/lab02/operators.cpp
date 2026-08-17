#include <iostream>
#include <iomanip>

int main()
{
    constexpr 
    
    double maximum_voltage{3.3};

    int raw_temperature{27};
    int calibration_offset{-2};

    double measured_voltage{3.15};
    double current_ma{12.5};

    int corrected_temperature{
        raw_temperature + calibration_offset
    };

    double power_mw{
        measured_voltage * current_ma
    };

    bool voltage_safe{
        measured_voltage <= maximum_voltage
    };

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "--- Sensor Calculation ---\n";
    std::cout << "Raw temperature: "
              << raw_temperature << " C\n";

    std::cout << "Calibration offset: "
              << calibration_offset << " C\n";

    std::cout << "Corrected temperature: "
              << corrected_temperature << " C\n";

    std::cout << "Measured voltage: "
              << measured_voltage << " V\n";

    std::cout << "Current: "
              << current_ma << " mA\n";

    std::cout << "Power: "
              << power_mw << " mW\n";

    std::cout << std::boolalpha;
    std::cout << "Voltage safe: "
              << voltage_safe << '\n';

    return 0;
}