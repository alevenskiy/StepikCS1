#include <iostream>
using namespace std;

/*2.2.8
�������� ����������� ������� ���������� ����������� ������ �������� ���� ������������� ����� �����
���������� � ����������: � ������ ������� ��������� ������������ �������*/
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
��� ��������� �������� ���������, ������� "��������������" ������������������ ������������� ����� �����. 
�� ���� �������� ������������������ ����������� ��������� ������������� ����� �����. 
������������������ ������������� �����. 
��������� ������� ��� ������������������ � �������� �������.
���������� � ����������: � ������ ������� ��������� ������������ �����, � ����� �������������� ������: �������, ������ ��� ���������� (����, ���� �� � ���� ��� �������)*/
void meow() {
    int c = 0;
    cin >> c;
    if (c == 0) return;
    meow();
    cout << c << ' ';
}

/*2.3.9
� ���� ������ ��� ����� ����������� �������, ������� �������� ���������� ������� ����� �� �������� ����� ������� (����������� �����).
�� ���� ������� ��������� ������, ��� ������ � �������� ������. 
��������, ���� �� ���� ������� ����� ������: int a[] = { 1, 2, 3, 4, 5 }; � ��������� ���������� �������� ��� ����� �� 2 �������, �� �� ������ �� ������� ����� � ����� �������: 3, 4, 5, 1, 2.
�������� ��������, ��� �������� ������ ����� ���� �������, � ����� ���� � ������ ������� �������, ��� ��� ������ ����� ������.
���������� � ����������: ��� ����� ����������� ������ ������� ������������ ������.*/
void myrotate(int a[], unsigned size, int shift)
{   
    int b[sizeof(a)] = {};
    for (int i = 0; i < size; i++)
        b[(size + i - shift) % size] = a[i];

    for (int i = 0; i < size; i++)
        a[i] = b[i];

}

/*2.4.6
�������� �������, ������� ��������� ����� C-style ������*/
unsigned mystrlen(const char* str)
{
    const char* str_end = str;
    while (*str_end != '\0') {
        str_end++;
    }
    return str_end - str;
}

/*2.4.7
��� ��������� ����������� ������� ������������ (�������) ���� C-style �����*/
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
�������� ������� ������ ������� ��������� ������� � �����*/
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
