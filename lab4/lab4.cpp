#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

bool Is_option(string number)
{
    if (number.empty())
    {
        cout << "You entered nothing.\n";
        cout << "Please enter an integer number.\n";
        return false;
    }

    int position = 0;

    if (number[0] == '+' || number[0] == '-')
    {
        if (number.size() == 1)
        {
            cout << "This is not an integer number.\n";
            cout << "Please enter an integer number.\n";
            return false;
        }
        position = 1;
    }

    for (; position < (int)number.size(); ++position)
    {
        if (!isdigit(static_cast<unsigned char>(number[position])))
        {
            cout << "This is not an integer number.\n";
            cout << "Please enter an integer number.\n";
            return false;
        }
    }

    return true;
}

int Cin_function()
{
    string number_s{};
    cin >> number_s;

    while (Is_option(number_s) == false)
    {
        cin >> number_s;
    }

    return stoi(number_s);
}

void Cout_matrix(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    if (rows == 0)
    {
        return;
    }
    int columns = matrix[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int Mersenne_twister(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

void Fill_manual(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    cout << "Enter matrix elements.\n";

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = Cin_function();
        }
    }
}

void Fill_random(vector<vector<int>> &matrix, int left, int right)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = Mersenne_twister(left, right);
        }
    }
}

long long Sum_columns(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    if (rows == 0)
    {
        return 0;
    }
    int columns = matrix[0].size();

    long long sum = 0;
    bool has_zero = false;

    for (int j = 0; j < columns; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            if (matrix[i][j] == 0)
            {
                has_zero = true;
                break;
            }
        }

        if (has_zero)
        {
            for (int i = 0; i < rows; ++i)
            {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

void Sorting(vector<vector<int>> &matrix)
{
    int rows = matrix.size();

    if (rows == 0)
    {
        return;
    }

    for (int i = 0; i < rows; ++i)
    {
        if ((i + 1) % 2 == 0)
        {
            sort(matrix[i].begin(), matrix[i].end());
        }
        else
        {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
        }
    }
}

int main()
{
    cout << "Enter the number of rows of the matrix.\n";
    int rows = Cin_function();

    cout << "Now the number of columns of the matrix.\n";
    int cols = Cin_function();

    if (rows <= 0 || cols <= 0)
    {
        cout << "Matrix sizes must be positive. \n";
        return 0;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Choose how to fill the matrix:\n";
    cout << "1 - input from keyboard\n";
    cout << "2 - fill with random numbers\n";

    int choice = Cin_function();

    while (choice != 1 && choice != 2)
    {
        cout << "There is no such option.\n";
        choice = Cin_function();
    }

    if (choice == 1)
    {
        Fill_manual(matrix);
    }
    else
    {
        cout << "Enter the left bound of the interval.\n";
        int a = Cin_function();

        cout << "Enter the right bound of the interval.\n";
        int b = Cin_function();

        Fill_random(matrix, a, b);
    }

    cout << "\nHere's your matrix:\n";
    Cout_matrix(matrix);

    long long sum = Sum_columns(matrix);

    cout << "\nSum of elements in columns that contain at least one zero: " << sum << endl;

    Sorting(matrix);

    cout << "\nMatrix after sorting the rows\n";
    Cout_matrix(matrix);

    return 0;
}
