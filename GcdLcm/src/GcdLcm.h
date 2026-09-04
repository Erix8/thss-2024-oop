#pragma once

// Computes and stores the Greatest Common Divisor (GCD) and the Least Common
// Multiple (LCM) of two given positive integers.
class GcdLcm
{
public:
    GcdLcm(int firstNumber, int secondNumber);

    int gcd() const;   // Greatest Common Divisor
    int lcm() const;   // Least Common Multiple

private:
    int computeGcd(int first, int second) const;   // Recursive Euclidean algorithm

    int firstNumber_;   // First positive integer input
    int secondNumber_;  // Second positive integer input
    int gcd_;           // Greatest Common Divisor
    int lcm_;           // Least Common Multiple
};
