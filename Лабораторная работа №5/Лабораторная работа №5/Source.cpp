#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t n = 4;

void fun(int[n][n], int[n][n]);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int A[n][n];
    int B[n][n];
    cout << "Исходная матрица: \n\n";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            A[i][j] = rand() % 9;
            cout << A[i][j] << "\t";
        }
        cout << "\n\n";
    }
    cout << "Транспонированная матрица: \n\n";
    for (size_t j = 0; j < n; j++) {
        for (size_t i = 0; i < n; i++) {
            B[i][j] = A[i][j];
            cout << B[i][j] << "\t";
        }
        cout << "\n\n";
    }
    fun(A, B);
    return 0;
}
void fun(int a[n][n], int b[n][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << a[i][j] + b[i][j] << "\t";
        }
        cout << "\n\n";
    }
}