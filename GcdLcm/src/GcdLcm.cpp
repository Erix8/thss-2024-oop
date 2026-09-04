#include "GcdLcm.h"

GcdLcm::GcdLcm(int firstNumber, int secondNumber)
    : firstNumber_(firstNumber),
      secondNumber_(secondNumber)
{
    gcd_ = computeGcd(firstNumber_, secondNumber_);
    // LCM = product of the two numbers / GCD; divide first, then multiply
    // to keep the intermediate value small and avoid overflow.
    lcm_ = firstNumber_ / gcd_ * secondNumber_;
}

// Recursive Euclidean algorithm: gcd(a, b) = gcd(b, a % b).
int GcdLcm::computeGcd(int first, int second) const
{
    return second == 0 ? first : computeGcd(second, first % second);
}

int GcdLcm::gcd() const
{
    return gcd_;
}

int GcdLcm::lcm() const
{
    return lcm_;
}
