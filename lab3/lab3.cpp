#include <iostream>
#include <random>
#include <vector>
#include <windows.h>
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

int GetSize(const int maxSize)
{
    int size{};
    cin >> size;
    Check(size);

    while (size < 1 || size > maxSize)
    {
        cout << "\033[32m" << "The number is out of bounds. Enter the size in range [1.." << maxSize << "].\n"
             << "\033[0m";
        cin >> size;
        Check(size);
    }

    return size;
}

void Manual_arr(double *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
        Check(arr[i]);
    }
    return;
}

void Manual_vec(vector<double> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cin >> vec[i];
        Check(vec[i]);
    }
    return;
}

void Srand_arr(double *arr, int size)
{
    srand((unsigned)time(0));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = -100000.0 + (double)rand() / RAND_MAX * 200000.0;
    }
    return;
}

void Srand_vec(vector<double> &vec)
{
    srand((unsigned)time(0));
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = -100000.0 + (double)rand() / RAND_MAX * 200000.0;
    }
    return;
}

int GetStatus()
{
    int status{};
    cin >> status;
    Check(status);

    return status;
}

void MT_arr(double *arr, int size)
{
    double a{}, b{};

    cout << "\033[32m" << "Enter the borders of distribution.\n"
         << "\033[0m";
    cin >> a >> b;
    Check(a);
    Check(b);

    double temp = max(a, b);
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

void MT_vec(vector<double> &vec)
{
    double a{}, b{};

    cout << "\033[32m" << "Enter the borders of distribution.\n"
         << "\033[0m";
    cin >> a >> b;
    Check(a);
    Check(b);

    double temp = max(a, b);
    a = min(a, b);
    b = temp;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = dist(gen);
    }
}

void Sorting_arr(double *arr, int size, double x)
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

    cout << "Here's your sorted array with a respect to x: " << "\033[0m";

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return;
}

void Sorting_vec(vector<double> &vec, double x)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size() - i - 1; ++j)
        {
            if (abs(vec[j]) > x && abs(vec[j + 1]) <= x)
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }

    cout << "Here's your sorted array with a respect to x: " << "\033[0m";

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << '\n';

    return;
}

void Find_minimum_arr(const double *arr, int size)
{
    int minIndex{};
    double minElem = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] <= minElem)
        {
            minIndex = i;
            minElem = arr[i];
        }
    }

    cout << "\033[32m" << "The minimum element is located at number " << minIndex + 1 << '.' << "\n\n";
}

void Find_minimum_vect(const vector<double> &vec)
{
    int minIndex{};
    double minElem = vec[0];

    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] <= minElem)
        {
            minIndex = i;
            minElem = vec[i];
        }
    }

    cout << "\033[32m" << "The minimum element is located at number " << minIndex + 1 << '.' << "\n\n";
}

void Summation_arr(const double *arr, int size)
{
    int firstNegative{-1};
    int lastNegative{-1};

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

    if (firstNegative == -1)
    {
        cout << "The array doesn't have any negative numbers.\n\n";
        return;
    }

    if (firstNegative == lastNegative)
    {
        cout << "You have only one negative number.\n\n";
        return;
    }

    if (lastNegative - firstNegative == 1)
    {
        cout << "There are no elements between the first and the last negative numbers.\n\n";
        return;
    }

    double sum{};

    for (int i = firstNegative + 1; i < lastNegative; ++i)
    {
        sum += arr[i];
    }

    cout << "The sum of elements between the first and the last negative numbers equals: " << "\033[0m" << sum << ".\n\n"
         << "\033[32m";
}

void Summation_vec(const vector<double> &vec)
{
    int firstNegative{-1};
    int lastNegative{-1};

    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < 0)
        {
            firstNegative = i;
            break;
        }
    }

    for (int i = (int)vec.size() - 1; i >= 0; --i)
    {
        if (vec[i] < 0)
        {
            lastNegative = i;
            break;
        }
    }

    if (firstNegative == -1)
    {
        cout << "The array doesn't have any negative numbers.\n\n";
        return;
    }

    if (firstNegative == lastNegative)
    {
        cout << "You have only one negative number.\n\n";
        return;
    }

    if (lastNegative - firstNegative == 1)
    {
        cout << "There are no elements between the first and the last negative numbers.\n\n";
        return;
    }

    double sum{};

    for (int i = firstNegative + 1; i < lastNegative; ++i)
    {
        sum += vec[i];
    }

    cout << "The sum of elements between the first and the last negative numbers equals: " << "\033[0m" << sum << ".\n\n"
         << "\033[32m";
}

void Print_arr(const double *arr, int size)
{
    cout << "\033[32m" << "Here's your array: " << "\033[0m";

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n\n";
}

void Print_vec(const vector<double> &vec)
{
    cout << "\033[32m" << "Here's your array: " << "\033[0m";

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << "\n\n";
}

void Load_arr(double *arr, int size)
{
    cout << "\033[32m" << "Enter the method of loading the array.\n"
         << "[1] - Manually\n"
         << "[2] - Using Srand\n"
         << "[3] - Using mt19937\n"
         << "\033[0m";

    switch (int status = GetStatus(); status)
    {
    case 1:
    {
        cout << "\033[32m" << "Enter the elements of an array.\n\n"
             << "\033[0m";
        Manual_arr(arr, size);
        break;
    }
    case 2:
    {
        Srand_arr(arr, size);
        break;
    }
    case 3:
    {
        MT_arr(arr, size);
        break;
    }
    default:
        throw runtime_error("unknown method");
    }
}

void Load_vec(vector<double> &vec)
{
    cout << "\033[32m" << "Enter the method of loading the array.\n"
         << "[1] - Manually\n"
         << "[2] - Using Srand\n"
         << "[3] - Using mt19937\n"
         << "\033[0m";

    switch (int status = GetStatus(); status)
    {
    case 1:
    {
        cout << "\033[32m" << "Enter the elements of an array.\n\n"
             << "\033[0m";
        Manual_vec(vec);
        break;
    }
    case 2:
    {
        Srand_vec(vec);
        break;
    }
    case 3:
    {
        MT_vec(vec);
        break;
    }
    default:
        throw runtime_error("unknown method");
    }
}

void TaskExecution_arr(double *arr, int size, double x)
{
    Find_minimum_arr(arr, size);
    Summation_arr(arr, size);
    Sorting_arr(arr, size, x);
}

void TaskExecution_vec(vector<double> &vec, double x)
{
    Find_minimum_vect(vec);
    Summation_vec(vec);
    Sorting_vec(vec, x);
}

void Proceed_arr(double *arr, int size)
{
    cout << "\033[32m" << "Proceed to task execution?\n"
         << "[1] - Yes.\n"
         << "[2] - No.\n\n"
         << "\033[0m";

    switch (int status = GetStatus(); status)
    {
    case 1:
    {
        double x{};

        cout << "\033[32m" << "Enter x.\n\n"
             << "\033[0m";
        cin >> x;
        Check(x);
        cout << '\n';

        TaskExecution_arr(arr, size, x);
        break;
    }

    case 2:
    {
        throw runtime_error("You cancelled the task's execution.");
    }

    default:
        throw runtime_error("unknown option.");
    }
}

void Proceed_vec(vector<double> &vec)
{
    cout << "\033[32m" << "Proceed to task execution?\n"
         << "[1] - Yes.\n"
         << "[2] - No.\n\n"
         << "\033[0m";

    switch (int status = GetStatus(); status)
    {
    case 1:
    {
        double x{};

        cout << "\033[32m" << "Enter x.\n\n"
             << "\033[0m";
        cin >> x;
        Check(x);
        cout << '\n';

        TaskExecution_vec(vec, x);
        break;
    }

    case 2:
    {
        throw runtime_error("You cancelled the task's execution.");
    }

    default:
        throw runtime_error("unknown option.");
    }
}

int main()
{
    cout << "\033[32m" << "Choose the type of an array:\n"
         << "[1] - static array with a capacity of 100.\n"
         << "[2] - dynamic array.\n"
         << "[3] - std::vector.\n"
         << "\033[0m" << '\n';

    switch (int status = GetStatus(); status)
    {
    case 1:
    {
        double array[100];
        int size{};

        cout << "\033[32m" << "Enter the real size of an array(less than 100).\n"
             << "\033[0m";
        cin >> size;
        Check(size);
        cout << '\n';

        if (size > 100 || size < 1)
        {
            cout << "Out of range.";
            return 0;
        }

        Load_arr(array, size);
        Print_arr(array, size);
        Proceed_arr(array, size);

        break;
    }
    case 2:
    {
        int size{};

        cout << "\033[32m" << "Enter the size of an array in range.\n"
             << "\033[0m";
        cin >> size;
        Check(size);

        cout << '\n';

        if (size < 1)
        {
            cout << "Out of range.";
            return 0;
        }

        double *array = new double[size];

        Load_arr(array, size);
        Print_arr(array, size);
        Proceed_arr(array, size);

        delete[] array;

        break;
    }
    case 3:
    {
        int size{};

        cout << "\033[32m" << "Enter the size of an array in range.\n"
             << "\033[0m";
        cin >> size;
        Check(size);
        cout << '\n';

        if (size < 1)
        {
            cout << "Out of range.";
            return 0;
        }

        vector<double> array(size);

        Load_vec(array);
        Print_vec(array);
        Proceed_vec(array);

        break;
    }
    default:
        throw runtime_error("unknown option.");
    }

    cout << "\033[32m" << "Executed succesfully." << "\033[0m";

    return 0;
}
