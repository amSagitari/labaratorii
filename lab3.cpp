#include <iostream>
#include <random>
#include <cmath>
#include <windows.h>
using namespace std;

void Manual(double *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    return;
}

void Srand(double *arr, int size)
{
    srand(time(0));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = -100000.0 + (double)rand() / RAND_MAX * 200000.0;
    }
    return;
}

int GetStatus()
{
    int x{};
    cout <<  "\033[32m" << "Enter the method of loading the array." << endl
         << "[1] - Manually" << endl
         << "[2] - Using Srand" << endl
         << "[3] - Using mt19937" <<  "\033[0m" << endl << endl;
    cin >> x;
    cout << endl;

    if (x > 3 || x < 1)
    {
        return 0;
    }
    return x;
}

void Random2(double *arr, int size)
{
    double a, b, temp;

    cout << "\033[32m" << "Enter the borders of distribution." << "\033[32m" << endl;
    cin >> a >> b;

    temp = max(a, b);
    a = min(a, b);
    b = temp;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < size; i++)
    {
        arr[i] = dist(gen);
    }
}

void SortArray(double *arr, int size, double x)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (abs(arr[j]) > x && abs(arr[j + 1]) <= x)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return;
}

void TaskExecution(double *arr, int size, double x)
{
    int minIndex{};
    int firstNegative{-1};
    int lastNegative{-1};
    double sum{}; 
    double min = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] <= min)
        {
            minIndex = i;
            min = arr[i];
        }
    }

    cout << "\033[32m" << "The minimum element is located at number " << minIndex+1 << '.' << endl << endl;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            firstNegative = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; --i)
    {
        if (arr[i] < 0)
        {
            lastNegative = i;
            break;
        }
    }

    for (int i = firstNegative; i < lastNegative; ++i)
    {
        sum += arr[i];
    }

    if (firstNegative != -1)
    {
        cout << "The sum from first negative element to the last equals: " << "\033[0m" << sum << '.' << "\033[32m" << endl << endl;
    }
    else
    {
        cout << "The array doesn't have any negative numbers." << endl << endl;
    }

    SortArray(arr, size, x);

    cout << "Here's your sorted array with a respect to x: " <<  "\033[0m";

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return;
}

int main()
{
    double array[100];
    int size{};

    cout << "\033[32m" << "Enter the size of an array(between 1 and 100)." << "\033[0m" << endl << endl;
    cin >> size;
    cout << endl;

    if (size < 1 || size > 100)
    {
        cout << "\033[32m" << "Out of range." << "\033[0m";
        return 0;
    }

    switch (int status = GetStatus(); status)
    {
    case 1:
        cout << "\033[32m" << "Enter the elements" << "\033[0m" << endl << endl;
        Manual(array, size);
        break;

    case 2:
        Srand(array, size);
        break;

    case 3:
        Random2(array, size);
        break;

    default:
        cout << "\033[32m" << "Unknown method" << "\033[0m";
        return 0;
    }

    cout << "\033[32m" << "Here's your array: " << "\033[0m";

    for (int i{}; i < size; ++i)
    {
        cout << array[i] << ' ';
    }
    cout << endl << endl;

    cout << "\033[32m" << "Proceed to task execution?" << endl
         << "[1] - Yes" << endl
         << "[2] - No" << endl << endl << "\033[0m";

    int option{};

    cin >> option;
    cout << endl;

    switch (option)
    {

    case 1:
    {
        int x{};
        cout << "\033[32m" << "Enter x" << "\033[0m" << endl << endl;
        cin >> x;
        cout << endl;
        TaskExecution(array, size, x);
        break;
    }

    default:
        cout << "\033[32m" << "Unknown option." <<  "\033[0m";
        return 0;
    }

    cout << endl << "\033[32m" <<  "Executed succesfully." << "\033[0m" << endl;
    return 0;
}