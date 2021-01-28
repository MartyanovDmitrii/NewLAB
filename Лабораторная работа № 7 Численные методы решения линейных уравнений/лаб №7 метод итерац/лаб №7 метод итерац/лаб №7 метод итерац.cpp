#include <conio.h>
#include <cmath>
#include <iostream>

using namespace std;

double f(double x) {
    double f;
    f = 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
    return f;
}

double fi(double x, double L) {
    double fi;
    fi = x + L * f(x);
    return fi;
}


int main() {
    setlocale(LC_ALL, "rus");
    int n = 0;
    double x, y, b, L = -0.35, eps = 2.2985;

    cout << "Введите число x в интервале от 2 до 3 :" << endl;
    cout << "x="; cin >> x;
    cout << "eps=" << eps << endl;
    do {
        y = fi(x, L);
        b = fabs(x - y);
        x = y;
        n++;
    } while (b >= eps);

    cout << "Корень уравнения x=" << x << "\n";
    cout << "Количество итерации n=" << n << "\n";
    _getch();
    return 0;
}
