#ifndef _HEADERSTAT_H
#define _HEADERSTAT_H
#include <vector>
#include <string>

using namespace std;

const int N = 100;

struct test
{
	int topic; // ����� ���� 
	string text; // ����� ������� 
	int scope; // ���� �� ���������� �����
	vector<string> anwers; // ������ ��������� ������ (���������� ������� �� ������ 6)
	int corAnswer;	// ����� ����������� ������ (�� 1 �� 5)
};

struct tests {
	test arr[N] = { 0 }; // ������ �������� 
	int n; // ������� ���������� ��������� �������
};

#endif 