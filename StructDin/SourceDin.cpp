#include "HeaderDin.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

void inputQuestion(test& tempObj); // заполнение структуры
void addEl(tests& x, test tempObj); // увеличение длины массива на 1
void insertTopic(tests& x, test tempObj); // вставка структуры в массив, упорядочивая по номеру темы
void outputQuestions(tests x); // вывод массива структур
int quest(tests x, int m); // вывод структуры с заданным номером из массива
void formTest(tests x); // формирование теста с 2-мя вопросами из каждой темы
void delTopic(tests& x, int q); // удаление структур с выбранной темой
void delEl(tests& x); // уменьшение длины массива на 1 

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string stop = "\n---------------------------------------------------------------------------- \n";
	int problem, flag = 1, pos;
	tests x;
	x.n = 0;
	x.arr = new test[1];
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
			if (x.n == 0) { // если это первая структура в массиве
				inputQuestion(tempObj);
				x.arr[x.n]=tempObj; // вставка без упорядочивания
				x.n++; // количество элементов в массиве
			}
			else { // иначе
				inputQuestion(tempObj);
				addEl(x, tempObj );
				insertTopic(x, tempObj); // вставка с упорядочиванием
			}
			system("pause");
			break;
		}
		case 2:
			outputQuestions(x);
			system("pause");
			break;
		case 3:
			formTest(x);
			system("pause");
			break;
		case 4:
			cout << "Введите номер темы, которую нужно удалить: ";
			cin >> pos;
			delTopic(x, pos);
			outputQuestions(x);
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

void addEl(tests& x, test tempObj) {
	test* arr2 = new test[x.n + 1]; // создание нового массива(размер на 1 больше старого)
	for (int i = 0; i < x.n; i++) { // заполнение нового массива элементами старого
		arr2[i] = x.arr[i];
	}
	delete[] x.arr; // удаление элементов старого массива
	x.arr = arr2; // присваивание нового массива старому
	x.arr[x.n] = tempObj; // заполнение новой пустой ячейки
	x.n++; // увеличение переменной размера
}

void insertTopic(tests& x, test tempObj) {
	for (int i = 0; i < x.n; i++) // вставка структуры в нужную позицию
	{
		if (tempObj.topic <= x.arr[i].topic) // если номер темы введенной структуры меньше или равно текущей структуре в массиве
		{
			for (int j = x.n-1; j >i; j--)  // сдвиг всех элементов после текущего вправо
					x.arr[j] = x.arr[j - 1];
			x.arr[i] = tempObj; // вставка числа на позициютекущего элемента
			break; // принудительное завершение цикла
		}
	}
}

void outputQuestions(tests x) {

	int theme = 0, j = 1;

	for (int i = 0; i < x.n; i++) { // проход по вектору структур и вывод полей

		if (x.arr[i].topic != theme) {

			theme = x.arr[i].topic;
			cout << "\nВопросы по теме номер " << theme << '\n';
			j = 1;
		}

		cout << j << ". ";
		j++;

		cout << x.arr[i].text << '\n';

		for (int l = 0; l < x.arr[i].anwers.size(); l++) {

			cout << l + 1 << ") " << x.arr[i].anwers[l] << '\n';
		}

		cout << "Правильный ответ: " << x.arr[i].corAnswer << '\n';
		cout << "Количество баллов за првильный ответ: " << x.arr[i].scope << '\n';
	}
}

int quest(tests x, int m) {
	cout << x.arr[m].text << " (" << x.arr[m].scope << " баллов за правильный ответ)\n"; // вывод вопроса и количества баллов за него
	for (int l = 0; l < (x.arr[m].anwers).size(); l++) { // вывод списка вариантов ответов 
		cout << l + 1 << ") " << x.arr[m].anwers[l] << endl;
	}
	return x.arr[m].corAnswer; // возврат номера правильного ответа
}

void formTest(tests x) {
	int i, tem = 0, kol = 0, m = 0;
	vector <int> numT; // вектор номеров тем 
	string ss;
	for (i = 0; i < x.n; i++) { // проход по массиву структур
		if (tem != x.arr[i].topic) { // если встречается новая тема
			tem = x.arr[i].topic;
			numT.push_back(tem); // заполнение вектора номеров тем
			kol++; // счетчик количества тем
		}
	}
	vector <int> kolT(kol); // вектор количества вопросов в каждой теме
	for (i = 0; i < kol; i++) { // проход по каждой теме
		for (int j = 0; j < x.n; j++) { // цикл считает количество вопросов в текущей теме
			if (x.arr[j].topic == numT[i]) {
				kolT[i] = kolT[i] + 1;
			}
		}
		if (kolT[i] >= 2) { // если количество тем больше или равно 2
			tem = rand() % kolT[i]; // рандомно выбираем номер задачи из этой темы
			while (numT[i] != x.arr[m].topic) // определяем ее номер в векторе структур
				m++;
			m = m + tem;
			ss = ss + to_string(quest(x, m)); // вывод задачи и запись правильного ответа в строку
			m = 0;
			int tem2 = rand() % kolT[i];
			// то же самое для второго вопроса
			while (tem2 == tem) { // проверка, не одинковы ли 1 и 2 вопрос
				tem2 = rand() % kolT[i];
			}
			while (numT[i] != x.arr[m].topic)
				m++;
			m = m + tem2;
			ss = ss + to_string(quest(x, m));
			m = 0;
		}
	}
	cout << "Ответы: " << ss << endl;
}

void delEl(tests& x) { // уменьшение длины массива на 1 с конца
	test* arr2 = new test[x.n - 1]; // создание нового массива с длиной, меньшей на 1 
	for (int i = 0; i < x.n-1; i++) { // перепись старого массива в новый
		arr2[i] = x.arr[i];
	}
	delete[] x.arr; // удаление старого массива
	x.arr = arr2; // присвоение нового массива старому
	x.n--; // уменьшение переменной размера
}

void delTopic(tests& x, int q) {
	for (int i = 0; i < x.n; i++) { // проход по массиву структур
		if (x.arr[i].topic == q) { // если тема вопроса равна заданной
			for (int j = i; j < x.n-1; j++)  // сдвиг всех элементов после текущего
				x.arr[j] = x.arr[j + 1];
			delEl(x); // уменьшение длины массива на 1
			i--; // т.к после удаления элемента индекс следущих становится меньше на 1
			// необходимо отнять от индекса 1
		}
	}
}