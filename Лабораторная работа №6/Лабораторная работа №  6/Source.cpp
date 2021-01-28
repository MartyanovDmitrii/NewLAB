#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const char vowelsStrEn[] = "aAeEiIoOuUyY";


bool checkWord(char* str)
{
	int strLen = strlen(str);
	int vowelsStrEnLen = strlen(vowelsStrEn);

	for (int i = 0; i < strLen; i++)//пробегаем по всем символам слова
	{
		for (int j = 0; j < vowelsStrEnLen; j++)//пробегаем по символам строки с гласными буквами
		{
			if (str[i] == vowelsStrEn[j])//если есть попадание, то выходим - слово не подходит
			{
				return false;
			}
		}

	}
	//проверили все символы, гласных не обнаружили, возвращаем true
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char inputStr[256] = { 0 };
	char wordStr[256] = { 0 };
	int strLen;
	int j = 0;
	cout << "Ввод строки:" << endl;
	gets_s(inputStr, sizeof(inputStr));

	strLen = strlen(inputStr);
	cout << " Вывод слов не содержащих гласных букв:" << endl;
	for (int i = 0; i < strLen; i++)
	{
		if (inputStr[i] == ' ') //отделяем слова
		{
			if (j)
			{
				if (checkWord(wordStr))
				{
					cout << wordStr << endl;
				}

				memset(wordStr, 0, sizeof(wordStr));
				j = 0;
			}
		}
		else
		{
			wordStr[j++] = inputStr[i];//копируем посимвольно
		}
	}

	//проверим, что накопилось до конца строки

	if (j)
	{
		if (checkWord(wordStr))
		{
			cout << wordStr << endl;
		}
	}

	return 0;
}