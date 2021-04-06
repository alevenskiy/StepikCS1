#pragma once

int power(int, unsigned);

//Требования к реализации: вам нужно реализовать только макрос MAX. 
//Функцию main и какие-либо другие функции реализовывать не нужно. 
//Попробуйте решить эту задачу исключительно средствами макросов.
#define MAX(x, y, r) {int xx = x; int yy = y; int rr = ((xx > yy) ? (xx) : (yy)); r = rr;}

void step10();

void step11();

void step12();

void step13();

