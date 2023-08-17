#include "complex.h"
#include <iostream>

namespace COMPLEX {

    Complex::Complex(double real, double image) {
        this->real = real;
        this->image = image;
    }

    Complex::Complex() {}

    Complex::~Complex() {}

    std::ostream& operator<<(std::ostream& os, const Complex& num) {
        os << "(" << num.real << ", " << num.image << "i)";
        return os;
    }

    std::istream& operator>>(std::istream& os, Complex& num) {
        double real, image;
        os >> real;
        os >> image;
        num.real = real;
        num.image = image;
        return os;
    }

    Complex operator+(const Complex& num1, const Complex& num2) {
        Complex ret(num1.real + num2.real, num1.image + num2.image);
        return ret;
    }

    Complex operator-(const Complex& num1, const Complex& num2) {
        Complex ret(num1.real - num2.real, num1.image - num2.image);
        return ret;
    }

    Complex operator*(const Complex& num1, const Complex& num2) {
        double real = num1.real * num2.real - num1.image * num2.image;
        double image = num1.real * num2.image + num1.image * num2.real;
        Complex ret(real, image);
        return ret;
    }

    Complex operator*(const double numd, const Complex& num) {
        Complex ret(numd * num.real, numd * num.image);
        return ret;
    }

    Complex operator*(const Complex& num, const double numd) {
        Complex ret(numd * num.real, numd * num.image);
        return ret;
    }

    Complex operator~(const Complex& num) {
        Complex ret(num.real, -num.image);
        return ret;
    }
}