#ifndef _HEADERDIN_H
#define _HEADERDIN_H
#include <vector>
#include <string>

using namespace std;

struct test
{
	int topic; // ����� ���� 
	string text; // ����� ������� 
	int scope; // ���� �� ���������� �����
	vector<string> anwers; // ������ ��������� ������ (���������� ������� �� ������ 6)
	int corAnswer;	// ����� ����������� ������ (�� 1 �� 5)
};

struct tests {
	test* arr = NULL; // ������������ ������ ��������
	int n; // ���������� ��������� �������
};

#endif 