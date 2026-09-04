#include <iostream>

#include "FuPrinter.h"

FuPrinter::FuPrinter(char symbol) : symbol_(symbol) {}

// Print the rows of console output that together form the “福” picture.
void FuPrinter::drawFu() const
{
    const char s = symbol_;

    std::cout << "   " << s << "    " << s << s << s << s << s << '\n';
    std::cout << '\n';
    std::cout << ' ' << s << s << s << s << "   " << s << s << s << s << s << '\n';
    std::cout << "    " << s << "   " << s << "   " << s << '\n';
    std::cout << "   " << s << "    " << s << s << s << s << s << '\n';
    std::cout << "  " << s << s << s << s << '\n';
    std::cout << ' ' << s << ' ' << s << s << "  " << s << s << s << s << s << s << s << '\n';
    std::cout << "   " << s << ' ' << s << ' ' << s << "  " << s << "  " << s << '\n';
    std::cout << "   " << s << "   " << s << s << s << s << s << s << s << '\n';
    std::cout << "   " << s << "   " << s << "  " << s << "  " << s << '\n';
    std::cout << "   " << s << "   " << s << s << s << s << s << s << s << '\n';
    std::cout << '\n';
}
