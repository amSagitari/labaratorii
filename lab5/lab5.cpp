#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

double Integral1(double x)
{
    return x * atan(x);
}

double Integral2(double x)
{
    return 1.0 / (1.0 + sqrt(x));
}

double Integral3(double x)
{
    return 2.0 / (1.0 - 4.0 * x);
}

double Right_rectangle(double (*function)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i <= n; ++i)
    {
        double x = a + i * h;
        sum += function(x);
    }

    return sum * h;
}

double Simpson(double (*function)(double), double a, double b, int n)
{
    if (n % 2 != 0)
    {
        ++n;
    }

    double h = (b - a) / n;
    double sum_odd = 0.0;
    double sum_even = 0.0;

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum_odd += function(x);
    }

    for (int i = 2; i < n; i += 2)
    {
        double x = a + i * h;
        sum_even += function(x);
    }

    return (h / 3.0) * (function(a) + function(b) + 4.0 * sum_odd + 2.0 * sum_even);
}

double Integrate_right_rectangles(double (*function)(double), double a, double b, double eps, int &n_result)
{
    int n = 4;

    double s1 = Right_rectangle(function, a, b, n);
    n *= 2;
    double s2 = Right_rectangle(function, a, b, n);

    while (fabs(s2 - s1) >= eps)
    {
        s1 = s2;
        n *= 2;
        s2 = Right_rectangle(function, a, b, n);
    }

    n_result = n;
    return s2;
}

double Integrate_simpson(double (*function)(double), double a, double b, double eps, int &n_result)
{
    int n = 4;

    double s1 = Simpson(function, a, b, n);
    n *= 2;
    double s2 = Simpson(function, a, b, n);

    while (fabs(s2 - s1) >= eps)
    {
        s1 = s2;
        n *= 2;
        s2 = Simpson(function, a, b, n);
    }

    n_result = n;
    return s2;
}

int main()
{
    cout << "Enter desired eps.\n";
    double eps{};
    cin >> eps;

    while(!cin) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "This is not a double value. Please enter a double value. \n";
        cin >> eps;
    }

    int n_right = 0;
    int n_simpson = 0;

    double result_right_1 = Integrate_right_rectangles(Integral1, 0.0, 1.7, eps, n_right);
    double result_simpson_1 = Integrate_simpson(Integral1, 0.0, 1.7, eps, n_simpson);

    cout << "\nIntegral 1:\n";
    cout << "Right rectangles: I ≈ " << result_right_1 << ",  final n = " << n_right << endl;
    cout << "Simpson method: I ≈ " << result_simpson_1 << ", final n = " << n_simpson << endl;
    cout << "Reference value: I ≈ 1.1709955\n";

    double result_right_2 = Integrate_right_rectangles(Integral2, 0.0, 2.0, eps, n_right);
    double result_simpson_2 = Integrate_simpson(Integral2, 0.0, 2.0, eps, n_simpson);

    cout << "\nIntegral 2:\n";
    cout << "Right rectangles: I ≈ " << result_right_2 << ", final n = " << n_right << endl;
    cout << "Simpson method: I ≈ " << result_simpson_2 << ", final n = " << n_simpson << endl;
    cout << "Reference value: I ≈ 1.0656800\n";

    double result_right_3 = Integrate_right_rectangles(Integral3, -2.0, -1.2, eps, n_right);
    double result_simpson_3 = Integrate_simpson(Integral3, -2.0, -1.2, eps, n_simpson);

    cout << "\nIntegral 3:\n";
    cout << "Right rectangles: I ≈ " << result_right_3 << ", final n = " << n_right << endl;
    cout << "Simpson method: I ≈ " << result_simpson_3 << ", final n = " << n_simpson << endl;
    cout << "Reference value: I ≈ 0.2196833\n";

    return 0;
}