#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const char vowelsStrEn[] = "aAeEiIoOuUyY";


bool checkWord(char* str)
{
	int strLen = strlen(str);
	int vowelsStrEnLen = strlen(vowelsStrEn);

	for (int i = 0; i < strLen; i++)//��������� �� ���� �������� �����
	{
		for (int j = 0; j < vowelsStrEnLen; j++)//��������� �� �������� ������ � �������� �������
		{
			if (str[i] == vowelsStrEn[j])//���� ���� ���������, �� ������� - ����� �� ��������
			{
				return false;
			}
		}

	}
	//��������� ��� �������, ������� �� ����������, ���������� true
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char inputStr[256] = { 0 };
	char wordStr[256] = { 0 };
	int strLen;
	int j = 0;
	cout << "���� ������:" << endl;
	gets_s(inputStr, sizeof(inputStr));

	strLen = strlen(inputStr);
	cout << " ����� ���� �� ���������� ������� ����:" << endl;
	for (int i = 0; i < strLen; i++)
	{
		if (inputStr[i] == ' ') //�������� �����
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
			wordStr[j++] = inputStr[i];//�������� �����������
		}
	}

	//��������, ��� ���������� �� ����� ������

	if (j)
	{
		if (checkWord(wordStr))
		{
			cout << wordStr << endl;
		}
	}

	return 0;
}