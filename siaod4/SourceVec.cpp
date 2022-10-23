#include "HeaderVec.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

void inputQuestion(test& tempObj); // ���������� ���������
void insertTopic(vector<test>& vec, test& tempObj); // ������� ��������� � ������, ������������ �� ������ ����
void outputQuestions(const vector<test> vec); // ����� ������� ��������
int quest(const vector<test> vec, int n); // ����� ��������� � �������� ������� �� �������
void formTest(const vector<test> vec); // ������������ ����� � 2-�� ��������� �� ������ ����
void delTopic(vector<test>& vec, int n); // �������� �������� � ��������� ����

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string stop = "\n---------------------------------------------------------------------------- \n";
	int problem, flag = 1, pos;
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
			if (vec.size() == 0) { // ���� ��� ������ ��������� � �������
				
				inputQuestion(tempObj);
				vec.push_back(tempObj); // ������� ��� ��������������
			}
			else { // �����
				inputQuestion(tempObj);
				insertTopic(vec, tempObj); // ������� � ���������������
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
			cout << "������� ����� ����, ������� ����� �������: ";
			cin >> pos;
			delTopic(vec, pos);
			outputQuestions(vec);
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

void insertTopic(vector<test>& vec, test& tempObj) {

	for (size_t i = 0; i < vec.size(); i++) // ������� ��������� � ������ �������
	{
		if (tempObj.topic <= vec[i].topic) // ���� ����� ���� ��������� ��������� ������ ��� ����� ������� ��������� � �������
		{
			vec.insert(vec.begin() + i, tempObj); // ������� ��������� � �������� �������
			return;
		}
	}

	vec.push_back(tempObj);
}

void outputQuestions(const vector<test> vec) {

	int theme = 0, j = 1;

	for (int i = 0; i < vec.size(); i++) { // ������ �� ������� �������� � ����� �����

		if (vec[i].topic != theme) {

			theme = vec[i].topic;
			cout << "\n������� �� ���� ����� " << theme << '\n';
			j = 1;
		}

		cout << j << ". ";
		j++;

		cout << vec[i].text << '\n';

		for (int l = 0; l < vec[i].anwers.size(); l++) {

			cout << l + 1 << ") " << vec[i].anwers[l] << '\n';
		}

		cout << "���������� �����: " << vec[i].corAnswer << '\n';
		cout << "���������� ������ �� ��������� �����: " << vec[i].scope << '\n';
	}
}

int quest(const vector<test> vec, int n) {
	cout << vec[n].text << " (" << vec[n].scope <<" ������ �� ���������� �����)\n"; // ����� ������� � ���������� ������ �� ����
	for (int l = 0; l < (vec[n].anwers).size() ; l++) { // ����� ������ ��������� ������� 
		cout << l + 1 << ") " << vec[n].anwers[l] << endl; 
	}
	return vec[n].corAnswer; // ������� ������ ����������� ������
}

void formTest(const vector<test> vec) {
	int i, tem = 0, kol = 0, m = 0;
	vector <int> numT; // ������ ������� ��� 
	string ss;
	for (i = 0; i < vec.size(); i++) { // ������ �� ������� ��������
		if (tem != vec[i].topic) { // ���� ����������� ����� ����
			tem = vec[i].topic;
			numT.push_back(tem); // ���������� ������� ������� ���
			kol++; // ������� ���������� ���
		}
	}
	vector <int> kolT(kol); // ������ ���������� �������� � ������ ����
	for (i = 0; i < kol; i++) { // ������ �� ������ ����
		for (int j = 0; j < vec.size(); j++) { // ���� ������� ���������� �������� � ������� ����
			if (vec[j].topic == numT[i]) {
				kolT[i] = kolT[i] + 1;
			}
		}
		if (kolT[i] >= 2) { // ���� ���������� ��� ������ ��� ����� 2
			tem = rand() % kolT[i]; // �������� �������� ����� ������ �� ���� ����
			while (numT[i] != vec[m].topic) // ���������� �� ����� � ������� ��������
				m++;
			m = m + tem;
			ss=ss+to_string(quest(vec, m)); // ����� ������ � ������ ����������� ������ � ������
			m = 0;
			int tem2 = rand() % kolT[i];
			// �� �� ����� ��� ������� �������
			while (tem2 == tem) { // ��������, �� �������� �� 1 � 2 ������
				tem2 = rand() % kolT[i];
			}
			while (numT[i] != vec[m].topic)
				m++;
			m = m + tem2;
			ss =ss+ to_string(quest(vec, m));
			m = 0;
		}
	}
	cout << "������: " << ss;
}

void delTopic(vector<test>& vec, int n) {
	for (int i = 0; i < vec.size(); i++) { // ������ �� ������� ��������
		if (vec[i].topic == n) { // ���� ���� ������� ����� ��������
			vec.erase(vec.begin() + i); // ������� ������� �������
			i--; // �.� ����� �������� �������� ������ �������� ���������� ������ �� 1
			// ���������� ������ �� ������� 1
		}
	}
}