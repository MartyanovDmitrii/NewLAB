#include <iostream>
#include <fstream>
#include <string>



using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string line; // - временное хранилище для строк
    unsigned int amount = 0;
    bool exist = false;

    ifstream inTmp("file1.txt");
    ofstream out("file2.txt", ios_base::trunc);

    if (!inTmp.is_open())//файла нет, создадим
    {
        ofstream tmp("file1.txt");
        if (!tmp.is_open())
        {
            cout << "Ошибка создания исходного файла" << endl;
            return 1;
        }

        tmp << "Это просто текст для файла его читать не обязательно.\n";
        tmp << "Или можете  прочесть этот короткий текстовый файл.\n";
        tmp << "Или можете не читать.\n";
        tmp << "adsfgsdfgdsga\n";
        tmp << "или можете не чи\n";
        tmp << "текст\n";
        tmp << "Или можете не читать.\n";

        tmp.close();
    }
    else
        inTmp.close();

    ifstream in("file1.txt");

    if (!in.is_open() || !out.is_open())
    {
        cout << "Ошибка открытия файлов" << endl;
        return 1;
    }

    int countSymblos = 0;

    while (getline(in, line)) // - пока есть строки в файле
    {
        if (!line.empty())//строка не пустая
        {
            //если буква
            if (((line.at(0) >= 'a') && (line.at(0) <= 'z')) ||
                ((line.at(0) >= 'A') && (line.at(0) <= 'Z')) ||
                ((line.at(0) >= 'А') && (line.at(0) <= 'Я')) ||
                ((line.at(0) >= 'а') && (line.at(0) <= 'я'))) 
            {
                if (line.at(0) == line.at(line.length() - 1))//если буквы совпадают, то скопируем во второй файл
                {
                    out << line << "\n";
                    countSymblos += line.length();
                }
            }
        }
    }
 cout << "Количество символов в файле text.t = " << countSymblos << endl;   
    out.close();
    in.close();

   

    return 0;   
}
