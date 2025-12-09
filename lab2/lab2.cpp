#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

long long Addition(long long number)
{

    long long edited = number;

    int power{};
    vector<int> frequency = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (number != 0)
    {

        int r = number % 10;
        number /= 10;

        ++frequency[r];
        ++power;
    }

    int index{};
    int maximum = frequency[0];

    for (int i = 0; i < 10; ++i)
    {
        if (frequency[i + 1] >= maximum)
        {
            index = i + 1;
            maximum = frequency[i + 1];
        }
    }

    edited = edited * 10 + index + index * pow(10, power + 1);

    return edited;
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

    string number_s = to_string(number);
    size_t size = number_s.size();
    vector<int> digits(size);
    int digit{};

    for (int i = 0; i < size; ++i)
    {
        digit = number % 10;
        number /= 10;
        digits[i] = digit;
    }

    for (int i = size; i > 0; --i)
    {
        if (digits[i] >= digits[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool Is_option(string number)
{

    if (number.empty())
    {
        cout << "You haven't entered anything.\n";
        cout << "Enter the number.\n";
        return false;
    }

    int position{};
    while (!isalnum(number[position]))
    {
        ++position;
        if (position > number.size())
        {
            break;
        }
    }
    position = 0;

    for (position; position < number.size(); ++position)
    {
        if (!isdigit(number[position]))
        {
            cout << "This is not an integer.\n";
            cout << "Enter the number.\n";
            return false;
        }
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
        long long e = k * c - a;
        long long f = k * d - b;

        a = c;
        b = d;
        c = e;
        d = f;
    }

    cout << endl;
}

int main()
{
    string number_s{};

    cout << "Enter the number.\n";
    cin >> number_s;

    while (Is_option(number_s) == false)
    {
        getline(cin, number_s);
    }

    long long number = stoll(number_s);

    cout << "Modified number: " << Addition(number) << '\n';
    cout << "Here are your friendly numbeers: ";
    Gregarious_numbers(number);
    cout << endl;

    int a{};
    int b{};

    cout << "Now enter 2 numbers as borders of a series: \n";
    cin >> a >> b;
    cout << "Here are the 'sequential' numbers between a and b: ";

    for (int i = a; i <= b; ++i)
    {
        if (Is_sequence(i) == true)
        {
            cout << i << ' ';
        }
    }
    cout << endl;

    cout << "Enter the upper bound for denominators.\n";
    cin >> number_s;

    while (Is_option(number_s) == false)
    {
        getline(cin, number_s);
    }

    long long denominator = stoll(number_s);

    if (denominator <= 2)
    {
        cout << "There are no possible indivisible fractions strictly between 0 and 1 with denominators less than 2. \n";
        return 0;
    }

    cout << "All possible irreducible fractions between 0 and 1 with denominators less than " << denominator << ": \n";
    Fractions(denominator);

    return 0;
}