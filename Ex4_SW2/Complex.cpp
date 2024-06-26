#include "Complex.hpp"


Complex::Complex(double r, double i) : real(r), image(i) {}


Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, image + other.image);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, image - other.image);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - image * other.image, real * other.image + image * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.image * other.image;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex((real * other.real + image * other.image) / denominator,
                   (image * other.real - real * other.image) / denominator);
}

bool Complex::operator>(const Complex &other) const
{
    return (real * real + image * image) > (other.real * real + other.image * image);
}

bool Complex::operator<(const Complex &other) const
{
    return (real * real + image * image) < (other.real * real + other.image * image);
   
}

bool Complex::operator==(const Complex& other) const {
    return this->real == other.real && this->image == other.image;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator-() const {
    return Complex(-real, -image);
}

std::ostream& operator<<(std::ostream& out, const Complex& other) {
  out << other.real << " + " << other.image << "i"; 
  return out ;

}