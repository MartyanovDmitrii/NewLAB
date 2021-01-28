#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int t = 100, k = 0;
    int* arr1 = new int[t];
    cout << " Сформируем одномерный массив целых чисел: " << endl << "\n";
    for (int i = 0; i < t; i++)
    {
        arr1[i] = rand() % 100;
        cout << arr1[i] << "  ";
    }
    cout << endl << "\n";
    cout << " Удалим все элементы равные 0: " << endl << "\n";
    for (int i = 0; i < t; i++)
    {
        if (arr1[i] != 0)
        {
            arr1[k++] = arr1[i];
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr1[i]  << "  ";
    }
    cout << endl << "\n";
    

    for (int i = 0; i < k; i++) {
        if ((arr1[i] % 2) == 0) {
            for (int j = i; j != i; j--) {
                arr1[i] = arr1[i];
                k++;
            }
            cout << " Добавим после первого четного элемента массива элемент со значением (M[I-1]+2): " << endl << "\n";
            cout << arr1[i] - 1 + 2  << "  ";

            break;
        }

    }
    getch();
    return 0;
}
