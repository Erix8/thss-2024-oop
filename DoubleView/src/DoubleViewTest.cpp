#include <cmath>
#include <iostream>
#include <limits>

#include "DoubleView.h"
#include "DoubleViewTest.h"

static int gFailures = 0;

static void check(bool ok, const std::string& what)
{
    if (ok)
    {
        std::cout << "  PASS  " << what << '\n';
    }
    else
    {
        std::cout << "  FAIL  " << what << '\n';
        ++gFailures;
    }
}

static unsigned long long expBits(unsigned long long b)
{
    return (b >> 52) & 0x7FFULL;
}

static unsigned long long fracBits(unsigned long long b)
{
    return b & 0xFFFFFFFFFFFFFULL;
}

static void testKnownPatterns()
{
    std::cout << "\nFunctional tests (known IEEE-754 patterns)\n";

    check(DoubleView(0.0).getBits() == 0x0000000000000000ULL,
          "1) 0.0   -> bits 0x0000000000000000");
    check(DoubleView(1.0).getBits() == 0x3FF0000000000000ULL,
          "2) 1.0   -> bits 0x3FF0000000000000");
    check(DoubleView(-2.0).getBits() == 0xC000000000000000ULL,
          "3) -2.0  -> bits 0xC000000000000000");
    check(DoubleView(0.5).getBits() == 0x3FE0000000000000ULL,
          "4) 0.5   -> bits 0x3FE0000000000000");
}

static void testNanAndInf()
{
    std::cout << "\nNaN / infinity tests\n";

    double nanValue = std::numeric_limits<double>::quiet_NaN();
    unsigned long long nanBits = DoubleView(nanValue).getBits();
    check(std::isnan(nanValue)
              && expBits(nanBits) == 0x7FFULL
              && fracBits(nanBits) != 0ULL,
          "5) NaN: exponent all ones and a non-zero fraction");

    double infValue = std::numeric_limits<double>::infinity();
    unsigned long long infBits = DoubleView(infValue).getBits();
    check(std::isinf(infValue)
              && expBits(infBits) == 0x7FFULL
              && fracBits(infBits) == 0ULL,
          "6) +inf: exponent all ones and fraction zero");

    double negInfValue = -std::numeric_limits<double>::infinity();
    unsigned long long negInfBits = DoubleView(negInfValue).getBits();
    check(std::isinf(negInfValue)
              && ((negInfBits >> 63) & 1ULL) == 1ULL
              && expBits(negInfBits) == 0x7FFULL
              && fracBits(negInfBits) == 0ULL,
          "7) -inf: sign 1, exponent all ones and fraction zero");
}

int runAllDoubleViewTests()
{
    std::cout << "DoubleView tests\n";
    testKnownPatterns();
    testNanAndInf();

    std::cout << "\nFailed checks: " << gFailures << '\n';
    return gFailures;
}
