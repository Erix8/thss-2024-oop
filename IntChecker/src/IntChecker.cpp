#include <climits>

#include "IntChecker.h"

long long IntChecker::parse(const std::string& text) const
{
    if (text.empty())
    {
        throw 1;   // empty input
    }

    // 1) an optional leading sign
    std::size_t i = 0;
    int sign = 1;
    if (text[i] == '+' || text[i] == '-')
    {
        if (text[i] == '-')
        {
            sign = -1;
        }
        ++i;
    }

    // 2) the digits
    long long value = 0;
    bool anyDigit = false;
    char firstDigit = 0;   // to detect a leading zero later

    for (; i < text.size(); ++i)
    {
        const char c = text[i];

        if (c == ' ')
        {
            throw 2;   // a space inside the token
        }
        if (c == '+' || c == '-')
        {
            throw 4;   // another sign (misplaced / repeated)
        }
        if (c < '0' || c > '9')
        {
            throw 3;   // some other non-digit character
        }

        // it is a digit
        if (!anyDigit)
        {
            firstDigit = c;
            anyDigit = true;
        }
        else if (firstDigit == '0')
        {
            throw 6;   // leading zero, e.g. "007"
        }

        const int digit = c - '0';
        if (value > (LLONG_MAX - digit) / 10)
        {
            throw 7;   // overflow
        }
        value = value * 10 + digit;
    }

    if (!anyDigit)
    {
        throw 5;   // a sign but no digits (e.g. "+" or "-")
    }

    return sign * value;
}
