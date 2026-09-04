#include <iostream>
#include <string>

#include "IntChecker.h"

static void printReason(int code)
{
    switch (code)
    {
    case 1: std::cout << "  reason 1: the input is empty.\n"; break;
    case 2: std::cout << "  reason 2: the input contains spaces.\n"; break;
    case 3: std::cout << "  reason 3: it has a non-digit character.\n"; break;
    case 4: std::cout << "  reason 4: too many or misplaced '+'/'-' signs.\n"; break;
    case 5: std::cout << "  reason 5: a sign but no digits (like \"+\").\n"; break;
    case 6: std::cout << "  reason 6: a leading zero (like \"007\").\n"; break;
    case 7: std::cout << "  reason 7: the number is too big for a long.\n"; break;
    default: std::cout << "  reason " << code << ": unknown.\n"; break;
    }
}

int main()
{
    std::cout << "Type lines of text; an empty line ends the program.\n";
    IntChecker checker;

    std::string line;
    while (true)
    {
        std::cout << "\nEnter a string: ";
        std::getline(std::cin, line);
        if (line.empty())
        {
            break;
        }

        try
        {
            long long value = checker.parse(line);
            std::cout << "  OK: it is the integer " << value << ".\n";
        }
        catch (int code)
        {
            std::cout << "  Invalid integer.\n";
            printReason(code);
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
