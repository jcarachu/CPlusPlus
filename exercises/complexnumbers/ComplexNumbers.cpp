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
} /* namespace complexnumbersblock */