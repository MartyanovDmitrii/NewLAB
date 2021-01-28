#include <iostream>
#include <cmath>

using namespace std;


double fact(int z)

{
	float res = 1;
	for (double i = 1; i <= z; i++)
	{
		res *= i;
	}
	/*cout << "fac = " << res << " z = " << z << endl;*/
	return res;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double y;
	cout << "а) Для заданного n: " << endl;
	for (double x = 0.1; x <= 1; x += 0.1)
	{

		y = sin(x);

		cout << "sin(" << x << ") = " << y << " ";

		//ряд

		//a
		{
			int n = 10;

			double S = 0;

			for (int i = 0; i < n; ++i)
			{
				S += pow(-1, i) * (pow(x, (2 * i) + 1) / fact(2 * i + 1));
				//cout << "S = " << S << endl;
			}
			cout << "x = " << x << "  y(x) = " << S << endl;
		}
	}

	//b
	cout << "\n" << "b) для заданной точности eps: " << endl;
	for (double x = 0.1; x <= 1; x += 0.1)
	{

		{
			double eps = 0.0001;

			double S = 0;
			double sum = 0;
			int n = 0;

			do
			{
				sum = pow(-1, n) * (pow(x, (2 * n) + 1) / fact(2 * n + 1));
				n++;

				/*cout << "sum = " << sum << endl;*/

				S += sum;

			} while (abs(sum) >= eps); //вычисляем до тех пор, пока член ряда не станет меньше эпсилон

			cout << "S = " << S << "; n=" << n << endl;
		}
		setlocale(LC_ALL, "ru");
	}
}