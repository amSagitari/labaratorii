#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

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

template <typename T>
void Fill_array(vector<T> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        cin >> arr[i];
        Check(arr[i]);
    }
}

template <typename T>
void Fill_array_random(vector<T> &arr)
{
    int a{};
    int b{};

    cout << "Enter the borders of the Mersenne's Twister distribution. \n";
    cin >> a;
    Check(a);
    cin >> b;
    Check(b);

    if (a > b)
    {
        swap(a, b);
    }

    random_device rd;
    mt19937 gen(rd());
    if (is_integral<T>())
    {
        uniform_int_distribution<int> dist(a, b);
        for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = dist(gen);
    }
    }
    else
    {
        uniform_real_distribution<double> dist(a, b);
        for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = dist(gen);
    }
    }
}

template <typename T>
void Write_array(const vector<T> &arr, const string &filename)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        throw runtime_error("couldn't open the file " + filename);
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        fout << arr[i] << ' ';
    }
    fout << '\n';
}

template <typename T>
void Read_array(vector<T> &arr)
{
    cout << "Your array is: ";

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

template <typename T>
int Binary_search(const vector<T> &arr, T pivot)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == pivot)
        {
            return mid;
        }

        if (arr[mid] < pivot)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void hz_kak_nazvat_function(const vector<T> &arr, ostream &fout)
{
    T value{};
    cout << "Now enter the value you're searching for. \n";
    cin >> value;
    Check(value);

    int index = Binary_search(arr, value);

    if (index != -1)
    {
        fout << "Entered value was found on the position " << index << " in your array.";
    }
    else
    {
        fout << "Entered value doesn't exist in entered array.";
    }

    fout << '\n';
}

void Option_one()
{
    ofstream fout("output_lab6.txt");
    if (!fout.is_open())
    {
        throw runtime_error("couldn't open the file output_lab6.txt");
    }

    int option{};

    cout << "Please choose the type of an array:\n"
         << "[1] - integer.\n"
         << "[2] - double.\n"
         << "[3] - string based.\n";
    cin >> option;
    Check(option);

    int size{};
    cout << "Now enter the size of an array.\n";
    cin >> size;
    Check(size);

    if (size < 0) 
    {
      throw runtime_error("Size can't be negative");
    }

    switch (option)
    {
    case 1:
    {
        vector<int> arr(size);

        Fill_array(arr);
        sort(arr.begin(), arr.end());
        
        Write_array(arr, "input_lab6.txt");
        Read_array(arr);
        hz_kak_nazvat_function(arr, fout);

        break;
    }
    case 2:
    {
        vector<double> arr(size);

        Fill_array(arr);
        sort(arr.begin(), arr.end());

        Write_array(arr, "input_lab6.txt");
        Read_array(arr);
        hz_kak_nazvat_function(arr, fout);

        break;
    }
    case 3:
    {
        vector<string> arr(size);

        Fill_array(arr);
        sort(arr.begin(), arr.end());

        Write_array(arr, "input_lab6.txt");
        Read_array(arr);
        hz_kak_nazvat_function(arr, fout);

        break;
    }
    default:
        throw runtime_error("such option doesn't exist");
    }
}

void Option_two()
{
    ofstream fout("output_lab6.txt");
    if (!fout.is_open())
    {
        throw runtime_error("couldn't open the file output_lab6.txt");
    }

    int option{};
    cout << "Please choose the type of an array:\n"
         << "[1] - integer.\n"
         << "[2] - double.\n";
    cin >> option;
    Check(option);

    int size{};
    cout << "Now enter the size of an array.\n";
    cin >> size;
    Check(size);

    if (size < 0) 
    {
      throw runtime_error("Size can't be negative");
    }

    switch (option)
    {
    case 1:
    {
        vector<int> arr(size);

        Fill_array_random(arr);
        sort(arr.begin(), arr.end());

        Write_array(arr, "input_lab6.txt");
        Read_array(arr);
        hz_kak_nazvat_function(arr, fout);

        break;
    }
    case 2:
    {
        vector<double> arr(size);
        
        Fill_array_random(arr);
        sort(arr.begin(), arr.end());

        Write_array(arr, "input_lab6.txt");
        Read_array(arr);
        hz_kak_nazvat_function(arr, fout);

        break;
    }
    default:
        throw runtime_error("such option doesn't exist");
    }
}

void Option_three()
{
    ifstream fin("input_lab6.txt");
    if (!fin.is_open())
    {
        throw runtime_error("couldn't open the file input_lab6.txt");
    }
    if (fin.peek() == EOF)
    {
        throw runtime_error("the file input_lab6.txt empty.");
    }

    int option{};
    cout << "Please choose the type of an array:\n"
         << "[1] - integer.\n"
         << "[2] - double.\n"
         << "[3] - string based.\n";

    cin >> option;
    Check(option);

    switch (option)
    {
    case 1:
    {
        vector<int> arr;
        int value{};
        while (fin >> value)
        {
            arr.push_back(value);
        }

        if (arr.empty())
        {
            throw runtime_error("the file input_lab6.txt doesn't contain values of the chosen type.");
        }

        sort(arr.begin(), arr.end());

        Read_array(arr);
        hz_kak_nazvat_function(arr, cout);

        break;
    }
    case 2:
    {
        vector<double> arr;
        double value{};
        while (fin >> value)
        {
            arr.push_back(value);
        }

        if (arr.empty())
        {
            throw runtime_error("the file input_lab6.txt doesn't contain values of the chosen type.");
        }

        sort(arr.begin(), arr.end());

        Read_array(arr);
        hz_kak_nazvat_function(arr, cout);

        break;
    }
    case 3:
    {
        vector<string> arr;
        string value{};
        while (fin >> value)
        {
            arr.push_back(value);
        }

        if (arr.empty())
        {
            throw runtime_error("the file input_lab6.txt doesn't contain values of the chosen type.");
        }

        sort(arr.begin(), arr.end());

        Read_array(arr);
        hz_kak_nazvat_function(arr, cout);

        break;
    }
    default:
        throw runtime_error("such option doesn't exist");
    }
}

int main()
{
    int status{};

    cout << "Please select a method of getting the data: \n"
         << "[1] - read from console. Save input in input_lab6.txt. Save result in output_lab6.txt.\n"
         << "[2] - generate using Mersenne's Twister. Save input in input_lab6.txt. Save result in output_lab6.txt.\n"
         << "[3] - read from input_lab6.txt. Output in console.\n";

    cin >> status;
    Check(status);

    if (status < 0) 
    {
      cout << "Chosen option can't be negative.";
      return 0;
    }

    switch (status)
    {
    case 1:
        Option_one();
        break;
    case 2:
        Option_two();
        break;
    case 3:
        Option_three();
        break;
    default:
        throw runtime_error("such option doesn't exist");
    }

    return 0;
}