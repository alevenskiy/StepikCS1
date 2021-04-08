#pragma once
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy, strcat

struct String {

	size_t size;
	char* str;

	/*3.3.10
	���������� �����������*/
	String(const char* str = "") : size(strlen(str)), str(strcpy(new char[strlen(str) + 1], str)) {}

	/*3.3.11
	���������� ����������� �����������. � ����������
	��������� ����� � ������ � ������� ������ � �������� ����������� ���������� ����������� �������*/
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
	���������� �����, ����������� � ����� ������ ������ ������*/
	void append(String&);
};

