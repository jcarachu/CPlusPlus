//============================================================================
// Name         : Complex.cpp
// Description  : Complex Numbers in C++, Ansi-style
//============================================================================
#include "ComplexNumbers.h"

namespace complexnumbersblock {
    ComplexNumbers::ComplexNumbers(): 
    real(0), imaginary(0) {}

    ComplexNumbers::ComplexNumbers(double real, double imaginary):
    real(real), imaginary(imaginary) {}

    ComplexNumbers::ComplexNumbers(const ComplexNumbers &other)
    {
        real = other.real;
        imaginary = other.imaginary;
    }
    
    const ComplexNumbers &ComplexNumbers::operator=(const ComplexNumbers &other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    ostream &operator<<(ostream &out, const ComplexNumbers &c)
    {
        out << "(" << c.getReal() << ", " << c.getImaginary() << ")";
        return out;
    }

    ComplexNumbers operator+(const ComplexNumbers &c1, const ComplexNumbers &c2)
    {
        return ComplexNumbers(c1.getReal() +c2.getReal(), c1.getImaginary() + c2.getImaginary());
    }

    ComplexNumbers operator+(const ComplexNumbers &c1, int d)
    {
        return ComplexNumbers(c1.getReal() + d, c1.getImaginary());
    }

    ComplexNumbers operator+(const ComplexNumbers &c1, double d)
    {
        return ComplexNumbers(c1.getReal() + d, c1.getImaginary());
    }

    ComplexNumbers operator+(int d, const ComplexNumbers &c1)
    {
        return ComplexNumbers(c1.getReal() + d, c1.getImaginary());
    }
    ComplexNumbers operator+(double d, const ComplexNumbers &c1)
    {
        return ComplexNumbers(c1.getReal() + d, c1.getImaginary());
    }

} /* namespace complexnumbersblock */