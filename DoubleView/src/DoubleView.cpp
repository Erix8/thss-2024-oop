#include <bitset>
#include <iomanip>
#include <iostream>

#include "DoubleView.h"

DoubleView::DoubleView(double value)
{
    data_.value = value;
}

void DoubleView::show(const std::string& label) const
{
    const unsigned long long b = data_.bits;
    const std::string full = std::bitset<64>(b).to_string();

    std::cout << label << '\n';
    std::cout << "  value  = " << data_.value << '\n';
    std::cout << "  hex    = 0x" << std::hex << b << std::dec << '\n';
    std::cout << "  sign   = " << full.substr(0, 1) << '\n';
    std::cout << "  exp    = " << full.substr(1, 11) << '\n';
    std::cout << "  frac   = " << full.substr(12, 52) << '\n';
    std::cout << "  binary = " << full << '\n';
}
