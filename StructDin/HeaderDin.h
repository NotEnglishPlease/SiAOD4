#ifndef _HEADERDIN_H
#define _HEADERDIN_H
#include <vector>
#include <string>

using namespace std;

struct test
{
	int topic; // номер темы 
	string text; // текст вопроса 
	int scope; // балл за правильный ответ
	vector<string> anwers; // список вариантов ответа (количество ответов не больше 6)
	int corAnswer;	// номер правильного ответа (от 1 до 5)
};

struct tests {
	test* arr = NULL; // динамический массив вопросов
	int n; // количество элементов массива
};

#endif 