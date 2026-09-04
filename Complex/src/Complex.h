#pragma once

// Homework 05 belongs to this week's topic, polymorphism; the concrete method
// we practise here is OPERATOR OVERLOADING: making +, -, *, /, ++ and -- work
// on Complex numbers. The real and imaginary parts are private
// (encapsulation), so the free operators below go through the public getters
// real()/imag().
class Complex
{
public:
    Complex();                                  // the number (0,0)
    Complex(double real, double imaginary);     // build (real, imaginary)

    double real();        // the real part
    double imaginary();   // the imaginary part

    void print();         // print in the form a+bi (or a-bi)

    // ++ and -- change only the REAL part by 1 (a design choice).
    Complex& operator++();      // prefix  ++c
    Complex  operator++(int);   // postfix c++
    Complex& operator--();      // prefix  --c
    Complex  operator--(int);   // postfix c--

private:
    double real_;
    double imaginary_;
};

// Binary arithmetic: implemented as free functions through the getters.
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
