#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction a(1, 2), b(-3, 4), c(-10, -20); // разные дроби бла бла бла там последняя должна сократиться

    cout << a << b << c << "\n\n"; // должны вывестись эти дроби

    cout << a + b << '\n'; // операция сложения
    cout << a - b << '\n'; // операция вычитания
    cout << a * b << '\n'; // уножение соотв
    cout << a / b << "\n\n"; // диление

    Fraction x(1, 3), y(2, 5);

    x += y; // быстрае добавление
    x -= y; // вычитание
    x *= y; // умножение
    x /= y; // деление

    cout << x << "\n\n"; // результат после всех всех операций

    Fraction n(3, 2);

    cout << n << "\n"; // n= типа
    cout << ++n << "\n"; // префиксное инкрементирование
    cout << n++ << " after " << n << '\n'; // постфиксное соотв
    cout << --n << '\n'; // префиксное декрементирование
    cout << n-- << " after " << n << "\n\n"; // постфикснае соотв

    Fraction z(6, 7);

    cout << z << -z << !z << '\n'; // проста дробь, потом противоположная ее, потом обратная

    double converted = z.to_double(); // переводим дробь в десятичную
    cout << converted << "\n\n"; // выводим

    Fraction f1(1, 2), f2(2, 4);

    cout << (f1 == f2) << '\n'; // да
    cout << (f1 < b) << '\n'; // нет
    cout << (f1 > b) << "\n\n"; // не

    Fraction user;

    cin >> user; // пользаватель вводит
    cout << user << "\n"; // и программа выводит

    return 0; // фсьо
}