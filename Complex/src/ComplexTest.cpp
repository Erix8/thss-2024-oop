#include <cmath>
#include <iostream>
#include <string>

#include "Complex.h"
#include "ComplexTest.h"

static int gFailures = 0;

static void check(bool ok, std::string what)
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

static bool close(double x, double y)
{
    double d = x - y;
    if (d < 0.0)
    {
        d = -d;
    }
    return d < 1e-9;
}

static bool same(Complex x, Complex y)
{
    return close(x.real(), y.real()) && close(x.imaginary(), y.imaginary());
}

// ---------- the five sample situations used below ----------
//  (0,0) zero, (5,0) pure real, (0,4) pure imaginary,
//  mixed, and values with negative parts.

static void testAddition()
{
    std::cout << "\noperator+  (5 cases)\n";

    check(same(Complex(0, 0) + Complex(3, -2), Complex(3, -2)),
          "1) zero + (3-2i)            = (3-2i)");
    check(same(Complex(5, 0) + Complex(7, 0), Complex(12, 0)),
          "2) (5+0i) + (7+0i)          = (12+0i)");
    check(same(Complex(0, 4) + Complex(0, 6), Complex(0, 10)),
          "3) (0+4i) + (0+6i)          = (0+10i)   (pure imaginary)");
    check(same(Complex(5, 0) + Complex(0, 4), Complex(5, 4)),
          "4) (5+0i) + (0+4i)          = (5+4i)    (real + pure imaginary)");
    check(same(Complex(-3, -4) + Complex(1, 7), Complex(-2, 3)),
          "5) (-3-4i) + (1+7i)         = (-2+3i)   (negative parts)");
}

static void testSubtraction()
{
    std::cout << "\noperator-  (5 cases)\n";

    check(same(Complex(3, -2) - Complex(0, 0), Complex(3, -2)),
          "1) (3-2i) - zero            = (3-2i)");
    check(same(Complex(9, 0) - Complex(5, 0), Complex(4, 0)),
          "2) (9+0i) - (5+0i)          = (4+0i)");
    check(same(Complex(0, 4) - Complex(0, 6), Complex(0, -2)),
          "3) (0+4i) - (0+6i)          = (0-2i)    (pure imaginary)");
    check(same(Complex(5, 0) - Complex(0, 4), Complex(5, -4)),
          "4) (5+0i) - (0+4i)          = (5-4i)    (real - pure imaginary)");
    check(same(Complex(-3, 2) - Complex(1, -5), Complex(-4, 7)),
          "5) (-3+2i) - (1-5i)         = (-4+7i)   (negative parts)");
}

static void testMultiplication()
{
    std::cout << "\noperator*  (5 cases)\n";

    check(same(Complex(0, 0) * Complex(3, -2), Complex(0, 0)),
          "1) zero * (3-2i)            = (0+0i)");
    check(same(Complex(3, 0) * Complex(4, 0), Complex(12, 0)),
          "2) (3+0i) * (4+0i)          = (12+0i)");
    check(same(Complex(0, 3) * Complex(0, 4), Complex(-12, 0)),
          "3) (0+3i) * (0+4i)          = (-12+0i)  (pure imaginary)");
    check(same(Complex(2, 0) * Complex(0, 5), Complex(0, 10)),
          "4) (2+0i) * (0+5i)          = (0+10i)   (real * pure imaginary)");
    check(same(Complex(3, -2) * Complex(-1, 4), Complex(5, 14)),
          "5) (3-2i) * (-1+4i)         = (5+14i)   (negative parts)");
}

static void testDivision()
{
    std::cout << "\noperator/  (5 cases)\n";

    check(same(Complex(8, 0) / Complex(2, 0), Complex(4, 0)),
          "1) (8+0i) / (2+0i)          = (4+0i)");
    check(same(Complex(0, 8) / Complex(0, 2), Complex(4, 0)),
          "2) (0+8i) / (0+2i)          = (4+0i)    (pure imaginary)");
    check(same(Complex(6, 0) / Complex(0, 3), Complex(0, -2)),
          "3) (6+0i) / (0+3i)          = (0-2i)    (divide by pure imaginary)");
    check(same(Complex(1, 1) / Complex(1, -1), Complex(0, 1)),
          "4) (1+1i) / (1-1i)          = (0+1i)");
    check(same(Complex(3, -2) / Complex(1, 2), Complex(-0.2, -1.6)),
          "5) (3-2i) / (1+2i)          = (-0.2-1.6i) (negative parts)");
}


static void testPrefixIncrement()
{
    std::cout << "\noperator++ (prefix, +1 to the real part)  (5 cases)\n";

    // Zero, pure real, pure imaginary, mixed, negative parts.
    check(same(++Complex(0, 0), Complex(1, 0)),
          "1) ++(0+0i)      = (1+0i)");
    check(same(++Complex(5, 0), Complex(6, 0)),
          "2) ++(5+0i)      = (6+0i)");
    check(same(++Complex(0, 4), Complex(1, 4)),
          "3) ++(0+4i)      = (1+4i)   (pure imaginary keeps imaginary)");
    check(same(++Complex(3, -2), Complex(4, -2)),
          "4) ++(3-2i)      = (4-2i)");
    check(same(++Complex(-3, -4), Complex(-2, -4)),
          "5) ++(-3-4i)     = (-2-4i)");
}

static void testPostfixIncrement()
{
    std::cout << "\noperator++ (postfix)  (5 cases)\n";

    Complex c = Complex(0, 0);
    Complex old = c++;
    check(same(old, Complex(0, 0)) && same(c, Complex(1, 0)),
          "1) c=(0+0i): c++ returns (0+0i), c becomes (1+0i)");

    c = Complex(5, 0);
    old = c++;
    check(same(old, Complex(5, 0)) && same(c, Complex(6, 0)),
          "2) c=(5+0i): c++ returns (5+0i), c becomes (6+0i)");

    c = Complex(0, 4);
    old = c++;
    check(same(old, Complex(0, 4)) && same(c, Complex(1, 4)),
          "3) c=(0+4i): c++ returns (0+4i), c becomes (1+4i)");

    c = Complex(3, -2);
    old = c++;
    check(same(old, Complex(3, -2)) && same(c, Complex(4, -2)),
          "4) c=(3-2i): c++ returns (3-2i), c becomes (4-2i)");

    c = Complex(-3, -4);
    old = c++;
    check(same(old, Complex(-3, -4)) && same(c, Complex(-2, -4)),
          "5) c=(-3-4i): c++ returns (-3-4i), c becomes (-2-4i)");
}

static void testPrefixDecrement()
{
    std::cout << "\noperator-- (prefix, -1 to the real part)  (5 cases)\n";

    check(same(--Complex(0, 0), Complex(-1, 0)),
          "1) --(0+0i)      = (-1+0i)");
    check(same(--Complex(5, 0), Complex(4, 0)),
          "2) --(5+0i)      = (4+0i)");
    check(same(--Complex(0, 4), Complex(-1, 4)),
          "3) --(0+4i)      = (-1+4i)");
    check(same(--Complex(3, -2), Complex(2, -2)),
          "4) --(3-2i)      = (2-2i)");
    check(same(--Complex(-3, -4), Complex(-4, -4)),
          "5) --(-3-4i)     = (-4-4i)");
}

static void testPostfixDecrement()
{
    std::cout << "\noperator-- (postfix)  (5 cases)\n";

    Complex c = Complex(0, 0);
    Complex old = c--;
    check(same(old, Complex(0, 0)) && same(c, Complex(-1, 0)),
          "1) c=(0+0i): c-- returns (0+0i), c becomes (-1+0i)");

    c = Complex(5, 0);
    old = c--;
    check(same(old, Complex(5, 0)) && same(c, Complex(4, 0)),
          "2) c=(5+0i): c-- returns (5+0i), c becomes (4+0i)");

    c = Complex(0, 4);
    old = c--;
    check(same(old, Complex(0, 4)) && same(c, Complex(-1, 4)),
          "3) c=(0+4i): c-- returns (0+4i), c becomes (-1+4i)");

    c = Complex(3, -2);
    old = c--;
    check(same(old, Complex(3, -2)) && same(c, Complex(2, -2)),
          "4) c=(3-2i): c-- returns (3-2i), c becomes (2-2i)");

    c = Complex(-3, -4);
    old = c--;
    check(same(old, Complex(-3, -4)) && same(c, Complex(-4, -4)),
          "5) c=(-3-4i): c-- returns (-3-4i), c becomes (-4-4i)");
}

int runAllComplexTests()
{
    std::cout << "Complex operator-overload tests\n";

    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testPrefixIncrement();
    testPostfixIncrement();
    testPrefixDecrement();
    testPostfixDecrement();

    std::cout << "\nFailed checks: " << gFailures << '\n';
    return gFailures;
}

