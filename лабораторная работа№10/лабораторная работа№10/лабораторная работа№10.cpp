#include <iostream>
#include <cstdlib>


using namespace std;

int* GetArrayFill(int inputArrayLength)           // Создание массива
{

    int* newArray = new int[inputArrayLength];

    for (int i = 0; i < inputArrayLength; i++) {
        newArray[i] = rand() % 100;
       
    }

    return newArray;
}

void PrintArray(int* inputArray, int inputArrayLength)  // Печать массива
{
    cout << "Размер: " << inputArrayLength << endl;

    for (int i = 0; i < inputArrayLength; i++)
    {
        cout << i << "  " << inputArray[i] << endl;
    }

    cout << endl;
}

int AddArrayItemBack(int** inputArray, int inputNewItem, int arraySize)  //Добавление элемента в массив
{
    int newArrayLength = arraySize + 1;
    int* newArray = new int[newArrayLength];

    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = (*inputArray)[i];
    }

    newArray[newArrayLength - 1] = inputNewItem;

    delete[](*inputArray);

    *inputArray = newArray;

    return newArrayLength;
}

int DeleteWasteItems(int** array, int inputArrayLength, int inputValueIndex)  // Удаление К элементов из масива
{
    int* newArray = nullptr;
 
    if (!inputValueIndex)
    {
        delete[](*array);
        return 0;
    }

    if (inputValueIndex < inputArrayLength)
    {
        newArray = new int[inputValueIndex];

        for (int i = 0; i < inputValueIndex; i++)
        {
            newArray[i] = (*array)[i];
        }

        delete[] (*array);

        *array = newArray;
    }

    return inputValueIndex;
}

int main()
{
    setlocale(LC_ALL, "RUS");


    int valueKey = 0;
    int arrayLength = 0;
    int addValue;

    cout << "Введите размер массива: " << endl;
    cin >> arrayLength;

    int* currentArray = GetArrayFill(arrayLength);

    PrintArray(currentArray, arrayLength);

    cout << "Введите целое число k: " << endl;
    cin >> valueKey;
    arrayLength = DeleteWasteItems(&currentArray, arrayLength, valueKey);

    if (arrayLength)
        PrintArray(currentArray, arrayLength);
    else
        cout << "Массив пуст" << endl;

    cout << "Введите целое число для добавления " << endl;
    cin >> addValue;

    arrayLength = AddArrayItemBack(&currentArray, addValue, arrayLength);


    if (arrayLength)
        PrintArray(currentArray, arrayLength);
    else
        cout << "Что то пошло не так" << endl;

    return 0;
}