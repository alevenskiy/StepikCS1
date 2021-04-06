#include <iostream>
using namespace std;

/*2.2.8
Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел
Требования к реализации: в данном задании запрещено пользоваться циклами*/
unsigned gcd(unsigned a, unsigned b)
{
    if (a == 0 || b == 0)
        return (a + b);
    else if (a > b)
        return gcd(a % b, b);
    else
        return gcd(a, b % a);
}

/*2.2.10
Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел. 
На вход подается последовательность разделенных пробелами положительных целых чисел. 
Последовательность заканчивается нулем. 
Требуется вывести эту последовательность в обратном порядке.
Требования к реализации: в данном задании запрещено использовать циклы, а также дополнительную память: массивы, строки или контейнеры (даже, если вы с ними уже знакомы)*/
void meow() {
    int c = 0;
    cin >> c;
    if (c == 0) return;
    meow();
    cout << c << ' ';
}

/*2.3.9
В этой задаче вам нужно реализовать функцию, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
На вход функция принимает массив, его размер и величину сдвига. 
Например, если на вход функции подан массив: int a[] = { 1, 2, 3, 4, 5 }; и требуется циклически сдвинуть его влево на 2 позиции, то на выходе мы получим числа в таком порядке: 3, 4, 5, 1, 2.
Обратите внимание, что величина сдвига может быть нулевой, а может быть и больше размера массива, все эти случаи нужно учесть.
Требования к реализации: вам нужно реализовать только функцию циклического сдвига.*/
void myrotate(int a[], unsigned size, int shift)
{   
    int b[sizeof(a)] = {};
    for (int i = 0; i < size; i++)
        b[(size + i - shift) % size] = a[i];

    for (int i = 0; i < size; i++)
        a[i] = b[i];

}

/*2.4.6
Напишите функцию, которая вычисляет длину C-style строки*/
unsigned mystrlen(const char* str)
{
    const char* str_end = str;
    while (*str_end != '\0') {
        str_end++;
    }
    return str_end - str;
}

/*2.4.7
Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк*/
void mystrcat(char* to, const char* from)
{
    while (*to != '\0') to++;

    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
}

/*2.4.8
Напишите функцию поиска первого вхождения шаблона в текст*/
int mystrstr(const char* text, const char* pattern)
{
    if (*pattern == '\0') return 0;
    int position = 0;
    //for(const char* ind = pattern; *text != '\0'; text++){
    while (*text != '\0') {
        const char* ind = pattern;
        const char* ind_text = text;
        while (*ind == *ind_text) {
            ind++;
            ind_text++;
            if (*ind == '\0')
                return position;
        }
        text++;
        position++;
    }
    return -1;
}


char* myresize(const char* str, unsigned size, unsigned new_size) {
    char* new_str = new char[new_size];
    for (int i = 0; i < size && i < new_size; i++)
        new_str[i] = str[i];
    delete[] str;
    return new_str;
}

char* mygetline() {
    unsigned sizestr = 8;
    char* str = new char[sizestr];
    unsigned size = 0;

    char c = '\0';
    while (cin.get(c) && c != '\n') {
        str[size] = c;
        size++;
        if (size == sizestr - 1) {
            str = myresize(str, sizestr, sizestr * 2);
            sizestr *= 2;
        }
    }
    str[size] = '\0';
    return str;
}
