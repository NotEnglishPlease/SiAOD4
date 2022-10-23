#include "HeaderDin.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

void inputQuestion(test& tempObj); // ���������� ���������
void addEl(tests& x, test tempObj); // ���������� ����� ������� �� 1
void insertTopic(tests& x, test tempObj); // ������� ��������� � ������, ������������ �� ������ ����
void outputQuestions(tests x); // ����� ������� ��������
int quest(tests x, int m); // ����� ��������� � �������� ������� �� �������
void formTest(tests x); // ������������ ����� � 2-�� ��������� �� ������ ����
void delTopic(tests& x, int q); // �������� �������� � ��������� �����
void delEl(tests& x); // ���������� ����� ������� �� 1 

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
		cout << "������������ ������ �4 ����-33-21 �������� �.�. ������� 29" <<
			"\n\n"
			"������� 1\n"
			"����\n"
			"1) ���� ������ �� ������� �����������\n"
			"2) ����� ������������� �� ������ ���� �������\n"
			"3) ������������ ����, ���������� �� ��� ��������� ������� �� ������ ����\n"
			"4) ������� ������� �� ��������� ����\n"
			"5) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1: {
			test tempObj;
			if (x.n == 0) { // ���� ��� ������ ��������� � �������
				inputQuestion(tempObj);
				x.arr[x.n]=tempObj; // ������� ��� ��������������
				x.n++; // ���������� ��������� � �������
			}
			else { // �����
				inputQuestion(tempObj);
				addEl(x, tempObj );
				insertTopic(x, tempObj); // ������� � ���������������
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
			cout << "������� ����� ����, ������� ����� �������: ";
			cin >> pos;
			delTopic(x, pos);
			outputQuestions(x);
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

void inputQuestion(test& tempObj) {
	int anwersNumber;
	cout << "������� ����� ����: ";
	cin >> tempObj.topic;
	cout << "������� ����� �������: ";
	cin >> tempObj.text;
	cout << "������� ���������� ������ �� ���������� �����: ";
	cin >> tempObj.scope;
	cout << "������� ���������� ��������� ������: ";
	cin >> anwersNumber;
	while (anwersNumber > 5 || anwersNumber < 2) // �������� ����� ���������� ��������� ������
	{
		cout << "�������� ����, ������� ���������� ��������� � ��������� �� 2 �� 5";
		cin >> anwersNumber;
	}
	for (int i = 0; i < anwersNumber; i++) {
		cout << "������� " << i + 1 << " ������� ������ : ";
		tempObj.anwers.resize(tempObj.anwers.size() + 1);
		cin >> tempObj.anwers[i];
	}
	cout << "������� ����� ����������� �������� ������: ";
	cin >> tempObj.corAnswer;
	while (tempObj.corAnswer > anwersNumber || tempObj.corAnswer < 1) // �������� ����� ������ ����������� ������
	{
		cout << "�������� ����, ������� ������������ ������� ������: ";
		cin >> tempObj.corAnswer;
	}
}

void addEl(tests& x, test tempObj) {
	test* arr2 = new test[x.n + 1]; // �������� ������ �������(������ �� 1 ������ �������)
	for (int i = 0; i < x.n; i++) { // ���������� ������ ������� ���������� �������
		arr2[i] = x.arr[i];
	}
	delete[] x.arr; // �������� ��������� ������� �������
	x.arr = arr2; // ������������ ������ ������� �������
	x.arr[x.n] = tempObj; // ���������� ����� ������ ������
	x.n++; // ���������� ���������� �������
}

void insertTopic(tests& x, test tempObj) {
	for (int i = 0; i < x.n; i++) // ������� ��������� � ������ �������
	{
		if (tempObj.topic <= x.arr[i].topic) // ���� ����� ���� ��������� ��������� ������ ��� ����� ������� ��������� � �������
		{
			for (int j = x.n-1; j >i; j--)  // ����� ���� ��������� ����� �������� ������
					x.arr[j] = x.arr[j - 1];
			x.arr[i] = tempObj; // ������� ����� �� ��������������� ��������
			break; // �������������� ���������� �����
		}
	}
}

void outputQuestions(tests x) {

	int theme = 0, j = 1;

	for (int i = 0; i < x.n; i++) { // ������ �� ������� �������� � ����� �����

		if (x.arr[i].topic != theme) {

			theme = x.arr[i].topic;
			cout << "\n������� �� ���� ����� " << theme << '\n';
			j = 1;
		}

		cout << j << ". ";
		j++;

		cout << x.arr[i].text << '\n';

		for (int l = 0; l < x.arr[i].anwers.size(); l++) {

			cout << l + 1 << ") " << x.arr[i].anwers[l] << '\n';
		}

		cout << "���������� �����: " << x.arr[i].corAnswer << '\n';
		cout << "���������� ������ �� ��������� �����: " << x.arr[i].scope << '\n';
	}
}

int quest(tests x, int m) {
	cout << x.arr[m].text << " (" << x.arr[m].scope << " ������ �� ���������� �����)\n"; // ����� ������� � ���������� ������ �� ����
	for (int l = 0; l < (x.arr[m].anwers).size(); l++) { // ����� ������ ��������� ������� 
		cout << l + 1 << ") " << x.arr[m].anwers[l] << endl;
	}
	return x.arr[m].corAnswer; // ������� ������ ����������� ������
}

void formTest(tests x) {
	int i, tem = 0, kol = 0, m = 0;
	vector <int> numT; // ������ ������� ��� 
	string ss;
	for (i = 0; i < x.n; i++) { // ������ �� ������� ��������
		if (tem != x.arr[i].topic) { // ���� ����������� ����� ����
			tem = x.arr[i].topic;
			numT.push_back(tem); // ���������� ������� ������� ���
			kol++; // ������� ���������� ���
		}
	}
	vector <int> kolT(kol); // ������ ���������� �������� � ������ ����
	for (i = 0; i < kol; i++) { // ������ �� ������ ����
		for (int j = 0; j < x.n; j++) { // ���� ������� ���������� �������� � ������� ����
			if (x.arr[j].topic == numT[i]) {
				kolT[i] = kolT[i] + 1;
			}
		}
		if (kolT[i] >= 2) { // ���� ���������� ��� ������ ��� ����� 2
			tem = rand() % kolT[i]; // �������� �������� ����� ������ �� ���� ����
			while (numT[i] != x.arr[m].topic) // ���������� �� ����� � ������� ��������
				m++;
			m = m + tem;
			ss = ss + to_string(quest(x, m)); // ����� ������ � ������ ����������� ������ � ������
			m = 0;
			int tem2 = rand() % kolT[i];
			// �� �� ����� ��� ������� �������
			while (tem2 == tem) { // ��������, �� �������� �� 1 � 2 ������
				tem2 = rand() % kolT[i];
			}
			while (numT[i] != x.arr[m].topic)
				m++;
			m = m + tem2;
			ss = ss + to_string(quest(x, m));
			m = 0;
		}
	}
	cout << "������: " << ss << endl;
}

void delEl(tests& x) { // ���������� ����� ������� �� 1 � �����
	test* arr2 = new test[x.n - 1]; // �������� ������ ������� � ������, ������� �� 1 
	for (int i = 0; i < x.n-1; i++) { // �������� ������� ������� � �����
		arr2[i] = x.arr[i];
	}
	delete[] x.arr; // �������� ������� �������
	x.arr = arr2; // ���������� ������ ������� �������
	x.n--; // ���������� ���������� �������
}

void delTopic(tests& x, int q) {
	for (int i = 0; i < x.n; i++) { // ������ �� ������� ��������
		if (x.arr[i].topic == q) { // ���� ���� ������� ����� ��������
			for (int j = i; j < x.n-1; j++)  // ����� ���� ��������� ����� ��������
				x.arr[j] = x.arr[j + 1];
			delEl(x); // ���������� ����� ������� �� 1
			i--; // �.� ����� �������� �������� ������ �������� ���������� ������ �� 1
			// ���������� ������ �� ������� 1
		}
	}
}