#include <iostream>

#include "Complex.h"

Complex::Complex() : real_(0.0), imaginary_(0.0) {}

Complex::Complex(double real, double imaginary)
    : real_(real), imaginary_(imaginary) {}

double Complex::real()
{
    return real_;
}

double Complex::imaginary()
{
    return imaginary_;
}

void Complex::print()
{
    std::cout << real_;
    if (imaginary_ >= 0.0)
    {
        std::cout << '+' << imaginary_ << 'i';
    }
    else
    {
        std::cout << imaginary_ << 'i';   // already includes the minus sign
    }
}

Complex& Complex::operator++()   // prefix  ++c : change, then return c
{
    real_ = real_ + 1.0;
    return *this;
}

Complex Complex::operator++(int) // postfix c++ : return old c, then change
{
    Complex old = *this;
    real_ = real_ + 1.0;
    return old;
}

Complex& Complex::operator--()   // prefix  --c
{
    real_ = real_ - 1.0;
    return *this;
}

Complex Complex::operator--(int) // postfix c--
{
    Complex old = *this;
    real_ = real_ - 1.0;
    return old;
}

// (a+bi) + (c+di) = (a+c) + (b+d)i
Complex operator+(Complex a, Complex b)
{
    return Complex(a.real() + b.real(), a.imaginary() + b.imaginary());
}

// (a+bi) - (c+di) = (a-c) + (b-d)i
Complex operator-(Complex a, Complex b)
{
    return Complex(a.real() - b.real(), a.imaginary() - b.imaginary());
}

// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complex operator*(Complex a, Complex b)
{
    double real = a.real() * b.real() - a.imaginary() * b.imaginary();
    double imag = a.real() * b.imaginary() + a.imaginary() * b.real();
    return Complex(real, imag);
}

// (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c^2+d^2)
Complex operator/(Complex a, Complex b)
{
    double denominator = b.real() * b.real() + b.imaginary() * b.imaginary();

    if (denominator == 0.0)   // dividing by zero is not possible
    {
        std::cout << "Error: division by zero. Returning (0,0)." << std::endl;
        return Complex(0.0, 0.0);
    }

    double real = (a.real() * b.real() + a.imaginary() * b.imaginary()) / denominator;
    double imag = (a.imaginary() * b.real() - a.real() * b.imaginary()) / denominator;
    return Complex(real, imag);
}
