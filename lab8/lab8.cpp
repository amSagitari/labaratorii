#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool Is_separator(char symbol)
{
    const string separators = " ,.!?;:-'()\[]{}";

    for (char sep : separators)
    {
        if (symbol == sep)
        {
            return true;
        }
    }

    return false;
}

bool Is_digit_string(const string &word)
{
    if (word.empty())
    {
        return false;
    }

    for (char ch : word)
    {
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }

    return true;
}

bool Is_armstrong(const string &word)
{
    if (!Is_digit_string(word))
    {
        return false;
    }

    int n = word.size();

    long long number = 0;
    for (char ch : word)
    {
        int digit = ch - '0';
        number = number * 10 + digit;
    }

    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        int digit = word[i] - '0';
        sum += static_cast<long long>(pow(digit, n));
    }

    return sum == number;
}

string Find_armstrong_words(const string &line)
{
    string result{};
    string current_word{};

    for (int i = 0; i < line.size(); ++i)
    {
        char symbol = line[i];

        if (Is_separator(symbol))
        {
            if (!current_word.empty())
            {
                if (Is_armstrong(current_word))
                {
                    if (!result.empty())
                    {
                        result += ' ';
                    }
                    result += current_word;
                }
                current_word.clear();
            }
        }
        else
        {
            current_word += symbol;
        }
    }

    if (!current_word.empty())
    {
        if (Is_armstrong(current_word))
        {
            if (!result.empty())
            {
                result += ' ';
            }
            result += current_word;
        }
    }

    return result;
}

int main()
{
    string line{};

    cout << "Enter the string:\n";
    getline(cin, line);

    if (line.empty())
    {
        cout << "The string is empty.\n";
        return 0;
    }

    string result = Find_armstrong_words(line);

    if (result.empty())
    {
        cout << "There are no Armstrong numbers in the given string.\n";
    }
    else
    {
        cout << "Armstrong numbers found in the string:\n";
        cout << result << '\n';
    }

    return 0;
}