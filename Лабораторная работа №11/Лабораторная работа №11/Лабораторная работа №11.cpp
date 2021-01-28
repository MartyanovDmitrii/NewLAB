#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;
//описание структуры

struct point
{
    int num;//информационное поле
    point* next;//адресное поле следующего элемента
};
point* make_point()
//создание одного элемента
{
    point* p = new(point);//выделить память
    cout << "\nВведите число: ";
    cin >> p->num;
    p->next = 0;//сформировать адресное поле 
    return p;
}
void print_point(point* p, int i)
//печать информационных полей одного элемента списка
{
    cout << "\nЧисло[" << i << "]:" << p->num;
}

point* make_list(int n)
//формирование списка из n элементов
{
    point* tmp = make_point();//сформировать первый элемент
    point* beg = tmp;
    point* r;
    for (int i = 1; i < n; i++)
    {
        r = make_point();//сформировать следующий элемент
        tmp->next = r;//сохраним указатель на следующий элемент
        tmp = r;//изменить адрес первого элемента списка
    }
    return beg;//вернуть адрес начала списка
}
int print_list(point* beg)
//печать списка, на который указывает указатель beg
{
    point* p = beg;//р присвоить адрес первого элемента списка
    int k = 0;//счетчик количества напечатанных элементов 
    while (p)//пока нет конца списка
    {
        print_point(p, k);//печать элемента, на который указывает элемент p
        p = p->next;//переход к следующему элементу
        k++;
    }
    return k;//количество элементов в списке
}

void delete_evens(point*& beg, int n)
{
    point* p = beg;
    point* prev = NULL;

    int i = 0;

    while (p)
    {
        if (i == n)
        {
            prev->next = nullptr;

            while (p)
            {
                point* t = p->next;
                delete p;
                p = t;
            }

            return;
        }
        else
            i++;

        prev = p;
        p = p->next;
    }
}

point* add_list(point* beg)
{
    int n, k;
    cout << "\nВведите ключ элемента, перед которым нужно добавить новый элемент: "; cin >> n;
    cout << "\nВведите ключ нового элемента списка: "; cin >> k;
    point* p = beg;
    while (p->next != nullptr)
    {
        if (p->next->num == n)
        {
            point* f = new point;
            f->num = k;
            f->next = p->next;
            p->next = f;
            p = p->next;
        }
        p = p->next;
    }

    return beg;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "\nВведите размер списка: ";
    cin >> n;
    point* beg = make_list(n);//формирование списка
    if (!print_list(beg)) cout << "\nСписок пуст";

    cout << "\nВведите номер, с которого удалить: ";
    cin >> n;

    delete_evens(beg, n);

    cout << "\nИзменённый список: " << endl;
    print_list(beg);


    add_list(beg);
    cout << "\nИзменённый список: " << endl;
    print_list(beg);

    getch();//печать списка
    return 0;

}