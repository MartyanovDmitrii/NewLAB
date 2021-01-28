#pragma warning(disable :4244 )
#pragma warning(disable :4305 )

#include <cmath>                
#include <iostream>
#include <iomanip>
using namespace std;


void task1()
{
    setlocale(LC_ALL, "Rus");  //Устанавливаем русский шрифт
    int n, m;
    cout << "Задание №2" << endl;
    cout << "n = "; cin >> n; // Вводим значение n
    cout << "m = "; cin >> m; // Вводим знвчение m

    cout << "1)" << "n---m = " << n-- - m << "  n = " << n << "  m = " << m << endl
    << "2)" << "m--<n = " << (m-- < n ? "true" : "false") << "  n = " << n << "  m = " << m << endl
    << "3)" << "n++>m = " << (n++ > m ? "true" : "false") << "  n = " << n << "  m = " << m << endl;


}
int main()
{
    setlocale(LC_ALL, "Rus");  //Устанавливаем русский шрифт
    cout << "Задание №1 " << endl;  
    double a = 1000, b = 0.0001;
    float a1 = 1000, b1 = 0.0001;
    //Промежуточные переменные
    double x, y, z, c, d, res;
    float x1, y1, z1, c1, d1, res1;
    //Вычисление double
    x = pow((a + b), 3);
    y = pow(a, 3);
    z = 3 * pow(a, 2) * b;
    c = 3 * a * pow(b, 2);
    d = pow(b, 3);
    res = (x - (y + z)) / (c + d);
    cout << "Результат double: " << res << endl;
    //Вычисление float
    x1 = pow((a1 + b1), 3);
    y1 = pow(a1, 3);
    z1 = 3 * pow(a1, 2) * b1;
    c1 = 3 * a1 * pow(b1, 2);
    d1 = pow(b1, 3);
    res1 = (x1 - (y1 + z1)) / (c1 + d1);
    cout << "Результат float: " << res1 << endl << "\n";



    task1();
    getchar();
    cout << '\n' << endl;

    return 0;
}

