#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Is_separator(char symbol, const string& separators)
{
    for (char sep : separators)
    {
        if (symbol == sep)
        {
            return true;
        }
    }
    return false;
}

bool Is_palindrome(const string& word)
{
    if (word.empty())
    {
        return false;
    }

    int left = 0;
    int right = word.size() - 1;

    while (left < right)
    {
        if (word[left] != word[right])
        {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

string Find_longest(const string& line, const string& separators)
{
    vector<string> longest_palindromes;
    int max_length = 0;

    int i = 0;
    while (i < line.size())
    {
        while (i < line.size() && Is_separator(line[i], separators))
        {
            ++i;
        }

        int start = i;

        while (i < line.size() && !Is_separator(line[i], separators))
        {
            ++i;
        }

        int length = i - start;
        if (length == 0)
        {
            continue;
        }

        string word = line.substr(start, length);

        if (Is_palindrome(word))
        {
            if (length > max_length)
            {
                longest_palindromes.clear();
                longest_palindromes.push_back(word);
                max_length = length;
            }
            else if (length == max_length)
            {
                longest_palindromes.push_back(word);
            }
        }
    }

    if (max_length == 0)
    {
        return "";
    }

    string result;
    for (int i = 0; i < longest_palindromes.size(); ++i)
    {
        result += longest_palindromes[i];
        if (i + 1 < longest_palindromes.size())
        {
            result += "; ";
        }
    }

    return result;
}

int main()
{
    string separators{};
    string line{};

    cout << "Enter separator characters: ";
    getline(cin, separators);

    cout << "Enter the string (length <= 300):\n";
    getline(cin, line);

    if (line.empty())
    {
        cout << "The string is empty.\n";
        return 0;
    }

    if (line.size() > 300)
    {
        cout << "The string is too long.\n";
        return 0;
    }

    string result = Find_longest(line, separators);

    if (result.empty())
    {
        cout << "There are no palindrome words in the given string.\n";
    }
    else
    {
        cout << "The longest palindrome words:\n";
        cout << result << '\n';
    }

    return 0;
}