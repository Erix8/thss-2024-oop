#include <iostream>

#include "GcdLcm.h"

int main()
{
    std::cout << "Enter two positive integers: ";

    int firstNumber = 0;
    int secondNumber = 0;
    std::cin >> firstNumber >> secondNumber;

    if (firstNumber <= 0 || secondNumber <= 0)
    {
        std::cout << "Invalid input." << std::endl;
        return -1;
    }

    GcdLcm calculator(firstNumber, secondNumber);
    std::cout << "GCD: " << calculator.gcd() << std::endl;
    std::cout << "LCM: " << calculator.lcm() << std::endl;

    return 0;
}
