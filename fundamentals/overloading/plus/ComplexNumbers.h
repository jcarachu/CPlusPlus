//============================================================================
// Name         : Complex.h
// Description  : Complex Numbers in C++, Ansi-style
//============================================================================
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;

namespace complexnumbersblock{
    class ComplexNumbers {
        private: 
            double real;
            double imaginary;
        
        public:
            ComplexNumbers();
            ComplexNumbers(double real, double imaginary);
            ComplexNumbers(const ComplexNumbers &other);
            const ComplexNumbers &operator=(const ComplexNumbers &other);

            double getReal() const { return real; }
            double getImaginary() const{ return imaginary; }
    };

    ostream &operator<<(ostream &out, const ComplexNumbers &c);
    ComplexNumbers operator+(const ComplexNumbers &c1, const ComplexNumbers &c2);
    ComplexNumbers operator+(const ComplexNumbers &c1, int d);
    ComplexNumbers operator+(const ComplexNumbers &c1, double d);
    ComplexNumbers operator+(int d, const ComplexNumbers &c1);
    ComplexNumbers operator+(double d, const ComplexNumbers &c1);
} /* namespace complexblock*/
#endif /* COMPLEX_H_ */