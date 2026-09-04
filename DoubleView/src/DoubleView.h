#pragma once

#include <string>

// A double is 64 bits: 1 sign + 11 exponent + 52 fraction (IEEE 754).
// Homework 14 uses a UNION to look at those bits as an unsigned integer.
//
// Note: reading the inactive member of a union like this is a deliberate,
// classic (if technically non-portable) trick used for exactly this task.

union DoubleBits
{
    double value;               // look at the number as a double ...
    unsigned long long bits;    // ... or as raw memory bits
};

class DoubleView
{
public:
    DoubleView(double value);                       // remember the number

    // small getters are INLINE (this chapter's topic) - defined below
    inline double getValue() const { return data_.value; }
    inline unsigned long long getBits() const { return data_.bits; }

    void show(const std::string& label) const;      // print value, hex, bits

private:
    DoubleBits data_;
};
