#include <iostream>
using namespace std;

class Complex {
    private:
        double real, img;

    public:
        Complex(double _real, double _img) : real(_real), img(_img) {}
        Complex(Complex& c) : real(c.real), img(c.img) {}

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);
        Complex& operator=(const Complex& c);
        Complex operator+=(const Complex& c);

        void println();
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) {
    Complex temp((real * c.real - img * c.img), (real * c.img + img * c.real));
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp((real * c.real + img + c.img) / (c.real * c.real + c.img * c.img), 
    (c.real * img - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator=(const Complex& c) {
     real = c.real;
     img = c.img;
     return *this;
}

void Complex::println() {
    cout << "(" << real << ", " << img << ")" << endl;
}

