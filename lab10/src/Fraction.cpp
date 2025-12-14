#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction() {};

Fraction::Fraction(int num, int denom)
{
    bool negative = (num < 0) ^ (denom < 0);

    unsigned int num_abs = static_cast<unsigned int>(num < 0 ? -num : num);
    unsigned int den_abs = static_cast<unsigned int>(denom < 0 ? -denom : denom);

    numerator = static_cast<int>(num_abs / Gcd(num_abs, den_abs));
    denominator = den_abs / Gcd(num_abs, den_abs);

    if (negative)
    {
        numerator = -numerator;
    }
};

Fraction::Fraction(const Fraction& other) : denominator(other.denominator), numerator(other.numerator) {};

Fraction::Fraction(Fraction&& other) : denominator(other.denominator), numerator(other.numerator)
{
    other.denominator = 1;
    other.numerator = 0;
};

Fraction::~Fraction() {};

unsigned int Fraction::Gcd(unsigned int a, unsigned int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    unsigned int max = a > b ? a : b;
    unsigned int min = a <= b ? a : b;

    while (min != 0)
    {
        unsigned int temp = max % min;
        max = min;
        min = temp;
    }
    return max;
};

void Fraction::Reduction()
{
    if (numerator == 0)
    {
        denominator = 1;
        return;
    }

    unsigned int num_abs = static_cast<unsigned int>(numerator < 0 ? -numerator : numerator);

    numerator /= static_cast<int>(Gcd(num_abs, denominator));
    denominator /= Gcd(num_abs, denominator);
};

int Fraction::get_denom() const
{
    return static_cast<int>(denominator);
};

int Fraction::get_num() const
{
    return numerator;
};

double Fraction::to_double() const
{
    return static_cast<double>(numerator) / denominator;
};

Fraction& Fraction::operator=(const Fraction& other)
{
        numerator = other.numerator;
        denominator = other.denominator;

    return *this;
};

Fraction& Fraction::operator=(Fraction&& other)
{
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;

    return *this;
};

Fraction& Fraction::operator+=(const Fraction& fract)
{
    long long newNum = static_cast<long long>(numerator) * fract.denominator + static_cast<long long>(fract.numerator) * denominator;
    long long newDen = static_cast<long long>(denominator) * fract.denominator;

    numerator = static_cast<int>(newNum);
    denominator = static_cast<unsigned int>(newDen);

    Reduction();

    return *this;
};

Fraction& Fraction::operator-=(const Fraction& fract)
{
    return *this += (-fract);
};

Fraction& Fraction::operator*=(const Fraction& fract)
{
    long long newNum = static_cast<long long>(numerator) * fract.numerator;
    long long newDen = static_cast<long long>(denominator) * fract.denominator;

    numerator = static_cast<int>(newNum);
    denominator = static_cast<unsigned int>(newDen);

    Reduction();

    return *this;
};

Fraction& Fraction::operator/=(const Fraction& fract)
{
    if (fract.numerator == 0)
    {
        throw runtime_error("Division by zero fraction is impossible.");
    }
    return *this *= (!fract);
};

Fraction operator+(Fraction f1, const Fraction& f2)
{
    f1 += f2;
    return f1;
};

Fraction operator-(Fraction f1, const Fraction& f2)
{
    f1 -= f2;
    return f1;
};

Fraction operator*(Fraction f1, const Fraction& f2)
{
    f1 *= f2;
    return f1;
};

Fraction operator/(Fraction f1, const Fraction& f2)
{
    f1 /= f2;
    return f1;
};

Fraction& Fraction::operator++()
{
    numerator += static_cast<int>(denominator);
    return *this;
};

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);
    return temp;
};

Fraction& Fraction::operator--()
{
    numerator -= static_cast<int>(denominator);
    return *this;
};

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --(*this);
    return temp;
};

Fraction Fraction::operator-() const
{
    Fraction temp(*this);
    temp.numerator = -temp.numerator;
    return temp;
};

Fraction Fraction::operator!() const
{
    if (numerator == 0)
    {
        throw runtime_error("Can't invert zero fraction.");
    }

    Fraction result;

    result.denominator = static_cast<unsigned int>(numerator > 0 ? numerator : -numerator);
    result.numerator = (numerator > 0) ? static_cast<int>(denominator) : -static_cast<int>(denominator);

    return result;
};

bool operator==(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
};

bool operator!=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 == f2);
};

bool operator<(const Fraction& f1, const Fraction& f2)
{
    long long left  = static_cast<long long>(f1.numerator) * f2.denominator;
    long long right = static_cast<long long>(f2.numerator) * f1.denominator;

    return left < right;
};

bool operator<=(const Fraction& f1, const Fraction& f2)
{
    return (f1 < f2) || (f1 == f2);
};

bool operator>(const Fraction& f1, const Fraction& f2)
{
    return f2 < f1;
};

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    return (f1 > f2) || (f1 == f2);
};

ostream& operator<<(ostream& output, const Fraction& f)
{
    output << f.numerator;
    if (f.denominator != 1)
    {
        output << '/' << f.denominator;
    }
    return output;
};

istream& operator>>(istream& input, Fraction& fract)
{
    int num = 0;
    int denom = 1;
    char ch = 0;

    if (!(input >> num))
    {
        return input;
    }

    if (input.peek() == '/')
    {
        input.get(ch);

        if (!(input >> denom))
        {
            input.setstate(ios::failbit);
            return input;
        }
    }

    fract = Fraction(num, denom);
    return input;
};