#pragma once

#include <iostream>
#include <cmath>
#include "../log/log.hpp"

class Complex
{
    double real_;
    double imaginary_;

public:
    // Construc
        Complex();
        Complex(double real, double imaginary);

    // Copy
        Complex(const Complex& other);

    // Do i need "~Complex()"?

    // Operators
        // Arithmetics
            Complex& operator=(const Complex& other);
            Complex operator+(const Complex& other) const;
            Complex operator-(const Complex& other) const;
            Complex operator*(const Complex& other) const;
            Complex operator/(const Complex& other) const;


    // Compar
        bool operator>(const Complex& other) const;
        bool operator<(const Complex& other) const;
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;


    // Increment
        Complex& operator++();                                                  // pre
        Complex  operator++(int);                                               // post
    // Decrement
        Complex& operator--();                                                  // pre
        Complex  operator--(int);                                               // post

        Complex& operator+=(const Complex& other);


    // Iostream is friend
        friend std::ostream& operator<<(std::ostream& out, const Complex& c);
        friend std::istream& operator>>(std::istream& in, Complex& c);

    // Methods
        // void Show() const;
        double  Modulo() const;
};