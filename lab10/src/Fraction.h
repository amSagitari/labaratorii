#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction
{
private:
    unsigned int denominator = 1;
    int numerator = 0;

    void Reduction();
    static unsigned int Gcd(unsigned int a, unsigned int b);

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction&);
    Fraction(Fraction&&) noexcept;
    ~Fraction();

    int get_denom() const;
    int get_num() const;

    double to_double() const;

    Fraction& operator=(const Fraction&);
    Fraction& operator=(Fraction&&);

    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    Fraction operator-() const;

    Fraction operator!() const;

    friend Fraction operator+(Fraction f1, const Fraction& f2);
    friend Fraction operator-(Fraction f1, const Fraction& f2);
    friend Fraction operator*(Fraction f1, const Fraction& f2);
    friend Fraction operator/(Fraction f1, const Fraction& f2);

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};