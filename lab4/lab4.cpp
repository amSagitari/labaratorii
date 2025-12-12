#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

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
            cin >> matrix[i][j];
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
    int rows{};
    cout << "Enter the number of rows of the matrix.\n";
    cin >> rows;

    while (!cin)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "This is not an integer. Please enter INTEGER number. \n";
        cin >> rows;
    }

    int cols{};
    cout << "Now the number of columns of the matrix.\n";
    cin >> cols;

    while (!cin)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "This is not an integer. Please enter INTEGER number. \n";
        cin >> cols;
    }

    if (rows <= 0 || cols <= 0)
    {
        cout << "Matrix sizes must be positive. \n";
        return 0;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Choose how to fill the matrix:\n";
    cout << "1 - input from keyboard\n";
    cout << "2 - fill with random numbers\n";

    int choice{};
    cin >> choice;

    while (choice != 1 && choice != 2)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "This is not a viable option. \n";
        cin >> choice;
    }

    if (choice == 1)
    {
        Fill_manual(matrix);
    }
    else
    {
        cout << "Enter the left bound of the interval.\n";
        int a{};
        cin >> a;
        while (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "This is not an integer. Please enter INTEGER number. \n";
            cin >> a;
        }

        cout << "Enter the right bound of the interval.\n";

        int b{};
        while (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "This is not an integer. Please enter INTEGER number. \n";
            cin >> b;
        }

        Fill_random(matrix, a, b);
    }

    cout << "\nHere's your matrix:\n";
    Cout_matrix(matrix);

    long long sum = Sum_columns(matrix);

    cout << "\nSum of elements in columns that contain at least one zero: " << sum << '\n';

    Sorting(matrix);

    cout << "\nMatrix after sorting the rows\n";
    Cout_matrix(matrix);

    return 0;
}
