#include"3.h"

void String::append(String& other) {
	this->size += other.size;
	char* tmp = new char[this->size + 1];
	tmp = strcpy(tmp, this->str);
	strcat(tmp, other.str);
	delete[] this->str;
	this->str = tmp;
}