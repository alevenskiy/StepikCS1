#pragma once
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy, strcat

struct String {

	size_t size;
	char* str;

	/*3.3.10
	реализуйте конструктор*/
	String(const char* str = "") : size(strlen(str)), str(strcpy(new char[strlen(str) + 1], str)) {}

	/*3.3.11
	реализуйте заполн€ющий конструктор. и деструктор
	принимает число и символ и создает строку с заданным количеством повторений переданного символа*/
	String(size_t n, char c) {
		this->size = n;
		str = new char[size + 1];
		for (size_t i = 0; i != size; ++i)
			str[i] = c;
	}

	~String() {
		delete[] str;
	}

	/*3.3.11
	реализуйте метод, добавл€ющий в конец строки другую строку*/
	void append(String&);
};

