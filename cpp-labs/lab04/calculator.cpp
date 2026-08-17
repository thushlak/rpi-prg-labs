#include <iostream>
#include <limits>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

int main()
{
    int choice;
    double num1;
    double num2;
    double result;

    std::cout << "=========================\n";
    std::cout << "   C++ Simple Calculator\n";
    std::cout << "=========================\n";

    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";

    std::cout << "\nChoose an option (1-4): ";
    std::cin >> choice;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch (choice)
    {
        case 1:
            result = add(num1, num2);
            std::cout << "Result: " << result << '\n';
            break;

        case 2:
            result = subtract(num1, num2);
            std::cout << "Result: " << result << '\n';
            break;

        case 3:
            result = multiply(num1, num2);
            std::cout << "Result: " << result << '\n';
            break;

        case 4:
            if (num2 == 0)
            {
                std::cout << "Error: Cannot divide by zero.\n";
            }
            else
            {
                result = divide(num1, num2);
                std::cout << "Result: " << result << '\n';
            }
            break;

        default:
            std::cout << "Invalid option.\n";
            break;
    }

    return 0;
}


