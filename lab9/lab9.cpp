#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int Words_amount(const string &line)
{
    stringstream ss(line);
    string word{};
    int amount = 0;

    while (ss >> word) 
    {
        ++amount;
    }

    return amount;
}

bool Reading(const string &file, vector<string> &lines)
{
    ifstream fin(file);

    if (!fin.is_open())
    {
        cerr << "couldn't open the file.\n";
        return false;
    }

    string line{};

    while (getline(fin, line))
    {
        lines.push_back(line);
    }

    fin.close();

    return true;
}

int Find_max_words(const vector<string> &lines)
{
    int max = 0;

    for (int i = 0; i < lines.size(); ++i)
    {
        int current = Words_amount(lines[i]);

        if (current > max)
        {
            max = current;
        }
    }

    return max;
}

void Find_max_lines(const vector<string> &lines, int max, vector<int> &maxLines)
{
    for (int i = 0; i < lines.size() && maxLines.size() < 10; ++i)
    {
        int current = Words_amount(lines[i]);

        if (current == max)
        {
            maxLines.push_back(i);
        }
    }
}

void Cout_result(int max_words, const vector<int> &maxLines, const vector<string> &lines)
{
    cout << "Maximum number of words in a line: " << max_words << "\n";
    cout << "First " << maxLines.size() << " lines containing this number of words:\n\n";

    for (int i = 0; i < maxLines.size(); ++i)
    {
        int index = maxLines[i];

        cout << "Line " << (index + 1) << ":\n";
        cout << lines[index] << "\n";
    }
}

int main()
{
    const string file = "epstein_files.txt";
    vector<string> lines{};

    if (!Reading(file, lines))
    {
        return -1;
    }

    if (lines.empty())
    {
        cout << "File " << file << " is empty.\n";
        return 0;
    }

    int max_words = Find_max_words(lines);

    vector<int> maxLines{};

    Find_max_lines(lines, max_words, maxLines);
    Cout_result(max_words, maxLines, lines);

    return 0;
}