#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

namespace COMPLEX {
    class Complex {
    private:
        double real;
        double image;
    public:
        Complex(double real, double image);
        Complex();
        ~Complex();
        friend std::ostream& operator<<(std::ostream& os, const Complex& num);
        friend std::istream& operator>>(std::istream& os, Complex& num);
        friend Complex operator+(const Complex& num1, const Complex& num2);
        friend Complex operator-(const Complex& num1, const Complex& num2);
        friend Complex operator*(const Complex& num1, const Complex& num2);
        friend Complex operator*(const double numd, const Complex& num);
        friend Complex operator*(const Complex& num, const double numd);
        friend Complex operator~(const Complex& num);
    };
}
#endif