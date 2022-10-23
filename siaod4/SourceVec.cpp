#include "HeaderVec.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

void inputQuestion(test& tempObj); // заполнение структуры
void insertTopic(vector<test>& vec, test& tempObj); // вставка структуры в вектор, упорядочивая по номеру темы
void outputQuestions(const vector<test> vec); // вывод вектора структур
int quest(const vector<test> vec, int n); // вывод структуры с заданным номером из вектора
void formTest(const vector<test> vec); // формирование теста с 2-мя вопросами из каждой темы
void delTopic(vector<test>& vec, int n); // удаление структур с выбранной темы

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string stop = "\n---------------------------------------------------------------------------- \n";
	int problem, flag = 1, pos;
	srand(time(0));
	while (flag)
	{
		system("cls");
		cout << "Практическая работа №4 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" <<
			"\n\n"
			"Задание 1\n"
			"Меню\n"
			"1) Ввод записи по вопросу склавиатуры\n"
			"2) Вывод упорядоченной по номеру темы таблицы\n"
			"3) Сформировать тест, включающий по два случайных вопроса из каждой темы\n"
			"4) Удалить вопросы по выбранной теме\n"
			"5) Выход из программы.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1: {
			test tempObj;
			if (vec.size() == 0) { // если это первая структура в векторе
				
				inputQuestion(tempObj);
				vec.push_back(tempObj); // вставка без упорядочивания
			}
			else { // иначе
				inputQuestion(tempObj);
				insertTopic(vec, tempObj); // вставка с упорядочиванием
			}
			system("pause");
			break;
		}
		case 2:
			outputQuestions(vec); 
			system("pause");
			break;
		case 3:
			formTest(vec);
			system("pause");
			break;
		case 4:
			cout << "Введите номер темы, которую нужно удалить: ";
			cin >> pos;
			delTopic(vec, pos);
			outputQuestions(vec);
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
				system("pause");
		}
	}
	return 0;
}

void inputQuestion(test& tempObj) {
	int anwersNumber;
	cout << "Введите номер темы: ";
	cin >> tempObj.topic;
	cout << "Введите текст вопроса: ";
	cin >> tempObj.text;
	cout << "Введите количество баллов за правильный ответ: ";
	cin >> tempObj.scope;
	cout << "Введите количество вариантов ответа: ";
	cin >> anwersNumber;
	while (anwersNumber > 5 || anwersNumber < 2) // проверка ввода количества вариантов ответа
	{
		cout << "Неверный ввод, введите количество вариантов в диапазоне от 2 до 5";
		cin >> anwersNumber;
	}
	for (int i = 0; i < anwersNumber; i++) {
		cout << "Введите " << i + 1 << " вариант ответа : ";
		tempObj.anwers.resize(tempObj.anwers.size() + 1);
		cin >> tempObj.anwers[i];
	}
	cout << "Введите номер правильного варианта ответа: ";
	cin >> tempObj.corAnswer;
	while (tempObj.corAnswer > anwersNumber || tempObj.corAnswer < 1) // проверка ввода номера правильного ответа
	{
		cout << "Неверный ввод, введите существующий вариант ответа: ";
		cin >> tempObj.corAnswer;
	}
}

void insertTopic(vector<test>& vec, test& tempObj) {

	for (size_t i = 0; i < vec.size(); i++) // вставка структуры в нужную позицию
	{
		if (tempObj.topic <= vec[i].topic) // если номер темы введенной структуры меньше или равно текущей структуры в векторе
		{
			vec.insert(vec.begin() + i, tempObj); // вставка структуры в следущую позицию
			return;
		}
	}

	vec.push_back(tempObj);
}

void outputQuestions(const vector<test> vec) {

	int theme = 0, j = 1;

	for (int i = 0; i < vec.size(); i++) { // проход по вектору структур и вывод полей

		if (vec[i].topic != theme) {

			theme = vec[i].topic;
			cout << "\nВопросы по теме номер " << theme << '\n';
			j = 1;
		}

		cout << j << ". ";
		j++;

		cout << vec[i].text << '\n';

		for (int l = 0; l < vec[i].anwers.size(); l++) {

			cout << l + 1 << ") " << vec[i].anwers[l] << '\n';
		}

		cout << "Правильный ответ: " << vec[i].corAnswer << '\n';
		cout << "Количество баллов за првильный ответ: " << vec[i].scope << '\n';
	}
}

int quest(const vector<test> vec, int n) {
	cout << vec[n].text << " (" << vec[n].scope <<" баллов за правильный ответ)\n"; // вывод вопроса и количества баллов за него
	for (int l = 0; l < (vec[n].anwers).size() ; l++) { // вывод списка вариантов ответов 
		cout << l + 1 << ") " << vec[n].anwers[l] << endl; 
	}
	return vec[n].corAnswer; // возврат номера правильного ответа
}

void formTest(const vector<test> vec) {
	int i, tem = 0, kol = 0, m = 0;
	vector <int> numT; // вектор номеров тем 
	string ss;
	for (i = 0; i < vec.size(); i++) { // проход по вектору структур
		if (tem != vec[i].topic) { // если встречается новая тема
			tem = vec[i].topic;
			numT.push_back(tem); // заполнение вектора номеров тем
			kol++; // счетчик количества тем
		}
	}
	vector <int> kolT(kol); // вектор количества вопросов в каждой теме
	for (i = 0; i < kol; i++) { // проход по каждой теме
		for (int j = 0; j < vec.size(); j++) { // цикл считает количество вопросов в текущей теме
			if (vec[j].topic == numT[i]) {
				kolT[i] = kolT[i] + 1;
			}
		}
		if (kolT[i] >= 2) { // если количество тем больше или равно 2
			tem = rand() % kolT[i]; // рандомно выбираем номер задачи из этой темы
			while (numT[i] != vec[m].topic) // определяем ее номер в векторе структур
				m++;
			m = m + tem;
			ss=ss+to_string(quest(vec, m)); // вывод задачи и запись правильного ответа в строку
			m = 0;
			int tem2 = rand() % kolT[i];
			// то же самое для второго вопроса
			while (tem2 == tem) { // проверка, не одинковы ли 1 и 2 вопрос
				tem2 = rand() % kolT[i];
			}
			while (numT[i] != vec[m].topic)
				m++;
			m = m + tem2;
			ss =ss+ to_string(quest(vec, m));
			m = 0;
		}
	}
	cout << "Ответы: " << ss;
}

void delTopic(vector<test>& vec, int n) {
	for (int i = 0; i < vec.size(); i++) { // проход по вектору структур
		if (vec[i].topic == n) { // если тема вопроса равна заданной
			vec.erase(vec.begin() + i); // удаляем элемент вектора
			i--; // т.к после удаления элемента индекс следущих становится меньше на 1
			// необходимо отнять от индекса 1
		}
	}
}