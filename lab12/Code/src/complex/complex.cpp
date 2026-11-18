#include "complex.hpp"

// Construc
    Complex::Complex()
        : real_(0), imaginary_(0)
    {
        log("Log", "");
    }

    Complex::Complex(int r, int i)
        : real_(r), imaginary_(i)
    {
        log("Log", "");
    }

    
// Copy
        Complex::Complex(const Complex& other)
            : real_(other.real_), imaginary_(other.imaginary_)
        {
            log("Log", "");
        }

        
// Operators

    // Arithmetics
        Complex& Complex::operator=(const Complex& other)
        {
            if (this == &other)
                return *this;

            real_      = other.real_;
            imaginary_ = other.imaginary_;

            return *this;
        }

        Complex Complex::operator+(const Complex& other) const
        {
            return Complex(real_ + other.real_,
                        imaginary_ + other.imaginary_);
        }

        Complex Complex::operator-(const Complex& other) const
        {
            return Complex(real_ - other.real_,
                        imaginary_ - other.imaginary_);
        }

        Complex Complex::operator*(const Complex& other) const
        {
            return Complex(real_ * other.real_ - imaginary_ * other.imaginary_,
                        real_ * other.imaginary_ + imaginary_ * other.real_);
        }


    // Compar
        bool Complex::operator>(const Complex& other) const
        {
            return Modulo() > other.Modulo();
        }
        

    // Increment
        Complex& Complex::operator++()
        {
            ++real_;
            ++imaginary_;

            return *this;
        }

        Complex Complex::operator++(int)
        {
            Complex tmp = *this;

            ++(*this);

            return tmp;
        }

        Complex& Complex::operator+=(const Complex& other)
        {
            real_ += other.real_;
            imaginary_ += other.imaginary_;

            return *this;
        }


    // iostream is friend
        std::ostream& operator<<(std::ostream& out, const Complex& c)
        {
            out << "Complex num: r = " << c.real_
                << ", i = " << c.imaginary_ << "\n";

            return out;
        }

        std::istream& operator>>(std::istream& in, Complex& c)
        {
            std::cout << "Enter real and imaginary parts: ";

            in >> c.real_ >> c.imaginary_;

            return in;
        }

// Methods
    void Complex::Show() const
    {
        std::cout << real_;
        if(imaginary_ == 1)     std::cout << " + " << "i ";
        else if(imaginary_ > 0) std::cout << " + " << imaginary_ << "i ";
        else if(imaginary_ < 0) std::cout << " " << imaginary_ << "i ";
    };

    double Complex::Modulo() const
    {
        return sqrt(pow(real_, 2) + pow(imaginary_, 2));
    }