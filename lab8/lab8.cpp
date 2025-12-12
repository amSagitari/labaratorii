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

    long long number = 0;
    for (char ch : word)
    {
        int digit = ch - '0';
        number = number * 10 + digit;
    }

    long long sum = 0;

    for (int i = 0; i < word.size(); ++i)
    {
        int digit = word[i] - '0';
        sum += static_cast<long long>(pow(digit, word.size()));
    }

    return sum == number;
}

string Find_armstrong_words(const string &line)
{
    string result{};
    string current_num{};

    for (int i = 0; i < line.size(); ++i)
    {
        if (Is_separator(line[i]))
        {
            if (!current_num.empty())
            {
                if (Is_armstrong(current_num))
                {
                    if (!result.empty())
                    {
                        result += ' ';
                    }
                    result += current_num;
                }
                current_num.clear();
            }
        }
        else
        {
            current_num += line[i];
        }
    }

    if (!current_num.empty())
    {
        if (Is_armstrong(current_num))
        {
            if (!result.empty())
            {
                result += ' ';
            }
            result += current_num;
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