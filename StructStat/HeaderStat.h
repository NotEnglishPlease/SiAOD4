#ifndef _HEADERSTAT_H
#define _HEADERSTAT_H
#include <vector>
#include <string>

using namespace std;

const int N = 100;

struct test
{
	int topic; // номер темы 
	string text; // текст вопроса 
	int scope; // балл за правильный ответ
	vector<string> anwers; // список вариантов ответа (количество ответов не больше 6)
	int corAnswer;	// номер правильного ответа (от 1 до 5)
};

struct tests {
	test arr[N] = { 0 }; // массив вопросов 
	int n; // текущее количество элементов массива
};

#endif 