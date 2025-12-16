#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void Check(T &a)
{
    while (!cin)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "You've entered a string with an improper data type. Please enter a string of the correct data type. \n";
        cin >> a;
    }
}

long long Addition(long long number)
{
    long long initial = number;

    if (number == 0)
    {
        return 0;
    }

    int bestDigit = 0;
    int bestFreq = -1;

    for (int d = 0; d <= 9; ++d)
    {
        int frequency = 0;

        for (long long i = number; i > 0; i /= 10)
        {
            if (i % 10 == d)
            {
                ++frequency;
            }
        }

        if (frequency > bestFreq || (frequency == bestFreq && d > bestDigit))
        {
            bestFreq = frequency;
            bestDigit = d;
        }
    }

    int power{};
    for (long long i = number; i > 0; i /= 10)
    {
        ++power;
    }

    return initial * 10 + bestDigit + bestDigit * pow(10, power + 1);
}

long long Find_divisors(long long number)
{
    long long sum{0};

    for (int i = 1; i <= 0.5 * number; ++i)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

void Gregarious_numbers(long long number)
{
    long long sumFirst{};
    long long sumSecond{};
    long long lastSecond{};

    for (int first = 1; first <= number; ++first)
    {
        sumFirst = Find_divisors(first);
        sumSecond = Find_divisors(sumFirst);
        if (first == lastSecond)
        {
            continue;
        }
        if (sumSecond <= number && sumSecond == first && first != sumFirst)
        {
            cout << first << ' ' << sumFirst << " | ";
            lastSecond = sumFirst;
        }
    }
}

bool Is_sequence(long long number)
{

    int d1 = number % 10;
    number /= 10;

    while (number != 0)
    {
        int d2 = number % 10;

        if (d1 >= d2)
        {
            return false;
        }
        d1 = d2;
        number /= 10;
    }

    return true;
}

void Fractions(long long number)
{
    long long N = number - 1;

    long long a = 0;
    long long b = 1;
    long long c = 1;
    long long d = N;

    while (c <= N)
    {
        if (c != d)
        {
            cout << c << '/' << d << ' ';
        }

        long long k = (N + b) / d;
        long long p = k * c - a;
        long long q = k * d - b;

        a = c;
        b = d;
        c = p;
        d = q;
    }

    cout << endl;
}

int main()
{
    long long number{};

    cout << "Enter the number.\n";
    cin >> number;
    Check(number);

    if (number < 0)
    {
        cout << "Entered number is negative.";
        return 0;
    }

    cout << "Modified number: " << Addition(number) << '\n';
    cout << "Here are your friendly numbeers: ";
    Gregarious_numbers(number);
    cout << '\n';

    long long a{};
    long long b{};

    cout << "Now enter 2 numbers as borders of a series: \n";
    cin >> a >> b;
    Check(a);
    Check(b);

    if (a < 0 || b < 0)
    {
        cout << "Entered value(s) is(are) negative.";
        return 0;
    }

    long long temp = min(a, b);
    b = max(a, b);
    a = temp;

    cout << "Here are the 'sequential' numbers between a and b: ";

    for (long long i = a; i <= b; ++i)
    {
        if (Is_sequence(i) == true)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';

    long long denominator{1};

    cout << "Enter the upper bound for denominators.\n";
    cin >> denominator;

    while (!cin)
    {
        denominator = 1;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "This is not an integer. Please enter INTEGER number.\n";
        cin >> denominator;
    }

    if (denominator <= 2)
    {
        cout << "There are no possible indivisible fractions strictly between 0 and 1 with denominators less than 2. \n";
        return 0;
    }

    cout << "All possible irreducible fractions between 0 and 1 with denominators less than " << denominator << ": \n";
    Fractions(denominator);

    return 0;
}