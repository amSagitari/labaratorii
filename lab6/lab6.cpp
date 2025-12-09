#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int Option_one()
{
    ifstream fin("input_lab6.txt");

    if (!fin.is_open())
    {
        cerr << "couldn't open/find the file!\n";
        return -1;
    }

    ofstream fout("output_lab6.txt");
    string str{};

    getline(fin, str);
    stringstream line(str);

    return 0;
}

void Option_two()
{
}

void Option_three()
{
}

bool Is_option(string number)
{
    if (number.empty())
    {
        cout << "You entered nothing.\n";
        cout << "Please enter a valid option.\n";
        return false;
    }

    int position = 0;

    if (number[0] == '+')
    {
        if (number.size() == 1)
        {
            cout << "This is not an option.\n";
            cout << "Please enter a valid option.\n";
            return false;
        }
        position = 1;
    }

    if (number[position] != '1' || number[position] != '2' || number[position] != '3')
    {
        cout << "This is not an option.\n";
        cout << "Please enter a valid option.\n";
        return false;
    }

    while (position < number.size() || number[position] != '1' || number[position] != '2' || number[position] != '3')
    {
        if (isalpha(static_cast<unsigned char>(number[position])))
        {
            cout << "This is not an option.\n";
            cout << "Please enter a valid option.\n";
            return false;
        }
        ++position;
    }
    ++position;

    for (; position < number.size(); ++position)
    {
        if (!isspace(static_cast<unsigned char>(number[position])))
        {
            cout << "This is not an option.\n";
            cout << "Please enter a valid option.\n";
            return false;
        }
    }

    return true;
}

int main()
{
    string status_s{};

    cout << "Please select a method of getting the data: \n"
         << "[1] - read from external file. Write in external file.\n"
         << "[2] - generate using Mersenne's Twister. Write in external file.\n"
         << "[3] - read from external file. Write in console.\n";

    while (!Is_option)
    {
        getline(cin, status_s);
    }

    int status = stoi(status_s);

    switch (status)
    {
    case 1:
        Option_one();
    case 2:
        Option_two();
    case 3:
        Option_three();
    default:
        cout << "such option doesn't exist. \n";
    }

    return 0;
}