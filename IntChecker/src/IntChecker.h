#pragma once

#include <string>

// A tiny checker (homework 12, exception handling). It analyses a line of
// text and decides whether it is a valid integer representation. If it is,
// parse() returns the integer; if not, parse() throws an int whose value
// tells you WHY it failed. Different reasons throw different values.
class IntChecker
{
public:
    // The reason codes thrown by parse():
    //   1  the input is empty
    //   2  the input contains spaces/whitespace
    //   3  the input contains other non-digit characters (letters, etc.)
    //   4  there are too many / misplaced '+' or '-' signs
    //   5  only a sign, no digits (e.g. "+" or "-")
    //   6  leading zero in a number with more than one digit (e.g. "007")
    //   7  the number is too big to fit in a long
    long long parse(const std::string& text) const;
};
